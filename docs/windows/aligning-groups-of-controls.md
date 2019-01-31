---
title: Alinhar controles
ms.date: 11/04/2016
helpviewer_keywords:
- controls [C++], aligning
- controls [C++], positioning
- Space Evenly command
- dialog box controls [C++], placement
- Center in Dialog command
- Arrange Buttons command
- buttons, arranging push buttons in dialog boxes
- push buttons
ms.assetid: a4f49a73-4a17-44b3-8568-aa35f646b5cf
ms.openlocfilehash: abfae0f0146fa736a6427eb1180805717ce8a78e
ms.sourcegitcommit: 5270117dbecc4c49bca0cf10b927bae3c9930038
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/31/2019
ms.locfileid: "55484975"
---
# <a name="align-controls"></a>Alinhar controles

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

Os procedimentos a seguir mostram como alinhar controles:

## <a name="to-align-groups-of-controls"></a>Alinhar grupos de controles

1. [Selecione os controles](../windows/selecting-multiple-controls.md) você deseja alinhar. Certifique-se de selecionar o controle que você deseja ser o controle dominante pela primeira vez ou defini-lo para ser o controle dominante antes de executar o alinhamento ou comando de dimensionamento.

   A posição final do grupo de controles depende a posição do controle dominante. Para obter mais informações sobre como selecionar o controle dominante, consulte [especificando o controle dominante](../windows/specifying-the-dominant-control.md).

1. Dos **formato** menu, escolha **alinhar**e, em seguida, escolha uma das alinhamentos a seguir:

   - `Lefts`: alinha os controles selecionados ao longo dos lados esquerdos.

   - `Centers`: alinha os controles selecionados horizontalmente ao longo de seus pontos centrais.

   - `Rights`: alinha os controles selecionados ao longo dos lados direito.

   - `Tops`: alinha os controles selecionados ao longo de suas bordas na parte superior.

   - `Middles`: alinha os controles selecionados verticalmente ao longo de seus pontos intermediários.

   - `Bottoms`: alinha os controles selecionados ao longo de suas bordas inferior.

## <a name="to-even-the-spacing-between-controls"></a>Para até mesmo o espaçamento entre controles

O **caixa de diálogo** editor permite que você espaçar os controles uniformemente entre os controles mais externos selecionados.

1. Selecione os controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **espaçar uniformemente**e, em seguida, escolha uma dos alinhamentos de espaçamento a seguir:

   - `Across`: espaço controles uniformemente entre os mais à esquerda e o controle mais à direita selecionado.

   - `Down`: espaço controles uniformemente entre o primeiro e o controle na extremidade inferior selecionado.

## <a name="to-center-controls-in-a-dialog-box"></a>Para centralizar os controles em uma caixa de diálogo

1. Selecione o controle ou controles que você deseja reorganizar.

1. Dos **formato** menu, escolha **na caixa de diálogo Centro**e, em seguida, escolha uma das seguintes organizações:

   - `Vertical`: Centralizar controles verticalmente na caixa de diálogo.

   - `Horizontal`: Centralizar controles horizontalmente na caixa de diálogo.

## <a name="to-arrange-push-buttons-along-the-right-or-bottom-of-a-dialog-box"></a>Para organizar os botões de envio por push ao longo da direita ou inferior de uma caixa de diálogo

1. Selecione um ou mais botões de envio por push.

1. Dos **formato** menu, escolha **Organizar botões**e, em seguida, escolha uma das seguintes organizações:

   - `Right`: alinha os botões de envio por push ao longo da borda direita da caixa de diálogo.

   - `Bottom`: alinha os botões de envio por push ao longo da borda inferior da caixa de diálogo.

       Se você selecionar um controle que não seja um botão de envio por push, sua posição não é afetada.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Organização de controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)