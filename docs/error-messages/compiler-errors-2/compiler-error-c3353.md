---
title: Erro do compilador C3353
ms.date: 11/04/2016
f1_keywords:
- C3353
helpviewer_keywords:
- C3353
ms.assetid: 5699c04b-d504-46ce-bf71-c200318fed71
ms.openlocfilehash: eb7b55f63e911f155c13e777e2e84ae7b587e9a3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432663"
---
# <a name="compiler-error-c3353"></a>Erro do compilador C3353

'delegate': um delegado só pode ser criado de uma função global ou uma função de membro de um ou o tipo de WinRT

Delegados, declarado com o [delegar](../../windows/delegate-cpp-component-extensions.md) palavra-chave, só podem ser declarados no escopo global.

O exemplo a seguir gera C3353:

```
// C3353.cpp
// compile with: /clr
delegate int f;   // C3353
```