---
title: Erro do compilador C3808
ms.date: 11/04/2016
f1_keywords:
- C3808
helpviewer_keywords:
- C3808
ms.assetid: 2ee8ac97-3ea4-417a-8710-be73a7f98cf4
ms.openlocfilehash: 0a1b0b82241c6e48d2c1941ff8122697d11492eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50587727"
---
# <a name="compiler-error-c3808"></a>Erro do compilador C3808

> '*tipo*': uma classe com o atributo ComImport não pode definir membro '*membro*', somente abstrair ou funções de dllimport são permitidas

## <a name="remarks"></a>Comentários

Um tipo que derivado <xref:System.Runtime.InteropServices.ComImportAttribute> não é possível definir *membro*.

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3808.

```cpp
// C3808.cpp
// compile with: /c /clr:pure user32.lib
using namespace System::Runtime::InteropServices;

[System::Runtime::InteropServices::ComImportAttribute()]
ref struct S1 {
   int f() {}   // C3808
   virtual int g() abstract;   // OK

   [DllImport("msvcrt.dll")]
   int printf(System::String ^, int i);   // OK
};
```