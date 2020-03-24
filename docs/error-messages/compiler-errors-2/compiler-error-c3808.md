---
title: Erro do compilador C3808
ms.date: 11/04/2016
f1_keywords:
- C3808
helpviewer_keywords:
- C3808
ms.assetid: 2ee8ac97-3ea4-417a-8710-be73a7f98cf4
ms.openlocfilehash: e854764dc3f8d3ede79965302b62055b91df0a4c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165620"
---
# <a name="compiler-error-c3808"></a>Erro do compilador C3808

> '*Type*': uma classe com o atributo ComImport não pode definir membro '*Member*', somente funções abstract ou DllImport são permitidas

## <a name="remarks"></a>Comentários

Um tipo derivado de <xref:System.Runtime.InteropServices.ComImportAttribute> não pode definir um *membro*.

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

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
