---
title: "Selecionando um objeto gráfico em um contexto de dispositivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- graphic objects [MFC], selecting into device context
- SelectObject method [MFC]
- GDI objects [MFC], device contexts
- lifetime, graphic objects [MFC]
- device contexts, selecting graphic objects into
- device contexts, graphic objects [MFC]
ms.assetid: cf54a330-63ef-421f-83eb-90ec7bd82eef
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5909625b816deb1303821aaec4034fa24f29be5f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="selecting-a-graphic-object-into-a-device-context"></a>Selecionando um objeto gráfico em um contexto de dispositivo
Este tópico se aplica ao uso de objetos gráficos no contexto de dispositivo da janela. Depois que você [criar um objeto de desenho](../mfc/one-stage-and-two-stage-construction-of-objects.md), você deve selecioná-lo no contexto de dispositivo no lugar do objeto padrão armazenado:  
  
 [!code-cpp[NVC_MFCDocViewSDI#7](../mfc/codesnippet/cpp/selecting-a-graphic-object-into-a-device-context_1.cpp)]  
  
## <a name="lifetime-of-graphic-objects"></a>Tempo de vida de objetos gráficos  
 O objeto de gráfico retornado por [SelectObject](../mfc/reference/cdc-class.md#selectobject) é "temporário". Ou seja, ele será excluído o [OnIdle](../mfc/reference/cwinapp-class.md#onidle) função de membro de classe `CWinApp` na próxima vez que o programa obtém ocioso de tempo. Como usar o objeto retornado por `SelectObject` em uma única função sem devolver o controle para o loop de mensagem principal, você não terá nenhum problema.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Objetos gráficos](../mfc/graphic-objects.md)  
  
-   [Construção de um e dois estágios de objetos gráficos](../mfc/one-stage-and-two-stage-construction-of-objects.md)  
  
-   [Contextos de dispositivo](../mfc/device-contexts.md)  
  
-   [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos gráficos](../mfc/graphic-objects.md)

