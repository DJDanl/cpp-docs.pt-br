---
title: Aviso do compilador (nível 1) C4348
ms.date: 11/04/2016
f1_keywords:
- C4348
helpviewer_keywords:
- C4348
ms.assetid: 816010eb-6079-48d5-a41b-0fc4d67cfe4c
ms.openlocfilehash: 97d382b68f9a252b09056599e38016a60e680bdf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187226"
---
# <a name="compiler-warning-level-1-c4348"></a>Aviso do compilador (nível 1) C4348

' type ': redefinição do parâmetro padrão: número do parâmetro

Um parâmetro de modelo foi redefinido.

O exemplo a seguir gera C4348:

```cpp
// C4348.cpp
// compile with: /LD /W1
template <class T=int> struct A;   // forward declaration

template <class T=int> struct A { };
// C4348, redefinition of default parameter
// try the following line instead
// template <class T> struct A { };
```
