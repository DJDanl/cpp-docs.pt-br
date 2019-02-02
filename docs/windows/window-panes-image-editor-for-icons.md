---
title: Painéis Janela (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
helpviewer_keywords:
- graphics editor [C++]
- Image editor [C++], panes
- Image editor [C++], magnification
- grids, pixel
- pixel grid, Image editor
- Image editor [C++], pixel grid
- Image editor [C++], grid settings
- grid settings, Image editor
ms.assetid: d66ea5b3-e2e2-4fc4-aa99-f50022cc690e
ms.openlocfilehash: 72b7cf056147cdbd216d861f0e710da423951c5a
ms.sourcegitcommit: efcc8c97570ddf7631570226c700e8f6ebb6c7be
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2019
ms.locfileid: "55560303"
---
# <a name="window-panes-image-editor-for-icons"></a>Painéis Janela (editor de imagens para ícones)

O **Editor de imagens** janela normalmente exibe uma imagem em dois painéis separados por uma barra divisória. Um modo de exibição é o tamanho real e a outra é ampliada (o fator de ampliação padrão é 6). As exibições desses dois painéis são atualizadas automaticamente: as alterações feitas em um único painel imediatamente são mostradas no outro. Os dois painéis tornam fácil para você trabalhar em uma exibição ampliada da imagem, na qual você pode distinguir pixels individuais e, ao mesmo tempo, observar o efeito de seu trabalho no modo de exibição de tamanho real da imagem.

O painel esquerdo usa tanto espaço quanto for necessário (até metade dos **imagem** janela) para mostrar a exibição de ampliação 1:1 (o padrão) da sua imagem. O painel direito exibe a imagem ampliada (6:1 ampliação por padrão). Você pode alterar a ampliação em cada painel usando o **ampliar** ferramenta sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou usando as teclas de aceleração.

Você pode ampliar o painel de menor do **Editor de imagens** janela e usar os dois painéis para mostrar diferentes regiões de uma imagem grande. Selecione dentro do painel para escolhê-lo.

Você pode alterar o tamanho relativo dos painéis de posicionando o ponteiro na barra de divisão e mover a barra de divisão para a direita ou esquerda. A barra de divisão pode mover todo o caminho para ambos os lados se você quiser trabalhar em somente um painel.

Se o **Editor de imagens** painel é ampliada por um fator de 4 ou superior, você pode exibir uma grade de pixels que delimita os pixels individuais na imagem.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-change-the-magnification-factor"></a>Para alterar o fator de ampliação

Por padrão, o **imagem** editor exibe o modo de exibição no painel esquerdo em tamanho real e o modo de exibição no painel direito, em 6 vezes o tamanho real. O fator de ampliação (visto na barra de status na parte inferior do espaço de trabalho) é a proporção entre o tamanho real da imagem e o tamanho exibido. O fator de padrão é 6 e o intervalo é de 1 a 10.

1. Selecione o **Editor de imagens** painel cujo fator de ampliação que você deseja alterar.

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md), selecione a seta à direita do [ferramenta ampliar](../windows/toolbar-image-editor-for-icons.md) e selecione o fator de ampliação do submenu: **1 X**, **2 X**, **6 X**, ou **8 X**.

   > [!NOTE]
   > Para selecionar um fator de ampliação diferente das listadas as **ampliar** ferramenta, use as teclas de aceleração.

## <a name="to-display-or-hide-the-pixel-grid"></a>Para exibir ou ocultar a grade de pixels

Para todos os **Editor de imagens** painéis com um fator de ampliação de 4 ou superior, você pode exibir uma grade que delimita os pixels individuais na imagem.

1. Sobre o **imagem** menu, selecione **configurações da grade**.

1. Selecione o **grade de pixels** caixa de seleção para exibir a grade, ou desmarque a caixa para ocultar a grade.

> [!TIP]
> Dicas de ferramenta aparecem quando você passa o cursor sobre um botão de barra de ferramentas. Estas dicas podem ajudá-lo a identificar a função de cada botão.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)