---
title: "Estrutura de LINGER | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "LINGER"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura LINGER"
ms.assetid: 1fb1c5bf-a64e-4a6c-89d6-1734e4fdbb1b
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura de LINGER
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `LINGER` é usada manipulando as opções de **SO\_LINGER** e de **SO\_DONTLINGER** de `CAsyncSocket::GetSockOpt`.  
  
## Sintaxe  
  
```  
  
      struct linger {  
   u_short l_onoff;            // option on/off  
   u_short l_linger;           // linger time  
};  
```  
  
## Comentários  
 Definir a opção de **SO\_DONTLINGER** impede o bloqueio na função de membro **Fechar** ao aguardar os dados não enviado a ser enviado.  Definir essa opção é equivalente à configuração **SO\_LINGER** com **l\_onoff** definido como 0.  
  
## Requisitos  
 **Cabeçalho:** winsock2.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CAsyncSocket::GetSockOpt](../Topic/CAsyncSocket::GetSockOpt.md)   
 [CAsyncSocket::SetSockOpt](../Topic/CAsyncSocket::SetSockOpt.md)