---
title: Teclas de aceleração (Editor de C++ imagens para ícones)
ms.date: 02/15/2019
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
helpviewer_keywords:
- accelerator keys
- Image editor [C++], accelerator keys
ms.assetid: add37861-3e17-4a6f-89e8-46df12e74a90
ms.openlocfilehash: 0b29f435ab91b10e010e956d26fb8d2d116edc6e
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57563115"
---
# <a name="accelerator-keys-c-image-editor-for-icons"></a>Teclas de aceleração (Editor de C++ imagens para ícones)

Abaixo estão as teclas de aceleração para os comandos do editor de imagem que estão associados às chaves por padrão. Para alterar as teclas de aceleração, vá ao menu **ferramentas** > **opções** e escolha **teclado** sob o **ambiente** pasta. Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

> [!NOTE]
> As opções disponíveis nas caixas de diálogo e os nomes os locais dos comandos de menu que você vê podem diferir do que é descrito na Ajuda, dependendo de suas configurações ativas ou da edição. Para alterar suas configurações, vá ao menu **ferramentas** > **importar e exportar configurações**. Para obter mais informações, confira [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

|Comando|Chaves|Descrição|
|-------------|----------|-----------------|
|Image.AirBrushTool|**Ctrl** + **A**|Desenha usando um spray com o tamanho e cor selecionados.|
|Image.BrushTool|**Ctrl** + **B**|Desenha usando um pincel com a forma selecionada, tamanho e cor.|
|Image.CopyAndOutlineSelection|**Ctrl** + **Shift** + **U**|Cria uma cópia da seleção atual e a contorna. Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você tiver [transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md) selecionado.|
|Image.DrawOpaque|**Ctrl** + **J**|Torna a seleção atual seja [opaca ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).|
|Image.EllipseTool|**Ctrl** + **P**|Desenha uma elipse com a cor e largura da linha selecionada.|
|Image.EraserTool|**Ctrl** + **Shift** + **I**|Apaga uma parte da imagem (com a cor de plano de fundo atual).|
|Image.FilledEllipseTool|**Ctrl** + **Shift** + **Alt** + **P**|Desenha uma elipse preenchida.|
|Image.FilledRectangleTool|**Ctrl** + **Shift** + **Alt** + **R**|Desenha um retângulo preenchido.|
|Image.FilledRoundRectangleTool|**Ctrl** + **Shift** + **Alt** + **W**|Desenha um retângulo arredondado preenchido.|
|Image.FillTool|**Ctrl** + **F**|Preenche uma área.|
|Image.FlipHorizontal|**Ctrl** + **H**|Inverte a imagem ou seleção horizontalmente.|
|Image.FlipVertical|**Shift**+ **Alt** + **H**|Inverte a imagem ou seleção verticalmente.|
|Image.LargerBrush|**Ctrl** + **=**|Aumenta o tamanho do pincel por um pixel em cada direção. Para diminuir o tamanho do pincel, consulte Image. smallerbrush nesta tabela.|
|Image.LineTool|**Ctrl** + **L**|Desenha uma linha reta com a forma selecionada, tamanho e cor.|
|Image.MagnificationTool|**Ctrl** + **M**|Ativa a **ampliar** ferramenta, que lhe permite ampliar seções específicas da sua imagem.|
|Image.Magnify|**Ctrl** + **Shift** + **M**|Alterna entre ampliação atual e a ampliação 1:1.|
|Image.NewImageType|**Inserir**|Inicia o [New \<dispositivo > caixa de diálogo de tipo de imagem](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md) com o qual você pode criar uma imagem para um tipo de imagem diferente.|
|Image.NextColor|**Ctrl** + **]**<br /><br /> - ou -<br /><br /> **CTRL** + **seta para a direita**|Altera a cor de primeiro plano de desenho para a próxima cor da paleta.|
|Image.NextRightColor|**Ctrl** + **Shift** + **]**<br /><br /> - ou -<br /><br /> **SHIFT** + **Ctrl** + **seta para a direita**|Altera o cor do plano de fundo de desenho para a próxima cor da paleta.|
|Image.OutlinedEllipseTool|**Shift** + **Alt** + **P**|Desenha uma elipse preenchida com uma estrutura de tópicos.|
|Image.OutlinedRectangleTool|**Shift** + **Alt** + **R**|Desenha um retângulo preenchido com uma estrutura de tópicos|
|Image.OutlinedRoundRectangleTool|**Shift** + **Alt** + **W**|Desenha um retângulo arredondado preenchido com uma estrutura de tópicos.|
|Image.PencilTool|**Ctrl** + **I**|Desenha usando um lápis de pixel único.|
|Image.PreviousColor|**Ctrl** + **[**<br /><br /> - ou -<br /><br /> **CTRL** + **seta para a esquerda**|Altera a cor de primeiro plano de desenho para a cor anterior da paleta.|
|Image.PreviousRightColor|**Ctrl** + **Shift** + **[**<br /><br /> - ou -<br /><br /> **SHIFT** + **Ctrl** + **seta para a esquerda**|Altera o cor do plano de fundo de desenho para a cor anterior da paleta.|
|Image.RectangleSelectionTool|**Shift** + **Alt** + **S**|Seleciona uma parte retangular da imagem para mover, copiar ou editar.|
|Image.RectangleTool|ATL + R|Desenha um retângulo com a cor e largura da linha selecionada.|
|Image.Rotate90Degrees|**Ctrl** + **Shift** + **H**|A imagem ou seleção gira 90 graus.|
|Image.RoundedRectangleTool|**Alt** + **W**|Desenha um retângulo arredondado com a cor e largura da linha selecionada.|
|Image.ShowGrid|**Ctrl** + **Alt** + **S**|Alterna a grade de pixels (seleciona ou desmarca a **grade de pixels** opção a [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md)).|
|Image.ShowTileGrid|**Ctrl** + **Shift** + **Alt** + **S**|Alterna a grade lado a lado (seleciona ou desmarca a **grade lado a lado** opção a [caixa de diálogo de configurações da grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md)).|
|Image.SmallBrush|**Ctrl** + **.** (período)|Reduz a **pincel** tamanho a um pixel. (Consulte também largerbrush e smallerbrush nesta tabela.)|
|Image.SmallerBrush|**CTRL**  +  **-** (menos)|Reduz o tamanho do pincel por um pixel em cada direção. Para expandir o tamanho do pincel novamente, consulte Image. largerbrush nesta tabela.|
|Image.TextTool|**Ctrl** + **T**|Abre o [caixa de diálogo Ferramenta de texto](../windows/text-tool-dialog-box-image-editor-for-icons.md).|
|Image.UseSelectionAsBrush|**Ctrl** + **U**|Desenha usando a seleção atual como um pincel.|
|Image.ZoomIn|**Ctrl** + **Shift** + **.** (período)<br /><br /> - ou -<br /><br /> **CTRL** + **seta para cima**|Aumenta a ampliação da exibição atual.|
|Image.ZoomOut|**Ctrl** + **,** (comma)<br /><br /> - ou -<br /><br /> **CTRL** + **na seta para baixo**|Reduz a ampliação da exibição atual.|

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Como: Criar um ícone ou outra imagem](../windows/creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: Editar uma imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: Usar uma ferramenta de desenho](../windows/using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como: Trabalhar com cores](../windows/working-with-color-image-editor-for-icons.md)<br/>