---
title: "Criando um pincel personalizado (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- colors [C++], brush
- brushes, colors
- brushes, creating custom
- images [C++], creating custom brushes
- graphics [C++], custom brushes
- custom brushes
ms.assetid: 750881aa-6f47-4de9-8ca6-a7a12afc6383
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 38f376053635708372c09a37aa0810e4305db60a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-custom-brush-image-editor-for-icons"></a>Criando um pincel personalizado (editor de imagens para ícones)
Um pincel personalizado é uma parte retangular de uma imagem que você escolher e usar como pincéis predefinidos do editor de imagem. Todas as operações que você pode executar em uma seleção, você pode executar em um pincel personalizado também.  
  
### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado de uma parte de uma imagem  
  
1.  [Selecione a parte da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) que você deseja usar para um pincel.  
  
2.  Mantendo o **SHIFT** tecla pressionada, clique na seleção e arraste-o pela imagem.  
  
     \- ou -  
  
3.  Do **imagem** menu, escolha **usar seleção como Pincel**.  
  
     Sua seleção se torna um pincel personalizado que distribui as cores na seleção através da imagem. Cópias da seleção deixadas ao longo do caminho de arrastar. Mais lenta você arrastar, mais cópias são feitas.  
  
     **Observação** clicar o **usar uma seleção como Pincel** sem primeiro selecionar uma parte da imagem usará a imagem inteira como um pincel. O resultado do uso de um pincel personalizado também dependem se você tiver selecionado um [plano de fundo opaco ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).  
  
 Pixels em um pincel personalizado que correspondem a cor de plano de fundo atual são normalmente transparentes: eles não pintar a imagem existente. Você pode alterar esse comportamento para que os pixels da cor de plano de fundo pintar a imagem existente.  
  
 Você pode usar o pincel personalizado como um carimbo de data ou um estêncil para criar uma variedade de efeitos especiais.  
  
#### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas de pincel personalizado na cor de plano de fundo  
  
1.  [Selecione um plano de fundo transparente ou opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).  
  
2.  [Definir a cor de plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) para a cor na qual você deseja desenhar.  
  
3.  Posicione o pincel personalizado onde você deseja desenhar.  
  
4.  Clique no botão direito do mouse. Nenhuma região opaco do pincel personalizado é desenhada na cor de plano de fundo.  
  
#### <a name="to-double-or-halve-the-custom-brush-size"></a>Clique duas vezes ou dividir o tamanho de pincel personalizado  
  
1.  Pressione o **sinal** (**+**) chave para dobrar o tamanho de pincel, ou o **sinal** (**-**) chave para dividir a ele .  
  
#### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado  
  
1.  Pressione **ESC** ou escolha outra ferramenta de desenho.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

