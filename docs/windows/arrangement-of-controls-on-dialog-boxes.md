---
title: 'Como: Organizar os controles (C++) | Microsoft Docs'
ms.date: 02/15/2019
f1_keywords:
- vc.editors.dialog.grouping
- vc.editors.dialog.combo
helpviewer_keywords:
- controls [C++], positioning
- dialog box controls [C++], placement
- Dialog Editor [C++], arranging controls
- Dialog Editor [C++], guides and margins
- guides, clearing
- guides
- dialog box controls [C++], placement
- controls [C++], guides and margins
- guides, creating
- guides, moving
- margins, moving
- DLUs (dialog units)
- controls [C++], aligning
- Dialog Editor [C++], snap to guides
- guides, tick mark interval
- dialog box controls [C++], placement
- guides, aligning controls
- dialog units (DLUs)
- snap to guides (Dialog editor)
- controls [C++], sizing
- tick mark interval in Dialog editor
- controls [C++], snap to guides/grid
- guides, disabling snapping
- controls [C++], snap to guides/grid
- controls [C++], layout grid
- snap to layout grid
- grids, turning on or off
- layout grid in Dialog Editor
- grids, changing size
- grid spacing
- guides, settings
- layout grid in Dialog Editor
- controls [C++], snap to guides/grid
- Guide Settings dialog box (Dialog editor)
- controls [C++], aligning
- controls [C++], positioning
- Space Evenly command
- dialog box controls [C++], placement
- Center in Dialog command
- Arrange Buttons command
- buttons, arranging push buttons in dialog boxes
- push buttons
- member variables, adding to radio button groups
- variables, dialog box control member variables
- dialog box controls [C++], grouping radio buttons
- grouping controls
- radio buttons [C++], grouping on dialog boxes
- controls [C++], tab order
- focus, tab order
- tab controls [C++], tab order
- Tabstop property for controls
- controls [C++], focus
- dialog box controls [C++], tab order
- Dialog Editor [C++], selecting controls
- dominant controls
- dialog box controls [C++], selecting in editor
- controls [C++], selecting
- size, controls
- controls [C++], dominant
- controls [C++], removing from groups
- Dialog Editor [C++], dominant control
- Size to Content command
- size, controls
- text, autosizing controls to fit text
- controls [C++], sizing
- Make Same Size command
- combo boxes, sizing
- list controls [C++], scroll bar width
- CListBox::SetHorizontalExtent
- controls [C++], scroll bar
- scroll bars [C++], displaying in controls
- horizontal scroll bar width
- CListBox class, scroll bar width
- scroll bars [C++], width
ms.assetid: 832491cf-98af-42e5-a854-2cb135fd45c6
ms.openlocfilehash: d9bd73c9cc81b113f222bbc090c62200c93554b2
ms.sourcegitcommit: 24592ba0a38c7c996ffd3d55fe1024231a59ccc2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/18/2019
ms.locfileid: "56336625"
---
# <a name="how-to-arrange-controls-c"></a>Como: Organizar os controles (C++)

O **caixa de diálogo** editor fornece ferramentas de layout que se alinham e dimensionar automaticamente os controles. Para a maioria das tarefas, você pode usar o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md). Todos os **Editor de caixa de diálogo** comandos da barra de ferramentas também estão disponíveis na **formato** menu e a maioria tem [teclas de atalho](../windows/accelerator-keys-for-the-dialog-editor.md).

Muitos comandos de layout para caixas de diálogo estão disponíveis somente quando mais de um controle é selecionado. Você pode selecionar um controle único ou vários controles, e quando mais de um controle é selecionado, a primeira é que você selecione é, por padrão, o controle "dominante". Para obter informações sobre a seleção de controles e o controle dominante, consulte [controles selecionando](../windows/selecting-controls.md).

O local, altura e largura do controle atual são exibidos no canto inferior direito da barra de status. Quando a caixa de diálogo inteira é selecionada, a barra de status exibe a posição da caixa de diálogo como um todo e sua altura e largura.

## <a name="guides-and-grids"></a>Guias e grades

Você pode organizar controles em caixas de diálogo com o **caixa de diálogo** editor em um dos três estados diferentes:

- Com os guias e margens em (configuração padrão)

- Com a grade de layout no

- Sem nenhum recurso de ajuste ou de alinhamento

O [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md) contém botões que controlam o estado. Para alterar o estado, selecione o ícone apropriado. Você também pode alterar estados usando o **configurações da guia** comando as **formato** menu.

O **guia de configurações** caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Guias de layout**|Exibe as configurações das guias de layout.|
|**Nenhum**|Oculta as ferramentas de layout.|
|**Réguas e guias**|Quando habilitado, adiciona réguas para as ferramentas de layout; guias podem ser colocados nas réguas. Os guias padrão são as margens, que podem ser movidas, arrastando. Selecione as réguas para colocar uma guia. Controles de "ajustará" aos guias de quando os controles são movidos pela ou ao lado deles. Controles também são movidos com um guia depois que eles são anexados a ele. Quando um controle está anexado a uma guia em cada lado e um guia é movido, o controle é redimensionado.|
|**Grade**|Cria uma grade de layout. Novos controles são alinhados automaticamente à grade.|
|**Espaçamento da grade**|Exibe as configurações para o espaçamento da grade em unidades de caixa de diálogo (DLUs).|
|**Largura: DLUs**|Define a largura da grade de layout em DLUs. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro.|
|**Altura: DLUs**|Define a altura da grade de layout em DLUs. Um DLU vertical é a média altura da fonte de caixa de diálogo dividida por oito.|

### <a name="to-create-edit-and-delete-guides-and-margins"></a>Para criar, editar e excluir guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias de podem ajudar a alinhar controles com precisão dentro de uma caixa de diálogo. Guias são exibidas como azul pontilhada entre a caixa de diálogo exibida no editor e setas correspondentes nas réguas na parte superior e o lado esquerdo dos **caixa de diálogo** editor.

Quando você cria uma caixa de diálogo, são fornecidas as quatro margens. As margens são modificadas guias, que aparecem como linhas pontilhadas azuis. Consulte as seguintes ações:

- Para criar uma guia, dentro da régua, selecione uma vez para criar uma guia. (Um clique cria uma nova guia; clicar duas vezes em inicializações a **configurações da guia** caixa de diálogo na qual você pode especificar configurações do guia.)

- Para definir um guia, na caixa de diálogo, selecione o guia e arraste-o para uma nova posição. (Você também pode selecionar a seta na régua à arraste a guia associada.) As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua. Mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.

- Para mover as margens, arraste a margem para a nova posição. Para tornar uma margem desaparecer, mova a margem para uma posição zero. Para trazer de volta a margem, coloque o ponteiro sobre a margem posição zero e mover a margem para a posição.

- Para excluir uma guia, arraste a guia fora da caixa de diálogo ou arraste a seta correspondente fora da régua.

### <a name="to-align-controls-on-a-guide"></a>Para alinhar controles em um guia

As alças de dimensionamento de controles de ajustam-se às guias de quando os controles são movidos e guias de ajustam-se aos controles se não houver nenhum controle ajustado anteriormente para o guia. Quando um guia é movido, controles que são ajustados para que ele é mover também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.

As marcas de escala em que determinam o espaçamento entre controles e guias de réguas são definidas pelas unidades de caixa de diálogo (DLUs). Um DLU baseia-se no tamanho da fonte de caixa de diálogo, normalmente de 8 pontas MS Shell Dlg. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro. Um DLU vertical é a média altura da fonte dividida por oito.

#### <a name="to-size-a-group-of-controls-with-guides"></a>Para dimensionar um grupo de controles com guias

1. Ajuste um dos lados do controle (ou controles) a uma guia.

1. Arraste um guia para o outro lado do controle (ou controles).

   Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.

1. Mova um guia para dimensionar o controle (ou controles).

#### <a name="to-change-the-intervals-of-the-tick-marks"></a>Alterar os intervalos das marcas de escala

Do **formato** menu, escolha **configurações da guia**, em seguida, no **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

### <a name="to-disable-guides"></a>Para desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito dos guias de ajuste. Usando o **Alt** chave desativa os efeitos de ajuste do guia selecionada. Movendo um guia com o **Shift** chave impede que os controles sem-instantâneo movendo com o guia.

- Para desabilitar o efeito de ajuste dos guias, arraste o controle enquanto mantém pressionada a **Alt** chave.

- Para mover guias sem mover os controles encaixados, arraste o guia enquanto mantém pressionada a **Shift** chave.

- Para desativar os guias do **formato** menu, escolha **guia de configurações**. Em seguida, nos **guia de configurações** caixa de diálogo **guias de Layout**, selecione **None**.

   > [!NOTE]
   > Você também pode clicar duas vezes a barra de régua para acessar o **guia de configurações** caixa de diálogo.

> [!TIP]
> Um atalho para desativar guias é sobre a **formato** menu, selecione **ativar/desativar guias**.

### <a name="to-modify-the-layout-grid"></a>Para modificar a grade de layout

Quando você está colocando ou Organizando controles em uma caixa de diálogo, você pode usar a grade de layout para um posicionamento mais preciso. Quando a grade é ativada, os controles aparecem para "ajustar-se às" as linhas pontilhadas da grade como se magnetizada. Você pode ativar e desativar a esse recurso de "Ajustar à grade" e alterar o tamanho das células da grade de layout.

- Para ativar ou desativar, a grade de layout do **formato** menu, escolha **configurações da guia**, em seguida, marque ou desmarque as **grade** botão.

   Você ainda pode controlar a grade no indivíduo **caixa de diálogo** janelas do editor usando o **ativar/desativar grade** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

- Para alterar o tamanho da grade de layout, do **formato** menu, escolha **guia Configurações**, em seguida, digite a altura e largura DLUs para as células na grade. A largura ou altura mínima é 4 DLUs.

## <a name="select-controls"></a>Selecionar controles

Selecione controles para tamanho, alinhar, mover, copiar, ou excluí-los e, em seguida, concluir a operação desejada. Na maioria dos casos, você precisa selecionar mais de um controle para usar as ferramentas de dimensionamento e o alinhamento a [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Quando um controle for selecionado, ele tem uma borda sombreada em torno dele com sólida (ativa) ou vazios (inativo) "alças de dimensionamento" pequenos quadrados que aparecem na borda de seleção. Quando vários controles estiverem selecionados, o controle dominante tem alças de dimensionamento sólida e todos os outros controles selecionados tem alças de dimensionamento vazado.

Quando você estiver dimensionando ou alinhar vários controles, o **caixa de diálogo** editor usa o "controle dominante" para determinar como os outros controles são dimensionados ou alinhados. Por padrão, o controle dominante é o primeiro controle selecionado.

### <a name="to-select-controls"></a>Selecionar controles

1. No [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o **ponteiro** ferramenta.

1. Use uma das etapas a seguir para fazer sua seleção:

   - Arraste o ponteiro para desenhar uma caixa de seleção ao redor dos controles que você deseja selecionar na caixa de diálogo. Quando você soltar o botão do mouse, todos os controles internos e interseção a caixa de seleção estiver marcada.

   - Mantenha pressionada a **Shift** da chave e selecione os controles que você deseja incluir na seleção.

   - Mantenha pressionada a **Ctrl** da chave e selecione os controles que você deseja incluir na seleção.

1. Para adicionar ou remover um controle do grupo de controles selecionados, mantenha pressionada a **Shift** da chave e selecione o controle que você deseja adicionar ou remover.

> [!NOTE]
> Manter pressionada a **Ctrl** chave e selecionando um controle dentro de uma seleção farão com que controlam o controle dominante nessa seleção.

### <a name="to-select-a-dominant-control"></a>Para selecionar um controle dominante

- Para especificar o controle dominante, mantenha pressionada a **Ctrl** da chave e selecione o controle que você deseja usar para influenciar o tamanho ou local de outros controles *primeiro*.

- Para alterar o controle dominante, desmarque a seleção atual selecionando fora de todos os controles selecionados no momento e repita o procedimento anterior, selecionar um controle diferente pela primeira vez.

> [!NOTE]
> As alças de dimensionamento do controle dominante são sólidas, enquanto as alças dos controles subordinados são vazadas. Todos os ainda mais o redimensionamento ou alinhamento baseia-se no controle dominante.

## <a name="size-controls"></a>Controles de tamanho

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as direções em que o controle pode ser redimensionado. Alças de dimensionamento do Active Directory são sólidas e se uma alça de dimensionamento for vazia, o controle não pode ser redimensionado ao longo desse eixo.

> [!TIP]
> Você também pode alterar o tamanho de um controle, ajuste o controle nas guias ou margens ou movendo um encaixada guia para longe do outro e controle.

### <a name="to-size-a-control"></a>Para dimensionar um controle

1. Selecione o controle.

1. Arraste as alças de dimensionamento para alterar o tamanho do controle:

   - Identificadores de tamanho na parte superior e os lados alteram o tamanho horizontal ou vertical.

   - Identificadores de tamanho nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a **Shift** chave e usando o **direita** e **para baixo** teclas de direção.

> [!TIP]
> Para dimensionar automaticamente um controle para se ajustar ao texto dentro dele, abra o **formato** menu ou o controle com o botão direito e escolha **tamanho ao conteúdo**.

### <a name="to-make-controls-the-same-size"></a>Para tornar os controles do mesmo tamanho

Você pode redimensionar um grupo de controles com base no tamanho do controle dominante.

1. Selecione os controles que você deseja redimensionar.

   O controle selecionado primeiro da série é o controle dominante. O tamanho final dos controles no grupo depende do tamanho do controle dominante.

1. Do **formato** menu, escolha **Igualar tamanho**, em seguida, escolha **ambos**, **altura**, ou **largura**.

### <a name="combo-box"></a>Caixa de Combinação

Quando você adicioná-lo à caixa de diálogo, você pode dimensionar uma caixa de combinação. Você também pode especificar o tamanho da caixa de listagem suspensa. Para obter mais informações, consulte [adicionando valores a um controle de caixa de combinação](../windows/adding-values-to-a-combo-box-control.md).

1. Selecione o botão de seta suspensa à direita da caixa de combinação.

   ![Seta em uma caixa de combinação em um projeto MFC](../mfc/media/vccomboboxarrow.gif "vcComboBoxArrow")

   O contorno do controle muda para mostrar o tamanho da caixa de combinação com a área de lista suspensa estendida.

1. Use a alça de dimensionamento inferior para alterar o tamanho inicial da área de lista suspensa.

   ![Caixa de combinação&#45;dimensionamento caixa em um projeto MFC](../mfc/media/vccomboboxsizing.gif "vcComboBoxSizing")

1. Selecione a seta suspensa novamente para fechar a parte da lista suspensa da caixa de combinação.

### <a name="horizontal-scroll-bar"></a>Barra de rolagem horizontal

Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando classes do MFC, a barra de rolagem não aparecerá automaticamente no seu aplicativo.

Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código. Sem este conjunto de valores, a barra de rolagem não aparecerá, até mesmo quando os itens na caixa de listagem são mais largas do que a caixa.

## <a name="align-controls"></a>Alinhar controles

1. Selecione os controles que você deseja alinhar. Certifique-se de selecionar o controle que você deseja ser dominante pela primeira vez ou defini-lo para ser o controle dominante antes de executar o alinhamento ou comando de dimensionamento.

   A posição final do grupo de controles depende a posição do controle dominante.

1. Dos **formato** menu, escolha **alinhar**e, em seguida, escolha uma das alinhamentos a seguir:

   |Alinhamento|Descrição|
   |-----|-----------|
   |`Lefts`|Alinha os controles selecionados ao longo dos lados esquerdos.|
   |`Centers`|Alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.|
   |`Rights`|Alinha os controles selecionados ao longo dos lados direito.|
   |`Tops`|Alinha os controles selecionados ao longo de suas bordas na parte superior.|
   |`Middles`|Alinha os controles selecionados verticalmente ao longo de seus pontos intermediários.|
   |`Bottoms`|Alinha os controles selecionados ao longo de suas bordas inferior.|

### <a name="to-even-spacing-between-controls"></a>Para espaçamento entre controles

O **caixa de diálogo** editor permite que você espaçar os controles uniformemente entre os controles mais externos selecionados.

1. Selecione os controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **espaçar uniformemente**e, em seguida, escolha uma dos alinhamentos de espaçamento a seguir:

   |Espaçamento|Descrição|
   |---|---|
   |`Across`|Controles de espaço uniformemente entre os mais à esquerda e o controle mais à direita selecionado.|
   |`Down`|Controles de espaço uniformemente entre o primeiro e o controle na extremidade inferior selecionado.|

### <a name="to-center-controls"></a>Para centralizar os controles

1. Selecione o controle ou controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **na caixa de diálogo Centro**e, em seguida, escolha uma das seguintes organizações:

   |Disposição|Descrição|
   |---|---|
   |`Vertical`|Centralizar os controles verticalmente na caixa de diálogo.|
   |`Horizontal`|Centralizar controles horizontalmente na caixa de diálogo.|

### <a name="to-arrange-push-buttons"></a>Para organizar os botões de ação

1. Selecione um ou mais botões de envio por push.

1. Dos **formato** menu, escolha **Organizar botões**e, em seguida, escolha uma das seguintes organizações:

   |Disposição|Descrição|
   |---|---|
   |`Right`|Alinha os botões de envio por push ao longo da borda direita da caixa de diálogo.|
   |`Bottom`|Alinha os botões de envio por push ao longo da borda inferior da caixa de diálogo.|

   Se você selecionar um controle que não seja um botão de envio por push, sua posição não é afetada.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)