---
title: Aviso do compilador (nível 2) C4056
ms.date: 11/04/2016
f1_keywords:
- C4056
helpviewer_keywords:
- C4056
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
ms.openlocfilehash: 6046c41bfe9d787732a2cbd50ce3b0d0d9fdb26f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174343"
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
