---
title: Aviso do compilador (níveis 2 e 3) C4008
ms.date: 11/04/2016
f1_keywords:
- C4008
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
ms.openlocfilehash: 9b6fb56045d53cd18689f3903bb3d7a08c3d4e4d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197998"
---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Aviso do compilador (níveis 2 e 3) C4008

' identifier ': atributo ' attribute ' ignorado

O compilador ignorou o atributo `__fastcall`, **estático**ou **embutido** para uma função (aviso de nível 3) ou dados (aviso de nível 2).

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. `__fastcall` atributo com dados.

1. atributo **estático** ou **embutido** com a função **Main** .
