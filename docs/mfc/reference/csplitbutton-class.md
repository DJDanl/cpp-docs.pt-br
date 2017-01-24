---
title: "Classe de CSplitButton | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
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
  - "Classe de CSplitButton"
ms.assetid: 6844d0a9-6408-4e44-9b5f-57628ed8bad6
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSplitButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CSplitButton` representa um controle de botão split.  O controle de botão split executa um comportamento padrão quando um usuário clica na parte principal do botão, e exibe um menu drop\-down quando um usuário clica na seta suspensa do botão.  
  
## Sintaxe  
  
```  
class CSplitButton : public CButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitButton::CSplitButton](../Topic/CSplitButton::CSplitButton.md)|Constrói um objeto de `CSplitButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitButton::Create](../Topic/CSplitButton::Create.md)|Cria um controle de botão split com os estilos especificados e anexa ao objeto atual de `CSplitButton` .|  
|[CSplitButton::SetDropDownMenu](../Topic/CSplitButton::SetDropDownMenu.md)|Define o menu suspenso que é exibido quando um usuário clica na seta suspensa do controle de botão split atual.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSplitButton::OnDropDown](../Topic/CSplitButton::OnDropDown.md)|Trata a notificação de `BCN_DROPDOWN` que o sistema envia quando um usuário clica na seta suspensa do controle de botão split atual.|  
  
## Comentários  
 A classe de `CSplitButton` é derivada da classe de [CButton](../../mfc/reference/cbutton-class.md) .  O controle de botão split é um controle de botão cujo estilo é `BS_SPLITBUTTON`.  Exibe um menu personalizado quando um usuário clica na seta suspensa.  Para obter mais informações, consulte os estilos de `BS_SPLITBUTTON` e de `BS_DEFSPLITBUTTON` em [Estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951).  
  
 A figura a seguir descreve um caixa de diálogo que contém um controle de paginação e \(1\) um controle de botão de divisão.  A seta suspensa \(2\) já foi clicado e o submenus \(3\) é exibido.  
  
 ![Caixa de diálogo com um controle splitbutton e pager.](../../mfc/reference/media/splitbutton_pager.png "SplitButton\_Pager")  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 `CSplitButton`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
 Essa classe é suportado em [!INCLUDE[windowsver](../Token/windowsver_md.md)] e posteriormente.  
  
 Os requisitos adicionais para essa classe são descritos em [Requisitos de compilação para controles comuns do Windows Vista](../../mfc/build-requirements-for-windows-vista-common-controls.md).  
  
## Consulte também  
 [CSplitButton Class](../../mfc/reference/csplitbutton-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CButton](../../mfc/reference/cbutton-class.md)