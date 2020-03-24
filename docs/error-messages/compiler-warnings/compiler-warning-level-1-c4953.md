---
title: Aviso do compilador (nível 1) C4953
ms.date: 08/27/2018
f1_keywords:
- C4953
helpviewer_keywords:
- C4953
ms.assetid: 3c4f6ac6-3976-41ab-8a27-3c41d7472ea7
ms.openlocfilehash: 46f07227b5df62938cc51a7be4cf4f3595a0d947
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174513"
---
# <a name="compiler-warning-level-1-c4953"></a>Aviso do compilador (nível 1) C4953

> '*Function*' embutido foi editado desde que os dados do perfil foram coletados, dados de perfil não usados

Ao usar [/LTCG: PGUPDATE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada que foi recompilado após `/LTCG:PGINSTRUMENT` e tem uma função (*função*) que foi editada e onde as execuções de teste existentes identificaram a função como um candidato para o inlining. No entanto, como resultado da recompilação do módulo, a função não será mais um candidato para a inlinhagem.

Esse aviso é informativo. Para resolver esse aviso, execute `/LTCG:PGINSTRUMENT`, refaça todas as execuções de teste e execute `/LTCG:PGOPTIMIZE`.

Esse aviso será substituído por um erro se `/LTCG:PGOPTIMIZE` tivesse sido usado.
