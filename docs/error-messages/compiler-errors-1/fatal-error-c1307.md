---
title: Erro fatal C1307
ms.date: 11/04/2016
f1_keywords:
- C1307
helpviewer_keywords:
- C1307
ms.assetid: 6f77d3d4-ba8a-476c-b540-aff19eb4efc4
ms.openlocfilehash: 1acdda77ac9cbf8d99752de3b78ab9c32bbb4cbc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552263"
---
# <a name="fatal-error-c1307"></a>Erro fatal C1307

programa foi editado desde que foram coletados dados de perfil

Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada foi recompilado após /LTCG:PGINSTRUMENT e que o módulo foi alterado para o ponto em que os dados de perfil existentes não são mais relevantes. Por exemplo, se o grafo de chamada é alterado no módulo recompilado, o compilador gerará C1307.

Para resolver esse erro, execute /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e execute /LTCG:PGOPTIMIZE. Se você não pode executar /LTCG:PGINSTRUMENT e refazer que todas as de teste é executado, use /LTCG:PGUPDATE em vez de /LTCG:PGOPTIMIZE para criar a imagem otimizada.