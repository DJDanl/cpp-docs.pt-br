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
ms.openlocfilehash: 5a8fb7bf07ec631869075c5977dcec468143ad56
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366282"
---
# <a name="mfc-internet-programming-basics"></a>Noções básicas de programação da Internet MFC

A Microsoft fornece muitas APIs para programar aplicativos de clientes e servidores. Muitos novos aplicativos estão sendo escritos para a Internet e, à medida que as tecnologias, os recursos do navegador e as opções de segurança mudam, novos tipos de aplicativos serão escritos. Os navegadores são executados em computadores clientes, fornecendo acesso à World Wide Web e exibindo páginas HTML que contêm texto, gráficos, controles ActiveX e documentos. Os servidores fornecem serviços FTP, HTTP e gopher e executam aplicativos de extensão de servidor usando CGI. Seu aplicativo personalizado pode recuperar informações e fornecer dados na Internet.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [ActiveX Controls](activex-controls.md).

![Aplicativos de clientes e servidores](../mfc/media/vc38bq1.gif "Aplicativos de clientes e servidores")

O MFC oferece aulas que suportam a programação da Internet. Você pode usar [COleControl](../mfc/reference/colecontrol-class.md) e [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) e classes MFC relacionadas para escrever controles ActiveX e documentos Ativos. Você pode usar classes MFC como [CInternetSession,](../mfc/reference/cinternetsession-class.md) [CFtpConnection](../mfc/reference/cftpconnection-class.md)e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) para recuperar arquivos e informações usando protocolos da Internet como FTP, HTTP e gopher.

## <a name="in-this-section"></a>Nesta seção

- [Classes MFC relacionadas à Internet](../mfc/internet-related-mfc-classes.md)

- [Informações da Internet por tópico](../mfc/internet-information-by-topic.md)

- [Informações da Internet por tarefa](../mfc/internet-information-by-task.md)

- [Tecnologia Ativa na Internet](../mfc/active-technology-on-the-internet.md)

- [Noções básicas de WinInet](../mfc/wininet-basics.md)

- [Noções básicas de HTML](../mfc/html-basics.md)

## <a name="related-sections"></a>Seções relacionadas

- [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)

- [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)

- [Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)

- [Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)

- [Opções de design do aplicativo](../mfc/application-design-choices.md)

- [Escrevendo aplicativos MFC](../mfc/writing-mfc-applications.md)

- [Testando aplicativos da Internet](../mfc/testing-internet-applications.md)

- [Segurança na Internet](../mfc/internet-security-cpp.md)

- [Suporte do ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)

## <a name="web-sites-for-more-information"></a><a name="_core_web_sites_for_more_information"></a>Sites para mais informações

Para obter informações adicionais sobre a tecnologia microsoft internet, consulte o site da [Microsoft Developer Network (MSDN).](https://go.microsoft.com/fwlink/p/?linkid=56322) (Os links podem ser alterar sem aviso prévio.)

Este site para desenvolvedores contém informações sobre o uso de ferramentas e tecnologias de desenvolvimento da Microsoft e as principais histórias sobre conferências recentes e futuras. A partir desta página, você pode saltar para muitos sites de desenvolvedores relacionados, incluindo o .NET e o XML Developer Centers. Você também pode baixar SDKs e amostras beta.

O [World Wide Web Consortium (W3C)](https://go.microsoft.com/fwlink/p/?linkid=37125) publica especificações para HTML, HTTP, CGI e outras tecnologias da World Wide Web.

## <a name="more-internet-help"></a><a name="_core_more_internet_help"></a>Mais ajuda na Internet

A seção OLE do Windows SDK contém informações adicionais sobre a programação OLE. Essas informações fornecem detalhes sobre o uso das funções Win32 WinInet diretamente, e não através das classes MFC. Ele também contém informações de visão geral sobre tecnologias de Internet.
