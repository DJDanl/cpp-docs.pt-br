---
title: Compilador aviso (nível 2) C4056
ms.date: 11/04/2016
f1_keywords:
- C4056
helpviewer_keywords:
- C4056
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
ms.openlocfilehash: 59c66f2f7dcbd1e20463df613b1b7deae6a1c349
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50586895"
---
# <a name="compiler-warning-level-2-c4056"></a>Compilador aviso (nível 2) C4056

Estouro em aritmética de constante de ponto flutuante

Aritmética de constante de ponto flutuante gera um resultado que excede o valor máximo permitido.

Esse aviso pode ser causado pelas otimizações do compilador executadas durante a aritmética de constante. Você pode ignorar com segurança esse aviso se ele desaparecer quando você desligar a otimização ([/Od](../../build/reference/od-disable-debug.md)).

O exemplo a seguir gera C4056:

```
// C4056.cpp
// compile with: /W2 /LD
#pragma warning (default : 4056)
float fp_val = 1.0e300 * 1.0e300;   // C4056
```