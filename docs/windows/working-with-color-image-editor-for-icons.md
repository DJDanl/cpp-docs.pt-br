---
title: "Trabalhando com cor (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.image.color
dev_langs: C++
helpviewer_keywords:
- images [C++], background colors
- Image editor [C++], Colors Palette
- colors [C++], image
- Colors Palette, Image editor
- palettes, Image editor colors
- foreground colors, Image editor
- colors [C++]
ms.assetid: d34ff96f-241d-494f-abdd-13811ada8cd3
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6afda534f55d3247f2df11c1a48d0157af245cf2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="working-with-color-image-editor-for-icons"></a>Trabalhando com cor (editor de imagens para ícones)
O editor de imagem contém muitos recursos que manipulam especificamente e personalizar as cores. Você pode definir uma cor de primeiro plano ou segundo plano, preencher as áreas associadas com a cor ou selecione uma cor em uma imagem para usar como a cor de primeiro plano ou segundo plano atual. Você pode usar ferramentas o [barra de ferramentas do Editor de imagem](../windows/toolbar-image-editor-for-icons.md) junto com a paleta de cores no [janela cores](../windows/colors-window-image-editor-for-icons.md) para criar imagens.  
  
 Todas as cores para imagens de 16 cores e monocromática são mostradas na paleta de cores na janela de cores. Além de 16 cores padrão, você pode criar suas próprias cores personalizadas. Alteração de qualquer uma das cores na paleta imediatamente alterará a cor correspondente na imagem.  
  
 Ao trabalhar com ícone de 256 cores e cursor imagens, a propriedade de cores no [janela propriedades](/visualstudio/ide/reference/properties-window) é usado. Para obter mais informações, consulte [criando um ícone de 256 cores ou cursor](creating-a-256-color-icon-or-cursor-image-editor-for-icons.md).  
  
> [!NOTE]
>  Usando o Editor de Imagens, você pode exibir imagens de 32 bits, mas não pode editá-las.  
  
 Imagens coloridas True também podem ser criadas. No entanto, exemplos de cor true não aparecem na paleta completa na janela de cores. eles aparecem somente na área de indicador de cor do primeiro plano ou segundo plano. True cores são criadas usando o [caixa de diálogo Seletor de cor personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Para obter mais informações, consulte [personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md).  
  
 Você pode salvar paletas de cores personalizadas no disco e recarregá-las conforme necessário. A paleta de cores usado mais recentemente é salva no registro e carregada automaticamente na próxima vez que você iniciar o Visual Studio.  
  
-   [Selecionando cores de plano de fundo ou primeiro plano](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md)  
  
-   [Preenchendo uma área limitada de uma imagem com uma cor](../windows/filling-a-bounded-area-of-an-image-with-a-color-image-editor-for-icons.md)  
  
-   [Escolhendo uma cor de uma imagem a ser usada em qualquer lugar](../windows/picking-up-a-color-from-an-image-to-use-elsewhere-image-editor-for-icons.md)  
  
-   [Escolher um plano de fundo transparente ou opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md)  
  
-   [Invertendo as cores em uma seleção](../windows/inverting-the-colors-in-a-selection-image-editor-for-icons.md)  
  
-   [Personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md)  
  
-   [Salvando e carregando paletas de cores diferentes](../windows/saving-and-loading-different-color-palettes-image-editor-for-icons.md)  
  
-   [Janela de cores](../windows/colors-window-image-editor-for-icons.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   

