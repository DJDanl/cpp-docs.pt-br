---
title: Especificando o local e o tamanho de uma caixa de diálogo (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [C++], size
- dialog boxes [C++], positioning
ms.assetid: 2b7c495e-6595-4cfb-9664-80b2826d0851
ms.openlocfilehash: 2c39cf5076ea38635268120da96fec6c82e23c47
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50524924"
---
# <a name="specifying-the-location-and-size-of-a-dialog-box-c"></a>Especificando o local e o tamanho de uma caixa de diálogo (C++)

O local e o tamanho de uma caixa de diálogo de C++, bem como o local e tamanho dos controles dentro dele, são medidos em unidades de diálogo. Os valores para controles individuais e a caixa de diálogo aparecer no canto inferior direito do Visual Studio barra de status quando você seleciona.

Há três propriedades que podem ser definidas na [janela de propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo será exibida na tela. O **Center** propriedade é booliano; se você definir o valor como **verdadeiro**, a caixa de diálogo será sempre exibido no centro da tela. Se você defini-lo **falso**, em seguida, você pode definir o **XPos** e **YPos** propriedades para definir explicitamente onde na tela de caixa de diálogo será exibida. As propriedades de posição são valores de deslocamento do canto superior esquerdo da área de exibição, que é definida como `{X=0, Y=0}`. A posição também se baseia a **alinhamento absoluto** propriedade: se **verdadeiro**, as coordenadas são em relação à tela; se **False**, as coordenadas são relativas à caixa de diálogo janela do proprietário.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)