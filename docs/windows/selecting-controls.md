---
title: Selecionando controles
ms.date: 11/04/2016
helpviewer_keywords:
- Dialog Editor [C++], selecting controls
- dominant controls
- dialog box controls [C++], selecting in editor
- controls [C++], selecting
- size, controls
- controls [C++], dominant
- controls [C++], removing from groups
- Dialog Editor [C++], dominant control
ms.assetid: 27f05450-4550-4229-9f4c-2c9e06365596
ms.openlocfilehash: a0a21942f6e2c37b96a7a704fadbb9bacc4761c8
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56149668"
---
# <a name="selecting-controls"></a>Selecionando controles

Selecione controles para tamanho, alinhar, mover, copiar, ou excluí-los e, em seguida, concluir a operação desejada. Na maioria dos casos, você precisa selecionar mais de um controle para usar as ferramentas de dimensionamento e o alinhamento a [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).

Quando um controle for selecionado, ele tem uma borda sombreada em torno dele com sólida (ativa) ou vazios (inativo) "alças de dimensionamento" pequenos quadrados que aparecem na borda de seleção. Quando vários controles estiverem selecionados, o controle dominante tem alças de dimensionamento sólida e todos os outros controles selecionados tem alças de dimensionamento vazado.

Quando você estiver dimensionando ou alinhar vários controles, o **caixa de diálogo** editor usa o "controle dominante" para determinar como os outros controles são dimensionados ou alinhados. Por padrão, o controle dominante é o primeiro controle selecionado.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-select-multiple-controls"></a>Para selecionar vários controles

1. No [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o **ponteiro** ferramenta.

1. Arraste o ponteiro para desenhar uma caixa de seleção ao redor dos controles que você deseja selecionar na caixa de diálogo.

   Quando você soltar o botão do mouse, todos os controles internos e interseção a caixa de seleção estiver marcada.

   \- ou -

   Mantenha pressionada a **Shift** da chave e selecione os controles que você deseja incluir na seleção.

   \- ou -

   Mantenha pressionada a **Ctrl** da chave e selecione os controles que você deseja incluir na seleção.

## <a name="to-remove-a-control-from-a-group-of-selected-controls-or-to-add-a-control-to-a-group-of-selected-controls"></a>Para remover um controle de um grupo de controles selecionados ou para adicionar um controle a um grupo de controles selecionados

1. Com um grupo de controles selecionados, mantenha pressionada a **Shift** da chave e selecione o controle que você deseja remover ou adicionar a seleção existente.

   > [!NOTE]
   > Manter pressionada a **Ctrl** chave e selecionando um controle dentro de uma seleção farão com que controlam o controle dominante nessa seleção.

## <a name="to-specify-the-dominant-control"></a>Para especificar o controle dominante

1. Mantenha pressionada a **Ctrl** da chave e clique no controle que você deseja usar para influenciar o tamanho ou local de outros controles *primeiro*.

> [!NOTE]
> As alças de dimensionamento do controle dominante são sólidas, enquanto as alças dos controles subordinados são vazadas. Todos os ainda mais o redimensionamento ou alinhamento baseia-se no controle dominante.

## <a name="to-change-the-dominant-control"></a>Para alterar o controle dominante

1. Desmarque a seleção atual clicando fora de todos os controles atualmente selecionados.

1. Repita o procedimento anterior, selecionar um controle diferente pela primeira vez.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)