---
title: Dimensionando um controle ao adicioná-lo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog box controls [C++], size
- controls [C++], sizing
ms.assetid: 06b1dd2b-0ba1-4e1f-adc3-cb73679f765e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: da998c748a3471f053c922e0a80c33d1526b2055
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313137"
---
# <a name="sizing-a-control-while-you-add-it"></a>Dimensionando um controle enquanto você o adiciona

### <a name="to-size-a-control-while-you-add-it"></a>Para dimensionar um controle enquanto você adicioná-lo

1. Selecione um controle na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox).

2. Coloque o cursor (que aparece como cruzada cruzes) onde você deseja que o canto superior esquerdo do novo controle esteja em sua caixa de diálogo.

3. Clique e mantenha pressionado o botão do mouse para o canto superior esquerdo do seu controle na caixa de diálogo de ancoragem e arraste o cursor para a direita e para baixo até que o controle é o tamanho desejado.

   > [!NOTE]
   > Na verdade, é possível ancorar qualquer um dos quatro cantos do controle que está sendo desenhado. Esse procedimento usado no canto superior esquerdo como um exemplo.

4. Solte o botão do mouse. O controle liquida para a caixa de diálogo pelo tamanho especificado.

   > [!TIP]
   > Você pode redimensionar o controle após arrastando-o para a caixa de diálogo, movendo as alças de dimensionamento na borda do controle. Para obter mais informações, consulte [controles individuais do dimensionamento](../windows/sizing-individual-controls.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)  
[Adicionando manipuladores de eventos a controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md)  
[Controles da caixa de diálogo e tipos de variável](../ide/dialog-box-controls-and-variable-types.md)