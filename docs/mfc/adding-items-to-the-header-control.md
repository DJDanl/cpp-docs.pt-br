---
title: Adicionando itens ao controle de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [MFC], header
- CHeaderCtrl class [MFC], adding items
- header controls [MFC], adding items to
ms.assetid: 2e9a28b1-7302-4a93-8037-c5a4183e589a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a6450d99b8df436c64337e52fc14244ecbb0edfc
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43206141"
---
# <a name="adding-items-to-the-header-control"></a>Adicionando itens ao controle de cabeçalho
Depois de criar seu controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) em sua janela pai, adicione quantos "itens de cabeçalho" conforme necessário: normalmente, uma por coluna.  
  
### <a name="to-add-a-header-item"></a>Para adicionar um item de cabeçalho  
  
1.  Preparar uma [HD_ITEM](/windows/desktop/api/commctrl/ns-commctrl-_hd_itema) estrutura.  
  
2.  Chame [CHeaderCtrl::InsertItem](../mfc/reference/cheaderctrl-class.md#insertitem), passando a estrutura.  
  
3.  Repita as etapas 1 e 2 para itens adicionais.  
  
 Para obter mais informações, consulte [adicionando um Item a um controle de cabeçalho](/windows/desktop/Controls/header-controls) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

