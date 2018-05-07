---
title: Implementando áreas de trabalho em controles de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- list controls [MFC], working areas
- working areas in list control [MFC]
ms.assetid: fbbb356b-3359-4348-8603-f1cb114cadde
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 44b92fbda7f00c761059a44b5bf9483e2dfac814
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="implementing-working-areas-in-list-controls"></a>Implementando áreas de trabalho em controles de lista
Por padrão, um controle de lista organiza todos os itens de um modo de grade padrão. No entanto, outro método tem suporte, áreas, que organiza os itens da lista em retangulares grupos de trabalho. Para uma imagem de um controle de lista que implementa áreas de trabalho, consulte usando controles de exibição de lista no SDK do Windows.  
  
> [!NOTE]
>  Áreas de trabalho são visíveis apenas quando o controle de lista está no modo de ícone pequeno ou ícone. No entanto, as áreas de trabalho atual são mantidas se o modo é alternado para o modo de relatório ou uma lista.  
  
 Áreas de trabalho podem ser usadas para exibir uma borda vazia (a esquerda, superior e/ou à direita dos itens), ou fazer com que a ser exibida quando normalmente não haver uma barra de rolagem horizontal. Outro uso comum é criar várias áreas de trabalho para o qual os itens podem ser movidos ou descartados. Com esse método, você pode criar áreas em uma única exibição que têm significados diferentes. O usuário, em seguida, pode categorizar os itens, colocando-os em uma área diferente. Um exemplo disso seria um modo de exibição de um sistema de arquivos que tem uma área para arquivos de leitura/gravação e outra área para arquivos somente leitura. Se um item de arquivo foram movido para a área de somente leitura, ela automaticamente se tornarão somente leitura. Movendo um arquivo da área de somente leitura para a área de leitura/gravação tornaria o arquivo de leitura/gravação.  
  
 `CListCtrl` fornece várias funções de membro para criar e gerenciar áreas de trabalho do seu controle de lista. [GetWorkAreas](../mfc/reference/clistctrl-class.md#getworkareas) e [SetWorkAreas](../mfc/reference/clistctrl-class.md#setworkareas) recuperar e definir uma matriz de `CRect` objetos (ou `RECT` estruturas), que armazena as áreas de trabalho implementado atualmente para o controle de lista. Além disso, [GetNumberOfWorkAreas](../mfc/reference/clistctrl-class.md#getnumberofworkareas) recupera o número atual de áreas de trabalho para o controle de lista (por padrão, zero).  
  
## <a name="items-and-working-areas"></a>Itens e áreas de trabalho  
 Quando uma área de trabalho é criada, os itens que estiverem na área de trabalho se tornam membros do mesmo. Da mesma forma, se um item é movido para uma área de trabalho, ele se torna um membro da área de trabalho ao qual ele foi movido. Se um item não estiver em qualquer área de trabalho, ele automaticamente se torna um membro da primeira área de trabalho (índice 0). Se você quiser criar um item e que ele seja colocado em uma área de trabalho específica, você precisará criar o item e, em seguida, mova-o para a área de trabalho desejado com uma chamada para [SetItemPosition](../mfc/reference/clistctrl-class.md#setitemposition). O segundo exemplo abaixo demonstra essa técnica.  
  
 O exemplo a seguir implementa quatro áreas de trabalho (`rcWorkAreas`), de tamanho igual com uma borda em torno de cada área de trabalho, em um controle de lista de 10 pixels de largura (`m_WorkAreaListCtrl`).  
  
 [!code-cpp[NVC_MFCControlLadenDialog#20](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_1.cpp)]  
  
 A chamada para [ApproximateViewRect](../mfc/reference/clistctrl-class.md#approximateviewrect) foi feita para obter uma estimativa da área total necessária para exibir todos os itens em uma região. Essa estimativa é dividida em quatro regiões e preenchida com uma borda de 5 pixels de largura.  
  
 O exemplo a seguir atribui os itens existentes na lista para cada grupo (`rcWorkAreas`) e atualiza o modo de exibição de controle (`m_WorkAreaListCtrl`) para completar o efeito.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#21](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

