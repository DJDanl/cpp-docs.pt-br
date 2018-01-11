---
title: Usando controles deslizantes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CSliderCtrl class [MFC], using
- slider controls
- slider controls [MFC], using
ms.assetid: 2b1a8ac8-2b17-41e1-aa24-83c1fd737049
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4fdab6a7fae25845da81ee7263e045e50951f557
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-slider-controls"></a>Usando controles de controle deslizante
Um uso típico de um controle deslizante segue o padrão abaixo:  
  
-   O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo, criação é automática quando a caixa de diálogo é criada. (Você deve ter uma [CSliderCtrl](../mfc/reference/csliderctrl-class.md) membro em sua classe de caixa de diálogo correspondente para o controle deslizante.) Como alternativa, você pode usar o [criar](../mfc/reference/csliderctrl-class.md#create) função de membro ao criar o controle como uma janela filho de qualquer janela.  
  
-   Chame várias funções de membro de conjunto para definir os valores para o controle. As alterações que você pode fazer incluem definindo as posições de mínimas e máxima para o controle deslizante, as marcas de escala de desenho, definindo um intervalo de seleção e reposicionar o controle deslizante. Para controles em uma caixa de diálogo, um bom momento para fazer isso é na caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) função.  
  
-   Como o usuário interage com o controle, ele envia várias mensagens de notificação. Você pode extrair o valor do controle deslizante de controle chamando o [GetPos](../mfc/reference/csliderctrl-class.md#getpos) função de membro.  
  
-   Quando tiver terminado com o controle, você precisa certificar-se de que ele será destruído corretamente. Se o controle deslizante está em uma caixa de diálogo, ele e o `CSliderCtrl` objeto será destruído automaticamente. Se não, você precisará garantir que ambos o controle e o `CSliderCtrl` objeto corretamente são destruídas.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSliderCtrl](../mfc/using-csliderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

