---
title: "No&#231;&#245;es b&#225;sicas de programa&#231;&#227;o da Internet MFC | Microsoft Docs"
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
  - "Tecnologia ativa [C++]"
  - "Controles ActiveX [C++], Internet"
  - "Aplicativos da Internet [C++]"
  - "Aplicativos da Internet [C++], Tecnologia ativa"
  - "Aplicativos da Internet [C++], Controles ActiveX"
  - "Aplicativos da Internet [C++], gravando"
  - "Conteúdo de Internet [C++]"
  - "ISAPI"
  - "Extensões ISAPI, programando com ISAPI"
  - "Filtros ISAPI, programando com ISAPI"
  - "programação [C++], Internet"
  - "aplicativos da Web [C++], Classes MFC"
  - "Classes WinInet"
ms.assetid: 6df2dfd0-6e3f-4587-9d01-2a32f00f8a6f
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de programa&#231;&#227;o da Internet MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Microsoft fornece muitas APIs para o cliente de programação e aplicativos de servidor.  Muitas novos aplicativos estão sendo gravados para a Internet, e como as tecnologias, os recursos do navegador, e as opções de segurança são alterados, os novos tipos de aplicativos serão gravados.  Os navegadores são executados nos computadores cliente, fornecendo acesso ao W3C \(World Wide Web e exibindo as páginas HTML que contêm o texto, os gráficos, os controles ActiveX, e os documentos.  Servidores fornece FTP, HTTP, e os serviços de Gopher, e aplicativos de extensão do servidor por meio do cgi.  Seu aplicativo personalizado pode recuperar informações e fornecer dados na Internet.  
  
 ![Aplicativos cliente&#47;servidor](../mfc/media/vc38bq1.png "vc38BQ1")  
  
 MFC O fornece classes que oferecem suporte à programação da Internet.  Você pode usar [COleControl](../mfc/reference/colecontrol-class.md) e [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) e classes relacionadas MFC para gravar controles ActiveX e documentos ativas.  Você pode usar classes de MFC como [CInternetSession](../Topic/CInternetSession%20Class.md), [CFtpConnection](../mfc/reference/cftpconnection-class.md), e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) para recuperar arquivos e protocolos usando informações da Internet como FTP, HTTP, e o Gopher.  
  
## Nesta seção  
  
-   [Classes de MFC relacionados](../mfc/internet-related-mfc-classes.md)  
  
-   [Informações da internet\) o tópico](../Topic/Internet%20Information%20by%20Topic.md)  
  
-   [Informações da internet\) pela tarefa](../mfc/internet-information-by-task.md)  
  
-   [Tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md)  
  
-   [Fundamentos de WinInet](../mfc/wininet-basics.md)  
  
-   [Fundamentos de HTML](../mfc/html-basics.md)  
  
-   [Fundamentos de HTTP](../mfc/http-basics.md)  
  
## Seções relacionadas  
  
-   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
-   [Documentos ativos na Internet](../Topic/Active%20Documents%20on%20the%20Internet.md)  
  
-   [Apelidos assíncrona na Internet](../mfc/asynchronous-monikers-on-the-internet.md)  
  
-   [Extensões do Win32 a Internet \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)  
  
-   [Tarefas de Programação MFC Internet](../mfc/mfc-internet-programming-tasks.md)  
  
-   [Opções de criação de aplicativo](../mfc/application-design-choices.md)  
  
-   [MFC a gravação de aplicativos](../mfc/writing-mfc-applications.md)  
  
-   [Aplicativos da Internet de teste](../mfc/testing-internet-applications.md)  
  
-   [Segurança da Internet](../Topic/Internet%20Security%20\(C++\).md)  
  
-   [Suporte de ATL para controles do DHTML](../atl/atl-support-for-dhtml-controls.md)  
  
##  <a name="_core_web_sites_for_more_information"></a> Sites para obter mais informações  
 Para obter informações adicionais sobre a tecnologia da Microsoft Internet, consulte [Microsoft developer network \(MSDN\)](http://go.microsoft.com/fwlink/?LinkID=56322) o site. \(Links pode ser alterado sem aviso prévio.\)  
  
 Este site para desenvolvedores contém informações sobre como usar ferramentas e tecnologias de desenvolvimento da Microsoft, e sobre conferências notícias as principais e próximos recentes.  Nessa página, você pode ignorar a muitos sites relacionadas do desenvolvedor, incluindo os centros do desenvolvedor do .NET, e XML.  Você também pode baixar beta SDKs e exemplos.  
  
 [O World Wide Web Consortium \(W3C\)](http://go.microsoft.com/fwlink/?LinkID=37125) Publica especificações para HTML, HTTP, o cgi, e outras tecnologias da World Wide Web.  
  
##  <a name="_core_more_internet_help"></a> Mais ajuda da Internet  
 A seção de OLE [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)] contém informações adicionais sobre como programar OLE.  Essas informações fornecem detalhes sobre o usando as funções do Win32 WinInet diretamente, em vez de pelas classes MFC.  Também contêm informações de visão geral sobre tecnologias da Internet.  
  
## Consulte também  
 [MFC Internet Programming \(NIB\)](http://msdn.microsoft.com/pt-br/0f7a1f3a-385b-4d56-a55b-0d766840c58a)