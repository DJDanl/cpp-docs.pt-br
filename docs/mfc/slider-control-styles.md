---
title: Estilos de controle deslizante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- slider controls [MFC], styles
- CSliderCtrl class [MFC], styles
- styles [MFC], CSliderCtrl
- styles [MFC], slider controls
ms.assetid: 64c491fc-5af1-4f97-ae30-854071b3dc02
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f76fbe9f85d978a5c2865b48720588b620508a07
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951046"
---
# <a name="slider-control-styles"></a>Estilos de controle de controle deslizante
Controles deslizantes ([CSliderCtrl](../mfc/reference/csliderctrl-class.md)) pode ter uma orientação vertical ou horizontal. Eles podem ter marcas de escala em ambos os lados, ambos os lados, ou nenhum. Eles também podem ser usados para especificar um intervalo de valores consecutivos. Essas propriedades são controladas usando estilos de controle deslizante, que você especifica ao criar o controle deslizante.  
  
 Os estilos TBS_HORZ e TBS_VERT determinam a orientação do controle deslizante. Se você não especificar uma orientação, o controle deslizante é orientado horizontal.  
  
 O estilo TBS_AUTOTICKS cria um controle deslizante que tem uma marca de escala para cada incremento em seu intervalo de valores. Essas marcas de escala são adicionadas automaticamente quando você chama o [SetRange](../mfc/reference/csliderctrl-class.md#setrange) função de membro. Se você não especificar TBS_AUTOTICKS, você pode usar funções de membro, como [SetTic](../mfc/reference/csliderctrl-class.md#settic) e [SetTicFreq](../mfc/reference/csliderctrl-class.md#setticfreq), para especificar as posições das marcas de escala. Para criar um controle deslizante que não são exibidas as marcas de escala, você pode usar o estilo TBS_NOTICKS.  
  
 Você pode exibir as marcas de escala em um ou ambos os lados do controle deslizante. Para controles de controle deslizante horizontal, você pode especificar o estilo TBS_BOTTOM ou TBS_TOP. Para controles do slider vertical, você pode especificar o estilo TBS_RIGHT ou TBS_LEFT. (TBS_BOTTOM e TBS_RIGHT são as configurações padrão.) Para as marcas de escala em ambos os lados do controle deslizante em qualquer orientação, especifique o estilo TBS_BOTH.  
  
 Um controle deslizante pode exibir um intervalo de seleção somente se você especificar o estilo TBS_ENABLESELRANGE ao criá-lo. Quando um controle deslizante tem esse estilo, as marcas de escala nas posições iniciais e final de um intervalo de seleção são exibidas como triângulos (em vez de traços verticais) e o intervalo selecionado é realçado. Por exemplo, os intervalos de seleção podem ser útil em um aplicativo simple de agendamento. O usuário pode selecionar um intervalo de marcas de escala correspondente para horas em um dia para identificar um horário agendado.  
  
 Por padrão, o comprimento do controle deslizante de um controle deslizante varia de acordo com as alterações de intervalo de seleção. Se o controle deslizante tem o estilo TBS_FIXEDLENGTH, o comprimento do controle deslizante permanece o mesmo mesmo se o intervalo de seleção é alterado. Um controle deslizante que tenha o estilo TBS_NOTHUMB não inclui um controle deslizante.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

