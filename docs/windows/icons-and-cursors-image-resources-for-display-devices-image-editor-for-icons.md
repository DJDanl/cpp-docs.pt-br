---
title: "&#205;cones e cursores: recursos de imagem para exibir dispositivos (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.icon"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cursores [C++], criando"
  - "recursos de imagem, dispositivos de exibição"
  - "ícones [C++], criando"
  - "cursores [C++], tipos"
  - "ícones [C++]"
  - "Editor de imagem [C++], ícones e cursores"
  - "cursores [C++]"
  - "dispositivos de exibição, criando ícones para"
  - "cursores [C++], pontos de acesso"
  - "ícones [C++], tipos"
ms.assetid: 8f0809a8-0cf0-4da9-b23d-51f28bf15f5b
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &#205;cones e cursores: recursos de imagem para exibir dispositivos (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ícones e cursores são recursos gráficos que podem conter várias imagens em tamanhos diferentes e esquemas para diferentes tipos de dispositivos de exibição de cores. Além disso, um cursor tem um "ponto de acesso", o local em que o Windows usa para controlar sua posição. Ícones e cursores são criados e editados usando o editor de imagens, assim como bitmaps e outras imagens.  
  
 Quando você cria um novo ícone ou cursor, o editor de imagem primeiro cria uma imagem de um tipo padrão. Inicialmente, a imagem é preenchida com a cor da tela \(transparente\). Se a imagem for um cursor, o ponto de acesso é inicialmente o canto superior esquerdo \(coordenadas 0,0\).  
  
 Por padrão, o editor de imagem oferece suporte a criação de imagens adicionais para os dispositivos mostrados na tabela a seguir. Você pode criar imagens de outros dispositivos digitando parâmetros de largura, altura e contagem de cor para o [caixa de diálogo imagem personalizada](../mfc/custom-image-dialog-box-image-editor-for-icons.md).  
  
> [!NOTE]
>  Usando o Editor de imagens, você pode exibir imagens de 32 bits, mas você não pode editá\-los.  
  
|Cor|Largura \(pixels\)|Altura \(pixels\)|  
|---------|------------------------|-----------------------|  
|Monocromático|16|16|  
|Monocromático|32|32|  
|Monocromático|48|48|  
|Monocromático|64|64|  
|Monocromático|96|96|  
|16|16|16|  
|16|32|32|  
|16|64|64|  
|16|48|48|  
|16|96|96|  
|256|16|16|  
|256|32|32|  
|256|48|48|  
|256|64|64|  
|256|96|96|  
  
-   [Criar uma nova imagem de dispositivo \(ícone ou Cursor\)](../mfc/creating-a-device-image-image-editor-for-icons.md)  
  
-   [Adicionando uma imagem para um dispositivo de exibição diferente](../mfc/adding-an-image-for-a-different-display-device-image-editor-for-icons.md)  
  
-   [Copiando imagem de um dispositivo](../mfc/copying-a-device-image-image-editor-for-icons.md)  
  
-   [Excluindo a imagem de um dispositivo](../Topic/Deleting%20a%20Device%20Image%20\(Image%20Editor%20for%20Icons\).md)  
  
-   [Criando regiões transparentes ou inversas em imagens de dispositivo](../mfc/creating-transparent-or-inverse-regions-in-device-images.md)  
  
-   [Criando um ícone ou cursor de 256 cores](../mfc/creating-a-256-color-icon-or-cursor-image-editor-for-icons.md)  
  
-   [Definindo um ponto de acesso do cursor](../Topic/Setting%20a%20Cursor's%20Hot%20Spot%20\(Image%20Editor%20for%20Icons\).md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Nenhum  
  
## Consulte também  
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)   
 [Ícones](http://msdn.microsoft.com/library/windows/desktop/ms646973)   
 [Cursores](http://msdn.microsoft.com/library/windows/desktop/ms646970)