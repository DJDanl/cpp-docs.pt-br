---
title: Classes de servidor OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE server applications [MFC], server classes
- OLE server documents
- COM components, classes [MFC]
- component classes [MFC]
ms.assetid: 8e9b67a2-c0ff-479c-a8d6-19b36c5e6fc6
ms.openlocfilehash: 06f5cf0985756506e42c7ad9fde24641b5a0ce93
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619864"
---
# <a name="ole-server-classes"></a>Classes de servidor OLE

Essas classes são usadas por aplicativos de servidor. Os documentos de servidor são derivados de `COleServerDoc` em vez de `CDocument` . Observe que `COleServerDoc` , como é derivado de `COleLinkingDoc` , os documentos de servidor também podem ser contêineres com suporte para vinculação.

A `COleServerItem` classe representa um documento ou parte de um documento que pode ser inserido em outro documento ou vinculado ao.

`COleIPFrameWnd`e `COleResizeBar` suporte à edição in-loco enquanto o objeto está em um contêiner e `COleTemplateServer` dá suporte à criação de pares de documento/exibição para que objetos OLE de outros aplicativos possam ser editados.

[COleServerDoc](reference/coleserverdoc-class.md)<br/>
Usado como a classe base para as classes de documento do aplicativo servidor. `COleServerDoc`os objetos fornecem a grande quantidade de suporte ao servidor por meio de interações com `COleServerItem` objetos. A capacidade de edição visual é fornecida usando a arquitetura de documento/exibição da biblioteca de classes.

[CDocItem](reference/cdocitem-class.md)<br/>
Classe base abstrata de `COleClientItem` e `COleServerItem` . Objetos de classes derivadas de `CDocItem` representam partes de documentos.

[COleServerItem](reference/coleserveritem-class.md)<br/>
Usado para representar a interface OLE para `COleServerDoc` itens. Normalmente, há um `COleServerDoc` objeto, que representa a parte incorporada de um documento. Em servidores que dão suporte a links para partes de documentos, pode haver muitos `COleServerItem` objetos, cada um representando um link para uma parte do documento.

[COleIPFrameWnd](reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para uma exibição quando um documento do servidor está sendo editado no local.

[COleResizeBar](reference/coleresizebar-class.md)<br/>
Fornece a interface do usuário padrão para o redimensionamento in-loco. Os objetos dessa classe são sempre usados em conjunto com `COleIPFrameWnd` objetos.

[COleTemplateServer](reference/coletemplateserver-class.md)<br/>
Usado para criar documentos usando a arquitetura de documento/exibição da estrutura. Um `COleTemplateServer` objeto delega a maior parte de seu trabalho a um `CDocTemplate` objeto associado.

[COleException](reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
