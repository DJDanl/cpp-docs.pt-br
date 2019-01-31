---
title: Estados do Editor de caixa de diálogo (guias e grades) (C++)
ms.date: 11/04/2016
helpviewer_keywords:
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
ms.assetid: dbacf9ef-e8b0-4125-a7ce-84911c482e98
ms.openlocfilehash: 52fc19d8a39680c16692177e2758fba78afc7d3a
ms.sourcegitcommit: 5270117dbecc4c49bca0cf10b927bae3c9930038
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/31/2019
ms.locfileid: "55484988"
---
# <a name="dialog-editor-states-guides-and-grids-c"></a>Estados do Editor de caixa de diálogo (guias e grades) (C++)

Você pode organizar controles em caixas de diálogo com o **caixa de diálogo** editor em um dos três estados diferentes:

- Com os guias e margens em (configuração padrão)

- Com a grade de layout no

- Sem nenhum recurso de ajuste ou de alinhamento

O [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md) contém botões que controlam o estado. Para alterar o estado, clique no ícone apropriado. Você também pode alterar estados usando o **configurações da guia** comando as **formato** menu.

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

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="create-and-set-guides-and-margins"></a>Crie e defina os guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias de podem ajudar a alinhar controles com precisão dentro de uma caixa de diálogo. Guias são exibidas como azul pontilhada entre a caixa de diálogo exibida no editor e setas correspondentes nas réguas na parte superior e o lado esquerdo dos **caixa de diálogo** editor.

Quando você cria uma caixa de diálogo, são fornecidas as quatro margens. As margens são modificadas guias, que aparecem como linhas pontilhadas azuis.

### <a name="to-create-a-guide"></a>Para criar uma guia

Dentro da régua, clique uma vez para criar uma guia. (Um clique cria uma nova guia; clicar duas vezes em inicializações a **configurações da guia** caixa de diálogo na qual você pode especificar configurações do guia.)

### <a name="to-set-a-guide"></a>Para definir um guia

Na caixa de diálogo, clique na guia e arraste-o para uma nova posição. (Você também pode clicar na seta na régua à arraste a guia associada).

As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua. Mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.

### <a name="to-delete-a-guide"></a>Para excluir uma guia

Arraste a guia fora da caixa de diálogo.

\- ou -

Arraste a seta correspondente fora da régua.

### <a name="to-move-margins"></a>Para mover as margens

Arraste a margem para a nova posição.

Para tornar uma margem desaparecer, mova a margem para uma posição zero. Para trazer de volta a margem, coloque o ponteiro sobre a margem posição zero e mover a margem para a posição.

## <a name="align-controls-on-a-guide"></a>Alinhar controles em um guia

As alças de dimensionamento de controles de ajustam-se às guias de quando os controles são movidos e guias de ajustam-se aos controles se não houver nenhum controle ajustado anteriormente para o guia. Quando um guia é movido, controles que são ajustados para que ele é mover também. Ajustado para mais de um guia de controles são redimensionados quando um dos guias é movido.

As marcas de escala em que determinam o espaçamento entre controles e guias de réguas são definidas pelas unidades de caixa de diálogo (DLUs). Um DLU baseia-se no tamanho da fonte de caixa de diálogo, normalmente de 8 pontas MS Shell Dlg. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro. Um DLU vertical é a média altura da fonte dividida por oito.

### <a name="to-size-a-group-of-controls-with-guides"></a>Para dimensionar um grupo de controles com guias

1. Ajuste um dos lados do controle (ou controles) a uma guia.

1. Arraste um guia para o outro lado do controle (ou controles).

   Se necessário, com vários controles, tamanho de cada uma delas para encaixar na segunda guia.

1. Mova um guia para dimensionar o controle (ou controles).

### <a name="to-change-the-intervals-of-the-tick-marks"></a>Alterar os intervalos das marcas de escala

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** na caixa de **espaçamento da grade** , especifique uma nova largura e altura em DLUs.

## <a name="disable-guides"></a>Desabilitar guias

Você pode usar chaves especiais em conjunto com o mouse para desabilitar o efeito dos guias de ajuste. Usando o **Alt** chave desativa os efeitos de ajuste do guia selecionada. Movendo um guia com o **Shift** chave impede que os controles sem-instantâneo movendo com o guia.

### <a name="to-disable-the-snapping-effect-of-the-guides"></a>Para desabilitar o efeito dos guias de ajuste

Arraste o controle enquanto mantém pressionada a **Alt** chave.

### <a name="to-move-guides-without-moving-the-snapped-controls"></a>Para mover guias sem mover os controles sem-instantâneo

Arraste a guia enquanto mantém pressionada a **Shift** chave.

### <a name="to-turn-off-the-guides"></a>Para desativar os guias

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo **guias de Layout**, selecione **None**.

   > [!NOTE]
   > Você também pode clicar duas vezes a barra de régua para acessar o **guia de configurações** caixa de diálogo.

\- ou -

Sobre o **formato** menu, selecione **ativar/desativar guias**.

## <a name="modify-the-layout-grid"></a>Modificar a grade de layout

Quando você está colocando ou Organizando controles em uma caixa de diálogo, você pode usar a grade de layout para um posicionamento mais preciso. Quando a grade é ativada, os controles aparecem para "ajustar-se às" as linhas pontilhadas da grade como se magnetizada. Você pode ativar e desativar a esse recurso de "Ajustar à grade" e alterar o tamanho das células da grade de layout.

### <a name="to-turn-the-layout-grid-on-or-off"></a>Para ativar ou desativar a grade de layout

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, marque ou desmarque as **grade** botão.

   Você ainda pode controlar a grade no indivíduo **caixa de diálogo** janelas do editor usando o **ativar/desativar grade** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

### <a name="to-change-the-size-of-the-layout-grid"></a>Para alterar o tamanho da grade de layout

1. Dos **formato** menu, escolha **guia de configurações**.

1. No **guia de configurações** caixa de diálogo, digite a altura e largura em DLUs para as células na grade. A largura ou altura mínima é 4 DLUs. Para obter mais informações sobre DLUs, consulte [organização de controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles (MFC)](../mfc/controls-mfc.md)<br/>
