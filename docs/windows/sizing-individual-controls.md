---
title: Dimensionando controles individuais | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Size to Content command
- size, controls
- text, autosizing controls to fit text
- controls [C++], sizing
ms.assetid: 14ccba02-7171-463a-a121-7018cf1e2e5a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9932b14b3d3afaa0afdff90c08ce44bf1f8648dc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373447"
---
# <a name="sizing-individual-controls"></a>Dimensionando controles individuais

Use as alças de dimensionamento para redimensionar um controle. Quando o ponteiro está posicionado em uma alça de dimensionamento, ele muda de forma para indicar as direções em que o controle pode ser redimensionado. Alças de dimensionamento do Active Directory são sólidas; Se uma alça de dimensionamento for vazia, o controle não pode ser redimensionado ao longo desse eixo.

Você também pode alterar o tamanho de um controle, ajuste o controle nas guias ou margens ou movendo um encaixada guia para longe do outro e controle.

### <a name="to-size-a-control"></a>Para dimensionar um controle

1. Selecione o controle.

2. Arraste as alças de dimensionamento para alterar o tamanho do controle:

   - Alças de dimensionamento na parte superior e os lados alteram o tamanho horizontal ou vertical.

   - Alças de dimensionamento nos cantos alteram o tamanho horizontal e vertical.

   > [!TIP]
   > Você pode redimensionar a unidade de uma caixa de diálogo de controle (DLU) por vez, mantendo pressionada a **Shift** chave e usando o **seta para a direita** e **seta para baixo** chaves.

### <a name="to-automatically-size-a-control-to-fit-the-text-within-it"></a>Para dimensionar automaticamente um controle para se ajustar ao texto dentro dele

1. Escolher **tamanho de conteúdo** da **formato** menu.

\- ou -

- O controle com o botão direito e escolha **tamanho ao conteúdo** no menu de atalho.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)