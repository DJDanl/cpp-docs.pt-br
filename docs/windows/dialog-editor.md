---
title: Editor de caixaC++de diálogo ()
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
ms.openlocfilehash: 9d0f9993d81c499f67a08e5401c5e56dba7b281c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80215248"
---
# <a name="dialog-editor-c"></a>Editor de caixaC++de diálogo ()

O **Editor de diálogo** permite que você crie ou edite recursos da caixa de diálogo.

- Para abrir o editor, clique duas vezes no arquivo. rc de uma caixa de diálogo na janela **modo de exibição de recursos** ou vá até **modo de exibição** de menu > outra **modo de exibição de recursos**de > do **Windows** .

Uma das primeiras etapas para criar um novo modelo de caixa de diálogo ou caixa de diálogo é adicionar controles. No **Editor de caixa de diálogo**, você pode organizar os controles para se ajustar a um determinado tamanho, forma ou alinhamento, ou pode movê-los para o trabalho na caixa de diálogo. Também é fácil excluir um controle.

Você pode armazenar uma caixa de diálogo como um modelo para que possa reutilizá-la. Você também pode alternar facilmente entre projetar a caixa de diálogo e editar o código que a implementa.

Também é possível editar propriedades de um ou vários controles no **Editor de caixa de diálogo**. Você pode alterar a ordem de tabulação, ou seja, a ordem na qual os controles têm foco quando a tecla **Tab** é pressionada ou você pode definir uma tecla de acesso ou combinação de teclas que permite aos usuários escolher um controle usando o teclado.

O **Editor da caixa de diálogo** também permite que você use controles personalizados, incluindo controles ActiveX. Você também pode editar uma [exibição de formulário](../mfc/reference/cformview-class.md), [exibições de registro](../data/record-views-mfc-data-access.md)ou [barras de diálogo](../mfc/dialog-bars.md).

A partir do Visual Studio 2015, você pode usar o **Editor de caixa de diálogo** para definir layouts dinâmicos, que especificam como os controles são movidos e redimensionados quando o usuário redimensiona uma caixa de diálogo. Para obter mais informações, consulte [layout dinâmico](../mfc/dynamic-layout.md).

Para obter mais informações sobre recursos, consulte como [criar uma caixa](../windows/creating-a-new-dialog-box.md) de diálogo e [controles de caixa de diálogo](../windows/controls-in-dialog-boxes.md).

> [!TIP]
> Ao usar o **Editor de caixa de diálogo**, em muitas instâncias, você pode selecionar com o botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="dialog-editor-toolbar"></a>Barra de ferramentas do editor de diálogo

A barra de ferramentas do **Editor de caixa de diálogo** contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo, tamanho e alinhamento. Os botões da barra de ferramentas do **Editor de caixa de diálogo** correspondem aos comandos no menu **Formatar** .

|ícone|Significado|ícone|Significado|
|----------|-------------|----------|-------------|
|![Botão de diálogo testar](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Caixa de diálogo de teste|![Espaço ao longo do botão](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Via|
|![Botão Alinhar à esquerda](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar à esquerda|![Botão para baixo do espaço](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Para baixo|
|![Botão alinhar direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar direitos|![Botão da mesma largura](../mfc/media/vcdialogeditorsamewidth.png "vcDialogEditorSameWidth")|Igualar largura|
|![Botão alinhar partes superiores](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar partes superiores|![Botão da mesma altura](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Igualar altura|
|![Botão alinhar abaixo](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar partes inferiores|![Botão igualar tamanho](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Igualar tamanho|
|![Centralizar botão vertical](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Botão de alternância de grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|
|![Botão horizontal central](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Botão Alternar guias](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Alternar guias|

- Para mostrar ou ocultar a barra de ferramentas do **Editor de caixa de diálogo** , vá até modo de **exibição** de menu > **barras de ferramentas** > editor de **diálogo**.

Quando você abre o **Editor de caixa** de C++ diálogo em um projeto, a barra de ferramentas do **Editor de caixa de diálogo** aparece automaticamente na parte superior da sua solução. no entanto, se você fechar explicitamente a barra de ferramentas, será necessário chamá-la da próxima vez que abrir o editor da caixa de **diálogo**. Você pode alternar sua exibição selecionando-a na lista de barras de ferramentas e janelas disponíveis.

## <a name="switch-between-dialog-box-controls-and-code"></a>Alternar entre controles de caixa de diálogo e código

Em aplicativos MFC, você pode clicar duas vezes nos controles da caixa de diálogo para ir para o código do manipulador ou para criar rapidamente funções de manipulador de stub.

Com um controle selecionado, selecione o botão **ControlEvents** ou o botão **mensagens** na [janela Propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de mensagens e eventos do Windows disponíveis para o item selecionado. Escolha na lista para criar ou editar funções de manipulador.

- Para saltar para o código do **Editor**de caixa de diálogo, clique duas vezes em um controle dentro da caixa de diálogo para saltar para a declaração de sua função de manipulação de mensagens implementada mais recentemente.

   Para as classes de diálogo baseadas em ATL, você sempre salta para a definição do construtor.

- Para exibir eventos de um controle, com um controle selecionado, escolha o botão **ControlEvents** na janela **Propriedades** .

   Quando um único controle tiver foco na caixa de diálogo, você poderá clicar com o botão direito do mouse e selecionar **Adicionar manipulador de eventos**. Isso permite que você especifique a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).

   > [!NOTE]
   > Escolher o botão **ControlEvents** quando a caixa de diálogo tiver foco expõe uma lista de todos os controles na caixa de diálogo, que você pode expandir para editar os eventos para os controles individuais.

- Para exibir mensagens de uma caixa de diálogo, com a caixa de diálogo selecionada, escolha o botão **mensagens** na janela **Propriedades** .

## <a name="accelerator-keys"></a>Teclas de aceleração

Abaixo estão as teclas de aceleração padrão para os comandos do **Editor de caixa de diálogo** .  

|Comando|simétricas|DESCRIÇÃO|
|-------------|----------|-----------------|
|Format.AlignBottoms|**Ctrl** + **Shift** + **seta para baixo**|Alinha as bordas inferiores dos controles selecionados com o controle dominante.|
|Format.AlignCenters|**Shift** + **F9**|Alinha os centros verticais dos controles selecionados com o controle dominante.|
|Format.AlignLefts|**Ctrl** + **Shift** + **seta para a esquerda**|Alinha as bordas esquerdas dos controles selecionados com o controle dominante.|
|Format.AlignMiddles|**F9**|Alinha os centros horizontais dos controles selecionados com o controle dominante.|
|Format.AlignRights|**Ctrl** + **Shift** + **seta para a direita**|Alinha as bordas direitas dos controles selecionados com o controle dominante.|
|Format.AlignTops|**Ctrl** + **Shift** + **seta para cima**|Alinha as bordas superiores dos controles selecionados com o controle dominante.|
|Format.ButtonBottom|**Ctrl** + **B**|Coloca os botões selecionados ao longo do centro inferior da caixa de diálogo.|
|Format.ButtonRight|**Ctrl** + **R**|Coloca os botões selecionados no canto superior direito da caixa de diálogo.|
|Format.CenterHorizontal|**Ctrl** + **Shift** + **F9**|Centraliza os controles horizontalmente dentro da caixa de diálogo.|
|Format.CenterVertical|**Ctrl** + **F9**|Centraliza os controles verticalmente dentro da caixa de diálogo.|
|Format.CheckMnemonics|**Ctrl** + **M**|Verifica a exclusividade de mnemônicos.|
|Format.SizeToContent|**Shift** + **F7**|Redimensiona os controles selecionados para ajustá-los ao texto da legenda.|
|Format.SpaceAcross|**Alt** + **Seta para a Esquerda**|Espaça uniformemente os controles selecionados horizontalmente.|
|Format.SpaceDown|**Alt** + **seta para baixo**|Espaça uniformemente os controles selecionados verticalmente.|
|Format.TabOrder|**Ctrl** + **D**|Define a ordem dos controles dentro da caixa de diálogo.|
|Format.TestDialog|**Ctrl** + **T**|Executa a caixa de diálogo para testar a aparência e o comportamento.|
|Format.ToggleGuides|**Ctrl** + **G**|Alterna entre sem grade, diretrizes e grade para edição de caixa de diálogo.|

- Para alterar as teclas de atalho, vá para menu **ferramentas** > **Opções**e escolha **teclado** na pasta **ambiente** .

   Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

- Para alterar as configurações, vá até **ferramentas** de menu > **configurações de importação e exportação**.

   As opções disponíveis nas caixas de diálogo e os nomes e locais dos comandos de menu que você vê podem diferir do que está descrito na **ajuda** , dependendo de suas configurações ativas ou edição.  Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Como: criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md)<br/>
[Controles da caixa de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
<!--
[Controls](../mfc/controls-mfc.md)<br/>
[Control Classes](../mfc/control-classes.md)<br/>
[Dialog Box Classes](../mfc/dialog-box-classes.md)<br/>
[Dialog Box Controls and Variable Types](../ide/dialog-box-controls-and-variable-types.md)-->
