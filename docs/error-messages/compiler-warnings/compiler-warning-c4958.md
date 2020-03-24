---
title: Aviso do compilador C4958
ms.date: 11/04/2016
f1_keywords:
- C4958
helpviewer_keywords:
- C4958
ms.assetid: e79b9e9c-d572-4a3a-a3b6-60962b70864a
ms.openlocfilehash: 63371d91367902c1eab539cb370e55440fcbf917
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164879"
---
# <a name="compiler-warning-c4958"></a>Aviso do compilador C4958

> '*Operation*': aritmética de ponteiro não é verificável

## <a name="remarks"></a>Comentários

Usar aritmética de ponteiro produzirá uma imagem não verificável.

Para obter mais informações, consulte [puro e verificável CodeC++(/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

A opção de compilador **/CLR: safe** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o pragma de [aviso](../../preprocessor/warning.md) ou a opção de compilador [/WD](../../build/reference/compiler-option-warning-level.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4958:

```cpp
// C4958.cpp
// compile with: /clr:safe
// #pragma warning( disable : 4958 )
using namespace System;

int main( ) {
   Int32 arr[] = new Int32[10];
   Int32* p = &arr[0];
   p++;   // C4958
}
```

O compilador implementa operações de matriz com aritmética de ponteiro. Portanto, as matrizes nativas não são verificáveis; em vez disso, use uma matriz CLR. Para obter mais informações, consulte [matriz](../../extensions/arrays-cpp-component-extensions.md).

O exemplo a seguir gera C4958:

```cpp
// C4958b.cpp
// compile with: /clr:safe
// #pragma warning( disable : 4958 )

int main() {
   int array[5];
   array[4] = 0;   // C4958
}
```
