---
title: Aviso do compilador C4958
ms.date: 11/04/2016
f1_keywords:
- C4958
helpviewer_keywords:
- C4958
ms.assetid: e79b9e9c-d572-4a3a-a3b6-60962b70864a
ms.openlocfilehash: 7d4ac6f21cfcfe0f37eb17ff81eabd3e6341a7d5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477396"
---
# <a name="compiler-warning-c4958"></a>Aviso do compilador C4958

> '*operação*': aritmética de ponteiro não é verificável

## <a name="remarks"></a>Comentários

Usando a aritmética de ponteiro produzirá uma imagem não verificável.

Para obter mais informações, consulte [código puro e verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

O **/CLR: safe** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou o [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

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

O compilador implementa operações de matriz com a aritmética de ponteiro. Portanto, as matrizes nativos não são verificáveis; Use uma matriz CLR. Para obter mais informações, consulte [matriz](../../windows/arrays-cpp-component-extensions.md).

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