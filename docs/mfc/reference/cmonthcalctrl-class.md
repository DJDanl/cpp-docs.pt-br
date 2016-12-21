---
title: "Classe de CMonthCalCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMonthCalCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMonthCalCtrl"
  - "controles comuns, Internet Explorer 4.0"
  - "Controles comuns do Internet Explorer 4.0"
  - "controles de calendário mensal"
  - "controles de calendário mensal, Classe de CMonthCalCtrl"
ms.assetid: a42f6bd6-ab5c-4335-82f8-839982fc64a2
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMonthCalCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula funcionalidade de um controle de calendário mensal.  
  
## Sintaxe  
  
```  
class CMonthCalCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMonthCalCtrl::CMonthCalCtrl](../Topic/CMonthCalCtrl::CMonthCalCtrl.md)|Constrói um objeto de `CMonthCalCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMonthCalCtrl::Create](../Topic/CMonthCalCtrl::Create.md)|Cria um controle de calendário mensal e anexá\-la ao objeto de `CMonthCalCtrl` .|  
|[CMonthCalCtrl::GetCalendarBorder](../Topic/CMonthCalCtrl::GetCalendarBorder.md)|Obtém a largura da borda do controle atual de calendário mensal.|  
|[CMonthCalCtrl::GetCalendarCount](../Topic/CMonthCalCtrl::GetCalendarCount.md)|Retorna o número de calendários exibidos no controle atual de calendário mensal.|  
|[CMonthCalCtrl::GetCalendarGridInfo](../Topic/CMonthCalCtrl::GetCalendarGridInfo.md)|Recupera informações sobre o controle atual de calendário mensal.|  
|[CMonthCalCtrl::GetCalID](../Topic/CMonthCalCtrl::GetCalID.md)|Recupera o identificador de calendário atual para o controle de calendário mensal.|  
|[CMonthCalCtrl::GetColor](../Topic/CMonthCalCtrl::GetColor.md)|Obtém a cor de uma área especificada de um controle de calendário mensal.|  
|[CMonthCalCtrl::GetCurrentView](../Topic/CMonthCalCtrl::GetCurrentView.md)|Recupera a exibição que é exibida no momento atual pelo controle de calendário mensal.|  
|[CMonthCalCtrl::GetCurSel](../Topic/CMonthCalCtrl::GetCurSel.md)|Recupera a hora do sistema como indicado em atual\- data selecionada.|  
|[CMonthCalCtrl::GetFirstDayOfWeek](../Topic/CMonthCalCtrl::GetFirstDayOfWeek.md)|Obtém o primeiro dia da semana a ser exibida na coluna mais à esquerda do calendário.|  
|[CMonthCalCtrl::GetMaxSelCount](../Topic/CMonthCalCtrl::GetMaxSelCount.md)|Retorna o número máximo de dias atual que pode ser selecionado em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMaxTodayWidth](../Topic/CMonthCalCtrl::GetMaxTodayWidth.md)|Obtém a largura máximo de” para “hoje no controle atual de calendário mensal.|  
|[CMonthCalCtrl::GetMinReqRect](../Topic/CMonthCalCtrl::GetMinReqRect.md)|Retorna o tamanho mínimo necessário mostrar um mês completo em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMonthDelta](../Topic/CMonthCalCtrl::GetMonthDelta.md)|Recupera a taxa de rolagem para um controle de calendário mensal.|  
|[CMonthCalCtrl::GetMonthRange](../Topic/CMonthCalCtrl::GetMonthRange.md)|Recupera as informações de data que representa os limites de alta e baixa de exibição de um controle de calendário mensal.|  
|[CMonthCalCtrl::GetRange](../Topic/CMonthCalCtrl::GetRange.md)|Recupera o mínimo atual e datas máximo definidos em um controle de calendário mensal.|  
|[CMonthCalCtrl::GetSelRange](../Topic/CMonthCalCtrl::GetSelRange.md)|Recupera as informações de data que representa os limites superiores e inferiores do intervalo de data atualmente selecionado pelo usuário.|  
|[CMonthCalCtrl::GetToday](../Topic/CMonthCalCtrl::GetToday.md)|Recupera as informações de data para a data especificada como “hoje” para um controle de calendário mensal.|  
|[CMonthCalCtrl::HitTest](../Topic/CMonthCalCtrl::HitTest.md)|Determina qual seção de um controle de calendário mensal está em um determinado ponto na tela.|  
|[CMonthCalCtrl::IsCenturyView](../Topic/CMonthCalCtrl::IsCenturyView.md)|Indica se a exibição atual do controle atual de calendário mensal é a exibição do século.|  
|[CMonthCalCtrl::IsDecadeView](../Topic/CMonthCalCtrl::IsDecadeView.md)|Indica se a exibição atual do controle atual de calendário mensal é modo de década.|  
|[CMonthCalCtrl::IsMonthView](../Topic/CMonthCalCtrl::IsMonthView.md)|Indica se a exibição atual do controle atual de calendário mensal é a exibição de mês.|  
|[CMonthCalCtrl::IsYearView](../Topic/CMonthCalCtrl::IsYearView.md)|Indica se a exibição atual do controle atual de calendário mensal é a exibição do ano.|  
|[CMonthCalCtrl::SetCalendarBorder](../Topic/CMonthCalCtrl::SetCalendarBorder.md)|Defina a largura da borda do controle atual de calendário mensal.|  
|[CMonthCalCtrl::SetCalendarBorderDefault](../Topic/CMonthCalCtrl::SetCalendarBorderDefault.md)|Defina a largura padrão da borda do controle atual de calendário mensal.|  
|[CMonthCalCtrl::SetCalID](../Topic/CMonthCalCtrl::SetCalID.md)|Define o identificador de calendário atual para o controle de calendário mensal.|  
|[CMonthCalCtrl::SetCenturyView](../Topic/CMonthCalCtrl::SetCenturyView.md)|Define o controle atual de calendário mensal alterna para o modo do século.|  
|[CMonthCalCtrl::SetColor](../Topic/CMonthCalCtrl::SetColor.md)|Define a cor de uma área especificada de um controle de calendário mensal.|  
|[CMonthCalCtrl::SetCurrentView](../Topic/CMonthCalCtrl::SetCurrentView.md)|Define o controle atual de calendário mensal para exibir a exibição especificada.|  
|[CMonthCalCtrl::SetCurSel](../Topic/CMonthCalCtrl::SetCurSel.md)|Define a data atualmente selecionada para um controle de calendário mensal.|  
|[CMonthCalCtrl::SetDayState](../Topic/CMonthCalCtrl::SetDayState.md)|Define a exibição de dias em um controle de calendário mensal.|  
|[CMonthCalCtrl::SetDecadeView](../Topic/CMonthCalCtrl::SetDecadeView.md)|Define o controle atual de calendário mensal para modo de década.|  
|[CMonthCalCtrl::SetFirstDayOfWeek](../Topic/CMonthCalCtrl::SetFirstDayOfWeek.md)|Define o dia da semana a ser exibida na coluna mais à esquerda do calendário.|  
|[CMonthCalCtrl::SetMaxSelCount](../Topic/CMonthCalCtrl::SetMaxSelCount.md)|Define o número máximo de dias que pode ser selecionado em um controle de calendário mensal.|  
|[CMonthCalCtrl::SetMonthDelta](../Topic/CMonthCalCtrl::SetMonthDelta.md)|Definir taxa de rolagem para um controle de calendário mensal.|  
|[CMonthCalCtrl::SetMonthView](../Topic/CMonthCalCtrl::SetMonthView.md)|Define o controle atual de calendário mensal para exibir a exibição de mês.|  
|[CMonthCalCtrl::SetRange](../Topic/CMonthCalCtrl::SetRange.md)|Define o mínimo e máximo permitido data para um controle de calendário mensal.|  
|[CMonthCalCtrl::SetSelRange](../Topic/CMonthCalCtrl::SetSelRange.md)|Define a seleção de um controle de calendário mensal a um determinado intervalo de datas.|  
|[CMonthCalCtrl::SetToday](../Topic/CMonthCalCtrl::SetToday.md)|Defina o controle de calendário para o dia atual.|  
|[CMonthCalCtrl::SetYearView](../Topic/CMonthCalCtrl::SetYearView.md)|Define o controle atual de calendário mensal para o modo do.|  
|[CMonthCalCtrl::SizeMinReq](../Topic/CMonthCalCtrl::SizeMinReq.md)|Repintura o controle de calendário mensal ao mínimo, tamanho de um mês.|  
|[CMonthCalCtrl::SizeRectToMin](../Topic/CMonthCalCtrl::SizeRectToMin.md)|Para o controle atual de calendário mensal, calcula o retângulo o menor que pode conter todos os calendários que ajustaram em um retângulo especificado.|  
  
## Comentários  
 O controle de calendário mensal fornece ao usuário uma interface simples de calendário, que o usuário pode selecionar uma data.  O usuário pode alterar a exibição por:  
  
-   Enrolando para trás e encaminhar, de mês para mês.  
  
-   Clicando no texto para exibir o dia atual \(se o estilo de **MCS\_NOTODAY** não é usado\).  
  
-   Escolhendo um mês ou ano de um menu pop\-up.  
  
 Você pode personalizar o controle de calendário mensal aplicando uma variedade de estilos ao objeto quando você o cria.  Esses estilos são descritos em [Estilos de controle de calendário mensal](http://msdn.microsoft.com/library/windows/desktop/bb760919) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 O controle de calendário mensal pode exibir mais de um mês, e pode indicar dias especiais \(como feriados\) por bolding a data.  
  
 Para obter mais informações sobre como usar o controle de calendário mensal, consulte [usando CMonthCalCtrl](../Topic/Using%20CMonthCalCtrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CMonthCalCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxdtctl.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL1](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)