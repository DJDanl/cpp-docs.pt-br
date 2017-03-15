---
title: "Fun&#231;&#245;es de membro de controle deslizante | Microsoft Docs"
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
  - "Classe CSliderCtrl, métodos"
  - "controles deslizantes, funções de membro"
ms.assetid: dbde49ee-7306-4d14-a6ce-d09aa198178f
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es de membro de controle deslizante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo pode chamar funções de membro de controle deslizante para recuperar informações sobre o controle deslizante[CSliderCtrl](../mfc/reference/csliderctrl-class.md)\(\) e modificar suas características.  
  
 Para recuperar a posição do controle deslizante \(isto é, o valor que o usuário optou\), use a função de membro de [GetPos](../Topic/CSliderCtrl::GetPos.md) .  Para definir a posição do controle deslizante, use a função de membro de [SetPos](../Topic/CSliderCtrl::SetPos.md) .  A qualquer momento você pode usar a função de membro de `VerifyPos` para garantir que o controle deslizante está entre os valores mínimo e máximo.  
  
 O intervalo de um controle deslizante é o conjunto de valores contíguas que o controle deslizante pode representar.  A maioria dos aplicativos usa a função de membro de [SetRange](../Topic/CSliderCtrl::SetRange.md) para definir o intervalo de um controle deslizante quando for criado.  Os aplicativos podem alterar dinamicamente o intervalo após o controle deslizante foram criados usando as funções de membro de [SetRangeMax](../Topic/CSliderCtrl::SetRangeMax.md) e de [SetRangeMin](../Topic/CSliderCtrl::SetRangeMin.md) .  Um aplicativo que permite que o intervalo seja alterado dinamicamente normalmente recupera as configurações final do intervalo quando o usuário foi concluída trabalhar com o controle deslizante.  Para recuperar essas configurações, use [GetRange](../Topic/CSliderCtrl::GetRange.md), [GetRangeMax](../Topic/CSliderCtrl::GetRangeMax.md), e as funções de membro de [GetRangeMin](../Topic/CSliderCtrl::GetRangeMin.md) .  
  
 Um aplicativo pode usar o estilo de `TBS_AUTOTICKS` para que as marcas de escala de um controle deslizante exibidas automaticamente.  Se um aplicativo precisar controlar a posição ou frequência das marcas de escala, porém, um número de funções de membro podem ser usadas.  
  
 Para definir a posição da marca de escala, um aplicativo pode usar a função de membro de [SetTic](../Topic/CSliderCtrl::SetTic.md) .  A função de membro de [SetTicFreq](../Topic/CSliderCtrl::SetTicFreq.md) permite que um aplicativo defina as marcas de escala que aparece em intervalos regulares para o intervalo de controle deslizante.  Por exemplo, o aplicativo pode usar essa função de membro para exibir apenas 10 marcas de escala em um intervalo de 1 a 100.  
  
 Para recuperar o índice no intervalo que corresponde a uma marca de escala, use a função de membro de [GetTic](../Topic/CSliderCtrl::GetTic.md) .  A função de membro de [GetTicArray](../Topic/CSliderCtrl::GetTicArray.md) recupera uma matriz desses índices.  Para recuperar a posição da marca de escala, nas coordenadas do cliente, use a função de membro de [GetTicPos](../Topic/CSliderCtrl::GetTicPos.md) .  Um aplicativo pode recuperar o número de marcas de escala usando a função de membro de [GetNumTics](../Topic/CSliderCtrl::GetNumTics.md) .  
  
 A função de membro de [ClearTics](../Topic/CSliderCtrl::ClearTics.md) remove todas as marcas de escala de um controle deslizante.  
  
 Uma linha de controle deslizante tamanho determina como a distância do controle deslizante se move quando um aplicativo recebe uma notificação de **TB\_LINEDOWN** ou de **TB\_LINEUP** .  Da mesma forma, o tamanho da página determina a resposta às notificações de **TB\_PAGEDOWN** e de **TB\_PAGEUP** .  Os aplicativos podem recuperar e definir valores de linha e do tamanho da página usando [GetLineSize](../Topic/CSliderCtrl::GetLineSize.md), [SetLineSize](../Topic/CSliderCtrl::SetLineSize.md), [GetPageSize](../Topic/CSliderCtrl::GetPageSize.md), e as funções de membro de [SetPageSize](../Topic/CSliderCtrl::SetPageSize.md) .  
  
 Um aplicativo pode usar as funções de membro para recuperar as dimensões de um controle deslizante.  A função de membro de [GetThumbRect](../Topic/CSliderCtrl::GetThumbRect.md) recupera o retângulo delimitador para o controle deslizante.  A função de membro de [GetChannelRect](../Topic/CSliderCtrl::GetChannelRect.md) recupera o retângulo delimitador para o canal de controle deslizante. \(O canal é a área na qual o controle deslizante se movimenta e que contém o realce quando um intervalo seja selecionado.\)  
  
 Se um controle deslizante tem o estilo de `TBS_ENABLESELRANGE` , o usuário pode selecionar um intervalo de valores contíguas deles.  Várias funções de membro permitem que o intervalo de seleção é definido dinamicamente.  A função de membro de [SetSelection](../Topic/CSliderCtrl::SetSelection.md) define as posições de início e término de uma seleção.  Quando o usuário foi concluída definir um intervalo de seleção, um aplicativo pode recuperar as configurações usando a função de membro de [GetSelection](../Topic/CSliderCtrl::GetSelection.md) .  Para desmarcar a seleção de um usuário, use a função de membro de [ClearSel](../Topic/CSliderCtrl::ClearSel.md) .  
  
## Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)