---
title: 'Arrastar e soltar: Implementando uma origem para soltar'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE drag and drop [MFC], initiating drag operations
- drag and drop [MFC], calling DoDragDrop
- OLE drag and drop [MFC], drop source
- OLE drag and drop [MFC], calling DoDragDrop
- drag and drop [MFC], initiating drag operations
- drag and drop [MFC], drop source
ms.assetid: 0ed2fda0-63fa-4b1e-b398-f1f142f40035
ms.openlocfilehash: 2aa593fa953f7a9874036d48124ae7b92d88e0a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62219750"
---
# <a name="drag-and-drop-implementing-a-drop-source"></a>Arrastar e soltar: Implementando uma origem para soltar

Este artigo explica como obter seu aplicativo para fornecer dados para uma operação de arrastar e soltar.

Uma implementação básica de uma origem para soltar é relativamente simple. A primeira etapa é determinar quais eventos iniciar uma operação de arrastar. Recomendado diretrizes de interface do usuário definem o início de uma operação de arrastar, como a seleção de dados e uma **WM_LBUTTONDOWN** evento que ocorre em um ponto de dados selecionados. Os exemplos de OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) e [HIERSVR](../overview/visual-cpp-samples.md) siga estas diretrizes.

Se seu aplicativo é um contêiner e os dados selecionados forem vinculado ou um objeto incorporado do tipo `COleClientItem`, chame seu `DoDragDrop` função de membro. Caso contrário, construir uma `COleDataSource` do objeto, inicializá-lo com a seleção e chamar o objeto de fonte de dados `DoDragDrop` função de membro. Se seu aplicativo for um servidor, use `COleServerItem::DoDragDrop`. Para obter informações sobre como personalizar o comportamento padrão de arrastar e soltar, consulte o artigo [arrastar e soltar: Personalizando](../mfc/drag-and-drop-customizing.md).

Se `DoDragDrop` retorna **DROPEFFECT_MOVE**, exclua os dados de origem do documento de origem imediatamente. Nenhum valor retornado de `DoDragDrop` tem qualquer efeito em uma origem para soltar.

Para obter mais informações, consulte:

- [Implementando um destino de soltar](../mfc/drag-and-drop-implementing-a-drop-target.md)

- [Personalizando o arrastar e soltar](../mfc/drag-and-drop-customizing.md)

- [Criação e destruição de objetos OLE e fontes de dados](../mfc/data-objects-and-data-sources-creation-and-destruction.md)

- [Manipulação de fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-manipulation.md)

## <a name="see-also"></a>Consulte também

[Arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)<br/>
[COleDataSource::DoDragDrop](../mfc/reference/coledatasource-class.md#dodragdrop)<br/>
[COleClientItem::DoDragDrop](../mfc/reference/coleclientitem-class.md#dodragdrop)<br/>
[CView::OnDragLeave](../mfc/reference/cview-class.md#ondragleave)
