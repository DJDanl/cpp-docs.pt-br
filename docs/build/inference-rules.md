---
title: Regras de inferência | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inference rules in NMAKE
- rules, inference
- NMAKE program, inference rules
ms.assetid: caff320f-fb07-4eea-80c3-a6a2133a8492
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2baa4bdd749e7553d052600cc9efe524ec09910d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="inference-rules"></a>Regras de inferência
Regras de inferência fornecem comandos para atualizar os destinos e inferir dependentes para destinos. Extensões em uma regra de inferência correspondem a um único destino e dependente que têm o mesmo nome de base. Regras de inferência são definidos pelo usuário ou predefinido; regras predefinidas podem ser redefinidas.  
  
 Se uma dependência desatualizada não tiver nenhum comando e [. SUFIXOS](../build/dot-directives.md) contém a extensão do dependente, usa NMAKE uma regra cujos extensões coincidirem com o destino e uma existente de arquivos no diretório atual ou especificado. Se os arquivos existentes, corresponde a mais de uma regra de **. SUFIXOS** lista determina qual usar; prioridade lista desce da esquerda para a direita. Se um arquivo dependente não existe e não está listado como um destino em outro bloco de descrição, uma regra de inferência pode criar ausentes dependente de outro arquivo com o mesmo nome de base. Se o destino de um bloco de descrição não tem nenhuma dependentes ou comandos, uma regra de inferência pode atualizar o destino. Regras de inferência podem criar um destino de linha de comando, mesmo que exista nenhum bloco de descrição. NMAKE pode invocar uma regra para um dependentes inferidos mesmo se um dependente explícita for especificada.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Definindo uma regra](../build/defining-a-rule.md)  
  
 [Regras de modo de lote](../build/batch-mode-rules.md)  
  
 [Regras predefinidas](../build/predefined-rules.md)  
  
 [Dependentes inferidos e regras](../build/inferred-dependents-and-rules.md)  
  
 [Precedência em regras de inferência](../build/precedence-in-inference-rules.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência a NMAKE](../build/nmake-reference.md)