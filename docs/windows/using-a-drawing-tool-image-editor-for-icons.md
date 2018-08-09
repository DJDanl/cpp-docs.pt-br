---
title: Usando uma ferramenta de desenho (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.image.drawing
dev_langs:
- C++
helpviewer_keywords:
- Image editor [C++], selecting drawing tools
- Image editor [C++], toolbar
- drawing tools
ms.assetid: 1f8c6eef-7760-45a9-a5cb-9e15c6f91245
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fde195d465116f2fa3055d5981c2c465c4bf31ba
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40019458"
---
# <a name="using-a-drawing-tool-image-editor-for-icons"></a>Usando uma ferramenta de desenho (editor de imagens para ícones)
O **imagem** do freehand desenhar e apagar todos funcionam da mesma forma de ferramentas editor: selecione a ferramenta e, se necessário, [selecionar cores de primeiro plano e plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md) e opções de tamanho e forma. Você, em seguida, mova o ponteiro para a imagem e clique ou arraste para desenhar e apagar.  
  
 Quando você seleciona os **borracha** ferramenta, **pincel** ferramenta, ou **spray** ferramenta, o seletor de opção exibe opções da ferramenta.  
  
> [!TIP]
>  Em vez de usar o **borracha** ferramenta, talvez seja mais conveniente para desenhar a cor do plano de fundo com uma das ferramentas de desenho.  
  
 Você pode selecionar ferramentas de desenho a **Editor de imagens** barra de ferramentas ou o **imagem** menu.  
  
### <a name="to-select-and-use-a-drawing-tool-from-the-image-editor-toolbar"></a>Para selecionar e usar uma ferramenta de desenho da barra de ferramentas do Editor de imagens  
  
1.  Clique em um botão na **Editor de imagens** barra de ferramentas.  
  
    -   O **borracha** ferramenta pinta sobre a imagem com a cor de plano de fundo atual quando você pressiona o botão esquerdo do mouse.  
  
    -   O **Lápis** ferramenta desenha à mão livre em uma constante de largura de um pixel.  
  
    -   O **seletor de opção determina a forma e o tamanho da ferramenta Pincel**.  
  
    -   O **spray** ferramenta distribui aleatoriamente os pixels da cor em torno do centro do pincel.  
  
        > [!TIP]
        >  Dicas de ferramenta aparecem quando você passa o cursor sobre os botões na [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md). Estas dicas ajudarão você a identificar os botões específicos mencionados aqui.  
  
2.  Se necessário, selecione as cores e um pincel:  
  
    -   No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), clique no botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.  
  
    -   No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), clique em uma forma que representa o pincel que você deseja usar.  
  
3.  Aponte para o local na imagem para onde você deseja começar a desenhar ou pintura. O ponteiro muda a forma de acordo com a ferramenta que você selecionou.  
  
4.  Pressione o botão esquerdo do mouse (para a cor de primeiro plano) ou o botão direito do mouse (para a cor do plano de fundo) e mantenha-a pressionada enquanto você desenhar.  
  
### <a name="to-select-and-use-a-drawing-tool-from-the-image-menu"></a>Para selecionar e usar uma ferramenta de desenho no menu imagem  
  
1.  Clique o **imagem** menu e selecione o **ferramentas** comando.  
  
2.  No submenu em cascata, escolha a ferramenta que você deseja usar.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)   
 [Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)