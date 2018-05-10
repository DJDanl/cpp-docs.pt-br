---
title: Selecionando uma área de uma imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.image.editing
dev_langs:
- C++
helpviewer_keywords:
- Image editor [C++], image selection
- Image editor [C++], selecting images
- images [C++], selecting
- cursors [C++], selecting areas of
ms.assetid: 8b6ce4ad-eba1-4ece-86ba-cea92c3edff2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 07cb7528e25604e873f6da92193a97cf79700799
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="selecting-an-area-of-an-image-image-editor-for-icons"></a>Selecionando uma área de uma imagem (editor de imagens para ícones)
Você pode usar as ferramentas de seleção para definir uma área de uma imagem que você deseja recortar, copiar, limpar, redimensionar, inverter ou mover. Com o **seleção de retângulo** ferramenta, você pode definir e selecionar uma região retangular da imagem. Com o **seleção Irregular** ferramenta Desenhar um contorno traçado da área que você deseja selecionar a recortar, copiar ou outra operação.  
  
> [!NOTE]
>  Consulte o **seleção de retângulo** e **seleção Irregular** ferramentas mostrado na [barra de ferramentas do Editor de imagem](../windows/toolbar-image-editor-for-icons.md) ou exibir as dicas de ferramenta associadas a cada botão de **Editor de imagem** barra de ferramentas.  
  
 Você também pode criar um pincel personalizado de uma seleção. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).  
  
### <a name="to-select-an-area-of-an-image"></a>Para selecionar uma área de uma imagem  
  
1.  No **Editor de imagem** barra de ferramentas (ou o **imagem** menu **ferramentas** comando), clique na ferramenta de seleção que você deseja.  
  
2.  Mova o ponto de inserção para um dos cantos da área da imagem que você deseja selecionar. Cursores em cruz aparecem quando o ponto de inserção estiver sobre a imagem.  
  
3.  Arraste o ponto de inserção para o canto oposto da área que você deseja selecionar. Um retângulo mostra quais pixels serão selecionados. Todos os pixels dentro do retângulo, inclusive as encontradas sob o retângulo, estão incluídos na seleção.  
  
4.  Solte o botão do mouse. A borda de seleção coloca na área selecionada.  
  
### <a name="to-select-an-entire-image"></a>Para selecionar uma imagem inteira  
  
1.  Clique na imagem fora da seleção atual. A borda de seleção muda o foco e abrange a imagem inteira novamente.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

