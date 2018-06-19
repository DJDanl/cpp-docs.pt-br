---
title: 'Windows Sockets: Soquetes de datagrama | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- sockets [MFC], datagram
- Windows Sockets [MFC], bi-directional data flow
- datagram sockets [MFC]
- Windows Sockets [MFC], datagram
- sockets [MFC], bi-directional data flow
ms.assetid: bec16a1c-74c0-4ff9-8c18-c2d87897d264
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 30ad7cab43301ae2cb7ebcb1fb4dfa850090955d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33383936"
---
# <a name="windows-sockets-datagram-sockets"></a>Windows Sockets: soquetes de datagrama
Este artigo descreve os soquetes de datagrama, um dos dois tipos de Windows Socket disponível. (O outro tipo é o [soquete fluxo](../mfc/windows-sockets-stream-sockets.md).)  
  
 Soquetes de datagrama oferecem suporte a um fluxo de dados bidirecional que não é garantido em sequência ou unduplicated. Datagramas também não há garantia de ser confiável; eles podem não for atingido. Dados de datagrama podem chegar fora de ordem e possivelmente duplicados, mas o registros limites nos dados são preservados, desde que os registros são menores do que o limite de tamanho interno do destinatário. Você é responsável por gerenciar sequenciamento e confiabilidade. (Confiabilidade tende a ser bom em redes de área local [LAN], mas menos remota etc redes WAN, como a Internet.)  
  
 Datagramas são "sem conexão", ou seja, nenhuma conexão explícita é estabelecida. enviar uma mensagem de datagrama a um soquete especificado e você pode receber mensagens de um soquete especificado.  
  
 Um exemplo de um soquete de datagrama é um aplicativo que mantém os relógios do sistema na rede sincronizada. Isso ilustra um recurso adicional de soquetes de datagrama pelo menos algumas configurações: difusão de mensagens para um grande número de endereços de rede.  
  
 Soquetes de datagrama são melhores que soquetes de fluxo de dados orientados ao registro. Para obter mais informações sobre soquetes de datagrama, consulte a especificação de Windows Sockets, disponível no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)

