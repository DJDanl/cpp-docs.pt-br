---
title: "Opções de Design de aplicativo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4b78c4c086b40f786d86411c99279245704a48a8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="application-design-choices"></a>Opções de design do aplicativo
Este artigo aborda alguns dos problemas de design a serem considerados ao programar para a Internet.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Intranet ou da Internet](#_core_intranet_versus_internet)  
  
-   [Aplicativo cliente ou servidor](#_core_client_or_server_application)  
  
-   [](#_core_the_web_page)  
  
-   [Navegador ou aplicativo autônomo](#_core_browser_or_standalone)  
  
-   [COM a Internet](#_core_com_on_the_internet)  
  
-   [Serviços de Download do cliente de dados](#_core_client_data_download_services)  
  
 Se você estiver pronto para começar a escrever seu programa agora, consulte [escrever aplicativos do MFC](../mfc/writing-mfc-applications.md).  
  
##  <a name="_core_intranet_versus_internet"></a>Intranet ou da Internet  
 Muitos aplicativos executados na Internet e estão acessíveis para qualquer pessoa com um navegador e o acesso à Internet. As empresas também estiver implementando intranets, que são redes de toda a empresa usando os protocolos TCP/IP e navegadores da Web. Intranets oferecem uma fonte facilmente atualizável, central de informações de toda a empresa. Eles podem ser usados para atualização de software, para o fornecimento e a organização pesquisas, para suporte ao cliente e para o fornecimento de informações. A tabela a seguir compara os recursos de Internet e intranets.  
  
|Internet|Intranet|  
|--------------|--------------|  
|Largura de banda baixa|Largura de banda alta|  
|Segurança de redução de dados e sistemas|Acesso controlado a sistemas e dados|  
|Controle mínimo de conteúdo|Controle alta de conteúdo|  
  
##  <a name="_core_client_or_server_application"></a>Aplicativo cliente ou servidor  
 Seu aplicativo pode ser executado em um computador servidor ou em um computador cliente. Seu aplicativo pode também ser armazenado em um servidor e, em seguida, baixado da Internet e execute em um computador cliente. Classes WinInet MFC são usados para aplicativos cliente para baixar arquivos. MFC e classes do moniker assíncronas são usados para baixar os arquivos e as propriedades de controle. Classes para controles ActiveX e documentos ativos são usadas para aplicativos cliente e para aplicativos que são baixados do servidor para executar em um cliente.  
  
##  <a name="_core_the_web_page"></a>A página da Web: Controles de ActiveX HTML, documentos ativos,  
 A Microsoft oferece várias maneiras de fornecer conteúdo em uma página da Web. Páginas da Web pode usar HTML ou HTML padrão extensões, como a marca do objeto, para fornecer conteúdo dinâmico, como controles ActiveX.  
  
 Navegadores da Web geralmente exibir páginas HTML. Documentos ativos também podem exibir os dados do aplicativo na interface de apontar e clicar simple de um navegador habilitado para COM. Seu servidor de documento ativo pode exibir o documento, o quadro completo em toda a área cliente, com seus próprios menus e barras de ferramentas.  
  
 Controles ActiveX que você escreve podem ser baixados de forma assíncrona do servidor e exibidos em uma página da Web. Você pode usar uma linguagem de script, como VBScript para executar a validação do lado do cliente antes de enviar informações para o servidor.  
  
##  <a name="_core_browser_or_standalone"></a>Navegador ou aplicativo autônomo  
 Você pode escrever os controles ActiveX que são inseridos em uma página HTML e servidores de documentos ativos que são exibidos em um navegador. Você pode gravar páginas HTML que contém um botão para enviar uma solicitação para executar seu aplicativo ISAPI em um servidor Web. Você pode escrever um aplicativo autônomo que usa protocolos de Internet para baixar os arquivos e exibir as informações para o usuário, sem nunca usando um aplicativo de navegador.  
  
##  <a name="_core_com_on_the_internet"></a>COM a Internet  
 Controles ActiveX, documentos ativos e monikers assíncronos usam tecnologias de COM (Component Object Model).  
  
 Controles ActiveX fornecem conteúdo dinâmico para documentos e páginas em sites da Internet. Com o COM, você pode criar documentos de quadro completo usando documentos ativos e controles ActiveX.  
  
 Monikers assíncronos fornecem recursos para ativar um controle executar bem em um ambiente de Internet, incluindo um incremental ou progressivo significa para baixar os dados. Controles também devem funcionar bem com outros controles que podem também ser recuperar seus dados de forma assíncrona ao mesmo tempo.  
  
##  <a name="_core_client_data_download_services"></a>Serviços de Download do cliente de dados  
 Dois conjuntos de APIs que ajudará a transferir dados para o seu cliente são WinInet e monikers assíncronos. Se você tiver grandes GIF e arquivos. avi e controles ActiveX na página HTML, você pode aumentar a capacidade de resposta para o usuário, de forma assíncrona, baixando usando monikers assíncronos ou usando WinInet de forma assíncrona.  
  
 Uma tarefa comum na Internet estiver transferindo dados. Se você já estiver usando a tecnologia ativa (por exemplo, se você tiver um controle ActiveX), você pode usar monikers assíncronos progressivamente processar dados como baixa. Você pode usar WinInet para transferir dados usando protocolos de Internet como HTTP, FTP e gopher. Ambos os métodos fornecem independência de protocolo e fornecem uma camada abstrata usando TCP/IP e WinSock. Você ainda pode usar [WinSock](../mfc/windows-sockets-in-mfc.md) diretamente.  
  
 A tabela a seguir resume as várias maneiras de usar MFC para transferir dados pela Internet.  
  
|Use este protocolo|Sob essas condições|Usando essas classes|  
|-----------------------|----------------------------|-------------------------|  
|[Internet baixando usando Monikers assíncronos](../mfc/asynchronous-monikers-on-the-internet.md)|Para a transferência assíncrona usando COM, controles ActiveX e qualquer protocolo de Internet.|[CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md), [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)|  
|[WinInet](../mfc/win32-internet-extensions-wininet.md)|Para protocolos de Internet para HTTP, FTP e gopher. Dados podem ser transferidos de forma síncrona ou assíncrona e são armazenados em um cache de todo o sistema.|[CInternetSession](../mfc/reference/cinternetsession-class.md), [CFtpFileFind](../mfc/reference/cftpfilefind-class.md), [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md)e muito mais.|  
|[WinSock](../mfc/windows-sockets-in-mfc.md)|Para máxima eficiência e controle. Requer a compreensão dos soquetes e protocolos TCP/IP.|[CSocket](../mfc/reference/csocket-class.md), [CAsyncSocket](../mfc/reference/casyncsocket-class.md)|  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação de Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)

