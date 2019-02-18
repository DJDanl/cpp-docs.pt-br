---
title: Editor de caixa de diálogo (C++)
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
ms.openlocfilehash: fef4a7f0d4c785a40ea946127d8e3c84c797e1aa
ms.sourcegitcommit: 24592ba0a38c7c996ffd3d55fe1024231a59ccc2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/18/2019
ms.locfileid: "56336690"
---
# <a name="dialog-editor-c"></a>Editor de caixa de diálogo (C++)

O **caixa de diálogo** editor permite que você criar ou editar os recursos de caixa de diálogo. Abra o editor de caixa de diálogo clicando duas vezes no arquivo. rc da caixa de diálogo do **exibição de recurso** janela (**exibição** > **exibição de recurso**). Observe que **exibição de recurso** não está disponível nas edições Express.

Uma das primeiras etapas na tomada de uma caixa de diálogo Novo (ou o modelo de caixa de diálogo) é adicionando controles à caixa de diálogo. No **caixa de diálogo** editor, você pode organizar os controles de acordo com um determinado tamanho, forma ou alinhamento, ou você pode movê-los para trabalhar dentro da caixa de diálogo. Também é fácil excluir um controle.

Você pode armazenar uma caixa de diálogo como um modelo para que você possa reutilizá-lo. Também é fácil, você pode alternar entre a caixa de diálogo de criação e editando o código que implementa a ele.

Também é possível editar as propriedades de um ou vários controles no editor de caixa de diálogo. Você pode alterar a ordem de tabulação, ou seja, a ordem na qual os controles de obtém foco quando o **guia** tecla é pressionada, ou você pode definir uma chave de acesso (uma combinação de teclas) que permite aos usuários escolher um controle usando o teclado.

O **caixa de diálogo** editor também permite que você use os controles personalizados, incluindo os controles ActiveX. Além disso, você pode editar uma [exibição de formulário](../mfc/reference/cformview-class.md), [exibições de registro](../data/record-views-mfc-data-access.md), ou [barras da caixa de diálogo](../mfc/dialog-bars.md).

Começando com o Visual Studio 2015, você pode usar o editor de caixa de diálogo para definir layouts dinâmicos, que especificam como os controles de mover e redimensionem quando o usuário redimensiona uma caixa de diálogo. Para obter mais informações, consulte [Layout dinâmico](../mfc/dynamic-layout.md).

- [Como: Criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md)

- [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)

   > [!TIP]
   > Ao usar o **caixa de diálogo** editor, em muitos casos, você pode selecionar o botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="dialog-editor-toolbar"></a>Barra de ferramentas do Editor de caixa de diálogo

Quando você abre o **caixa de diálogo** editor em um projeto do C++, o **Editor de caixa de diálogo** barra de ferramentas aparece automaticamente na parte superior da sua solução.

|Ícone|Significado|Ícone|Significado|
|----------|-------------|----------|-------------|
|![Botão da caixa de diálogo de teste](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Caixa de diálogo de teste|![Botão de espaço entre](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Entre|
|![Alinhar botão esquerdas](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar à esquerda|![Botão espaço para baixo](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Abaixo|
|![Alinhar o botão de direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar os direitos|![Botão de mesma largura Make](../mfc/media/vcdialogeditorsamewidth.png "vcDialogEditorSameWidth")|Fazer a mesma largura|
|![Alinhar botão Tops](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar partes superiores|![Botão de mesma altura Make](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Make Same Height|
|![Botão inferior alinhar](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar partes inferiores|![Botão de mesmo tamanho de marca](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Igualar tamanho|
|![Botão de centro Vertical](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Botão de alternância de grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|
|![Botão de centro Horizontal](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Botão de guias de alternância](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Ativar/desativar guias|

O **Editor de caixa de diálogo** barra de ferramentas contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo tamanho e alinhamento. **Editor de caixa de diálogo** botões da barra de ferramentas correspondem aos comandos na **formato** menu.

Quando você está no **caixa de diálogo** editor, você pode alternar a exibição da **Editor de caixa de diálogo** barra de ferramentas, selecionando-o na lista de barras de ferramentas disponíveis e windows.

- Para mostrar ou ocultar a barra de ferramentas editor de caixa de diálogo, no **modo de exibição** menu, selecione **barras de ferramentas**, em seguida, escolha **Editor de caixa de diálogo** do submenu.

   > [!NOTE]
   > O **Editor de caixa de diálogo** barra de ferramentas é exibida por padrão, quando você abre um recurso de caixa de diálogo no editor de caixa de diálogo; no entanto, se você fechar explicitamente a barra de ferramentas, você precisará invocá-lo na próxima vez que você abrir um recurso de caixa de diálogo.

## <a name="switch-between-dialog-box-controls-and-code"></a>Alternar entre os controles de caixa de diálogo e código

Em aplicativos MFC, você pode clicar duas vezes em controles de caixa de diálogo para saltar para o seu código de manipulador ou crie rapidamente stub de funções do manipulador.

Com um controle selecionado, clique no **ControlEvents** botão ou o **mensagens** botão o [janela propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de mensagens do Windows e eventos disponível para o item selecionado. Escolha na lista para criar ou editar funções de manipulador.

- Para ir diretamente ao código do editor de caixa de diálogo, clique duas vezes em um controle dentro da caixa de diálogo para ir para a declaração para sua função de manipulação de mensagens implementada mais recentemente. (Para classes de caixa de diálogo com base em ATL, você sempre ir para a definição do construtor.)

- Para exibir eventos para um controle, com um controle selecionado, escolha o **ControlEvents** botão na [janela propriedades](/visualstudio/ide/reference/properties-window).

   > [!NOTE]
   > Escolhendo a **ControlEvents** botão quando o *caixa de diálogo* tem foco expõe uma lista de todos os controles na caixa de diálogo, você pode, em seguida, expandir para editar os eventos para os controles individuais.

   Quando um único controle tem o foco na caixa de diálogo, você pode clique duas vezes e selecionar **Adicionar manipulador de eventos** no menu de atalho. Isso permite que você especificar a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).

- Para exibir as mensagens para uma caixa de diálogo com a caixa de diálogo selecionada, escolha o **mensagens** botão na [janela propriedades](/visualstudio/ide/reference/properties-window).

## <a name="accelerator-keys"></a>Teclas de aceleração

Abaixo são o padrão teclas de aceleração para os comandos do editor de caixa de diálogo. Para alterar as teclas de atalho, selecione **opções** na **ferramentas** menu, em seguida, escolha **teclado** sob o **ambiente** pasta. Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

> [!NOTE]
> As opções disponíveis nas caixas de diálogo e os nomes os locais dos comandos de menu que você vê podem diferir do que é descrito na Ajuda, dependendo de suas configurações ativas ou da edição. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

|Comando|Chaves|Descrição|
|-------------|----------|-----------------|
|Format.AlignBottoms|**CTRL** + **Shift** + **na seta para baixo**|Alinha as bordas inferior dos controles selecionados com o controle dominante|
|Format.AlignCenters|**Shift** + **F9**|Alinha os centros verticais dos controles selecionados com o controle dominante|
|Format.AlignLefts|**CTRL** + **Shift** + **seta para a esquerda**|Alinha as bordas esquerdas dos controles selecionados com o controle dominante|
|Format.AlignMiddles|**F9**|Alinha os centros horizontais dos controles selecionados com o controle dominante|
|Format.AlignRights|**CTRL** + **Shift** + **seta para a direita**|Alinha as bordas direitas dos controles selecionados com o controle dominante|
|Format.AlignTops|**CTRL** + **Shift** + **seta para cima**|Alinha as bordas na parte superior dos controles selecionados com o controle dominante|
|Format.ButtonBottom|**Ctrl** + **B**|Coloca os botões selecionados ao longo da parte inferior central da caixa de diálogo|
|Format.ButtonRight|**Ctrl** + **R**|Coloca os botões selecionados no canto superior direito da caixa de diálogo|
|Format.CenterHorizontal|**Ctrl** + **Shift** + **F9**|Centraliza os controles horizontalmente dentro da caixa de diálogo|
|Format.CenterVertical|**Ctrl** + **F9**|Centraliza os controles verticalmente dentro da caixa de diálogo|
|Format.CheckMnemonics|**Ctrl** + **M**|Verificações de exclusividade de mnemônicos|
|Format.SizeToContent|**Shift** + **F7**|Redimensiona o controle (s) selecionado de acordo com o texto da legenda|
|Format.SpaceAcross|**Alt** + **Seta para a Esquerda**|Espaços de uniformemente os controles selecionados horizontalmente|
|Format.SpaceDown|**ALT** + **na seta para baixo**|Espaços de uniformemente os controles selecionados verticalmente|
|Format.TabOrder|**Ctrl** + **D**|Define a ordem dos controles na caixa de diálogo|
|Format.TestDialog|**Ctrl** + **T**|Executa a caixa de diálogo para testar a aparência e comportamento|
|Format.ToggleGuides|**Ctrl** + **G**|Ciclos entre nenhuma grade, diretrizes e grade para a caixa de diálogo de edição|

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: criar um recurso](../windows/how-to-create-a-resource.md)<br/>
[Controles](../mfc/controls-mfc.md)<br/>
[Classes de controle](../mfc/control-classes.md)<br/>
[Classes da caixa de diálogo](../mfc/dialog-box-classes.md)<br/>
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)