---
title: Implementando áreas de trabalho em controles de lista
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], working areas
- working areas in list control [MFC]
ms.assetid: fbbb356b-3359-4348-8603-f1cb114cadde
ms.openlocfilehash: abbf9dd823e13fab252b7af8f32338b0d801079b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626382"
---
# <a name="implementing-working-areas-in-list-controls"></a>Implementando áreas de trabalho em controles de lista

Por padrão, um controle de lista organiza todos os itens de modo de grade padrão. No entanto, há suporte para outro método, áreas de trabalho, que organizam os itens de lista em grupos retangulares. Para obter uma imagem de um controle de lista que implementa áreas de trabalho, consulte usando controles de exibição de lista no SDK do Windows.

> [!NOTE]
> As áreas de trabalho ficam visíveis somente quando o controle de lista está no modo de ícone ou ícone pequeno. No entanto, todas as áreas de trabalho atuais serão mantidas se a exibição for alternada para o modo de relatório ou de lista.

As áreas de trabalho podem ser usadas para exibir uma borda vazia (na parte esquerda, superior e/ou direita dos itens) ou fazer com que uma barra de rolagem horizontal seja exibida quando normalmente não haveria uma. Outro uso comum é criar várias áreas de trabalho para as quais os itens podem ser movidos ou removidos. Com esse método, você pode criar áreas em uma única exibição com significados diferentes. O usuário poderia então categorizar os itens colocando-os em uma área diferente. Um exemplo disso seria uma exibição de um sistema de arquivos que tem uma área para arquivos de leitura/gravação e outra área para arquivos somente leitura. Se um item de arquivo foi movido para a área somente leitura, ele se tornará automaticamente somente leitura. Mover um arquivo da área somente leitura para a área de leitura/gravação tornaria o arquivo de leitura/gravação.

`CListCtrl`fornece várias funções de membro para criar e gerenciar áreas de trabalho em seu controle de lista. [GetWorkAreas](reference/clistctrl-class.md#getworkareas) e [SetWorkAreas](reference/clistctrl-class.md#setworkareas) recuperam e definem uma matriz de `CRect` objetos (ou `RECT` estruturas), que armazenam as áreas de trabalho implementadas no momento para seu controle de lista. Além disso, o [GetNumberOfWorkAreas](reference/clistctrl-class.md#getnumberofworkareas) recupera o número atual de áreas de trabalho para seu controle de lista (por padrão, zero).

## <a name="items-and-working-areas"></a>Itens e áreas de trabalho

Quando uma área de trabalho é criada, os itens que estão na área de trabalho se tornam Membros dela. Da mesma forma, se um item for movido para uma área de trabalho, ele se tornará membro da área de trabalho para a qual foi movido. Se um item não estiver em nenhuma área de trabalho, ele se tornará automaticamente um membro da primeira área de trabalho (índice 0). Se você quiser criar um item e colocá-lo dentro de uma área de trabalho específica, será necessário criar o item e, em seguida, movê-lo para a área de trabalho desejada com uma chamada para [SetItemPosition](reference/clistctrl-class.md#setitemposition). O segundo exemplo a seguir demonstra essa técnica.

O exemplo a seguir implementa quatro áreas de trabalho ( `rcWorkAreas` ), de tamanho igual com uma borda de 10 pixels em torno de cada área de trabalho, em um controle de lista ( `m_WorkAreaListCtrl` ).

[!code-cpp[NVC_MFCControlLadenDialog#20](codesnippet/cpp/implementing-working-areas-in-list-controls_1.cpp)]

A chamada para [ApproximateViewRect](reference/clistctrl-class.md#approximateviewrect) foi feita para obter uma estimativa da área total necessária para exibir todos os itens em uma região. Em seguida, essa estimativa é dividida em quatro regiões e preenchida com uma borda de 5 pixels.

O exemplo a seguir atribui os itens de lista existentes a cada grupo ( `rcWorkAreas` ) e atualiza o modo de exibição de controle ( `m_WorkAreaListCtrl` ) para concluir o efeito.

[!code-cpp[NVC_MFCControlLadenDialog#21](codesnippet/cpp/implementing-working-areas-in-list-controls_2.cpp)]

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
