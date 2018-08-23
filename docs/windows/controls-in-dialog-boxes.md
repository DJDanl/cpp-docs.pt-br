---
title: Controles em caixas de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], dialog boxes
- dialog box controls, about dialog box controls
- dialog box controls
ms.assetid: e216c4f9-2fd4-429d-889a-8ebce7bad177
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 70e3bcfb644893f1dc8b41b9c11a3aee5c92103d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591952"
---
# <a name="controls-in-dialog-boxes"></a>Controles em caixas de diálogo

Você pode adicionar controles a uma caixa de diálogo usando o [guia do Editor de caixa de diálogo](../windows/dialog-editor-tab-toolbox.md) na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), que permite que você escolha o controle desejado e arraste-o para a caixa de diálogo. Por padrão, a janela de caixa de ferramentas é definida para ocultar automaticamente. Ele aparece como uma guia na margem esquerda da sua solução quando o editor de caixa de diálogo é aberto. No entanto, você pode fixar o **caixa de ferramentas** janela na posição clicando o **ocultar automaticamente** botão no canto superior direito da janela. Para obter mais informações sobre como controlar o comportamento desta janela, consulte [gerenciamento de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

A maneira mais rápida para adicionar controles a uma caixa de diálogo, reposicionar os controles existentes ou mover os controles de uma caixa de diálogo para outra, é usar o método de arrastar e soltar. A posição do controle é descrita em uma linha pontilhada até que ele é colocado na caixa de diálogo. Quando você adiciona um controle a uma caixa de diálogo com o método de arrastar e soltar, o controle recebe uma altura padrão apropriada para esse tipo de controle.

Quando você adicionar um controle a uma caixa de diálogo ou reposicioná-lo, seu posicionamento final pode ser determinado por guias ou as margens, ou se você tiver ativada a grade de layout.

Depois de adicionar um controle à caixa de diálogo, você pode alterar as propriedades, como a legenda na [janela de propriedades](/visualstudio/ide/reference/properties-window). Você pode selecionar vários controles e alterar suas propriedades de uma só vez.

- [Adicionando, editando ou excluindo controles](adding-editing-or-deleting-controls.md)

- [Selecionando controles](../windows/selecting-controls.md)

- [Dimensionando controles individuais](../windows/sizing-individual-controls.md)

- [Criando controles com a mesma largura, altura ou tamanho](../windows/making-controls-the-same-width-height-or-size.md)

- [Definindo o tamanho da caixa de combinação e de sua lista suspensa](setting-the-size-of-the-combo-box-and-its-drop-down-list.md)

- [Adicionando valores a um controle de caixa de combinação](../windows/adding-values-to-a-combo-box-control.md)

- [Definindo a largura de uma barra de rolagem horizontal](../windows/setting-the-width-of-a-horizontal-scroll-bar.md)

- [A organização dos controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)

- [Controles personalizados no Editor de Caixa de Diálogo](custom-controls-in-the-dialog-editor.md)

- [Definindo a mnemônica (teclas de acesso)](../windows/defining-mnemonics-access-keys.md)

- [Especificando o local e o tamanho de uma caixa de diálogo](../windows/specifying-the-location-and-size-of-a-dialog-box.md)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)  
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)  
[Editor de caixa de diálogo](../windows/dialog-editor.md)