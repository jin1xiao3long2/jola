//
// Created by XM on 2021/3/28.
//

#include <Tiny_Parser.hpp>

namespace tn {


//    Support Function

    bool Parser::IsEnd() { return tokens.empty(); }

    void Parser::Ensure() {
        if (IsEnd()) //error happened
            throw std::runtime_error("Unexpected error");
    }

    token_type Parser::peek() {
        Ensure();
        return tokens.front()->get_type();
    }

    signal_type Parser::peek_signal() {
        return static_cast<token_signal *>(tokens.front())->get_value();
    }

    keyword_type Parser::peek_keyword() {
        return static_cast<token_keyword *>(tokens.front())->get_value();
    }

    token_base *Parser::consume_token() {
        token_base *value = tokens.front();
        tokens.pop_front();
        return value;
    }

    void Parser::match_type(token_type type) {
        if (peek() != type)
            throw std::runtime_error("unexpected token (match type)");
    }

    token_base *Parser::consume_type(token_type type) {
        match_type(type);
        return consume_token();
    }

    void Parser::match_keyword(keyword_type keyword) {
        if (peek_keyword() != keyword)
            throw std::runtime_error("unexpected keyword");
    }

    token_base *Parser::consume_keyword(keyword_type keyword) {
        match_type(token_type::keyword_type);
        match_keyword(keyword);
        return consume_token();
    }

    void Parser::match_signal(signal_type signal) {
        if (peek_signal() != signal)
            throw std::runtime_error("unexpected signal");
    }

    token_base *Parser::consume_signal(signal_type signal) {
        match_type(token_type::signal_type);
        match_signal(signal);
        return consume_token();
    }

//    Parse Function
    node_Program *Parser::Parse_Program() {
        node_Program *program = new node_Program;
        program->Stmt_sequence = Parse_Stmt_sequence();
        return program;
    }

    node_Stmt_sequence *Parser::Parse_Stmt_sequence() {
        node_Stmt_sequence *stmtSequence = new node_Stmt_sequence;
        stmtSequence->Stmt_1 = Parse_Statement();
        bool break_while = false;
        while (!IsEnd()) {
            switch (peek()) {
                case token_type::signal_type: {
                    switch (peek_signal()) {
                        case signal_type::SEMICOLON: {
                            stmtSequence->Semicolon = consume_token();
                            stmtSequence->Stmt_2 = Parse_Statement();
                            node_Stmt_sequence *next = new node_Stmt_sequence;
                            next->Stmt_1 = stmtSequence;
                            stmtSequence = next;
                            break;
                        }
                        default: {
                            break_while = true;
                            break;
                        }
                    }
                    break;
                }
                default: {
                    break_while = true;
                    break;
                }
            }
            if (break_while)
                break;
        }
        return stmtSequence;
    }

    node_Statement *Parser::Parse_Statement() {
        node_Statement *statement = new node_Statement;
        switch (peek()) {
            case token_type::keyword_type: {
                switch (peek_keyword()) {
                    case keyword_type::IF: {
                        statement->If_stmt = Parse_If_stmt();
                        break;
                    }
                    case keyword_type::REPEAT: {
                        statement->Repeat_stmt = Parse_Repeat_stmt();
                        break;
                    }
                    case keyword_type::READ: {
                        statement->Read_stmt = Parse_Read_stmt();
                        break;
                    }
                    case keyword_type::WRITE: {
                        statement->Write_stmt = Parse_Write_stmt();
                        break;
                    }
                    default: {
                        throw std::runtime_error("unexpected keyword");
                    }
                }
                break;
            }
            case token_type::identifier_type: {
                statement->Assign_stmt = Parse_Assign_stmt();
                break;
            }
            default:
                throw std::runtime_error("expected \"if\", \"repeat\",\"identifier\",\"read\",\"write\"");
        }
        return statement;
    }

    node_If_stmt *Parser::Parse_If_stmt() {
        node_If_stmt *ifStmt = new node_If_stmt;
        ifStmt->If = consume_token();
        ifStmt->Exp = Parse_Exp();
//        consume THEN
        consume_keyword(keyword_type::THEN);
        ifStmt->Stmt_sequence_1 = Parse_Stmt_sequence();
        switch (peek()) {
            case token_type::keyword_type: {
                switch (peek_keyword()) {
                    case keyword_type::THEN: {
                        ifStmt->Then = consume_token();
                        ifStmt->Stmt_sequence_2 = Parse_Stmt_sequence();
                        ifStmt->End = consume_keyword(keyword_type::END);
                        break;
                    }
                    case keyword_type::END: {
                        ifStmt->Then = consume_token();
                        break;
                    }
                    default:
                        throw std::runtime_error("unexpected token (ifstmt)");
                }
                break;
            }
            default:
                throw std::runtime_error("unexpected token (ifstmt)");
        }
        return ifStmt;
    }

    node_Repeat_stmt *Parser::Parse_Repeat_stmt() {
        node_Repeat_stmt *repeatStmt = new node_Repeat_stmt;
        repeatStmt->Repeat = consume_token();
        repeatStmt->Stmt_sequence = Parse_Stmt_sequence();
        repeatStmt->Until = consume_keyword(keyword_type::UNTIL);
        repeatStmt->Exp = Parse_Exp();
        return repeatStmt;
    }

    node_Assign_stmt *Parser::Parse_Assign_stmt() {
        node_Assign_stmt *assignStmt = new node_Assign_stmt;
        assignStmt->Identifier = consume_type(token_type::identifier_type);
        assignStmt->Assign = consume_signal(signal_type::ASSIGN);
        assignStmt->Exp = Parse_Exp();
        return assignStmt;
    }

    node_Read_stmt *Parser::Parse_Read_stmt() {
        node_Read_stmt *readStmt = new node_Read_stmt;
        readStmt->Read = consume_token();
        readStmt->Identifier = consume_type(token_type::identifier_type);
        return readStmt;
    }

    node_Write_stmt *Parser::Parse_Write_stmt() {
        node_Write_stmt *writeStmt = new node_Write_stmt;
        writeStmt->Write = consume_token();
        writeStmt->Exp = Parse_Exp();
        return writeStmt;
    }

    node_Exp *Parser::Parse_Exp() {
        node_Exp *exp = new node_Exp;
        exp->Simple_exp_1 = Parse_Simple_exp();
        if (IsEnd()) return exp;
        switch (peek()) {
            case token_type::signal_type: {
                switch (peek_signal()) {
                    case signal_type::LT:
                    case signal_type::EQ: {
                        exp->Comparison_op = Parse_Comparison_op();
                        exp->Simple_exp_2 = Parse_Simple_exp();
                        break;
                    }
                }
                break;
            }
        }
        return exp;
    }

    node_Comparison_op *Parser::Parse_Comparison_op() {
        node_Comparison_op *comparisonOp = new node_Comparison_op;
        comparisonOp->Comparison_op = consume_token();
        return comparisonOp;
    }

    node_Simple_exp *Parser::Parse_Simple_exp() {
        node_Simple_exp *simpleExp = new node_Simple_exp;
        simpleExp->Term_1 = Parse_Term();
        bool break_while = false;
        while (!IsEnd()) {
            switch (peek()) {
                case token_type::signal_type: {
                    switch (peek_signal()) {
                        case signal_type::ADD:
                        case signal_type::SUB: {
                            simpleExp->AddOp = Parse_AddOp();
                            simpleExp->Term_2 = Parse_Term();
                            node_Simple_exp *next = new node_Simple_exp;
                            next->Term_1 = simpleExp;
                            simpleExp = next;
                            break;
                        }
                        default:
                            break_while = true;
                    }
                    break;
                }
                default:
                    break_while = true;
            }
            if (break_while)
                break;
        }
        return simpleExp;
    }

    node_AddOp *Parser::Parse_AddOp() {
        node_AddOp *addOp = new node_AddOp;
        addOp->AddOp = consume_type(token_type::signal_type);
        return addOp;
    }

    node_Term *Parser::Parse_Term() {
        node_Term *term = new node_Term;
        term->Factor_1 = Parse_Factor();
        bool break_while = false;
        while (!IsEnd()) {
            switch (peek()) {
                case token_type::signal_type: {
                    switch (peek_signal()) {
                        case signal_type::MUL:
                        case signal_type::DIV: {
                            term->MulOp = Parse_MulOp();
                            term->Factor_2 = Parse_Factor();
                            node_Term *next = new node_Term;
                            next->Factor_1 = term;
                            term = next;
                            break;
                        }
                        default:
                            break_while = true;
                    }
                    break;
                }
                default:
                    break_while = true;
            }
            if (break_while)
                break;
        }
        return term;
    }

    node_MulOp *Parser::Parse_MulOp() {
        node_MulOp *mulOp = new node_MulOp;
        mulOp->MulOp = consume_type(token_type::signal_type);
        return mulOp;
    }

    node_Factor *Parser::Parse_Factor() {
        node_Factor *factor = new node_Factor;
        switch (peek()) {
            case token_type::signal_type: {
                factor->Left_B = consume_signal(signal_type::LEFT_B);
                factor->Exp = Parse_Exp();
                factor->Right_B = consume_signal(signal_type::RIGHT_B);
                break;
            }
            case token_type::number_type: {
                factor->Number = consume_type(token_type::number_type);
                break;
            }
            case token_type::identifier_type: {
                factor->Identifier = consume_type(token_type::identifier_type);
                break;
            }
            default:
                throw std::runtime_error("unexpected token(factor)");
        }
        return factor;
    }

}