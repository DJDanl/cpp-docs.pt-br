---
title: "Identificando mensagens do Windows na caixa de di&#225;logo | Microsoft Docs"
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
  - "tratamento de mensagens [C++], em caixas de diálogo"
  - "caixas de diálogo MFC, mensagens do Windows"
  - "mensagens do Windows [C++], tratamento"
ms.assetid: 4af0c9cb-09da-4b15-97df-a1cfb89def79
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Identificando mensagens do Windows na caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As caixas de diálogo são windows, assim podem tratar mensagens do windows se você fornece funções apropriadas do manipulador.  Quando você cria a classe da caixa de diálogo com o assistente da classe adicionar, o assistente adiciona um mapa de mensagem vazia à classe.  Use a janela Propriedades para mapear todas as mensagens ou comandos windows que você desejar que sua classe para tratar.  
  
 Consulte [Mensagens do windows de mapeamento a sua classe da caixa de diálogo](../mfc/mapping-windows-messages-to-your-class.md) para obter mais informações.  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)