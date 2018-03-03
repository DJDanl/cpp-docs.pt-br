---
title: "Criação de objeto dinâmico | Microsoft Docs"
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
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 755cbf614966ad6faedbe8db9bbf11ac88c63328
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico
Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe de tempo de execução, conforme descrito no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md).  
  
#### <a name="to-dynamically-create-an-object-given-its-run-time-class"></a>Para criar dinamicamente um objeto, considerando sua classe de tempo de execução  
  
1.  Use o seguinte código para criar um objeto dinamicamente usando a `CreateObject` função do `CRuntimeClass`. Observe que, em caso de falha `CreateObject` retorna **nulo** em vez de gerar uma exceção:  
  
     [!code-cpp[NVC_MFCCObjectSample#6](../mfc/codesnippet/cpp/dynamic-object-creation_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CObject](../mfc/using-cobject.md)

