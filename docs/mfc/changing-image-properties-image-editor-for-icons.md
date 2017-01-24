---
title: "Alterando propriedades da imagem (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "Editor de imagem [C++], propriedades de imagem"
  - "Editor de imagem [C++], janela Propriedades"
  - "imagens [C++], propriedades"
  - "janela Propriedades, editor de imagem"
ms.assetid: f6172bf1-08c4-4dfd-b542-dd8749e83fe6
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando propriedades da imagem (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode definir ou modificar propriedades de uma imagem usando o  [janela Propriedades do](../Topic/Properties%20Window.md).  
  
### Para alterar as propriedades da imagem  
  
1.  Abra a imagem no  **imagem** editor.  
  
2.  No  **Propriedades** janela, alterar qualquer ou todas as propriedades para sua imagem.  
  
    |Propriedade|Descrição|  
    |-----------------|---------------|  
    |**Cores**|Especifica o esquema de cores da imagem.  Selecione monocromático, cor de 16 ou 256 ou verdadeiro.  Se você já tiver desenhado a imagem com uma paleta de 16 cores, selecionar monocromático faz com que as substituições de preto e branco para as cores na imagem.  Contraste não seja sempre mantido: por exemplo, as áreas adjacentes de vermelho e verde são ambos convertidas em preto.|  
    |**Nome do arquivo**|Especifica o nome do arquivo de imagem.  Por padrão, o Visual Studio atribui um nome de arquivo base criado, removendo os quatro primeiros caracteres \("IDB\_"\) o identificador de recurso padrão \(IDB\_BITMAP1\) e o acréscimo a extensão apropriada.  O nome do arquivo da imagem neste exemplo seria BITMAP1.bmp.  Você pode renomeá\-lo MYBITMAP1.bmp.|  
    |**Height**|Define a altura da imagem \(em pixels\).  O valor padrão é 48.  A imagem está cortada ou espaço em branco é adicionado abaixo da imagem existente.|  
    |**ID**|Define o identificador do recurso.  Para uma imagem, Visual Studio da Microsoft, por padrão, atribui o próximo identificador disponível em uma série: IDB\_BITMAP1, IDB\_BITMAP2, e assim por diante.  Nomes semelhantes são usados para ícones e cursores.|  
    |**Paleta**|As alterações de propriedades de cores.  Clique duas vezes para selecionar uma cor e exibir o  [caixa de diálogo Seletor de cores personalizado](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md).  Defina a cor digitando os valores RGB ou HSL nas caixas de texto apropriado.|  
    |**SaveCompressed**|Indica se a imagem está em um formato compactado.  Esta propriedade é somente para leitura.  Visual Studio não permite salvar imagens em um formato compactado, portanto, para quaisquer imagens criadas no Visual Studio, essa propriedade será  **False**.  Se você abrir uma imagem compactada \(criada em outro programa\) em Visual Studio, essa propriedade será  **True**.  Se você salvar uma imagem compactada usando Visual Studio, ele será descompactado e essa propriedade será revertida para  **False**.|  
    |**Width**|Define a largura da imagem \(em pixels\).  O valor padrão para bitmaps é de 48.  A imagem está cortada ou espaço em branco é adicionado à direita da imagem existente.|  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)