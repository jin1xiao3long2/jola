#include <Tiny_Nodes.hpp>

namespace tn {
    void build_tree_version(int l, const std::string &info) {
        for (int i = 0; i < l; i++)
            std::cout << "  ";
        std::cout << info << std::endl;
    }

    node_base *node_Program::Eval(int i) {
        Stmt_sequence->Eval(i);
        return nullptr;
    }

    node_base *node_Stmt_sequence::Eval(int i) {
        Stmt_1->Eval(i);
        if (Semicolon != nullptr) {
            Stmt_2->Eval(i);
        }
        return nullptr;
    }

    node_base *node_Statement::Eval(int i) {
        if (If_stmt) {
            If_stmt->Eval(i);
            return nullptr;
        } else if (Repeat_stmt) {
            Repeat_stmt->Eval(i);
            return nullptr;
        } else if (Assign_stmt) {
            Assign_stmt->Eval(i);
            return nullptr;
        } else if (Read_stmt) {
            Read_stmt->Eval(i);
            return nullptr;
        } else if (Write_stmt) {
            Write_stmt->Eval(i);
            return nullptr;
        }
        return nullptr;
    }

    node_base *node_If_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, std::string("If"));
        Exp->Eval(j);
        Stmt_sequence_1->Eval(j);
        if (Else) {
            Stmt_sequence_2->Eval(j);
        }
        return nullptr;
    }

    node_base *node_Repeat_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, std::string("Repeat"));;
        Stmt_sequence->Eval(j);
        Exp->Eval(j);
        return nullptr;
    }

    node_base *node_Assign_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, std::string("Assign to: " + Identifier->get_string()));
        Exp->Eval(j);
        return nullptr;
    }

    node_base *node_Read_stmt::Eval(int i) {
        build_tree_version(i, std::string("Read: " + Identifier->get_string()));
        return nullptr;
    }

    node_base *node_Write_stmt::Eval(int i) {
        int j = i + 1;
        build_tree_version(i, std::string("Write"));
        Exp->Eval(j);
        return nullptr;
    }

    node_base *node_Exp::Eval(int i) {
        int j = i + 1;
        if (Comparison_op) {
            Comparison_op->Eval(i);
            Simple_exp_1->Eval(j);
            Simple_exp_2->Eval(j);
        } else {
            Simple_exp_1->Eval(i);
        }
        return nullptr;
    }

    node_base *node_Comparison_op::Eval(int i) {
        build_tree_version(i, std::string("Op: " + Comparison_op->get_string()));
        return nullptr;
    }

    node_base *node_Simple_exp::Eval(int i) {
        int j = i + 1;
        if (AddOp) {
            AddOp->Eval(i);
            Term_1->Eval(j);
            Term_2->Eval(j);
        } else {
            Term_1->Eval(i);
        }
        return nullptr;
    }

    node_base *node_AddOp::Eval(int i) {
        build_tree_version(i, std::string("Op: " + AddOp->get_string()));
        return nullptr;
    }

    node_base *node_Term::Eval(int i) {
        int j = i + 1;
        if (MulOp) {
            MulOp->Eval(i);
            Factor_1->Eval(j);
            Factor_2->Eval(j);
        } else {
            Factor_1->Eval(i);
        }
        return nullptr;
    }

    node_base *node_MulOp::Eval(int i) {
        build_tree_version(i, std::string("Op: " + MulOp->get_string()));
        return nullptr;
    }

    node_base *node_Factor::Eval(int i) {
        if (Left_B) {
            Exp->Eval(i);
            return nullptr;
        } else if (Number) {
            build_tree_version(i, std::string("Const: " + Number->get_string()));
            return nullptr;
        } else if (Identifier) {
            build_tree_version(i, std::string("Id: " + Identifier->get_string()));
            return nullptr;
        }
        return nullptr;
    }
}