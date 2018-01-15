---
title: Criando um objeto CToolBarCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CToolBarCtrl
dev_langs: C++
helpviewer_keywords:
- toolbar controls [MFC], creating
- CToolBarCtrl class [MFC], creating toolbars
ms.assetid: a4f6bf0c-0195-4dbf-a09e-aee503e19dc3
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e86fad8191c4dea2eed3ae34ec96ed853ac1deae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-ctoolbarctrl-object"></a>Criando um objeto CToolBarCtrl
[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objetos contêm várias estruturas de dados internas, uma lista de bitmaps de imagem do botão, uma lista de cadeias de caracteres de rótulo de botão e uma lista de `TBBUTTON` estruturas — que associar uma imagem e/ou cadeia de caracteres com a posição, o estilo, o estado, e ID de comando do botão. Cada um dos elementos dessas estruturas de dados é chamada por um índice com base em zero. Antes de usar um `CToolBarCtrl` do objeto, você deve configurar essas estruturas de dados. Para obter uma lista das estruturas de dados, consulte [controles de barra de ferramentas](controls-mfc.md) no SDK do Windows. A lista de cadeias de caracteres só pode ser usada para rótulos de botão; Você não pode recuperar cadeias de caracteres na barra de ferramentas.  
  
 Para usar um `CToolBarCtrl` do objeto, normalmente você seguirá estas etapas:  
  
### <a name="to-use-a-ctoolbarctrl-object"></a>Para usar um objeto CToolBarCtrl  
  
1.  Construir o [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto.  
  
2.  Chamar [criar](../mfc/reference/ctoolbarctrl-class.md#create) para criar o controle comum de barra de ferramentas do Windows e anexá-lo para o `CToolBarCtrl` objeto. Imagens de bitmap para os botões, adicione os bitmaps de botão na barra de ferramentas chamando [AddBitmap](../mfc/reference/ctoolbarctrl-class.md#addbitmap). Se você desejar rótulos de cadeia de caracteres para os botões, adicionar as cadeias de caracteres na barra de ferramentas chamando [AddString](../mfc/reference/ctoolbarctrl-class.md#addstring) e/ou [AddStrings](../mfc/reference/ctoolbarctrl-class.md#addstrings). Depois de chamar `AddString` e/ou `AddStrings`, você deve chamar [AutoSize](../mfc/reference/ctoolbarctrl-class.md#autosize) para obter a cadeia de caracteres ou cadeias de caracteres seja exibido.  
  
3.  Adicionar estruturas de botão na barra de ferramentas chamando [AddButtons](../mfc/reference/ctoolbarctrl-class.md#addbuttons).  
  
4.  Se você desejar dicas de ferramenta, manipular **TTN_NEEDTEXT** mensagens na janela do proprietário da barra de ferramentas, conforme descrito em [tratamento notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md).  
  
5.  Se você desejar que o usuário seja capaz de personalizar a barra de ferramentas, lidar com mensagens de notificação de personalização na janela do proprietário conforme descrito em [manipulando notificações de personalização](../mfc/handling-customization-notifications.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

