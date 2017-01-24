---
title: "Estilos para o controle de progresso | Microsoft Docs"
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
  - "Classe CProgressCtrl, estilos"
  - "Estilo PBS_SMOOTH"
  - "Estilo PBS_VERTICAL"
  - "controles de andamento [C++], estilos"
ms.assetid: 39eb8081-bc20-4552-91b9-e7cdd1b7d8ae
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos para o controle de progresso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você criar inicialmente o controle do progresso \([CProgressCtrl::Create](../Topic/CProgressCtrl::Create.md)\), use o parâmetro de `dwStyle` para especificar os estilos desejados da janela para o controle de progresso.  A lista a seguir detalha os estilos aplicáveis da janela.  O controle ignora qualquer estilo da janela exceto aqueles listados aqui.  Você sempre deve criar o controle como uma janela filho, geralmente de um pai da caixa de diálogo.  
  
|Estilo da janela|Efeito|  
|----------------------|------------|  
|`WS_BORDER`|Cria uma borda em torno da janela.|  
|**WS\_CHILD**|Cria uma janela filho \(sempre deve ser usado para `CProgressCtrl`\).|  
|**WS\_CLIPCHILDREN**|Exclui a área ocupada por janelas filho quando você desenha dentro da janela pai.  Usado ao criar a janela pai.|  
|**WS\_CLIPSIBLINGS**|Recorta as janelas filho relacionadas ao.|  
|**WS\_DISABLED**|Cria uma janela que é desabilitada inicialmente.|  
|**WS\_VISIBLE**|Cria uma janela que é inicialmente visível.|  
|**WS\_TABSTOP**|Especifica que o controle pode receber o foco quando o usuário pressione a tecla TAB para ir para a ele.|  
  
 Além disso, você pode especificar dois estilos que se aplicam apenas ao controle, a `PBS_VERTICAL` e a `PBS_SMOOTH`de progresso.  
  
 Use `PBS_VERTICAL` para orientação vertical do controle, em vez de horizontalmente.  Use `PBS_SMOOTH` para preencher completamente o controle, em vez de exibi\-los quadrados representados por pequenos que preenchem o controle incremental.  
  
 Sem estilo de `PBS_SMOOTH` :  
  
 ![Tela de StandardProgressBarStyle](../mfc/media/vc4ruw1.png "vc4RUW1")  
  
 Com `PBS_SMOOTH` e estilos de `PBS_VERTICAL` :  
  
 ![Tela de ProgressBarStyle&#95;SmoothVertical](../mfc/media/vc4ruw2.png "vc4RUW2")  
  
 Para obter mais informações, consulte [Estilos da janela](../mfc/reference/frame-window-styles-mfc.md)*na referência de MFC*.  
  
## Consulte também  
 [Usando CProgressCtrl](../mfc/using-cprogressctrl.md)