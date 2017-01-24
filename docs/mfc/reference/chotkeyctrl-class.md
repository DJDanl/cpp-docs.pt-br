---
title: "Classe de CHotKeyCtrl | Microsoft Docs"
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
  - "CHotKeyCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHotKeyCtrl"
  - "controles de tecla de acesso"
  - "Controles comuns do Windows [C++], CHotKeyCtrl"
ms.assetid: 896f9766-0718-4f58-aab2-20325e118ca6
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHotKeyCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de tecla de acesso do windows.  
  
## Sintaxe  
  
```  
class CHotKeyCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHotKeyCtrl::CHotKeyCtrl](../Topic/CHotKeyCtrl::CHotKeyCtrl.md)|Constrói um objeto de `CHotKeyCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHotKeyCtrl::Create](../Topic/CHotKeyCtrl::Create.md)|Cria um controle de tecla de acesso e anexá\-la a um objeto de `CHotKeyCtrl` .|  
|[CHotKeyCtrl::CreateEx](../Topic/CHotKeyCtrl::CreateEx.md)|Cria um controle de tecla de acesso com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CHotKeyCtrl` .|  
|[CHotKeyCtrl::GetHotKey](../Topic/CHotKeyCtrl::GetHotKey.md)|Recupera os sinalizadores virtuais de código de tecla e modificadoras de uma tecla de acesso de um controle de tecla de acesso.|  
|[CHotKeyCtrl::GetHotKeyName](../Topic/CHotKeyCtrl::GetHotKeyName.md)|Recupera o nome da chave, no conjunto de caracteres local, atribuído a uma tecla de acesso.|  
|[CHotKeyCtrl::GetKeyName](../Topic/CHotKeyCtrl::GetKeyName.md)|Recupera o nome da chave, no conjunto de caracteres local, atribuído ao código da tecla virtual especificado.|  
|[CHotKeyCtrl::SetHotKey](../Topic/CHotKeyCtrl::SetHotKey.md)|Define a combinação de tecla de acesso para um controle de tecla de acesso.|  
|[CHotKeyCtrl::SetRules](../Topic/CHotKeyCtrl::SetRules.md)|Define as combinações inválidos e a combinação de modificador padrão para um controle de tecla de acesso.|  
  
## Comentários  
 “De um controle tecla de acesso” é uma janela que permite ao usuário para criar uma tecla de acesso.  Uma “tecla de acesso” é uma combinação de teclas que o usuário pode pressionar para executar rapidamente uma ação.  \(Por exemplo, um usuário pode criar uma tecla de acesso que alterna uma dada a janela e trazer à parte superior da ordem Z.\) O controle de tecla de acesso exibe as opções de usuário e garante que o usuário selecione uma combinação de teclas válido.  
  
 Este controle \(e portanto a classe de `CHotKeyCtrl` \) estão disponíveis somente para programas que executam na versão 3,51 do \/98 Windows 95 e Windows NT e posterior.  
  
 Quando o usuário escolher uma combinação de teclas, o aplicativo pode recuperar a combinação de teclas especificada do controle e usar a mensagem de **WM\_SETHOTKEY** para configurar a tecla de acesso no sistema.  Sempre que o usuário pressiona a tecla de acesso depois de isso, de qualquer parte do sistema, a janela especificada na mensagem de **WM\_SETHOTKEY** recebe uma mensagem de `WM_SYSCOMMAND` que especifica **SC\_HOTKEY**.  Esta mensagem ativa a janela que recebe a.  A tecla de acesso permanece válida até que o aplicativo **WM\_SETHOTKEY** chamado será encerrado.  
  
 Esse mecanismo é diferente de suporte a tecla de acesso que depende da mensagem de **WM\_HOTKEY** as funções e do windows [RegisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646309) e de [UnregisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646327) .  
  
 Para obter mais informações sobre como usar `CHotKeyCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CHotKeyCtrl](../../mfc/using-chotkeyctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CHotKeyCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)