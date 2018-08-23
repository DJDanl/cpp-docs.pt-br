---
title: Criando um pincel personalizado (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- colors [C++], brush
- brushes, colors
- brushes, creating custom
- images [C++], creating custom brushes
- graphics [C++], custom brushes
- custom brushes
ms.assetid: 750881aa-6f47-4de9-8ca6-a7a12afc6383
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 62e4cb9d6eebee4235db2bc38b2cd20935493b02
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42607974"
---
# <a name="creating-a-custom-brush-image-editor-for-icons"></a>Criando um pincel personalizado (editor de imagens para ícones)

Um pincel personalizado é uma parte retangular de uma imagem que você pegue e usar como uma da **imagem** pincéis de prontas para uso do editor. Todas as operações que você pode executar em uma seleção, você pode executar em um pincel personalizado também.

### <a name="to-create-a-custom-brush-from-a-portion-of-an-image"></a>Para criar um pincel personalizado de uma parte de uma imagem

1. [Selecione a parte da imagem](../windows/selecting-an-area-of-an-image-image-editor-for-icons.md) que você deseja usar para um pincel.

2. Mantendo os **Shift** para baixo da chave, clique na seleção e arraste-o em toda a imagem.

   \- ou -

3. Dos **imagem** menu, escolha **usar seleção como Pincel**.

   Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais.

   > [!NOTE]
   > Clicar a **usar uma seleção como Pincel** sem primeiro selecionar uma parte da imagem usará a imagem inteira como um pincel. O resultado do uso de um pincel personalizado também dependem se você selecionou uma [plano de fundo opaca ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

Pixels em um pincel personalizado que correspondem à cor do plano de fundo atual são normalmente transparentes: eles não pinte sobre a imagem existente. Você pode alterar esse comportamento para que os pixels da cor de plano de fundo pinte sobre a imagem existente.

Você pode usar o pincel personalizado, como um carimbo de data / ou um estêncil para criar uma variedade de efeitos especiais.

### <a name="to-draw-custom-brush-shapes-in-the-background-color"></a>Para desenhar formas de pincel personalizado na cor da tela de fundo

1. [Selecione um plano de fundo opaco ou transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).

2. [Definir a cor do plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) para a cor em que você deseja desenhar.

3. Posicione o pincel personalizado no qual você deseja desenhar.

4. Clique no botão direito do mouse. Quaisquer regiões opacos do pincel personalizado são desenhadas na cor da tela de fundo.

### <a name="to-double-or-halve-the-custom-brush-size"></a>Clique duas vezes ou reduz pela metade o tamanho do pincel personalizados

1. Pressione a **sinal de adição** (**+**) a chave para dobrar o tamanho do pincel, ou o **sinal de subtração** (**-**) chave para dividir a ele .

### <a name="to-cancel-the-custom-brush"></a>Para cancelar o pincel personalizado

1. Pressione **Esc** ou escolha outra ferramenta de desenho.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)  
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)  
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)