---
title: "Criando cole&#231;&#245;es de pilhas e filas | Microsoft Docs"
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
  - "classes de coleção, criando"
  - "Coleções , queue"
  - "Coleções , stack"
  - "Classes de coleção MFC, coleções de fila"
  - "Classes de coleção MFC, coleções de pilha"
  - "coleções de fila"
  - "stack"
  - "coleções de pilha"
ms.assetid: 3c7bc198-35f0-4fc3-aaed-6005a0f22638
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando cole&#231;&#245;es de pilhas e filas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como criar outras estruturas de dados, como [pilhas](#_core_stacks) e [filas](#_core_queues), das classes de MFC lista.  Os exemplos usam as classes derivadas de `CList`, mas você pode usar `CList` diretamente a menos que você precise adicionar funcionalidade.  
  
##  <a name="_core_stacks"></a> Pilhas  
 Porque a coleção padrão da lista tem um início e uma parte final, é fácil criar uma coleção derivado da lista que imite o comportamento de uma último\-em\- primeira em expansão pilha.  Uma pilha é como uma pilha de bandejas em um pub.  Como as bandejas são adicionadas à pilha, não na pilha.  A superfície da última adicionada é a primeira a ser removida.  As funções de membro `AddHead` e `RemoveHead` da coleção da lista podem ser usadas para adicionar e remover especificamente os elementos do início da lista; assim, o elemento é adicionado recentemente o primeiro a ser removido.  
  
#### Para criar uma coleção de pilha  
  
1.  Derivar uma nova classe da lista de uma das classes existentes na lista de MFC e adicionar mais funções de membro para dar suporte à funcionalidade de operações de pilha.  
  
     O exemplo a seguir mostra como adicionar sobre funções de membro para elementos de envio para a pilha, espreitá\-las no elemento superior da pilha, e exibida o elemento superior da pilha:  
  
     [!code-cpp[NVC_MFCCollections#20](../mfc/codesnippet/CPP/creating-stack-and-queue-collections_1.h)]  
  
 Observe que esta abordagem expõe a classe subjacente de `CObList` .  O usuário pode chamar qualquer função de membro de `CObList` , se faz sentido para uma pilha ou não.  
  
##  <a name="_core_queues"></a> Filas  
 Porque a coleção padrão da lista tem um início e uma parte final, também é fácil criar uma coleção derivado da lista que imite o comportamento de uma uma primeira em expansão fila.  Uma fila é como uma linha de pessoas em um pub.  A pessoa na primeira linha é a primeira a ser atendida.  à medida que mais pessoas vêm, vá até o final da linha aguarda a sua volta.  As funções de membro `AddTail` e `RemoveHead` da coleção da lista podem ser usadas para adicionar e remover especificamente os elementos de início ou do final da lista; assim, o elemento é adicionado recentemente sempre o último a ser removido.  
  
#### Para criar uma coleção de fila  
  
1.  Derivar uma nova classe da lista de uma das classes predefinidas da lista fornecidas com a biblioteca de classes do Microsoft e adicionar mais funções de membro para dar suporte a semântica de operações de fila.  
  
     O exemplo a seguir mostra como você pode acrescentar funções de membro para adicionar um elemento ao final da fila e para obter o elemento da frente da fila.  
  
     [!code-cpp[NVC_MFCCollections#21](../mfc/codesnippet/CPP/creating-stack-and-queue-collections_2.h)]  
  
## Consulte também  
 [Coleções](../mfc/collections.md)