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
ms.openlocfilehash: a6146106a7ae378821fc7133d2d65597d1225cc1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079656"
---
# <a name="windows-sockets-background"></a>Windows Sockets: tela de fundo

Este artigo explica a natureza e a finalidade de soquetes do Windows. O artigo também:

- [Define o termo "soquete"](#_core_definition_of_a_socket).

- [Descreve o tipo de dados de identificador de soquete](#_core_the_socket_data_type).

- [Descreve os usos para soquetes](#_core_uses_for_sockets).

A especificação de soquetes do Windows define uma interface de programação de rede compatíveis com o binário para o Microsoft Windows. Windows Sockets baseiam-se na implementação de soquetes do UNIX em a Berkeley Software Distribution (BSD, versão 4.3) da Universidade da Califórnia em Berkeley. A especificação inclui rotinas de soquete de estilo BSD e extensões específicas do Windows. Usando soquetes do Windows permite que seu aplicativo para se comunicar em qualquer rede que esteja de acordo com a API do Windows Sockets. No Win32, Windows Sockets fornecem para acesso thread-safe.

Muitos fornecedores de software de rede dão suporte a Windows Sockets em protocolos de rede, incluindo Protocol/Internet Protocol (TCP), sistema de rede Xerox (XNS), do protocolo DECNet Digital Equipment Corporation, Internet da empresa do Novell Packet Exchange/Sequenced empacotadas Exchange (IPX/SPX) e outros. Embora a especificação de soquetes do Windows presente define a abstração de soquetes de TCP/IP, qualquer protocolo de rede pode estar em conformidade com soquetes do Windows, fornecendo sua própria versão da biblioteca de vínculo dinâmico (DLL) que implementa o Windows Sockets. Servidores Windows X, emuladores de terminal e sistemas de correio eletrônico são exemplos de aplicativos comerciais escritos com o Windows Sockets.

> [!NOTE]
>  A finalidade de soquetes do Windows é abstrair a rede subjacente para que você não precise ter conhecimentos sobre rede e, portanto, seu aplicativo pode ser executado em qualquer rede que dá suporte a soquetes. Consequentemente, esta documentação não aborda os detalhes dos protocolos de rede.

O Microsoft Foundation Class Library (MFC) dá suporte à programação com a API de soquetes do Windows, fornecendo duas classes. Uma dessas classes, `CSocket`, fornece um alto nível de abstração para simplificar sua programação de comunicações de rede.

A especificação de soquetes do Windows, Windows Sockets: um abrir a Interface de rede de computação em Microsoft Windows, agora na versão 1.1, foi desenvolvido como um padrão de rede aberto por um grande grupo de indivíduos e corporações na comunidade de TCP/IP e é disponível gratuitamente para uso. Os soquetes de programação modelo dá suporte a um "comunicação domínio" no momento, usando o pacote de protocolos de Internet. A especificação está disponível no SDK do Windows.

> [!TIP]
>  Como os soquetes usam o conjunto de protocolos de Internet, eles são a rota preferida para aplicativos que dão suporte à comunicação com a Internet na "rodovia informações".

##  <a name="_core_definition_of_a_socket"></a> Definição de um soquete

Um soquete é um ponto de extremidade de comunicação — um objeto por meio do qual um aplicativo do Windows Sockets envia ou recebe pacotes de dados em uma rede. Um soquete tem um tipo e está associado um processo em execução, e ele pode ter um nome. Atualmente, soquetes geralmente trocam dados apenas com outros soquetes no mesmo "comunicação domínio," que usa o conjunto de protocolos de Internet.

Os dois tipos de soquetes são bidirecionais; eles são fluxos de dados que podem ser comunicados em ambas as direções simultaneamente (full duplex).

Dois tipos de soquete estão disponíveis:

- Soquetes de Stream

   Soquetes de Stream fornecem um fluxo de dados sem limites de registros: um fluxo de bytes. Fluxos têm garantia de entrega e ser corretamente sequenciado e não duplicadas.

- Soquetes de datagrama

   Datagrama soquetes suporte um registro orientado por fluxo de dados que não é garantido para ser entregue e não pode ser sequenciado como enviado ou não duplicadas.

"Sequenciado" significa que os pacotes sejam entregues na ordem enviadas. "Não duplicadas" significa que você obtenha um pacote específico apenas uma vez.

> [!NOTE]
>  Em alguns protocolos de rede, como XNS, fluxos de podem ser orientado, como fluxos de registros em vez de fluxos de bytes de registro. No entanto, com o protocolo TCP/IP mais comuns, fluxos são fluxos de bytes. Soquetes do Windows fornece um nível de abstração independente do protocolo subjacente.

Para obter informações sobre esses tipos e qual tipo de soquete para usar em quais situações, consulte [Windows Sockets: soquetes de Stream](../mfc/windows-sockets-stream-sockets.md) e [Windows Sockets: soquetes de datagrama](../mfc/windows-sockets-datagram-sockets.md).

##  <a name="_core_the_socket_data_type"></a> O tipo de dados do soquete

Cada objeto de soquete do MFC encapsula um identificador para um objeto do Windows Sockets. O tipo de dados desse identificador é **soquete**. Um **soquete** identificador é semelhante ao `HWND` para uma janela. Classes de soquete do MFC fornecem operações no identificador encapsulado.

O **soquete** tipo de dados é descrito em detalhes no SDK do Windows. Consulte o "Tipo de dados do soquete e valores de erro" em soquetes do Windows.

##  <a name="_core_uses_for_sockets"></a> Usos para soquetes

Soquetes são altamente úteis em contextos de comunicações de pelo menos três:

- Modelos de cliente/servidor.

- Cenários de ponto a ponto, como aplicativos de mensagens.

- Fazendo chamadas de procedimento remoto (RPC), fazendo com que o aplicativo de recebimento interpretar uma mensagem como uma chamada de função.

> [!TIP]
>  O caso ideal para usar soquetes MFC é quando você estiver escrevendo ambas as extremidades da comunicação: usando MFC em ambas as extremidades. Para obter mais informações sobre esse tópico, incluindo como gerenciar o caso quando você estiver se comunicando com aplicativos não MFC, consulte [Windows Sockets: ordenação de bytes](../mfc/windows-sockets-byte-ordering.md).

Para obter mais informações, consulte a especificação do Windows Sockets: **ntohs**, **ntohl**, **htons**, **htonl**. Além disso, consulte os tópicos a seguir:

- [Windows Sockets: usando soquetes com arquivos mortos](../mfc/windows-sockets-using-sockets-with-archives.md)

- [Windows Sockets: exemplo de soquetes que usam arquivos mortos](../mfc/windows-sockets-example-of-sockets-using-archives.md)

- [Windows Sockets: usando a classe CAsyncSocket](../mfc/windows-sockets-using-class-casyncsocket.md)

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)

