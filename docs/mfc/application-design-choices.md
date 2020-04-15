---
title: Opções de design do aplicativo
ms.date: 09/12/2019
helpviewer_keywords:
- design
- application design [MFC], design goals
- application design [MFC], Internet applications
- Internet applications [MFC], designing applications
- Internet [MFC], vs. intranets
- applications [MFC], Internet
- server applications [MFC], vs. client applications on Internet
- client applications [MFC], vs. server applications on Internet
ms.assetid: 9b96172c-b4d4-4c69-bfb2-226ce0de6d08
ms.openlocfilehash: 89f3e5c108de1cf7b3b73a33a08e2c50b1333c92
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374637"
---
# <a name="application-design-choices"></a>Opções de design do aplicativo

Este artigo discute algumas das questões de design a serem consideradas na programação para a Internet.

Os tópicos abordados neste artigo incluem:

- [Intranet Versus Internet](#_core_intranet_versus_internet)

- [Aplicativo cliente ou servidor](#_core_client_or_server_application)

- [A Página web](#_core_the_web_page)

- [Aplicativo de navegador ou autônomo](#_core_browser_or_standalone)

- [COM na Internet](#_core_com_on_the_internet)

- [Serviços de download de dados do cliente](#_core_client_data_download_services)

Se você estiver pronto para começar a escrever seu programa agora, consulte [Escrevendo aplicativos MFC](../mfc/writing-mfc-applications.md).

## <a name="intranet-versus-internet"></a><a name="_core_intranet_versus_internet"></a>Intranet Versus Internet

Muitos aplicativos são executados na Internet e são acessíveis a qualquer pessoa com um navegador e acesso à Internet. As empresas também estão implementando intranets, que são redes de toda a empresa usando protocolos TCP/IP e navegadores da Web. A Intranets oferece uma fonte central facilmente atualizada para informações em toda a empresa. Eles podem ser usados para atualizar softwares, para fornecer e tabular pesquisas, para suporte ao cliente e para entrega de informações. A tabela a seguir compara características da Internet e intranets.

|Internet|Intranet|
|--------------|--------------|
|Largura de banda baixa|Largura de banda alta|
|Redução da segurança de dados e sistemas|Acesso controlado a dados e sistemas|
|Controle mínimo de conteúdo|Alto controle de conteúdo|

## <a name="client-or-server-application"></a><a name="_core_client_or_server_application"></a>Aplicativo cliente ou servidor

Seu aplicativo pode ser executado em um computador cliente ou em um computador de servidor. Seu aplicativo também pode ser armazenado em um servidor e, em seguida, baixado na Internet e executado em um computador cliente. As classes MFC WinInet são usadas para aplicativos clientes para baixar arquivos. MFC e classes de apelidos assíncronos são usados para baixar arquivos e controlar propriedades. Classes para controles ActiveX e documentos ativos são usadas para aplicativos clientes e para aplicativos que são baixados do servidor para serem executados em um cliente.

## <a name="the-web-page-html-active-documents-activex-controls"></a><a name="_core_the_web_page"></a>Página da Web: HTML, Documentos Ativos, Controles ActiveX

A Microsoft oferece várias maneiras de fornecer conteúdo em uma página da Web. As páginas da Web podem usar extensões PADRÃO HTML ou HTML, como a tag de objeto, para fornecer conteúdo dinâmico, como controles ActiveX.

Os navegadores da Web normalmente exibem páginas HTML. Documentos ativos também podem exibir os dados do seu aplicativo na interface simples de ponto e clique de um navegador habilitado para COM. Seu servidor de documentos Ativo pode exibir seu documento, full frame em toda a área do cliente, com seus próprios menus e barras de ferramentas.

Os controles ActiveX que você escreve podem ser baixados assíncronamente do servidor e exibidos em uma página da Web. Você pode usar um idioma de script, como o VBScript, para executar a validação do lado do cliente antes de enviar informações para o servidor.

## <a name="browser-or-stand-alone-application"></a><a name="_core_browser_or_standalone"></a>Aplicativo de navegador ou autônomo

Você pode escrever controles ActiveX que estão incorporados em uma página HTML e servidores de documentos ativos que são visualizados em um navegador. Você pode escrever páginas HTML que contenham um botão para enviar uma solicitação para executar seu aplicativo ISAPI em um servidor Web. Você pode escrever um aplicativo autônomo que usa protocolos da Internet para baixar arquivos e exibir as informações para o seu usuário, sem nunca usar um aplicativo do navegador.

## <a name="com-on-the-internet"></a><a name="_core_com_on_the_internet"></a>COM na Internet

Controles ActiveX, documentos ativos e apelidos assíncronos usam tecnologias COM (Component Object Model).

Os controles ActiveX fornecem conteúdo dinâmico para documentos e páginas em sites da Internet. Com o COM, você pode criar controles ActiveX e documentos full-frame usando documentos Ativos.

Os apelidos assíncronos fornecem recursos para permitir que um controle tenha um bom desempenho em um ambiente da Internet, incluindo um meio incremental ou progressivo para baixar dados. Os controles também devem funcionar bem com outros controles que também podem estar recuperando seus dados assíncronamente ao mesmo tempo.

## <a name="client-data-download-services"></a><a name="_core_client_data_download_services"></a>Serviços de download de dados do cliente

Dois conjuntos de APIs que ajudarão a transferir dados para seu cliente são nomes WinInet e assíncronos. Se você tiver arquivos .gif e .avi grandes e controles ActiveX em sua página HTML, você pode aumentar a capacidade de resposta ao usuário baixando assíncronamente, usando apelidos assíncronos ou usando WinInet assíncronamente.

Uma tarefa comum na Internet é transferir dados. Se você já estiver usando a tecnologia Active (por exemplo, se você tiver um controle ActiveX), você pode usar apelidos assíncronos para renderizar progressivamente os dados à medida que ele baixa. Você pode usar o WinInet para transferir dados usando protocolos comuns da Internet como HTTP, FTP e gopher. Ambos os métodos fornecem independência de protocolo e fornecem uma camada abstrata para usar WinSock e TCP/IP. Você ainda pode usar [o WinSock](../mfc/windows-sockets-in-mfc.md) diretamente.

A tabela a seguir resume várias maneiras de usar o MFC para transferir dados pela Internet.

|Use este protocolo|Nessas condições|Usando essas classes|
|-----------------------|----------------------------|-------------------------|
|[Download da Internet usando apelidos assíncronos](../mfc/asynchronous-monikers-on-the-internet.md)|Para transferência assíncrona usando com, controles ActiveX e qualquer protocolo da Internet.|[CAsyncMonikerFile,](../mfc/reference/casyncmonikerfile-class.md) [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)|
|[WinInet](../mfc/win32-internet-extensions-wininet.md)|Para protocolos de Internet para HTTP, FTP e gopher. Os dados podem ser transferidos de forma sincronizada ou assíncrona e são armazenados em um cache em todo o sistema.|[CInternetSession,](../mfc/reference/cinternetsession-class.md) [CFtpFileFind,](../mfc/reference/cftpfilefind-class.md) [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)e muito mais.|
|[Winsock](../mfc/windows-sockets-in-mfc.md)|Para máxima eficiência e controle. Requer a compreensão de soquetes e protocolos TCP/IP.|[CSocket,](../mfc/reference/csocket-class.md) [CasyncSocket](../mfc/reference/casyncsocket-class.md)|

## <a name="see-also"></a>Confira também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet Do MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)
