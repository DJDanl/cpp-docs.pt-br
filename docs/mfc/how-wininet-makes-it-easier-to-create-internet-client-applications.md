---
title: Como WinInet facilita a criação de aplicativos clientes da Internet
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], vs. WinInet
- WinInet classes [MFC], vs. WinSock
- WinInet classes [MFC], Internet client applications
ms.assetid: dc0f9f47-3184-4e7a-8074-2c63e0359885
ms.openlocfilehash: 54f63da7451dfef39a33e6b437be938cb1652326
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624567"
---
# <a name="how-wininet-makes-it-easier-to-create-internet-client-applications"></a>Como WinInet facilita a criação de aplicativos clientes da Internet

As extensões de Internet do Win32, ou WinInet, fornecem acesso a protocolos de Internet comuns, incluindo Gopher, FTP e HTTP. Usando o WinInet, você pode escrever aplicativos de cliente de Internet em um nível mais alto de programação, sem precisar lidar com WinSock, TCP/IP ou os detalhes de protocolos de Internet específicos. O WinInet fornece um conjunto consistente de funções para todos os três protocolos, com uma interface de API Win32 familiar. Essa consistência minimiza as alterações de código que você precisa fazer se o protocolo subjacente mudar (por exemplo, de FTP para HTTP).

O Visual C++ fornece duas maneiras de usar o WinInet. Você pode chamar as funções da Internet do Win32 diretamente (consulte a documentação do OLE no SDK do Windows para obter mais informações) ou pode usar o WinInet por meio das [classes do MFC WinInet](mfc-classes-for-creating-internet-client-applications.md).

**Você pode usar o WinInet para:**

- Baixar páginas HTML.

   HTTP é um protocolo usado para transferir páginas HTML de um servidor para um navegador do cliente.

- Envie solicitações de FTP para carregar ou baixar arquivos ou obter listagens de diretório.

   Uma solicitação típica é um logon anônimo para baixar um arquivo.

- Use o sistema de menu do Gopher para acessar recursos na Internet.

   Os itens de menu podem ser vários tipos, incluindo outros menus, um banco de dados indexado que você pode pesquisar, um grupo de notícias ou um arquivo.

Para todos os três protocolos, você estabelece uma conexão, faz solicitações para o servidor e fecha a conexão.

**As classes do MFC WinInet facilitam:**

- Leia informações de servidores HTTP, FTP e Gopher tão facilmente quanto ler arquivos de um disco rígido.

- Use protocolos HTTP, FTP e Gopher sem programar diretamente para WinSock ou TCP/IP.

   Os desenvolvedores que usam as funções de Internet do Win32 não precisam estar familiarizados com o TCP/IP ou com o Windows Sockets. Você ainda pode programar no nível de soquete, usando os protocolos WinSock e TCP/IP diretamente, mas é ainda mais fácil usar as classes WinInet do MFC para acessar protocolos HTTP, FTP e Gopher pela Internet. Para muitas operações comuns, os desenvolvedores não precisam saber os detalhes do protocolo específico que estão usando.

Muitas operações que podem ser executadas pelo computador como um cliente para outros computadores na Internet podem levar muito tempo. A velocidade dessas operações geralmente é limitada pela velocidade de sua conexão de rede, mas elas também podem ser afetadas por outros tráfegos de rede e pela complexidade da operação. Conectar-se a um servidor FTP remoto, por exemplo, requer que o computador primeiro procure o nome desse servidor para localizar seu endereço. Em seguida, seu aplicativo tentará se conectar ao servidor nesse endereço. Quando a conexão for aberta, o computador e o servidor remoto iniciarão uma conversa com o protocolo de transferência de arquivos antes que você realmente possa usar a conexão para recuperar arquivos.

## <a name="see-also"></a>Consulte também

[Extensões da Internet Win32 (WinInet)](win32-internet-extensions-wininet.md)<br/>
[Como o MFC facilita a criação de aplicativos cliente da Internet](how-mfc-makes-it-easier-to-create-internet-client-applications.md)
