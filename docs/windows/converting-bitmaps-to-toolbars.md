---
title: Convertendo Bitmaps em barras de ferramentas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- bitmaps [C++], converting to toolbars
- Toolbar editor, converting bitmaps
- toolbars [C++], converting bitmaps
ms.assetid: 971c181b-40f5-44be-843d-677a7c235667
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 43eda0c6bd875b9fd82ee97d346e3f5d89584795
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="converting-bitmaps-to-toolbars"></a>Convertendo bitmaps em barras de ferramentas
Você pode criar uma nova barra de ferramentas, convertendo um bitmap. O gráfico de bitmap converte as imagens de botão de uma barra de ferramentas. Normalmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão. Imagens podem ser de qualquer tamanho. o padrão é 16 pixels de largura e a altura da imagem. Você pode especificar o tamanho das imagens no botão de [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md) quando você escolhe o Editor de barra de ferramentas do **imagem** menu enquanto estiver no editor de imagem.  
  
### <a name="to-convert-bitmaps-to-a-toolbar"></a>Converter bitmaps em uma barra de ferramentas  
  
1.  Abrir um recurso de bitmap existente no [editor de imagem](../windows/image-editor-for-icons.md). (Se o bitmap não ainda estiver em seu arquivo. RC, com o botão direito no arquivo. RC, escolha **importação** no menu de atalho, navegue até o bitmap que você deseja adicionar ao seu arquivo. RC e clique em **abrir**.)  
  
2.  Do **imagem** menu, escolha **Editor de barra de ferramentas**.  
  
     O [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md) é exibida. Você pode alterar a largura e altura das imagens de ícone para corresponder o bitmap. A imagem da barra de ferramentas é exibida no editor de barra de ferramentas.  
  
3.  Para concluir a conversão, altere o comando **ID** do botão usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Digite o novo **ID** ou selecione um **ID** na lista suspensa.  
  
    > [!TIP]
    >  A janela de propriedades contém um botão de pino na barra de título. Este botão habilita ou desabilita a ocultar automaticamente para a janela. Para alternar rapidamente entre todas as propriedades de botão da barra de ferramentas sem precisar reabrir janelas de propriedade individuais, desative ocultar automaticamente para a janela Propriedades permanece parada.  
  
 Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Para obter informações sobre como editar a nova barra de ferramentas, consulte [criando, movendo e editando botões da barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
 Requisitos  
  
 MFC ou do ATL  
  
## <a name="see-also"></a>Consulte também  
 [Criando novas barras de ferramentas](../windows/creating-new-toolbars.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

