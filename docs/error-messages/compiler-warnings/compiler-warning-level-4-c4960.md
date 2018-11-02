---
title: Compilador aviso (nível 4) C4960
ms.date: 11/04/2016
f1_keywords:
- C4960
helpviewer_keywords:
- C4960
ms.assetid: 3b4ed286-9e8d-46f1-af0c-00ba669693a9
ms.openlocfilehash: ff4a9b3d78a108a45abb18c22049b104e630bf15
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516357"
---
# <a name="compiler-warning-level-4-c4960"></a>Compilador aviso (nível 4) C4960

'function' é muito grande para ser analisado

Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada com uma função maior do que 65.535 instruções. Tal função não está disponível para otimizações guiadas por perfil.

Para resolver este aviso, reduza o tamanho da função.