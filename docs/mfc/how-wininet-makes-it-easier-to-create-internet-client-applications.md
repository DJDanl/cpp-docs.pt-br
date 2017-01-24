---
title: "Como WinInet facilita a cria&#231;&#227;o de aplicativos clientes da Internet | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "Windows Sockets [C++], vs. WinInet"
  - "Classes WinInet, aplicativos cliente da Internet"
  - "Classes WinInet, vs. WinSock"
ms.assetid: dc0f9f47-3184-4e7a-8074-2c63e0359885
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como WinInet facilita a cria&#231;&#227;o de aplicativos clientes da Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As extensões do Win32 a Internet, ou WinInet, fornecem acesso aos protocolos comuns da Internet, incluindo o Gopher, o FTP, e o HTTP.  Usando WinInet, você pode escrever aplicativos cliente da Internet em um nível mais alto de programação, sem precisar controlar o Winsock, TCP\/IP, ou os detalhes de protocolos específicos da Internet.  WinInet fornece um conjunto consistente de funções para todos os três protocolos, com uma interface familiar da API do Win32.  Essa consistência minimiza alterações de código que você precisa fazer se o protocolo subjacente alterações \(por exemplo, FTP a HTTP.  
  
 Visual C\+\+ fornece dois modos para que você use WinInet.  Você pode chamar funções do Win32 Internet diretamente \(consulte a documentação de OLE em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)] para obter mais informações\) ou você pode usar WinInet com [Classes de WinInet MFC](../mfc/mfc-classes-for-creating-internet-client-applications.md).  
  
 **Você pode usar WinInet:**  
  
-   Páginas HTML de download.  
  
     HTTP é um protocolo usado para transferir páginas HTML de um servidor para um navegador cliente.  
  
-   Solicitações de FTP de envio carregar ou baixar arquivos ou obter listagens do diretório.  
  
     Uma solicitação típica é um logon anônimo para baixar um arquivo.  
  
-   Use o sistema do menu de Gopher acessando recursos na Internet.  
  
     Os itens de menu podem ser vários tipos, inclusive outros menus, um base de dados que indexado você pode pesquisar, um grupos de notícias, ou um arquivo.  
  
 Para todos os três protocolos, você estabelece uma conexão, faz solicitações ao servidor, e fecha a conexão.  
  
 **As classes de MFC WinInet fazem\-na fácil:**  
  
-   Lê informações de HTTP, FTP, e servidores de Gopher tão facilmente quanto a leitura arquivos de um disco rígido.  
  
-   Use HTTP, FTP, e protocolos de Gopher sem programação diretamente ao Winsock ou ao TCP\/IP.  
  
     Os desenvolvedores que usam as funções do Win32 a Internet não precisam estar familiarizado com os soquetes TCP\/IP ou do windows.  Você ainda pode programar no nível de soquete, usando o Winsock e protocolos TCP\/IP diretamente, mas mesmo é mais fácil usar as classes de MFC WinInet para acessar HTTP, FTP, e protocolos de Gopher por meio da Internet.  Para muitas operações comuns, os desenvolvedores não precisam saber os detalhes do protocolo específico que estão usando.  
  
 Muitas operações que podem ser executadas pelo seu computador como um cliente com outros computadores na Internet podem demorar muito tempo.  A velocidade dessas operações é normalmente limitada pela velocidade da conexão de rede, mas também podem ser afetados por outro tráfego de rede e pela complexidade da operação.  Conectar a um servidor FTP remoto, por exemplo, requer que seu computador pesquisa primeiro o nome do servidor para localizar o endereço.  Seu aplicativo tentará se conectar ao servidor no endereço.  Uma vez que a conexão é aberta, seu computador e o servidor remoto iniciarão uma conversa com o FTP \(File Transfer Protocol\) para que você possa eventualmente usar a conexão para recuperar arquivos.  
  
## Consulte também  
 [Extensões da Internet Win32 \(WinInet\)](../mfc/win32-internet-extensions-wininet.md)   
 [Como o MFC facilita a criação de aplicativos clientes da Internet](../mfc/how-mfc-makes-it-easier-to-create-internet-client-applications.md)