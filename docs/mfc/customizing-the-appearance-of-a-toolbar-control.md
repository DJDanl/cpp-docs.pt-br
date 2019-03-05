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
ms.openlocfilehash: 8a0db3299ebb54d226edc1434dedbc6a04eb9b00
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302332"
---
# <a name="customizing-the-appearance-of-a-toolbar-control"></a>Personalizando a aparência de um controle de barra de ferramentas

Classe `CToolBarCtrl` fornece vários estilos que afetam a aparência (e, ocasionalmente, o comportamento) do objeto da barra de ferramentas. Modificar o objeto de barra de ferramentas, definindo o `dwCtrlStyle` parâmetro do `CToolBarCtrl::Create` (ou `CToolBar::CreateEx`) função membro, quando você cria o controle de barra de ferramentas.

Os estilos a seguir afetam o aspecto "3D" dos botões da barra de ferramentas e o posicionamento do texto do botão:

- **TBSTYLE_FLAT** cria uma barra de ferramentas simples em que a barra de ferramentas e os botões são transparentes. Texto do botão aparece sob os bitmaps de botão. Quando esse estilo é usado, o botão embaixo do cursor será realçado automaticamente.

- **TBSTYLE_TRANSPARENT** cria uma barra de ferramentas transparente. Em uma barra de ferramentas transparente, a barra de ferramentas é transparente, mas os botões não são. Texto do botão aparece sob os bitmaps de botão.

- **TBSTYLE_LIST** locais de texto à direita do botão bitmaps de botão.

> [!NOTE]
>  Para evitar problemas de repintura, o **TBSTYLE_FLAT** e **TBSTYLE_TRANSPARENT** estilos devem ser definidos antes do objeto de barra de ferramentas está visível.

Os seguintes estilos de determinam se a barra de ferramentas permite que um usuário reposicionar botões individuais dentro de um objeto de barra de ferramentas usando arrastar e soltar:

- **TBSTYLE_ALTDRAG** permite que os usuários alterar a posição de um botão barra de ferramentas, arrastando-o enquanto mantém pressionada a tecla ALT. Se esse estilo não for especificado, o usuário deve manter pressionada a tecla SHIFT enquanto arrasta um botão.

    > [!NOTE]
    >  O **CCS_ADJUSTABLE** estilo deve ser especificado para habilitar os botões de barra de ferramentas a ser arrastado.

- **TBSTYLE_REGISTERDROP** gera **TBN_GETOBJECT** notificação mensagens para solicitar descartar objetos de destino quando o ponteiro do mouse passa sobre botões de barra de ferramentas.

Os estilos restantes afetam os aspectos visuais e do objeto da barra de ferramentas:

- **TBSTYLE_WRAPABLE** cria uma barra de ferramentas que pode ter várias linhas de botões. Botões da barra de ferramentas podem "encapsular" para a próxima linha quando a barra de ferramentas se torna muito estreita para incluir todos os botões na mesma linha. Quebra automática ocorre em limites nongroup e separação.

- **TBSTYLE_CUSTOMERASE** gera **NM_CUSTOMDRAW** quando ele processa as mensagens de notificação **WM_ERASEBKGND** mensagens.

- **TBSTYLE_TOOLTIPS** cria um controle de dica de ferramenta que um aplicativo pode usar para exibir o texto descritivo para os botões na barra de ferramentas.

Para obter uma listagem completa dos estilos de barra de ferramentas e os estilos estendidos, consulte [estilos de botão e controle de barra de ferramentas](/windows/desktop/Controls/toolbar-control-and-button-styles) e [estilos estendidos da barra de ferramentas](/windows/desktop/Controls/toolbar-extended-styles) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
