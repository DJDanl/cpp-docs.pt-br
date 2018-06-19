---
title: Classes de servidor OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE server applications [MFC], server classes
- OLE server documents
- COM components, classes [MFC]
- component classes [MFC]
ms.assetid: 8e9b67a2-c0ff-479c-a8d6-19b36c5e6fc6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9fc737a3d11307dff917132bfd113896b4ad801f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33350423"
---
# <a name="ole-server-classes"></a>Classes de servidor OLE
Essas classes são usadas por aplicativos de servidor. Documentos de servidor são derivados de `COleServerDoc` , em vez de **CDocument**. Observe que, como `COleServerDoc` é derivado de `COleLinkingDoc`, documentos de servidor também podem ser recipientes que oferecem suporte à vinculação.  
  
 O `COleServerItem` classe representa um documento ou parte de um documento que pode ser inserido em outro documento ou vinculado.  
  
 `COleIPFrameWnd` e `COleResizeBar` suporte a edição no local, enquanto o objeto está em um contêiner, e `COleTemplateServer` dá suporte à criação de pares de documento/exibição para objetos OLE de outros aplicativos que podem ser editados.  
  
 [COleServerDoc](../mfc/reference/coleserverdoc-class.md)  
 Usado como a classe base para classes de documento do aplicativo de servidor. `COleServerDoc` objetos fornecem a maior parte do suporte do servidor por meio de interações com `COleServerItem` objetos. Recurso de edição visual é fornecido usando a arquitetura de documento/exibição da biblioteca de classes.  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe abstrata base de `COleClientItem` e `COleServerItem`. Objetos de classes derivam de `CDocItem` representar partes de documentos.  
  
 [COleServerItem](../mfc/reference/coleserveritem-class.md)  
 Usado para representar a interface OLE `COleServerDoc` itens. Geralmente há um `COleServerDoc` objeto que representa a parte inserida de um documento. Em servidores que oferecem suporte a links para partes de documentos, pode haver muitos `COleServerItem` objetos, cada um deles representa um link para uma parte do documento.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para um modo de exibição quando um documento do servidor está sendo editado no local.  
  
 [COleResizeBar](../mfc/reference/coleresizebar-class.md)  
 Fornece a interface de usuário padrão para redimensionamento no local. Objetos desta classe são sempre usados em conjunto com `COleIPFrameWnd` objetos.  
  
 [COleTemplateServer](../mfc/reference/coletemplateserver-class.md)  
 Usado para criar documentos usando a arquitetura de documento/exibição do framework. Um `COleTemplateServer` delega a maior parte do seu trabalho para um tipo de objeto `CDocTemplate` objeto.  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

