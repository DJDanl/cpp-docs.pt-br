---
title: 'Windows Sockets: Soquetes de datagrama | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- sockets [MFC], datagram
- Windows Sockets [MFC], bi-directional data flow
- datagram sockets [MFC]
- Windows Sockets [MFC], datagram
- sockets [MFC], bi-directional data flow
ms.assetid: bec16a1c-74c0-4ff9-8c18-c2d87897d264
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f8c19280645edad0d449708434ebbc0ee646e981
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

