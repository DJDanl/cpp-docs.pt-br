---
title: 'Arrastar e soltar: Implementando um destino de soltar | Microsoft Docs'
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
- OLE drag and drop [MFC], implementing drop targets
- OLE drag and drop [MFC], drop target
- drag and drop [MFC], drop target
ms.assetid: 0689f1ec-5326-4008-b226-4b373c881358
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9fc73eb6627e63b8013180b7608633a9ee424c92
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="drag-and-drop-implementing-a-drop-target"></a>Arrastar e soltar: implementando um destino de soltar
Este artigo descreve como fazer um destino de seu aplicativo. Implementando um destino de soltar leva um pouco mais trabalho que a implementação de uma origem para soltar, mas ela ainda é relativamente simple. Essas técnicas também se aplicam a aplicativos não-OLE.  
  
#### <a name="to-implement-a-drop-target"></a>Para implementar um destino de soltar  
  
1.  Adicione uma variável de membro para cada modo de exibição do aplicativo que você deseja ser um destino de soltar. Essa variável de membro deve ser do tipo `COleDropTarget` ou uma classe derivada.  
  
2.  Da função da classe seu modo de exibição que manipula o `WM_CREATE` mensagem (normalmente `OnCreate`), chamar a variável de membro novo `Register` função de membro. `Revoke`será chamado automaticamente para você quando o modo de exibição é destruído.  
  
3.  Substitua as funções a seguir. Se desejar que o mesmo comportamento ao longo de seu aplicativo, substitua essas funções em sua classe de exibição. Se você quiser modificar o comportamento em casos isolados ou deseja habilitar descartando em não -`CView` windows, substituir essas funções em sua `COleDropTarget`-classe derivada.  
  
    |Substituições|Para permitir|  
    |--------------|--------------|  
    |`OnDragEnter`|Descarte operações ocorra na janela. Chamado quando o cursor entra primeiro na janela.|  
    |`OnDragLeave`|Comportamento especial quando a operação de arrastar deixa a janela especificada.|  
    |`OnDragOver`|Descarte operações ocorra na janela. Chamado quando o cursor é arrastado ao longo da janela.|  
    |`OnDrop`|Manipulação de dados que está sendo descartados na janela especificada.|  
    |`OnScrollBy`|Comportamento especial quando rolagem é necessário na janela de destino.|  
  
 Consulte o MAINVIEW. CPP arquivo que é parte do exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) para obter um exemplo de como funcionam essas funções.  
  
 Para obter mais informações, consulte:  
  
-   [Implementando uma origem para soltar](../mfc/drag-and-drop-implementing-a-drop-source.md)  
  
-   [Criação e destruição de fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-creation-and-destruction.md)  
  
-   [Manipulação de fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-manipulation.md)  
  
## <a name="see-also"></a>Consulte também  
 [Arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)   
 [Classe COleDropTarget](../mfc/reference/coledroptarget-class.md)
