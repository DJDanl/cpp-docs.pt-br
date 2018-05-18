---
title: Noções básicas de programação do MFC Internet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ISAPI extensions, programming with ISAPI
- Internet applications [MFC]
- ISAPI
- ActiveX controls [MFC], Internet
- programming [MFC], Internet
- Web applications [MFC], MFC classes
- ISAPI filters [MFC], programming with ISAPI
- Internet applications [MFC], ActiveX controls
- Internet applications [MFC], writing
- Internet applications [MFC], Active technology
- Active technology [MFC]
- Internet content [MFC]
- WinInet classes [MFC]
ms.assetid: 6df2dfd0-6e3f-4587-9d01-2a32f00f8a6f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6896daddc0eb900f9e2a29497eb2dd8a1dc78446
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
---
# <a name="mfc-internet-programming-basics"></a>Noções básicas de programação da Internet MFC
Microsoft oferece várias APIs para programação de aplicativos de cliente e servidor. Muitos novos aplicativos estão sendo gravados para a Internet, e como tecnologias, recursos do navegador e alteração de opções de segurança, os novos tipos de aplicativos serão gravados. Navegadores executados em computadores cliente, fornecendo acesso a World Wide Web e exibir páginas HTML que contém texto, gráficos, controles ActiveX e documentos. Servidores fornecem serviços gopher, HTTP e FTP e executam aplicativos de extensão de servidor usando CGI. Seu aplicativo personalizado pode recuperar as informações e fornecer dados na Internet.  
  
 ![Aplicativos cliente e servidor](../mfc/media/vc38bq1.gif "vc38bq1")  
  
 MFC fornece classes que oferecem suporte a programação da Internet. Você pode usar [COleControl](../mfc/reference/colecontrol-class.md) e [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) e classes do MFC para gravar os controles ActiveX e documentos ativos relacionadas. Você pode usar classes MFC como [CInternetSession](../mfc/reference/cinternetsession-class.md), [CFtpConnection](../mfc/reference/cftpconnection-class.md), e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) para recuperar arquivos e informações usando protocolos de Internet, como FTP, HTTP e gopher.  
  
## <a name="in-this-section"></a>Nesta seção  
  
-   [Classes MFC relacionadas à Internet](../mfc/internet-related-mfc-classes.md)  
  
-   [Informações da Internet por tópico](../mfc/internet-information-by-topic.md)  
  
-   [Informações da Internet por tarefa](../mfc/internet-information-by-task.md)  
  
-   [Tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md)  
  
-   [Noções básicas de WinInet](../mfc/wininet-basics.md)  
  
-   [Noções básicas de HTML](../mfc/html-basics.md)  
  
## <a name="related-sections"></a>Seções relacionadas  
  
-   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
-   [Documentos ativos na Internet](../mfc/active-documents-on-the-internet.md)  
  
-   [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)  
  
-   [Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)  
  
-   [Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)  
  
-   [Opções de design do aplicativo](../mfc/application-design-choices.md)  
  
-   [Escrevendo aplicativos MFC](../mfc/writing-mfc-applications.md)  
  
-   [Testando aplicativos da Internet](../mfc/testing-internet-applications.md)  
  
-   [Segurança da Internet](../mfc/internet-security-cpp.md)  
  
-   [Suporte da ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)  
  
##  <a name="_core_web_sites_for_more_information"></a> Sites da Web para obter mais informações  
 Para obter informações adicionais sobre a tecnologia de Internet da Microsoft, consulte o [Microsoft Developer Network (MSDN)](http://go.microsoft.com/fwlink/p/?linkid=56322) site da Web. (Links podem ser alteradas sem aviso prévio.)  
  
 Deste site para os desenvolvedores contém informações sobre como usar ferramentas de desenvolvimento da Microsoft e tecnologias e principais histórias sobre conferências recentes e futuras. Nessa página, você pode ir para vários sites de desenvolvedor relacionados, incluindo o .NET e centros de desenvolvedor de XML. Você também pode baixar exemplos e SDKs de beta.  
  
 O [World Wide Web Consortium (W3C)](http://go.microsoft.com/fwlink/p/?linkid=37125) publica especificações do HTML, HTTP, CGI e outras tecnologias da World Wide Web.  
  
##  <a name="_core_more_internet_help"></a> Obter ajuda da Internet  
 A seção OLE do SDK do Windows contém informações adicionais sobre a programação de OLE. Essas informações fornecem detalhes sobre como usar as funções WinInet Win32 diretamente, em vez de por meio das classes MFC. Ele também contém informações de visão geral sobre as tecnologias de Internet.  
  
## <a name="see-also"></a>Consulte também  



