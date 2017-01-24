---
title: "Servidores de documentos ativos | Microsoft Docs"
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
  - "servidores de documentos ativos [C++]"
  - "documentos ativos [C++], servidores"
  - "servidores [C++], documento ativo"
ms.assetid: 131fec1e-02a0-4305-a7ab-903b911232a7
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servidores de documentos ativos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os servidores ativas do documento como documentos do host do word, Excel, ou do Powerpoint de outros tipos de aplicativo chamado documentos ativas.  Ao contrário de OLE inseriu os objetos \(que são exibidos somente na página de outro documento\), documentos ativas fornecem a interface completa e concluir a funcionalidade nativa de aplicativo de servidor que os cria.  Os usuários podem criar documentos usando o total poder de seus aplicativos favoritos \(se for documento ativo habilitado\), porém podem tratar o projeto resultante como uma única entidade.  
  
 Os documentos ativos podem ter mais de uma página e sempre estão ativas no local.  Parte ativa de controle de documentos da interface do usuário, mesclando os menus com os menus de **Arquivo** e de **Ajuda** do contêiner.  Ocupam a área editando inteira do contêiner e controlam as exibições e o layout da página da impressora \(margens, os rodapés, e assim por diante\).  
  
 Servidores ativas do documento das ferramentas MFC com interfaces do documento\/exibição, mapas de expedição de comando, impressão, gerenciamento no menu, e gerenciamento do Registro.  Os requisitos específicos de programação são discutidos em [documentos ativas](../Topic/Active%20Documents.md).  
  
 MFC O da suporte a documentos ativos com a classe de [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) , derivado de [CCmdTarget](../Topic/CCmdTarget%20Class.md), e de [CDocObjectServerItem](../mfc/reference/cdocobjectserveritem-class.md), derivado de [COleServerItem](../mfc/reference/coleserveritem-class.md).  O contêiner ativas MFC suporte do documento com a classe de [COleDocObjectItem](../Topic/COleDocObjectItem%20Class.md) , derivado de [COleClientItem](../mfc/reference/coleclientitem-class.md).  
  
 `CDocObjectServer` mapeia as interfaces ativas do documento e inicializa e ativa um documento ativo.  MFC O também fornece macros ao roteamento do comando de identificador em documentos ATIVOS.  Para usar documentos ativas em seu aplicativo, inclua AfxDocOb.h em seu arquivo de StdAfx.h.  
  
 Um servidor normal de MFC engancha acima de seu próprio `COleServerItem`\- classe derivada.  O assistente de aplicativo MFC gerencia essa classe para se você marcar a caixa de seleção de **Mini\-server** ou de **Full\-server** para fornecer ao servidor de aplicativos suporte do documento de composto.  Se você também marcar a caixa de seleção de **Active document server** , o assistente de aplicativo MFC gerenciar uma classe derivada de `CDocObjectServerItem` em vez disso.  
  
 A classe de `COleDocObjectItem` permite que um contêiner OLE se tornar um contêiner ativa do documento.  Você pode usar o assistente de aplicativo MFC para criar um contêiner ativa do documento selecionando a caixa de seleção de **Active document container** na página composta de suporte do documento do assistente de aplicativo MFC.  Para obter mais informações, consulte [Criando um aplicativo de contêineres do documento ativo](../mfc/creating-an-active-document-container-application.md).  
  
## Consulte também  
 [Contenção de documento ativa](../mfc/active-document-containment.md)