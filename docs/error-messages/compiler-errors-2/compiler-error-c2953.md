---
title: Erro do compilador C2953
ms.date: 11/04/2016
f1_keywords:
- C2953
helpviewer_keywords:
- C2953
ms.assetid: 8dbcfa24-8296-4e40-bdc4-5526c07d8892
ms.openlocfilehash: 8a8d591bfbfa30a4ad2fbed171b5febbd46524b0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747664"
---
# <a name="compiler-error-c2953"></a>Erro do compilador C2953

' identifier ': modelo de classe já foi definido

Verifique o arquivo de origem e inclua arquivos para outras definições.

O exemplo a seguir gera C2953:

```cpp
// C2953.cpp
// compile with: /c
template <class T>  class A {};
template <class T>  class A {};   // C2953
template <class T>  class B {};   // OK
```
