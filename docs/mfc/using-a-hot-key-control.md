---
title: Usando um controle de tecla de acesso
ms.date: 11/04/2016
helpviewer_keywords:
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: cdd6524b-cc43-447f-b151-164273559685
ms.openlocfilehash: d9178fe989e476111a3da55861642e9aa6311872
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62180525"
---
# <a name="using-a-hot-key-control"></a>Usando um controle de tecla de acesso

Um uso típico de um controle de acesso de chave segue o padrão abaixo:

- O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo, a criação é automática quando a caixa de diálogo é criada. (Você deve ter uma [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md) membro em sua classe de caixa de diálogo que corresponde ao controle de chave de acesso.) Como alternativa, você pode usar o [criar](../mfc/reference/chotkeyctrl-class.md#create) função de membro para criar o controle como uma janela filho de qualquer janela.

- Se você quiser definir um valor padrão para o controle, chame o [SetHotKey](../mfc/reference/chotkeyctrl-class.md#sethotkey) função de membro. Se você deseja proibir determinados estados de deslocamento, chame [SetRules](../mfc/reference/chotkeyctrl-class.md#setrules). Para controles em uma caixa de diálogo, um bom momento para fazer isso é na caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) função.

- O usuário interage com o controle pressionando uma combinação de teclas de acesso quando o controle de chave de acesso tem o foco. O usuário, em seguida, alguma forma indica que a tarefa estiver concluída, talvez, clicando em um botão na caixa de diálogo.

- Quando seu programa é notificado de que o usuário selecionou uma tecla de acesso, ele deve usar a função de membro [GetHotKey](../mfc/reference/chotkeyctrl-class.md#gethotkey) para recuperar os valores de estado de chave- and -shift virtuais de controle de chave de acesso.

- Depois que você sabe o que o usuário selecionado da chave, você pode definir a tecla de acesso usando um dos métodos descritos em [definindo uma tecla de acesso](../mfc/setting-a-hot-key.md).

- Se o controle de chave de acesso está em uma caixa de diálogo, ele e o `CHotKeyCtrl` objeto será destruído automaticamente. Se não, você precisa garantir que os dois o controle e o `CHotKeyCtrl` objeto são destruídos corretamente.

## <a name="see-also"></a>Consulte também

[Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
