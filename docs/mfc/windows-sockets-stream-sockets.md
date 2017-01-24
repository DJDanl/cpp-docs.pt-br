---
title: "Windows Sockets: soquetes de fluxo | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Soquetes de fluxo do Windows Sockets [C++]"
  - "soquetes [C++], soquetes de fluxo"
  - "soquetes de fluxo [C++]"
ms.assetid: 31faaa34-a995-493f-a30b-b8115293d619
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: soquetes de fluxo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve os soquetes de fluxo, um dos dois tipos de soquete do Windows disponíveis. \(O outro tipo é o [soquete de datagrama](../mfc/windows-sockets-datagram-sockets.md).\)  
  
 Soquetes de fluxo fornecem um fluxo de dados sem limites de registros: um fluxo de bytes que pode ser bidirecional \(o aplicativo é full\-duplex: ele pode transmitir e receber por meio do soquete\). Fluxos podem ser considerados para entregar dados unduplicated seqüenciados. \("Sequenciado" significa que os pacotes sejam entregues na ordem enviadas. "Unduplicated" significa que você obtenha um pacote específico apenas uma vez.\) Recebimento de mensagens de fluxo é garantido e fluxos são adequados para lidar com grandes quantidades de dados.  
  
 A camada de transporte de rede pode dividir ou agrupar dados em pacotes de tamanho razoável. O `CSocket` classe tratará o empacotamento e desempacotar para você.  
  
 Fluxos se baseiam em conexões explícitas: soquete A solicita uma conexão de soquete B; soquete B aceita ou rejeita a solicitação de conexão.  
  
 Uma chamada telefônica fornece uma boa analogia para um fluxo. Em circunstâncias normais, a parte destinatária ouve o que diz na ordem em que você diz, sem duplicação ou perda. Soquetes de fluxo são apropriados, por exemplo, para implementações, como o protocolo FTP \(File Transfer\), que facilita a transferência ASCII ou arquivos binários de tamanho arbitrário.  
  
 Soquetes de fluxo são preferíveis para soquetes de datagrama quando devem garantir que os dados chegam e quando o tamanho dos dados é grande. Para obter mais informações sobre soquetes de fluxo, consulte a especificação do Windows Sockets. A especificação está disponível no [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
 Usar soquetes de fluxo pode ser superior a aplicativos criados para usar um soquete de datagrama de difusão para todos os soquetes de recebimentos na rede porque  
  
-   O modelo de difusão está sujeito a problemas de rede inundação \(ou "storm"\).  
  
-   O modelo cliente\-servidor adotado subsequentemente é mais eficiente.  
  
-   O modelo de fluxo fornece transferência de dados confiável, onde o modelo de datagrama não.  
  
-   Modelo final se beneficia da capacidade de se comunicar entre Unicode e ANSI, aplicativos de soquete classe que carchive leva a classe CSocket.  
  
    > [!NOTE]
    >  Se você usar a classe `CSocket`, você deve usar um fluxo. Uma asserção MFC falhará se você especificar o tipo de soquete como **SOCK\_DGRAM**.  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)