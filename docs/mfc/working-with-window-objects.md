---
title: Trabalhando com objetos de janela | Microsoft Docs
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
- child windows [MFC], working with
- window objects [MFC], working with
ms.assetid: f73aa254-90e3-46a9-8e9b-d78b7054a331
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1eb8622c18a9b9539388ad2b3162916288cb28af
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="working-with-window-objects"></a>Trabalhando com objetos de janela
Trabalhando com chamadas de windows para dois tipos de atividade:  
  
-   Tratamento de mensagens do Windows  
  
-   Na janela de desenho  
  
 Para lidar com mensagens do Windows em qualquer janela, incluindo suas próprias janelas filho, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md) para mapear as mensagens para sua classe de janela C++. Em seguida, grave manipulador de mensagem de funções de membro em sua classe.  
  
 Desenhando a maioria em um aplicativo do framework ocorre no modo de exibição, cujo [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro é chamada sempre que o conteúdo da janela deve ser desenhado. Se a janela é um filho do modo de exibição, você pode delegar algumas das desenho do modo de exibição para a janela filho tendo `OnDraw` chame uma das funções de membro da janela.  
  
 Em qualquer caso, você precisará de um contexto de dispositivo para o desenho. Você pode usar a caneta de estoque, Pincel e outros objetos gráficos contidos no contexto de dispositivo associado a janela. Ou você pode modificar esses objetos para obter os efeitos de desenho que é necessário. Com o contexto de dispositivo configurado conforme desejar, chame membro funções da classe [CDC](../mfc/reference/cdc-class.md) (classe de contexto de dispositivo) para desenhar linhas, formas e texto; para usar cores; e para trabalhar com um sistema de coordenadas.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Mapeamento e a manipulação de mensagens](../mfc/message-handling-and-mapping.md)  
  
-   [Desenhando uma exibição](../mfc/drawing-in-a-view.md)  
  
-   [Contextos de dispositivo](../mfc/device-contexts.md)  
  
-   [Objetos gráficos](../mfc/graphic-objects.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

