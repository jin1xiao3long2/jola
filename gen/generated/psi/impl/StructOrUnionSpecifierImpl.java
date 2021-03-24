// This is a generated file. Not intended for manual editing.
package generated.psi.impl;

import java.util.List;
import org.jetbrains.annotations.*;
import com.intellij.lang.ASTNode;
import com.intellij.psi.PsiElement;
import com.intellij.psi.PsiElementVisitor;
import com.intellij.psi.util.PsiTreeUtil;
import static generated.GeneratedTypes.*;
import com.intellij.extapi.psi.ASTWrapperPsiElement;
import generated.psi.*;

public class StructOrUnionSpecifierImpl extends ASTWrapperPsiElement implements StructOrUnionSpecifier {

  public StructOrUnionSpecifierImpl(@NotNull ASTNode node) {
    super(node);
  }

  public void accept(@NotNull Visitor visitor) {
    visitor.visitStructOrUnionSpecifier(this);
  }

  @Override
  public void accept(@NotNull PsiElementVisitor visitor) {
    if (visitor instanceof Visitor) accept((Visitor)visitor);
    else super.accept(visitor);
  }

  @Override
  @Nullable
  public StructDeclarationList getStructDeclarationList() {
    return findChildByClass(StructDeclarationList.class);
  }

  @Override
  @NotNull
  public StructOrUnion getStructOrUnion() {
    return findNotNullChildByClass(StructOrUnion.class);
  }

}
