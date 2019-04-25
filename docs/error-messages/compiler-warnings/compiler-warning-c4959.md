---
title: Aviso do compilador C4959
ms.date: 11/04/2016
f1_keywords:
- C4959
helpviewer_keywords:
- C4959
ms.assetid: 3a128f3e-4d8a-4565-ba1a-5d32fdeb5982
ms.openlocfilehash: 646347dec7bc2bac7fa73c8f754d2f9549cb2ba6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388651"
---
# <a name="compiler-warning-c4959"></a>Aviso do compilador C4959

> não é possível definir um struct não gerenciado '*tipo*' em /CLR: safe porque o acesso aos seus membros produz código não verificável

## <a name="remarks"></a>Comentários

Acesso a um membro de um tipo não gerenciado produzirá uma imagem (peverify.exe) não verificável.

Para obter mais informações, consulte [código puro e verificável (C++/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

O **/CLR: safe** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou o [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

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