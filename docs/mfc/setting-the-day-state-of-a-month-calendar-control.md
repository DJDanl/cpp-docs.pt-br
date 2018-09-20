---
title: Definindo o estado do dia de um mês de controle de calendário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MCN_GETDAYSTATE
dev_langs:
- C++
helpviewer_keywords:
- CMonthCalCtrl class [MFC], setting day state info
- MCN_GETDAYSTATE notification [MFC]
- month calendar controls [MFC], day state info
ms.assetid: 435d1b11-ec0e-4121-9e25-aaa6af812a3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b443e1758f766b7fa2dd9a0169ab98172423779d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439336"
---
# <a name="setting-the-day-state-of-a-month-calendar-control"></a>Definindo o estado do dia de um controle de calendário mensal

Um dos atributos de um controle de calendário mensal é a capacidade de armazenar informações, conhecidas como o estado do dia do controle, para cada dia do mês. Essas informações são usadas para enfatizar certas datas para o mês atualmente exibido.

> [!NOTE]
>  O `CMonthCalCtrl` objeto deve ter o estilo MCS_DAYSTATE para exibir informações de estado do dia.

Informações de estado do dia é expresso como um tipo de dados de 32 bits **MONTHDAYSTATE**. Cada bit em uma **MONTHDAYSTATE** campo de bits (1 a 31) representa o estado de um dia de um mês. Se um bit estiver ativado, o dia correspondente será exibido em negrito; Caso contrário, ele será exibido com nenhuma ênfase.

Há dois métodos para definir o estado do dia de controle de calendário mensal: explicitamente com uma chamada para [CMonthCalCtrl::SetDayState](../mfc/reference/cmonthcalctrl-class.md#setdaystate) ou manipulando a mensagem de notificação MCN_GETDAYSTATE.

## <a name="handling-the-mcngetdaystate-notification-message"></a>Lidar com a mensagem de notificação MCN_GETDAYSTATE

A mensagem MCN_GETDAYSTATE é enviada pelo controle para determinar como os dias nos meses visíveis devem ser exibidos.

> [!NOTE]
>  Como o controle armazena em cache os meses anteriores e seguintes, em relação aos mês visível, você receberá essa notificação toda vez que um novo mês é escolhido.

Para lidar adequadamente com essa mensagem, você deve determinar quantos meses as informações de estado do dia está sendo solicitada para, inicializar uma matriz de **MONTHDAYSTATE** estruturas com os valores adequados e inicialize o membro da estrutura relacionados com as novas informações. O procedimento a seguir, que detalha as etapas necessárias, pressupõe que você tenha um `CMonthCalCtrl` objeto chamado *m_monthcal* e uma matriz de **MONTHDAYSTATE** objetos, *mdState*.

#### <a name="to-handle-the-mcngetdaystate-notification-message"></a>Para lidar com a mensagem de notificação MCN_GETDAYSTATE

1. Usando a janela Propriedades, adicionar um manipulador de notificação para a mensagem MCN_GETDAYSTATE para o *m_monthcal* objeto (veja [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).

1. No corpo do manipulador, adicione o seguinte código:

     [!code-cpp[NVC_MFCControlLadenDialog#26](../mfc/codesnippet/cpp/setting-the-day-state-of-a-month-calendar-control_1.cpp)]

     O exemplo converte o *pNMHDR* ponteiro para o tipo apropriado, em seguida, determina o número de meses de informações está sendo solicitado (`pDayState->cDayState`). Para cada mês, o campo de bits atual (`pDayState->prgDayState[i]`) é inicializado como zero e, em seguida, o necessários datas são definir (neste caso, o 15º dia de cada mês).

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

