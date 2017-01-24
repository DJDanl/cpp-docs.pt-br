---
title: "Classe de CDateTimeCtrl | Microsoft Docs"
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
  - "CDateTimeCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDateTimeCtrl"
  - "funcionalidade de datas recortagem"
  - "Controle DateTimePicker [MFC]"
  - "Controle DateTimePicker [MFC], Classe de CDateTimeCtrl"
ms.assetid: 7113993b-5d37-4148-939f-500a190c5bdc
caps.latest.revision: 23
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDateTimeCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Encapsula funcionalidade de um controle seletor de data e hora.  
  
## Sintaxe  
  
```  
class CDateTimeCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDateTimeCtrl::CDateTimeCtrl](../Topic/CDateTimeCtrl::CDateTimeCtrl.md)|Constrói um objeto de `CDateTimeCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDateTimeCtrl::CloseMonthCal](../Topic/CDateTimeCtrl::CloseMonthCal.md)|Fecha o controle seletor de data e hora.|  
|[CDateTimeCtrl::Create](../Topic/CDateTimeCtrl::Create.md)|Cria o controle seletor de data e hora e anexá\-la ao objeto de `CDateTimeCtrl` .|  
|[CDateTimeCtrl::GetDateTimePickerInfo](../Topic/CDateTimeCtrl::GetDateTimePickerInfo.md)|Recupera informações sobre o controle seletor de data e hora.|  
|[CDateTimeCtrl::GetIdealSize](../Topic/CDateTimeCtrl::GetIdealSize.md)|Retorna o tamanho ideal de controle seletor de data e hora que é necessário para exibir a data ou hora atual.|  
|[CDateTimeCtrl::GetMonthCalColor](../Topic/CDateTimeCtrl::GetMonthCalColor.md)|Recupera a cor para uma determinada parte do calendário mensal dentro do controle seletor de data e hora.|  
|[CDateTimeCtrl::GetMonthCalCtrl](../Topic/CDateTimeCtrl::GetMonthCalCtrl.md)|Retorna o objeto de `CMonthCalCtrl` associado ao controle seletor de data e hora.|  
|[CDateTimeCtrl::GetMonthCalFont](../Topic/CDateTimeCtrl::GetMonthCalFont.md)|Recupera a fonte usada no momento pelo controle filho do calendário mensal de controle seletor de data e hora.|  
|[CDateTimeCtrl::GetMonthCalStyle](../Topic/CDateTimeCtrl::GetMonthCalStyle.md)|Obtém o estilo de controle seletor de data e hora.|  
|[CDateTimeCtrl::GetRange](../Topic/CDateTimeCtrl::GetRange.md)|Recupera o mínimo atual e a hora do sistema reservados máximo para um controle seletor de data e hora.|  
|[CDateTimeCtrl::GetTime](../Topic/CDateTimeCtrl::GetTime.md)|Recupera o tempo atualmente selecionados de um controle seletor de data e hora e os coloca em uma estrutura específica de `SYSTEMTIME` .|  
|[CDateTimeCtrl::SetFormat](../Topic/CDateTimeCtrl::SetFormat.md)|Define a exibição de um controle seletor de data e hora de acordo com uma determinada cadeia de caracteres de formato.|  
|[CDateTimeCtrl::SetMonthCalColor](../Topic/CDateTimeCtrl::SetMonthCalColor.md)|Define a cor para uma determinada parte do calendário mensal dentro de um controle seletor de data e hora.|  
|[CDateTimeCtrl::SetMonthCalFont](../Topic/CDateTimeCtrl::SetMonthCalFont.md)|Define a fonte que o controle filho do calendário mensal de controle seletor de data e hora usará.|  
|[CDateTimeCtrl::SetMonthCalStyle](../Topic/CDateTimeCtrl::SetMonthCalStyle.md)|Defina o estilo de controle seletor de data e hora.|  
|[CDateTimeCtrl::SetRange](../Topic/CDateTimeCtrl::SetRange.md)|Define o mínimo e a hora do sistema reservados máximo para um controle seletor de data e hora.|  
|[CDateTimeCtrl::SetTime](../Topic/CDateTimeCtrl::SetTime.md)|Defina a hora em um controle seletor de data e hora.|  
  
## Comentários  
 O controle seletor de data e hora \(controle de DTP\) fornece uma interface simples para trocar informações de data e hora com um usuário.  Essa interface contém campos, cada um de eles exibe uma parte das informações de data e hora armazenada no controle.  O usuário pode alterar informações armazenadas no controle modificando o conteúdo da cadeia de caracteres em um campo especificado.  O usuário pode mover de campo para o campo usando o mouse ou o teclado.  
  
 Você pode personalizar o controle seletor de data e hora aplicando uma variedade de estilos ao objeto quando você o cria.  Consulte [O selecionador de data e hora os estilos](http://msdn.microsoft.com/library/windows/desktop/bb761728) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre estilos específicos para o controle seletor de data e hora.  Você pode definir o formato de exibição de controle de DTP usando estilos de formato.  Esses estilos de formatação são descritos no formato “suporta” no tópico [O selecionador de data e hora os estilos](http://msdn.microsoft.com/library/windows/desktop/bb761728)de [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)] .  
  
 O controle seletor de data e hora também usa as notificações e os retornos de chamada, que são descritas em [usando CDateTimeCtrl](../../mfc/using-cdatetimectrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CDateTimeCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxdtctl.h  
  
## Consulte também  
 [Exemplo CMNCTRL1 MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)