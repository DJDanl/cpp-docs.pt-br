---
title: Noções básicas de programação do MFC da Internet | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
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
ms.openlocfilehash: b2be02e6cac5dac226f7b04cd627a292e3761980
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50082665"
---
# <a name="mfc-internet-programming-basics"></a>Noções básicas de programação da Internet MFC

Microsoft fornece várias APIs para programar aplicativos de cliente e servidor. Muitos aplicativos novos estão sendo gravados para a Internet, e como tecnologias, recursos do navegador e opções de segurança mudam, novos tipos de aplicativos serão gravados. Navegadores executados em computadores cliente, fornecendo acesso a World Wide Web e exibir páginas HTML que contêm texto, gráficos, controles ActiveX e documentos. Servidores fornecem FTP, HTTP e os serviços de gopher e executam aplicativos de extensão de servidor usando CGI. Seu aplicativo personalizado pode recuperar as informações e fornecem dados sobre a Internet.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

![Aplicativos cliente e servidor](../mfc/media/vc38bq1.gif "vc38bq1")

O MFC fornece classes que dão suporte à programação da Internet. Você pode usar [COleControl](../mfc/reference/colecontrol-class.md) e [CDocObjectServer](../mfc/reference/cdocobjectserver-class.md) e as classes MFC para gravar documentos ativos e controles ActiveX relacionadas. Você pode usar classes do MFC, como [CInternetSession](../mfc/reference/cinternetsession-class.md), [CFtpConnection](../mfc/reference/cftpconnection-class.md), e [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md) para recuperar informações usando protocolos de Internet, como FTP e arquivos HTTP e gopher.

## <a name="in-this-section"></a>Nesta seção

- [Classes MFC relacionadas à Internet](../mfc/internet-related-mfc-classes.md)

- [Informações da Internet por tópico](../mfc/internet-information-by-topic.md)

- [Informações da Internet por tarefa](../mfc/internet-information-by-task.md)

- [Tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md)

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

- [Segurança da Internet](../mfc/internet-security-cpp.md)

- [Suporte da ATL para controles DHTML](../atl/atl-support-for-dhtml-controls.md)

##  <a name="_core_web_sites_for_more_information"></a> Sites da Web para obter mais informações

Para obter informações adicionais sobre a tecnologia de Internet da Microsoft, consulte o [Microsoft Developer Network (MSDN)](http://go.microsoft.com/fwlink/p/?linkid=56322) site da Web. (Links podem ser alteradas sem aviso prévio.)

Este site da Web para os desenvolvedores contém informações sobre como usar ferramentas de desenvolvimento da Microsoft e as tecnologias e as principais histórias sobre conferências recentes e futuras. Nessa página, você pode ir para muitos sites relacionados para desenvolvedores, incluindo o .NET e XML Developer Centers. Você também pode baixar exemplos e SDKs de beta.

O [World Wide Web Consortium (W3C)](http://go.microsoft.com/fwlink/p/?linkid=37125) publica as especificações do HTML, HTTP, CGI e outras tecnologias de World Wide Web.

##  <a name="_core_more_internet_help"></a> Mais ajuda da Internet

A seção OLE do SDK do Windows contém informações adicionais sobre a programação de OLE. Essas informações fornecem detalhes sobre como usar as funções Win32 WinInet diretamente, em vez de por meio de classes do MFC. Ele também contém informações de visão geral sobre tecnologias da Internet.

## <a name="see-also"></a>Consulte também

