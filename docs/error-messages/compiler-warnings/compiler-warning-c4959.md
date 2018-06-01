---
title: C4959 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4959
dev_langs:
- C++
helpviewer_keywords:
- C4959
ms.assetid: 3a128f3e-4d8a-4565-ba1a-5d32fdeb5982
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2819664fa94ca777339156dc9a31da17b991c6da
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705158"
---
# <a name="compiler-warning-c4959"></a>C4959 de aviso do compilador

> não é possível definir a estrutura não gerenciada '*tipo*' em /CLR: safe porque o acesso aos seus membros produz código não verificável

## <a name="remarks"></a>Comentários

Acesso a um membro de um tipo não gerenciado produzirá uma imagem não verificado (peverify.exe).

Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

O **/CLR: safe** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

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