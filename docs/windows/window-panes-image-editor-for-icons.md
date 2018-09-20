---
title: Painéis janela (Editor de imagens para ícones) | Microsoft Docs
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
ms.openlocfilehash: b4177313a9fa05d160935e6602454ff6c73ab34f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46398730"
---
# <a name="window-panes-image-editor-for-icons"></a>Painéis Janela (editor de imagens para ícones)

O **Editor de imagens** janela normalmente exibe uma imagem em dois painéis separados por uma barra divisória. Um modo de exibição é o tamanho real e a outra é ampliada (o fator de ampliação padrão é 6). As exibições desses dois painéis são atualizadas automaticamente: as alterações feitas em um único painel imediatamente são mostradas no outro. Os dois painéis tornam fácil para você trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito de seu trabalho no modo de exibição de tamanho real da imagem.

O painel esquerdo usa tanto espaço quanto for necessário (até metade dos **imagem** janela) para mostrar a exibição de ampliação 1:1 (o padrão) da sua imagem. O painel direito exibe a imagem ampliada (6:1 ampliação por padrão). Você pode [alterar a ampliação](../windows/changing-the-magnification-factor-image-editor-for-icons.md) em cada painel usando o **ampliar** ferramenta sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou usando as teclas de aceleração.

Você pode ampliar o painel de menor do **Editor de imagens** janela e usar os dois painéis para mostrar diferentes regiões de uma imagem grande. Clique no painel para selecioná-lo.

Você pode alterar o tamanho relativo dos painéis de posicionando o ponteiro na barra de divisão e mover a barra de divisão para a direita ou esquerda. A barra de divisão pode mover todo o caminho para ambos os lados se você quiser trabalhar em somente um painel.

Se o **Editor de imagens** painel é ampliada por um fator de 4 ou maior, você pode [exibir uma grade de pixel](../windows/displaying-or-hiding-the-pixel-grid-image-editor-for-icons.md) que delimita os pixels individuais na imagem.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)