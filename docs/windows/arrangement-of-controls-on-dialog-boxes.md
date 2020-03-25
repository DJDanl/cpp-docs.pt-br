---
title: 'Como: controles de layout (C++) | Microsoft Docs'
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
ms.openlocfilehash: ee732cfb414f011e95edbbb57b218d81179d44f3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168571"
---
# <a name="how-to-layout-controls-c"></a>Como: controles de layout (C++)

O **Editor de caixa de diálogo** fornece ferramentas de layout que alinham e dimensionam os controles automaticamente. Para a maioria das tarefas, você pode usar a [barra de ferramentas do editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md). Todos os comandos da barra de ferramentas do **Editor de caixa de diálogo** também estão disponíveis no menu **Formatar** e têm a maioria das [teclas de atalho](../windows/accelerator-keys-for-the-dialog-editor.md).

Muitos comandos de layout para caixas de diálogo estão disponíveis somente quando mais de um controle é selecionado. Você pode selecionar um único controle ou vários controles, e quando mais de um controle for selecionado, o primeiro que você selecionar será por padrão o controle dominante.

O local, a altura e a largura do controle atual são exibidos no canto inferior direito da barra de status. Quando a caixa de diálogo inteira for selecionada, a barra de status exibirá a posição da caixa de diálogo como um todo, e sua altura e largura.

## <a name="arrange-controls"></a>Organizar controles

Você pode organizar os controles nas caixas de diálogo com o **Editor de caixa de diálogo** em um dos três Estados diferentes:

- Com guias e margens em, defina como padrão.

- Com a grade de layout ativada.

- Sem nenhum recurso de ajuste ou alinhamento.

A [barra de ferramentas do editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md) contém botões que controlam o estado.

- Para alterar o estado, selecione o ícone apropriado ou vá para o **formato** do menu > **configurações do guia**.

A caixa de diálogo **configurações do guia** tem as seguintes propriedades:

|Propriedade|DESCRIÇÃO|
|---|---|
|**Guias de layout**|Exibe as configurações para os guias de layout.|
|**Nenhuma**|Oculta as ferramentas de layout.|
|**Réguas e guias**|Quando habilitada, o adiciona réguas às ferramentas de layout e permite que os guias sejam colocados nas réguas. Os guias padrão são as margens.|
|**Grade**|Cria uma grade de layout. Os novos controles serão alinhados automaticamente à grade.|
|**Espaçamento da grade**|Exibe as configurações para o espaçamento de grade nas unidades da caixa de diálogo (DLUs).|
|**Largura: DLUs**|Define a largura da grade de layout em DLUs. Um DLU horizontal é a largura média da fonte da caixa de diálogo dividida por 4.|
|**Altura: DLUs**|Define a altura da grade de layout em DLUs. Um DLU vertical é a altura média da fonte da caixa de diálogo dividida por 8.|

### <a name="guides-and-margins"></a>Guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias e margens podem ajudá-lo a alinhar controles com precisão dentro de uma caixa de diálogo.

Quando você cria uma caixa de diálogo, quatro guias modificadas chamadas margens são fornecidas e aparecem como linhas pontilhadas azuis.

- Para mover as margens, arraste a margem para a nova posição.

- Para fazer uma margem desaparecer, mova a margem para uma posição zero.

- Para retornar a margem, coloque o ponteiro sobre a posição zero da margem e mova a margem para a posição.

Os guias aparecem como linhas pontilhadas azuis na caixa de diálogo exibida no editor e nas setas correspondentes nas réguas na parte superior e no lado esquerdo do editor da **caixa de diálogo**. Os identificadores de dimensionamento dos controles se ajustam aos guias quando os controles são movidos e os guias se ajustam aos controles se não houver controles previamente encaixados no guia. Quando um guia é movido, os controles que são ajustados para ele também são movidos. Controles encaixados em mais de um guia são redimensionados quando um dos guias é movido.

- Para criar um guia dentro da régua, selecione uma vez para criar um guia ou clique duas vezes para iniciar a caixa de diálogo **configurações do guia** , onde você pode especificar as configurações do guia.

- Para definir um guia na caixa de diálogo, selecione o guia e arraste-o para uma nova posição ou selecione a seta na régua para arrastar o guia associado.

   As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua ou mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.

- Para excluir um guia, arraste o guia para fora da caixa de diálogo ou arraste a seta correspondente para fora da régua.

As marcas de escala nas réguas que determinam o espaçamento de guias e controles são definidas por unidades de caixa de diálogo (DLUs). Um DLU é baseado no tamanho da fonte da caixa de diálogo, normalmente MS Shell de 8 pontos Dlg. Um DLU horizontal é a largura média da fonte da caixa de diálogo dividida por quatro. Um DLU vertical é a altura média da fonte dividida por 8.

- Para alterar os intervalos das marcas de escala, vá para **formato** de menu > **configurações do guia**e, em seguida, no campo **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

### <a name="layout-grid"></a>Grade de layout

Quando você estiver colocando ou Organizando controles em uma caixa de diálogo, use a grade de layout para um posicionamento mais preciso. Quando a grade for ativada, os controles se ajustarão às linhas pontilhadas da grade como se estiverem magnetizados.

- Para ativar ou desativar a grade de layout, vá para **formato** de menu > **configurações de guia** e marque ou desmarque o botão de **grade** .

   Você ainda pode controlar a grade em janelas de **Editor de caixa de diálogo** individuais usando o botão **Alternar grade** na barra de ferramentas do editor de caixa de [diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

- Para alterar o tamanho da grade de layout, vá para **formato** de menu > **configurações de guia** e digite a altura e a largura em DLUs para as células na grade. A altura ou largura mínima é 4.

### <a name="disable-guides"></a>Desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito de ajuste dos guias. O uso da tecla **ALT** desabilita os efeitos de ajuste do guia selecionado. Mover um guia com a tecla **Shift** impede que controles encaixados se movam com o guia.

- Para desabilitar o efeito de ajuste dos guias, arraste o controle enquanto mantém a tecla **ALT** pressionada.

- Para mover os guias sem mover os controles encaixados, arraste o guia enquanto mantém a tecla **Shift** pressionada.

- Para desativar os guias, vá para **formato** de menu > **configurações do guia**. Em seguida, em **guias de layout**, selecione **nenhum**.

   > [!TIP]
   > Você também pode usar o atalho no **formato** de menu > **guias de alternância**.

## <a name="select-controls"></a>Selecionar controles

Selecione controles para dimensionar, alinhar, mover, copiar ou excluí-los e, em seguida, conclua a operação desejada. Na maioria dos casos, você precisa selecionar mais de um controle para usar as ferramentas de dimensionamento e alinhamento na [barra de ferramentas do editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Quando um controle é selecionado, ele tem uma borda sombreada em torno dele com identificadores de dimensionamento sólidos (ativos) ou vazios (inativos), pequenos quadrados que aparecem na borda de seleção. Quando vários controles são selecionados, o controle dominante tem identificadores de dimensionamento sólidos e todos os outros controles selecionados têm identificadores de dimensionamento vazios.

- Para selecionar controles, na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione a ferramenta **ponteiro** e use uma das seguintes etapas para fazer sua seleção:

  - Arraste o ponteiro para desenhar uma caixa de seleção em volta dos controles que você deseja selecionar na caixa de diálogo. Quando você libera o botão do mouse, todos os controles dentro e interseção da caixa de seleção são selecionados.

  - Mantenha pressionada a tecla **Shift** e selecione os controles que você gostaria de incluir na seleção.

  - Mantenha pressionada a tecla **Ctrl** e selecione os controles que você gostaria de incluir na seleção.

- Para adicionar ou remover um controle do grupo de controles selecionados, mantenha pressionada a tecla **Shift** e selecione o controle que deseja adicionar ou remover.

### <a name="dominant-controls"></a>Controles dominantes

Quando você está dimensionando ou alinhando vários controles, o **Editor da caixa de diálogo** usa o controle dominante para determinar como os outros controles são dimensionados ou alinhados. Por padrão, o controle dominante é o primeiro controle selecionado.

- Para especificar o controle dominante, mantenha pressionada a tecla **Ctrl** e selecione o controle que você deseja usar para influenciar o tamanho ou o local de outros controles *primeiro*. Manter pressionada a tecla **Ctrl** e selecionar um controle dentro de uma seleção também fará com que controle o controle dominante nessa seleção.

- Para alterar o controle dominante, desmarque a seleção atual selecionando fora de todos os controles selecionados no momento e repita o procedimento acima, selecionando um controle diferente *primeiro*.

> [!NOTE]
> Os identificadores de dimensionamento do controle dominante são sólidos enquanto os identificadores de controles subordinados são vazados. Todo o redimensionamento ou alinhamento adicional baseia-se no controle dominante.

## <a name="size-controls"></a>Controles de tamanho

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro é posicionado em uma alça de dimensionamento, ele altera a forma para indicar as direções em que o controle pode ser redimensionado. As alças de dimensionamento ativas são sólidas e, se um identificador de dimensionamento for vazado, o controle não poderá ser redimensionado ao longo desse eixo.

- Para dimensionar um controle, selecione o controle e arraste as alças de dimensionamento para alterar o tamanho.

  - As alças de tamanho na parte superior e nos lados alteram o tamanho horizontal ou vertical.

  - As alças de tamanho nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar o controle uma unidade de caixa de diálogo (DLU) de cada vez mantendo a tecla **Shift** pressionada e usando as teclas de seta para a **direita** e **para baixo** .

- Para dimensionar automaticamente um controle para se ajustar ao texto dentro dele, vá para o **formato** de menu ou clique com o botão direito do mouse no controle e escolha **tamanho para conteúdo**.

- Para tornar os controles do mesmo tamanho, selecione os controles que você deseja redimensionar e vá para o **formato** do menu > **igualar o mesmo tamanho**, escolha **ambos**, **altura**ou **largura**.

   Você redimensiona um grupo de controles com base no tamanho do controle dominante, que é o controle selecionado primeiro na série. O tamanho final dos controles no grupo depende do tamanho do controle dominante.

- Para dimensionar um grupo de controles com guias, ajuste um lado do controle (ou controles) para um guia e, em seguida, arraste um guia para o outro lado do controle (ou controles). Agora você pode mover qualquer guia para dimensionar o controle (ou controles).

   Se necessário, com vários controles, dimensione cada um para se ajustar ao segundo guia.

### <a name="other-controls"></a>Outros controles

Você pode dimensionar uma caixa de combinação ao adicioná-la à caixa de diálogo. Você também pode especificar o tamanho da caixa de listagem suspensa. Para obter mais informações, consulte [Adicionando valores a um controle caixa de combinação](../windows/adding-values-to-a-combo-box-control.md).

1. Selecione o botão de seta suspensa à direita da caixa de combinação.

   ![Seta em uma caixa de combinação em um projeto do MFC](../mfc/media/vccomboboxarrow.gif "vcComboBoxArrow")

   O contorno do controle é alterado para mostrar o tamanho da caixa de combinação com a área de lista suspensa estendida.

1. Use a alça de dimensionamento inferior para alterar o tamanho inicial da área da lista suspensa.

   ![Dimensionamento da caixa de combinação&#45;em um projeto do MFC](../mfc/media/vccomboboxsizing.gif "vcComboBoxSizing")

1. Selecione a seta suspensa novamente para fechar a parte da lista suspensa da caixa de combinação.

> [!NOTE]
> Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal a uma caixa de diálogo usando o MFC, a barra de rolagem não aparecerá automaticamente em seu aplicativo.
>
> Defina uma largura máxima para o elemento mais largo chamando [CListBox:: SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código. Sem esse valor definido, a barra de rolagem não aparecerá, mesmo quando os itens na caixa de listagem forem mais largos do que a caixa.

## <a name="align-controls"></a>Alinhar controles

- Para alinhar controles, selecione os controles que você deseja alinhar. Vá para o **formato** de menu > **alinhar** e escolha um dos seguintes alinhamentos:

   |Alinhamento|DESCRIÇÃO|
   |-----|-----------|
   |**Esquerdas**|Alinha os controles selecionados ao longo de seus lados à esquerda.|
   |**Centrais**|Alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.|
   |**Direitos**|Alinha os controles selecionados ao longo de seus lados à direita.|
   |**Tops**|Alinha os controles selecionados ao longo de suas bordas superiores.|
   |**Meios**|Alinha os controles selecionados verticalmente ao longo de seus pontos centrais.|
   |**Partes inferiores**|Alinha os controles selecionados ao longo de suas bordas inferiores.|

   Certifique-se de selecionar o controle que você deseja que seja dominante primeiro ou defini-lo como o controle dominante antes de executar o alinhamento ou o comando de dimensionamento, uma vez que a posição final do grupo de controles depende da posição do controle dominante.

- Para os controles de espaço uniforme, selecione os controles que você deseja reorganizar. Vá para o **formato** de menu > **espaço uniformemente** e escolha um dos seguintes alinhamentos de espaçamento:

   |Spacing|DESCRIÇÃO|
   |---|---|
   |**Via**|Os controles de espaço uniformemente entre a mais à esquerda e o controle mais à direita selecionados.|
   |**Para baixo**|Os controles de espaço uniformemente entre o primeiro e o controle na extremidade inferior selecionados.|

- Para centralizar controles, selecione o controle ou os controles que você deseja reorganizar. Vá para o **formato** de menu > **central na caixa de diálogo** e escolha uma das seguintes disposições:

   |Disposição|DESCRIÇÃO|
   |---|---|
   |**Vertical**|Centralizar controles verticalmente na caixa de diálogo.|
   |**Horizontal**|Centralizar controles horizontalmente na caixa de diálogo.|

- Para alinhar botões de push, selecione um ou mais botões de ação. Vá para o **formato** de menu > **organizar botões**e, em seguida, escolha uma das seguintes disposições:

   |Disposição|DESCRIÇÃO|
   |---|---|
   |**Right**|Alinha os botões de ação ao longo da borda direita da caixa de diálogo.|
   |**Inferior**|Alinha os botões de ação ao longo da borda inferior da caixa de diálogo.|

   Se você selecionar um controle que não seja um botão de ação, sua posição não será afetada.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Gerenciar controles da caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: Adicionar, editar ou excluir controles](adding-editing-or-deleting-controls.md)<br/>
[Como definir o acesso e os valores de controle](defining-mnemonics-access-keys.md)<br/>
