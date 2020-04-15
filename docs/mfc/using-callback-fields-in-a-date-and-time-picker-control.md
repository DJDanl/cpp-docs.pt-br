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
ms.openlocfilehash: 50350e51b6747d8c010db9d0dcaa9dff2e56e1f3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366565"
---
# <a name="using-callback-fields-in-a-date-and-time-picker-control"></a>Usando campos de retorno de chamada em um controle de seletor de data e hora

Além dos caracteres de formato padrão que definem campos de seleção de data e hora, você pode personalizar sua saída especificando certas partes de uma seqüência de formato personalizado como campos de retorno de chamada. Para declarar um campo de retorno de chamada, inclua um ou mais caracteres "X" (CÓDIGO ASCII 88) em qualquer lugar do corpo da seqüência de formato. Por exemplo, a seguinte string "'Hoje é: 'yy'/'MM'/'dd' (Dia 'X')'"faz com que o controle de data e hora do seletor exiba o valor atual como o ano seguido pelo mês, data e, finalmente, o dia do ano.

> [!NOTE]
> O número de X em um campo de retorno de chamada não corresponde ao número de caracteres que serão exibidos.

Você pode distinguir entre vários campos de retorno de chamada em uma seqüência de caracteres personalizadas repetindo o caractere "X". Assim, a seqüência de formato "XXddddMMMdd", "yyyXXX" contém dois campos de chamada exclusivos, "XX" e "XXX".

> [!NOTE]
> Os campos de retorno de chamada são tratados como campos válidos, de modo que seu aplicativo deve estar preparado para lidar com mensagens de notificação DTN_WMKEYDOWN.

A implementação de campos de retorno de chamada no controle de data e hora do seletor consiste em três partes:

- Inicializando a seqüência de formato personalizado

- Lidar com a notificação de DTN_FORMATQUERY

- Lidar com a notificação DTN_FORMAT

## <a name="initializing-the-custom-format-string"></a>Inicializando a string de formato personalizado

Inicialize a seqüência `CDateTimeCtrl::SetFormat`personalizada com uma chamada para . Para obter mais informações, consulte [Usando strings de formato personalizado em um controle de seleção de datas e horas](../mfc/using-custom-format-strings-in-a-date-and-time-picker-control.md). Um lugar comum para definir a `OnInitDialog` seqüência de formato `OnInitialUpdate` personalizado está na função de sua classe de diálogo contendo ou função da sua classe de exibição contendo.

## <a name="handling-the-dtn_formatquery-notification"></a>Manuseio da Notificação de DTN_FORMATQUERY

Quando o controle analisa a seqüência de formatos e encontra um campo de retorno de chamada, o aplicativo envia mensagens de notificação DTN_FORMAT e DTN_FORMATQUERY. A seqüência de campo de retorno de chamada está incluída nas notificações para que você possa determinar qual campo de retorno de chamada está sendo consultado.

A notificação DTN_FORMATQUERY é enviada para recuperar o tamanho máximo permitido em pixels da string que será exibida no campo de retorno de chamada atual.

Para calcular corretamente este valor, você deve calcular a altura e a largura da string, a ser substituída pelo campo, usando a fonte de exibição do controle. O cálculo real da seqüência é facilmente alcançado com uma chamada para a função [GetTextExtentPoint32](/windows/win32/api/wingdi/nf-wingdi-gettextextentpoint32w) Win32. Uma vez determinado o tamanho, passe o valor de volta para o aplicativo e saia da função do manipulador.

O exemplo a seguir é um método de fornecer o tamanho da seqüência de chamadas:

[!code-cpp[NVC_MFCControlLadenDialog#8](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_1.cpp)]

Uma vez calculado o tamanho do campo de retorno de chamada atual, você deve fornecer um valor para o campo. Isso é feito no manipulador para a notificação DTN_FORMAT.

## <a name="handling-the-dtn_format-notification"></a>Manuseio da Notificação de DTN_FORMAT

A notificação DTN_FORMAT é usada pelo aplicativo para solicitar a seqüência de caracteres que será substituída. O exemplo a seguir demonstra um método possível:

[!code-cpp[NVC_MFCControlLadenDialog#9](../mfc/codesnippet/cpp/using-callback-fields-in-a-date-and-time-picker-control_2.cpp)]

> [!NOTE]
> O ponteiro para a estrutura **NMDATETIMEFORMAT** é encontrado lançando o primeiro parâmetro do manipulador de notificação para o tipo adequado.

## <a name="see-also"></a>Confira também

[Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
