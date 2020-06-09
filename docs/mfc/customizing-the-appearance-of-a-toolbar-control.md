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
ms.openlocfilehash: ddccb5f05152d95377b430d7492ede3c86926e37
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619292"
---
# <a name="customizing-the-appearance-of-a-toolbar-control"></a>Personalizando a aparência de um controle de barra de ferramentas

A classe `CToolBarCtrl` fornece muitos estilos que afetam a aparência (e, ocasionalmente, o comportamento) do objeto Toolbar. Modifique o objeto Toolbar definindo o `dwCtrlStyle` parâmetro da `CToolBarCtrl::Create` função membro (ou `CToolBar::CreateEx` ), quando você criar o controle Toolbar pela primeira vez.

Os estilos a seguir afetam o aspecto "3D" dos botões da barra de ferramentas e o posicionamento do texto do botão:

- **TBSTYLE_FLAT** Cria uma barra de ferramentas simples onde a barra de ferramentas e os botões são transparentes. O texto do botão aparece em bitmaps de botão. Quando esse estilo é usado, o botão sob o cursor é realçado automaticamente.

- **TBSTYLE_TRANSPARENT** Cria uma barra de ferramentas transparente. Em uma barra de ferramentas transparente, a barra de ferramentas é transparente, mas os botões não são. O texto do botão aparece em bitmaps de botão.

- **TBSTYLE_LIST** Coloca o texto do botão à direita dos bitmaps de botão.

> [!NOTE]
> Para evitar problemas de repintura, os estilos de **TBSTYLE_FLAT** e de **TBSTYLE_TRANSPARENT** devem ser definidos antes de o objeto Toolbar ser visível.

Os seguintes estilos determinam se a barra de ferramentas permite que um usuário reposicione botões individuais dentro de um objeto Toolbar usando arrastar e soltar:

- **TBSTYLE_ALTDRAG** Permite que os usuários alterem a posição de um botão da barra de ferramentas arrastando-o enquanto mantém pressionada a tecla ALT. Se esse estilo não for especificado, o usuário deverá manter a tecla SHIFT pressionada ao arrastar um botão.

    > [!NOTE]
    >  O estilo de **CCS_ADJUSTABLE** deve ser especificado para permitir que os botões da barra de ferramentas sejam arrastados.

- **TBSTYLE_REGISTERDROP** Gera **TBN_GETOBJECT** mensagens de notificação para solicitar a remoção de objetos de destino quando o ponteiro do mouse passa sobre botões da barra de ferramentas.

Os estilos restantes afetam os aspectos visuais e não visuais do objeto Toolbar:

- **TBSTYLE_WRAPABLE** Cria uma barra de ferramentas que pode ter várias linhas de botões. Os botões da barra de ferramentas podem "encapsular" na próxima linha quando a barra de ferramentas se tornar muito estreita para incluir todos os botões na mesma linha. A disposição ocorre em limites de separação e não de grupo.

- **TBSTYLE_CUSTOMERASE** Gera **NM_CUSTOMDRAW** mensagens de notificação quando processa **WM_ERASEBKGND** mensagens.

- **TBSTYLE_TOOLTIPS** Cria um controle de dica de ferramenta que um aplicativo pode usar para exibir texto descritivo para os botões na barra de ferramentas.

Para obter uma lista completa de estilos de barra de ferramentas e estilos estendidos, consulte [controle da barra de ferramentas e](/windows/win32/Controls/toolbar-control-and-button-styles) estilos de botão e [estilos estendidos da barra de ferramentas](/windows/win32/Controls/toolbar-extended-styles) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](using-ctoolbarctrl.md)<br/>
[Controles](controls-mfc.md)
