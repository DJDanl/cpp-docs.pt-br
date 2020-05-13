---
title: 'Windows Sockets: plano de fundo'
ms.date: 11/04/2016
helpviewer_keywords:
- record-oriented data [MFC]
- e-mail [MFC]
- Internet Protocol Suite
- mail [MFC]
- communications [MFC], domain
- Windows Sockets [MFC], stream sockets
- mail [MFC], programming for
- sockets [MFC], stream sockets
- datagram sockets [MFC]
- SOCKET handle
- data types [MFC], socket
- e-mail [MFC], programming for
- X Window servers
- sequenced data flow
- stream sockets [MFC]
ms.assetid: f60d4ed2-bf23-4a0e-98d2-fee77e8473dd
ms.openlocfilehash: 1c4a6dc6740660d1097785578cdac355983cad18
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360124"
---
# <a name="windows-sockets-background"></a>Windows Sockets: plano de fundo

Este artigo explica a natureza e o propósito do Windows Sockets. O artigo também:

- [Define o termo "soquete".](#_core_definition_of_a_socket)

- [Descreve o tipo de dados do cabo SOCKET](#_core_the_socket_data_type).

- [Descreve os usos para soquetes](#_core_uses_for_sockets).

A especificação do Windows Sockets define uma interface de programação de rede compatível com binário para o Microsoft Windows. Os soquetes do Windows são baseados na implementação de soquetes UNIX na Berkeley Software Distribution (BSD, versão 4.3) da Universidade da Califórnia em Berkeley. A especificação inclui tanto as rotinas de soquete no estilo BSD quanto extensões específicas do Windows. O uso do Windows Sockets permite que seu aplicativo se comunique em qualquer rede que esteja em conformidade com a API do Windows Sockets. No Win32, os soquetes do Windows fornecem a segurança dos fios.

Muitos fornecedores de software de rede suportam soquetes windows sob protocolos de rede, incluindo Protocolo de Controle de Transmissão/Protocolo de Internet (TCP/IP), Xerox Network System (XNS), protocolo DECNet da Digital Equipment Corporation, Troca de Pacotes de Internet/Troca de Pacotes Seqüenciais (IPX/SPX) da Novell Corporation, entre outros. Embora a presente especificação do Windows Sockets defina a abstração de soquetes para TCP/IP, qualquer protocolo de rede pode cumprir com os Soquetes do Windows fornecendo sua própria versão da biblioteca de links dinâmicos (DLL) que implementa soquetes do Windows. Exemplos de aplicativos comerciais escritos com soquetes do Windows incluem servidores X Windows, emuladores de terminais e sistemas de correio eletrônico.

> [!NOTE]
> O objetivo do Windows Sockets é abstrair a rede subjacente para que você não tenha que ter conhecimento sobre essa rede e para que seu aplicativo possa ser executado em qualquer rede que suporte soquetes. Consequentemente, essa documentação não discute os detalhes dos protocolos de rede.

O Microsoft Foundation Class Library (MFC) suporta programação com a API do Windows Sockets fornecendo duas classes. Uma dessas aulas, `CSocket`fornece um alto nível de abstração para simplificar sua programação de comunicação de rede.

A especificação do Windows Sockets, Windows Sockets: An Open Interface for Network Computing Under Microsoft Windows, agora na versão 1.1, foi desenvolvida como um padrão de rede aberta por um grande grupo de indivíduos e corporações na comunidade TCP/IP e está disponível gratuitamente para uso. O modelo de programação de soquetes suporta um "domínio de comunicação" atualmente, usando o Internet Protocol Suite. A especificação está disponível no Windows SDK.

> [!TIP]
> Como os soquetes usam o Internet Protocol Suite, eles são a rota preferida para aplicativos que suportam comunicações da Internet na "rodovia da informação".

## <a name="definition-of-a-socket"></a><a name="_core_definition_of_a_socket"></a>Definição de um Soquete

Um soquete é um ponto final de comunicação — um objeto através do qual um aplicativo do Windows Sockets envia ou recebe pacotes de dados em uma rede. Um soquete tem um tipo e está associado a um processo de execução, e pode ter um nome. Atualmente, os soquetes geralmente trocam dados apenas com outros soquetes no mesmo "domínio de comunicação", que usa o Internet Protocol Suite.

Ambos os tipos de soquetes são bidirecionais; são fluxos de dados que podem ser comunicados em ambas as direções simultaneamente (full-duplex).

Dois tipos de soquete estão disponíveis:

- soquetes de fluxo

   As tomadas de fluxo fornecem um fluxo de dados sem limites de registro: um fluxo de bytes. Os fluxos são garantidos para serem entregues e para serem corretamente sequenciados e não duplicados.

- soquetes de datagrama

   Os soquetes de datagrama suportam um fluxo de dados orientado a registros que não é garantido para ser entregue e não pode ser seqüenciado conforme enviado ou não duplicado.

"Seqüenciado" significa que os pacotes são entregues na ordem enviada. "Não duplicado" significa que você recebe um pacote específico apenas uma vez.

> [!NOTE]
> Sob alguns protocolos de rede, como XNS, os fluxos podem ser orientados para registros, como fluxos de discos em vez de fluxos de bytes. Sob o protocolo TCP/IP mais comum, no entanto, os fluxos são fluxos de bytes. O Windows Sockets fornece um nível de abstração independente do protocolo subjacente.

Para obter informações sobre esses tipos e que tipo de soquete usar em quais situações, consulte [Soquetes do Windows: Soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md) e [soquetes do Windows: Soquetes de Datagram](../mfc/windows-sockets-datagram-sockets.md).

## <a name="the-socket-data-type"></a><a name="_core_the_socket_data_type"></a>O tipo de dados do SOCKET

Cada objeto de soquete MFC encapsula uma alça para um objeto do Windows Sockets. O tipo de dados desta alça é **SOCKET**. Uma **alça SOCKET** é análoga à `HWND` de uma janela. As classes de soquete MFC fornecem operações na alça encapsulada.

O tipo de dados **SOCKET** é descrito em detalhes no SDK do Windows. Consulte "Digite de dados do soquete e valores de erro" em Soquetes do Windows.

## <a name="uses-for-sockets"></a><a name="_core_uses_for_sockets"></a>Usos para soquetes

Os soquetes são altamente úteis em pelo menos três contextos de comunicação:

- Modelos de cliente/servidor.

- Cenários peer-to-peer, como aplicativos de mensagens.

- Fazer chamadas de procedimento remoto (RPC) fazendo com que o aplicativo receptor interprete uma mensagem como uma chamada de função.

> [!TIP]
> O caso ideal para o uso de soquetes MFC é quando você está escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Para obter mais informações sobre este tópico, incluindo como gerenciar o caso quando você está se comunicando com aplicativos não-MFC, consulte [Soquetes do Windows: Byte Ordering](../mfc/windows-sockets-byte-ordering.md).

Para obter mais informações, consulte a especificação do Soquete do Windows: **ntohs,** **ntohl,** **htons,** **htonl**. Além disso, veja os seguintes tópicos:

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)

- [Windows Sockets: usando classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

## <a name="see-also"></a>Confira também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)
