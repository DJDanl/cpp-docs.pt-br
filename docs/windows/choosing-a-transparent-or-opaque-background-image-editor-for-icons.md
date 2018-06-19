---
title: Escolha um fundo transparente ou opaco (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- opaque backgrounds
- background colors, images
- colors [C++], image
- Image editor [C++], transparent or opague backgrounds
- background images
- images [C++], transparency
- images [C++], opaque background
- transparent backgrounds
- transparency, background
- transparent backgrounds, images
ms.assetid: 61b743d9-c86b-405d-9a81-0806431b4363
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 244e6a63bc16b5e83bb8419dbe1b53741d566e56
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857906"
---
# <a name="choosing-a-transparent-or-opaque-background-image-editor-for-icons"></a>Escolhendo uma tela de fundo transparente ou opaco (editor de imagens para ícones)
Quando você move ou copia uma seleção de uma imagem, os pixels da seleção que correspondem a cor de plano de fundo atual são, por padrão, transparente; eles não podem ocultar pixels no local de destino.  
  
 Você pode alternar de um plano de fundo transparente (o padrão) para um plano de fundo opaco e voltar novamente. Quando você usar uma ferramenta de seleção, o **plano de fundo transparente** e **plano de fundo opaco** opções são exibidas no seletor de opção no **Editor de imagem** barra de ferramentas (conforme mostrado abaixo).  
  
 ![Opções de plano de fundo &#45; transparente ou opaco](../windows/media/vcimageeditoropaqtranspback.gif "vcImageEditorOpaqTranspBack")  
Opções de opacas e transparentes na barra de ferramentas do Editor de imagem  
  
### <a name="to-switch-between-a-transparent-and-opaque-background"></a>Para alternar entre um plano de fundo transparente e opaco  
  
1.  No **Editor de imagem** barra de ferramentas, clique no **opção** seletor e, em seguida, clique em segundo plano apropriado:  
  
    -   **Plano de fundo opaco (O)**: imagem existente é obscurecida por todas as partes da seleção.  
  
    -   **Plano de fundo transparente (T)**: mostra a imagem existente por meio de partes da seleção que correspondem a cor de plano de fundo atual.  
  
 \- ou -  
  
-   Sobre o **imagem** menu, selecione ou desmarque **desenho opaco**.  
  
 Você pode alterar a cor do plano de fundo enquanto uma seleção já está em vigor para alterar quais partes da imagem são transparentes.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)