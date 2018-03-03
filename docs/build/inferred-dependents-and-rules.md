---
title: Inferir dependentes e regras | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- rules, inferred
- inferred dependents in NMAKE
- inferred rules in NMAKE
- dependents, inferred
ms.assetid: 9381e74a-53d9-445c-836d-0ff7ef6112d9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fe7c49607f466d8fd1d333883414b24d7837432b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inferred-dependents-and-rules"></a>Dependentes inferidos e regras
NMAKE assume um dependentes inferidos para um destino se existe uma regra de inferência aplicável. Uma regra se aplica se:  
  
-   *toext* coincide com a extensão do destino.  
  
-   *fromext* correspondências a extensão de um arquivo que tem o nome de base do destino e se existe no diretório atual ou especificado.  
  
-   *fromext* está em [. SUFIXOS](../build/dot-directives.md); nenhum outro *fromext* em uma regra de correspondência tem um maior **. SUFIXOS** prioridade.  
  
-   Nenhum dependente explícita tem uma maior **. SUFIXOS** prioridade.  
  
 Dependentes inferidos podem causar efeitos colaterais inesperados. Se o bloco de descrição do destino contém comandos, NMAKE executa os comandos em vez dos comandos na regra.  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)