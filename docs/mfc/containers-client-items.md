---
title: "Cont&#234;ineres: itens clientes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "itens de cliente e contêineres OLE"
  - "Contêineres OLE, itens de cliente"
ms.assetid: 231528b5-0744-4f83-8897-083bf55ed087
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: itens clientes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica o que os itens do cliente são e de classes que seu aplicativo deve derivar os itens do cliente.  
  
 Os itens do cliente são os itens de dados que pertencem a um outro aplicativo que estão contidos em ou referenciadas por um documento OLE de aplicativo do contêiner.  Os itens do cliente cujos dados estão contidos no documento são inseridos; aqueles cujos dados são armazenados em outro local referenciado pelo documento contêiner são vinculados.  
  
 A classe do documento em um aplicativo OLE é derivada da classe [COleDocument](../mfc/reference/coledocument-class.md) em vez de **CDocument**.  A classe de `COleDocument` herda de **CDocument** toda a funcionalidade necessária para usar a arquitetura do documento\/exibição na qual os aplicativos MFC são baseados.  `COleDocument` também define uma interface que manipula um documento como uma coleção de objetos de `CDocItem` .  Várias funções de membro de `COleDocument` são fornecidas, recuperando, adicionando e excluindo elementos da coleção.  
  
 Cada aplicativo de contêiner deve derivar pelo menos uma classe de `COleClientItem`.  Os objetos dessa classe representa os itens, inseridos ou vinculados, no documento OLE.  Esses objetos existem enquanto durar o documento que contém os dados, a menos que sejam excluídos do documento.  
  
 `CDocItem` é a classe base para `COleClientItem` e `COleServerItem`.  Os objetos das classes derivadas desses dois atuam como intermediários entre o item OLE e aplicativos cliente e de servidor do, respectivamente.  Sempre que um novo item OLE é adicionado ao documento, a estrutura MFC adiciona um novo objeto de `COleClientItem`do aplicativo cliente \- classe derivada à coleção do documento de objetos de `CDocItem` .  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Contêineres: arquivos compostos](../mfc/containers-compound-files.md)   
 [Contêineres: emissões de interface do usuário](../mfc/containers-user-interface-issues.md)   
 [Contêineres: recursos avançados](../mfc/containers-advanced-features.md)   
 [Classe de COleClientItem](../mfc/reference/coleclientitem-class.md)   
 [Classe de COleServerItem](../mfc/reference/coleserveritem-class.md)