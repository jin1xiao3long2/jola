/*
 * program ::= stmt-sequence ;
 *
 * stmt-sequence ::= statement ( ';' statement)* ;
 *
 * statement ::= if-stmt
 *             | repeat-stmt
 *             | assign-stmt
 *             | read-stmt
 *             | write-stmt
 *             ;
 *
 * if-stmt ::= 'if' exp 'then' stmt-sequence end
 *           | 'if' exp 'then' stmt-sequence else stmt-sequence end
 *
 * repeat-stmt ::= 'repeat' stmt-sequence 'until' exp ;
 *
 * assign-stmt ::= 'identifier' ':=' exp
 *
 * read-stmt ::= 'read' 'identifier'
 *
 * write-stmt ::= 'write' exp
 *
 * exp ::= simple-exp
 *       | simple-exp comparison-op simple-exp
 *       ;
 *
 * comparison-op ::= '<'
 *                 | '='
 *                 ;
 * simple-exp ::= term
 *              | term (addop term)*
 *              ;
 *
 * addop ::= '+'
 *         | '-'
 *         ;
 *
 * term ::= factor
 *        | factor (mulop factor)*
 *        ;
 *
 * mulop ::= '*'
 *         | '/'
 *         ;
 *
 * factor ::= '(' exp ')'
 *          | 'number'
 *          | 'identifier'
 *          ;
 */

#pragma once


#include <Tiny_Nodes.hpp>
#include <deque>

namespace tn{

    class Parser final{

    private:
        std::deque<token_base *> tokens;


//        Support Function
        bool IsEnd(); //check if tokens.empty

        void Ensure(); //check if empty

        token_type peek(); //check tokens.front.type

        signal_type peek_signal(); //check signal.value

        keyword_type peek_keyword(); //check keyword.value

        token_base* consume_token(); //pop and get tokens.front

        void match_type(token_type type);

        token_base* consume_type(token_type type);

        void match_keyword(keyword_type keyword);

        token_base* consume_keyword(keyword_type keyword);

        void match_signal(signal_type signal);

        token_base* consume_signal(signal_type signal);
//        Parse Function

        node_Program* Parse_Program();

        node_Stmt_sequence* Parse_Stmt_sequence();

        node_Statement* Parse_Statement();

        node_If_stmt* Parse_If_stmt();

        node_Repeat_stmt* Parse_Repeat_stmt();

        node_Assign_stmt* Parse_Assign_stmt();

        node_Read_stmt* Parse_Read_stmt();

        node_Write_stmt* Parse_Write_stmt();

        node_Exp* Parse_Exp();

        node_Comparison_op* Parse_Comparison_op();

        node_Simple_exp* Parse_Simple_exp();

        node_AddOp* Parse_AddOp();

        node_Term* Parse_Term();

        node_MulOp* Parse_MulOp();

        node_Factor* Parse_Factor();

    public:
        explicit Parser(const std::deque<token_base *> Tokens) : tokens(std::move(Tokens)) {};
    };

}

