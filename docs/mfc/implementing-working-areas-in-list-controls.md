---
title: "Implementando &#225;reas de trabalho em controles de lista | Microsoft Docs"
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
  - "controles de lista, áreas de trabalho"
  - "áreas de trabalho no controle de lista"
ms.assetid: fbbb356b-3359-4348-8603-f1cb114cadde
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando &#225;reas de trabalho em controles de lista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, um controle de página lista todos os itens em uma forma padrão da grade.  Porém, outro método tem suporte, áreas de operação, que organiza os itens de lista em grupos retangulares.  Para uma imagem de um controle da lista que implementa áreas de operação, consulte usando controles de exibição de lista em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
> [!NOTE]
>  As áreas de trabalho são visíveis apenas quando o controle da lista está no ícone ou o modo de ícone pequeno.  Porém, todas as áreas de trabalho atuais são mantidas se a exibição é alternada para o modo de relatório ou na lista.  
  
 As áreas de trabalho podem ser usadas para exibir uma borda vazia \(na esquerda, e\/ou superior direito de itens\), ou causar uma barra de rolagem horizontal a ser exibida quando normalmente não haveria uma.  Outro uso comum é criar várias áreas de operação para que os itens podem ser movidos ou descartado.  Com esse método, você pode criar as áreas em uma única exibição que têm significados diferentes.  O usuário pode então categorizar colocando os itens em uma área diferente.  Um exemplo disso seria uma exibição de um sistema de arquivos que tem uma área para arquivos de leitura\/gravação e outra área para grupos de arquivos somente leitura.  Se um item do arquivo foi movido na área somente leitura, iria automaticamente somente leitura.  Mover um arquivo da área somente leitura na área de leitura\/gravação faz a leitura\/gravação do arquivo.  
  
 `CListCtrl` fornece várias funções de membro para criar e gerenciar áreas de operação no controle da lista.  [GetWorkAreas](../Topic/CListCtrl::GetWorkAreas.md) e [SetWorkAreas](../Topic/CListCtrl::SetWorkAreas.md) recuperam e definem uma matriz de objetos `CRect` \(ou as estruturas de `RECT` \), que armazenam as áreas de operação atualmente implementadas para o controle da lista.  Além disso, [GetNumberOfWorkAreas](../Topic/CListCtrl::GetNumberOfWorkAreas.md) recupera o número atual de áreas de trabalho para o controle da lista \(por padrão, zero\).  
  
## Itens e áreas de operação  
 Quando uma área de trabalho é criada, os itens que residem dentro da área de trabalho se tornam em membros delas.  Da mesma forma, se um item é movido em uma área de trabalho, que se torna um membro da área de trabalho a que foi movido.  Se um item não residem dentro de uma área de trabalho, se torna automaticamente em um membro da primeira índice \(0\) área de trabalho.  Se você quiser criar um item e para o ter colocado dentro de uma área de trabalho específica, você precisará criar o item e de movê\-la na área de trabalho desejada com uma chamada a [SetItemPosition](../Topic/CListCtrl::SetItemPosition.md).  O segundo exemplo a seguir demonstra essa técnica.  
  
 O exemplo a seguir implementa quatro áreas de operação \(\),`rcWorkAreas`de tamanhos iguais a 10 pixel\- larga uma borda em torno de cada área de trabalho, em um controle de listas \(`m_WorkAreaListCtrl`\).  
  
 [!code-cpp[NVC_MFCControlLadenDialog#20](../mfc/codesnippet/CPP/implementing-working-areas-in-list-controls_1.cpp)]  
  
 A chamada para [ApproximateViewRect](../Topic/CListCtrl::ApproximateViewRect.md) foi feito para obter uma estimativa da área total necessária para exibir todos os itens em uma região.  Essa estimativa em é dividido em quatro regiões e preenchida com uma borda 5 pixel\- larga.  
  
 O exemplo a seguir atribui os itens da lista existente para cada grupo`rcWorkAreas`\(\) e a atualizações a exibição de controle \(`m_``WorkAreaListCtrl`\) para concluir o efeito.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#21](../mfc/codesnippet/CPP/implementing-working-areas-in-list-controls_2.cpp)]  
  
## Consulte também  
 [Usando CListCtrl](../Topic/Using%20CListCtrl.md)   
 [Controles](../mfc/controls-mfc.md)