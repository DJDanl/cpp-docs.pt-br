---
title: Inferir dependentes e regras | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rules, inferred
- inferred dependents in NMAKE
- inferred rules in NMAKE
- dependents, inferred
ms.assetid: 9381e74a-53d9-445c-836d-0ff7ef6112d9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aae09fd756e0eb4eab3031beb5b4cba8c4d35a40
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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