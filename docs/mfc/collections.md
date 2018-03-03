---
title: "Coleções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC, collections
- arrays [MFC], classes
- MFC collection classes
- shapes, collection
- collection classes [MFC], MFC
- collections, about collections
- array templates [MFC]
- collection classes [MFC], template-based
- collection classes [MFC], about collection classes
- collection classes [MFC], maps
- collection classes [MFC], arrays
- shapes
- collection classes [MFC], lists
- collection classes [MFC], shapes
ms.assetid: 02586e4c-851d-41d0-a722-feb11c17c74c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0e980f3f8fe86b621cb1494b08aec3fcdcb49f54
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="collections"></a>Coleções
A biblioteca Microsoft Foundation Class fornece classes de coleção para gerenciar grupos de objetos. Essas classes são de dois tipos:  
  
-   [Classes de coleção criados a partir de modelos C++](#_core_the_template_based_collection_classes)  
  
-   [Classes de coleção não criados a partir de modelos](#_core_the_collection_classes_not_based_on_templates)  
  
> [!NOTE]
>  Se seu código utiliza as classes de coleção de nontemplate, você pode continuar a usá-los. Se você escrever novas classes de coleção de tipo seguro para seus próprios tipos de dados, é recomendável que você use as classes de baseado em modelo mais recentes.  
  
##  <a name="_core_collection_shapes"></a>Formas de coleção  
 Uma classe de coleção é caracterizada por "forma" e nos tipos de seus elementos. A forma refere-se à forma como os objetos são organizados e armazenados na coleção. MFC oferece três formas de coleção básica: lista, matrizes e mapas (também conhecido como dicionários). Você pode escolher a forma de coleção que é mais adequada ao seu problema específico de programação.  
  
 Cada uma das três formas de coleção fornecida é descrita resumidamente posteriormente neste tópico. Para comparar os recursos das formas para ajudá-lo a decidir o que é melhor para seu programa, consulte [recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md).  
  
-   Lista  
  
     A classe de lista fornece uma lista ordenada de elementos, implementado como uma lista duplamente vinculada não indexada. Uma lista tem um "head" e "final" e adicionando ou removendo elementos do cabeçalho ou final, ou inserindo ou excluindo elementos no meio, é muito rápida.  
  
-   Matriz  
  
     Classe array fornece uma matriz dinamicamente dimensionada, ordenada e indexadas inteiro de objetos.  
  
-   Mapa (também conhecido como um dicionário)  
  
     Um mapa é uma coleção que associa um objeto de chave com um objeto de valor.  
  
##  <a name="_core_the_template_based_collection_classes"></a>As Classes de coleção com base em modelo  
 A maneira mais fácil de implementar uma coleção fortemente tipada que contém objetos de qualquer tipo é usar uma das classes MFC com base em modelo. Para obter exemplos dessas classes, consulte o exemplo MFC [COLETAR](../visual-cpp-samples.md).  
  
 A tabela a seguir lista as classes de coleção com base em modelo do MFC.  
  
### <a name="collection-template-classes"></a>Classes de modelo de coleção  
  
|Conteúdo da coleção|Matrizes|Listas|Mapas|  
|-------------------------|------------|-----------|----------|  
|Coleções de objetos de qualquer tipo|`CArray`|`CList`|`CMap`|  
|Coleções de ponteiros para objetos de qualquer tipo|`CTypedPtrArray`|`CTypedPtrList`|`CTypedPtrMap`|  
  
##  <a name="_core_the_collection_classes_not_based_on_templates"></a>As Classes de coleção não com base em modelos  
 Se seu aplicativo já utiliza as classes do MFC nontemplate, você pode continuar a usá-los. No entanto, para novas coleções, recomendamos que você use as classes de modelo. A tabela a seguir lista as classes de coleção MFC que não são baseadas em modelos.  
  
### <a name="nontemplate-collection-classes"></a>Classes de coleção de nontemplate  
  
|Matrizes|Listas|Mapas|  
|------------|-----------|----------|  
|`CObArray`|`CObList`|`CMapPtrToWord`|  
|`CByteArray`|`CPtrList`|`CMapPtrToPtr`|  
|`CDWordArray`|`CStringList`|`CMapStringToOb`|  
|`CPtrArray`||`CMapStringToPtr`|  
|`CStringArray`||`CMapStringToString`|  
|`CWordArray`||`CMapWordToOb`|  
|`CUIntArray`||`CMapWordToPtr`|  
  
 As características de Classes de coleção do MFC tabela [recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md) descreve as classes de coleção MFC em termos essas características (diferente de forma):  
  
-   Se a classe usar modelos do C++  
  
-   Se os elementos armazenados na coleção podem ser serializados  
  
-   Se os elementos armazenados na coleção podem ser despejados para diagnóstico  
  
-   Se a coleção é fortemente tipado  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
#### <a name="general-collection-class-tasks"></a>Classe de coleção geral de tarefas  
  
-   [Recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md)  
  
-   [Como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)  
  
-   [Criando coleções de pilhas e filas](../mfc/creating-stack-and-queue-collections.md)  
  
-   [CArray::Add](../mfc/reference/carray-class.md#add)  
  
#### <a name="template-based-collection-class-tasks"></a>Tarefas de classe de coleção com base em modelo  
  
-   [Classes com base no modelo](../mfc/template-based-classes.md)  
  
#### <a name="accessing-the-members-of-a-collection-template-based-or-not"></a>Acessando membros de uma coleção (baseado em modelo ou não)  
  
-   [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)  
  
-   [Excluindo todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

