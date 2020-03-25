---
title: Aviso do compilador C4959
ms.date: 11/04/2016
f1_keywords:
- C4959
helpviewer_keywords:
- C4959
ms.assetid: 3a128f3e-4d8a-4565-ba1a-5d32fdeb5982
ms.openlocfilehash: 13d2ed705bff7b42eb3c348692a5829bd54158b0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164866"
---
# <a name="compiler-warning-c4959"></a>Aviso do compilador C4959

> Não é possível definir struct '*Type*' não gerenciado em/CLR: safe porque acessar seus membros produz código não verificável

## <a name="remarks"></a>Comentários

O acesso a um membro de um tipo não gerenciado produzirá uma imagem não verificável (peverify. exe).

Para obter mais informações, consulte [puro e verificável CodeC++(/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

A opção de compilador **/CLR: safe** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o pragma de [aviso](../../preprocessor/warning.md) ou a opção de compilador [/WD](../../build/reference/compiler-option-warning-level.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4959:

```cpp
// C4959.cpp
// compile with: /clr:safe

// Uncomment the following line to resolve.
// #pragma warning( disable : 4959 )
struct X {
   int data;
};

int main() {
   X x;
   x.data = 10;   // C4959
}
```
