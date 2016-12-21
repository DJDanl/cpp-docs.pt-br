---
title: "Exibindo asser&#231;&#245;es | Microsoft Docs"
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
  - "asserções, depuração"
  - "asserções, exibir"
  - "depuração [ATL], exibindo asserções"
  - "asserções de depuração"
ms.assetid: fa353fe8-4656-4384-a5d2-8866bc977f06
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exibindo asser&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o cliente conectado ao serviço aparece para parar de responder, o serviço pode ter afirmado e ter exibido em uma caixa de mensagem que você não veja.  Você pode confirmar isso usando o depurador do Visual C\+\+ para depurar seu código \(consulte [Usando o gerenciador de tarefas](../atl/using-task-manager.md) anteriormente em esta seção.\)  
  
 Se você determinar que o serviço está exibindo uma caixa de mensagem que você não possa ver, você pode querer definir a opção de **Permitir que o serviço interaja com a área de trabalho** antes de usar o serviço novamente.  Essa opção é um parâmetro de inicialização que permite todas as caixas de mensagem exibida pelo serviço para aparecer na área de trabalho.  Para definir essa opção, abra o aplicativo do painel de controle de serviços, selecione o serviço, clique em **Inicialização**, selecione a opção de **Permitir que o serviço interaja com a área de trabalho** .  
  
## Consulte também  
 [Dicas de depuração](../atl/debugging-tips.md)