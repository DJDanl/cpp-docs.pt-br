---
title: "Criando o controle de cabe&#231;alho | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "Classe CHeaderCtrl, criando"
  - "controles de cabeçalho, criando"
ms.assetid: 7864d9d2-4a2c-4622-b58b-7b110a1e28d2
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o controle de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O controle de cabeçalho não está diretamente disponível no publicador da caixa de diálogo \(embora você pode adicionar um controle de lista, que inclui um controle de cabeçalho\).  
  
### Para colocar um controle de cabeçalho em uma caixa de diálogo  
  
1.  Digitar manualmente uma variável de membro do tipo [CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md) em sua classe da caixa de diálogo.  
  
2.  Em [OnInitDialog](../Topic/CDialog::OnInitDialog.md), crie e define os estilos para `CHeaderCtrl`, posiciona\-os, e exibi\-los.  
  
3.  Adicionar itens ao controle de cabeçalho.  
  
4.  Use a janela Propriedades para mapear funções do manipulador na classe da caixa de diálogo para todas as notificações de cabeçalho\- controle você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
### Para colocar um controle de cabeçalho em uma exibição \(não um CListView\)  
  
1.  Inserir um objeto de [CHeaderCtrl](../Topic/CHeaderCtrl%20Class.md) em sua classe da exibição.  
  
2.  O estilo, posição, e exibe a janela de controle do cabeçalho na função de membro de [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) de exibição.  
  
3.  Adicionar itens ao controle de cabeçalho.  
  
4.  Use a janela Propriedades para mapear funções do manipulador na classe de exibição para todas as notificações de cabeçalho\- controle você precisar controlar [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)\(consulte\).  
  
 Em ambos os casos, o objeto inserido de controle é criado quando o objeto de exibição ou na caixa de diálogo é criado.  Então você deve chamar [CHeaderCtrl::Create](../Topic/CHeaderCtrl::Create.md) para criar a janela de controle.  Para posicionar o controle, chame [CHeaderCtrl::Layout](../Topic/CHeaderCtrl::Layout.md) para determinar o tamanho inicial de controle e posiciona\-os para e [SetWindowPos](../Topic/CWnd::SetWindowPos.md) para definir a posição que você deseja.  Adicione itens conforme descrito em [Adicionando itens ao controle de cabeçalho](../mfc/adding-items-to-the-header-control.md).  
  
 Para obter mais informações, consulte [Criando um controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775238) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)