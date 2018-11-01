---
title: Classes de documento
ms.date: 11/04/2016
f1_keywords:
- vc.classes.document
helpviewer_keywords:
- document classes [MFC]
ms.assetid: 4bf19b02-0a4f-4319-b68e-cddcba2705cb
ms.openlocfilehash: eee8cf874230874b519bbd2cb3ebb34c7d4c5c80
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484624"
---
# <a name="document-classes"></a>Classes de documento

Objetos de classe de documento, criados por objetos de modelo de documento, gerenciar os dados do aplicativo. Você será derivar uma classe para seus documentos de uma dessas classes.

Objetos de classe de documento interagem com objetos de exibição. Exibir objetos representam a área de cliente de uma janela, exibem dados de um documento e permitem aos usuários interagir com ele. Documentos e exibições são criadas por um objeto de modelo de documento.

[CDocument](../mfc/reference/cdocument-class.md)<br/>
A classe base para documentos específicos do aplicativo. Derive sua classe de documento ou classes de `CDocument`.

[COleDocument](../mfc/reference/coledocument-class.md)<br/>
Usado para a implementação de documento composto, bem como suporte a contêiner básico. Serve como um contêiner para as classes derivadas de [CDocItem](../mfc/reference/cdocitem-class.md). Essa classe pode ser usada como a classe base para o contêiner de documentos e é a classe base para `COleServerDoc`.

[COleLinkingDoc](../mfc/reference/colelinkingdoc-class.md)<br/>
Uma classe derivada de `COleDocument` que fornece a infraestrutura para vinculação. Você deve derivar as classes de documento para seus aplicativos de contêiner a partir dessa classe em vez de partir `COleDocument` se você deseja dar suporte a links para os objetos inseridos.

[CRichEditDoc](../mfc/reference/cricheditdoc-class.md)<br/>
Mantém a lista de itens de cliente OLE que estão no controle de edição rica. Usado com [CRichEditView](../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../mfc/reference/cricheditcntritem-class.md).

[COleServerDoc](../mfc/reference/coleserverdoc-class.md)<br/>
Usado como a classe base para classes de documento do aplicativo de servidor. `COleServerDoc` a maior parte do suporte do servidor por meio de interações com os objetos fornecem [COleServerItem](../mfc/reference/coleserveritem-class.md) objetos. Funcionalidades de edição visual é fornecida usando a arquitetura de documento/exibição da biblioteca de classe.

[CHtmlEditDoc](../mfc/reference/chtmleditdoc-class.md)<br/>
Fornece, com [CHtmlEditView](../mfc/reference/chtmleditview-class.md), a funcionalidade da plataforma de edição WebBrowser HTML dentro do contexto da arquitetura de exibição de documento do MFC.

## <a name="related-classes"></a>Classes relacionadas

Objetos de classe de documento podem ser persistentes — em outras palavras, eles podem gravar seu estado em uma mídia de armazenamento e lê-lo novamente. O MFC fornece o `CArchive` classe para facilitar a transferência de dados do documento em uma mídia de armazenamento.

[CArchive](../mfc/reference/carchive-class.md)<br/>
Coopera com um [CFile](../mfc/reference/cfile-class.md) objeto para implementar o armazenamento persistente de objetos por meio de serialização (consulte [CObject::Serialize](../mfc/reference/cobject-class.md#serialize)).

Documentos também podem conter objetos OLE. `CDocItem` é a classe base dos itens do servidor e cliente.

[CDocItem](../mfc/reference/cdocitem-class.md)<br/>
Classe abstrata base de [COleClientItem](../mfc/reference/coleclientitem-class.md) e [COleServerItem](../mfc/reference/coleserveritem-class.md). Objetos de classes derivados de `CDocItem` representam as partes de documentos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)

