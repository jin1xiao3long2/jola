#include <Tiny_Nodes.hpp>

namespace tn{
    node_base* node_Program::Eval(int i)  {
        int j = i + 1;
        build_tree_version(i, "program");
        Stmt_sequence->Eval(j);
        return nullptr;
    }

    node_base* node_Stmt_sequence::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "stmt-sequence");
        Stmt_1->Eval(j);
        if(Semicolon != nullptr){
            build_tree_version(j, ";");
            Stmt_2->Eval(j);
        }
        return nullptr;
    }

    node_base* node_Statement::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "statement");
        if(If_stmt){
            If_stmt->Eval(j);
            return nullptr;
        }else if(Repeat_stmt){
            Repeat_stmt->Eval(j);
            return nullptr;
        }else if(Assign_stmt){
            Assign_stmt->Eval(j);
            return nullptr;
        }else if(Read_stmt){
            Read_stmt->Eval(j);
            return nullptr;
        }else if(Write_stmt){
            Write_stmt->Eval(j);
            return nullptr;
        }
        return nullptr;
    }

    node_base* node_If_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "if_stmt");
        build_tree_version(j, "Keyword IF");
        Exp->Eval(j);
        build_tree_version(j, "Keyword THEN");
        Stmt_sequence_1->Eval(j);
        if(Else){
            build_tree_version(j, "Keyword ELSE");
            Stmt_sequence_2->Eval(j);
        }
        build_tree_version(j, "Keyword END");
        return nullptr;
    }

    node_base* node_Repeat_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "repeat-stmt");
        build_tree_version(j, "Keyword REPEAT");
        Stmt_sequence->Eval(j);
        build_tree_version(j, "Keyword UNTIL");
        Exp->Eval(j);
        return nullptr;
    }

    node_base* node_Assign_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "assign-stmt");
        build_tree_version(j, "Identifier " + Identifier->get_string());
        build_tree_version(j, "Signal :=");
        Exp->Eval(j);
        return nullptr;
    }

    node_base* node_Read_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "read-stmt");
        build_tree_version(j, "Keyword READ");
        build_tree_version(j, "Identifier " + Identifier->get_string());
        return nullptr;
    }

    node_base* node_Write_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "write-stmt");
        build_tree_version(j, "Keyword WRITE");
        Exp->Eval(j);
        return nullptr;
    }

    node_base* node_Exp::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "exp");
        Simple_exp_1->Eval(j);
        if(Comparison_op){
            Comparison_op->Eval(j);
            Simple_exp_2->Eval(j);
        }
        return nullptr;
    }

    node_base* node_Comparison_op::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "comparison-op");
        build_tree_version(j, "Signal " + Comparison_op->get_string());
        return nullptr;
    }

    node_base* node_Simple_exp::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "simple-exp");
        Term_1->Eval(j);
        if(AddOp){
            AddOp->Eval(j);
            Term_2->Eval(j);
        }
        return nullptr;
    }

    node_base* node_AddOp::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "addop");
        build_tree_version(j, "Signal " + AddOp->get_string());
        return nullptr;
    }

    node_base* node_Term::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "term");
        Factor_1->Eval(j);
        if(MulOp){
            MulOp->Eval(j);
            Factor_2->Eval(j);
        }
        return nullptr;
    }

    node_base* node_MulOp::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "mulop");
        build_tree_version(j, "Signal " + MulOp->get_string());
    }

    node_base* node_Factor::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, "factor");
        if(Left_B){
            build_tree_version(j, "Signal " + Left_B->get_string());
            Exp->Eval(j);
            build_tree_version(j, "Signal " + Right_B->get_string());
            return nullptr;
        }else if(Number){
            build_tree_version(j, "Number " + Number->get_string());
            return nullptr;
        }else if(Identifier){
            build_tree_version(j, "Identifier " + Identifier->get_string());
            return nullptr;
        }
        return nullptr;
    }
}