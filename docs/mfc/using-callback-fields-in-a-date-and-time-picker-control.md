---
title: Usando campos de retorno de chamada em um seletor de data e hora controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DTN_FORMATQUERY
- DTN_FORMAT
dev_langs:
- C++
helpviewer_keywords:
- DateTimePicker control [MFC], callback fields
- callback fields in CDateTimeCtrl class [MFC]
- CDateTimeCtrl class [MFC], callback fields
- CDateTimeCtrl class [MFC], handling DTN_FORMAT and DTN_FORMATQ
- DTN_FORMATQUERY notification [MFC]
- DTN_FORMAT notification [MFC]
- DateTimePicker control [MFC]
ms.assetid: 404f4ba9-cba7-4718-9faa-bc6b274a723f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9e5526b0f8826a91eb0b1c5a6eae250abbb02fcf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-callback-fields-in-a-date-and-time-picker-control"></a>Usando campos de retorno de chamada em um controle de seletor de data e hora
Além de caracteres de formato padrão que definem campos de seletor de data e hora, você pode personalizar a saída especificando algumas partes de uma cadeia de caracteres de formato personalizado como campos de retorno de chamada. Para declarar um campo de retorno de chamada, inclua um ou mais caracteres "X" (88 do código ASCII) em qualquer lugar no corpo da cadeia de caracteres de formato. Por exemplo, a seguinte cadeia de caracteres "' atualmente é: 'yy' / 'MM' / 'dd' (dia 'X')'" faz com que o controle de seletor de data e hora exibir o valor atual como o ano seguido por mês, data e, finalmente, o dia do ano.  
  
> [!NOTE]
>  O número de x em um retorno de chamada de campo não corresponde ao número de caracteres que será exibida.  
  
 Você pode distinguir entre os vários campos de retorno de chamada em uma cadeia de caracteres personalizada, repetindo o caractere "X". Assim, a cadeia de caracteres de formato "XXddddMMMdd', ' yyyXXX" contém dois campos de retorno de chamada exclusivo "XX" e "XXX".  
  
> [!NOTE]
>  Campos de retorno de chamada são tratados como campos válidos, para que seu aplicativo deve estar preparado para lidar com **DTN_WMKEYDOWN** mensagens de notificação.  
  
 Implementar os campos de retorno de chamada no controle de seletor de data e hora consiste em três partes:  
  
-   Inicializando a cadeia de caracteres de formato personalizado  
  
-   Tratamento de **DTN_FORMATQUERY** notificação  
  
-   Tratamento de **DTN_FORMAT** notificação  
  
## <a name="initializing-the-custom-format-string"></a>Inicializando a cadeia de caracteres de formato personalizado  
 Inicialize a cadeia de caracteres personalizada com uma chamada para `CDateTimeCtrl::SetFormat`. Para obter mais informações, consulte [usando cadeias de formato personalizado em uma data e o controle seletor de hora](../mfc/using-custom-format-strings-in-a-date-and-time-picker-control.md). É um local comum para definir a cadeia de caracteres de formato personalizado no `OnInitDialog` função da sua classe de caixa de diálogo contém ou `OnInitialUpdate` função da sua classe de exibição contém.  
  
## <a name="handling-the-dtnformatquery-notification"></a>Tratamento de DTN_FORMATQUERY (notificação)  
 Quando o controle analisa a cadeia de caracteres de formato e encontra um campo de retorno de chamada, o aplicativo envia **DTN_FORMAT** e **DTN_FORMATQUERY** mensagens de notificação. A cadeia de caracteres de campo de retorno de chamada é incluída com as notificações para que possa determinar qual campo de retorno de chamada está sendo consultado.  
  
 O **DTN_FORMATQUERY** notificação é enviada para recuperar o tamanho máximo permitido em pixels da cadeia de caracteres que será exibido no campo de retorno de chamada atual.  
  
 Para calcular corretamente esse valor, você deve calcular a altura e largura da cadeia de caracteres a serem substituídos por campo, usando a fonte de exibição do controle. O cálculo real da cadeia de caracteres é fácil com uma chamada para o [GetTextExtentPoint32](http://msdn.microsoft.com/library/windows/desktop/dd144938) função Win32. Depois que o tamanho é determinado, passe o valor para o aplicativo e a função do manipulador de saída.  
  
 O exemplo a seguir é um método para fornecer o tamanho da cadeia de caracteres de retorno de chamada:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#8](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_1.cpp)]  
  
 Depois que o tamanho do campo de retorno de chamada atual foi calculado, você deve fornecer um valor para o campo. Isso é feito no manipulador para o **DTN_FORMAT** notificação.  
  
## <a name="handling-the-dtnformat-notification"></a>Tratamento de DTN_FORMAT (notificação)  
 O **DTN_FORMAT** notificação é usada pelo aplicativo para solicitar a cadeia de caracteres que será substituída. O exemplo a seguir demonstra um método possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#9](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_2.cpp)]  
  
> [!NOTE]
>  O ponteiro para o **NMDATETIMEFORMAT** estrutura é encontrada por conversão o primeiro parâmetro do manipulador de notificação para o tipo adequado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

