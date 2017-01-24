---
title: "Cole&#231;&#245;es | Microsoft Docs"
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
  - "modelos de matriz"
  - "matrizes [C++], Classes "
  - "classes de coleção, sobre classes de coleção"
  - "classes de coleção, matrizes"
  - "classes de coleção, listas"
  - "classes de coleção, mapas"
  - "classes de coleção, MFC"
  - "classes de coleção, formas"
  - "classes de coleção, baseado em modelo"
  - "Coleções , sobre coleções"
  - "Classes de coleção MFC"
  - "MFC, Coleções "
  - "formas"
  - "formas, Coleção "
ms.assetid: 02586e4c-851d-41d0-a722-feb11c17c74c
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cole&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classes do Microsoft fornece classes de coleção para o gerenciamento de grupos de objetos.  Essas classes são de dois tipos:  
  
-   [Classes de coleção criadas de modelos C\+\+](#_core_the_template.2d.based_collection_classes)  
  
-   [Classes de coleção não criadas de modelos](#_core_the_collection_classes_not_based_on_templates)  
  
> [!NOTE]
>  Se seu código já usa classes de coleção de nontemplate, você poderá continuar a usá\-las.  Se você grava a nova coleção fortemente tipado para classificar seus próprios tipos de dados, recomendamos que você use as classes de baseadas mais recentes.  
  
##  <a name="_core_collection_shapes"></a> Forma da coleção  
 Uma classe de coleção é caracterizada por sua forma “” e os tipos de seus elementos.  A forma refere\-se à maneira como os objetos são organizados e armazenados pela coleção.  MFC O fornece três formas básicas da coleção: , matrizes e listas, mapas \(também conhecidos como dicionários\).  Você pode escolher a forma da coleção que é mais adequado ao seu problema específico de programação.  
  
 Cada uma das três formas fornecidas a coleção é descrita brevemente posteriormente neste tópico.  Para comparar os recursos de forma para ajudá\-lo a decidir qual é o melhor para seu programa, consulte [Recomendações para escolher uma classe de coleção](../Topic/Recommendations%20for%20Choosing%20a%20Collection%20Class.md).  
  
-   Lista  
  
     A classe da lista fornece uma lista ordenada, não indexada de elementos, implementada como uma lista vinculada double.  Uma lista tem um “início” e “uma parte final,” e adicionando ou removendo elementos de início ou da parte final, ou inserindo ou excluindo elementos no meio, é muito rapidamente.  
  
-   Matriz  
  
     A classe da matriz fornece uma matriz feita dimensionar dinamicamente, ordenado, e indexada total de objetos.  
  
-   O mapa \(também conhecido como um dicionário\)  
  
     Um mapa é uma coleção que associa um objeto de chave com um valor do objeto.  
  
##  <a name="_core_the_template.2d.based_collection_classes"></a> As classes com base na coleção  
 A maneira mais fácil de implementar uma coleção que contém objetos fortemente tipado de qualquer tipo é usar uma das classes com base em MFC.  Para obter exemplos dessas classes, consulte o exemplo [COLLECT](../top/visual-cpp-samples.md)MFC.  
  
 A tabela a seguir lista as classes com base em MFC da coleção.  
  
### Classes de modelo de coleção  
  
|Conteúdo da coleção|Matrizes|Listas|Mapas|  
|-------------------------|--------------|------------|-----------|  
|Coleções de objetos de qualquer tipo|`CArray`|`CList`|`CMap`|  
|As coleções de ponteiros para os objetos de qualquer tipo|`CTypedPtrArray`|`CTypedPtrList`|`CTypedPtrMap`|  
  
##  <a name="_core_the_collection_classes_not_based_on_templates"></a> As classes de coleção não baseadas em modelos  
 Se seu aplicativo já usa classes de nontemplate MFC, você poderá continuar a usá\-las.  No entanto, para novas coleções, recomendamos que você use as classes com base em log.  A tabela a seguir lista as classes de coleção de MFC que não se baseiam em modelos.  
  
### Classes de coleção de Nontemplate  
  
|Matrizes|Listas|Mapas|  
|--------------|------------|-----------|  
|`CObArray`|`CObList`|`CMapPtrToWord`|  
|`CByteArray`|`CPtrList`|`CMapPtrToPtr`|  
|`CDWordArray`|`CStringList`|`CMapStringToOb`|  
|`CPtrArray`||`CMapStringToPtr`|  
|`CStringArray`||`CMapStringToString`|  
|`CWordArray`||`CMapWordToOb`|  
|`CUIntArray`||`CMapWordToPtr`|  
  
 As características da tabela de classes de coleção de MFC em [Recomendações para escolher uma classe de coleção](../Topic/Recommendations%20for%20Choosing%20a%20Collection%20Class.md) descrevem as classes de coleção de MFC em termos dessas características \(diferente da forma\):  
  
-   Se a classe usa modelos C\+\+  
  
-   Se os elementos armazenados na coleção podem ser serializados  
  
-   Se os elementos da coleção podem ser armazenados despejados para diagnóstico  
  
-   Se a coleção é fortemente tipado  
  
### O que você deseja fazer?  
  
#### Tarefas gerais da classe Coleção\-  
  
-   [Recomendações para escolher uma classe de coleção](../Topic/Recommendations%20for%20Choosing%20a%20Collection%20Class.md)  
  
-   [Como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)  
  
-   [Criando coleções de pilhas e filas](../mfc/creating-stack-and-queue-collections.md)  
  
-   [CArray::Add](../Topic/CArray::Add.md)  
  
#### Tarefas com base em Coleção\- classe  
  
-   [Classes com base no modelo](../Topic/Template-Based%20Classes.md)  
  
#### Acessando os membros de uma coleção baseada em \(ou não\)  
  
-   [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)  
  
-   [Excluindo todos os objetos em uma coleção CObject](../Topic/Deleting%20All%20Objects%20in%20a%20CObject%20Collection.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)