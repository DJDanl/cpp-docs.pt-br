---
title: Rastreadores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- trackers [MFC]
- OLE applications [MFC], trackers
- applications [OLE], trackers
- tracking OLE items [MFC]
- OLE containers [MFC], trackers
- CDC class [MFC], trackers
- CRectTracker class [MFC], implementing trackers
- OLE server applications [MFC], trackers
ms.assetid: dcd09399-6637-4621-80e5-d12670429787
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 29e4d3c556a5f7b6b3aed5daa0285ea6c2c15447
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="trackers"></a>Controladores
O [CRectTracker](../mfc/reference/crecttracker-class.md) classe fornece uma interface de usuário entre os itens retangulares em seu aplicativo e o usuário, fornecendo uma variedade de estilos de exibição. Esses estilos incluem bordas tracejadas, tracejadas ou sólidas; um padrão hachurado que abrange o item; e as alças de redimensionamento que podem estar localizadas fora ou dentro de uma borda. Rastreadores geralmente são usados em conjunto com itens OLE, ou seja, os objetos derivados da `COleClientItem`. Os retângulos controlador dê indicações visuais sobre o status atual do item.  
  
 O exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) demonstra uma interface comum usando controladores e itens de cliente OLE do ponto de vista de um aplicativo de contêiner. Para ver uma demonstração dos estilos diferentes e capacidades de um objeto de controlador, consulte o exemplo MFC geral [RASTREADOR](../visual-cpp-samples.md).  
  
 Para obter mais informações sobre implementando controladores no aplicativo OLE, consulte [controladores: Implementando controladores no seu aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Classe COleClientItem](../mfc/reference/coleclientitem-class.md)
