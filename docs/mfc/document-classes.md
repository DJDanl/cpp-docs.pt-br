---
title: Classes de documento
ms.date: 11/04/2016
f1_keywords:
- vc.classes.document
helpviewer_keywords:
- document classes [MFC]
ms.assetid: 4bf19b02-0a4f-4319-b68e-cddcba2705cb
ms.openlocfilehash: 012d107d7bcc630c4bc02a9dc697172080787eac
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615798"
---
# <a name="document-classes"></a>Classes de documento

Objetos de classe de documento, criados por objetos de modelo de documento, gerenciam os dados do aplicativo. Você irá derivar uma classe para seus documentos de uma dessas classes.

Objetos de classe de documento interagem com objetos de exibição. Os objetos de exibição representam a área de cliente de uma janela, exibem os dados de um documento e permitem que os usuários interajam com ele. Documentos e exibições são criados por um objeto documento-modelo.

[CDocument](reference/cdocument-class.md)<br/>
A classe base para documentos específicos do aplicativo. Derive sua classe ou classes de documento do `CDocument` .

[COleDocument](reference/coledocument-class.md)<br/>
Usado para implementação de documentos compostos, bem como suporte a contêineres básicos. Serve como um contêiner para classes derivadas de [CDocItem](reference/cdocitem-class.md). Essa classe pode ser usada como a classe base para documentos de contêiner e é a classe base para o `COleServerDoc` .

[COleLinkingDoc](reference/colelinkingdoc-class.md)<br/>
Uma classe derivada do `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar as classes de documento para seus aplicativos de contêiner a partir dessa classe, em vez de `COleDocument` se desejar que elas ofereçam suporte a links para objetos inseridos.

[CRichEditDoc](reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão no controle de edição rico. Usado com [CRichEditView](reference/cricheditview-class.md) e [CRichEditCntrItem](reference/cricheditcntritem-class.md).

[COleServerDoc](reference/coleserverdoc-class.md)<br/>
Usado como a classe base para as classes de documento do aplicativo servidor. `COleServerDoc`os objetos fornecem a grande quantidade de suporte ao servidor por meio de interações com objetos [COleServerItem](reference/coleserveritem-class.md) . A capacidade de edição visual é fornecida usando a arquitetura de documento/exibição da biblioteca de classes.

[CHtmlEditDoc](reference/chtmleditdoc-class.md)<br/>
Fornece, com [CHtmlEditView](reference/chtmleditview-class.md), a funcionalidade da plataforma de edição HTML do WebBrowser no contexto da arquitetura de exibição de documento do MFC.

## <a name="related-classes"></a>Classes relacionadas

Os objetos de classe de documento podem ser persistentes — em outras palavras, eles podem gravar seu estado em um meio de armazenamento e lê-lo de volta. O MFC fornece a `CArchive` classe para facilitar a transferência dos dados do documento para um meio de armazenamento.

[CArchive](reference/carchive-class.md)<br/>
Coopera com um objeto [testcfile](reference/cfile-class.md) para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject:: Serialize](reference/cobject-class.md#serialize)).

Os documentos também podem conter objetos OLE. `CDocItem`é a classe base dos itens do servidor e do cliente.

[CDocItem](reference/cdocitem-class.md)<br/>
Classe base abstrata de [COleClientItem](reference/coleclientitem-class.md) e [COleServerItem](reference/coleserveritem-class.md). Objetos de classes derivadas de `CDocItem` representam partes de documentos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
