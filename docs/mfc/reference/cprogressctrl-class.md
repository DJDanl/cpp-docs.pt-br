---
title: "Classe de CProgressCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CProgressCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CProgressCtrl"
  - "Controles comuns do Internet Explorer 4.0"
  - "controles de progresso [C++], Classe de CProgressCtrl"
ms.assetid: 222630f4-1598-4026-8198-51649b1192ab
caps.latest.revision: 25
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CProgressCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de barra de progresso do windows.  
  
## Sintaxe  
  
```  
class CProgressCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CProgressCtrl::CProgressCtrl](../Topic/CProgressCtrl::CProgressCtrl.md)|Constrói um objeto de `CProgressCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CProgressCtrl::Create](../Topic/CProgressCtrl::Create.md)|Cria um controle de barra de progresso e anexá\-la a um objeto de `CProgressCtrl` .|  
|[CProgressCtrl::CreateEx](../Topic/CProgressCtrl::CreateEx.md)|Cria um controle de andamento com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CProgressCtrl` .|  
|[CProgressCtrl::GetBarColor](../Topic/CProgressCtrl::GetBarColor.md)|Obtém a cor do indexador de barra de progresso para o controle atual de barra de progresso.|  
|[CProgressCtrl::GetBkColor](../Topic/CProgressCtrl::GetBkColor.md)|Obtém a cor do plano de fundo atual de barra de progresso.|  
|[CProgressCtrl::GetPos](../Topic/CProgressCtrl::GetPos.md)|Obtém a atual posição de barra de progresso.|  
|[CProgressCtrl::GetRange](../Topic/CProgressCtrl::GetRange.md)|Obtém os limites inferiores e superior do intervalo de controle de barra de progresso.|  
|[CProgressCtrl::GetState](../Topic/CProgressCtrl::GetState.md)|Obtém o estado atual do controle de barra de progresso.|  
|[CProgressCtrl::GetStep](../Topic/CProgressCtrl::GetStep.md)|Recupera o incremento da etapa para a barra de progresso do controle atual de barra de progresso.|  
|[CProgressCtrl::OffsetPos](../Topic/CProgressCtrl::OffsetPos.md)|Avança a posição atual de um controle de barra de progresso por um incremento especificado e redesenho para refletir a barra a nova posição.|  
|[CProgressCtrl::SetBarColor](../Topic/CProgressCtrl::SetBarColor.md)|Define a cor do indexador de barra de progresso no controle atual de barra de progresso.|  
|[CProgressCtrl::SetBkColor](../Topic/CProgressCtrl::SetBkColor.md)|Define a cor do plano de fundo para a barra de progresso.|  
|[CProgressCtrl::SetMarquee](../Topic/CProgressCtrl::SetMarquee.md)|Modo de famoso da transforma para ativar\/desativar o controle atual de barra de progresso.|  
|[CProgressCtrl::SetPos](../Topic/CProgressCtrl::SetPos.md)|Define a posição atual para o controle de barra de progresso e redesenho para refletir a barra a nova posição.|  
|[CProgressCtrl::SetRange](../Topic/CProgressCtrl::SetRange.md)|Defina os intervalos mínimo e máximo para um controle de barra de progresso e redesenho para refletir a barra novos intervalos.|  
|[CProgressCtrl::SetState](../Topic/CProgressCtrl::SetState.md)|Define o estado atual do controle de barra de progresso.|  
|[CProgressCtrl::SetStep](../Topic/CProgressCtrl::SetStep.md)|Especifica o incremento da etapa para um controle de barra de progresso.|  
|[CProgressCtrl::StepIt](../Topic/CProgressCtrl::StepIt.md)|Avança a posição atual para um controle de barra de progresso por incremento da etapa \(consulte\) [SetStep](../Topic/CProgressCtrl::SetStep.md)a barra e redesenho para refletir a nova posição.|  
  
## Comentários  
 Um controle de barra de progresso é uma janela que um aplicativo pode usar para indicar o progresso de uma operação longa.  Consiste em um retângulo que é preenchido, da esquerda para a direita, com a cor de realce do sistema a medida que uma operação progride.  
  
 Um controle de barra de progresso tem um intervalo e um posição atual.  O intervalo representa a duração total da operação, e a posição atual representa o progresso que o aplicativo tiver feito para concluir a operação.  O procedimento de janela utiliza o intervalo e a posição atual determinar a porcentagem de barra de progresso preencher com a cor de realce.  Porque valores do intervalo e da posição atual são expressos como números inteiros com sinal, o intervalo de valores possíveis da posição atual é – 2.147.483.648 a 2.147.483.647 inclusivos.  
  
 Para obter mais informações sobre como usar `CProgressCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CProgressCtrl](../../mfc/using-cprogressctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CProgressCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [Exemplo CMNCTRL2 MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)