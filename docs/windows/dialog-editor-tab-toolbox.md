---
title: Guia do Editor de caixa de diálogo, caixa de ferramentas (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- Toolbox [C++], Dialog Editor tab
- controls [C++], types
- syslink controls in dialog boxes
- custom controls [C++], dialog boxes
- controls [C++], standard
- Dialog Editor [C++], creating controls
- controls [C++], adding to dialog boxes
ms.assetid: 253885c2-dcb9-4d8e-ac9b-805ea31cbf5e
ms.openlocfilehash: ee5ee95f22c9cbcbde1d6c8b9ba1646f979697a6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515226"
---
# <a name="dialog-editor-tab-toolbox-c"></a>Guia do Editor de caixa de diálogo, caixa de ferramentas (C++)

O **Editor de caixa de diálogo** guia é exibida na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) quando você estiver trabalhando no **caixa de diálogo** editor. Para adicionar controles à sua nova caixa de diálogo, arraste os controles do **caixa de ferramentas** à caixa de diálogo que você está criando (para obter mais informações, consulte [adicionando um controle a uma caixa de diálogo](adding-a-control-to-a-dialog-box.md)). Em seguida, você pode mover os controles ou alterar seu tamanho e forma.

Os controles padrão disponíveis na **caixa de ferramentas** são:

- [Controle de botão](../mfc/reference/cbutton-class.md)

- [Controle de caixa de seleção](../mfc/reference/styles-used-by-mfc.md#button-styles)

- [Controle de caixa de combinação](../mfc/reference/ccombobox-class.md)

- [Controle de edição](../mfc/reference/cedit-class.md)

- Caixa de grupo

- [Controle de caixa de listagem](../mfc/reference/clistbox-class.md)

- [Controle de botão de opção](../mfc/reference/styles-used-by-mfc.md#button-styles)

- [Controle de texto estático](../mfc/reference/cstatic-class.md)

- [Controle de imagem](../mfc/reference/cpictureholder-class.md)

- [Controle Rich Editar 2.0](../mfc/using-cricheditctrl.md)

- [Controle de barra de rolagem](../mfc/reference/cscrollbar-class.md)

O [controles comuns do Windows](../mfc/controls-mfc.md) disponível na **caixa de ferramentas** fornecer funcionalidade aumentada em seu aplicativo. Entre elas estão:

- [Controle deslizante](../mfc/slider-control-styles.md)

- [Controle de rotação](../mfc/using-cspinbuttonctrl.md)

- [Controle de progresso](../mfc/styles-for-the-progress-control.md)

- [Controle de tecla de acesso](../mfc/using-a-hot-key-control.md)

- [Controle de lista](../mfc/list-control-and-list-view.md)

- [Controle de árvore](../mfc/tree-control-styles.md)

- [Controle de guia](../mfc/tab-controls-and-property-sheets.md)

- [Controle de animação](../mfc/using-an-animation-control.md)

- [Controle de seletor de tempo de data](../mfc/creating-the-date-and-time-picker-control.md)

- [Controle de calendário mensal](../mfc/month-calendar-control-examples.md)

- [Controle de endereço IP](../mfc/reference/cipaddressctrl-class.md)

- [Controle de caixa de combinação estendido](../mfc/creating-an-extended-combo-box-control.md)

- [Controle personalizado](custom-controls-in-the-dialog-editor.md)

Você pode adicionar controles personalizados à caixa de diálogo, selecionando o **controle personalizado** ícone na **caixa de ferramentas** e arrastando-o para sua caixa de diálogo. Para adicionar um **Syslink** controlar, adicionar um controle personalizado e, em seguida, alterar o controle **classe** propriedade a ser **Syslink**. Isso fará com que as propriedades atualizar e mostrar o **Syslink** propriedades do controle. Para obter informações sobre a classe de wrapper do MFC, consulte [CLinkCtrl](../mfc/reference/clinkctrl-class.md).

Você também pode [adicionar controles ActiveX à sua caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

Você também pode personalizar o **caixa de ferramentas** janela para facilitar o uso. Para obter mais informações, consulte [Usando a caixa de ferramentas](/visualstudio/ide/using-the-toolbox).

Para obter mais informações sobre como usar o **RichEdit 1.0** controle com o MFC, consulte [usando o controle RichEdit 1.0 com MFC](../windows/using-the-richedit-1-0-control-with-mfc.md)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)<br/>
[Classes de controle](../mfc/control-classes.md)<br/>
[Classes da caixa de diálogo](../mfc/dialog-box-classes.md)<br/>
[Estilos de barra de rolagem](../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles)<br/>
[Exemplos de controle de edição avançada](../mfc/rich-edit-control-examples.md)<br/>
[Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)<br/>
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)