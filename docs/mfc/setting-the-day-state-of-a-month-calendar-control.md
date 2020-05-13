---
title: Definindo o estado do dia de um controle de calendário mensal
ms.date: 11/04/2016
f1_keywords:
- MCN_GETDAYSTATE
helpviewer_keywords:
- CMonthCalCtrl class [MFC], setting day state info
- MCN_GETDAYSTATE notification [MFC]
- month calendar controls [MFC], day state info
ms.assetid: 435d1b11-ec0e-4121-9e25-aaa6af812a3c
ms.openlocfilehash: 9892f2d853687787dd76428fc9bc95f3a4f74565
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365424"
---
# <a name="setting-the-day-state-of-a-month-calendar-control"></a>Definindo o estado do dia de um controle de calendário mensal

Um dos atributos de um mês de controle do calendário é a capacidade de armazenar informações, referida como o estado diário do controle, para cada dia do mês. Essas informações são usadas para enfatizar determinadas datas para o mês atualmente exibido.

> [!NOTE]
> O `CMonthCalCtrl` objeto deve ter o estilo MCS_DAYSTATE para exibir informações do estado do dia.

As informações do estado diurno são expressas como um tipo de dados de 32 bits, **MONTHDAYSTATE**. Cada bit em um campo **de bits MONTHDAYSTATE** (1 a 31) representa o estado de um dia em um mês. Se um pouco estiver ligado, o dia correspondente será exibido em negrito; caso contrário, será exibido sem ênfase.

Existem dois métodos para definir o estado do dia do controle do calendário do mês: explicitamente com uma chamada para [CMonthCalCtrl::SetDayState](../mfc/reference/cmonthcalctrl-class.md#setdaystate) ou manipulando a mensagem de notificação MCN_GETDAYSTATE.

## <a name="handling-the-mcn_getdaystate-notification-message"></a>Manipulação da mensagem de notificação MCN_GETDAYSTATE

A mensagem MCN_GETDAYSTATE é enviada pelo controle para determinar como os dias dentro dos meses visíveis devem ser exibidos.

> [!NOTE]
> Como o controle armazena os meses anteriores e seguintes, em relação ao mês visível, você receberá essa notificação toda vez que um novo mês for escolhido.

Para lidar adequadamente com essa mensagem, você deve determinar para quantos meses de informações do estado de dia estão sendo solicitadas, inicializar uma matriz de estruturas **MONTHDAYSTATE** com os valores adequados e inicializar o membro da estrutura relacionada com as novas informações. O procedimento a seguir, detalhando as etapas `CMonthCalCtrl` necessárias, pressupõe que você tenha um objeto chamado *m_monthcal* e uma matriz de objetos **MONTHDAYSTATE,** *mdState*.

#### <a name="to-handle-the-mcn_getdaystate-notification-message"></a>Para lidar com a mensagem de notificação MCN_GETDAYSTATE

1. Usando o [Assistente de Classe](reference/mfc-class-wizard.md), adicione um manipulador de notificação para a mensagem MCN_GETDAYSTATE ao objeto *m_monthcal* (consulte ['''''''''''''''''''''''''''''''''''''''''''''''''''''''''''](../mfc/reference/mapping-messages-to-functions.md)

1. No corpo do manipulador, adicione o seguinte código:

   [!code-cpp[NVC_MFCControlLadenDialog#26](../mfc/codesnippet/cpp/setting-the-day-state-of-a-month-calendar-control_1.cpp)]

   O exemplo converte o ponteiro *pNMHDR* para o tipo adequado e, em`pDayState->cDayState`seguida, determina quantos meses de informações estão sendo solicitadas ( ). Para cada mês, o`pDayState->prgDayState[i]`bitfield atual é inicializado como zero e, em seguida, as datas necessárias são definidas (neste caso, no dia 15 de cada mês).

## <a name="see-also"></a>Confira também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
