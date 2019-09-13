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
ms.openlocfilehash: b205599ed3bf33e84516120b1855482797b86c9b
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70924910"
---
# <a name="application-design-choices"></a>Opções de design do aplicativo

Este artigo discute alguns dos problemas de design a serem considerados ao programar para a Internet.

Os tópicos abordados neste artigo incluem:

- [Intranet versus Internet](#_core_intranet_versus_internet)

- [Aplicativo cliente ou servidor](#_core_client_or_server_application)

- [A página da Web](#_core_the_web_page)

- [Navegador ou aplicativo autônomo](#_core_browser_or_standalone)

- [COM na Internet](#_core_com_on_the_internet)

- [Serviços de download de dados do cliente](#_core_client_data_download_services)

Se você estiver pronto para começar a escrever seu programa agora, consulte [Writing MFC Applications](../mfc/writing-mfc-applications.md).

##  <a name="_core_intranet_versus_internet"></a>Intranet versus Internet

Muitos aplicativos são executados na Internet e podem ser acessados por qualquer pessoa com um navegador e acesso à Internet. As empresas também estão implementando intranets, que são redes de toda a empresa usando protocolos TCP/IP e navegadores da Web. As intranets oferecem uma fonte central facilmente atualizável para informações de toda a empresa. Eles podem ser usados para atualizar o software, para entrega e Tabulação de pesquisas, para o atendimento ao cliente e para a distribuição de informações. A tabela a seguir compara os recursos da Internet e intranets.

|Internet|Intranet|
|--------------|--------------|
|Baixa largura de banda|Largura de banda alta|
|Redução da segurança de dados e sistemas|Acesso controlado a dados e sistemas|
|Controle mínimo de conteúdo|Alto controle de conteúdo|

##  <a name="_core_client_or_server_application"></a>Aplicativo cliente ou servidor

Seu aplicativo pode ser executado em um computador cliente ou em um computador servidor. Seu aplicativo também pode ser armazenado em um servidor e, em seguida, baixado pela Internet e executado em um computador cliente. As classes do MFC WinInet são usadas para aplicativos cliente baixarem arquivos. As classes MFC e de moniker assíncrono são usadas para baixar arquivos e propriedades de controle. As classes para controles ActiveX e documentos ativos são usadas para aplicativos cliente e para aplicativos que são baixados do servidor para serem executados em um cliente.

##  <a name="_core_the_web_page"></a>A página da Web: HTML, documentos ativos, controles ActiveX

A Microsoft oferece várias maneiras de fornecer conteúdo em uma página da Web. As páginas da Web podem usar extensões HTML ou HTML padrão, como a marca Object, para fornecer conteúdo dinâmico, como controles ActiveX.

Os navegadores da Web normalmente exibem páginas HTML. Os documentos ativos também podem exibir os dados do aplicativo na interface simples de apontar e clicar de um navegador habilitado para COM. O servidor de documentos ativo pode exibir seu documento, quadro completo em toda a área do cliente, com seus próprios menus e barras de ferramentas.

Os controles ActiveX que você escreve podem ser baixados assincronamente do servidor e exibidos em uma página da Web. Você pode usar uma linguagem de script, como o VBScript, para executar a validação do lado do cliente antes de enviar informações para o servidor.

##  <a name="_core_browser_or_standalone"></a>Navegador ou aplicativo autônomo

Você pode escrever controles ActiveX que são inseridos em uma página HTML e em servidores de documentos ativos que são exibidos em um navegador. Você pode escrever páginas HTML que contêm um botão para enviar uma solicitação para executar o aplicativo ISAPI em um servidor Web. Você pode escrever um aplicativo autônomo que usa protocolos de Internet para baixar arquivos e exibir as informações para o usuário, sem nunca usar um aplicativo de navegador.

##  <a name="_core_com_on_the_internet"></a>COM na Internet

Os controles ActiveX, os documentos ativos e os monikers assíncronos usam tecnologias COM (Component Object Model).

Os controles ActiveX fornecem conteúdo dinâmico para documentos e páginas em sites da Internet. Com o COM, você pode criar controles ActiveX e documentos de quadro completo usando documentos ativos.

Os monikers assíncronos fornecem recursos para permitir que um controle tenha um bom desempenho em um ambiente de Internet, incluindo um meio incremental ou progressivo de baixar dados. Os controles também devem funcionar bem com outros controles que também podem recuperar seus dados de forma assíncrona ao mesmo tempo.

##  <a name="_core_client_data_download_services"></a>Serviços de download de dados do cliente

Dois conjuntos de APIs que ajudarão a transferir dados para o cliente são os monikers WinInet e assíncronos. Se você tiver arquivos. gif e. avi grandes e controles ActiveX na sua página HTML, poderá aumentar a capacidade de resposta para o usuário baixando de forma assíncrona, seja usando monikers assíncronos ou usando o WinInet de forma assíncrona.

Uma tarefa comum na Internet é A transferência de dados. Se você já estiver usando a tecnologia ativa (por exemplo, se tiver um controle ActiveX), poderá usar monikers assíncronos para renderizar progressivamente os dados conforme eles forem baixados. Você pode usar o WinInet para transferir dados usando protocolos comuns de Internet, como HTTP, FTP e Gopher. Os dois métodos fornecem independência de protocolo e fornecem uma camada abstrata para usar WinSock e TCP/IP. Você ainda pode usar o [Winsock](../mfc/windows-sockets-in-mfc.md) diretamente.

A tabela a seguir resume várias maneiras de usar o MFC para transferir dados pela Internet.

|Usar este protocolo|Sob essas condições|Usando essas classes|
|-----------------------|----------------------------|-------------------------|
|[Download da Internet usando monikers assíncronos](../mfc/asynchronous-monikers-on-the-internet.md)|Para transferência assíncrona usando COM, controles ActiveX e qualquer protocolo de Internet.|[CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md), [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)|
|[WinInet](../mfc/win32-internet-extensions-wininet.md)|Para protocolos de Internet para HTTP, FTP e Gopher. Os dados podem ser transferidos de forma síncrona ou assíncrona e armazenados em um cache em todo o sistema.|[CInternetSession](../mfc/reference/cinternetsession-class.md), [CFtpFileFind](../mfc/reference/cftpfilefind-class.md), [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)e muito mais.|
|[WinSock](../mfc/windows-sockets-in-mfc.md)|Para obter o máximo de eficiência e controle. Requer a compreensão de soquetes e protocolos TCP/IP.|[CSocket](../mfc/reference/csocket-class.md), [CAsyncSocket](../mfc/reference/casyncsocket-class.md)|

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)
