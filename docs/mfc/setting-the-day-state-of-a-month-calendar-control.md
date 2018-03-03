---
title: "Definindo o estado do dia de um mês de controle de calendário | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- MCN_GETDAYSTATE
dev_langs:
- C++
helpviewer_keywords:
- CMonthCalCtrl class [MFC], setting day state info
- MCN_GETDAYSTATE notification [MFC]
- month calendar controls [MFC], day state info
ms.assetid: 435d1b11-ec0e-4121-9e25-aaa6af812a3c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c634815065c68cceb3c528222c0fd60e19b6827
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setting-the-day-state-of-a-month-calendar-control"></a>Definindo o estado do dia de um controle de calendário mensal
Um dos atributos de um controle de calendário mensal é a capacidade de armazenar informações, conhecidas como o estado do dia do controle, para cada dia do mês. Essas informações são usadas para enfatizar determinadas datas do mês exibido atualmente.  
  
> [!NOTE]
>  O `CMonthCalCtrl` o objeto deve ter o **MCS_DAYSTATE** estilo para exibir informações de estado do dia.  
  
 Informações de estado do dia é expresso como um tipo de dados de 32 bits, **MONTHDAYSTATE**. Cada bit em uma **MONTHDAYSTATE** campo de bits (1 a 31) representa o estado de um dia de um mês. Se um bit estiver ativado, o dia correspondente será exibido em negrito; Caso contrário, ele será exibido com nenhuma ênfase.  
  
 Há dois métodos para definir o estado do dia do controle de calendário do mês: explicitamente com uma chamada para [CMonthCalCtrl::SetDayState](../mfc/reference/cmonthcalctrl-class.md#setdaystate) ou manipulando o **MCN_GETDAYSTATE** mensagem de notificação.  
  
## <a name="handling-the-mcngetdaystate-notification-message"></a>Tratamento de mensagem de notificação MCN_GETDAYSTATE  
 O **MCN_GETDAYSTATE** mensagem é enviada pelo controle para determinar como os dias nos meses visíveis devem ser exibidos.  
  
> [!NOTE]
>  Como o controle armazena em cache os meses anteriores e seguintes, em relação ao mês visível, você receberá essa notificação sempre que um novo mês é escolhido.  
  
 Para lidar adequadamente com essa mensagem, você deve determinar quantos meses as informações de estado do dia está sendo solicitada para, inicializar uma matriz de **MONTHDAYSTATE** estruturas com valores adequados e inicializar o membro de estrutura relacionados com as novas informações. O procedimento a seguir detalha as etapas necessárias, pressupõe que você tenha um `CMonthCalCtrl` objeto chamado `m_monthcal` e uma matriz de **MONTHDAYSTATE** objetos, `mdState`.  
  
#### <a name="to-handle-the-mcngetdaystate-notification-message"></a>Para manipular a mensagem de notificação MCN_GETDAYSTATE  
  
1.  Usando a janela Propriedades, adicione um manipulador de notificação para o **MCN_GETDAYSTATE** de mensagem para o `m_monthcal` objeto (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
2.  No corpo do manipulador, adicione o seguinte código:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#26](../mfc/codesnippet/cpp/setting-the-day-state-of-a-month-calendar-control_1.cpp)]  
  
     O exemplo converte o `pNMHDR` ponteiro para o tipo apropriado, em seguida, determina o número de meses de informações que está sendo solicitado (`pDayState->cDayState`). Para cada mês, o campo de bits atual (`pDayState->prgDayState[i]`) é inicializado como zero e, em seguida, o necessários datas são definir (neste caso, o 15º dia de cada mês).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)   
 [Controles](../mfc/controls-mfc.md)

