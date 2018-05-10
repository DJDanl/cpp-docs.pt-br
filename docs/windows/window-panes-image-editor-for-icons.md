---
title: Painéis de janela (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
dev_langs:
- C++
helpviewer_keywords:
- graphics editor [C++]
- Image editor [C++], panes
ms.assetid: d66ea5b3-e2e2-4fc4-aa99-f50022cc690e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e899729e70db089c1c55f00aa9c4196a22c67060
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="window-panes-image-editor-for-icons"></a>Painéis Janela (editor de imagens para ícones)
A janela do Editor de imagem exibe uma imagem em dois painéis separados por uma barra de divisão. Um modo de exibição é o tamanho real e a outra é ampliada (o fator de ampliação padrão é 6). Os modos de exibição nesses dois painéis são atualizados automaticamente: as alterações feitas em um painel são mostradas imediatamente no outro. Os dois painéis tornam mais fácil para você trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito de seu trabalho no modo de exibição de tamanho real da imagem.  
  
 O painel esquerdo usa como a quantidade de espaço é necessário (até a metade da janela de imagem) para mostrar a exibição de ampliação 1:1 (o padrão) da imagem. O painel direito exibe a imagem com zoom (6:1 ampliação por padrão). Você pode [alterar a ampliação](../windows/changing-the-magnification-factor-image-editor-for-icons.md) em cada painel usando o **ampliar** ferramenta no [barra de ferramentas do Editor de imagem](../windows/toolbar-image-editor-for-icons.md) ou usando as teclas de aceleração.  
  
 Você pode ampliar o painel menor da janela do Editor de imagem e usar os dois painéis para mostrar regiões diferentes de uma imagem grande. Clique no painel para selecioná-la.  
  
 Você pode alterar os tamanhos relativos dos painéis posicionando o ponteiro sobre a barra de divisão e movendo a barra de divisão para a direita ou esquerda. A barra de divisão pode mover para ambos os lados se você deseja trabalhar em apenas um painel.  
  
 Se o painel do editor de imagem é ampliado por um fator de 4 ou superior, você pode [exibir uma grade de pixels](../windows/displaying-or-hiding-the-pixel-grid-image-editor-for-icons.md) que delimita os pixels individuais na imagem.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

