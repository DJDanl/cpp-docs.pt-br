---
title: Usando uma lista de imagens com um controle Rebar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- image lists [MFC], rebar controls
- rebar controls [MFC], image lists
ms.assetid: 1a5836ac-019a-46aa-8741-b35c3376b839
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1786c89f4ec9cf1c0908dac5d81858d5b2e6b7db
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36950700"
---
# <a name="using-an-image-list-with-a-rebar-control"></a>Usando uma lista de imagens com um controle rebar
Cada faixa rebar pode conter, entre outras coisas, uma imagem de uma lista de imagens associado. O procedimento a seguir detalha as etapas necessárias para exibir uma imagem em uma faixa de rebar.  
  
### <a name="to-display-images-in-a-rebar-band"></a>Para exibir imagens em uma faixa de rebar  
  
1.  Anexar uma lista de imagens para seu objeto de controle rebar fazendo uma chamada para [SetImageList](../mfc/reference/crebarctrl-class.md#setimagelist), transmitindo um ponteiro para uma lista de imagem existente.  
  
2.  Modificar o **REBARBANDINFO** estrutura para atribuir uma imagem a uma faixa de rebar:  
  
    -   Definir o *fMask* membro `RBBIM_IMAGE`, usando o operador OR bit a bit para incluir sinalizadores adicionais conforme necessário.  
  
    -   Definir o *iImage* membro para o índice de lista de imagem da imagem a ser exibida.  
  
3.  Inicialize quaisquer membros de dados restantes, como o tamanho, o texto e o identificador da janela filho independente, com as informações necessárias.  
  
4.  Insira a nova faixa (com a imagem) com uma chamada para [CReBarCtrl::InsertBand](../mfc/reference/crebarctrl-class.md#insertband), passando o **REBARBANDINFO** estrutura.  
  
 O exemplo a seguir supõe que um objeto de lista de imagem existente com duas imagens foi anexado ao objeto de controle rebar (`m_wndReBar`). Uma nova faixa de rebar (definido por `rbi`), que contém a primeira imagem, que é adicionado com uma chamada para `InsertBand`:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#28](../mfc/codesnippet/cpp/using-an-image-list-with-a-rebar-control_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

