---
title: Guias e guia atributos de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- attributes [MFC], reference topics
- tab controls [MFC], attributes
- tabs [MFC]
- tabs [MFC], attributes
- CTabCtrl class [MFC], tab control attributes
ms.assetid: ecf190cb-f323-4751-bfdb-766dbe6bb553
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f925f8b6a5c522e22890ee2c1082ae8d709d2220
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381187"
---
# <a name="tabs-and-tab-control-attributes"></a>Guias e atributos de controle da guia
Você tem controle considerável sobre a aparência e comportamento de guias que compõem um controle de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)). Cada guia pode ter um rótulo, um ícone, um estado de item e um valor de 32 bits definido pelo aplicativo associado a ele. Para cada guia, você pode exibir o ícone, o rótulo ou ambos.  
  
 Além disso, cada item de guia pode ter três estados possíveis: pressionado, não pressionado ou realçado. Esse estado somente pode ser definido por meio de modificação de um item de guia existente. Para modificar um item de guia existente, recuperá-lo com uma chamada para [GetItem](../mfc/reference/ctabctrl-class.md#getitem), modifique o `TCITEM` estrutura (especificamente o **dwState** e **dwStateMask** membros de dados ) e, em seguida, retornar o `TCITEM` estrutura com uma chamada para [SetItem](../mfc/reference/ctabctrl-class.md#setitem). Se você precisa limpar os estados de item de todos os itens na guia um `CTabCtrl` de objeto, fazer uma chamada para [DeselectAll](../mfc/reference/ctabctrl-class.md#deselectall). Essa função redefine o estado de todos os itens de guia ou todos os itens, exceto a selecionada no momento.  
  
 O código a seguir limpa o estado de todos os itens de guia e, em seguida, modifica o estado do item de terceiro:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#32](../mfc/codesnippet/cpp/tabs-and-tab-control-attributes_1.cpp)]  
  
 Para obter mais informações sobre atributos de guia, consulte [guias e atributos guia](http://msdn.microsoft.com/library/windows/desktop/bb760550) no SDK do Windows. Para obter mais informações sobre como adicionar guias a um controle guia, consulte [adicionando guias a um controle guia](../mfc/adding-tabs-to-a-tab-control.md) mais adiante neste tópico.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTabCtrl](../mfc/using-ctabctrl.md)   
 [Controles](../mfc/controls-mfc.md)

