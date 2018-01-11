---
title: 'Windows Sockets: Soquetes de fluxo | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Sockets [MFC], stream sockets
- sockets [MFC], stream sockets
- stream sockets [MFC]
ms.assetid: 31faaa34-a995-493f-a30b-b8115293d619
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bc112bd3cfbf1194a2898afecb513edcbc456747
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-sockets-stream-sockets"></a>Windows Sockets: soquetes de fluxo
Este artigo descreve os soquetes de fluxo, um dos dois tipos de Windows Socket disponível. (O outro tipo é o [soquete de datagrama](../mfc/windows-sockets-datagram-sockets.md).)  
  
 Soquetes de fluxo fornecem um fluxo de dados sem limites de registro: um fluxo de bytes que podem ser bidirecionais (o aplicativo é full-duplex: ele pode transmitir e receber através do soquete). Fluxos de podem ser usados para entregar dados unduplicated sequenciados. ("Sequenciado" significa que os pacotes são entregues em ordem enviadas. "Unduplicated" significa que você obtenha um pacote específico apenas uma vez.) Recebimento de mensagens de fluxo é garantido e fluxos são adequados para lidar com grandes quantidades de dados.  
  
 A camada de transporte de rede pode quebrar ou agrupar dados em pacotes de tamanho razoável. O `CSocket` classe tratará o empacotamento e a descompactação para você.  
  
 Fluxos são com base nas conexões explícitas: soquete A solicita uma conexão de soquete B; soquete B aceita ou rejeita a solicitação de conexão.  
  
 Uma chamada telefônica fornece uma boa analogia para um fluxo. Em circunstâncias normais, a parte destinatária ouve o que dizer na ordem dizer, sem perda ou de eliminação de duplicação. Soquetes de fluxo são apropriados, por exemplo, para implementações, como o protocolo FTP (File Transfer), que facilita a transferir ASCII ou os arquivos binários de tamanho arbitrário.  
  
 Soquetes de fluxo são preferível soquetes de datagrama quando os dados devem ser garantidos de chegar e tamanho dos dados é grande. Para obter mais informações sobre soquetes de fluxo, consulte a especificação de Windows Sockets. A especificação está disponível no SDK do Windows.  
  
 Usar soquetes de fluxo pode ser vantajoso para aplicativos projetados para usar um soquete de datagrama de difusão de dados para todos os soquetes de recebimento na rede como  
  
-   O modelo de difusão está sujeita a problemas de saturação (ou "storm") da rede.  
  
-   O modelo de cliente-servidor adotado subsequentemente é mais eficiente.  
  
-   O modelo de fluxo fornece transferência de dados confiável, onde o modelo de datagrama não.  
  
-   Modelo final aproveita a capacidade de se comunicar entre ANSI e Unicode aplicativos de soquete classe que carchive presta a classe CSocket.  
  
    > [!NOTE]
    >  Se você usar a classe `CSocket`, você deve usar um fluxo. Uma declaração de MFC falha se você especificar o tipo de soquete como **SOCK_DGRAM**.  
  
## <a name="see-also"></a>Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [Windows Sockets: tela de fundo](../mfc/windows-sockets-background.md)

