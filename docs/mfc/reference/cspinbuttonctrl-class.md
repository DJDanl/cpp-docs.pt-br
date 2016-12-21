---
title: "Classe de CSpinButtonCtrl | Microsoft Docs"
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
  - "CSpinButtonCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSpinButtonCtrl"
  - "Classe de CSpinButtonCtrl, controles comuns"
  - "controle de botão de rotação"
  - "controles de up-down, controle de botão de rotação"
  - "Controles comuns do Windows [C++], CSpinButtonCtrl"
ms.assetid: 509bfd76-1c5a-4af6-973f-e133c0b87734
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSpinButtonCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de botão de rotação do windows.  
  
## Sintaxe  
  
```  
class CSpinButtonCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSpinButtonCtrl::CSpinButtonCtrl](../Topic/CSpinButtonCtrl::CSpinButtonCtrl.md)|Constrói um objeto de `CSpinButtonCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSpinButtonCtrl::Create](../Topic/CSpinButtonCtrl::Create.md)|Cria um controle de botão de rotação e anexá\-la a um objeto de `CSpinButtonCtrl` .|  
|[CSpinButtonCtrl::CreateEx](../Topic/CSpinButtonCtrl::CreateEx.md)|Cria um controle de botão de rotação com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CSpinButtonCtrl` .|  
|[CSpinButtonCtrl::GetAccel](../Topic/CSpinButtonCtrl::GetAccel.md)|Recupera informações de aceleração para um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetBase](../Topic/CSpinButtonCtrl::GetBase.md)|Recupera a base atual para um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetBuddy](../Topic/CSpinButtonCtrl::GetBuddy.md)|Recupera um ponteiro para a janela atual autorizado.|  
|[CSpinButtonCtrl::GetPos](../Topic/CSpinButtonCtrl::GetPos.md)|Obtém a atual posição de um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetRange](../Topic/CSpinButtonCtrl::GetRange.md)|Recupera os limites superiores e inferiores \(intervalo\) para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetAccel](../Topic/CSpinButtonCtrl::SetAccel.md)|Define a aceleração para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetBase](../Topic/CSpinButtonCtrl::SetBase.md)|Define a base para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetBuddy](../Topic/CSpinButtonCtrl::SetBuddy.md)|Define a janela autorizado para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetPos](../Topic/CSpinButtonCtrl::SetPos.md)|Define a posição atual para o controle.|  
|[CSpinButtonCtrl::SetRange](../Topic/CSpinButtonCtrl::SetRange.md)|Defina os limites superiores e inferiores \(intervalo\) para um controle de botão de rotação.|  
  
## Comentários  
 “De um controle de botão rotação” \(também conhecido como um controle de up\-down\) é um par de botões de seta que o usuário pode clicar para incrementar ou diminuir um valor, como uma posição de rolagem ou um número exibida em um controle complementar.  O valor associado com um controle de botão de rotação é chamado sua posição atual.  Um controle de botão de rotação é frequentemente usado para complementar, com um controle chamado de uma janela “friend”.  
  
 Este controle \(e portanto a classe de `CSpinButtonCtrl` \) estão disponíveis somente para programas que executam na versão 3,51 do \/98 Windows 95 e Windows NT e posterior.  
  
 Para o usuário, um controle de botão de rotação e sua janela autorizado geralmente aparecem como um único controle.  Você pode especificar a posição própria de controle de botão de rotação automaticamente ao lado da janela autorizado, e que define automaticamente a legenda da janela autorizado a sua posição atual.  Você pode usar um controle de botão de rotação com um controle de edição para solicitar ao usuário para a entrada numérica.  
  
 Clicando na seta para cima move a posição atual para o máximo, e clicando na seta para baixo move a posição atual para o mínimo.  Por padrão, o mínimo e máximo é 100 é 0.  Quando a configuração mínima é maior do que a configuração máximo \(por exemplo, quando as configurações padrão são usadas\), clicando na seta para cima diminui o valor de posição e clique na seta para baixo aumenta\-a.  
  
 Um controle de botão de rotação sem janela funções autorizado como um meio uma barra de rolagem simplificada.  Por exemplo, um controle de guia exibe às vezes em um controle de botão de rotação para permitir que o usuário role guias adicionais no modo.  
  
 Para obter mais informações sobre como usar `CSpinButtonCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CSpinButtonCtrl](../../mfc/using-cspinbuttonctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CSpinButtonCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL2](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CSliderCtrl](../../mfc/reference/csliderctrl-class.md)