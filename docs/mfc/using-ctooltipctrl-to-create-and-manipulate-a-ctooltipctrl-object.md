---
title: Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CToolTipCtrl
dev_langs:
- C++
helpviewer_keywords:
- tool tips [MFC], creating
- CToolTipCtrl class [MFC], using
ms.assetid: 0a34583f-f66d-46a1-a239-31b80ea395ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6f2143ea37cfe9448e43aacfa75622beab93d2fb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-ctooltipctrl-to-create-and-manipulate-a-ctooltipctrl-object"></a>Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl
Aqui está um exemplo de [CToolTipCtrl](../mfc/reference/ctooltipctrl-class.md) uso:  
  
### <a name="to-create-and-manipulate-a-ctooltipctrl"></a>Para criar e manipular um CToolTipCtrl  
  
1.  Construir o `CToolTipCtrl` objeto.  
  
2.  Chamar [criar](../mfc/reference/ctooltipctrl-class.md#create) para criar o controle comum de dica de ferramenta Windows e anexá-lo para o `CToolTipCtrl` objeto.  
  
3.  Chamar [AddTool](../mfc/reference/ctooltipctrl-class.md#addtool) para registrar uma ferramenta com o controle de dica de ferramenta, para que as informações armazenadas na dica de ferramenta são exibidas quando o cursor estiver sobre a ferramenta.  
  
4.  Chamar [SetToolInfo](../mfc/reference/ctooltipctrl-class.md#settoolinfo) para definir as informações que mantém uma dica de ferramenta para uma ferramenta.  
  
5.  Chamar [SetToolRect](../mfc/reference/ctooltipctrl-class.md#settoolrect) para definir um novo retângulo delimitador para uma ferramenta.  
  
6.  Chamar [HitTest](../mfc/reference/ctooltipctrl-class.md#hittest) para testar um ponto para determinar se ele está dentro do retângulo delimitador da ferramenta de determinada e, nesse caso, recuperar informações sobre a ferramenta.  
  
7.  Chamar [GetToolCount](../mfc/reference/ctooltipctrl-class.md#gettoolcount) recuperar uma contagem das ferramentas registrado com o controle de dica de ferramenta.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)

