---
title: "Blocos de descrição | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 37f095f5ae46e4b555f1d3f7996bd5f357e58ee2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="description-blocks"></a>Blocos de descrição
Um bloco de descrição é uma linha de dependência opcionalmente seguida por um bloco de comandos:  
  
```  
targets... : dependents...  
    commands...  
```  
  
 Uma linha de dependência Especifica um ou mais destinos e zero ou mais dependentes. Um destino deve estar no início da linha. Destinos separados de dependentes por dois-pontos (:); tabulações ou espaços são permitidas. Para dividir a linha, use uma barra invertida (\) depois de um destino ou dependentes. Se não existir um destino, tem um carimbo de hora anterior de um dependente ou é um [pseudotarget](../build/pseudotargets.md), NMAKE executa os comandos. Se um dependente é um destino em outro lugar e não existe ou está desatualizado em relação à suas própria dependentes, NMAKE atualiza dependente antes de atualizar a dependência atual.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Destinos](../build/targets.md)  
  
 [Dependentes](../build/dependents.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência a NMAKE](../build/nmake-reference.md)