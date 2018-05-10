---
title: Alterando propriedades da imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- images [C++], properties
- Image editor [C++], Properties window
- Image editor [C++], image properties
- Properties window, image editor
ms.assetid: f6172bf1-08c4-4dfd-b542-dd8749e83fe6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 79903e198ddd418b96b0fac2a464dc130d81614e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="changing-image-properties-image-editor-for-icons"></a>Alterando propriedades da imagem (editor de imagens para ícones)
Você pode definir ou modificar as propriedades de uma imagem usando o [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
### <a name="to-change-an-images-properties"></a>Para alterar as propriedades da imagem  
  
1.  Abra a imagem no **imagem** editor.  
  
2.  No **propriedades** janela, alterar uma ou todas as propriedades para a imagem.  
  
    |Propriedade|Descrição|  
    |--------------|-----------------|  
    |**Cores**|Especifica o esquema de cores para a imagem. Selecione monocromática, cor de 16, ou 256 ou True. Se você já selecionou a imagem com uma paleta de cores de 16, selecionar monocromática faz com que as substituições de preto e branco para as cores na imagem. Contraste não é mantida sempre: por exemplo, as áreas adjacentes de vermelho e verde são ambos convertidas para preto.|  
    |**Filename**|Especifica o nome do arquivo de imagem. Por padrão, o Visual Studio atribui um nome de arquivo base criado removendo os primeiros quatro caracteres ("IDB_") o identificador de recurso padrão (IDB_BITMAP1) além de incluir a extensão apropriada. O nome do arquivo para a imagem neste exemplo seria BITMAP1.bmp. Você pode renomeá-la MYBITMAP1.bmp.|  
    |**Altura**|Define a altura da imagem (em pixels). O valor padrão é 48. A imagem é cortada ou espaço em branco é adicionado abaixo da imagem existente.|  
    |**ID**|Define o identificador do recurso. Para uma imagem, Microsoft Visual Studio, por padrão, atribui o próximo identificador disponível em uma série: IDB_BITMAP1, IDB_BITMAP2, e assim por diante. Nomes semelhantes são usados para ícones e cursores.|  
    |**Paleta**|Alterações de propriedades de cores. Clique duas vezes para selecionar uma cor e exibir o [caixa de diálogo Seletor de cor personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md). Defina a cor, digitando os valores RGB ou HSL nas caixas de texto apropriado.|  
    |**SaveCompressed**|Indica se a imagem está em um formato compactado. Esta propriedade é somente para leitura. O Visual Studio não permite salvar imagens em um formato compactado, portanto qualquer imagens criadas no Visual Studio, essa propriedade será **False**. Se você abrir uma imagem compactada (criada em outro programa) no Visual Studio, essa propriedade será **True**. Se você salvar uma imagem compactada usando o Visual Studio, ele será descompactado e essa propriedade será revertida para **False**.|  
    |**Largura**|Define a largura da imagem (em pixels). O valor padrão de bitmaps é 48. A imagem é cortada ou espaço em branco é adicionado à direita da imagem existente.|  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

