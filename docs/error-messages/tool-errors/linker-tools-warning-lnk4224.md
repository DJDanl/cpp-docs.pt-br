---
title: Aviso LNK4224 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4224
helpviewer_keywords:
- LNK4224
ms.assetid: 8624b70e-0b93-43cf-b457-834d38632d0b
ms.openlocfilehash: eb0a019cc80e5218a52697b8bcd5e91b811d04d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160387"
---
# <a name="linker-tools-warning-lnk4224"></a>Aviso LNK4224 (Ferramentas de Vinculador)

> *opção* não é mais suportado; ignorado

## <a name="remarks"></a>Comentários

Uma opção de vinculador obsoleto, inválido foi especificada e é ignorada.

Por exemplo, LNK4224 pode ocorrer se uma diretiva /comment aparece em. obj. A diretiva /comment tenham sido adicionada por meio de [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) pragma, usando a opção exestr preterido. Use dumpbin [/ALL](../../build/reference/all.md) para exibir as diretivas de vinculador em um arquivo. obj.

Se possível, modifique a fonte para o. obj e remova o pragma. Se você ignorar esse aviso, é possível que um .executable compilado com **/clr: pure** não será executado conforme o esperado. O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

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