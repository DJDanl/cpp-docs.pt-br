---
title: Salvando Bitmaps como GIFs ou JPEGs (Editor de imagens para ícones) | Microsoft Docs
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
- .gif files, saving bitmaps as
- jpg files, saving bitmaps as
- jpeg files, saving bitmaps as
- .jpg files, saving bitmaps as
- Image editor [C++], converting image formats
- gif files, saving bitmaps as
- bitmaps [C++], converting formats
- .jpeg files, saving bitmaps as
- graphics [C++], converting formats
- images [C++], converting formats
ms.assetid: 115df69f-10fb-4e6f-906b-853c1e4a54af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: debb2b1e8435cc53ec82ab1f957710850d7b5de3
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40010685"
---
# <a name="saving-bitmaps-as-gifs-or-jpegs-image-editor-for-icons"></a>Salvando bitmaps como GIFs ou JPEGs (editor de imagens para ícones)
Quando você cria um bitmap, a imagem é criada no formato de bitmap (. bmp). No entanto, você pode, salve a imagem como GIF ou JPEG ou em outros formatos de gráfico.  
  
> [!NOTE]
>  Esse processo não se aplica a ícones e cursores.  
  
### <a name="to-create-and-save-a-bitmap-as-a-gif-or-jpeg"></a>Para criar e salvar um bitmap como um. gif ou JPEG  
  
1.  Do **arquivo** menu, escolha **aberto**, em seguida, clique em **arquivo**.  
  
2.  No **caixa de diálogo Novo arquivo**, clique no **Visual C++** pasta, em seguida, selecione **arquivo de Bitmap (. bmp)** no **modelos** caixa e clique em  **Abra**.  
  
     O bitmap é aberto na **imagem** editor.  
  
3.  Faça alterações em seu novo bitmap, conforme necessário.  
  
4.  Com o bitmap ainda aberto na **imagem** editor, clique em **salvar *filename*bmp como** no **arquivo** menu.  
  
5.  No **salvar arquivo como** caixa de diálogo, digite o nome que você deseja dar o arquivo e a extensão que indica o formato de arquivo que você deseja na **nome do arquivo** caixa. Por exemplo, *myfile.gif*.  
  
     > [!NOTE]
     > Você deve criar ou abrir o bitmap fora do seu projeto para salvá-lo como outro formato de arquivo. Se você criar ou abri-lo em seu projeto, o **Salvar como** comando estará disponível. Para obter mais informações, consulte [exibir recursos em um recurso de Script arquivo externa de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
6.  Clique em **Salvar**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="see-also"></a>Consulte também  
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)