---
title: Aviso do compilador (níveis 2 e 3) C4008
ms.date: 11/04/2016
f1_keywords:
- C4008
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
ms.openlocfilehash: ab51b16331cc6a102c828234d2c2b8be84f2d276
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225235"
---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Aviso do compilador (níveis 2 e 3) C4008

' identifier ': atributo ' attribute ' ignorado

O compilador ignorou **`__fastcall`** o **`static`** atributo,, ou **`inline`** para uma função (aviso de nível 3) ou dados (aviso de nível 2).

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. **`__fastcall`** atributo com dados.

1. **`static`** ou **`inline`** atributo com a função **Main** .
