// This is a generated file. Not intended for manual editing.
package generated.psi;

import java.util.List;
import org.jetbrains.annotations.*;
import com.intellij.psi.PsiElement;

public interface Statement extends PsiElement {

  @Nullable
  CompoundStatement getCompoundStatement();

  @Nullable
  ExpressionStatement getExpressionStatement();

  @Nullable
  IterationStatement getIterationStatement();

  @Nullable
  JumpStatement getJumpStatement();

  @Nullable
  SelectionStatement getSelectionStatement();

}
