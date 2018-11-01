---
title: Selecionando uma área de uma imagem (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.image.editing
helpviewer_keywords:
- Image editor [C++], image selection
- Image editor [C++], selecting images
- images [C++], selecting
- cursors [C++], selecting areas of
ms.assetid: 8b6ce4ad-eba1-4ece-86ba-cea92c3edff2
ms.openlocfilehash: 5e2522d23b30a91639e887a8761871e3df8139f4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50565107"
---
# <a name="selecting-an-area-of-an-image-image-editor-for-icons"></a>Selecionando uma área de uma imagem (editor de imagens para ícones)

Você pode usar ferramentas de seleção para definir uma área de uma imagem que você deseja recortar, copiar, limpar, redimensionar, inverter ou mover. Com o **seleção de retângulo** ferramenta você pode definir e selecionar uma região retangular da imagem. Com o **seleção Irregular** ferramenta você pode desenhar um contorno à mão livre da área que você deseja selecionar para o recorte, cópia ou outra operação.

> [!NOTE]
> Consulte a **seleção de retângulo** e **seleção Irregular** ferramentas mostrada na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) ou exibir as dicas de ferramenta associadas com cada botão o **Editor de imagens** barra de ferramentas.

Você também pode criar um pincel personalizado a partir de uma seleção. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).

### <a name="to-select-an-area-of-an-image"></a>Para selecionar uma área de uma imagem

1. Sobre o **Editor de imagens** barra de ferramentas (ou do **imagem** menu, **ferramentas** comando), clique na ferramenta de seleção que você deseja.

2. Mova o ponto de inserção para um canto da área de imagem que você deseja selecionar. Cruzes aparecem quando o ponto de inserção é sobre a imagem.

3. Arraste o ponto de inserção para o canto oposto da área que você deseja selecionar. Um retângulo mostra quais pixels serão selecionados. Todos os pixels dentro do retângulo, inclusive as encontradas sob o retângulo, estão incluídos na seleção.

4. Solte o botão do mouse. A borda de seleção abrange a área selecionada.

### <a name="to-select-an-entire-image"></a>Para selecionar uma imagem inteira

1. Clique na imagem fora da seleção atual. A borda de seleção altera o foco e abrange a imagem inteira novamente.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)