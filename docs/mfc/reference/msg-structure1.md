---
title: "Estrutura MSG | Microsoft Docs"
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
  - "MSG"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura MSG"
ms.assetid: dc166d27-9423-41f1-9599-5ba76d2f0138
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura MSG
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `MSG` contém informações de mensagem da fila de mensagens de um thread.  
  
## Sintaxe  
  
```  
  
      typedef struct tagMSG {     // msg    
   HWND hwnd;  
   UINT message;  
   WPARAM wParam;  
   LPARAM lParam;  
   DWORD time;  
   POINT pt;  
} MSG;  
```  
  
#### Parâmetros  
 *hwnd*  
 Identifica a janela cujo procedimento de janela recebe a mensagem.  
  
 `message`  
 Especifica o número de mensagem.  
  
 `wParam`  
 Especifica informações adicionais sobre a mensagem.  O significado exato depende do valor do membro de **message** .  
  
 `lParam`  
 Especifica informações adicionais sobre a mensagem.  O significado exato depende do valor do membro de **message** .  
  
 `time`  
 Especifica a hora em que a mensagem foi postada.  
  
 `pt`  
 Especifica a posição do cursor, em coordenadas de tela, quando a mensagem foi postada.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)