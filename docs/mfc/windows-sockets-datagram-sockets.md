---
title: 'Windows Sockets: Soquetes de datagrama'
ms.date: 11/04/2016
helpviewer_keywords:
- sockets [MFC], datagram
- Windows Sockets [MFC], bi-directional data flow
- datagram sockets [MFC]
- Windows Sockets [MFC], datagram
- sockets [MFC], bi-directional data flow
ms.assetid: bec16a1c-74c0-4ff9-8c18-c2d87897d264
ms.openlocfilehash: 14d33ece66d902b5705e573e9863ea78fff9737f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57266783"
---
# <a name="windows-sockets-datagram-sockets"></a>Windows Sockets: Soquetes de datagrama

Este artigo descreve os soquetes de datagrama, um dos dois tipos de soquete do Windows disponíveis. (O outro tipo é o [soquete de fluxo](../mfc/windows-sockets-stream-sockets.md).)

Soquetes de datagrama dão suporte a um fluxo de dados bidirecionais que não tem garantia de ser sequenciado ou não duplicadas. Datagramas também não têm garantia de ser confiáveis; eles podem não chegar. Dados de datagrama podem chegar fora de ordem e possivelmente duplicados, mas os limites de registro nos dados são preservados, desde que os registros são menores do que o limite de tamanho interno do destinatário. Você é responsável por gerenciar o sequenciamento e a confiabilidade. (Confiabilidade tende a ser bom em redes de área local [LAN], mas menos assim por diante de longa distância redes WAN, como a Internet.)

Datagramas são "sem conexão", ou seja, nenhuma conexão explícita é estabelecida; enviar uma mensagem de datagrama para um soquete especificado e você pode receber mensagens de um soquete especificado.

Um exemplo de um soquete de datagrama é um aplicativo que mantém os relógios do sistema na rede sincronizada. Isso ilustra uma funcionalidade adicional de soquetes de datagrama pelo menos algumas configurações: mensagens de difusão para um grande número de endereços de rede.

Soquetes de datagrama são melhores que soquetes de fluxo de dados orientados a registros. Para obter mais informações sobre os soquetes de datagrama, consulte a especificação de soquetes do Windows, disponível no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)<br/>
[Windows Sockets: Background](../mfc/windows-sockets-background.md)
