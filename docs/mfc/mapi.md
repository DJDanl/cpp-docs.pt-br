---
title: "MAPI | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
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
  - "email, ativando"
  - "habilitando aplicativos para email"
  - "habilitando aplicativos para MAPI"
  - "email, habilitando seu aplicativo"
  - "Suporte a MAPI no MFC"
  - "MAPI, MFC"
  - "mensagens, aplicativos cliente"
ms.assetid: 193449f7-b131-4ab0-9301-8d4f6cd1e7c4
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# MAPI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve a mensagem Interface de Programação de Aplicativo \(MAPI\) da Microsoft para desenvolvedores de aplicativos de mensagens do cliente.  Suporte das fontes MFC para um subconjunto de MAPI na classe **CDocument** mas não encapsula a API inteiro.  Para obter mais informações, consulte [Suporte de MAPI estendida em MFC](../mfc/mapi-support-in-mfc.md).  
  
 MAPI é um conjunto de funções que os aplicativos habilitados para emails e email\- reconhecem usam para criar, manipular, transferir, e armazenar mensagens de email.  Oferece aos desenvolvedores de aplicativos as ferramentas para definir o propósito e o conteúdo das mensagens de email e dá\-lhes a flexibilidade no gerenciamento de mensagens de email armazenadas.  MAPI estendida também fornece uma interface comum que os desenvolvedores de aplicativos podem usar para criar o independente habilitado para emails e email\- ciente dos aplicativos do sistema de mensagens subjacente.  
  
 Os clientes de mensagem fornecem uma interface humana para interação com o sistema de mensagens \(WMS\) do Microsoft Windows.  Essa interação normalmente inclui o aplicativo de serviço de provedores MAPI\- correspondentes como lojas e listas de endereços de mensagem.  
  
 Para obter mais informações sobre de MAPI estendida, consulte os artigos na guia na mensagem do Win32 \(MAPI estendida\) de [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Nesta seção  
 [Suporte de MAPI estendida em MFC](../mfc/mapi-support-in-mfc.md)  
  
## Consulte também  
 [CDocument::OnFileSendMail](../Topic/CDocument::OnFileSendMail.md)   
 [CDocument::OnUpdateFileSendMail](../Topic/CDocument::OnUpdateFileSendMail.md)   
 [COleDocument::OnFileSendMail](../Topic/COleDocument::OnFileSendMail.md)