---
title: "Classe de CPagerCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CPagerCtrl"
ms.assetid: 65ac58dd-4f5e-4b7e-b15c-e0d435a7e884
caps.latest.revision: 26
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CPagerCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CPagerCtrl` envolve o controle paginação do windows, que pode rolar no modo de exibição uma janela que contém não se ajusta a janela que a contém.  
  
## Sintaxe  
  
```  
class CPagerCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPagerCtrl::CPagerCtrl](../Topic/CPagerCtrl::CPagerCtrl.md)|Constrói um objeto de `CPagerCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CPagerCtrl::Create](../Topic/CPagerCtrl::Create.md)|Cria um controle de paginação através de estilos especificados e anexá\-la ao objeto atual de `CPagerCtrl` .|  
|[CPagerCtrl::CreateEx](../Topic/CPagerCtrl::CreateEx.md)|Cria um controle de paginação através de estilos estendidos especificados e anexá\-la ao objeto atual de `CPagerCtrl` .|  
|[CPagerCtrl::ForwardMouse](../Topic/CPagerCtrl::ForwardMouse.md)|Habilita ou desabilita encaminhar mensagens de [WM\_MOUSEMOVE](http://msdn.microsoft.com/library/windows/desktop/ms645616) para a janela que está contida no controle atual de paginação.|  
|[CPagerCtrl::GetBkColor](../Topic/CPagerCtrl::GetBkColor.md)|Recupera a cor do plano de fundo do controle atual de paginação.|  
|[CPagerCtrl::GetBorder](../Topic/CPagerCtrl::GetBorder.md)|Retorna o tamanho da borda do controle atual de paginação.|  
|[CPagerCtrl::GetButtonSize](../Topic/CPagerCtrl::GetButtonSize.md)|Retorna o tamanho do botão do controle atual de paginação.|  
|[CPagerCtrl::GetButtonState](../Topic/CPagerCtrl::GetButtonState.md)|Recupera o estado do botão especificado no controle atual de paginação.|  
|[CPagerCtrl::GetDropTarget](../Topic/CPagerCtrl::GetDropTarget.md)|Recupera a interface de [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) do controle atual de paginação.|  
|[CPagerCtrl::GetScrollPos](../Topic/CPagerCtrl::GetScrollPos.md)|Retorna a posição de rolagem do controle atual de paginação.|  
|[CPagerCtrl::IsButtonDepressed](../Topic/CPagerCtrl::IsButtonDepressed.md)|Indica se o botão de controle específico de paginação atual está no estado de `pressed` .|  
|[CPagerCtrl::IsButtonGrayed](../Topic/CPagerCtrl::IsButtonGrayed.md)|Indica se o botão de controle específico de paginação atual está no estado de `grayed` .|  
|[CPagerCtrl::IsButtonHot](../Topic/CPagerCtrl::IsButtonHot.md)|Indica se o botão de controle específico de paginação atual está no estado de `hot` .|  
|[CPagerCtrl::IsButtonInvisible](../Topic/CPagerCtrl::IsButtonInvisible.md)|Indica se o botão de controle específico de paginação atual está no estado de `invisible` .|  
|[CPagerCtrl::IsButtonNormal](../Topic/CPagerCtrl::IsButtonNormal.md)|Indica se o botão de controle específico de paginação atual está no estado de `normal` .|  
|[CPagerCtrl::RecalcSize](../Topic/CPagerCtrl::RecalcSize.md)|Faz com que o controle atual de paginação recalcule o tamanho da janela contida.|  
|[CPagerCtrl::SetBkColor](../Topic/CPagerCtrl::SetBkColor.md)|Define a cor do plano de fundo do controle atual de paginação.|  
|[CPagerCtrl::SetBorder](../Topic/CPagerCtrl::SetBorder.md)|Defina o tamanho da borda do controle atual de paginação.|  
|[CPagerCtrl::SetButtonSize](../Topic/CPagerCtrl::SetButtonSize.md)|Defina o tamanho do botão do controle atual de paginação.|  
|[CPagerCtrl::SetChild](../Topic/CPagerCtrl::SetChild.md)|Define a janela contida do controle atual de paginação.|  
|[CPagerCtrl::SetScrollPos](../Topic/CPagerCtrl::SetScrollPos.md)|Define a posição de rolagem do controle atual de paginação.|  
  
## Comentários  
 Um controle de paginação é uma janela que contém outra janela que é linear quanto maior do que a janela continente, e permite rolar a janela contida no modo.  O controle exibe dois botões de paginação de rolagem que desaparecem automaticamente quando a janela é rolada contida sua extensão extrema, e reaparecem caso contrário.  Você pode criar um controle de paginação que rolar horizontalmente ou verticalmente.  
  
 Por exemplo, se seu aplicativo tiver uma barra de ferramentas que não é larga o suficiente para mostrar todos seus itens, você pode atribuir a barra de ferramentas para um controle paginação e os usuários poderão rolar a barra de ferramentas o esquerda ou direita para acessar todos os itens.  A versão 4,0 do Microsoft Internet Explorer \(versão 4,71 de commctrl.dll\) apresenta o controle paginação.  
  
 A classe de `CPagerCtrl` é derivada da classe de [CWnd](../Topic/CWnd%20Class.md) .  Para mais informações e um exemplo de um controle de paginação, consulte [Controles de paginação](http://msdn.microsoft.com/library/windows/desktop/bb760855).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CPagerCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CPagerCtrl Class](../../mfc/reference/cpagerctrl-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Controles de paginação](http://msdn.microsoft.com/library/windows/desktop/bb760855)