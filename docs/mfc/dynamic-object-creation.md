---
title: Criação de objeto dinâmico | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- object creation [MFC], dynamically at run time
- CObject class [MFC], dynamic object creation
- objects [MFC], creating dynamically at run time
- dynamic object creation [MFC]
ms.assetid: 3e0f51cb-3e24-4231-817f-1c0ce9f2d5df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5763e3f0f3ee5a0e58ac20fe9f637e4f7e097999
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="dynamic-object-creation"></a>Criação de objeto dinâmico
Este artigo explica como criar um objeto dinamicamente em tempo de execução. O procedimento usa informações de classe de tempo de execução, conforme descrito no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md).  
  
#### <a name="to-dynamically-create-an-object-given-its-run-time-class"></a>Para criar dinamicamente um objeto, considerando sua classe de tempo de execução  
  
1.  Use o seguinte código para criar um objeto dinamicamente usando a `CreateObject` função do `CRuntimeClass`. Observe que, em caso de falha `CreateObject` retorna **nulo** em vez de gerar uma exceção:  
  
     [!code-cpp[NVC_MFCCObjectSample#6](../mfc/codesnippet/cpp/dynamic-object-creation_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CObject](../mfc/using-cobject.md)

