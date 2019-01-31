---
title: Adicionando um controle a uma caixa de diálogo (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.dialog.dialog
helpviewer_keywords:
- dialog boxes [C++], adding controls to
- Toolbox [C++], Dialog Editor tab
- controls [C++], types
- syslink controls in dialog boxes
- custom controls [C++], dialog boxes
- controls [C++], standard
- Dialog Editor [C++], creating controls
- controls [C++], adding to dialog boxes
- controls [C++], adding multiple
- dialog box controls [C++], size
- controls [C++], sizing
ms.assetid: b2a26d19-093f-49ca-93da-fef00dfbb381
ms.openlocfilehash: 92b644769bcbe2649d00ba68437bd474ee06dfcc
ms.sourcegitcommit: b488462a6e035131121e6f32d8f3b108cc798b5e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/30/2019
ms.locfileid: "55293618"
---
# <a name="adding-a-control-to-a-dialog-box-c"></a>Adicionando um controle a uma caixa de diálogo (C++)

O **Editor de caixa de diálogo** guia é exibida na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) quando você estiver trabalhando no **caixa de diálogo** editor. Para adicionar controles à sua nova caixa de diálogo, arraste os controles do **caixa de ferramentas** à caixa de diálogo que você está criando. Em seguida, você pode mover os controles ou alterar seu tamanho e forma.

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

## <a name="to-add-a-control-to-a-dialog-box"></a>Para adicionar um controle a uma caixa de diálogo

1. Certifique-se de que a janela com guias da caixa de diálogo é o documento atual no quadro do editor. Se uma caixa de diálogo não for o documento atual, você não verá os **guia do Editor de caixa de diálogo** na **caixa de ferramentas**.

1. No **Editor de caixa de diálogo** guia da [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o controle, em seguida, você deseja:

   - Marque a caixa de diálogo no local onde você deseja colocar o controle. O controle aparece em que você selecionou.

       \- ou -

   - Arraste e solte o controle a partir de **caixa de ferramentas** janela para o local em sua caixa de diálogo.

       \- ou -

   - Clique duas vezes no controle na **caixa de ferramentas** janela (ele é exibido na caixa de diálogo), em seguida, reposicionar o controle para o local de sua preferência.

## <a name="to-add-multiple-controls"></a>Para adicionar vários controles

1. Enquanto mantém pressionada a **Ctrl** da chave, selecione um controle na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox).

1. Versão do **Ctrl** da chave e marque a caixa de diálogo quantas vezes você deseja adicionar o controle específico.

1. Pressione **Esc** para interromper a colocação de controles.

## <a name="to-size-a-control-while-you-add-it"></a>Para dimensionar um controle enquanto você adicioná-lo

1. Selecione um controle na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox).

1. Coloque o cursor (que aparece como cruzada cruzes) onde você deseja que o canto superior esquerdo do novo controle esteja em sua caixa de diálogo.

1. Selecione e mantenha pressionado o botão do mouse para o canto superior esquerdo do seu controle na caixa de diálogo de ancoragem e arraste o cursor para a direita e para baixo até que o controle é o tamanho desejado.

   > [!NOTE]
   > Na verdade, é possível ancorar qualquer um dos quatro cantos do controle que está sendo desenhado. Esse procedimento usado no canto superior esquerdo como um exemplo.

1. Solte o botão do mouse. O controle liquida para a caixa de diálogo pelo tamanho especificado.

   > [!TIP]
   > Você pode redimensionar o controle após arrastando-o para a caixa de diálogo, movendo as alças de dimensionamento na borda do controle. Para obter mais informações, consulte [controles individuais do dimensionamento](../windows/sizing-individual-controls.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)<br/>
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)<br/>
[Controles](../mfc/controls-mfc.md)<br/>
[Classes de controle](../mfc/control-classes.md)<br/>
[Classes da caixa de diálogo](../mfc/dialog-box-classes.md)<br/>
[Estilos de barra de rolagem](../mfc/reference/styles-used-by-mfc.md#scroll-bar-styles)<br/>
[Exemplos de controle de edição avançada](../mfc/rich-edit-control-examples.md)<br/>
