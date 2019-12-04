---
title: Erro do compilador C2289
ms.date: 11/04/2016
f1_keywords:
- C2289
helpviewer_keywords:
- C2289
ms.assetid: cb41a29e-1b06-47dc-bfce-8d73bd63a0df
ms.openlocfilehash: 32afd6b99b84fba1ef9c2c701306abc67488337c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759120"
---
# <a name="compiler-error-c2289"></a>Erro do compilador C2289

mesmo qualificador de tipo usado mais de uma vez

Uma declaração ou definição de tipo usa um qualificador de tipo (`const`, `volatile`, `signed`ou `unsigned`) mais de uma vez, causando um erro em compatibilidade com ANSI ( **/za**).

O exemplo a seguir gera C2286:

```cpp
// C2289.cpp
// compile with: /Za /c
volatile volatile int i;   // C2289
volatile int j;   // OK
```
