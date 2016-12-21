---
title: "Como usar a refer&#234;ncia cruzada do mapa de mensagem | Microsoft Docs"
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
  - "vc.mfc.messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "janelas [C++], mapas de mensagem"
ms.assetid: 2e863d23-9e58-45ba-b5e4-a8ceefccd0c8
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar a refer&#234;ncia cruzada do mapa de mensagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Nas entradas rotuladas \<memberFxn\>, escrever sua própria função de membro para uma classe derivada de [CWnd](../Topic/CWnd%20Class.md) .  Da função qualquer nome que você gostar.  Outras funções, como `OnActivate`, são funções de membro da classe `CWnd`.  Se chamadas, passam a mensagem à função do windows de `DefWindowProc` .  Para processar notificações do windows, substitua a função correspondente de `CWnd` em sua classe derivada.  A função deve chamar a função preterida em sua classe base para deixar a classe base e janelas responder à mensagem.  
  
 Em todos os casos, coloque o protótipo em `CWnd`\- cabeçalho da função da classe derivada, e codifica a entrada da mensagem como mostrado.  
  
 Os termos a seguir são usados:  
  
|Termo|Definição|  
|-----------|---------------|  
|id|Qualquer ID do item de menu definido pelo usuário \(mensagens de**WM\_COMMAND** \) ou a ID de controle \(notificações da janela filho\).|  
|“mensagem” e “wNotifyCode”|IDs de mensagem do windows como definido em. WINDOWS.H.|  
|nMessageVariable|Nome de uma variável que contém o valor de retorno da função do windows de **RegisterWindowMessage** .|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)