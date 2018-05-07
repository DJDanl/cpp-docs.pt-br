---
title: 'Windows Sockets: Plano de fundo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fda86bbbeb49bcb253348ed02abef4fb8d4cff9c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="windows-sockets-background"></a>Windows Sockets: tela de fundo
Este artigo explica a natureza e a finalidade de soquetes do Windows. O artigo também:  
  
-   [Define o termo "soquete"](#_core_definition_of_a_socket).  
  
-   [Descreve o tipo de dados de identificador de soquete](#_core_the_socket_data_type).  
  
-   [Descreve usos para soquetes](#_core_uses_for_sockets).  
  
 A especificação de Windows Sockets define uma interface de programação de rede compatível com o binário para o Microsoft Windows. Windows Sockets baseiam-se na implementação de soquetes do UNIX na Berkeley Software Distribution (BSD, versão 4.3) da University of California em Berkeley. A especificação inclui rotinas de soquete de estilo BSD e extensões específicas do Windows. Usar o Windows Sockets permite que seu aplicativo para se comunicar através de qualquer rede que esteja de acordo com a API do Windows Sockets. Em Win32, Windows Sockets fornecer para acesso thread-safe.  
  
 Muitos fornecedores de software de rede oferecem suporte a Windows Sockets em protocolos de rede, incluindo Protocol/Internet Protocol (TCP), sistema de rede Xerox (XNS), o protocolo DECNet Digital Equipment Corporation, Novell Corporation Internet Packet Exchange/Sequenced empacotadas Exchange (IPX/SPX) e outros. Embora a especificação de Windows Sockets presente define a abstração de soquetes TCP/IP, qualquer protocolo de rede pode estar em conformidade com o Windows Sockets fornecendo sua própria versão da biblioteca de vínculo dinâmico (DLL) que implementa o Windows Sockets. Servidores Windows X, emuladores de terminal e sistemas de email são exemplos de aplicativos comerciais escritos com o Windows Sockets.  
  
> [!NOTE]
>  A finalidade do Windows Sockets é abstrair rede subjacente para que você não precisa conhecer a rede e, portanto, seu aplicativo pode ser executado em qualquer rede que suporta soquetes. Consequentemente, esta documentação não aborda os detalhes de protocolos de rede.  
  
 O Microsoft Foundation Class Library (MFC) dá suporte a programação com a API do Windows Sockets fornecendo duas classes. Uma dessas classes, `CSocket`, fornece um alto nível de abstração para simplificar a programação de comunicação de rede.  
  
 A especificação de Windows Sockets do Windows Sockets: um abrir a Interface de rede de computação no Microsoft Windows, agora na versão 1.1, foi desenvolvido como um padrão de rede aberto por um grande grupo de indivíduos e empresas na comunidade de TCP/IP e é disponível gratuitamente para uso. Soquetes de programação dá suporte a um "comunicação domínio de modelo" no momento, usando o pacote de protocolos de Internet. A especificação está disponível no SDK do Windows.  
  
> [!TIP]
>  Como soquetes usam o conjunto de protocolos de Internet, eles são a rota preferencial para aplicativos que oferecem suporte a comunicações de Internet "estrada informações".  
  
##  <a name="_core_definition_of_a_socket"></a> Definição de um soquete  
 Um soquete é um ponto de extremidade de comunicação — um objeto por meio do qual um aplicativo de Windows Sockets envia ou recebe os pacotes de dados em uma rede. Um soquete tem um tipo e está associado um processo em execução, e pode ter um nome. Atualmente, soquetes geralmente trocam dados apenas com outros soquetes no mesmo "comunicação domínio," que usa o conjunto de protocolos de Internet.  
  
 Os dois tipos de soquetes são bidirecional; eles são fluxos de dados que podem ser comunicados simultaneamente em ambas as direções (full duplex).  
  
 Existem dois tipos de soquete:  
  
-   Soquetes de fluxo  
  
     Soquetes de fluxo fornecem um fluxo de dados sem limites de registro: um fluxo de bytes. Fluxos são garantidos para ser entregue e ser sequenciado e unduplicated corretamente.  
  
-   Soquetes de datagrama  
  
     Datagrama soquetes suporte um registro orientado por fluxo de dados que não é garantido para ser entregue e não pode ser sequenciado como enviado ou unduplicated.  
  
 "Sequenciado" significa que os pacotes são entregues em ordem enviadas. "Unduplicated" significa que você obtenha um pacote específico apenas uma vez.  
  
> [!NOTE]
>  Em alguns protocolos de rede, como XNS, fluxos podem ser registro orientadas a objeto, como fluxos de registros em vez de fluxos de bytes. Sob o protocolo mais comum de TCP/IP, no entanto, fluxos são fluxos de byte. Windows Sockets fornece um nível de abstração independente do protocolo subjacente.  
  
 Para obter informações sobre esses tipos e que tipo de soquete para usar em que situações, consulte [Windows Sockets: soquetes de fluxo](../mfc/windows-sockets-stream-sockets.md) e [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md).  
  
##  <a name="_core_the_socket_data_type"></a> O tipo de dados do soquete  
 Cada objeto de soquete MFC encapsula um identificador para um objeto do Windows Sockets. O tipo de dados desse identificador é **soquete**. Um **soquete** identificador é análogo ao `HWND` para uma janela. Classes de soquete MFC fornecem operações no identificador do encapsulado.  
  
 O **soquete** tipo de dados é descrito detalhadamente no SDK do Windows. Consulte "Tipo de dados do soquete e valores de erro" em soquetes do Windows.  
  
##  <a name="_core_uses_for_sockets"></a> Usos de soquetes  
 Soquetes são altamente úteis em contextos de comunicações de pelo menos três:  
  
-   Modelos de cliente/servidor.  
  
-   Cenários de ponto a ponto, como aplicativos de mensagens.  
  
-   Fazendo chamadas de procedimento remoto (RPC), fazendo com que o aplicativo de recebimento interpretar uma mensagem como uma chamada de função.  
  
> [!TIP]
>  O caso ideal para usar soquetes MFC é quando você está escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Para obter mais informações sobre este tópico, incluindo como gerenciar o caso quando você estiver se comunicando com aplicativos não MFC, consulte [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).  
  
 Para obter mais informações, consulte a especificação do Windows Sockets: **ntohs**, **ntohl**, **htons**, **htonl**. Além disso, consulte os tópicos a seguir:  
  
-   [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)  
  
-   [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)  
  
-   [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

