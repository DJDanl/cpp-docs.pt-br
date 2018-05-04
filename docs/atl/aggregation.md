---
title: Agregação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 760a595274ba7a1901138cc0cceceddf97122725
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="aggregation"></a>Agregação
Há ocasiões quando deseja que o implementador de um objeto para aproveitar os serviços oferecidos por outro objeto pré-compiladas. Além disso, ele gostaria que este segundo objeto a ser exibido como uma parte natural do primeiro. COM alcança ambas essas metas por meio de contenção e de agregação.  
  
 Agregação significa que o objeto de contêiner (externo) cria o objeto de (interno) independente como parte de seu processo de criação e as interfaces do objeto interna são expostas pelo externa. Um objeto permite automaticamente para ser agregáveis ou não. Se estiver, ele deve seguir algumas regras de agregação para funcionar corretamente.  
  
 Primeiramente, todos os **IUnknown** chamadas de método no objeto independente devem delegar para o objeto contido.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Reutilizando objetos](http://msdn.microsoft.com/library/windows/desktop/ms678443)

