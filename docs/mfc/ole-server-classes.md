---
title: "Classes de servidor OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "componentes COM, Classes "
  - "classes de componentes"
  - "aplicativos de servidor OLE, classes de servidor"
  - "Documentos de servidor OLE"
ms.assetid: 8e9b67a2-c0ff-479c-a8d6-19b36c5e6fc6
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de servidor OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas classes são usadas por aplicativos para servidores.  Os documentos de servidor são derivados de `COleServerDoc` em vez de **CDocument**.  Observe que `COleServerDoc` porque é derivado de `COleLinkingDoc`, os documentos de servidor também podem ser os contêineres que dão suporte a ser vinculado.  
  
 A classe de `COleServerItem` representa um documento ou parte de um documento em que pode ser inserido em outro documento ou ser vinculado.  
  
 `COleIPFrameWnd` e `COleResizeBar` dão suporte ao editar no local quando o objeto está em um contêiner, e da suporte à criação de `COleTemplateServer` de documento\/exibição combina de forma que os objetos OLE de outros aplicativos podem ser editados.  
  
 [COleServerDoc](../Topic/COleServerDoc%20Class.md)  
 Usado como a classe base para o documento de aplicativo de servidor classifica.  os objetos de`COleServerDoc` fornecem o volume de suporte do servidor com interações com objetos de `COleServerItem` .  O recurso visual da edição é fornecido com o uso da arquitetura do documento\/exibição de biblioteca da classe.  
  
 [CDocItem](../mfc/reference/cdocitem-class.md)  
 Classe base abstrata de `COleClientItem` e de `COleServerItem`.  Os objetos das classes derivadas de `CDocItem` representam partes de documentos.  
  
 [COleServerItem](../mfc/reference/coleserveritem-class.md)  
 Usado para representar a interface OLE em itens de `COleServerDoc` .  Geralmente há um objeto de `COleServerDoc` , que representa a parte de um documento inserido.  Em servidores que os links de suporte às partes de documentos, que podem ser muitos objetos de `COleServerItem` , cada uma representando um link para uma parte do documento.  
  
 [COleIPFrameWnd](../mfc/reference/coleipframewnd-class.md)  
 Fornece a janela do quadro para uma exibição quando um documento de servidor está sendo editado no lugar.  
  
 [COleResizeBar](../mfc/reference/coleresizebar-class.md)  
 Fornece a interface do usuário padrão para redimensionar o local.  Os objetos dessa classe são sempre usados em conjunto com objetos de `COleIPFrameWnd` .  
  
 [COleTemplateServer](../mfc/reference/coletemplateserver-class.md)  
 Usado para criar documentos usando a arquitetura do documento\/exibição de estrutura.  Delega de um objeto de `COleTemplateServer` mais de seu trabalho associado a um objeto de `CDocTemplate` .  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento OLE.  Esta classe é usada por contêineres e por servidores.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)