---
title: Aviso do compilador (nível 2) C4056
ms.date: 11/04/2016
f1_keywords:
- C4056
helpviewer_keywords:
- C4056
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
ms.openlocfilehash: 20e7c2693c14c0ea05cc6f07f8dad4ce76c1ef5e
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052188"
---
# <a name="compiler-warning-level-2-c4056"></a>Aviso do compilador (nível 2) C4056

estouro na aritmética de constante de ponto flutuante

Aritmética constante de ponto flutuante gera um resultado que excede o valor máximo permitido.

Esse aviso pode ser causado por otimizações de compilador executadas durante a aritmética de constante. Você pode ignorar esse aviso com segurança se ele desaparecer quando você desligar a otimização ([/OD](../../build/reference/od-disable-debug.md)).

O exemplo a seguir gera C4056:

```cpp
// C4056.cpp
// compile with: /W2 /LD
#pragma warning (default : 4056)
float fp_val = 1.0e300 * 1.0e300;   // C4056
```