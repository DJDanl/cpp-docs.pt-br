---
title: "Salvando Bitmaps como GIFs ou JPEGs (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f3fe626357283dde8d8f283c6d0aa406ec6c1db0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="saving-bitmaps-as-gifs-or-jpegs-image-editor-for-icons"></a>Salvando bitmaps como GIFs ou JPEGs (editor de imagens para ícones)
Quando você cria um bitmap, a imagem é criada no formato de bitmap (bmp). No entanto, você pode, salve a imagem como GIF ou JPEG ou em outros formatos de gráfico.  
  
> [!NOTE]
>  Esse processo não se aplica a ícones e cursores.  
  
### <a name="to-create-and-save-a-bitmap-as-a-gif-or-jpeg"></a>Para criar e salvar um bitmap como um. gif ou JPEG  
  
1.  Do **arquivo** menu, escolha **abrir**, em seguida, clique em **arquivo**.  
  
2.  No **caixa de diálogo do novo arquivo**, clique no **Visual C++** pasta, em seguida, selecione **arquivo de Bitmap (bmp)** no **modelos** caixa e clique em  **Abra**.  
  
     O bitmap é aberto no **imagem** editor.  
  
3.  Fazer alterações em seu novo bitmap conforme necessário.  
  
4.  Com o bitmap ainda aberto no **imagem** editor, clique em **salvar *filename*. bmp como** no **arquivo** menu.  
  
5.  No **salvar arquivo como** caixa de diálogo caixa, digite o nome que você deseja dar o arquivo e a extensão que indica o formato de arquivo desejado no **nome de arquivo** caixa. Por exemplo, myfile.gif.  
  
     **Observação** você deve criar ou abrir o bitmap fora do seu projeto para salvá-lo como outro formato de arquivo. Se você criar ou abri-lo em seu projeto, o **Salvar como** comando não estará disponível. Para obter mais informações, consulte [exibir recursos em um recurso de Script arquivo fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).  
  
6.  Clique em **Salvar**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="see-also"></a>Consulte também  
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

