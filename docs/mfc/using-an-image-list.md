---
title: "Usando uma lista de imagens | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CImageList, usando"
  - "listas de imagens [C++]"
  - "listas [C++], imagem"
ms.assetid: e0aed188-a1e6-400e-9f51-033d61c5541f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma lista de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso típico de uma lista de imagem segue o padrão abaixo:  
  
-   Construir um objeto de [CImageList](../Topic/CImageList%20Class.md) e chame uma das sobrecargas da função de [Crie](../Topic/CImageList::Create.md) para criar uma lista de imagem e para conecta\-o ao objeto de `CImageList` .  
  
-   Se você não adicionar imagens quando você cria a lista da imagem, adicionar imagens à lista de imagem chamando a função de membro de [Adicionar](../Topic/CImageList::Add.md) ou de [Leitura](../Topic/CImageList::Read.md) .  
  
-   Associar a lista de imagem com um controle chamando a função de membro apropriado desse controle, ou imagens na lista de imagem você mesmo de descompasso que usa a função de membro de [Desenhe](../Topic/CImageList::Draw.md) da lista da imagem.  
  
-   Talvez permite que o usuário arrasta uma imagem, usando o suporte interno da lista de imagem arraste para.  
  
> [!NOTE]
>  Se a lista de imagem foi criada com o operador de **new** , você deve destruir o objeto de `CImageList` quando você terminar a ela.  
  
## Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)