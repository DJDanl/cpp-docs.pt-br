---
title: Funções de membro de controle deslizante
ms.date: 11/04/2016
helpviewer_keywords:
- CSliderCtrl class [MFC], methods
- slider controls [MFC], member functions
ms.assetid: dbde49ee-7306-4d14-a6ce-d09aa198178f
ms.openlocfilehash: a88dd1a49eb928261393a4473ee7eb53628c607a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307425"
---
# <a name="slider-control-member-functions"></a>Funções de membro de controle deslizante

Um aplicativo pode chamar o controle deslizante de funções de membro do controle para recuperar informações sobre o controle deslizante ([CSliderCtrl](../mfc/reference/csliderctrl-class.md)) e para alterar suas características.

Para recuperar a posição do controle deslizante (ou seja, o valor que o usuário tiver escolhido), use o [GetPos](../mfc/reference/csliderctrl-class.md#getpos) função de membro. Para definir a posição do controle deslizante, use o [SetPos](../mfc/reference/csliderctrl-class.md#setpos) função de membro. A qualquer momento, você pode usar o `VerifyPos` a função de membro para certificar-se de que o controle deslizante está entre os valores mínimo e máximo.

O intervalo de um controle deslizante é o conjunto de valores contíguos que o controle deslizante pode representar. A maioria dos aplicativos é usar o [SetRange](../mfc/reference/csliderctrl-class.md#setrange) função de membro para definir o intervalo de um controle deslizante quando ele é criado pela primeira vez. Aplicativos podem alterar dinamicamente o intervalo após o controle deslizante foi criado usando o [SetRangeMax](../mfc/reference/csliderctrl-class.md#setrangemax) e [SetRangeMin](../mfc/reference/csliderctrl-class.md#setrangemin) funções de membro. Um aplicativo que permite que o intervalo a ser alterado dinamicamente normalmente recupera as configurações de intervalo final quando o usuário termina de trabalhar com o controle deslizante. Para recuperar essas configurações, use o [GetRange](../mfc/reference/csliderctrl-class.md#getrange), [GetRangeMax](../mfc/reference/csliderctrl-class.md#getrangemax), e [GetRangeMin](../mfc/reference/csliderctrl-class.md#getrangemin) funções de membro.

Um aplicativo pode usar o estilo TBS_AUTOTICKS ter exibidas automaticamente as marcas de escala do controle deslizante. Se um aplicativo precisar controlar a posição ou a frequência das marcas de escala, no entanto, um número de funções de membro pode ser usado.

Para definir a posição de uma marca de escala, um aplicativo pode usar o [SetTic](../mfc/reference/csliderctrl-class.md#settic) função de membro. O [SetTicFreq](../mfc/reference/csliderctrl-class.md#setticfreq) função de membro permite que um aplicativo definir as marcas que aparecem em intervalos regulares no intervalo do controle deslizante de escala. Por exemplo, o aplicativo pode usar essa função de membro para exibir apenas 10 marcas de escala em um intervalo de 1 a 100.

Para recuperar o índice do intervalo correspondente a uma marca de escala, use o [GetTic](../mfc/reference/csliderctrl-class.md#gettic) função de membro. O [GetTicArray](../mfc/reference/csliderctrl-class.md#getticarray) função de membro recupera uma matriz desses índices. Para recuperar a posição de uma marca de escala, nas coordenadas do cliente, use o [GetTicPos](../mfc/reference/csliderctrl-class.md#getticpos) função de membro. Um aplicativo pode recuperar o número de marcas de escala usando o [GetNumTics](../mfc/reference/csliderctrl-class.md#getnumtics) função de membro.

O [ClearTics](../mfc/reference/csliderctrl-class.md#cleartics) função membro remove todas as marcas de escala do controle deslizante.

Tamanho da linha do controle deslizante determina até onde o controle deslizante se move quando um aplicativo recebe uma mensagem de notificação TB_LINEDOWN ou TB_LINEUP. Da mesma forma, o tamanho da página determina a resposta para as mensagens de notificação TB_PAGEDOWN e TB_PAGEUP. Aplicativos podem recuperar e definir os valores de tamanho de linha e página usando o [GetLineSize](../mfc/reference/csliderctrl-class.md#getlinesize), [SetLineSize](../mfc/reference/csliderctrl-class.md#setlinesize), [GetPageSize](../mfc/reference/csliderctrl-class.md#getpagesize), e [SetPageSize](../mfc/reference/csliderctrl-class.md#setpagesize) funções de membro.

Um aplicativo pode usar funções de membro para recuperar as dimensões de um controle deslizante. O [GetThumbRect](../mfc/reference/csliderctrl-class.md#getthumbrect) função de membro recupera o retângulo delimitador para o controle deslizante. O [GetChannelRect](../mfc/reference/csliderctrl-class.md#getchannelrect) função de membro recupera o retângulo delimitador do canal do controle deslizante. (O canal é a área em que move o controle deslizante e que contém o realce quando um intervalo está selecionado.)

Se um controle deslizante tem o estilo TBS_ENABLESELRANGE, o usuário pode selecionar um intervalo de valores contíguos dele. Um número de funções de membro permitem que o intervalo de seleção para ser ajustado dinamicamente. O [SetSelection](../mfc/reference/csliderctrl-class.md#setselection) função de membro define inicial e final posições de uma seleção. Quando o usuário tiver terminado de definir um intervalo de seleção, um aplicativo pode recuperar as configurações usando o [GetSelection](../mfc/reference/csliderctrl-class.md#getselection) função de membro. Para limpar a seleção do usuário, use o [ClearSel](../mfc/reference/csliderctrl-class.md#clearsel) função de membro.

## <a name="see-also"></a>Consulte também

[Usando CSliderCtrl](../mfc/using-csliderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
