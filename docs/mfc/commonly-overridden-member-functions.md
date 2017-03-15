---
title: "Fun&#231;&#245;es de membro normalmente substitu&#237;das | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDialog, membros"
  - "classes da caixa de diálogo, funções de membro normalmente substituídas"
  - "caixas de diálogo MFC, substituindo funções de membro"
  - "Função OnCancel"
  - "Função OnInitDialog"
  - "Função OnOK"
  - "substituição, membros de classe de caixa de diálogo"
ms.assetid: 78eb566c-e361-4c86-8db5-c7e2791b249a
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de membro normalmente substitu&#237;das
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir lista as funções de membro mais provável para substituir em seu `CDialog`\- classe derivada.  
  
### Funções de membro geralmente substituídas da classe CDialog  
  
|Função de membro|O responde a mensagem|Finalidade de substituição|  
|----------------------|---------------------------|--------------------------------|  
|`OnInitDialog`|**WM\_INITDIALOG**|Inicializar os controles da caixa de diálogo.|  
|`OnOK`|**BN\_CLICKED** para o botão **IDOK**|Responder quando o usuário clicar no botão OK.|  
|`OnCancel`|**BN\_CLICKED** para o botão **IDCANCEL**|Responder quando o usuário clicar no botão de cancelamento.|  
  
 `OnInitDialog`, `OnOK`, e `OnCancel` são funções virtuais.  Substituí\-los, você declara uma função substituindo em sua classe derivada da caixa de diálogo que usa [Janela Propriedades](../Topic/Properties%20Window.md).  
  
 `OnInitDialog` é chamado imediatamente antes da caixa de diálogo é exibida.  Você deve chamar o manipulador padrão de `OnInitDialog` de sua substituição — geralmente como a primeira ação no manipulador.  Por padrão, `OnInitDialog` retorna **Verdadeiro** para indicar que o foco deve ser definido para o primeiro controle na caixa de diálogo.  
  
 `OnOK` é substituído normalmente para caixas de diálogo modeless mas não modais.  Se você substituir esse manipulador para uma caixa de diálogo modal, chame a versão da classe base da substituição — para garantir que `EndDialog` — ou seja chamado de chamada `EndDialog` você mesmo.  
  
 `OnCancel` geralmente é substituído para caixas de diálogo modeless.  
  
 Para obter mais informações sobre essas funções de membro, consulte a classe [CDialog](../mfc/reference/cdialog-class.md)*na referência de MFC* e a discussão em [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md).  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Funções de membro normalmente adicionadas](../Topic/Commonly%20Added%20Member%20Functions.md)