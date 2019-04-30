---
title: Classes de servidor OLE
ms.date: 11/04/2016
f1_keywords:
- vc.classes.ole
helpviewer_keywords:
- OLE server applications [MFC], server classes
- OLE server documents
- COM components, classes [MFC]
- component classes [MFC]
ms.assetid: 8e9b67a2-c0ff-479c-a8d6-19b36c5e6fc6
ms.openlocfilehash: 99dd7f58b862fadc86ee2515bb8ef2008bc538fa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385317"
---
# <a name="ole-server-classes"></a>Classes de servidor OLE

Essas classes são usadas por aplicativos de servidor. Documentos de servidor são derivados `COleServerDoc` , em vez de `CDocument`. Observe que, como `COleServerDoc` é derivado de `COleLinkingDoc`, documentos de servidor também podem ser contêineres que dão suporte à vinculação.

O `COleServerItem` classe representa um documento ou parte de um documento que pode ser inserido em outro documento ou vinculado.

`COleIPFrameWnd` e `COleResizeBar` dar suporte a edição in-loco, enquanto o objeto está em um contêiner, e `COleTemplateServer` dá suporte à criação de pares de documento/exibição para objetos OLE de outros aplicativos que podem ser editados.

[COleServerDoc](../mfc/reference/coleserverdoc-class.md)<br/>
Usado como a classe base para classes de documento do aplicativo de servidor. `COleServerDoc` a maior parte do suporte do servidor por meio de interações com os objetos fornecem `COleServerItem` objetos. Funcionalidades de edição visual é fornecida usando a arquitetura de documento/exibição da biblioteca de classe.

[CDocItem](../mfc/reference/cdocitem-class.md)<br/>
Classe abstrata base de `COleClientItem` e `COleServerItem`. Objetos de classes derivados de `CDocItem` representam as partes de documentos.

[COleServerItem](../mfc/reference/coleserveritem-class.md)<br/>
Usado para representar a interface OLE para `COleServerDoc` itens. Normalmente, há um `COleServerDoc` objeto que representa a parte inserida de um documento. Em servidores que oferecem suporte a links para as partes de documentos, pode haver muitos `COleServerItem` objetos, cada um deles representa um link para uma parte do documento.

[COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)<br/>
Fornece a janela do quadro para um modo de exibição quando um documento do servidor está sendo editado no local.

[COleResizeBar](../mfc/reference/coleresizebar-class.md)<br/>
Fornece a interface de usuário padrão para redimensionamento in-loco. Objetos dessa classe são sempre usados em conjunto com `COleIPFrameWnd` objetos.

[COleTemplateServer](../mfc/reference/coletemplateserver-class.md)<br/>
Usado para criar documentos usando a arquitetura de documento/exibição da estrutura. Um `COleTemplateServer` delega a maior parte do seu trabalho para um tipo de objeto `CDocTemplate` objeto.

[COleException](../mfc/reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
