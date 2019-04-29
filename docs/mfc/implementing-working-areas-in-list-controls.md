---
title: Implementando áreas de trabalho em controles de lista
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], working areas
- working areas in list control [MFC]
ms.assetid: fbbb356b-3359-4348-8603-f1cb114cadde
ms.openlocfilehash: 01b166243c9032a113d46ff297b9f6e53429da21
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62297210"
---
# <a name="implementing-working-areas-in-list-controls"></a>Implementando áreas de trabalho em controles de lista

Por padrão, um controle de lista organiza todos os itens de uma maneira de grade padrão. No entanto, outro método tem suporte, áreas, que organiza os itens da lista em retangulares grupos de trabalho. Para uma imagem de um controle de lista que implementa áreas de trabalho, consulte usando controles de exibição de lista no SDK do Windows.

> [!NOTE]
>  Áreas de trabalho são visíveis apenas quando o controle de lista está no modo de pequeno ícone ou ícone. No entanto, as áreas de trabalho atual são mantidas se o modo de exibição é alternado para o modo de relatório ou uma lista.

Áreas de trabalho podem ser usadas para exibir uma borda vazia (sobre a esquerda, superior e/ou direito dos itens), ou fazer com que a ser exibida quando há normalmente não uma barra de rolagem horizontal. Outro uso comum é criar várias áreas de trabalho para o qual os itens podem ser movidos ou removidos. Com esse método, você poderia criar áreas em uma única exibição que têm significados diferentes. O usuário pode, em seguida, categorizar os itens, colocando-os em uma área diferente. Um exemplo disso seria um modo de exibição de um sistema de arquivo que tem uma área para arquivos de leitura/gravação e outra área para arquivos somente leitura. Se um item de arquivo foram movido para a área de somente leitura, ele seria automaticamente se tornará somente leitura. Movendo um arquivo de área de somente leitura para a área de leitura/gravação tornaria o arquivo de leitura/gravação.

`CListCtrl` fornece várias funções de membro para criar e gerenciar áreas de trabalho no controle de lista. [GetWorkAreas](../mfc/reference/clistctrl-class.md#getworkareas) e [SetWorkAreas](../mfc/reference/clistctrl-class.md#setworkareas) recuperar e definir uma matriz de `CRect` objetos (ou `RECT` estruturas), que armazena as áreas de trabalho implementado atualmente para o seu controle de lista. Além disso, [GetNumberOfWorkAreas](../mfc/reference/clistctrl-class.md#getnumberofworkareas) recupera o número atual de áreas de trabalho para o seu controle de lista (por padrão, zero).

## <a name="items-and-working-areas"></a>Itens e áreas de trabalho

Quando uma área de trabalho é criada, os itens que estiverem na área de trabalho se tornar membros dele. Da mesma forma, se um item é movido para uma área de trabalho, ele se torna um membro da área de trabalho para o qual ele foi movido. Se um item não residem dentro de qualquer área de trabalho, ele se tornará automaticamente um membro da área de trabalho (índice 0) primeiro. Se você quiser criar um item e que ele seja colocado em uma área de trabalho específica, você precisará criar o item e, em seguida, mova-o para a área de trabalho desejado com uma chamada para [SetItemPosition](../mfc/reference/clistctrl-class.md#setitemposition). O segundo exemplo abaixo demonstra essa técnica.

O exemplo a seguir implementa quatro áreas de trabalho (`rcWorkAreas`), de tamanho igual com uma borda ao redor de cada área de trabalho, em um controle de lista de 10 pixels de largura (`m_WorkAreaListCtrl`).

[!code-cpp[NVC_MFCControlLadenDialog#20](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_1.cpp)]

A chamada para [ApproximateViewRect](../mfc/reference/clistctrl-class.md#approximateviewrect) foi feita para obter uma estimativa da área total necessária para exibir todos os itens em uma região. Essa estimativa é dividida em quatro regiões e preenchida com uma borda de 5 pixels de largura.

O exemplo a seguir atribui os itens da lista existente para cada grupo (`rcWorkAreas`) e atualiza a exibição de controle (`m_WorkAreaListCtrl`) para concluir o efeito.

[!code-cpp[NVC_MFCControlLadenDialog#21](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_2.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
