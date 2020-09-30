---
title: Teclas de aceleração (editor de imagem C++ para ícones)
ms.date: 02/15/2019
helpviewer_keywords:
- accelerator keys
- Image editor [C++], accelerator keys
ms.assetid: add37861-3e17-4a6f-89e8-46df12e74a90
ms.openlocfilehash: 02ac25b693e4d8f7bb6739708d23eb1df0ebf190
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500876"
---
# <a name="accelerator-keys-c-image-editor-for-icons"></a>Teclas de aceleração (editor de imagem C++ para ícones)

Abaixo estão as teclas de aceleração para os comandos do editor de imagem que são associados a chaves por padrão. Para alterar as teclas de aceleração, vá para menu **ferramentas**  >  **Opções** e escolha **teclado** na pasta **ambiente** . Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).

> [!NOTE]
> As opções disponíveis nas caixas de diálogo e os nomes os locais dos comandos de menu que você vê podem diferir do que é descrito na Ajuda, dependendo de suas configurações ativas ou da edição. Para alterar as configurações, vá para menu **ferramentas**  >  **importar e exportar configurações**. Para obter mais informações, consulte [Personalizar o IDE do Visual Studio](/visualstudio/ide/personalizing-the-visual-studio-ide).

|Comando|simétricas|Descrição|
|-------------|----------|-----------------|
|Image. AirBrushTool|**Ctrl**  +  **Um**|Desenha usando um spray com o tamanho e a cor selecionados.|
|Image.BrushTool|**Ctrl** + **B**|Desenha usando um pincel com a forma, o tamanho e a cor selecionados.|
|Image. CopyAndOutlineSelection|**Ctrl**  +  **Shift**  +  **U**|Cria uma cópia da seleção atual e a descreve. Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você tiver selecionado [transparentemente](./image-editor-for-icons.md) .|
|Image.DrawOpaque|**Ctrl** + **J**|Torna a seleção atual [opaca ou transparente](./image-editor-for-icons.md).|
|Image.EllipseTool|**Ctrl**  +  **P**|Desenha uma elipse com a largura e a cor da linha selecionada.|
|Image. EraserTool|**Ctrl**  +  **Shift**  +  **I**|Apaga uma parte da imagem (com a cor do plano de fundo atual).|
|Image.FilledEllipseTool|**Ctrl**  +  **Shift**  +  **ALT**  +  **P**|Desenha uma elipse preenchida.|
|Image.FilledRectangleTool|**Ctrl**  +  **Shift**  +  **ALT**  +  **R**|Desenha um retângulo preenchido.|
|Image. FilledRoundRectangleTool|**Ctrl**  +  **Shift**  +  **ALT**  +  **W**|Desenha um retângulo redondo preenchido.|
|Image.FillTool|**Ctrl**  +  **F**|Preenche uma área.|
|Image.FlipHorizontal|**Ctrl**  +  **H**|Inverte a imagem ou a seleção horizontalmente.|
|Image.FlipVertical|**Shift** +  **ALT**  +  **H**|Inverte a imagem ou a seleção verticalmente.|
|Image.LargerBrush|**Teclas** + **=**|Aumenta o tamanho do pincel em um pixel em cada direção. Para diminuir o tamanho do pincel, consulte Image. SmallerBrush nesta tabela.|
|Image.LineTool|**Ctrl**  +  **L**|Desenha uma linha reta com a forma, o tamanho e a cor selecionados.|
|Image.MagnificationTool|**Ctrl**  +  **M**|Ativa a ferramenta de **ampliação** , que permite que você amplie seções específicas da imagem.|
|Image.Magnify|**Ctrl**  +  **Shift**  +  **M**|Alterna entre a ampliação atual e a ampliação de 1:1.|
|Image.NewImageType|**Inserção**|Inicia a [ \<Device> caixa de diálogo novo tipo de imagem](./creating-an-icon-or-other-image-image-editor-for-icons.md) com a qual você pode criar uma imagem para um tipo de imagem diferente.|
|Image.NextColor|**Ctrl**  +  **]**<br /><br /> - ou -<br /><br /> **Ctrl**  +  **Seta para a direita**|Altera a cor do primeiro plano do desenho para a próxima cor da paleta.|
|Image.NextRightColor|**Ctrl**  +  **Shift**  +  **]**<br /><br /> - ou -<br /><br /> **Shift**  +  **Ctrl**  +  **Seta para a direita**|Altera a cor do plano de fundo do desenho para a próxima cor da paleta.|
|Image.OutlinedEllipseTool|**Shift**  +  **ALT**  +  **P**|Desenha uma elipse preenchida com um contorno.|
|Image.OutlinedRectangleTool|**Shift**  +  **ALT**  +  **R**|Desenha um retângulo preenchido com um contorno|
|Image. OutlinedRoundRectangleTool|**Shift**  +  **ALT**  +  **W**|Desenha um retângulo redondo preenchido com um contorno.|
|Image.PencilTool|**Ctrl**  +  **I**|Desenha usando um lápis de pixel único.|
|Image.PreviousColor|**Ctrl**  +  **[**<br /><br /> - ou -<br /><br /> **Ctrl**  +  **Seta para a esquerda**|Altera a cor do primeiro plano do desenho para a cor da paleta anterior.|
|Image.PreviousRightColor|**Ctrl**  +  **Shift**  +  **[**<br /><br /> - ou -<br /><br /> **Shift**  +  **Ctrl**  +  **Seta para a esquerda**|Altera a cor do plano de fundo do desenho para a cor da paleta anterior.|
|Image.RectangleSelectionTool|**Shift**  +  **ALT**  +  **S**|Seleciona uma parte retangular da imagem a ser movida, copiada ou editada.|
|Image.RectangleTool|ATL + R|Desenha um retângulo com a largura e a cor da linha selecionada.|
|Image.Rotate90Degrees|**Ctrl**  +  **Shift**  +  **H**|Gira a imagem ou a seleção de 90 graus.|
|Image.RoundedRectangleTool|**ALT**  +  **W**|Desenha um retângulo arredondado com a largura e a cor da linha selecionada.|
|Image.ShowGrid|**Ctrl**  +  **ALT**  +  **S**|Alterna a grade de pixels (marca ou limpa a opção de **grade de pixels** na [caixa de diálogo Configurações de grade](./image-editor-for-icons.md)).|
|Image.ShowTileGrid|**Ctrl**  +  **Shift**  +  **ALT**  +  **S**|Alterna a grade de blocos (marca ou limpa a opção de **grade de blocos** na [caixa de diálogo Configurações de grade](./image-editor-for-icons.md)).|
|Image.SmallBrush|**Ctrl**  +  **.** (ponto final)|Reduz o tamanho do **pincel** a um pixel. (Veja também Image. LargerBrush e image. SmallerBrush nesta tabela.)|
|Image.SmallerBrush|**Ctrl**  +  Ctrl **-** menos|Reduz o tamanho do pincel em um pixel em cada direção. Para expandir o tamanho do pincel novamente, consulte Image. LargerBrush nesta tabela.|
|Image.TextTool|**Ctrl**  +  **T**|Abre a [caixa de diálogo ferramenta de texto](./image-editor-for-icons.md).|
|Image. UseSelectionAsBrush|**Ctrl**  +  **U**|Desenha usando a seleção atual como um pincel.|
|Image.ZoomIn|**Ctrl**  +  **Shift**  +  **.** (ponto final)<br /><br /> - ou -<br /><br /> **Ctrl**  +  **Seta para cima**|Aumenta a ampliação da exibição atual.|
|Image.ZoomOut|**Ctrl**  +  **,** (vírgula)<br /><br /> - ou -<br /><br /> **Ctrl**  +  **Seta para baixo**|Reduz a ampliação da exibição atual.|

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagem para ícones](image-editor-for-icons.md)<br/>
[Como: criar um ícone ou outra imagem](creating-an-icon-or-other-image-image-editor-for-icons.md)<br/>
[Como: editar uma imagem](selecting-an-area-of-an-image-image-editor-for-icons.md)<br/>
[Como: usar uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md)<br/>
[Como trabalhar com cores](working-with-color-image-editor-for-icons.md)<br/>
