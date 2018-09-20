---
title: Usando cadeias de caracteres de formato personalizado em um seletor de data e hora controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CDateTimeCtrl class [MFC], display styles
- DateTimePicker control [MFC], display styles
- DateTimePicker control [MFC]
ms.assetid: 7d577f03-6ca0-4597-9093-50b78f304719
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8dcfe39a3054d998cf5116ef125a3791d8c4a47
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405041"
---
# <a name="using-custom-format-strings-in-a-date-and-time-picker-control"></a>Usando cadeias de caracteres de formato personalizado em um controle de seletor de data e hora

Por padrão, os controles de seletor de data e hora fornecem que três tipos (cada formato correspondentes a um estilo exclusivo) de formato para exibir a data ou hora atual:

- **DTS_LONGDATEFORMAT** exibe a data no formato longo, produzindo a saída como "Quarta-feira, 3 de janeiro de 2000".

- **DTS_SHORTDATEFORMAT** exibe a data no formato curto, produzindo a saída como "3/1/00".

- **DTS_TIMEFORMAT** exibe a hora no formato longo, produzindo a saída como "17:31: 42,".

No entanto, você pode personalizar a aparência de data ou hora, usando uma cadeia de caracteres de formato personalizado. Essa cadeia de caracteres personalizada é composta por caracteres de formato existente, de caracteres nonformat ou em uma combinação de ambos. Depois que a cadeia de caracteres personalizada for criada, fazer uma chamada para [CDateTimeCtrl::SetFormat](../mfc/reference/cdatetimectrl-class.md#setformat) passando na sua cadeia de caracteres personalizada. O controle de seletor de data e hora, em seguida, exibirá o valor atual usando a cadeia de caracteres de formato personalizado.

O exemplo de código a seguir (onde *m_dtPicker* é o `CDateTimeCtrl` objeto) demonstra uma solução possível:

[!code-cpp[NVC_MFCControlLadenDialog#7](../mfc/codesnippet/cpp/using-custom-format-strings-in-a-date-and-time-picker-control_1.cpp)]

Além de cadeias de caracteres de formato personalizado, o seletor de data e hora também controles suportam [campos de retorno de chamada](../mfc/using-callback-fields-in-a-date-and-time-picker-control.md).

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

