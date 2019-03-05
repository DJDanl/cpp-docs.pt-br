---
title: 'Windows Sockets: Soquetes de Stream'
ms.date: 11/04/2016
helpviewer_keywords:
- Windows Sockets [MFC], stream sockets
- sockets [MFC], stream sockets
- stream sockets [MFC]
ms.assetid: 31faaa34-a995-493f-a30b-b8115293d619
ms.openlocfilehash: 91f06c4a36e76638708edf085987e51418913fd6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57271288"
---
# <a name="windows-sockets-stream-sockets"></a>Windows Sockets: Soquetes de Stream

Este artigo descreve os soquetes de fluxo, um dos dois tipos de soquete do Windows disponíveis. (O outro tipo é o [soquete de datagrama](../mfc/windows-sockets-datagram-sockets.md).)

Soquetes de Stream fornecem um fluxo de dados sem limites de registros: um fluxo de bytes que pode ser bidirecional (o aplicativo é full-duplex: ele pode transmitir e receber por meio do soquete). Fluxos podem ser utilizados para entregar dados sequenciados não duplicados. ("Sequenciado" significa que os pacotes sejam entregues na ordem enviadas. "Não duplicadas" significa que você obtenha um pacote específico apenas uma vez.) Tem a garantia de recebimento de mensagens do fluxo e fluxos são bem adequados para lidar com grandes quantidades de dados.

A camada de transporte de rede pode dividir ou agrupar dados em pacotes de tamanho razoável. O `CSocket` classe manipulará o empacotamento e desempacotar para você.

Fluxos são com base nas conexões explícitas: soquete A solicita uma conexão de soquete B; soquete B aceita ou rejeita a solicitação de conexão.

Uma chamada telefônica fornece uma boa analogia para um fluxo. Em circunstâncias normais, a parte destinatária ouve na ordem em que você diz isso, sem duplicação ou perda, você diz. Soquetes de Stream são apropriados, por exemplo, para implementações, como o protocolo FTP (File Transfer), que facilita a transferência ASCII ou arquivos binários de tamanho arbitrário.

Soquetes de Stream são preferíveis para soquetes de datagrama quando os dados devem ser garantidos de chegar e tamanho dos dados é grande. Para obter mais informações sobre os soquetes de fluxo, consulte a especificação de soquetes do Windows. A especificação está disponível no SDK do Windows.

Usar soquetes de fluxo pode ser melhor do que os aplicativos projetados para usar um soquete de datagrama para difusão a todos os soquetes de recebimento na rede, pois

- O modelo de difusão está sujeita a problemas de rede de inundação (ou "storm").

- O modelo cliente-servidor adotado subsequentemente é mais eficiente.

- O modelo de fluxo fornece transferência de dados confiável, em que o modelo de datagrama não tem.

- O modelo final se beneficia da capacidade de se comunicar entre Unicode e ANSI, aplicativos de soquete dessa classe que carchive se presta à classe CSocket.

    > [!NOTE]
    >  Se você usar a classe `CSocket`, você deve usar um fluxo. Uma asserção MFC falhará se você especificar como o tipo de soquete **SOCK_DGRAM**.

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[Windows Sockets: Background](../mfc/windows-sockets-background.md)
