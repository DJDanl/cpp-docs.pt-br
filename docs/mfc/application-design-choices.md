---
title: "Op&#231;&#245;es de design do aplicativo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "design de aplicativo [C++], objetivos de design"
  - "design de aplicativo [C++], aplicativos da Internet"
  - "aplicativos [MFC], Internet"
  - "aplicativos cliente [C++], vs. aplicativos de servidor na Internet"
  - "design"
  - "Internet [C++], vs. intranets"
  - "Aplicativos da Internet [C++], projetando aplicativos"
  - "aplicativos de servidor, vs. aplicativos cliente na Internet"
ms.assetid: 9b96172c-b4d4-4c69-bfb2-226ce0de6d08
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Op&#231;&#245;es de design do aplicativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve alguns dos problemas de design para considerar ao programar para a Internet.  
  
 Os tópicos abordados neste artigo incluem:  
  
-   [Intranet na Internet](#_core_intranet_versus_internet)  
  
-   [Cliente ou aplicativo de servidor](#_core_client_or_server_application)  
  
-   [A página da Web: HTML, documentos ativas, controles ActiveX](#_core_the_web_page.3a_.html.2c_.activex_documents.2c_.activex_controls)  
  
-   [Navegador ou aplicativo autônomo](#_core_browser_or_stand.2d.alone_application)  
  
-   [Na Internet](#_core_com_on_the_internet)  
  
-   [Serviços de download dos dados do cliente](#_core_client_data_download_services)  
  
 Se você estiver pronto para começar a escrever seu programa agora, consulte [MFC a gravação de aplicativos](../mfc/writing-mfc-applications.md).  
  
##  <a name="_core_intranet_versus_internet"></a> Intranet na Internet  
 Muitos aplicativos executados em Internet e são acessíveis a qualquer um com um navegador e acesso à internet.  Os negócios também são implementando os intranet, que são redes comerciais que usam protocolos TCP\/IP e navegadores da Web.  Os intranet oferecem uma origem facilmente atualizável, centro de informações de negócios.  Podem ser usados pela atualização do software, entrega e tabulando pesquisas, para o atendimento ao cliente, e para entrega de informações.  A tabela a seguir compara recursos da Internet e de intranet.  
  
|Internet|Intranet|  
|--------------|--------------|  
|Largura da banda baixa|Largura de banda alta|  
|Segurança reduzida dos dados e dos sistemas|Acesso a dados e sistemas controlados|  
|Controle mínimo de conteúdo|Controle alto de conteúdo|  
  
##  <a name="_core_client_or_server_application"></a> Cliente ou aplicativo de servidor  
 Seu aplicativo pode executar em um computador cliente ou em um computador de servidor.  O aplicativo também pode ser armazenado em um servidor, e então ser baixado por meio da Internet e de execução em um computador cliente.  As classes de MFC WinInet são usadas para que os aplicativos cliente baixem arquivos.  MFC O e as classes assíncronas do moniker são usados para baixar arquivos e propriedades do controle.  As classes para controles ActiveX e documentos ativas são usadas para aplicativos cliente e para aplicativos que são baixados do servidor para execução em um cliente.  
  
##  <a name="_core_the_web_page.3a_.html.2c_.activex_documents.2c_.activex_controls"></a> A página da Web: HTML, documentos ativas, controles ActiveX  
 Microsoft oferece várias maneiras de fornecer conteúdo em uma página da Web.  As páginas da Web podem usar extensões padrão de HTML ou HTML, como a marca do objeto, para fornecer conteúdo dinâmico como controles ActiveX.  
  
 Navegadores da Web páginas HTML de exibição normalmente.  Os documentos ativas também podem exibir seus dados de aplicativo na interface de aponte para e clique em simples de um navegador COM\- habilitado.  O servidor ativo de documento pode exibir o documento, quadro completo na área do cliente, com seus próprios menus e barras de ferramentas.  
  
 Os controles ActiveX que você grava podem ser baixados de forma assíncrona do servidor e ser exibidos em uma página da Web.  Você pode usar uma linguagem de scripts como o VBScript para executar a validação do lado do cliente antes de enviar informações ao servidor.  
  
##  <a name="_core_browser_or_stand.2d.alone_application"></a> Navegador ou aplicativo autônomo  
 Você pode escrever os controles ActiveX que são inseridos em uma página HTML e em um servidor ativo de documento que são exibidos em um navegador.  Você pode gravar as páginas HTML que contêm um botão para enviar uma solicitação para executar o aplicativo de ISAPI em um servidor Web.  Você pode escrever um aplicativo autônomo que use protocolos de Internet para baixar arquivos e exibir informações ao usuário, sem nunca deve usar um aplicativo de navegador.  
  
##  <a name="_core_com_on_the_internet"></a> Na Internet  
 Os controles ActiveX, os documentos ativas, e apelidos assíncronas usam tecnologias COM \(Component Object Model\).  
  
 Os controles ActiveX fornecem conteúdo dinâmico a documentos e as páginas nas páginas da web.  Com a você pode criar controles ActiveX e documentos de texto completo usando documentos quadro ativo.  
  
 Apelidos assíncronas fornece recursos para habilitar um controle para executar bem em um ambiente da Internet, incluindo um conjunto ou incrementais de progressista baixar dados.  Os controles também devem funcionar bem com outros controles que também podem recuperar os dados de forma assíncrona ao mesmo tempo.  
  
##  <a name="_core_client_data_download_services"></a> Serviços de download dos dados do cliente  
 Dois conjuntos de APIs que ajudarão a transferência de dados para seu cliente são WinInet e apelidos assíncronas.  Se houver grandes arquivos .gif e de .avi e controles ActiveX em seu página HTML, você pode aumentar a resposta ao usuário baixando de forma assíncrona, usando origem ou assíncronas usando WinInet de forma assíncrona.  
  
 Uma tarefa comuns na Internet está transferindo dados.  Se você já estiver usando a tecnologia ativa \(por exemplo, se você tiver um controle ActiveX data objects\), você pode usar apelidos assíncronas para renderizar progressivamente dados como ele baixa.  Você pode usar WinInet para transferir dados usando protocolos comuns de Internet como HTTP, FTP, e o Gopher.  Ambos os métodos a fornecer independência do protocolo, e fornecem uma camada abstrata ao usar Winsock e TCP\/IP.  Você ainda pode usar [Winsock](../mfc/windows-sockets-in-mfc.md) diretamente.  
  
 A tabela a seguir resume várias maneiras de usar o MFC para transferir dados por meio da Internet.  
  
|Use esse protocolo|Sob estas condições|Usando essas classes|  
|------------------------|-------------------------|--------------------------|  
|[Internet que baixa usando apelidos assíncronas](../mfc/asynchronous-monikers-on-the-internet.md)|Para transferência assíncrona usando COM, controles ActiveX, e qualquer Internet\).|[CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md), [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)|  
|[WinInet](../mfc/win32-internet-extensions-wininet.md)|Para protocolos de Internet para HTTP, o FTP, e o Gopher.  Os dados podem ser transferidos de forma síncrona ou assíncrona e são armazenados em um cache em todo o sistema.|[CInternetSession](../Topic/CInternetSession%20Class.md), [CFtpFileFind](../Topic/CFtpFileFind%20Class.md), [CGopherFileFind](../mfc/reference/cgopherfilefind-class.md), e muito mais.|  
|[Winsock](../mfc/windows-sockets-in-mfc.md)|Para maior eficiência máximo e o controle.  Compreensão Requires de soquetes e os protocolos TCP\/IP.|[CSocket](../mfc/reference/csocket-class.md), [CAsyncSocket](../Topic/CAsyncSocket%20Class.md)|  
  
## Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)   
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Monikers assíncronos na Internet](../mfc/asynchronous-monikers-on-the-internet.md)