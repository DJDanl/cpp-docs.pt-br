---
title: Aviso LNK4224 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4224
helpviewer_keywords:
- LNK4224
ms.assetid: 8624b70e-0b93-43cf-b457-834d38632d0b
ms.openlocfilehash: 9e52dd533d897e729aba5f2b43ea6c019a024d43
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182975"
---
# <a name="linker-tools-warning-lnk4224"></a>Aviso LNK4224 (Ferramentas de Vinculador)

> a *opção* não é mais suportada; aceita

## <a name="remarks"></a>Comentários

Uma opção de vinculador inválida, obsoleta foi especificada e ignorada.

Por exemplo, LNK4224 pode ocorrer se uma diretiva/comment aparecer em. obj. A diretiva/comment teria sido adicionada por meio do [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) pragma, usando a opção preterida exestr. Use DUMPBIN [/All](../../build/reference/all.md) para exibir as diretivas do vinculador em um arquivo. obj.

Se possível, modifique a origem para o. obj e remova o pragma. Se você ignorar esse aviso, é possível que um. executável compilado com **/CLR: Pure** não seja executado conforme o esperado. A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK4224.

```cpp
// LNK4224.cpp
// compile with: /c /Zi
// post-build command: link LNK4224.obj /debug /debugtype:map
int main () {
   return 0;
}
```
