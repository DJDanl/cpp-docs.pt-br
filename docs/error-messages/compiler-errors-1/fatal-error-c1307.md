---
title: Erro fatal C1307 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1307
dev_langs:
- C++
helpviewer_keywords:
- C1307
ms.assetid: 6f77d3d4-ba8a-476c-b540-aff19eb4efc4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9d06ce51ada7cd9159b8e02ff627bf12ebb7293d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1307"></a>Erro fatal C1307
programa foi editado desde que foram coletados dados de perfil  
  
 Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada foi recompilado após /LTCG:PGINSTRUMENT e que o módulo foi alterado para o ponto em que os dados de perfil existente não são mais relevantes. Por exemplo, se o gráfico de chamada é alterado no módulo recompilado, o compilador gerará C1307.  
  
 Para resolver esse erro, execute /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE. Se você não puder executar /LTCG:PGINSTRUMENT e todos os teste de refazer é executado, use /LTCG:PGUPDATE em vez de /LTCG:PGOPTIMIZE criar imagem otimizada.