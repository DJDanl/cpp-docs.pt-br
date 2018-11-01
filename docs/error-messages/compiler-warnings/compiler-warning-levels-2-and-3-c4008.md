---
title: Compilador aviso (níveis 2 e 3) C4008
ms.date: 11/04/2016
f1_keywords:
- C4008
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
ms.openlocfilehash: 99b78e1426cf1618e68ae74ae7e16dd0f08606ba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604081"
---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Compilador aviso (níveis 2 e 3) C4008

'identifier': atributo ' atributo ' ignorado

O compilador ignorado a `__fastcall`, **estáticos**, ou **embutido** atributo para uma função (aviso de nível 3) ou os dados (aviso de nível 2).

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. `__fastcall` atributo com os dados.

1. **estática** ou **embutido** atributo com **principal** função.