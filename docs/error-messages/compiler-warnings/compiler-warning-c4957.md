---
title: Aviso do compilador C4957
ms.date: 11/04/2016
f1_keywords:
- C4957
helpviewer_keywords:
- C4957
ms.assetid: a18c52d4-23e2-44f1-b4b5-f7fa5a7f3987
ms.openlocfilehash: 340c26c97d0b5b686eee487cd3fd8b6b05bdf373
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164893"
---
# <a name="compiler-warning-c4957"></a>Aviso do compilador C4957

> '*Cast*': conversão explícita de '*cast_from*' em '*cast_to*' não é verificável

## <a name="remarks"></a>Comentários

Uma conversão resultará em uma imagem não verificável.

Algumas conversões são seguras (por exemplo, um `static_cast` que dispara conversões definidas pelo usuário e uma `const_cast`). Uma [safe_cast](../../extensions/safe-cast-cpp-component-extensions.md) é garantida para produzir código verificável.

Para obter mais informações, consulte [puro e verificável CodeC++(/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).

A opção de compilador **/CLR: safe** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Esse aviso é emitido como um erro e pode ser desabilitado com o pragma de [aviso](../../preprocessor/warning.md) ou a opção de compilador [/WD](../../build/reference/compiler-option-warning-level.md) .

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
