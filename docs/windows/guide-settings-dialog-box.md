---
title: Caixa de diálogo de configurações de guia (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- DLUs (dialog units)
- Dialog Editor [C++], snap to guides
- grid spacing
- guides, settings
- dialog units (DLUs)
- layout grid in Dialog Editor
- snap to guides (Dialog editor)
- controls [C++], snap to guides/grid
- Guide Settings dialog box (Dialog editor)
ms.assetid: 55381e1c-146a-4fa7-b1b3-b1492817615f
ms.openlocfilehash: 2f83acddf0f56225f74961ef31988a5938685b67
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50483610"
---
# <a name="guide-settings-dialog-box-c"></a>Caixa de diálogo de configurações de guia (C++)

## <a name="layout-guides"></a>Guias de layout

Exibe as configurações das guias de layout.

### <a name="none"></a>Nenhum

Oculta as ferramentas de layout.

### <a name="rulers-and-guides"></a>Réguas e guias

Quando habilitado, adiciona réguas para as ferramentas de layout; guias podem ser colocados nas réguas. Os guias padrão são as margens, que podem ser movidas, arrastando. Clique nas réguas para colocar uma guia. Controles de "ajustará" aos guias de quando os controles são movidos pela ou ao lado deles. Controles também são movidos com um guia depois que eles estão conectados a ele. Quando um controle está anexado a uma guia em cada lado e um guia é movido, o controle é redimensionado.

### <a name="grid"></a>Grade

Cria uma grade de layout. Novos controles são alinhados automaticamente à grade.

## <a name="grid-spacing"></a>Espaçamento da grade

Exibe as configurações para o espaçamento da grade em unidades de caixa de diálogo (DLUs).

### <a name="width-dlus"></a>Largura: DLUs

Define a largura da grade de layout em DLUs. Um DLU horizontal é a largura da média da fonte de caixa de diálogo dividida por quatro.

### <a name="height-dlus"></a>Altura: DLUs

Define a altura da grade de layout em DLUs. Um DLU vertical é a média altura da fonte de caixa de diálogo dividida por oito.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Modificando a grade de layout](../windows/modifying-the-layout-grid.md)<br/>
[Estados do Editor de Caixa de Diálogo (guias e grades)](../windows/dialog-editor-states-guides-and-grids.md)