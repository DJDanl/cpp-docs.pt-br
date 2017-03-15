---
title: "Definindo o estado do dia de um controle de calend&#225;rio mensal | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "MCN_GETDAYSTATE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMonthCalCtrl, definindo informações de estado do dia"
  - "MCN_GETDAYSTATE (notificação)"
  - "controles de calendário mensal, informações de estado do dia"
ms.assetid: 435d1b11-ec0e-4121-9e25-aaa6af812a3c
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo o estado do dia de um controle de calend&#225;rio mensal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um dos atributos de um controle de calendário do mês é a capacidade de armazenar informações, referenciada como o estado de um dia de controle, para cada dia do mês.  Estas informações são usadas para enfatizar determinadas datas do mês exibida atualmente.  
  
> [!NOTE]
>  O objeto de `CMonthCalCtrl` deve ter o estilo de **MCS\_DAYSTATE** para exibir informações de estado do dia.  
  
 Informações de estado do dia é expressa como um tipo de dados de 32 bits, **MONTHDAYSTATE**.  Cada bit em um campo de bit de **MONTHDAYSTATE** \(1 a 31\) representa o estado de um dia do mês.  Se um bit estiver ativada, o dia correspondente será exibido em negrito; se não será exibida sem dar ênfase.  
  
 Há dois métodos para definir o estado de um dia de controle de calendário do mês: explicitamente por uma chamada a [CMonthCalCtrl::SetDayState](../Topic/CMonthCalCtrl::SetDayState.md) ou executando a notificação de **MCN\_GETDAYSTATE** .  
  
## Tratando a notificação de MCN\_GETDAYSTATE  
 A mensagem de **MCN\_GETDAYSTATE** é enviada pelo controle para determinar como os dias dentro dos meses visíveis devem ser exibidos.  
  
> [!NOTE]
>  Como o controle armazena em cachê o anterior e meses a seguir, com relação ao mês visível, você receberá essa notificação sempre que um novo mês será escolhido.  
  
 Para tratar corretamente essa mensagem, você deve determinar as informações de estado do dia de número de meses estão sendo solicitadas por, inicializa uma matriz de estruturas de **MONTHDAYSTATE** com os valores apropriados, e inicializa o membro da estrutura relacionada com as novas informações.  O procedimento a seguir, o detalhamento as etapas necessárias, suponha que você tenha um objeto de `CMonthCalCtrl` chamado `m_monthcal` e uma matriz de objetos de **MONTHDAYSTATE** , `mdState`.  
  
#### Para tratar a notificação de MCN\_GETDAYSTATE  
  
1.  Usando a janela Propriedades, adicionar um manipulador de notificação para a mensagem de **MCN\_GETDAYSTATE** ao objeto de `m_monthcal` \(consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\).  
  
2.  No corpo do manipulador, adicione o seguinte código:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#26](../mfc/codesnippet/CPP/setting-the-day-state-of-a-month-calendar-control_1.cpp)]  
  
     O exemplo converte o ponteiro de `pNMHDR` no tipo apropriado, então determina quantos meses de informações estão sendo solicitado \(`pDayState->cDayState`\).  Para cada mês, o bitfield atual \(`pDayState->prgDayState[i]`\) é inicializado como zero e então as datas necessários definido como \(nesse caso, o 15º de cada mês\).  
  
## Consulte também  
 [Usando CMonthCalCtrl](../Topic/Using%20CMonthCalCtrl.md)   
 [Controles](../mfc/controls-mfc.md)