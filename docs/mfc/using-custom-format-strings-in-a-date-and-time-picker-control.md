---
title: Usando cadeias de caracteres de formato personalizado em um seletor de data e hora controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CDateTimeCtrl class [MFC], display styles
- DateTimePicker control [MFC], display styles
- DateTimePicker control [MFC]
ms.assetid: 7d577f03-6ca0-4597-9093-50b78f304719
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bfaad06571a8648db24497c46d55cb2eb1ce2157
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-custom-format-strings-in-a-date-and-time-picker-control"></a>Usando cadeias de caracteres de formato personalizado em um controle de seletor de data e hora
Por padrão, os controles de seletor de data e hora fornecem que três tipos (cada formato correspondente a um estilo exclusivo) de formato para exibir a data ou hora atual:  
  
-   **DTS_LONGDATEFORMAT** exibe a data em formato longo, produzir a saída como "Quarta-feira, 3 de janeiro de 2000".  
  
-   **DTS_SHORTDATEFORMAT** exibe a data no formato curto, produzir a saída como "1/3/00".  
  
-   **DTS_TIMEFORMAT** exibe a hora no formato longo, produzir a saída como "5:31:42 PM".  
  
 No entanto, você pode personalizar a aparência de data ou hora usando uma cadeia de caracteres de formato personalizado. Essa cadeia de caracteres personalizada é composta de caracteres de formato existente, de caracteres nonformat ou em uma combinação de ambos. Depois que a cadeia de caracteres personalizada é criada, fazer uma chamada para [CDateTimeCtrl::SetFormat](../mfc/reference/cdatetimectrl-class.md#setformat) passando a cadeia de caracteres personalizada. O controle de seletor de data e hora, em seguida, exibirá o valor atual usando a cadeia de caracteres de formato personalizado.  
  
 O exemplo de código a seguir (onde `m_dtPicker` é o `CDateTimeCtrl` objeto) demonstra uma solução possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#7](../mfc/codesnippet/cpp/using-custom-format-strings-in-a-date-and-time-picker-control_1.cpp)]  
  
 Além de cadeias de caracteres de formato personalizado, o seletor de data e hora também controla o suporte [campos de retorno de chamada](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

