---
title: Compilador aviso (níveis 2 e 3) C4008 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4008
dev_langs:
- C++
helpviewer_keywords:
- C4008
ms.assetid: fb45e535-cb68-4743-80e9-a6e34cfffeca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bd052b8dd6a0b70dd90ca076d0085675b33dc621
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091173"
---
# <a name="compiler-warning-levels-2-and-3-c4008"></a>Compilador aviso (níveis 2 e 3) C4008

'identifier': atributo ' atributo ' ignorado

O compilador ignorado a `__fastcall`, **estáticos**, ou **embutido** atributo para uma função (aviso de nível 3) ou os dados (aviso de nível 2).

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. `__fastcall` atributo com os dados.

1. **estática** ou **embutido** atributo com **principal** função.