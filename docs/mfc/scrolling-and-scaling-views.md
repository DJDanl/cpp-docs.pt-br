---
title: "Rolando e colocando exibições em escala | Microsoft Docs"
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
- message handlers [MFC]
- scaling views [MFC]
- message handling [MFC], scroll bars in view class [MFC]
- scroll bars [MFC], messages
- scrolling views [MFC]
ms.assetid: f98a3421-c336-407e-97ee-dbb2ffd76fbd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f8bd42a7da91f984c4cedc4deafc0ab9f4417495
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="scrolling-and-scaling-views"></a>Rolando e colocando exibições em escala
MFC oferece suporte a modos de exibição que rolagem e modos de exibição que são dimensionados automaticamente para o tamanho da janela do quadro que exibe-os. Classe `CScrollView` oferece suporte a ambos os tipos de modos de exibição.  
  
 Para obter mais informações sobre a rolagem e o dimensionamento, consulte a classe [CScrollView](../mfc/reference/cscrollview-class.md) no *referência MFC*. Para obter um exemplo de rolagem, consulte o [Rabisco exemplo](../visual-cpp-samples.md).  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   Um modo de exibição de rolagem  
  
-   Dimensionamento de um modo de exibição  
  
-   [Coordenadas do modo de exibição](http://msdn.microsoft.com/library/windows/desktop/dd145205)  
  
##  <a name="_core_scrolling_a_view"></a>Um modo de exibição de rolagem  
 Frequentemente, o tamanho de um documento é maior que o tamanho de que seu modo de exibição pode exibir. Isso pode ocorrer porque os dados do documento aumenta ou o usuário reduz a janela que o modo de exibição de quadros. Nesses casos, o modo de exibição deve oferecer suporte a rolagem.  
  
 Qualquer modo de exibição pode lidar com mensagens da barra de rolagem no seu `OnHScroll` e `OnVScroll` funções de membro. Lidando com barra de rolagem ou implementar essas funções, poderá fazer todo o trabalho por conta própria, ou você pode usar o `CScrollView` classe para manipular a rolagem para você.  
  
 `CScrollView`faz o seguinte:  
  
-   Gerencia os tamanhos de janela e visor e modos de mapeamento  
  
-   Rola automaticamente em resposta a mensagens da barra de rolagem  
  
 Você pode especificar quanto para rolar para uma "página" (quando o usuário clica em um eixo de barra de rolagem) e "linha" (quando o usuário clica em uma seta de rolagem). Planeje esses valores de acordo com a natureza do modo de exibição. Por exemplo, você talvez queira Role em incrementos de 1 pixel para uma exibição de gráficos, mas em incrementos com base na altura da linha em documentos de texto.  
  
##  <a name="_core_scaling_a_view"></a>Dimensionamento de um modo de exibição  
 Quando você deseja que a exibição para ajustar automaticamente o tamanho da sua janela do quadro, você pode usar `CScrollView` para dimensionamento, em vez de rolagem. O modo de exibição lógico é ampliado ou reduzido para se ajustar a área cliente da janela exatamente. Uma exibição expandida tem sem barras de rolagem.  
  
## <a name="see-also"></a>Consulte também  
 [Usando exibições](../mfc/using-views.md)

