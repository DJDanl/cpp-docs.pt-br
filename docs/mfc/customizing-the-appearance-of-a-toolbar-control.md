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
ms.openlocfilehash: 590f0dce6c50ee6d0ca30c4c68e21787563bd686
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508733"
---
# <a name="customizing-the-appearance-of-a-toolbar-control"></a>Personalizando a aparência de um controle de barra de ferramentas

A `CToolBarCtrl` classe fornece muitos estilos que afetam a aparência (e, ocasionalmente, o comportamento) do objeto Toolbar. Modifique o objeto Toolbar definindo o `dwCtrlStyle` parâmetro `CToolBarCtrl::Create` da função membro (ou `CToolBar::CreateEx`), quando você criar o controle Toolbar pela primeira vez.

Os estilos a seguir afetam o aspecto "3D" dos botões da barra de ferramentas e o posicionamento do texto do botão:

- **TBSTYLE_FLAT** Cria uma barra de ferramentas simples onde a barra de ferramentas e os botões são transparentes. O texto do botão aparece em bitmaps de botão. Quando esse estilo é usado, o botão sob o cursor é realçado automaticamente.

- **TBSTYLE_TRANSPARENT** Cria uma barra de ferramentas transparente. Em uma barra de ferramentas transparente, a barra de ferramentas é transparente, mas os botões não são. O texto do botão aparece em bitmaps de botão.

- **TBSTYLE_LIST** Coloca o texto do botão à direita dos bitmaps de botão.

> [!NOTE]
>  Para evitar problemas de repintura, os estilos **TBSTYLE_FLAT** e **TBSTYLE_TRANSPARENT** devem ser definidos antes de o objeto Toolbar ser visível.

Os seguintes estilos determinam se a barra de ferramentas permite que um usuário reposicione botões individuais dentro de um objeto Toolbar usando arrastar e soltar:

- **TBSTYLE_ALTDRAG** Permite que os usuários alterem a posição de um botão da barra de ferramentas arrastando-o enquanto mantém pressionada a tecla ALT. Se esse estilo não for especificado, o usuário deverá manter a tecla SHIFT pressionada ao arrastar um botão.

    > [!NOTE]
    >  O estilo **CCS_ADJUSTABLE** deve ser especificado para permitir que os botões da barra de ferramentas sejam arrastados.

- **TBSTYLE_REGISTERDROP** Gera mensagens de notificação **TBN_GETOBJECT** para solicitar a remoção de objetos de destino quando o ponteiro do mouse passa sobre botões da barra de ferramentas.

Os estilos restantes afetam os aspectos visuais e não visuais do objeto Toolbar:

- **TBSTYLE_WRAPABLE** Cria uma barra de ferramentas que pode ter várias linhas de botões. Os botões da barra de ferramentas podem "encapsular" na próxima linha quando a barra de ferramentas se tornar muito estreita para incluir todos os botões na mesma linha. A disposição ocorre em limites de separação e não de grupo.

- **TBSTYLE_CUSTOMERASE** Gera mensagens de notificação **NM_CUSTOMDRAW** quando processa mensagens **WM_ERASEBKGND** .

- **TBSTYLE_TOOLTIPS** Cria um controle de dica de ferramenta que um aplicativo pode usar para exibir texto descritivo para os botões na barra de ferramentas.

Para obter uma lista completa de estilos de barra de ferramentas e estilos estendidos, consulte [controle da barra de ferramentas e](/windows/win32/Controls/toolbar-control-and-button-styles) estilos de botão e [estilos estendidos da barra de ferramentas](/windows/win32/Controls/toolbar-extended-styles) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
