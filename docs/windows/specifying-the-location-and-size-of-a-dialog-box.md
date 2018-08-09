---
title: Especificando o local e o tamanho de uma caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes, size
- dialog boxes, positioning
ms.assetid: 2b7c495e-6595-4cfb-9664-80b2826d0851
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3a3a9a629ec138659a7b0d2aba2460aced31fc74
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648997"
---
# <a name="specifying-the-location-and-size-of-a-dialog-box"></a>Especificando o local e o tamanho de uma caixa de diálogo
O local e o tamanho de uma caixa de diálogo, bem como o local e tamanho dos controles dentro dele, são medidos em unidades de diálogo. Os valores para controles individuais e a caixa de diálogo aparecer no canto inferior direito do Visual Studio barra de status quando você seleciona.  
  
 Há três propriedades que podem ser definidas na [janela de propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo será exibida na tela. A propriedade Center é booleano; Se você definir o valor como True, a caixa de diálogo será sempre exibido no centro da tela. Se você defini-lo como False, você pode, em seguida, definir as propriedades de XPos e YPos definir explicitamente onde na tela de que caixa de diálogo será exibida. As propriedades de posição são valores de deslocamento do canto superior esquerdo da área de exibição, que é definido como {X = 0, Y = 0}. A posição também se baseia a **alinhamento absoluto** propriedade: se for True, as coordenadas são em relação à tela; se False, as coordenadas são em relação à janela do proprietário da caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)