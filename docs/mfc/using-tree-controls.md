---
title: "Usando controles de &#225;rvore | Microsoft Docs"
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
  - "Classe CTreeCtrl, usando"
  - "controles em árvore, sobre controles de árvore"
ms.assetid: 4e92941a-e477-4fb1-b1ce-4abeafbef1c1
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando controles de &#225;rvore
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso típico de um controle de árvore \(\)[CTreeCtrl](../mfc/reference/ctreectrl-class.md)segue o padrão abaixo:  
  
-   O controle é criado.  Se o controle for especificado em um modelo da caixa de diálogo ou se você estiver usando `CTreeView`, a criação for automático quando a caixa de diálogo ou exibição é criada.  Se você quiser criar o controle de árvore como uma janela filho de alguma outra janela, use a função de membro de [Crie](../Topic/CTreeCtrl::Create.md) .  
  
-   Se você deseja que o controle de árvore para usar imagens, defina uma lista de imagem chamando [SetImageList](../Topic/CTreeCtrl::SetImageList.md).  Você também pode alterar o recuo chamando [SetIndent](../Topic/CTreeCtrl::SetIndent.md).  Boas hora fazer isso estão em [OnInitDialog](../Topic/CDialog::OnInitDialog.md) \(para controles em caixas de diálogo\) ou em [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) \(para exibições\).  
  
-   Os dados colocados no controle chamando `CTreeCtrl`[InsertItem](../Topic/CTreeCtrl::InsertItem.md) função uma vez para cada item de dados.  `InsertItem` retorna um identificador para o item que você pode usar para se referir posteriormente, como ao adicionar itens filho.  Boas hora inicializar os dados estão em `OnInitDialog` \(para controles em caixas de diálogo\) ou em `OnInitialUpdate` \(para exibições\).  
  
-   Porque o usuário interage com o controle, enviará mais notificações.  Você pode especificar uma função para tratar cada uma das mensagens que deseja tratar adicionando uma macro de **ON\_NOTIFY\_REFLECT** em seu mapa da mensagem da janela de controle ou adicionando uma macro de `ON_NOTIFY` ao mapa pai da mensagem da janela do.  [Notificações de controle de árvore](../mfc/tree-control-notification-messages.md) consulte posteriormente neste tópico para obter uma lista de notificações possíveis.  
  
-   Chame as várias funções de membro definidas para definir valores do controle.  As alterações que você pode fazer para incluir definir recuo e modificar o texto, a imagem, ou os dados associados a um item.  
  
-   Use o mais conseguem funções para examinar o conteúdo do controle.  Você também pode atravessar o conteúdo do controle de árvore com as funções que permitem que você recupere os identificadores aos pais, os filhos, e os irmãos de um item especificado.  Você mesmo pode classificar os filhos de um nó específico.  
  
-   Quando você terminar ao controle, verifique se o é destruído corretamente.  Se o controle de árvore está em uma caixa de diálogo ou se for uma exibição, e o objeto de `CTreeCtrl` serão destruídos automaticamente.  Caso contrário, você precisa assegurar que a validação e o objeto de `CTreeCtrl` serem destruídos corretamente.  
  
## Consulte também  
 [Usando CTreeCtrl](../Topic/Using%20CTreeCtrl.md)   
 [Controles](../mfc/controls-mfc.md)