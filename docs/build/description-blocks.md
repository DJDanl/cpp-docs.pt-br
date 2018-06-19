---
title: Blocos de descrição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0784f08c479a8c8f3968ef61a01431cd9e0ca71e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367102"
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