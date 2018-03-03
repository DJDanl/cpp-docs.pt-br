---
title: Usando um controle de chave de acesso | Microsoft Docs
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
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: cdd6524b-cc43-447f-b151-164273559685
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0a64de06d5bc499d5b566d6d40508d08e920264
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-a-hot-key-control"></a>Usando um controle de tecla de acesso
Um uso típico de um controle de chave de acesso segue o padrão abaixo:  
  
-   O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo, criação é automática quando a caixa de diálogo é criada. (Você deve ter uma [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md) membro em sua classe de caixa de diálogo correspondente para o controle de chave de acesso.) Como alternativa, você pode usar o [criar](../mfc/reference/chotkeyctrl-class.md#create) função de membro ao criar o controle como uma janela filho de qualquer janela.  
  
-   Se você quiser definir um valor padrão para o controle, chame o [SetHotKey](../mfc/reference/chotkeyctrl-class.md#sethotkey) função de membro. Se você deseja proibir determinados estados de shift, chame [SetRules](../mfc/reference/chotkeyctrl-class.md#setrules). Para controles em uma caixa de diálogo, um bom momento para fazer isso é na caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) função.  
  
-   O usuário interage com o controle pressionando uma combinação de teclas de acesso quando o controle de chave de acesso tem foco. O usuário, em seguida, alguma forma indica que a tarefa estiver concluída, talvez, clicando em um botão na caixa de diálogo.  
  
-   Quando o programa é notificado que o usuário selecionou uma tecla de acesso, ele deve usar a função de membro [GetHotKey](../mfc/reference/chotkeyctrl-class.md#gethotkey) para recuperar os valores de estado de chave e shift virtuais de controle de chave de acesso.  
  
-   Depois que você sabe o que o usuário selecionado de chave, você pode definir a tecla de acesso usando um dos métodos descritos no [definindo uma tecla de acesso](../mfc/setting-a-hot-key.md).  
  
-   Se o controle de chave de acesso está em uma caixa de diálogo, ele e o `CHotKeyCtrl` objeto será destruído automaticamente. Se não, você precisará garantir que ambos o controle e o `CHotKeyCtrl` objeto corretamente são destruídas.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

