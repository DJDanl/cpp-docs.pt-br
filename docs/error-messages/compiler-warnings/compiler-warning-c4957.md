---
title: Aviso do compilador C4957
ms.date: 11/04/2016
f1_keywords:
- C4957
helpviewer_keywords:
- C4957
ms.assetid: a18c52d4-23e2-44f1-b4b5-f7fa5a7f3987
ms.openlocfilehash: 9afdd213baadd907afacde0ff7f14f3c78bc60a5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528252"
---
# <a name="compiler-warning-c4957"></a>Aviso do compilador C4957

> '*cast*': conversão explícita de '*cast_from*'para'*cast_to*' não é verificável

## <a name="remarks"></a>Comentários

Uma conversão resulta em uma imagem não verificável.

Algumas conversões são seguros (por exemplo, uma `static_cast` que dispara a conversões definidas pelo usuário e uma `const_cast`). Um [safe_cast](../../windows/safe-cast-cpp-component-extensions.md) é garantido que produzem código verificável.

Para obter mais informações, consulte [código puro e verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

O **/CLR: safe** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou o [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4957:

```cpp
// C4957.cpp
// compile with: /clr:safe
// #pragma warning( disable : 4957 )
using namespace System;
int main() {
   Object ^ o = "Hello, World!";
   String ^ s = static_cast<String^>(o);   // C4957
   String ^ s2 = safe_cast<String^>(o);   // OK
}
```