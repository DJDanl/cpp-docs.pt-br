---
title: C3808 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3808
dev_langs:
- C++
helpviewer_keywords:
- C3808
ms.assetid: 2ee8ac97-3ea4-417a-8710-be73a7f98cf4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 40668b8b2cc1a1f85b0ad4a7ef63d89956e922b3
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34705199"
---
# <a name="compiler-error-c3808"></a>C3808 de erro do compilador

> '*tipo*': uma classe com o atributo ComImport não pode definir membro '*membro*', somente abstract ou dllimport funções são permitidas

## <a name="remarks"></a>Comentários

Um tipo que derivado de <xref:System.Runtime.InteropServices.ComImportAttribute> não é possível definir *membro*.

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

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