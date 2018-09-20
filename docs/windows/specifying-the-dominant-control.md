---
title: Especificando o controle dominante | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dominant controls
- Dialog Editor [C++], dominant control
- controls [C++], dominant
ms.assetid: 42b523a7-192a-417b-9512-d4af795e002f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 31bb19a0854bd28573d474a65781808eaecd7ce2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407556"
---
# <a name="specifying-the-dominant-control"></a>Especificando o controle dominante

O controle selecionado primeiro é o controle dominante.

### <a name="to-specify-the-dominant-control"></a>Para especificar o controle dominante

1. Mantenha pressionada a **Ctrl** da chave e clique no controle que você deseja usar para influenciar o tamanho ou local de outros controles *primeiro*.

   **Observação** as alças de dimensionamento do controle dominante são sólidas, enquanto as alças dos controles subordinados são vazadas. Todos os ainda mais o redimensionamento ou alinhamento baseia-se no controle dominante.

### <a name="to-change-the-dominant-control"></a>Para alterar o controle dominante

1. Desmarque a seleção atual clicando fora de todos os controles atualmente selecionados.

2. Repita o procedimento anterior, selecionar um controle diferente pela primeira vez.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Selecionando vários controles](../windows/selecting-multiple-controls.md)<br/>
[Selecionando controles](../windows/selecting-controls.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)