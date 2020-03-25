---
title: Erro fatal C1307
ms.date: 11/04/2016
f1_keywords:
- C1307
helpviewer_keywords:
- C1307
ms.assetid: 6f77d3d4-ba8a-476c-b540-aff19eb4efc4
ms.openlocfilehash: c7eb90c8e17408f6898ef7ff1a9d9e5efcafb4fa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203340"
---
# <a name="fatal-error-c1307"></a>Erro fatal C1307

o programa foi editado desde que os dados do perfil foram coletados

Ao usar [/LTCG: PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada que foi recompilado após/LTCG: PGINSTRUMENT e que o módulo foi alterado para o ponto em que os dados de perfil existentes não são mais relevantes. Por exemplo, se o grafo de chamada for alterado no módulo recompilado, o compilador irá gerar C1307.

Para resolver esse erro, Execute/LTCG: PGINSTRUMENT, refaça todas as execuções de teste e Execute/LTCG: PGOPTIMIZE. Se você não puder executar/LTCG: PGINSTRUMENT e refazer todas as execuções de teste, use/LTCG: PGUPDATE em vez de/LTCG: PGOPTIMIZE para criar a imagem otimizada.
