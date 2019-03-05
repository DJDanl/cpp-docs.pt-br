---
title: Como WinInet facilita a criação de aplicativos clientes da Internet
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], vs. WinInet
- WinInet classes [MFC], vs. WinSock
- WinInet classes [MFC], Internet client applications
ms.assetid: dc0f9f47-3184-4e7a-8074-2c63e0359885
ms.openlocfilehash: 6da2ef1595e525bcfd407d67c806aa80cf90f1c3
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57286758"
---
# <a name="how-wininet-makes-it-easier-to-create-internet-client-applications"></a>Como WinInet facilita a criação de aplicativos clientes da Internet

As extensões da Internet Win32 ou WinInet, fornecem acesso a protocolos de Internet comuns, incluindo HTTP, FTP e gopher. Usando o WinInet, você pode escrever aplicativos de cliente da Internet em um nível mais alto de programação, sem ter que lidar com o WinSock, TCP/IP ou os detalhes dos protocolos de Internet específicos. O WinInet fornece um conjunto consistente de funções para todos os três protocolos, com uma interface familiar da API do Win32. Essa consistência minimiza as alterações de código que você precisa fazer se o protocolo subjacente é alterado (por exemplo, de FTP para HTTP).

Visual C++ fornece duas maneiras para você usar WinInet. Você pode chamar diretamente as funções de Internet Win32 (consulte a documentação de OLE no SDK do Windows para obter mais informações) ou você pode usar o WinInet por meio de [classes WinInet MFC](../mfc/mfc-classes-for-creating-internet-client-applications.md).

**Você pode usar o WinInet para:**

- Baixe as páginas HTML.

   HTTP é um protocolo usado para transferir páginas HTML de um servidor para um navegador cliente.

- Envie solicitações de FTP para carregar ou baixar arquivos ou obter as listagens de diretório.

   Uma solicitação típica é um logon anônimo para baixar um arquivo.

- Use o sistema de menus do gopher para acessar recursos na Internet.

   Itens de menu podem ser vários tipos, incluindo um arquivo, um banco de dados indexado, que você pode pesquisar, um grupo de notícias ou outros menus.

Para todos os três protocolos, estabelecer uma conexão, fazer solicitações ao servidor e fechar a conexão.

**As classes WinInet MFC facilitam a:**

- Ler informações de servidores HTTP, FTP e gopher tão facilmente quanto a leitura de arquivos de um disco rígido.

- Use protocolos HTTP, FTP e gopher sem programação direta em WinSock ou TCP/IP.

   Os desenvolvedores que usam as funções de Internet Win32 não é necessário estar familiarizado com o TCP/IP ou o Windows Sockets. Você pode ainda programar no nível de soquete, usando os protocolos TCP/IP e o WinSock diretamente, mas é ainda mais fácil de usar as classes WinInet do MFC para acesso HTTP, FTP e gopher protocolos pela Internet. Para várias operações comuns, os desenvolvedores não precisam saber os detalhes do protocolo específico que ele está usando.

Muitas operações que podem ser executadas pelo seu computador como um cliente para outros computadores na Internet podem levar muito tempo. A velocidade dessas operações é geralmente limitada pela velocidade da sua conexão de rede, mas eles também podem ser afetados por outro tráfego de rede e a complexidade da operação. Por exemplo, se conectar a um servidor FTP remoto, requer que o computador primeiro procurar o nome do servidor para localizar seu endereço. Seu aplicativo, em seguida, tentará se conectar ao servidor nesse endereço. Depois que a conexão for aberta, seu computador e o servidor remoto serão iniciar uma conversa com o protocolo de transferência de arquivo antes de poder usar a conexão, na verdade, para recuperar arquivos.

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](../mfc/win32-internet-extensions-wininet.md)<br/>
[Como o MFC facilita a criação de aplicativos cliente da Internet](../mfc/how-mfc-makes-it-easier-to-create-internet-client-applications.md)
