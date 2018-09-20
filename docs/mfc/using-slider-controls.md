---
title: Usando controles deslizantes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CSliderCtrl class [MFC], using
- slider controls
- slider controls [MFC], using
ms.assetid: 2b1a8ac8-2b17-41e1-aa24-83c1fd737049
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d0496a15b289ec055fd2706975603f25cef13938
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388830"
---
# <a name="using-slider-controls"></a>Usando controles de controle deslizante

Um uso típico de um controle deslizante segue o padrão abaixo:

- O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo, a criação é automática quando a caixa de diálogo é criada. (Você deve ter uma [CSliderCtrl](../mfc/reference/csliderctrl-class.md) membro em sua classe de caixa de diálogo que corresponde ao controle deslizante.) Como alternativa, você pode usar o [criar](../mfc/reference/csliderctrl-class.md#create) função de membro para criar o controle como uma janela filho de qualquer janela.

- Chame várias funções de membro de conjunto para definir valores para o controle. As alterações que você pode fazer incluem definindo as posições de mínimas e máxima para o controle deslizante, as marcas de escala de desenho, definindo um intervalo de seleção e reposicionar o controle deslizante. Para controles em uma caixa de diálogo, um bom momento para fazer isso é na caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) função.

- Conforme o usuário interage com o controle, ele envia várias mensagens de notificação. Você pode extrair o valor do controle deslizante de controle, chamando o [GetPos](../mfc/reference/csliderctrl-class.md#getpos) função de membro.

- Quando você terminar com o controle, você precisa certificar-se de que ele é destruído corretamente. Se o controle deslizante está em uma caixa de diálogo, ele e o `CSliderCtrl` objeto será destruído automaticamente. Se não, você precisa garantir que os dois o controle e o `CSliderCtrl` objeto são destruídos corretamente.

## <a name="see-also"></a>Consulte também

[Usando CSliderCtrl](../mfc/using-csliderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

