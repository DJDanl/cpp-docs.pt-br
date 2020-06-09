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
ms.openlocfilehash: 596b94e7fdbb5d9dc1862867001f6c01c1aea7b2
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617804"
---
# <a name="ole-container-classes"></a>Classes Container OLE

Essas classes são usadas por aplicativos de contêiner. `COleLinkingDoc`E `COleDocument` gerenciar coleções de `COleClientItem` objetos. Em vez de derivar sua classe de documento do `CDocument` , você a deriva de `COleLinkingDoc` ou `COleDocument` , dependendo se você deseja ter suporte para links para objetos inseridos em seu documento.

Use um `COleClientItem` objeto para representar cada item OLE no documento que está inserido de outro documento ou que é um link para outro documento.

[COleDocObjectItem](reference/coledocobjectitem-class.md)<br/>
Dá suporte à contenção de documento ativo.

[COleDocument](reference/coledocument-class.md)<br/>
Usado para implementação de documentos compostos, bem como suporte a contêineres básicos. Serve como um contêiner para classes derivadas de `CDocItem` . Essa classe pode ser usada como a classe base para documentos de contêiner e é a classe base para o `COleServerDoc` .

[COleLinkingDoc](reference/colelinkingdoc-class.md)<br/>
Uma classe derivada do `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar as classes de documento para seus aplicativos de contêiner a partir dessa classe, em vez de `COleDocument` se desejar que elas ofereçam suporte a links para objetos inseridos.

[CRichEditDoc](reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão no controle de edição rico. Usado com [CRichEditView](reference/cricheditview-class.md) e [CRichEditCntrItem](reference/cricheditcntritem-class.md).

[CDocItem](reference/cdocitem-class.md)<br/>
Classe base abstrata de `COleClientItem` e `COleServerItem` . Objetos de classes derivadas de `CDocItem` representam partes de documentos.

[COleClientItem](reference/coleclientitem-class.md)<br/>
Uma classe de item de cliente que representa o lado do cliente da conexão com um item OLE vinculado ou inserido. Derive os itens do cliente desta classe.

[CRichEditCntrItem](reference/cricheditcntritem-class.md)<br/>
Fornece acesso do lado do cliente a um item OLE armazenado em um controle de edição rico quando usado com o `CRichEditView` e o `CRichEditDoc` .

[COleException](reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
