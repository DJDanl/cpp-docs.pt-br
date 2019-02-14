---
title: Organização de controles em caixas de diálogo (C++) | Microsoft Docs
ms.date: 11/04/2016
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
ms.openlocfilehash: 99667898428fe9532d59277bfedafd24927304dc
ms.sourcegitcommit: eb2b34a24e6edafb727e87b138499fa8945f981e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2019
ms.locfileid: "56264875"
---
# <a name="arrangement-of-controls-on-dialog-boxes-c"></a>Organização de controles em caixas de diálogo (C++)

O **caixa de diálogo** editor fornece ferramentas de layout que se alinham e dimensionar automaticamente os controles. Para a maioria das tarefas, você pode usar o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md). Todos os **Editor de caixa de diálogo** comandos da barra de ferramentas também estão disponíveis na **formato** menu e a maioria tem [teclas de atalho](../windows/accelerator-keys-for-the-dialog-editor.md).

Muitos comandos de layout para caixas de diálogo estão disponíveis somente quando mais de um controle é selecionado. Você pode selecionar um controle único ou vários controles, e quando mais de um controle é selecionado, a primeira é que você selecione é, por padrão, o controle "dominante". Para obter informações sobre a seleção de controles e o controle dominante, consulte [controles selecionando](../windows/selecting-controls.md).

O local, altura e largura do controle atual são exibidos no canto inferior direito da barra de status. Quando a caixa de diálogo inteira é selecionada, a barra de status exibe a posição da caixa de diálogo como um todo e sua altura e largura.

## <a name="dialog-editor-states-guides-and-grids"></a>Estados do editor de caixa de diálogo (guias e grades)

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

### <a name="create-and-set-guides-and-margins"></a>Crie e defina os guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias de podem ajudar a alinhar controles com precisão dentro de uma caixa de diálogo. Guias são exibidas como azul pontilhada entre a caixa de diálogo exibida no editor e setas correspondentes nas réguas na parte superior e o lado esquerdo dos **caixa de diálogo** editor.

Quando você cria uma caixa de diálogo, são fornecidas as quatro margens. As margens são modificadas guias, que aparecem como linhas pontilhadas azuis.

|Processo|Etapas|
|----------------|----------------|
|Para criar uma guia|Dentro da régua, selecione uma vez para criar uma guia. (Um clique cria uma nova guia; clicar duas vezes em inicializações a **configurações da guia** caixa de diálogo na qual você pode especificar configurações do guia.)|
|Para definir um guia|Na caixa de diálogo, clique na guia e arraste-o para uma nova posição. (Você também pode clicar na seta na régua à arraste a guia associada).<br/><br/>As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua. Mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.|
|Para excluir uma guia|Arraste a guia fora da caixa de diálogo.<br/><br/>\- ou -<br/><br/>Arraste a seta correspondente fora da régua.|
|Para mover as margens|Arraste a margem para a nova posição.<br/><br/>Para tornar uma margem desaparecer, mova a margem para uma posição zero. Para trazer de volta a margem, coloque o ponteiro sobre a margem posição zero e mover a margem para a posição.|

### <a name="align-controls-on-a-guide"></a>Alinhar controles em um guia

As alças de dimensionamento de controles de ajustam-se às guias de quando os controles são movidos e guias de ajustam-se aos controles se não houver nenhum controle ajustado anteriormente para o guia. Quando um guia é movido, controles que são ajustados para que ele é mover também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.

As marcas de escala em que determinam o espaçamento entre controles e guias de réguas são definidas pelas unidades de caixa de diálogo (DLUs). Um DLU baseia-se no tamanho da fonte de caixa de diálogo, normalmente de 8 pontas MS Shell Dlg. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro. Um DLU vertical é a média altura da fonte dividida por oito.

Para dimensionar um grupo de controles com guias:

1. Ajuste um dos lados do controle (ou controles) a uma guia.

1. Arraste um guia para o outro lado do controle (ou controles).

   Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.

1. Mova um guia para dimensionar o controle (ou controles).

Para alterar os intervalos das marcas de escala:

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** na caixa de **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

### <a name="disable-guides"></a>Desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito dos guias de ajuste. Usando o **Alt** chave desativa os efeitos de ajuste do guia selecionada. Movendo um guia com o **Shift** chave impede que os controles sem-instantâneo movendo com o guia.

- Para desabilitar o efeito de ajuste dos guias, arraste o controle enquanto mantém pressionada a **Alt** chave.

- Para mover guias sem mover os controles encaixados, arraste o guia enquanto mantém pressionada a **Shift** chave.

- Para desativar os guias do **formato** menu, escolha **guia de configurações**. Em seguida, nos **guia de configurações** caixa de diálogo **guias de Layout**, selecione **None**.

   > [!NOTE]
   > Você também pode clicar duas vezes a barra de régua para acessar o **guia de configurações** caixa de diálogo.

> [!TIP]
> Um atalho para desativar guias é sobre a **formato** menu, selecione **ativar/desativar guias**.

### <a name="modify-the-layout-grid"></a>Modificar a grade de layout

Quando você está colocando ou Organizando controles em uma caixa de diálogo, você pode usar a grade de layout para um posicionamento mais preciso. Quando a grade é ativada, os controles aparecem para "ajustar-se às" as linhas pontilhadas da grade como se magnetizada. Você pode ativar e desativar a esse recurso de "Ajustar à grade" e alterar o tamanho das células da grade de layout.

Para ativar ou desativar a grade de layout:

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, marque ou desmarque as **grade** botão.

   Você ainda pode controlar a grade no indivíduo **caixa de diálogo** janelas do editor usando o **ativar/desativar grade** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Para alterar o tamanho da grade de layout:

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, digite a altura e largura em DLUs para as células na grade. A largura ou altura mínima é 4 DLUs.

## <a name="selecting-controls"></a>Selecionando controles

Selecione controles para tamanho, alinhar, mover, copiar, ou excluí-los e, em seguida, concluir a operação desejada. Na maioria dos casos, você precisa selecionar mais de um controle para usar as ferramentas de dimensionamento e o alinhamento a [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Quando um controle for selecionado, ele tem uma borda sombreada em torno dele com sólida (ativa) ou vazios (inativo) "alças de dimensionamento" pequenos quadrados que aparecem na borda de seleção. Quando vários controles estiverem selecionados, o controle dominante tem alças de dimensionamento sólida e todos os outros controles selecionados tem alças de dimensionamento vazado.

Quando você estiver dimensionando ou alinhar vários controles, o **caixa de diálogo** editor usa o "controle dominante" para determinar como os outros controles são dimensionados ou alinhados. Por padrão, o controle dominante é o primeiro controle selecionado.

### <a name="to-select-multiple-controls"></a>Para selecionar vários controles

1. No [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o **ponteiro** ferramenta.

1. Use uma das etapas a seguir para fazer sua seleção:

   - Arraste o ponteiro para desenhar uma caixa de seleção ao redor dos controles que você deseja selecionar na caixa de diálogo. Quando você soltar o botão do mouse, todos os controles internos e interseção a caixa de seleção estiver marcada.

   - Mantenha pressionada a **Shift** da chave e selecione os controles que você deseja incluir na seleção.

   - Mantenha pressionada a **Ctrl** da chave e selecione os controles que você deseja incluir na seleção.

### <a name="to-remove-a-control-from-a-group-of-selected-controls-or-to-add-a-control-to-a-group-of-selected-controls"></a>Para remover um controle de um grupo de controles selecionados ou para adicionar um controle a um grupo de controles selecionados

Com um grupo de controles selecionados, mantenha pressionada a **Shift** da chave e selecione o controle que você deseja remover ou adicionar a seleção existente.

   > [!NOTE]
   > Manter pressionada a **Ctrl** chave e selecionando um controle dentro de uma seleção farão com que controlam o controle dominante nessa seleção.

### <a name="to-specify-the-dominant-control"></a>Para especificar o controle dominante

Mantenha pressionada a **Ctrl** da chave e selecione o controle que você deseja usar para influenciar o tamanho ou local de outros controles *primeiro*.

> [!NOTE]
> As alças de dimensionamento do controle dominante são sólidas, enquanto as alças dos controles subordinados são vazadas. Todos os ainda mais o redimensionamento ou alinhamento baseia-se no controle dominante.

### <a name="to-change-the-dominant-control"></a>Para alterar o controle dominante

1. Desmarque a seleção atual clicando fora de todos os controles atualmente selecionados.

1. Repita o procedimento anterior, selecionar um controle diferente pela primeira vez.

## <a name="sizing-controls"></a>Dimensionando controles

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as direções em que o controle pode ser redimensionado. Alças de dimensionamento do Active Directory são sólidas; Se uma alça de dimensionamento for vazia, o controle não pode ser redimensionado ao longo desse eixo.

Você também pode alterar o tamanho de um controle, ajuste o controle nas guias ou margens ou movendo um encaixada guia para longe do outro e controle.

### <a name="to-size-an-individual-control"></a>Para dimensionar um controle individual

1. Selecione o controle.

1. Arraste as alças de dimensionamento para alterar o tamanho do controle:

   - Alças de dimensionamento na parte superior e os lados alteram o tamanho horizontal ou vertical.

   - Alças de dimensionamento nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a **Shift** chave e usando o **seta para a direita** e **seta para baixo** chaves.

### <a name="to-automatically-size-a-control-to-fit-the-text-within-it"></a>Para dimensionar automaticamente um controle para se ajustar ao texto dentro dele

Escolher **tamanho ao conteúdo** da **formato** menu ou o controle com o botão direito e escolha **tamanho ao conteúdo** no menu de atalho.

### <a name="to-make-controls-the-same-width-height-or-size"></a>Para tornar controla a mesma largura, altura ou tamanho

Você pode redimensionar um grupo de controles com base no tamanho do controle dominante.

1. Selecione os controles que você deseja redimensionar.

   O controle selecionado primeiro da série é o controle dominante. O tamanho final dos controles no grupo depende do tamanho do controle dominante.

1. Dos **formato** menu, escolha **Igualar tamanho**, em seguida, escolha **ambos**, **altura**, ou **largura**.

### <a name="to-set-the-size-of-the-combo-box-and-its-drop-down-list"></a>Para definir o tamanho da caixa de combinação de caixa e sua lista suspensa

Quando você adicioná-lo à caixa de diálogo, você pode dimensionar uma caixa de combinação. Você também pode especificar o tamanho da caixa de listagem suspensa. Para obter mais informações, consulte [adicionando valores a um controle de caixa de combinação](../windows/adding-values-to-a-combo-box-control.md).

#### <a name="to-size-a-combo-box"></a>Para dimensionar uma caixa de combinação

1. Selecione o controle de caixa de combinação na caixa de diálogo.

   Inicialmente, apenas as alças de dimensionamento de direito e esquerdo estão ativos.

1. Use as alças de dimensionamento para definir a largura da caixa de combinação.

Você também pode definir o tamanho vertical da parte suspensa da caixa de combinação.

#### <a name="to-set-the-size-of-the-combo-box-drop-down-list"></a>Para definir o tamanho da caixa de combinação de lista suspensa da caixa

1. Selecione o botão de seta suspensa à direita da caixa de combinação.

   ![Seta em uma caixa de combinação em um projeto MFC](../mfc/media/vccomboboxarrow.gif "vcComboBoxArrow")

   O contorno do controle muda para mostrar o tamanho da caixa de combinação com a área de lista suspensa estendida.

1. Use a alça de dimensionamento inferior para alterar o tamanho inicial da área de lista suspensa.

   ![Caixa de combinação&#45;dimensionamento caixa em um projeto MFC](../mfc/media/vccomboboxsizing.gif "vcComboBoxSizing")

1. Selecione a seta suspensa novamente para fechar a parte da lista suspensa da caixa de combinação.

### <a name="to-set-the-width-of-a-horizontal-scroll-bar-and-make-it-appear"></a>Para definir a largura da barra de rolagem horizontal e fazer com que pareça

Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando classes do MFC, a barra de rolagem não aparecerá automaticamente no seu aplicativo.

Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código.

   Sem este conjunto de valores, a barra de rolagem não aparecerá, até mesmo quando os itens na caixa de listagem são mais largas do que a caixa.

## <a name="group-radio-buttons-on-a-dialog-box"></a>Grupo de botões de opção em uma caixa de diálogo

Quando você adiciona botões de opção para uma caixa de diálogo, tratá-los como um grupo, definindo um **grupo** propriedade no **propriedades** janela para o primeiro botão no grupo. Então, aparecerá uma ID de controle para esse botão de opção na [Assistente para adição de variável de membro](../ide/add-member-variable-wizard.md), permitindo que você adicione uma variável de membro para o grupo de botões de opção.

Você pode ter mais de um grupo de botões de opção em uma caixa de diálogo, e cada grupo deve ser adicionado usando o procedimento a seguir.

### <a name="to-add-a-group-of-radio-buttons-to-a-dialog-box"></a>Para adicionar um grupo de botões de opção para uma caixa de diálogo

1. Selecione o controle de botão de opção na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) e escolha o local na caixa de diálogo onde você deseja colocar o controle.

1. Repita a etapa 1 para adicionar botões de opção quantas forem necessárias. Certifique-se de que os botões de opção no grupo são consecutivos na ordem de tabulação.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **grupo** propriedade do *primeiro* botão de opção na ordem de tabulação para **True**.

   Alterando a **grupo** propriedade **verdadeiro** adiciona o estilo WS_GROUP a entrada do botão no objeto de caixa de diálogo do script de recurso e garante que um usuário pode selecionar apenas um botão de opção por vez no botão grupo (quando o usuário clica em um botão de opção, os outros no grupo estão desmarcados).

   > [!NOTE]
   > Somente o primeiro botão de opção no grupo deve ter o **grupo** propriedade definida como **verdadeiro**. Se você tiver controles adicionais que não fazem parte do grupo de botões, defina as **grupo** propriedade do primeiro controle *que está fora do grupo* para **verdadeiro** também. Você pode identificar rapidamente o primeiro controle fora do grupo pressionando **Ctrl**+**1!d** para exibir a ordem de tabulação.

### <a name="to-add-a-member-variable-for-the-radio-button-group"></a>Para adicionar uma variável de membro para o grupo de botões de opção

1. Clique com botão direito do controle de botão de rádio primeiro na ordem de tabulação (o controle dominante e aquele com o **grupo** propriedade definida como True).

1. Escolher **Adicionar variável** no menu de atalho.

1. No [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md), selecione o **variável de controle** caixa de seleção e, em seguida, selecione o **valor** botão de opção.

1. No **nome da variável** , digite um nome para a nova variável de membro.

1. No **tipo de variável** caixa de listagem, selecione **int** ou tipo `int`.

1. Agora você pode modificar seu código para especificar qual botão de opção deve aparecer selecionado. Por exemplo, `m_radioBox1 = 0;` seleciona o primeiro botão de opção no grupo.

## <a name="to-align-groups-of-controls"></a>Alinhar grupos de controles

1. Selecione os controles que você deseja alinhar. Certifique-se de selecionar o controle que você deseja ser o controle dominante pela primeira vez ou defini-lo para ser o controle dominante antes de executar o alinhamento ou comando de dimensionamento.

   A posição final do grupo de controles depende a posição do controle dominante. Para obter mais informações sobre como selecionar o controle dominante, consulte [especificando o controle dominante](../windows/specifying-the-dominant-control.md).

1. Dos **formato** menu, escolha **alinhar**e, em seguida, escolha uma das alinhamentos a seguir:

   |Valor|Descrição|
   |-----|-----------|
   |`Lefts`|Alinha os controles selecionados ao longo dos lados esquerdos.|
   |`Centers`|Alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.|
   |`Rights`|Alinha os controles selecionados ao longo dos lados direito.|
   |`Tops`|Alinha os controles selecionados ao longo de suas bordas na parte superior.|
   |`Middles`|Alinha os controles selecionados verticalmente ao longo de seus pontos intermediários.|
   |`Bottoms`|Alinha os controles selecionados ao longo de suas bordas inferior.|

### <a name="to-even-the-spacing-between-controls"></a>Para até mesmo o espaçamento entre controles

O **caixa de diálogo** editor permite que você espaçar os controles uniformemente entre os controles mais externos selecionados.

1. Selecione os controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **espaçar uniformemente**e, em seguida, escolha uma dos alinhamentos de espaçamento a seguir:

   - `Across`: espaço controles uniformemente entre os mais à esquerda e o controle mais à direita selecionado.

   - `Down`: espaço controles uniformemente entre o primeiro e o controle na extremidade inferior selecionado.

### <a name="to-center-controls-in-a-dialog-box"></a>Para centralizar os controles em uma caixa de diálogo

1. Selecione o controle ou controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **na caixa de diálogo Centro**e, em seguida, escolha uma das seguintes organizações:

   - `Vertical`: Centralizar controles verticalmente na caixa de diálogo.

   - `Horizontal`: Centralizar controles horizontalmente na caixa de diálogo.

### <a name="to-arrange-push-buttons-along-the-right-or-bottom-of-a-dialog-box"></a>Para organizar os botões de envio por push ao longo da direita ou inferior de uma caixa de diálogo

1. Selecione um ou mais botões de envio por push.

1. Dos **formato** menu, escolha **Organizar botões**e, em seguida, escolha uma das seguintes organizações:

   - `Right`: alinha os botões de envio por push ao longo da borda direita da caixa de diálogo.

   - `Bottom`: alinha os botões de envio por push ao longo da borda inferior da caixa de diálogo.

       Se você selecionar um controle que não seja um botão de envio por push, sua posição não é afetada.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)