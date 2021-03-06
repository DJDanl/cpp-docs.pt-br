---
title: Noções básicas de programação da Internet MFC
ms.date: 11/19/2018
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
ms.openlocfilehash: b41ce97a9b5efe6ad84c543f5c49dd091557b3a8
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846310"
---
# <a name="mfc-internet-programming-basics"></a>Noções básicas de programação da Internet MFC

A Microsoft fornece muitas APIs para programação de aplicativos de cliente e servidor. Muitos aplicativos novos estão sendo escritos para a Internet e, como tecnologias, recursos de navegador e alteração de opções de segurança, novos tipos de aplicativos serão gravados. Os navegadores são executados em computadores cliente, fornecendo acesso ao World Wide Web e exibindo páginas HTML que contêm texto, gráficos, controles ActiveX e documentos. Os servidores fornecem serviços FTP, HTTP e Gopher e executam aplicativos de extensão de servidor usando CGI. Seu aplicativo personalizado pode recuperar informações e fornecer dados na Internet.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

![Aplicativos de cliente e servidor](../mfc/media/vc38bq1.gif "Aplicativos de cliente e servidor")

O MFC fornece classes que dão suporte à programação na Internet. Você pode usar [COleControl](reference/colecontrol-class.md) e [CDocObjectServer](reference/cdocobjectserver-class.md) e classes do MFC relacionadas para escrever controles ActiveX e documentos ativos. Você pode usar classes do MFC, como [CInternetSession](reference/cinternetsession-class.md), [CFtpConnection](reference/cftpconnection-class.md)e [CAsyncMonikerFile](reference/casyncmonikerfile-class.md) , para recuperar arquivos e informações usando protocolos de Internet, como FTP, http e Gopher.

## <a name="in-this-section"></a>Nesta seção

- [Classes do MFC relacionadas à Internet](internet-related-mfc-classes.md)

- [Informações da Internet por tópico](internet-information-by-topic.md)

- [Informações da Internet por tarefa](internet-information-by-task.md)

- [Tecnologia ativa na Internet](active-technology-on-the-internet.md)

- [Noções básicas do WinInet](wininet-basics.md)

- [Noções básicas de HTML](html-basics.md)

## <a name="related-sections"></a>Seções relacionadas

- [Controles ActiveX na Internet](activex-controls-on-the-internet.md)

- [Monikers assíncronos na Internet](asynchronous-monikers-on-the-internet.md)

- [WinInet (extensões de Internet do Win32)](win32-internet-extensions-wininet.md)

- [Tarefas de programação da Internet do MFC](mfc-internet-programming-tasks.md)

- [Opções de design de aplicativo](application-design-choices.md)

- [Gravando aplicativos MFC](writing-mfc-applications.md)

- [Testando aplicativos de Internet](testing-internet-applications.md)

- [Segurança da Internet](internet-security-cpp.md)

- [Suporte ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)

## <a name="websites-for-more-information"></a><a name="_core_web_sites_for_more_information"></a> Sites para obter mais informações

Para obter mais informações sobre a tecnologia de Internet da Microsoft, consulte [Networking and Internet](/windows/win32/networking).

O [World Wide Web Consortium (W3C)](https://go.microsoft.com/fwlink/p/?linkid=37125) publica especificações para HTML, http, CGI e outras tecnologias de World Wide Web.

## <a name="more-internet-help"></a><a name="_core_more_internet_help"></a> Mais ajuda da Internet

A seção OLE do SDK do Windows contém informações adicionais sobre a programação OLE. Essas informações fornecem detalhes sobre como usar as funções do Win32 WinInet diretamente, em vez das classes do MFC. Ele também contém informações gerais sobre tecnologias de Internet.
