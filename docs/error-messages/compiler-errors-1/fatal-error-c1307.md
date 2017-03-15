---
title: Erro fatal C1307 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: fdd866fa39808db1afd4b3b58b7b401178897b88
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1307"></a>Erro fatal C1307
programa foi editado após os dados de perfil serem coletados  
  
 Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o vinculador detectou um módulo de entrada recompilada após /LTCG:PGINSTRUMENT e que o módulo foi alterado para o ponto em que os dados de perfil existente não são mais relevantes. Por exemplo, se o gráfico de chamada é alterado no módulo recompilado, o compilador irá gerar C1307.  
  
 Para resolver esse erro, execute /LTCG:PGINSTRUMENT refazer todas as execuções de teste e executar /LTCG:PGOPTIMIZE. Se você não puder executar /LTCG:PGINSTRUMENT e refazer que todas as de teste é executado, use /LTCG:PGUPDATE em vez de /LTCG:PGOPTIMIZE para criar a imagem otimizada.
