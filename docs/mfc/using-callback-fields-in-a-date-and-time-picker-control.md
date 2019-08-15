---
title: Usando campos de retorno de chamada em um controle de seletor de data e hora
ms.date: 11/04/2016
f1_keywords:
- DTN_FORMATQUERY
- DTN_FORMAT
helpviewer_keywords:
- DateTimePicker control [MFC], callback fields
- callback fields in CDateTimeCtrl class [MFC]
- CDateTimeCtrl class [MFC], callback fields
- CDateTimeCtrl class [MFC], handling DTN_FORMAT and DTN_FORMATQ
- DTN_FORMATQUERY notification [MFC]
- DTN_FORMAT notification [MFC]
- DateTimePicker control [MFC]
ms.assetid: 404f4ba9-cba7-4718-9faa-bc6b274a723f
ms.openlocfilehash: 5d08c349253e62c15553cfa0452cee930b1a1876
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513512"
---
# <a name="using-callback-fields-in-a-date-and-time-picker-control"></a>Usando campos de retorno de chamada em um controle de seletor de data e hora

Além dos caracteres de formato padrão que definem os campos do seletor de data e hora, você pode personalizar a saída especificando determinadas partes de uma cadeia de caracteres de formato personalizado como campos de retorno de chamada. Para declarar um campo de retorno de chamada, inclua um ou mais caracteres "X" (código ASCII 88) em qualquer lugar no corpo da cadeia de caracteres de formato. Por exemplo, a seguinte cadeia de caracteres "" hoje é: "yy"/"MM"/"dd" (dia "X") "" faz com que o controle do seletor de data e hora exiba o valor atual como o ano seguido de mês, data e, por fim, o dia do ano.

> [!NOTE]
>  O número de X em um campo de retorno de chamada não corresponde ao número de caracteres que serão exibidos.

Você pode distinguir entre vários campos de retorno de chamada em uma cadeia de caracteres personalizada repetindo o caractere "X". Portanto, a cadeia de caracteres de formato "XXddddMMMdd", "yyyXXX", contém dois campos de retorno de chamada exclusivos, "XX" e "XXX".

> [!NOTE]
>  Os campos de retorno de chamada são tratados como campos válidos e, portanto, seu aplicativo deve estar preparado para lidar com mensagens de notificação DTN_WMKEYDOWN.

A implementação de campos de retorno de chamada em seu controle seletor de data e hora consiste em três partes:

- Inicializando a cadeia de caracteres de formato personalizado

- Manipulando a notificação DTN_FORMATQUERY

- Manipulando a notificação DTN_FORMAT

## <a name="initializing-the-custom-format-string"></a>Inicializando a cadeia de caracteres de formato personalizado

Inicialize a cadeia de caracteres personalizada com uma `CDateTimeCtrl::SetFormat`chamada para. Para obter mais informações, consulte [usando cadeias de caracteres de formato personalizado em um controle seletor de data e hora](../mfc/using-custom-format-strings-in-a-date-and-time-picker-control.md). Um local comum para definir a cadeia de caracteres de formato personalizado `OnInitDialog` é a função da classe de caixa `OnInitialUpdate` de diálogo que a contém ou função da classe de exibição que a contém.

## <a name="handling-the-dtn_formatquery-notification"></a>Manipulando a notificação DTN_FORMATQUERY

Quando o controle analisa a cadeia de caracteres de formato e encontra um campo de retorno de chamada, o aplicativo envia mensagens de notificação DTN_FORMAT e DTN_FORMATQUERY. A cadeia de caracteres do campo de retorno de chamada é incluída com as notificações para que você possa determinar qual campo de retorno de chamada está sendo consultado.

A notificação DTN_FORMATQUERY é enviada para recuperar o tamanho máximo permitido em pixels da cadeia de caracteres que será exibida no campo de retorno de chamada atual.

Para calcular corretamente esse valor, você deve calcular a altura e a largura da cadeia de caracteres, para que ela seja substituída pelo campo, usando a fonte de exibição do controle. O cálculo real da cadeia de caracteres é facilmente conseguido com uma chamada para a função Win32 [GetTextExtentPoint32](/windows/win32/api/wingdi/nf-wingdi-gettextextentpoint32w) . Depois que o tamanho é determinado, passe o valor de volta para o aplicativo e saia da função do manipulador.

O exemplo a seguir é um método de fornecer o tamanho da cadeia de caracteres de retorno:

[!code-cpp[NVC_MFCControlLadenDialog#8](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_1.cpp)]

Depois que o tamanho do campo de retorno de chamada atual tiver sido calculado, você deverá fornecer um valor para o campo. Isso é feito no manipulador para a notificação DTN_FORMAT.

## <a name="handling-the-dtn_format-notification"></a>Manipulando a notificação DTN_FORMAT

A notificação DTN_FORMAT é usada pelo aplicativo para solicitar a cadeia de caracteres que será substituída. O exemplo a seguir demonstra um possível método:

[!code-cpp[NVC_MFCControlLadenDialog#9](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_2.cpp)]

> [!NOTE]
>  O ponteiro para a estrutura **NMDATETIMEFORMAT** é encontrado pela conversão do primeiro parâmetro do manipulador de notificação para o tipo apropriado.

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
