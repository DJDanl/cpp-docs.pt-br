---
title: Selecionando vários controles | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Dialog Editor [C++], selecting controls
- dialog box controls [C++], selecting in editor
- controls [C++], selecting
- controls [C++], removing from groups
ms.assetid: efbdbade-0a3a-4328-b36e-a6376c06e8de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: aec9785040f0a30150c8399b5059d6d733ad8be2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383825"
---
# <a name="selecting-multiple-controls"></a>Selecionando vários controles

### <a name="to-select-multiple-controls"></a>Para selecionar vários controles

1. No [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox), selecione o **ponteiro** ferramenta.

2. Arraste o ponteiro para desenhar uma caixa de seleção ao redor dos controles que você deseja selecionar na caixa de diálogo.

   Quando você soltar o botão do mouse, todos os controles internos e interseção a caixa de seleção estiver marcada.

   \- ou -

- Mantenha pressionada a **Shift** de chave e clicar nos controles que você deseja incluir na seleção.

   \- ou -

- Mantenha pressionada a **Ctrl** de chave e clicar nos controles que você deseja incluir na seleção.

### <a name="to-remove-a-control-from-a-group-of-selected-controls-or-to-add-a-control-to-a-group-of-selected-controls"></a>Para remover um controle de um grupo de controles selecionados ou para adicionar um controle a um grupo de controles selecionados

1. Com um grupo de controles selecionados, mantenha pressionada a **Shift** da chave e clique no controle que você deseja remover ou adicionar a seleção existente.

   > [!NOTE]
   > Manter pressionada a **Ctrl** chave e clicar em um controle dentro de uma seleção farão com que controlam o controle dominante nessa seleção. Para obter mais informações, consulte [especificando o controle dominante](../windows/specifying-the-dominant-control.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Selecionando controles](../windows/selecting-controls.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)