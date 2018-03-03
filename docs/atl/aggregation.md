---
title: "Agregação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8dbb0332bc7e55464e5b8af9d0b57e236f23dc86
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aggregation"></a>Agregação
Há ocasiões quando deseja que o implementador de um objeto para aproveitar os serviços oferecidos por outro objeto pré-compiladas. Além disso, ele gostaria que este segundo objeto a ser exibido como uma parte natural do primeiro. COM alcança ambas essas metas por meio de contenção e de agregação.  
  
 Agregação significa que o objeto de contêiner (externo) cria o objeto de (interno) independente como parte de seu processo de criação e as interfaces do objeto interna são expostas pelo externa. Um objeto permite automaticamente para ser agregáveis ou não. Se estiver, ele deve seguir algumas regras de agregação para funcionar corretamente.  
  
 Primeiramente, todos os **IUnknown** chamadas de método no objeto independente devem delegar para o objeto contido.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Reutilizando objetos](http://msdn.microsoft.com/library/windows/desktop/ms678443)

