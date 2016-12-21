---
title: "No&#231;&#245;es b&#225;sicas de HTTP | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Solicitações HTTP, códigos de retorno"
  - "HTTP, códigos de retorno"
  - "códigos de retorno"
ms.assetid: 5b7421bf-42c8-4f3a-8566-8ff5957f58cc
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de HTTP
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao escrever um aplicativo da internet, você geralmente examina e adiciona a informações no cabeçalho HTTP.  Os códigos de retorno indica o êxito ou a falha do evento solicitado.  Vários códigos de retorno comuns são listados na tabela a seguir.  
  
|Código de retorno|Significado|  
|-----------------------|-----------------|  
|200|A URL encontrado, transmissão seguinte|  
|400|Solicitação incompreensível|  
|404|URL solicitado não encontrado|  
|405|O servidor não oferece suporte ao método solicitado|  
|500|Erro desconhecido do servidor|  
|503|Serviço não disponível|  
  
 As respostas HTTP são agrupadas como mostra a tabela a seguir.  
  
|Grupo|Significado|  
|-----------|-----------------|  
|200–299|Êxito|  
|300–399|Informações|  
|400–499|Erro de solicitação|  
|500–599|Erro de servidor|  
  
 O protocolo HTTP \(hypertext transfer protocol\) é um protocolo no nível de aplicativo para sistemas de informações de hipermídia.  Para obter mais informações sobre HTTP, e como navegadores da Web e os servidores se comunicam, consulte a especificação do protocolo HTTP:  
  
 [http:\/\/www.w3.org\/pub\/WWW\/Protocols\/](http://www.w3.org/pub/WWW/Protocols/)  
  
## Consulte também  
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)