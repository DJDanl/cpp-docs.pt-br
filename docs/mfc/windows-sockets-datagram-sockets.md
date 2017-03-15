---
title: "Windows Sockets: soquetes de datagrama | Microsoft Docs"
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
  - "soquetes de datagrama [C++]"
  - "soquetes [C++], fluxo de dados bidirecional"
  - "soquetes [C++], datagrama"
  - "Windows Sockets [C++], fluxo de dados bidirecional"
  - "Windows Sockets [C++], datagrama"
ms.assetid: bec16a1c-74c0-4ff9-8c18-c2d87897d264
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Sockets: soquetes de datagrama
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve os soquetes de datagrama, um dos dois tipos de soquete windows disponíveis. \(Outro tipo é [soquete de fluxo](../mfc/windows-sockets-stream-sockets.md).\)  
  
 Soquetes de datagrama oferecem suporte a um fluxo de dados bidirecional que não é garantido para ser colocado em sequência ou unduplicated.  As datagramas não há garantia de que também sejam confiáveis; podem não chegam.  Os dados de datagrama possam chegar fora de serviço e possivelmente duplicados, mas os limites do registro nos dados são preservados, à medida que os registros são menores que o limite interno do tamanho do destinatário.  Você é responsável para ordenar em sequência e confiabilidade gerenciar. \(A confiabilidade tenderá a ser boa em redes locais \[\] rede local mas em menos isso em redes de longa distância \[\] WAN, como a Internet\).  
  
 As datagramas são “sem conexão”, isto é, nenhuma conexão é estabelecida explícita; você envia uma mensagem de datagrama a um soquete especificado e você pode receber mensagens de um soquete especificado.  
  
 Um exemplo de um soquete de datagrama é um aplicativo que mantém relógios do sistema na rede sincronizados.  Isso ilustra um recurso adicional de soquetes de datagrama pelo menos em algumas configurações: mensagens de transmissão em um grande número de endereços de rede.  
  
 Soquetes de datagrama são melhor do que soquetes de fluxo de dados interfaces orientados.  Para obter mais informações sobre os soquetes de datagrama, consulte a especificação de soquetes do windows, disponível em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Windows Sockets em MFC](../mfc/windows-sockets-in-mfc.md)   
 [Windows Sockets: plano de fundo](../mfc/windows-sockets-background.md)