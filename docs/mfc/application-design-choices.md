---
title: Opções de design do aplicativo
ms.date: 11/04/2016
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
ms.openlocfilehash: b9b794070d1c4ff4f05f33895a7af5532a524ad1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602924"
---
# <a name="application-design-choices"></a>Opções de design do aplicativo

Este artigo discute alguns dos problemas de design a considerar ao programar para a Internet.

Os tópicos abordados neste artigo incluem:

- [Intranet em comparação com a Internet](#_core_intranet_versus_internet)

- [Aplicativo cliente ou servidor](#_core_client_or_server_application)

- [](#_core_the_web_page)

- [Navegador ou aplicativo autônomo](#_core_browser_or_standalone)

- [COM a Internet](#_core_com_on_the_internet)

- [Baixe o dados do cliente dos serviços](#_core_client_data_download_services)

Se você estiver pronto para começar a escrever o seu programa agora, consulte [escrever aplicativos do MFC](../mfc/writing-mfc-applications.md).

##  <a name="_core_intranet_versus_internet"></a> Intranet em comparação com a Internet

Muitos aplicativos executados na Internet e são acessíveis para qualquer pessoa com um navegador e o acesso à Internet. As empresas também estão implementando intranets, que são redes de toda a empresa usando protocolos TCP/IP e navegadores da Web. Intranets oferecem uma fonte central, pode ser atualizada facilmente para obter informações de toda a empresa. Eles podem ser usados para atualização de software, para entregar e tabulando pesquisas, para suporte ao cliente e para entrega de informações. A tabela a seguir compara os recursos da Internet e intranets.

|Internet|Intranet|
|--------------|--------------|
|Largura de banda baixa|Largura de banda alta|
|Segurança de redução de dados e sistemas|Acesso controlado aos sistemas e dados|
|Controle mínimo de conteúdo|Controle de conteúdo de alta|

##  <a name="_core_client_or_server_application"></a> Aplicativo cliente ou servidor

Seu aplicativo pode ser executado em um computador servidor ou em um computador cliente. Seu aplicativo pode também ser armazenado em um servidor e, em seguida, baixado da Internet e executar em um computador cliente. Classes WinInet MFC são usadas para aplicativos cliente para baixar arquivos. MFC e classes moniker assíncronas são usadas para baixar arquivos e propriedades do controle. Classes para controles ActiveX e documentos ativos são usadas para aplicativos cliente e para aplicativos que são baixados do servidor para ser executado em um cliente.

##  <a name="_core_the_web_page"></a> A página da Web: HTML, documentos do Active Directory, ActiveX controles

A Microsoft oferece várias maneiras de fornecer conteúdo em uma página da Web. Páginas da Web pode usar o padrão HTML ou HTML extensões, como a marca object, para fornecer conteúdo dinâmico, como controles ActiveX.

Navegadores da Web normalmente exibem páginas HTML. Documentos ativos também podem exibir os dados do aplicativo na interface ponto-e-clicar simple de um navegador habilitado para COM. O servidor de documento ativo pode exibir seu documento, o quadro completo em toda a área cliente, com seus próprios menus e barras de ferramentas.

Você escreve os controles ActiveX podem ser baixados de forma assíncrona do servidor e exibidos em uma página da Web. Você pode usar uma linguagem de script como VBScript para executar a validação do lado do cliente antes de enviar informações para o servidor.

##  <a name="_core_browser_or_standalone"></a> Navegador ou aplicativo autônomo

Você pode escrever controles ActiveX que são inseridos em uma página HTML e servidores de documentos ativos que são exibidos em um navegador. Você pode escrever páginas HTML que contém um botão para enviar uma solicitação para executar seu aplicativo ISAPI em um servidor Web. Você pode escrever um aplicativo autônomo que usa protocolos de Internet para baixar arquivos e exibir as informações para o usuário, sem nunca, usando um aplicativo de navegador.

##  <a name="_core_com_on_the_internet"></a> COM a Internet

Controles ActiveX, documentos ativos e monikers assíncronos usam tecnologias de COM (Component Object Model).

Controles ActiveX fornecem conteúdo dinâmico para documentos e páginas em sites da Internet. Com, você pode criar controles ActiveX e documentos de quadro completo usando documentos do Active Directory.

Monikers assíncronos fornecem recursos para ativar um controle executar bem em um ambiente de Internet, incluindo um incremental ou progressivo significa para baixar os dados. Controles também devem funcionar bem com outros controles que podem também ser recuperar seus dados de maneira assíncrona ao mesmo tempo.

##  <a name="_core_client_data_download_services"></a> Baixe o dados do cliente dos serviços

Dois conjuntos de APIs que o ajudará a transferir dados para seu cliente são WinInet e monikers assíncronos. Se você tiver grandes GIF e arquivos. avi e controles ActiveX em sua página HTML, você pode aumentar a capacidade de resposta para o usuário ao baixar de forma assíncrona, usando monikers assíncronos ou usando o WinInet de forma assíncrona.

Uma tarefa comum na Internet estiver transferindo dados. Se você já estiver usando a tecnologia do Active Directory (por exemplo, se você tiver um controle ActiveX), você pode usar monikers assíncronos para renderizar progressivamente dados à medida que o download. Você pode usar o WinInet para transferir dados usando protocolos de Internet comuns, como HTTP, FTP e gopher. Ambos os métodos oferecem independência de protocolo e fornecem uma camada abstrata usando TCP/IP e o WinSock. Você ainda pode usar [WinSock](../mfc/windows-sockets-in-mfc.md) diretamente.

A tabela a seguir resume as várias maneiras de usar o MFC para transferir dados pela Internet.

|Use este protocolo|Sob essas condições|Usando essas classes|
|-----------------------|----------------------------|-------------------------|
|[Internet baixando usando Monikers assíncronos](../mfc/asynchronous-monikers-on-the-internet.md)|Para a transferência assíncrona usando COM, controles ActiveX e qualquer protocolo de Internet.|[CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md), [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)|
|[WinInet](../mfc/win32-internet-extensions-wininet.md)|Para protocolos de Internet para HTTP, FTP e gopher. Dados podem ser transferidos de forma síncrona ou assíncrona e são armazenados em um cache de todo o sistema.|[CInternetSession](../mfc/reference/cinternetsession-class.md), [CFtpFileFind](../mfc/reference/cftpfilefind-class.md), [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)e muito mais.|
|[WinSock](../mfc/windows-sockets-in-mfc.md)|Para obter a máxima eficiência e controle. Exige a compreensão dos soquetes e protocolos TCP/IP.|[CSocket](../mfc/reference/csocket-class.md), [CAsyncSocket](../mfc/reference/casyncsocket-class.md)|

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)

