---
title: "Criando o controle de tabula&#231;&#227;o | Microsoft Docs"
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
  - "TCS_EX_REGISTERDROP"
  - "TCS_EX_FLATSEPARATORS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CTabCtrl, criando"
  - "controles de guia, criando"
  - "Estilo estendido TCS_EX_FLATSEPARATORS"
  - "Estilo estendido TCS_EX_REGISTERDROP"
ms.assetid: 3a9c2d64-f5f4-41ea-84ab-fceb73c3dbdc
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o controle de tabula&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o controle da guia é criado depende de se você estiver usando o controle em uma caixa de diálogo ou se estiver criando em uma janela de nondialog.  
  
### Para usar CTabCtrl diretamente em uma caixa de diálogo  
  
1.  No publicador da caixa de diálogo, adicione um controle da guia para seu recurso de modelo da caixa de diálogo.  Especificar sua ID de controle  
  
2.  Use [Adicionar o assistente da variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CTabCtrl](../Topic/CTabCtrl%20Class.md) com a propriedade do controle.  Você pode usar esse membro para chamar funções de membro de `CTabCtrl` .  
  
3.  Funções de manipulador do mapa na classe da caixa de diálogo para algumas notificações que o controle da guia você precisar ser identificado.  Para obter mais informações, consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md).  
  
4.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), defina os estilos para `CTabCtrl`.  
  
### Para usar CTabCtrl em uma janela de nondialog  
  
1.  Define o controle na exibição ou na classe da janela.  
  
2.  Chame a função de membro de [Crie](../Topic/CTabCtrl::Create.md) de controle, possivelmente em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md), possivelmente a partir da função pai do manipulador de [OnCreate](../Topic/CWnd::OnCreate.md) da janela \(se você subclassing o controle\).  Definir os estilos do controle.  
  
 Depois que o objeto de `CTabCtrl` foi criado, você poderá definir ou limpar os seguintes estilos estendidos:  
  
-   **TCS\_EX\_FLATSEPARATORS** o controle da guia desenhará separadores entre os itens da guia.  Afete estendidos desse estilo guia somente os controles que têm os estilos de **TCS\_BUTTONS** e de **TCS\_FLATBUTTONS** .  Por padrão, criando o guia controle com os conjuntos de estilo de **TCS\_FLATBUTTONS** esse estilo estendido.  
  
-   **TCS\_EX\_REGISTERDROP** o controle da guia gerenciar notificações de **TCN\_GETOBJECT** para solicitar um objeto de destino de descarte quando um objeto é arrastado para os itens da guia no controle.  
  
    > [!NOTE]
    >  Para receber uma notificação de **TCN\_GETOBJECT** , você deve inicializar as bibliotecas do com uma chamada a [AfxOleInit](../Topic/AfxOleInit.md).  
  
 Esses estilos podem ser recuperados e definido, depois que o controle for criado, com chamadas a funções de membro de [GetExtendedStyle](../Topic/CTabCtrl::GetExtendedStyle.md) e de [SetExtendedStyle](../Topic/CTabCtrl::SetExtendedStyle.md) .  
  
 Por exemplo, defina o estilo de **TCS\_EX\_FLATSEPARATORS** com as seguintes linhas de código:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#33](../mfc/codesnippet/CPP/creating-the-tab-control_1.cpp)]  
  
 Limpar o estilo de **TCS\_EX\_FLATSEPARATORS** de um objeto de `CTabCtrl` com as seguintes linhas de código:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#34](../mfc/codesnippet/CPP/creating-the-tab-control_2.cpp)]  
  
 Isso removerá os separadores que aparecem entre os botões do objeto de `CTabCtrl` .  
  
## Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)