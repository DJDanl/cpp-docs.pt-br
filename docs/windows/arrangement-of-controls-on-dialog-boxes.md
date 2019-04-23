---
title: 'Como: Controles de layout (C++) | Microsoft Docs'
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
ms.openlocfilehash: 878b7371dfa77880d68f1001444ed44b84d7240c
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037415"
---
# <a name="how-to-layout-controls-c"></a>Como: Controles de layout (C++)

O **Editor de caixa de diálogo** fornece ferramentas de layout que se alinham e dimensionar automaticamente os controles. Para a maioria das tarefas, você pode usar o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md). Todos os **Editor de caixa de diálogo** comandos da barra de ferramentas também estão disponíveis na **formato** menu e a maioria tem [teclas de atalho](../windows/accelerator-keys-for-the-dialog-editor.md).

Muitos comandos de layout para caixas de diálogo estão disponíveis somente quando mais de um controle é selecionado. Você pode selecionar um controle único ou vários controles, e quando mais de um controle é selecionado, a primeira é que você selecione é, por padrão, o controle dominante.

O local, altura e largura do controle atual são exibidos no canto inferior direito da barra de status. Quando a caixa de diálogo inteira é selecionada, a barra de status exibe a posição da caixa de diálogo como um todo e sua altura e largura.

## <a name="arrange-controls"></a>Organizar os controles

Você pode organizar controles em caixas de diálogo com o **Editor de caixa de diálogo** em um dos três estados diferentes:

- Com guias e margens em, defina como padrão.

- Com a grade de layout no.

- Sem nenhum recurso de ajuste ou alinhamento.

O [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md) contém botões que controlam o estado.

- Para alterar o estado, selecione o ícone apropriado, ou vá para o menu **formato** > **guia Configurações**.

O **guia de configurações** caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Guias de layout**|Exibe as configurações das guias de layout.|
|**Nenhum**|Oculta as ferramentas de layout.|
|**Réguas e guias**|Quando habilitada, adiciona as réguas para as ferramentas de layout e permite que os guias a serem colocados nas réguas. Os guias padrão são as margens.|
|**Grade**|Cria uma grade de layout. Novos controles são alinhados automaticamente à grade.|
|**Espaçamento da grade**|Exibe as configurações para o espaçamento da grade em unidades de caixa de diálogo (DLUs).|
|**Largura: DLUs**|Define a largura da grade de layout em DLUs. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por 4.|
|**Altura: DLUs**|Define a altura da grade de layout em DLUs. Um DLU vertical é a média altura da fonte de caixa de diálogo dividida por 8.|

### <a name="guides-and-margins"></a>Guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias e margens podem ajudar a alinhar controles com precisão dentro de uma caixa de diálogo.

Quando você cria uma caixa de diálogo, quatro guias modificadas chamadas margens são fornecidas e aparecem como linhas pontilhadas azuis.

- Para mover as margens, arraste a margem para a nova posição.

- Para tornar uma margem desaparecer, mova a margem para uma posição zero.

- Para trazer de volta a margem, coloque o ponteiro sobre a margem posição zero e mover a margem para a posição.

Guias são exibidas como azul pontilhada entre a caixa de diálogo exibida no editor e setas correspondentes nas réguas na parte superior e o lado esquerdo dos **Editor de caixa de diálogo**. As alças de dimensionamento de controles de ajustam-se às guias de quando os controles são movidos e guias de ajustam-se aos controles se não houver nenhum controle ajustado anteriormente para o guia. Quando um guia é movido, controles que são ajustados para que ele é mover também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.

- Para criar uma guia dentro da régua, selecione uma vez para criar uma guia ou clique duas vezes para iniciar o **guia de configurações** caixa de diálogo onde você pode especificar as configurações da guia.

- Para definir um guia na caixa de diálogo, selecione o guia e arraste-o para uma nova posição ou selecione a seta na régua à arraste a guia associada.

   As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua da ou mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.

- Para excluir uma guia, arraste a guia fora da caixa de diálogo ou arraste a seta correspondente fora da régua.

As marcas de escala em que determinam o espaçamento entre controles e guias de réguas são definidas pelas unidades de caixa de diálogo (DLUs). Um DLU baseia-se no tamanho da fonte de caixa de diálogo, normalmente de 8 pontas MS Shell Dlg. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro. Um DLU vertical é a média altura da fonte dividida por 8.

- Para alterar os intervalos das marcas de escala, vá ao menu **formato** > **configurações da guia**, em seguida, no **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

### <a name="layout-grid"></a>Grade de layout

Quando você está colocando ou organizar controles em uma caixa de diálogo, use a grade de layout para um posicionamento mais preciso. Quando a grade é ativada, controles serão ajustado para as linhas pontilhadas da grade, como se magnetizada.

- Para ativar ou desativar a grade de layout, vá ao menu **formato** > **configurações da guia** e marque ou desmarque o **grade** botão.

   Você ainda pode controlar a grade no indivíduo **Editor de caixa de diálogo** windows usando o **ativar/desativar grade** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

- Para alterar o tamanho da grade de layout, vá ao menu **formato** > **guia Configurações** e digite a altura e largura DLUs para as células na grade. A largura ou altura mínima é 4.

### <a name="disable-guides"></a>Desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito dos guias de ajuste. Usando o **Alt** chave desativa os efeitos de ajuste do guia selecionada. Movendo um guia com o **Shift** chave impede que os controles sem-instantâneo movendo com o guia.

- Para desabilitar o efeito de ajuste dos guias, arraste o controle enquanto mantém pressionada a **Alt** chave.

- Para mover guias sem mover os controles encaixados, arraste o guia enquanto mantém pressionada a **Shift** chave.

- Para desativar os guias, vá ao menu **formato** > **guia Configurações**. Em seguida, em **guias de Layout**, selecione **None**.

   > [!TIP]
   > Você também pode usar o atalho no menu **formato** > **ativar/desativar guias**.

## <a name="select-controls"></a>Selecionar controles

Selecione controles para tamanho, alinhar, mover, copiar, ou excluí-los e, em seguida, concluir a operação desejada. Na maioria dos casos, você precisa selecionar mais de um controle para usar as ferramentas de dimensionamento e o alinhamento a [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Quando um controle é selecionado, ele tem uma borda sombreada em torno de com o sólido (ativa) ou vazios (inativo) alças, pequenos quadrados que aparecem na borda de seleção de dimensionamento. Quando vários controles estiverem selecionados, o controle dominante tem alças de dimensionamento sólida e todos os outros controles selecionados tem alças de dimensionamento vazado.

- Para selecionar os controles, nos [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o **ponteiro** de ferramentas e use uma das etapas a seguir para fazer sua seleção:

  - Arraste o ponteiro para desenhar uma caixa de seleção ao redor dos controles que você deseja selecionar na caixa de diálogo. Quando você soltar o botão do mouse, todos os controles internos e interseção a caixa de seleção estiver marcada.

  - Mantenha pressionada a **Shift** da chave e selecione os controles que você deseja incluir na seleção.

  - Mantenha pressionada a **Ctrl** da chave e selecione os controles que você deseja incluir na seleção.

- Para adicionar ou remover um controle do grupo de controles selecionados, mantenha pressionada a **Shift** da chave e selecione o controle que você deseja adicionar ou remover.

### <a name="dominant-controls"></a>Controles dominantes

Quando você estiver dimensionando ou alinhar vários controles, o **Editor de caixa de diálogo** usa o controle dominante para determinar como os outros controles são dimensionados ou alinhados. Por padrão, o controle dominante é o primeiro controle selecionado.

- Para especificar o controle dominante, mantenha pressionada a **Ctrl** da chave e selecione o controle que você deseja usar para influenciar o tamanho ou local de outros controles *primeiro*. Manter pressionada a **Ctrl** chave e selecionando um controle dentro de uma seleção também farão com que controlam o controle dominante nessa seleção.

- Para alterar o controle dominante, desmarque a seleção atual selecionando fora de todos os controles selecionados no momento e repita o procedimento acima, selecionando um controle diferente *primeiro*.

> [!NOTE]
> As alças de dimensionamento do controle dominante são sólidas, enquanto as alças dos controles subordinados são vazadas. Todos os ainda mais o redimensionamento ou alinhamento baseia-se no controle dominante.

## <a name="size-controls"></a>Controles de tamanho

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as direções em que o controle pode ser redimensionado. Alças de dimensionamento do Active Directory são sólidas e se uma alça de dimensionamento for vazia, o controle não pode ser redimensionado ao longo desse eixo.

- Para dimensionar um controle, selecione o controle e arraste as alças de dimensionamento para alterar o tamanho.

  - Identificadores de tamanho na parte superior e os lados alteram o tamanho horizontal ou vertical.

  - Identificadores de tamanho nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a **Shift** chave e usando o **direita** e **para baixo** teclas de direção.

- Para dimensionar automaticamente um controle para se ajustar ao texto dentro dela, vá ao menu **formato** ou o controle com o botão direito e escolha **tamanho ao conteúdo**.

- Para tornar controles do mesmo tamanho, selecione os controles que você deseja redimensionar e vá para o menu **formato** > **Igualar tamanho**, em seguida, escolha **ambos**, **Altura**, ou **largura**.

   Você redimensionar um grupo de controles com base no tamanho do controle dominante, que é o controle selecionado primeiro da série. O tamanho final dos controles no grupo depende do tamanho do controle dominante.

- Para dimensionar um grupo de controles com guias, ajuste de um dos lados do controle (ou controles) a uma guia e arraste um guia para o outro lado do controle (ou controles). Agora você pode mover um guia para dimensionar o controle (ou controles).

   Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.

### <a name="other-controls"></a>Outros controles

Quando você adicioná-lo à caixa de diálogo, você pode dimensionar uma caixa de combinação. Você também pode especificar o tamanho da caixa de listagem suspensa. Para obter mais informações, consulte [adicionando valores a um controle de caixa de combinação](../windows/adding-values-to-a-combo-box-control.md).

1. Selecione o botão de seta suspensa à direita da caixa de combinação.

   ![Seta em uma caixa de combinação em um projeto MFC](../mfc/media/vccomboboxarrow.gif "vcComboBoxArrow")

   O contorno do controle muda para mostrar o tamanho da caixa de combinação com a área de lista suspensa estendida.

1. Use a alça de dimensionamento inferior para alterar o tamanho inicial da área de lista suspensa.

   ![Caixa de combinação&#45;dimensionamento caixa em um projeto MFC](../mfc/media/vccomboboxsizing.gif "vcComboBoxSizing")

1. Selecione a seta suspensa novamente para fechar a parte da lista suspensa da caixa de combinação.

> [!NOTE]
> Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando o MFC, a barra de rolagem não aparecem automaticamente em seu aplicativo.
>
> Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código. Sem este conjunto de valores, a barra de rolagem não aparecerá, até mesmo quando os itens na caixa de listagem são mais largas do que a caixa.

## <a name="align-controls"></a>Alinhar controles

- Para alinhar controles, selecione os controles que você deseja alinhar. Vá ao menu **formato** > **alinhar** e escolha uma das alinhamentos a seguir:

   |Alinhamento|Descrição|
   |-----|-----------|
   |**À esquerda**|Alinha os controles selecionados ao longo dos lados esquerdos.|
   |**Centros**|Alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.|
   |**Direitos**|Alinha os controles selecionados ao longo dos lados direito.|
   |**Partes superiores**|Alinha os controles selecionados ao longo de suas bordas na parte superior.|
   |**Meios**|Alinha os controles selecionados verticalmente ao longo de seus pontos intermediários.|
   |**Partes inferiores**|Alinha os controles selecionados ao longo de suas bordas inferior.|

   Certifique-se de selecionar o controle que você deseja ser dominante pela primeira vez ou defini-lo para ser o controle dominante antes de executar o alinhamento ou comando de dimensionamento, como a posição final do grupo de controles depende da posição do controle dominante.

- A uniformemente controles de espaço, selecione os controles que você deseja reorganizar. Vá ao menu **formato** > **espaçar uniformemente** e escolha uma dos alinhamentos de espaçamento a seguir:

   |Espaçamento|Descrição|
   |---|---|
   |**Entre**|Controles de espaço uniformemente entre os mais à esquerda e o controle mais à direita selecionado.|
   |**Para baixo**|Controles de espaço uniformemente entre o primeiro e o controle na extremidade inferior selecionado.|

- Para centralizar os controles, selecione o controle ou controles que você deseja reorganizar. Vá ao menu **formato** > **na caixa de diálogo Centro** e escolha uma das seguintes organizações:

   |Disposição|Descrição|
   |---|---|
   |**Vertical**|Centralizar os controles verticalmente na caixa de diálogo.|
   |**Horizontal**|Centralizar controles horizontalmente na caixa de diálogo.|

- Para alinhar os botões de ação, selecione um ou mais botões de envio por push. Vá ao menu **formato** > **Organizar botões**, em seguida, escolha uma das seguintes organizações:

   |Disposição|Descrição|
   |---|---|
   |**Direita**|Alinha os botões de envio por push ao longo da borda direita da caixa de diálogo.|
   |**Inferior**|Alinha os botões de envio por push ao longo da borda inferior da caixa de diálogo.|

   Se você selecionar um controle que não seja um botão de envio por push, sua posição não é afetada.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Gerenciar controles de caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md)<br/>
[Como: Definir acesso e valores de controle](defining-mnemonics-access-keys.md)<br/>