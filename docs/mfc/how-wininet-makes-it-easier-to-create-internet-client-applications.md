---
title: Como WinInet facilita a criar aplicativos cliente da Internet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Sockets [MFC], vs. WinInet
- WinInet classes [MFC], vs. WinSock
- WinInet classes [MFC], Internet client applications
ms.assetid: dc0f9f47-3184-4e7a-8074-2c63e0359885
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9c79404f296df09afb177930897064b8455217d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-wininet-makes-it-easier-to-create-internet-client-applications"></a>Como WinInet facilita a criação de aplicativos clientes da Internet
As extensões da Internet Win32 ou WinInet, fornecem acesso a protocolos de Internet comuns, incluindo HTTP, FTP e gopher. Usando WinInet, você pode escrever aplicativos de cliente da Internet em um nível mais alto de programação, sem a necessidade de lidar com os detalhes específicos de protocolos de Internet, TCP/IP ou WinSock. WinInet fornece um conjunto consistente de funções para todos os protocolos de três, com uma interface familiar da API do Win32. Essa consistência minimiza as alterações de código que você precisa verificar se o protocolo subjacente for alterado (por exemplo, de FTP para HTTP).  
  
 Visual C++ fornece duas maneiras para você usar WinInet. Você pode chamar diretamente as funções de Internet Win32 (consulte a documentação de OLE no SDK do Windows para obter mais informações) ou você pode usar WinInet por meio de [classes WinInet MFC](../mfc/mfc-classes-for-creating-internet-client-applications.md).  
  
 **Você pode usar WinInet para:**  
  
-   Faça o download de páginas HTML.  
  
     HTTP é um protocolo usado para transferir páginas HTML de um servidor para um navegador cliente.  
  
-   Envie solicitações FTP para carregar ou baixar os arquivos ou obter listagens de diretório.  
  
     Uma solicitação típica é um logon anônimo para baixar um arquivo.  
  
-   Use o sistema de menus do gopher para acessar recursos na Internet.  
  
     Itens de menu podem ser vários tipos, incluindo outros menus, um banco de dados indexado, que você pode pesquisar, um grupo de notícias ou um arquivo.  
  
 Para todos os três protocolos, estabelecer uma conexão, fazem solicitações ao servidor e fechar a conexão.  
  
 **As classes WinInet MFC facilitam a:**  
  
-   Ler informações de servidores HTTP, FTP e gopher facilmente como ler arquivos de um disco rígido.  
  
-   Use os protocolos HTTP, FTP e gopher sem programação diretamente a WinSock ou TCP/IP.  
  
     Os desenvolvedores que usam as funções de Internet Win32 não precisa estar familiarizado com o TCP/IP ou o Windows Sockets. Você pode ainda programar no nível de soquete, usando os protocolos TCP/IP e WinSock diretamente, mas é ainda mais fácil de usar as classes WinInet MFC para acesso HTTP, FTP e gopher protocolos através da Internet. Para várias operações comuns, os desenvolvedores não precisam saber os detalhes do protocolo específico que estão usando.  
  
 Várias operações que podem ser executadas pelo seu computador como um cliente para outros computadores na Internet podem levar muito tempo. A velocidade dessas operações geralmente é limitada pela velocidade da sua conexão de rede, mas eles também podem ser afetados por outro tráfego de rede e a complexidade da operação. Por exemplo, se conectar a um servidor FTP remoto, requer que o computador primeiro consultar o nome do servidor para localizar seu endereço. Seu aplicativo, em seguida, tente se conectar ao servidor nesse endereço. Depois que a conexão for aberta, seu computador e o servidor remoto irá iniciar uma conversa com o protocolo de transferência de arquivo antes, na verdade, você pode usar a conexão para recuperar arquivos.  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)   
 [Como o MFC facilita a criação de aplicativos cliente da Internet](../mfc/how-mfc-makes-it-easier-to-create-internet-client-applications.md)

