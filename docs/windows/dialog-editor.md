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
ms.openlocfilehash: 7bc5d5763881b862487fa97e02da02d98bcd017d
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562939"
---
# <a name="dialog-editor-c"></a>Editor de caixa de diálogo (C++)

O **Editor de caixa de diálogo** permite que você criar ou editar recursos de caixa de diálogo.

- Para abrir o editor, clique duas vezes no arquivo. rc da caixa de diálogo na **exibição de recurso** janela ou ir para o menu **exibição** > **exibição de recurso**.

Uma das primeiras etapas na tomada de uma caixa de diálogo Novo ou o modelo de caixa de diálogo, está adicionando controles. No **Editor de caixa de diálogo**, você pode organizar os controles de acordo com um determinado tamanho, forma ou alinhamento, ou você pode movê-los para trabalhar dentro da caixa de diálogo. Também é fácil excluir um controle.

Você pode armazenar uma caixa de diálogo como um modelo para que você possa reutilizá-lo. Também é fácil, você pode alternar entre a caixa de diálogo de criação e editando o código que implementa a ele.

Também é possível editar as propriedades de único ou vários controles na **Editor de caixa de diálogo**. Você pode alterar a ordem de tabulação, ou seja, a ordem na qual os controles de obtém foco quando o **guia** tecla é pressionada, ou você pode definir uma chave de acesso ou a combinação de teclas que permite aos usuários escolher um controle usando o teclado.

O **Editor de caixa de diálogo** também permite que você use os controles personalizados, incluindo os controles ActiveX. Você também pode editar uma [exibição de formulário](../mfc/reference/cformview-class.md), [modos de exibição de registro](../data/record-views-mfc-data-access.md), ou [barras da caixa de diálogo](../mfc/dialog-bars.md).

Começando com o Visual Studio 2015, você pode usar o **Editor de caixa de diálogo** definir layouts dinâmicos, que especificam como os controles de movem e redimensionar quando o usuário redimensiona uma caixa de diálogo. Para obter mais informações, consulte [Layout dinâmico](../mfc/dynamic-layout.md).

Para obter mais informações sobre recursos, consulte como [criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md) e [controles de caixa de diálogo](../windows/controls-in-dialog-boxes.md).

> [!TIP]
> Ao usar o **Editor de caixa de diálogo**, em muitos casos, você pode selecionar com o botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="dialog-editor-toolbar"></a>Barra de ferramentas do Editor de caixa de diálogo

O **Editor de caixa de diálogo** barra de ferramentas contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo tamanho e alinhamento. **Editor de caixa de diálogo** botões da barra de ferramentas correspondem aos comandos na **formato** menu.

|Ícone|Significado|Ícone|Significado|
|----------|-------------|----------|-------------|
|![Botão da caixa de diálogo de teste](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Caixa de diálogo de teste|![Botão de espaço entre](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Entre|
|![Alinhar botão esquerdas](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar à esquerda|![Botão espaço para baixo](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Abaixo|
|![Alinhar o botão de direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar os direitos|![Botão de mesma largura Make](../mfc/media/vcdialogeditorsamewidth.png "vcDialogEditorSameWidth")|Fazer a mesma largura|
|![Alinhar botão Tops](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar partes superiores|![Botão de mesma altura Make](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Make Same Height|
|![Botão inferior alinhar](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar partes inferiores|![Botão de mesmo tamanho de marca](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Igualar tamanho|
|![Botão de centro Vertical](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Botão de alternância de grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|
|![Botão de centro Horizontal](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Botão de guias de alternância](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Ativar/desativar guias|

- Para mostrar ou ocultar a **Editor de caixa de diálogo** barra de ferramentas, vá ao menu **exibição** > **barras de ferramentas** > **Editor de caixa de diálogo**.

Quando você abre o **Editor de caixa de diálogo** em um projeto do C++, o **Editor de caixa de diálogo** barra de ferramentas aparece automaticamente na parte superior da sua solução, no entanto, se você fechar explicitamente a barra de ferramentas, você precisará invocá-lo a próxima vez que abrir o **Editor de caixa de diálogo**. Você pode alternar a exibição, selecionando-o na lista de barras de ferramentas disponíveis e windows.

## <a name="switch-between-dialog-box-controls-and-code"></a>Alternar entre os controles de caixa de diálogo e código

Em aplicativos MFC, você pode clicar duas vezes em controles de caixa de diálogo para saltar para o seu código de manipulador ou crie rapidamente stub de funções do manipulador.

Com um controle selecionado, selecione a **ControlEvents** botão ou o **mensagens** botão o [janela propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de mensagens do Windows e eventos disponível para o item selecionado. Escolha na lista para criar ou editar funções de manipulador.

- Para ir para o código a partir o **Editor de caixa de diálogo**, clique duas vezes em um controle dentro da caixa de diálogo para ir para a declaração para sua função de manipulação de mensagens implementada mais recentemente.

   Para classes de caixa de diálogo com base em ATL, você sempre ir para a definição do construtor.

- Para exibir eventos para um controle, com um controle selecionado, escolha o **ControlEvents** botão na **propriedades** janela.

   Quando um único controle tem o foco na caixa de diálogo, é possível com o botão direito e selecionar **Adicionar manipulador de eventos**. Isso permite que você especificar a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).

   > [!NOTE]
   > Escolhendo a **ControlEvents** botão quando a caixa de diálogo tem o foco expõe uma lista de todos os controles na caixa de diálogo, você pode, em seguida, expandir para editar os eventos para os controles individuais.

- Para exibir as mensagens para uma caixa de diálogo com a caixa de diálogo selecionada, escolha o **mensagens** botão na **propriedades** janela.

## <a name="accelerator-keys"></a>Teclas de aceleração

Abaixo está o padrão de teclas de aceleração para o **Editor de caixa de diálogo** comandos.  

|Comando|Chaves|Descrição|
|-------------|----------|-----------------|
|Format.AlignBottoms|**CTRL** + **Shift** + **na seta para baixo**|Alinha as bordas inferiores dos controles selecionados com o controle dominante.|
|Format.AlignCenters|**Shift** + **F9**|Alinha os centros verticais dos controles selecionados com o controle dominante.|
|Format.AlignLefts|**CTRL** + **Shift** + **seta para a esquerda**|Alinha as bordas esquerdas dos controles selecionados com o controle dominante.|
|Format.AlignMiddles|**F9**|Alinha os centros horizontais dos controles selecionados com o controle dominante.|
|Format.AlignRights|**CTRL** + **Shift** + **seta para a direita**|Alinha as bordas direitas dos controles selecionados com o controle dominante.|
|Format.AlignTops|**CTRL** + **Shift** + **seta para cima**|Alinha as bordas na parte superior dos controles selecionados com o controle dominante.|
|Format.ButtonBottom|**Ctrl** + **B**|Coloca os botões selecionados ao longo da parte inferior central da caixa de diálogo.|
|Format.ButtonRight|**Ctrl** + **R**|Coloca os botões selecionados no canto superior direito da caixa de diálogo.|
|Format.CenterHorizontal|**Ctrl** + **Shift** + **F9**|Centraliza os controles horizontalmente dentro da caixa de diálogo.|
|Format.CenterVertical|**Ctrl** + **F9**|Centraliza os controles verticalmente dentro da caixa de diálogo.|
|Format.CheckMnemonics|**Ctrl** + **M**|Verifica a exclusividade de mnemônicos.|
|Format.SizeToContent|**Shift** + **F7**|Redimensiona o controle (s) selecionado de acordo com o texto da legenda.|
|Format.SpaceAcross|**Alt** + **Seta para a Esquerda**|Espaços uniformemente os controles selecionados horizontalmente.|
|Format.SpaceDown|**ALT** + **na seta para baixo**|Espaços uniformemente os controles selecionados verticalmente.|
|Format.TabOrder|**Ctrl** + **D**|Define a ordem dos controles na caixa de diálogo.|
|Format.TestDialog|**Ctrl** + **T**|Executa a caixa de diálogo para testar a aparência e comportamento.|
|Format.ToggleGuides|**Ctrl** + **G**|Ciclos entre nenhuma grade, diretrizes e grade para a caixa de diálogo de edição.|

- Para alterar as teclas de atalho, vá ao menu **ferramentas** > **opções**e escolha **teclado** sob o **ambiente** pasta.

   Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

- Para alterar suas configurações, vá ao menu **ferramentas** > **importar e exportar configurações**.

   As opções disponíveis nas caixas de diálogo e os nomes e locais dos comandos de menu que você vê, podem diferir do que é descrito na **ajudar** dependendo de suas configurações ativas ou edição.  Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)<br/>
[Como: Criar uma caixa de diálogo](../windows/creating-a-new-dialog-box.md)<br/>
[Controles de caixa de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
<!--
[Controls](../mfc/controls-mfc.md)<br/>
[Control Classes](../mfc/control-classes.md)<br/>
[Dialog Box Classes](../mfc/dialog-box-classes.md)<br/>
[Dialog Box Controls and Variable Types](../ide/dialog-box-controls-and-variable-types.md)-->