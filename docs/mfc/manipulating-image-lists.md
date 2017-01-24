---
title: "Manipulando listas de imagens | Microsoft Docs"
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
  - "Classe CImageList, manipulando"
  - "listas de imagens [C++], manipulando"
  - "listas [C++], imagem"
ms.assetid: 043418f8-077e-4dce-b8bb-2b7b0d7b5156
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando listas de imagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A função de membro de [Substituir](../Topic/CImageList::Replace.md) substitui uma imagem em uma lista de imagem \([CImageList](../Topic/CImageList%20Class.md)\) com uma nova imagem.  Essa função também é útil se você precisar aumentar dinamicamente o número de imagens em um objeto da lista da imagem.  A função de [SetImageCount](../Topic/CImageList::SetImageCount.md) alterar dinamicamente o número de imagens armazenadas na lista da imagem.  Se você aumentar o tamanho da lista de imagem, chame **Substituir** para adicionar imagens a novos slots da imagem.  Se você diminuir o tamanho da lista de imagem, as imagens além do novo tamanho são liberadas.  
  
 A função de membro de [Remover](../Topic/CImageList::Remove.md) remove uma imagem de uma lista de imagem.  A função de membro de [Cópia](../Topic/CImageList::Copy.md) pode copiar ou alternar imagens dentro de uma imagem listar.  Esta função permite que você indica se a imagem de origem devem ser copiados para o índice de destino ou imagens de origem e de destino devem ser alternadas.  
  
 Para criar uma nova lista de imagem mesclando duas listas da imagem, use a sobrecarga apropriado da função de membro de [Crie](../Topic/CImageList::Create.md) .  Essa sobrecarga de **Criar** mescla a primeira imagem das listas existentes da imagem, armazenando a imagem resultante em um novo objeto da lista da imagem.  A nova imagem é criada para desenhar a segunda imagem transparente na primeira.  A máscara para a nova imagem é o resultado da execução de uma operação OR lógica bit em duas das máscaras para as imagens existentes.  
  
 Isto é repetido até que todas as imagens sejam mescladas e adicionadas ao novo objeto da lista da imagem.  
  
 Você pode gravar informações da imagem em um arquivo morto chamando a função de membro de [Gravação](../Topic/CImageList::Write.md) , e ler\-la novamente chamando a função de membro de [Leitura](../Topic/CImageList::Read.md) .  
  
 [GetSafeHandle](../Topic/CImageList::GetSafeHandle.md), [Anexar](../Topic/CImageList::Attach.md), e as funções de membro de [Desanexar](../Topic/CImageList::Detach.md) permitem que você manipule a alça da lista de imagem anexada ao objeto de `CImageList` , enquanto a função de membro de [DeleteImageList](../Topic/CImageList::DeleteImageList.md) excluir a lista de imagem sem destruir o objeto de `CImageList` .  
  
## Consulte também  
 [Usando CImageList](../mfc/using-cimagelist.md)   
 [Controles](../mfc/controls-mfc.md)