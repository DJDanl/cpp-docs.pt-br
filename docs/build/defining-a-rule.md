---
title: Definindo uma regra | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, inference rules
- defining inference rules
ms.assetid: 071cd092-3f2e-4065-b0fb-36a9d393cfa8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a8ff7c58033ac5f7e42764d185c45c206bf406f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367115"
---
# <a name="defining-a-rule"></a>Definindo uma regra
O *fromext* representa a extensão de um arquivo dependente, e *toext* representa a extensão de um arquivo de destino.  
  
```  
.fromext.toext:  
   commands  
```  
  
## <a name="remarks"></a>Comentários  
 Extensões não diferenciam maiusculas de minúsculas. Macros podem ser chamadas para representar *fromext* e *toext*; as macros são expandidas durante o pré-processamento. O ponto (.) anterior *fromext* devem aparecer no início da linha. Os dois-pontos (:) é precedido por zero ou mais espaços ou guias. Ele pode ser seguido apenas por espaços ou guias, um ponto e vírgula (;) para especificar um comando, um sinal numérico (#) para especificar um comentário ou um caractere de nova linha. Não há outros espaços são permitidos. Comandos são especificados como blocos de descrição.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Caminhos de pesquisa em regras](../build/search-paths-in-rules.md)  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)