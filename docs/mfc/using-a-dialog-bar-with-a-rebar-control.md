---
title: Usando uma caixa de diálogo com um controle Rebar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- WM_EX_TRANSPARENT
dev_langs:
- C++
helpviewer_keywords:
- WS_EX_TRANSPARENT style
- rebar controls [MFC], dialog bars
- dialog bars [MFC], using with rebar bands
ms.assetid: e528cea0-6b81-4bdf-9643-7c03b6176590
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 47894c14e3b3d694847f94e7f981c9397383e598
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33382900"
---
# <a name="using-a-dialog-bar-with-a-rebar-control"></a>Usando uma caixa de diálogo com um controle rebar
Conforme mencionado em [controles Rebar e bandas](../mfc/rebar-controls-and-bands.md), cada faixa pode conter apenas um filho janela (ou controle). Isso pode ser uma limitação se desejar ter mais de uma janela filho por faixa. É uma solução alternativa conveniente criar um recurso de barra da caixa de diálogo com vários controles e, em seguida, adicionar uma faixa de rebar (que contém a barra da caixa de diálogo) para o controle rebar.  
  
 Normalmente, se você quiser que a faixa de barra da caixa de diálogo aparecer transparente, configure o **WS_EX_TRANSPARENT** estendido para o objeto de barra da caixa de diálogo. No entanto, como **WS_EX_TRANSPARENT** tem alguns problemas com pintura corretamente o plano de fundo de uma barra da caixa de diálogo, você precisará fazer um pouco de trabalho extra para obter o efeito desejado.  
  
 O procedimento a seguir detalha as etapas necessárias para obter transparência sem usar o **WS_EX_TRANSPARENT** estilo estendido.  
  
### <a name="to-implement-a-transparent-dialog-bar-in-a-rebar-band"></a>Para implementar uma barra de caixa de diálogo transparente em uma faixa de rebar  
  
1.  Usando o [caixa de diálogo Adicionar classe](../mfc/reference/adding-an-mfc-class.md), adicione uma nova classe (por exemplo, `CMyDlgBar`) que implementa o objeto de barra da caixa de diálogo.  
  
2.  Adicionar um manipulador para o `WM_ERASEBKGND` mensagem.  
  
3.  No manipulador de novo, modifique o código existente para corresponder ao exemplo a seguir:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#29](../mfc/codesnippet/cpp/using-a-dialog-bar-with-a-rebar-control_1.cpp)]  
  
4.  Adicionar um manipulador para o `WM_MOVE` mensagem.  
  
5.  No manipulador de novo, modifique o código existente para corresponder ao exemplo a seguir:  
  
     [!code-cpp[NVC_MFCControlLadenDialog#30](../mfc/codesnippet/cpp/using-a-dialog-bar-with-a-rebar-control_2.cpp)]  
  
 Os manipuladores de novo simular a transparência da barra de caixa de diálogo por encaminhamento de `WM_ERASEBKGND` mensagem para a janela pai e forçar um redesenho toda vez que o objeto de barra da caixa de diálogo será movido.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

