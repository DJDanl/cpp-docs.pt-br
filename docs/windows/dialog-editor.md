---
title: Editor de Diálogo (C++)
ms.date: 02/15/2019
f1_keywords:
- vc.editors.dialog.dialog
- vc.editors.dialog.F1
- vc.editors.dialog
helpviewer_keywords:
- resource editors [C++], Dialog editor
- editors, dialog boxes
- Dialog editor
- dialog boxes [C++], editing
- controls [C++], showing or hiding Dialog editor toolbar
- toolbars [C++], showing
- toolbars [C++], hiding
- Dialog Editor [C++], showing or hiding toolbar
- events [C++], viewing for controls
- Windows messages [C++], controls
- messages [C++], viewing for dialog boxes
- Dialog Editor [C++], accessing code
- code [C++], switching from Dialog Editor
- controls [C++], jumping to code
- Dialog Editor [C++], switching between controls and code
- Dialog Editor [C++], shortcut keys
ms.assetid: d94884ef-2cca-49d8-9b58-775f34848134
ms.openlocfilehash: f1544d3a8e14f9373e21b77d888860d24ab1ed6a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370287"
---
# <a name="dialog-editor-c"></a>Editor de Diálogo (C++)

O **Editor de Diálogo** permite criar ou editar recursos da caixa de diálogo.

- Para abrir o editor, clique duas vezes no arquivo .rc da caixa de diálogo na janela **'Exibição de recursos'** ou vá para o menu **Exibir** > **outra exibição** > de recursos**do Windows .**

Um dos primeiros passos para fazer uma nova caixa de diálogo ou modelo de caixa de diálogo é adicionar controles. No **Editor de Diálogo,** você pode organizar controles para caber em um determinado tamanho, forma ou alinhamento, ou pode movê-los para trabalhar dentro da caixa de diálogo. Também é fácil excluir um controle.

Você pode armazenar uma caixa de diálogo como um modelo para que você possa reutilizá-la. Você também pode alternar facilmente entre projetar a caixa de diálogo e editar o código que a implementa.

Também é possível editar propriedades de controles únicos ou múltiplos no **Editor de Diálogo**. Você pode alterar a ordem da guia, ou seja, a ordem na qual os controles ganham foco quando a **tecla Tab** é pressionada, ou você pode definir uma chave de acesso ou combinação de teclas que permite que os usuários escolham um controle usando o teclado.

O **Editor de Diálogo** também permite que você use controles personalizados, incluindo controles ActiveX. Você também pode editar uma [exibição de formulário,](../mfc/reference/cformview-class.md) [gravar visualizações](../data/record-views-mfc-data-access.md)ou [barras de diálogo](../mfc/dialog-bars.md).

A partir do Visual Studio 2015, você pode usar o **Editor de Diálogo** para definir layouts dinâmicos, que especificam como os controles se movem e redimensionam quando o usuário redimensiona uma caixa de diálogo. Para obter mais informações, consulte [Layout Dinâmico](../mfc/dynamic-layout.md).

Para obter mais informações sobre recursos, consulte como [criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md) e controles de caixa de [diálogo](../windows/controls-in-dialog-boxes.md).

> [!TIP]
> Ao usar o **Editor de diálogo,** em muitos casos, você pode selecionar com o botão direito do mouse para exibir um menu de atalho de comandos usados com freqüência.

## <a name="dialog-editor-toolbar"></a>Barra de ferramentas do editor de diálogo

A barra de ferramentas **do Editor de Diálogo** contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo, tamanho e alinhamento. **Os** botões da barra de ferramentas do Editor de Diálogo correspondem aos comandos no menu **Formato.**

|ícone|Significado|ícone|Significado|
|----------|-------------|----------|-------------|
|![Botão de diálogo de teste](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Diálogo de teste|![Botão de atravessar espaço](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Através|
|![Alinhar botão esquerdo](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar esquerdas|![Botão de down do espaço](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Para baixo|
|![Botão Alinhar direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar direitos|![Faça o mesmo botão de largura](../mfc/media/vcdialogeditorsamewidth.png "vcDiálogoEditorSameLargura")|Faça a mesma largura|
|![Botão Alinhar topos](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar topos|![Faça o mesmo botão de altura](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Faça a mesma altura|
|![Botão Alinhar fundo](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar as partes inferiores|![Faça o mesmo tamanho botão](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Faça o mesmo tamanho|
|![Botão vertical central](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Botão alternar grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|
|![Botão horizontal central](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Botão Guias alternados](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Guias alternar|

- Para mostrar ou ocultar a barra de ferramentas **do Editor de diálogo,** vá para o menu **Exibir** > **'Ferramenta de** > **diálogo Editor de diálogo**.

Ao abrir o **Editor de Diálogo** em um projeto C++, a barra de ferramentas Do Editor de **Diálogo** aparece automaticamente na parte superior da sua solução, no entanto, se você fechar explicitamente a barra de ferramentas, você precisará invocá-la na próxima vez que abrir o Editor **de Diálogo**. Você pode alternar sua exibição selecionando-a na lista de barras de ferramentas e janelas disponíveis.

## <a name="switch-between-dialog-box-controls-and-code"></a>Alternar entre controles de caixa de diálogo e código

Em aplicativos MFC, você pode clicar duas vezes nos controles da caixa de diálogo para saltar para o código do manipulador ou para criar rapidamente funções de manipulador de stub.

Com um controle selecionado, selecione o botão **ControlEvents** ou o botão **Mensagens** na [janela Propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de mensagens e eventos do Windows disponíveis para o item selecionado. Escolha entre a lista para criar ou editar funções de manipulador.

- Para saltar para o código do Editor de **Diálogo,** clique duas vezes em um controle dentro da caixa de diálogo para saltar para a declaração de sua função de manipulação de mensagens mais recentemente implementada.

   Para classes de diálogo baseadas em ATL, você sempre pula para a definição do construtor.

- Para exibir eventos para um controle, com um controle selecionado, escolha o botão **ControlEvents** na janela **Propriedades.**

   Quando um único controle tiver foco na caixa de diálogo, você pode clicar com o botão direito do mouse e selecionar **Adicionar manipulador de eventos**. Isso permite especificar a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [Adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).

   > [!NOTE]
   > Escolher o botão **ControlEvents** quando a caixa de diálogo tem foco expõe uma lista de todos os controles na caixa de diálogo, que você pode expandir para editar os eventos para os controles individuais.

- Para exibir mensagens para uma caixa de diálogo, com a caixa de diálogo selecionada, escolha o botão **Mensagens** na janela **Propriedades.**

## <a name="accelerator-keys"></a>Teclas de aceleração

Abaixo estão as teclas padrão do acelerador para os comandos **do Editor de Diálogo.**  

|Comando|simétricas|Descrição|
|-------------|----------|-----------------|
|Format.AlignBottoms|**Seta** + **para baixo** **do turno** + ctrl|Alinha as bordas inferiores dos controles selecionados com o controle dominante.|
|Format.AlignCenters|**Turno** + **F9**|Alinha os centros verticais dos controles selecionados com o controle dominante.|
|Format.AlignLefts|**Ctrl** + **Shift** + **Seta esquerda** do turno ctrl|Alinha as bordas esquerdas dos controles selecionados com o controle dominante.|
|Format.AlignMiddles|**F9**|Alinha os centros horizontais dos controles selecionados com o controle dominante.|
|Format.AlignRights|**Ctrl** + **Shift** + **Seta direita** do turno ctrl|Alinha as bordas direitas dos controles selecionados com o controle dominante.|
|Format.AlignTops|**Seta** + **de mudança de** + ctrl**para cima**|Alinha as bordas superiores dos controles selecionados com o controle dominante.|
|Format.ButtonBottom|**Ctrl** + **B**|Coloca os botões selecionados ao longo do centro inferior da caixa de diálogo.|
|Format.ButtonRight|**Ctrl** + **R**|Coloca os botões selecionados no canto superior direito da caixa de diálogo.|
|Format.CenterHorizontal|**Ctrl** + **Shift**Mudança + ctrl**F9**|Centraliza os controles horizontalmente dentro da caixa de diálogo.|
|Format.CenterVertical|**Ctrl** + **F9**|Centraliza os controles verticalmente dentro da caixa de diálogo.|
|Format.CheckMnemonics|**Ctrl** + **M**|Verifica a singularidade dos mnemônicos.|
|Format.SizeToContent|**Turno** + **F7**|Redimensiona os controles selecionados para ajustar o texto da legenda.|
|Format.SpaceAcross|**Seta** + **esquerda** alt|Espatecem uniformemente os controles selecionados horizontalmente.|
|Format.SpaceDown|**Alt** + **Seta para baixo**|Espatecem uniformemente os controles selecionados verticalmente.|
|Format.TabOrder|**Ctrl** + **D**|Define a ordem de controles dentro do diálogo.|
|Format.TestDialog|**Ctrl** + **T**|Executa a caixa de diálogo para testar a aparência e o comportamento.|
|Format.ToggleGuides|**Ctrl** + **G**|Ciclos entre grade, diretrizes e grade para edição de diálogo.|

- Para alterar as teclas de atalho, vá para menu **Opções de** > **ferramentas**e escolha **Teclado** na pasta **Meio Ambiente.**

   Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

- Para alterar suas configurações, vá para menu **Ferramentas** > **De importação e configurações de exportação**.

   As opções disponíveis nas caixas de diálogo e os nomes e locais dos comandos de menu que você vê podem diferir do que é descrito em **Ajuda,** dependendo de suas configurações ativas ou edição.  Para obter mais informações, consulte [Personalizar o Visual Studio IDE](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Como: Criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md)<br/>
[Controles da caixa de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
<!--
[Controls](../mfc/controls-mfc.md)<br/>
[Control Classes](../mfc/control-classes.md)<br/>
[Dialog Box Classes](../mfc/dialog-box-classes.md)<br/>
[Dialog Box Controls and Variable Types](../ide/dialog-box-controls-and-variable-types.md)-->
