---
title: "Usando cadeias de caracteres de formato personalizado em um controle de seletor de data e hora | Microsoft Docs"
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
  - "Classe CDateTimeCtrl, estilos de exibição"
  - "Controle DateTimePicker [MFC]"
  - "Controle DateTimePicker [MFC], estilos de exibição"
ms.assetid: 7d577f03-6ca0-4597-9093-50b78f304719
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando cadeias de caracteres de formato personalizado em um controle de seletor de data e hora
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, os controles de seletor de data e hora fornecem três tipos de formato \(cada formato que corresponde a um estilo exclusivo\) para exibir a data atual ou a hora:  
  
-   **DTS\_LONGDATEFORMAT** exibe a data no formato completo, produzir saída como “quarta\-feira 3 de janeiro de 2000”.  
  
-   **DTS\_SHORTDATEFORMAT** exibe a data no formato curto, produzir saída como “1\/3\/00 ".  
  
-   **DTS\_TIMEFORMAT** exibe a hora no formato completo, produzir saída como “5:31: 42 PM.”.  
  
 Porém, você pode personalizar a aparência de data ou hora usando uma cadeia de caracteres de formato personalizada.  Essa cadeia de caracteres personalizado é composto de caracteres de formato existente, caracteres de nonformat, ou uma combinação de ambos.  Uma vez que a cadeia de caracteres personalizado? a, fazer uma chamada a [CDateTimeCtrl::SetFormat](../Topic/CDateTimeCtrl::SetFormat.md) que passa na cadeia de caracteres personalizado.  O controle de seletor de data e hora exibirá o valor atual usando a cadeia de caracteres de formato personalizada.  
  
 O código de exemplo a seguir \(onde `m_dtPicker` é o objeto de `CDateTimeCtrl` \) demonstra uma solução possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#7](../mfc/codesnippet/CPP/using-custom-format-strings-in-a-date-and-time-picker-control_1.cpp)]  
  
 Além das cadeias de caracteres de formato personalizadas, os controles de seletor de data e hora também dão suporte a [campos de retorno de chamada](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
## Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)