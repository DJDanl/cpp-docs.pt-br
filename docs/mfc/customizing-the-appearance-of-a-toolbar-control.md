---
title: Personalizando a aparência de um controle de barra de ferramentas
ms.date: 11/04/2016
f1_keywords:
- TBSTYLE_
helpviewer_keywords:
- flat toolbars
- CToolBar class [MFC], styles
- transparent toolbars
- TBSTYLE_ styles [MFC]
- CToolBarCtrl class [MFC], object styles
- toolbar controls [MFC], style
ms.assetid: fd0a73db-7ad1-4fe4-889b-02c3980f49e8
ms.openlocfilehash: 9f4f9d90113d5074555d1b0cc411f854abc67fe5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377471"
---
# <a name="customizing-the-appearance-of-a-toolbar-control"></a>Personalizando a aparência de um controle de barra de ferramentas

A `CToolBarCtrl` classe fornece muitos estilos que afetam a aparência (e, ocasionalmente, o comportamento) do objeto da barra de ferramentas. Modifique o objeto da `dwCtrlStyle` barra de `CToolBarCtrl::Create` ferramentas `CToolBar::CreateEx`definindo o parâmetro da função (ou ) membro, quando você criar pela primeira vez o controle da barra de ferramentas.

Os seguintes estilos afetam o aspecto "3D" dos botões da barra de ferramentas e a colocação do texto do botão:

- **TBSTYLE_FLAT TBSTYLE_FLAT** Cria uma barra de ferramentas plana onde tanto a barra de ferramentas quanto os botões são transparentes. O texto do botão aparece em bitmaps de botão. Quando este estilo é usado, o botão abaixo do cursor é automaticamente destacado.

- **TBSTYLE_TRANSPARENT TBSTYLE_TRANSPARENT** Cria uma barra de ferramentas transparente. Em uma barra de ferramentas transparente, a barra de ferramentas é transparente, mas os botões não são. O texto do botão aparece em bitmaps de botão.

- **TBSTYLE_LIST** Coloca o texto do botão à direita dos bitmaps do botão.

> [!NOTE]
> Para evitar problemas de repintura, os estilos **TBSTYLE_FLAT** e **TBSTYLE_TRANSPARENT** devem ser definidos antes que o objeto da barra de ferramentas seja visível.

Os seguintes estilos determinam se a barra de ferramentas permite que um usuário reposicione botões individuais dentro de um objeto da barra de ferramentas usando arrastar e soltar:

- **TBSTYLE_ALTDRAG TBSTYLE_ALTDRAG** Permite que os usuários alterem a posição de um botão de barra de ferramentas arrastando-o enquanto seguram o ALT. Se este estilo não for especificado, o usuário deve segurar SHIFT enquanto arrasta um botão.

    > [!NOTE]
    >  O **estilo CCS_ADJUSTABLE** deve ser especificado para permitir que os botões da barra de ferramentas sejam arrastados.

- **TBSTYLE_REGISTERDROP** Gera **mensagens de** notificação TBN_GETOBJECT para solicitar objetos de destino de queda quando o ponteiro do mouse passa por cima dos botões da barra de ferramentas.

Os demais estilos afetam aspectos visuais e não visuais do objeto da barra de ferramentas:

- **TBSTYLE_WRAPABLE TBSTYLE_WRAPABLE.** Cria uma barra de ferramentas que pode ter várias linhas de botões. Os botões da barra de ferramentas podem "embrulhar" a próxima linha quando a barra de ferramentas ficar muito estreita para incluir todos os botões na mesma linha. O embrulho ocorre nos limites de separação e não-grupo.

- **TBSTYLE_CUSTOMERASE TBSTYLE_CUSTOMERASE** Gera **mensagens de** notificação NM_CUSTOMDRAW quando processa **mensagens WM_ERASEBKGND.**

- **TBSTYLE_TOOLTIPS** Cria um controle de ponta de ferramenta que um aplicativo pode usar para exibir texto descritivo para os botões na barra de ferramentas.

Para obter uma lista completa de estilos de barra de ferramentas e estilos estendidos, consulte [Controle de barra de ferramentas e estilos de botão](/windows/win32/Controls/toolbar-control-and-button-styles) e estilos [estendidos](/windows/win32/Controls/toolbar-extended-styles) da barra de ferramentas no SDK do Windows.

## <a name="see-also"></a>Confira também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
