---
title: "Criando regiões transparentes ou inversas em imagens de dispositivo (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- cursors [C++], screen regions
- inverse colors, device images
- transparent regions, device images
- transparency, device images
- Image editor [C++], device images
- inverse regions, device images
- cursors [C++], transparent regions
- screen colors
- regions, transparent
- icons [C++], transparent regions
- display devices, transparent and screen regions
- transparent regions in devices
- regions, inverse
- colors [C++], Image editor
- device projects, transparent images
- icons [C++], screen regions
ms.assetid: a994954b-b039-4391-a535-58d1fa10fc3b
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a1e59f05c011f1a65937c63f43bd8dfd6f506fe9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-transparent-or-inverse-regions-in-device-images-image-editor-for-icons"></a>Criando regiões transparentes ou inversas em imagens de dispositivo (editor de imagens para ícones)
No [editor de imagem](../windows/image-editor-for-icons.md), a imagem de ícone ou cursor inicial possui um atributo transparente. Embora as imagens de ícone e cursor são retangulares, muitos não são exibidos isso porque partes da imagem são transparentes; mostra a imagem subjacente na tela por meio do ícone ou cursor. Quando você arrasta um ícone, partes da imagem podem aparecer em uma cor invertida. Você cria esse efeito, definindo as cores de tela e inversa no [janela cores](../windows/colors-window-image-editor-for-icons.md).  
  
 As cores de tela e o inverso é aplicar a ícones e cursores em forma e cor da imagem derivada ou designar Inverter regiões. As cores indicam partes da imagem que possui os atributos. Você pode alterar as cores que representam os atributos de cor da tela e o inverso de cor na edição. Essas alterações não afetam a aparência do ícone ou cursor em seu aplicativo.  
  
> [!NOTE]
>  As caixas de diálogo e os comandos de menu que você vê podem ser diferentes dos descritos na Ajuda, dependendo da sua edição ou das configurações ativas. Para alterar as configurações, escolha **Importar e Exportar Configurações** no menu **Ferramentas**. Para obter mais informações, consulte [Personalizando configurações de desenvolvimento no Visual Studio](http://msdn.microsoft.com/en-us/22c4debb-4e31-47a8-8f19-16f328d7dcd3).  
  
### <a name="to-create-transparent-or-inverse-regions"></a>Para criar as regiões transparentes ou inversas  
  
1.  No **cores** janela, clique no **cor da tela** seletor ou **inverso cor** seletor.  
  
2.  Aplique a tela ou cores invertidas em sua imagem usando uma ferramenta de desenho. Para obter mais informações sobre ferramentas de desenho, consulte [usando uma ferramenta de desenho](using-a-drawing-tool-image-editor-for-icons.md).  
  
### <a name="to-change-the-screen-or-inverse-color"></a>Para alterar a cor da tela ou inverso  
  
1.  Selecione o **cor da tela** seletor ou **inverso cor** seletor.  
  
2.  Escolha uma cor no **cores** paleta no **cores** janela.  
  
     A cor complementar é automaticamente designada para o seletor de outros.  
  
    > [!TIP]
    >  Se você clicar duas vezes no seletor de cores da tela ou inverso cor, o [caixa de diálogo Seletor de cor personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md) é exibida.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)

