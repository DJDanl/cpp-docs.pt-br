---
title: "Adicionando controles manualmente | Microsoft Docs"
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
  - "controles comuns [C++], adicionando"
  - "controlado o foco da entrada"
  - "controles [MFC], adicionando a caixas de diálogo"
  - "controles de caixas de diálogo [C++], adicionando a caixas de diálogo"
  - "foco, controlado a entrada"
  - "controle do foco da entrada"
  - "controles comuns do Windows [C++], adicionando"
ms.assetid: bc843e59-0c51-4b5b-8bf2-343f716469d2
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando controles manualmente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode [adicionar controles para uma caixa de diálogo com o publicador da caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md) ou para adicioná\-los você mesmo, com código.  
  
 Para criar um objeto você mesmo de controle, você normalmente inserirá o objeto control C\+\+ na caixa de diálogo c criando ou no objeto de quadro\- janela.  Como vários outros objetos na estrutura, os controles exigem a construção de dois estágios.  Você deve chamar a função de membro de **Criar** de controle como parte da criação da janela pai da caixa de diálogo ou do quadro.  Para caixas de diálogo, isso é feito normalmente em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), e para o windows do quadro, em [OnCreate](../Topic/CWnd::OnCreate.md).  
  
 O exemplo a seguir mostra como você pode declarar um objeto de `CEdit` na declaração de classe de uma classe derivada da caixa de diálogo e chamar a função de membro de **Criar** em `OnInitDialog`.  Como o objeto de `CEdit` é declarado como um objeto inserido, ele é criado automaticamente quando o objeto da caixa de diálogo será construído, mas ainda deve ser inicializado com sua própria função de membro de **Criar** .  
  
 [!code-cpp[NVC_MFCControlLadenDialog#1](../mfc/codesnippet/CPP/adding-controls-by-hand_1.h)]  
  
 A seguinte função de `OnInitDialog` configura um retângulo, em seguida chama **Criar** para criar o controle de edição do windows e anexá\-lo ao objeto não inicializada de `CEdit` .  
  
 [!code-cpp[NVC_MFCControlLadenDialog#2](../mfc/codesnippet/CPP/adding-controls-by-hand_2.cpp)]  
  
 Após criar o objeto de edição, você também pode definir o foco de entrada para o controle chamando a função de membro de `SetFocus` .  Finalmente, você retorna 0 de `OnInitDialog` para mostrar que você definir o foco.  Se você retorna um valor diferente de zero, o gerenciador da caixa de diálogo define o foco para o primeiro item na lista de controle do item da caixa de diálogo.  Na maioria dos casos, você desejará adicionar controles para as caixas de diálogo ao publicador da caixa de diálogo.  
  
## Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)   
 [CDialog::OnInitDialog](../Topic/CDialog::OnInitDialog.md)