---
title: Classes Container OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- container classes [MFC]
- OLE classes [MFC]
- visual editing [MFC], classes
- OLE [MFC], classes
- containers [MFC], OLE container applications
ms.assetid: 1e27e1ab-4c22-41eb-8547-6915c72668ae
ms.openlocfilehash: 61db5310637d13da2d2cc183f12f8f62aa60e328
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447659"
---
# <a name="ole-container-classes"></a>Classes Container OLE

Essas classes são usadas por aplicativos de contêiner. `COleLinkingDoc` e `COleDocument` gerenciar coleções de objetos `COleClientItem`. Em vez de derivar sua classe de documento do `CDocument`, você a derivará de `COleLinkingDoc` ou `COleDocument`, dependendo se você deseja ter suporte para links para objetos inseridos em seu documento.

Use um objeto `COleClientItem` para representar cada item OLE no documento que está inserido de outro documento ou que é um link para outro documento.

[COleDocObjectItem](../mfc/reference/coledocobjectitem-class.md)<br/>
Dá suporte à contenção de documento ativo.

[COleDocument](../mfc/reference/coledocument-class.md)<br/>
Usado para implementação de documentos compostos, bem como suporte a contêineres básicos. Serve como um contêiner para classes derivadas de `CDocItem`. Essa classe pode ser usada como a classe base para documentos de contêiner e é a classe base para `COleServerDoc`.

[COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)<br/>
Uma classe derivada de `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar as classes de documento para seus aplicativos de contêiner a partir dessa classe em vez de `COleDocument` se quiser que eles ofereçam suporte a links para objetos inseridos.

[CRichEditDoc](../mfc/reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão no controle de edição rico. Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).

[CDocItem](../mfc/reference/cdocitem-class.md)<br/>
Classe base abstrata de `COleClientItem` e `COleServerItem`. Objetos de classes derivadas de `CDocItem` representam partes de documentos.

[COleClientItem](../mfc/reference/coleclientitem-class.md)<br/>
Uma classe de item de cliente que representa o lado do cliente da conexão com um item OLE vinculado ou inserido. Derive os itens do cliente desta classe.

[CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md)<br/>
Fornece acesso do lado do cliente a um item OLE armazenado em um controle de edição rico quando usado com `CRichEditView` e `CRichEditDoc`.

[COleException](../mfc/reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
