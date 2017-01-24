---
title: "MFC COM | Microsoft Docs"
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
  - "MFC COM (MFC)"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Tecnologia ativa [C++]"
  - "Controles ActiveX [C++], Modelo de objeto COM"
  - "COM [C++], Suporte MFC"
  - "MFC [C++], Suporte COM"
  - "Controles ActiveX MFC [C++], Suporte a COM no MFC"
  - "COM MFC [C++]"
ms.assetid: 7646bdcb-3a06-4ed5-9386-9b00f3979dcb
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# MFC COM
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um subconjunto de MFC é criado para dar suporte a, embora a maioria da biblioteca ativa \(ATL\) do modelo é criada para a programação da.  Tópicos dessa seção descreve o suporte para MFC COM.  
  
 As tecnologias ativas \(como controles ActiveX, a retenção ativa do documento, OLE, e assim por diante\) usam o Component Object Model \(COM\) para habilitar componentes de software para interagir um com o outro em um ambiente transmitido, independentemente do idioma com o qual foram criadas.  As tecnologias ativos podem ser usadas para criar aplicativos executados na área de trabalho ou na Internet.  Para obter mais informações [Introdução à](../atl/introduction-to-com.md) ou [O Component Object Model](http://msdn.microsoft.com/library/windows/desktop/ms694363).  
  
 As tecnologias ativos incluem as tecnologias de cliente e servidor, incluindo:  
  
-   [Retenção do documento ativo](../mfc/active-document-containment.md), com suporte em versões 4,2 MFC e posterior, permite que os usuários exibam [documentos ativas](../Topic/Active%20Documents.md) \(como o Microsoft Excel ou arquivos para o word\) e ativem a interface do aplicativo nativo do documento na área do cliente de [contêiner do documento ativo](../mfc/active-document-containers.md) como a pasta ou Microsoft Internet Explorer do Microsoft Office.  Os contêineres atuam como clientes, quando os documentos são fornecidos por [servidores ativas do documento](../mfc/active-document-servers.md).  Para obter mais informações sobre como usar documentos ativos em aplicativos da web, consulte: [Documentos ativos na Internet](../Topic/Active%20Documents%20on%20the%20Internet.md).  
  
-   Os controles ActiveX são os objetos interativos que podem ser usadas em contêineres como um site.  Para obter mais informações sobre os controles ActiveX, consulte:  
  
    -   [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)  
  
    -   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
    -   [Visão geral: Internet](../mfc/mfc-internet-programming-basics.md)  
  
    -   [Atualizar um controle ActiveX existente a ser usado na Internet](../Topic/Upgrading%20an%20Existing%20ActiveX%20Control.md)  
  
    -   [Depurando um controle ActiveX](../Topic/How%20to:%20Debug%20an%20ActiveX%20Control.md)  
  
-   O script ativo controla o comportamento integrado de um ou mais controles ActiveX de um navegador ou de um servidor.  Para obter mais informações sobre o script ativo, consulte [Tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md).  
  
-   [Automação](../mfc/automation.md) \(anteriormente conhecido como a Automação OLE\) possibilita para que um aplicativo manipule os objetos implementados em outro aplicativo, ou “para” exp\-los objetos para que possa ser manipulado.  
  
     O objeto pode ser automatizado local ou [remotos](../mfc/remote-automation.md) \(em outro computador acessível por uma rede\).  Está disponível para a automação OLE e objetos COM.  
  
-   Esta seção também fornece informações sobre como escrever componentes COM que usam o MFC, por exemplo, em [Pontos de conexão](../mfc/connection-points.md).  
  
 Para uma discussão de que é chamada ainda OLE no que é chamado agora tecnologia ativa, consulte os tópicos em [OLE](../mfc/ole-in-mfc.md).  
  
 Além disso, consulte o artigo da Base de Dados de Conhecimento Q248019: HOWTO: Impede que a caixa de diálogo ocupado de servidor são exibidas durante uma operação demorada COM.  
  
## Nesta seção  
 [Retenção do documento ativo](../mfc/active-document-containment.md)  
  
 [Automação](../mfc/automation.md)  
  
 [Automação remoto](../mfc/remote-automation.md)  
  
 [Pontos de conexão](../mfc/connection-points.md)  
  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)