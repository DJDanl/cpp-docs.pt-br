---
title: Itens de retorno de chamada e a máscara de retorno de chamada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- callback items in CListCtrl class [MFC]
- CListCtrl class [MFC], callback item and callback mask
ms.assetid: 67c1f76f-6144-453e-9376-6712f89430ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 95c896308970ffc6a2040657927dc127eee278ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342768"
---
# <a name="callback-items-and-the-callback-mask"></a>Itens e máscara de retorno de chamada
Para cada um de seus itens, um controle de exibição de lista geralmente armazena o texto do rótulo, o índice de lista de imagem dos ícones do item, e um conjunto de bits sinaliza para o estado do item. Você pode definir os itens individuais como itens de retorno de chamada, que são úteis se seu aplicativo já armazena algumas informações de um item.  
  
 Definir um item como um item de retorno de chamada, especificando os valores apropriados para o `pszText` e `iImage` membros a **LV_ITEM** estrutura (consulte [CListCtrl::GetItem](../mfc/reference/clistctrl-class.md#getitem)). Se o aplicativo mantiver o texto do item ou do subitem, especifique o **LPSTR_TEXTCALLBACK** valor para o `pszText` membro. Se o aplicativo mantém controle sobre o ícone do item, especifique o **I_IMAGECALLBACK** valor para o `iImage` membro.  
  
 Além de definir os itens de retorno de chamada, você também pode modificar a máscara de retorno de chamada do controle. Esta máscara é um conjunto de sinalizadores de bit que especificam os estados de item para o qual o aplicativo, em vez de controle, armazena os dados atuais. A máscara de retorno de chamada se aplica a todos os itens do controle, ao contrário a designação de item de retorno de chamada, que se aplica a um item específico. A máscara de retorno de chamada é zero por padrão, o que significa que o controle rastreia todos os estados de item. Para alterar esse comportamento padrão, inicialize a máscara de qualquer combinação dos valores a seguir:  
  
-   `LVIS_CUT` O item está marcado para uma operação recortar e colar.  
  
-   `LVIS_DROPHILITED` O item é realçado como um destino de arrastar e soltar.  
  
-   `LVIS_FOCUSED` O item tem o foco.  
  
-   `LVIS_SELECTED` O item é selecionado.  
  
-   **LVIS_OVERLAYMASK** o aplicativo armazena o índice de lista de imagem da imagem de sobreposição atual para cada item.  
  
-   **LVIS_STATEIMAGEMASK** o aplicativo armazena o índice de lista de imagem da imagem do estado atual de cada item.  
  
 Para obter mais informações sobre como recuperar e definir essa máscara, consulte [CListCtrl::GetCallbackMask](../mfc/reference/clistctrl-class.md#getcallbackmask) e [CListCtrl::SetCallbackMask](../mfc/reference/clistctrl-class.md#setcallbackmask).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

