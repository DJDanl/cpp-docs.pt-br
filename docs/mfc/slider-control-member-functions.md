---
title: "Funções de membro de controle deslizante | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CSliderCtrl class [MFC], methods
- slider controls [MFC], member functions
ms.assetid: dbde49ee-7306-4d14-a6ce-d09aa198178f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1bd6c1d05ce7b137e6153ad2ea3fc5df99565a52
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="slider-control-member-functions"></a>Funções de membro de controle deslizante
Um aplicativo pode chamar o controle deslizante de funções de membro do controle para recuperar informações sobre o controle deslizante ([CSliderCtrl](../mfc/reference/csliderctrl-class.md)) e para alterar suas características.  
  
 Para recuperar a posição do controle deslizante (ou seja, o valor que o usuário escolheu), use o [GetPos](../mfc/reference/csliderctrl-class.md#getpos) função de membro. Para definir a posição do controle deslizante, use o [SetPos](../mfc/reference/csliderctrl-class.md#setpos) função de membro. A qualquer momento, você pode usar o `VerifyPos` a função de membro para certificar-se de que o controle deslizante está entre os valores mínimo e máximo.  
  
 O intervalo de um controle deslizante é o conjunto de valores contíguos que pode representar o controle deslizante. Maioria dos aplicativos usa o [SetRange](../mfc/reference/csliderctrl-class.md#setrange) função de membro para definir o intervalo de um controle deslizante quando ele é criado. Aplicativos podem alterar dinamicamente o intervalo após o controle deslizante foi criado usando o [SetRangeMax](../mfc/reference/csliderctrl-class.md#setrangemax) e [SetRangeMin](../mfc/reference/csliderctrl-class.md#setrangemin) funções de membro. Um aplicativo que permite que o intervalo a ser alterado dinamicamente normalmente recupera as configurações de intervalo final quando o usuário tiver terminado de trabalhar com o controle deslizante. Para recuperar essas configurações, use o [GetRange](../mfc/reference/csliderctrl-class.md#getrange), [GetRangeMax](../mfc/reference/csliderctrl-class.md#getrangemax), e [GetRangeMin](../mfc/reference/csliderctrl-class.md#getrangemin) funções de membro.  
  
 Um aplicativo pode usar o `TBS_AUTOTICKS` estilo ter exibidas automaticamente as marcas de escala do controle deslizante. Se um aplicativo precisar controlar a posição ou a frequência das marcas de escala, no entanto, um número de funções de membro pode ser usado.  
  
 Para definir a posição de uma marca de escala, um aplicativo pode usar o [SetTic](../mfc/reference/csliderctrl-class.md#settic) função de membro. O [SetTicFreq](../mfc/reference/csliderctrl-class.md#setticfreq) função membro permite que um aplicativo definir marcas que aparecem em intervalos regulares no intervalo do controle deslizante de escala. Por exemplo, o aplicativo pode usar essa função de membro para exibir apenas 10 marcas de escala em um intervalo de 1 a 100.  
  
 Para recuperar o índice no intervalo correspondente a uma marca de escala, use o [GetTic](../mfc/reference/csliderctrl-class.md#gettic) função de membro. O [GetTicArray](../mfc/reference/csliderctrl-class.md#getticarray) função membro recupera uma matriz desses índices. Para recuperar a posição de uma marca de escala, nas coordenadas do cliente, use o [GetTicPos](../mfc/reference/csliderctrl-class.md#getticpos) função de membro. Um aplicativo pode recuperar o número de marcas de escala usando o [GetNumTics](../mfc/reference/csliderctrl-class.md#getnumtics) função de membro.  
  
 O [ClearTics](../mfc/reference/csliderctrl-class.md#cleartics) função membro remove todas as marcas de escala do controle deslizante.  
  
 Tamanho da linha do controle deslizante determina o quanto o controle deslizante se move quando um aplicativo recebe um **TB_LINEDOWN** ou **TB_LINEUP** mensagem de notificação. Da mesma forma, o tamanho da página determina a resposta para o **TB_PAGEDOWN** e **TB_PAGEUP** mensagens de notificação. Aplicativos podem recuperar e definir os valores de tamanho de linha e página usando o [GetLineSize](../mfc/reference/csliderctrl-class.md#getlinesize), [SetLineSize](../mfc/reference/csliderctrl-class.md#setlinesize), [GetPageSize](../mfc/reference/csliderctrl-class.md#getpagesize), e [SetPageSize](../mfc/reference/csliderctrl-class.md#setpagesize) funções de membro.  
  
 Um aplicativo pode usar funções de membro para recuperar as dimensões do controle deslizante. O [GetThumbRect](../mfc/reference/csliderctrl-class.md#getthumbrect) função membro recupera o retângulo delimitador para o controle deslizante. O [GetChannelRect](../mfc/reference/csliderctrl-class.md#getchannelrect) função membro recupera o retângulo delimitador do canal de controle deslizante. (O canal é a área em que o controle deslizante se move e que contém o realce quando um intervalo está selecionado.)  
  
 Se um controle deslizante tem o `TBS_ENABLESELRANGE` estilo, o usuário pode selecionar um intervalo de valores de contíguos dele. Um número de funções de membro permitem que o intervalo de seleção ser ajustado dinamicamente. O [SetSelection](../mfc/reference/csliderctrl-class.md#setselection) função membro define inicial e final posições de uma seleção. Quando o usuário termina de definir um intervalo de seleção, um aplicativo pode recuperar as configurações usando o [GetSelection](../mfc/reference/csliderctrl-class.md#getselection) função de membro. Para limpar a seleção do usuário, use o [ClearSel](../mfc/reference/csliderctrl-class.md#clearsel) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

