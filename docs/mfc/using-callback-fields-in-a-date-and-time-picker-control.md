---
title: Usando campos de retorno de chamada em um seletor de data e hora controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 092038a141f3ace1969fcfa50ec4a5cefb77de0c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195167"
---
# <a name="using-callback-fields-in-a-date-and-time-picker-control"></a>Usando campos de retorno de chamada em um controle de seletor de data e hora
Além dos caracteres de formato padrão que definem os campos de seletor de data e hora, você pode personalizar a saída especificando determinadas partes de uma cadeia de caracteres de formato personalizado como campos de retorno de chamada. Para declarar um campo de retorno de chamada, inclua um ou mais caracteres "X" (88 do código ASCII) em qualquer lugar no corpo da cadeia de caracteres de formato. Por exemplo, a seguinte cadeia de caracteres "' hoje é: 'yy' / 'MM' / 'dd' (dia 'X')'" faz com que o controle de seletor de data e hora exibir o valor atual como o ano seguido por mês, data e, finalmente, o dia do ano.  
  
> [!NOTE]
>  O número de x em um retorno de chamada de campo não corresponde ao número de caracteres que será exibido.  
  
 Você pode distinguir entre os vários campos de retorno de chamada em uma cadeia de caracteres personalizada repetindo o caractere "X". Assim, a cadeia de caracteres de formato "XXddddMMMdd', ' yyyXXX" contém dois campos de retorno de chamada exclusivos, "XX" e "XXX".  
  
> [!NOTE]
>  Campos de retorno de chamada são tratados como campos válidos, portanto, seu aplicativo deve estar preparado para lidar com mensagens de notificação DTN_WMKEYDOWN.  
  
 Implementar os campos de retorno de chamada em seu controle de seletor de data e hora consiste em três partes:  
  
-   Inicializando a cadeia de caracteres de formato personalizado  
  
-   Manipulando a DTN_FORMATQUERY (notificação)  
  
-   Manipulando a DTN_FORMAT (notificação)  
  
## <a name="initializing-the-custom-format-string"></a>Inicializando a cadeia de caracteres de formato personalizado  
 Inicialize a cadeia de caracteres personalizada com uma chamada para `CDateTimeCtrl::SetFormat`. Para obter mais informações, consulte [usando cadeias de caracteres personalizada em um controle de seletor de tempo de data e](../mfc/using-custom-format-strings-in-a-date-and-time-picker-control.md). Um lugar comum para definir a cadeia de caracteres de formato personalizado é na `OnInitDialog` função de sua classe de caixa de diálogo contém ou `OnInitialUpdate` função da sua classe recipiente do modo de exibição.  
  
## <a name="handling-the-dtnformatquery-notification"></a>Manipulando a DTN_FORMATQUERY (notificação)  
 Quando o controle analisa a cadeia de caracteres de formato e encontra um campo de retorno de chamada, o aplicativo envia mensagens de notificação DTN_FORMAT e DTN_FORMATQUERY. A cadeia de caracteres de campo de retorno de chamada é incluída com as notificações para que você possa determinar qual campo de retorno de chamada está sendo consultado.  
  
 A DTN_FORMATQUERY (notificação) é enviada para recuperar o tamanho máximo permitido em pixels, da cadeia de caracteres que será exibido no campo de retorno de chamada atual.  
  
 Para calcular corretamente esse valor, você deve calcular a altura e largura da cadeia de caracteres, deve ser substituído para o campo, usando a fonte de exibição do controle. O cálculo real da cadeia de caracteres pode ser conseguido facilmente com uma chamada para o [GetTextExtentPoint32](/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) função do Win32. Depois que o tamanho é determinado, passe o valor para o aplicativo e a função do manipulador de saída.  
  
 O exemplo a seguir é um método de fornecer o tamanho da cadeia de caracteres de retorno de chamada:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#8](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_1.cpp)]  
  
 Depois que o tamanho do campo de retorno de chamada atual foi calculado, você deve fornecer um valor para o campo. Isso é feito no manipulador para o DTN_FORMAT (notificação).  
  
## <a name="handling-the-dtnformat-notification"></a>Manipulando a DTN_FORMAT (notificação)  
 A DTN_FORMAT (notificação) é usada pelo aplicativo para solicitar a cadeia de caracteres que será substituída. O exemplo a seguir demonstra um método possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#9](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_2.cpp)]  
  
> [!NOTE]
>  O ponteiro para o **NMDATETIMEFORMAT** estrutura for encontrada ao converter o primeiro parâmetro do manipulador de notificação para o tipo apropriado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

