---
title: Erro do compilador C3353
ms.date: 11/04/2016
f1_keywords:
- C3353
helpviewer_keywords:
- C3353
ms.assetid: 5699c04b-d504-46ce-bf71-c200318fed71
ms.openlocfilehash: c38642d7abd4f2fd50792c548c9a5521b2da10ad
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58776135"
---
# <a name="compiler-error-c3353"></a>Erro do compilador C3353

'delegate': um delegado só pode ser criado de uma função global ou uma função de membro de um ou o tipo de WinRT

Delegados, declarado com o [delegar](../../extensions/delegate-cpp-component-extensions.md) palavra-chave, só podem ser declarados no escopo global.

O exemplo a seguir gera C3353:

```
// C3353.cpp
// compile with: /clr
delegate int f;   // C3353
```