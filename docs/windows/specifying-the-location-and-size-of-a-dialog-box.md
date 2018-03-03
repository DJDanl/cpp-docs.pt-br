---
title: "Especificando o local e o tamanho de uma caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes, size
- dialog boxes, positioning
ms.assetid: 2b7c495e-6595-4cfb-9664-80b2826d0851
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 03c4c6d6afb13a0e4ed8801838356ff0d1e851f1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="specifying-the-location-and-size-of-a-dialog-box"></a>Especificando o local e o tamanho de uma caixa de diálogo
O local e o tamanho de uma caixa de diálogo, bem como o local e o tamanho dos controles dentro dele, são medidos em unidades de diálogo. Os valores para os controles individuais e a caixa de diálogo aparecer no canto inferior direito da barra quando você seleciona o status para Visual Studio.  
  
 Há três propriedades que podem ser definidas no [janela propriedades](/visualstudio/ide/reference/properties-window) para especificar onde uma caixa de diálogo será exibida na tela. A propriedade Center é booleano; Se você definir o valor como True, a caixa de diálogo será sempre exibida no centro da tela. Se for definido como False, você pode definir as propriedades XPos e YPos para definir explicitamente onde na tela de que caixa de diálogo será exibida. As propriedades de posição são os valores de deslocamento do canto superior esquerdo da área de exibição, que é definido como {X = 0, 0 = Y}. A posição também se baseia o **alinhar absoluto** propriedade: se for True, as coordenadas são em relação à tela; se for falso, as coordenadas são em relação à janela do proprietário da caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

