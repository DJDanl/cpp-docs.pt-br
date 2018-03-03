---
title: "Teclas de aceleração (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.editors.bitmap
- vc.editors.icon
dev_langs:
- C++
helpviewer_keywords:
- accelerator keys
- Image editor [C++], accelerator keys
ms.assetid: add37861-3e17-4a6f-89e8-46df12e74a90
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c992ed83f5c86fdd770bda8f9970ff98a90c2722
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accelerator-keys-image-editor-for-icons"></a>Teclas de aceleração (editor de imagens para ícones)
Abaixo estão as teclas de aceleração para os comandos de editor de imagem que são associados às chaves por padrão. Para alterar as teclas de aceleração, clique em **opções** no **ferramentas** menu e, em seguida, escolha **teclado** sob o **ambiente** pasta. Para obter mais informações, consulte [Identificando e personalizando atalhos de teclado](/visualstudio/ide/identifying-and-customizing-keyboard-shortcuts-in-visual-studio).  
  
> [!NOTE]
>  As opções disponíveis nas caixas de diálogo e os nomes os locais dos comandos de menu que você vê podem diferir do que é descrito na Ajuda, dependendo de suas configurações ativas ou da edição. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, consulte [Personalizando configurações de desenvolvimento no Visual Studio](http://msdn.microsoft.com/en-us/22c4debb-4e31-47a8-8f19-16f328d7dcd3).  
  
|Comando|Chaves|Descrição|  
|-------------|----------|-----------------|  
|Image.AirBrushTool|CTRL + A|Desenha com um spray com o tamanho selecionado e a cor.|  
|Image.BrushTool|CTRL + B|Desenha utilizando um pincel com a forma selecionada, tamanho e cor.|  
|Image.CopyAndOutlineSelection|CTRL + SHIFT + U|Cria uma cópia da seleção atual e descreve a ele. Se a cor de plano de fundo estiver contida na seleção atual, ele será excluído se você tiver [transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md) selecionado.|  
|Image.DrawOpaque|CTRL + J|Torna a seleção atual ou [transparente ou opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).|  
|Image.EllipseTool|CTRL + P|Desenha uma elipse com a cor e largura da linha selecionada.|  
|Image.EraserTool|CTRL + SHIFT + I|Apaga uma parte da imagem (com a cor de plano de fundo atual).|  
|Image.FilledEllipseTool|CTRL + SHIFT + ALT + P|Desenha uma elipse preenchida.|  
|Image.FilledRectangleTool|CTRL + SHIFT + ALT + R|Desenha um retângulo preenchido.|  
|Image.FilledRoundRectangleTool|CTRL + SHIFT + ALT + W|Desenha um retângulo arredondado preenchido.|  
|Image.FillTool|CTRL + F|Preenche uma área.|  
|Image.FlipHorizontal|CTRL + H|Inverte a imagem ou seleção horizontalmente.|  
|Image.FlipVertical|SHIFT + ALT + H|Inverte a imagem ou seleção verticalmente.|  
|Image.LargerBrush|CTRL + =|Aumenta o tamanho do pincel um pixel em cada direção. Para diminuir o tamanho do pincel, consulte Image.SmallerBrush nesta tabela.|  
|Image.LineTool|CTRL + L|Desenha uma linha reta com a forma selecionada, tamanho e cor.|  
|Image.MagnificationTool|CTRL + M|Ativa o **ampliar** ferramenta, que permite ampliar a seções específicas da sua imagem.|  
|Image.Magnify|CTRL + SHIFT + M|Alterna entre a ampliação atual e a ampliação de 1:1.|  
|Image.NewImageType|INSERT|Inicia o [novo \<dispositivo > caixa de diálogo de tipo de imagem](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md) com a qual você pode criar uma imagem de um tipo de imagem diferente.|  
|Image.NextColor|CTRL +]<br /><br /> - ou -<br /><br /> CTRL + SETA PARA DIREITA|Altera a cor de primeiro plano desenho para a próxima cor da paleta.|  
|Image.NextRightColor|CTRL + SHIFT +]<br /><br /> - ou -<br /><br /> SHIFT + CTRL + SETA PARA A DIREITA|Altera a cor de plano de fundo de desenho para a próxima cor da paleta.|  
|Image.OutlinedEllipseTool|SHIFT + ALT + P|Desenha uma elipse preenchida com uma estrutura de tópicos.|  
|Image.OutlinedRectangleTool|SHIFT + R E ATL|Desenha um retângulo preenchido com uma estrutura de tópicos|  
|Image.OutlinedRoundRectangleTool|SHIFT + ALT + W|Desenha um retângulo arredondado preenchido com uma estrutura de tópicos.|  
|Image.PencilTool|CTRL + I|Desenha utilizando um lápis de pixel único.|  
|Image.PreviousColor|CTRL + [<br /><br /> - ou -<br /><br /> CTRL + SETA PARA ESQUERDA|Altera a cor de primeiro plano desenho a paleta de cores anterior.|  
|Image.PreviousRightColor|CTRL + SHIFT + [<br /><br /> - ou -<br /><br /> SHIFT + CTRL + SETA PARA A ESQUERDA|Altera a cor de plano de fundo desenho a paleta de cores anterior.|  
|Image.RectangleSelectionTool|SHIFT + ALT + S|Seleciona uma parte retangular da imagem para mover, copiar ou editar.|  
|Image.RectangleTool|ATL + R|Desenha um retângulo com a cor e largura da linha selecionada.|  
|Image.Rotate90Degrees|CTRL + SHIFT + H|A imagem ou seleção gira 90 graus.|  
|Image.RoundedRectangleTool|ALT + W|Desenha um retângulo arredondado com a cor e largura da linha selecionada.|  
|Image.ShowGrid|CTRL + ALT + S|Alterna a grade de pixels (seleciona ou limpa a **grade de pixels** opção o [caixa de diálogo Configurações de grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md)).|  
|Image.ShowTileGrid|CTRL + SHIFT + ALT + S|Alterna a grade de bloco (seleciona ou limpa a **grade lado a lado** opção o [caixa de diálogo Configurações de grade](../windows/grid-settings-dialog-box-image-editor-for-icons.md)).|  
|Image.SmallBrush|CTRL +. (ponto)|Reduz a **pincel** tamanho para um pixel. (Consulte também Image.LargerBrush e Image.SmallerBrush nesta tabela.)|  
|Image.SmallerBrush|CTRL + - (subtração)|Reduz o tamanho do pincel um pixel em cada direção. Para expandir o tamanho do pincel novamente, consulte Image.LargerBrush nesta tabela.|  
|Image.TextTool|CTRL + T|Abre o [caixa de diálogo Ferramenta de texto](../windows/text-tool-dialog-box-image-editor-for-icons.md).|  
|Image.UseSelectionAsBrush|CTRL + U|Desenha usando a seleção atual como um pincel.|  
|Image.ZoomIn|CTRL + SHIFT +. (ponto)<br /><br /> - ou -<br /><br /> CTRL + SETA PARA CIMA|Aumenta a ampliação da exibição atual.|  
|Image.ZoomOut|CTRL +, (vírgula)<br /><br /> - ou -<br /><br /> CTRL + SETA PARA BAIXO|Reduz a ampliação da exibição atual.|  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

