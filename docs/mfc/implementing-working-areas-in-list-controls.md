---
title: Implementando áreas de trabalho em controles de lista
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [MFC], working areas
- working areas in list control [MFC]
ms.assetid: fbbb356b-3359-4348-8603-f1cb114cadde
ms.openlocfilehash: 91577203163247bd230fecb083cf1c50e2875b98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377218"
---
# <a name="implementing-working-areas-in-list-controls"></a>Implementando áreas de trabalho em controles de lista

Por padrão, um controle de lista organiza todos os itens de forma padrão. No entanto, outro método é suportado, áreas de trabalho, que organiza os itens da lista em grupos retangulares. Para obter uma imagem de um controle de lista que implemente áreas de trabalho, consulte Usando controles de exibição de listas no SDK do Windows.

> [!NOTE]
> As áreas de trabalho só são visíveis quando o controle de lista está no modo ícone ou pequeno ícone. No entanto, todas as áreas de trabalho atuais são mantidas se a exibição for comutada para o modo relatório ou lista.

As áreas de trabalho podem ser usadas para exibir uma borda vazia (à esquerda, superior e/ou direita dos itens), ou fazer com que uma barra de rolagem horizontal seja exibida quando normalmente não haveria uma. Outro uso comum é criar várias áreas de trabalho para as quais os itens podem ser movidos ou descartados. Com este método, você pode criar áreas em uma única visão que têm significados diferentes. O usuário poderia então categorizar os itens colocando-os em uma área diferente. Um exemplo disso seria a exibição de um sistema de arquivos que tem uma área para arquivos de leitura/gravação e outra área para arquivos somente leitura. Se um item de arquivo fosse movido para a área somente leitura, ele se tornaria automaticamente somente leitura. Mover um arquivo da área somente leitura para a área de leitura/gravação faria com que o arquivo leia/escreva.

`CListCtrl`fornece várias funções de membros para criar e gerenciar áreas de trabalho em seu controle de lista. [GetWorkAreas](../mfc/reference/clistctrl-class.md#getworkareas) e [SetWorkAreas](../mfc/reference/clistctrl-class.md#setworkareas) recuperam `CRect` e definem uma matriz de objetos (ou `RECT` estruturas), que armazenam as áreas de trabalho atualmente implementadas para o controle de sua lista. Além disso, [getNumberOfWorkAreas](../mfc/reference/clistctrl-class.md#getnumberofworkareas) recupera o número atual de áreas de trabalho para o controle de sua lista (por padrão, zero).

## <a name="items-and-working-areas"></a>Itens e Áreas de Trabalho

Quando uma área de trabalho é criada, itens que estão dentro da área de trabalho tornam-se membros dela. Da mesma forma, se um item é movido para uma área de trabalho, torna-se um membro da área de trabalho para a qual foi movido. Se um item não estiver dentro de qualquer área de trabalho, ele automaticamente se torna um membro da primeira área de trabalho (índice 0). Se você quiser criar um item e colocá-lo dentro de uma área de trabalho específica, você precisará criar o item e movê-lo para a área de trabalho desejada com uma chamada para [SetItemPosition](../mfc/reference/clistctrl-class.md#setitemposition). O segundo exemplo abaixo demonstra essa técnica.

O exemplo a seguir implementa quatro áreas de trabalho (`rcWorkAreas`), de tamanho igual com`m_WorkAreaListCtrl`uma borda de 10 pixels de largura em torno de cada área de trabalho, em um controle de lista ().

[!code-cpp[NVC_MFCControlLadenDialog#20](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_1.cpp)]

A chamada para [ApproximateViewRect](../mfc/reference/clistctrl-class.md#approximateviewrect) foi feita para obter uma estimativa da área total necessária para exibir todos os itens em uma região. Esta estimativa é então dividida em quatro regiões e acolchoada com uma borda de 5 pixels de largura.

O próximo exemplo atribui os itens da lista`rcWorkAreas`existentes a cada grupo`m_WorkAreaListCtrl`( ) e atualiza a exibição de controle ( ) para completar o efeito.

[!code-cpp[NVC_MFCControlLadenDialog#21](../mfc/codesnippet/cpp/implementing-working-areas-in-list-controls_2.cpp)]

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
