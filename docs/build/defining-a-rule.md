---
title: Definindo uma regra | Microsoft Docs
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
- NMAKE program, inference rules
- defining inference rules
ms.assetid: 071cd092-3f2e-4065-b0fb-36a9d393cfa8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c0d6ca616e3685db36d6d24b339a860eab4c6150
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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