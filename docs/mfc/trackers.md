---
title: Rastreadores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6f0a0cc52e3a5150702af4acd293def38df758fd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381531"
---
# <a name="trackers"></a>Controladores
O [CRectTracker](../mfc/reference/crecttracker-class.md) classe fornece uma interface de usuário entre os itens retangulares em seu aplicativo e o usuário, fornecendo uma variedade de estilos de exibição. Esses estilos incluem bordas tracejadas, tracejadas ou sólidas; um padrão hachurado que abrange o item; e as alças de redimensionamento que podem estar localizadas fora ou dentro de uma borda. Rastreadores geralmente são usados em conjunto com itens OLE, ou seja, os objetos derivados da `COleClientItem`. Os retângulos controlador dê indicações visuais sobre o status atual do item.  
  
 O exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) demonstra uma interface comum usando controladores e itens de cliente OLE do ponto de vista de um aplicativo de contêiner. Para ver uma demonstração dos estilos diferentes e capacidades de um objeto de controlador, consulte o exemplo MFC geral [RASTREADOR](../visual-cpp-samples.md).  
  
 Para obter mais informações sobre implementando controladores no aplicativo OLE, consulte [controladores: Implementando controladores no seu aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Classe COleClientItem](../mfc/reference/coleclientitem-class.md)
