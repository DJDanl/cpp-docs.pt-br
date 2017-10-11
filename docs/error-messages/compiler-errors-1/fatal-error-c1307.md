---
title: Erro fatal C1307 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1307
dev_langs:
- C++
helpviewer_keywords:
- C1307
ms.assetid: 6f77d3d4-ba8a-476c-b540-aff19eb4efc4
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 1173f538f02e8178d523bb51476b4a10427099ea
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1307"></a>Erro fatal C1307
programa foi editado desde que foram coletados dados de perfil  
  
 Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada foi recompilado após /LTCG:PGINSTRUMENT e que o módulo foi alterado para o ponto em que os dados de perfil existente não são mais relevantes. Por exemplo, se o gráfico de chamada é alterado no módulo recompilado, o compilador gerará C1307.  
  
 Para resolver esse erro, execute /LTCG:PGINSTRUMENT, refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE. Se você não puder executar /LTCG:PGINSTRUMENT e todos os teste de refazer é executado, use /LTCG:PGUPDATE em vez de /LTCG:PGOPTIMIZE criar imagem otimizada.
