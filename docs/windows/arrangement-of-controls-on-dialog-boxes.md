---
title: Organização de controles em caixas de diálogo (C++) | Microsoft Docs
ms.date: 11/04/2016
f1_keywords:
- vc.editors.dialog.grouping
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
ms.assetid: 832491cf-98af-42e5-a854-2cb135fd45c6
ms.openlocfilehash: 210fbf8e062b4dd8c469f9c40a015bbc19bc2843
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152736"
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

#### <a name="to-size-a-group-of-controls-with-guides"></a>Para dimensionar um grupo de controles com guias

1. Ajuste um dos lados do controle (ou controles) a uma guia.

1. Arraste um guia para o outro lado do controle (ou controles).

   Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.

1. Mova um guia para dimensionar o controle (ou controles).

#### <a name="to-change-the-intervals-of-the-tick-marks"></a>Alterar os intervalos das marcas de escala

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** na caixa de **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

### <a name="disable-guides"></a>Desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito dos guias de ajuste. Usando o **Alt** chave desativa os efeitos de ajuste do guia selecionada. Movendo um guia com o **Shift** chave impede que os controles sem-instantâneo movendo com o guia.

#### <a name="to-disable-the-snapping-effect-of-the-guides"></a>Para desabilitar o efeito dos guias de ajuste

Arraste o controle enquanto mantém pressionada a **Alt** chave.

#### <a name="to-move-guides-without-moving-the-snapped-controls"></a>Para mover guias sem mover os controles sem-instantâneo

Arraste a guia enquanto mantém pressionada a **Shift** chave.

#### <a name="to-turn-off-the-guides"></a>Para desativar os guias

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo **guias de Layout**, selecione **None**.

   > [!NOTE]
   > Você também pode clicar duas vezes a barra de régua para acessar o **guia de configurações** caixa de diálogo.

\- ou -

Sobre o **formato** menu, selecione **ativar/desativar guias**.

### <a name="modify-the-layout-grid"></a>Modificar a grade de layout

Quando você está colocando ou Organizando controles em uma caixa de diálogo, você pode usar a grade de layout para um posicionamento mais preciso. Quando a grade é ativada, os controles aparecem para "ajustar-se às" as linhas pontilhadas da grade como se magnetizada. Você pode ativar e desativar a esse recurso de "Ajustar à grade" e alterar o tamanho das células da grade de layout.

#### <a name="to-turn-the-layout-grid-on-or-off"></a>Para ativar ou desativar a grade de layout

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, marque ou desmarque as **grade** botão.

   Você ainda pode controlar a grade no indivíduo **caixa de diálogo** janelas do editor usando o **ativar/desativar grade** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

#### <a name="to-change-the-size-of-the-layout-grid"></a>Para alterar o tamanho da grade de layout

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, digite a altura e largura em DLUs para as células na grade. A largura ou altura mínima é 4 DLUs.

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

## <a name="align-groups-of-controls"></a>Alinhar grupos de controles

Os procedimentos a seguir mostram como alinhar controles:

### <a name="to-align-groups-of-controls"></a>Alinhar grupos de controles

1. [Selecione os controles](../windows/selecting-multiple-controls.md) você deseja alinhar. Certifique-se de selecionar o controle que você deseja ser o controle dominante pela primeira vez ou defini-lo para ser o controle dominante antes de executar o alinhamento ou comando de dimensionamento.

   A posição final do grupo de controles depende a posição do controle dominante. Para obter mais informações sobre como selecionar o controle dominante, consulte [especificando o controle dominante](../windows/specifying-the-dominant-control.md).

1. Dos **formato** menu, escolha **alinhar**e, em seguida, escolha uma das alinhamentos a seguir:

   - `Lefts`: alinha os controles selecionados ao longo dos lados esquerdos.

   - `Centers`: alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.

   - `Rights`: alinha os controles selecionados ao longo dos lados direito.

   - `Tops`: alinha os controles selecionados ao longo de suas bordas na parte superior.

   - `Middles`: alinha os controles selecionados verticalmente ao longo de seus pontos intermediários.

   - `Bottoms`: alinha os controles selecionados ao longo de suas bordas inferior.

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

## <a name="change-the-tab-order-of-controls"></a>Alterar a ordem de tabulação dos controles

A ordem de tabulação é a ordem na qual o **guia** tecla move o foco de entrada de um controle para o próximo dentro de uma caixa de diálogo. Normalmente, a ordem de tabulação prossegue da esquerda para a direita e de cima para baixo em uma caixa de diálogo. Cada controle tem um **Tabstop** propriedade que determina se um controle recebe foco de entrada.

### <a name="to-set-input-focus-for-a-control"></a>Para definir o foco de entrada para um controle

No [janela de propriedades](/visualstudio/ide/reference/properties-window), selecione **verdadeiro** ou **False** no **Tabstop** propriedade.

Até mesmo os controles que não têm o **Tabstop** propriedade definida como **verdadeiro** precisam fazer parte da ordem de tabulação. Ordem de tabulação é importante, por exemplo, quando você [definir chaves de acesso (mnemônicos)](../windows/defining-mnemonics-access-keys.md) para controles que não têm legendas. Texto estático que contém uma chave de acesso para um controle relacionada deve preceder imediatamente o controle relacionado na ordem de tabulação.

> [!NOTE]
> Se a caixa de diálogo contém controles sobrepostos, alterando a ordem de tabulação pode alterar a maneira como os controles são exibidos. Controles que acompanham a ordem de tabulação são sempre exibidos na parte superior de todos os controles sobrepostos que precedem-os na ordem de tabulação.

### <a name="to-view-the-current-tab-order-for-all-controls-in-a-dialog-box"></a>Para exibir a ordem de tabulação para todos os controles em uma caixa de diálogo

Sobre o **formato** menu, selecione **ordem de tabulação**.

\- ou -

- Pressione **Ctrl** + **1!d**.

### <a name="to-change-the-tab-order-for-all-controls-in-a-dialog-box"></a>Para alterar a ordem de tabulação para todos os controles em uma caixa de diálogo

1. Sobre o **formato** menu, selecione **ordem de tabulação**.

   Um número no canto superior esquerdo de cada controle mostra seu lugar na ordem de tabulação atual.

1. Definir a ordem de tabulação, clicando em cada controle na ordem em que você deseja que o **guia** chave a seguir.

1. Pressione **Enter** para sair **ordem de tabulação** modo.

   > [!TIP]
   > Depois de digitar **ordem de tabulação** modo, você pode pressionar **Esc** ou **Enter** para desabilitar a capacidade de alterar a ordem de tabulação.

### <a name="to-change-the-tab-order-for-two-or-more-controls"></a>Para alterar a ordem de tabulação para dois ou mais controles

1. Dos **formato** menu, escolha **ordem de tabulação**.

1. Especifique onde começará a alteração na ordem. Primeiro, mantenha pressionada a **Ctrl** da chave, selecione o controle e selecione aquele em que você deseja a ordem alterada para começar.

   Por exemplo, se você quiser alterar a ordem dos controles `7` por meio `9`, mantenha pressionada **Ctrl**, em seguida, selecione o controle `6` primeiro.

   > [!NOTE]
   > Para definir um controle específico para número `1` (primeiro na ordem de tabulação), clique duas vezes no controle.

1. Versão de **Ctrl** da chave, em seguida, selecione os controles na ordem em que você deseja que o **guia** chave a serem seguidos a partir desse ponto.

1. Pressione **Enter** para sair **ordem de tabulação** modo.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)