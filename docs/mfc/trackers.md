---
title: Controladores
ms.date: 11/04/2016
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
ms.openlocfilehash: b71eb0e5d46a790b01ec12f12043af783bdfcf27
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58771442"
---
# <a name="trackers"></a>Controladores

O [CRectTracker](../mfc/reference/crecttracker-class.md) classe fornece uma interface do usuário entre os itens retangulares em seu aplicativo e seu usuário, fornecendo uma variedade de estilos de exibição. Esses estilos incluem bordas sólidas, tracejadas ou tracejadas; um padrão de hachurado que abrange o item; e as alças de redimensionamento podem estar localizadas no lado de fora ou dentro de uma borda. Rastreadores geralmente são usados em conjunto com itens OLE, ou seja, os objetos derivados de `COleClientItem`. Os retângulos de rastreador oferecem indicações visuais sobre o status atual do item.

O exemplo OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) demonstra uma interface comum usando controladores e itens de cliente OLE do ponto de vista de um aplicativo de contêiner. Para ver uma demonstração de diferentes estilos e capacidades de um objeto de controlador, consulte o exemplo de geral do MFC [RASTREADOR](../overview/visual-cpp-samples.md).

Para obter mais informações sobre implementando controladores no aplicativo OLE, consulte [rastreadores: Implementando controladores no aplicativo OLE](../mfc/trackers-implementing-trackers-in-your-ole-application.md)

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Classe COleClientItem](../mfc/reference/coleclientitem-class.md)
