---
title: Dimensionando controles
ms.date: 11/04/2016
f1_keywords:
- vc.editors.dialog.combo
helpviewer_keywords:
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
ms.assetid: 14ccba02-7171-463a-a121-7018cf1e2e5a
ms.openlocfilehash: a6381dcf1aeb9f73ac3b656229d9332df2a6a519
ms.sourcegitcommit: 52c05e10b503e834c443ef11e7ca1987e332f876
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2019
ms.locfileid: "55742707"
---
# <a name="sizing-controls"></a>Dimensionando controles

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as direções em que o controle pode ser redimensionado. Alças de dimensionamento do Active Directory são sólidas; Se uma alça de dimensionamento for vazia, o controle não pode ser redimensionado ao longo desse eixo.

Você também pode alterar o tamanho de um controle, ajuste o controle nas guias ou margens ou movendo um encaixada guia para longe do outro e controle.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-size-an-individual-control"></a>Para dimensionar um controle individual

1. Selecione o controle.

1. Arraste as alças de dimensionamento para alterar o tamanho do controle:

   - Alças de dimensionamento na parte superior e os lados alteram o tamanho horizontal ou vertical.

   - Alças de dimensionamento nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a **Shift** chave e usando o **seta para a direita** e **seta para baixo** chaves.

## <a name="to-automatically-size-a-control-to-fit-the-text-within-it"></a>Para dimensionar automaticamente um controle para se ajustar ao texto dentro dele

Escolher **tamanho de conteúdo** da **formato** menu.

\- ou -

O controle com o botão direito e escolha **tamanho ao conteúdo** no menu de atalho.

## <a name="to-make-controls-the-same-width-height-or-size"></a>Para tornar controla a mesma largura, altura ou tamanho

Você pode redimensionar um grupo de controles com base no tamanho do controle dominante.

1. [Selecione os controles](../windows/selecting-multiple-controls.md) você deseja redimensionar.

   O controle selecionado primeiro da série é o controle dominante. O tamanho final dos controles no grupo depende do tamanho do controle dominante. Para obter mais informações sobre como selecionar o controle dominante, consulte [especificando um controle dominante](../windows/specifying-the-dominant-control.md).

1. Dos **formato** menu, escolha **Igualar tamanho**, em seguida, escolha um dos seguintes comandos:

   - **Ambos**

   - **Altura**

   - **Largura**

## <a name="to-set-the-size-of-the-combo-box-and-its-drop-down-list"></a>Para definir o tamanho da caixa de combinação de caixa e sua lista suspensa

Quando você adicioná-lo à caixa de diálogo, você pode dimensionar uma caixa de combinação. Você também pode especificar o tamanho da caixa de listagem suspensa. Para obter mais informações, consulte [adicionando valores a um controle de caixa de combinação](../windows/adding-values-to-a-combo-box-control.md).

### <a name="to-size-a-combo-box"></a>Para dimensionar uma caixa de combinação

1. Selecione o controle de caixa de combinação na caixa de diálogo.

   Inicialmente, apenas as alças de dimensionamento de direito e esquerdo estão ativos.

1. Use as alças de dimensionamento para definir a largura da caixa de combinação.

Você também pode definir o tamanho vertical da parte suspensa da caixa de combinação.

### <a name="to-set-the-size-of-the-combo-box-drop-down-list"></a>Para definir o tamanho da caixa de combinação de lista suspensa da caixa

1. Selecione o botão de seta suspensa à direita da caixa de combinação.

   ![Seta em uma caixa de combinação em um projeto MFC](../mfc/media/vccomboboxarrow.gif "vcComboBoxArrow")

   O contorno do controle muda para mostrar o tamanho da caixa de combinação com a área de lista suspensa estendida.

1. Use a alça de dimensionamento inferior para alterar o tamanho inicial da área de lista suspensa.

   ![Caixa de combinação&#45;dimensionamento caixa em um projeto MFC](../mfc/media/vccomboboxsizing.gif "vcComboBoxSizing")

1. Selecione a seta suspensa novamente para fechar a parte da lista suspensa da caixa de combinação.

## <a name="to-set-the-width-of-a-horizontal-scroll-bar-and-make-it-appear"></a>Para definir a largura da barra de rolagem horizontal e fazer com que pareça

Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando classes do MFC, a barra de rolagem não aparecerá automaticamente no seu aplicativo.

Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código.

   Sem este conjunto de valores, a barra de rolagem não aparecerá, até mesmo quando os itens na caixa de listagem são mais largas do que a caixa.
> [!NOTE]
> A barra de rolagem horizontal requer MFC.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)
