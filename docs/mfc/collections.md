---
title: Coleções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 72bae0d985c81478321109c3c02c07e6b1386028
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069900"
---
# <a name="collections"></a>Coleções

A biblioteca Microsoft Foundation Class fornece classes de coleção para gerenciar grupos de objetos. Essas classes são de dois tipos:

- [Classes de coleção criadas a partir de modelos C++](#_core_the_template_based_collection_classes)

- [Classes de coleção não criadas a partir de modelos](#_core_the_collection_classes_not_based_on_templates)

> [!NOTE]
>  Se seu código já usa as classes de coleção de fora do modelo, você pode continuar a usá-los. Se você escrever novas classes de coleção fortemente tipada para seus próprios tipos de dados, é recomendável que você use as classes de baseado em modelo mais recentes.

##  <a name="_core_collection_shapes"></a> Formas de coleção

Uma classe de coleção é caracterizada por seu "forma" e os tipos de seus elementos. A forma refere-se à forma como os objetos são organizados e armazenados na coleção. O MFC fornece três formas básicas de coleta: listas, matrizes e mapas (também conhecido como dicionários). Você pode escolher a forma de coleção que é mais adequada ao seu problema específico de programação.

Cada uma das três formas de coleção fornecida é descrita brevemente posteriormente neste tópico. Para comparar os recursos das formas para ajudar você a decidir qual é o melhor para o seu programa, consulte [recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md).

- Lista

   A classe de lista fornece uma lista ordenada e não indexada de elementos, implementado como uma lista duplamente vinculada. Uma lista tem um "head" e "final" e adicionando ou removendo elementos do head ou da parte final do, ou inserindo ou excluindo elementos no meio, é muito rápida.

- Matriz

   A classe array fornece uma matriz dinamicamente dimensionada, ordenada e indexados de inteiro de objetos.

- Mapa (também conhecido como um dicionário)

   Um mapa é uma coleção que associa um objeto de chave com um objeto de valor.

##  <a name="_core_the_template_based_collection_classes"></a> As Classes de coleção com base em modelo

A maneira mais fácil de implementar uma coleção fortemente tipada que contém objetos de qualquer tipo é usar uma das classes do MFC com base no modelo. Para obter exemplos dessas classes, consulte o exemplo MFC [COLETAR](../visual-cpp-samples.md).

A tabela a seguir lista as classes de coleção com base no modelo do MFC.

### <a name="collection-template-classes"></a>Classes de modelo de coleção

|Conteúdo da coleção|Matrizes|Listas|Mapas|
|-------------------------|------------|-----------|----------|
|Coleções de objetos de qualquer tipo|`CArray`|`CList`|`CMap`|
|Coleções de ponteiros para objetos de qualquer tipo|`CTypedPtrArray`|`CTypedPtrList`|`CTypedPtrMap`|

##  <a name="_core_the_collection_classes_not_based_on_templates"></a> As Classes de coleção não baseadas em modelos

Se seu aplicativo já usa classes do MFC fora do modelo, você pode continuar a usá-los. No entanto, para novas coleções, é recomendável que você use as classes com base no modelo. A tabela a seguir lista as classes de coleção MFC que não são baseadas em modelos.

### <a name="nontemplate-collection-classes"></a>Classes de coleção de fora do modelo

|Matrizes|Listas|Mapas|
|------------|-----------|----------|
|`CObArray`|`CObList`|`CMapPtrToWord`|
|`CByteArray`|`CPtrList`|`CMapPtrToPtr`|
|`CDWordArray`|`CStringList`|`CMapStringToOb`|
|`CPtrArray`||`CMapStringToPtr`|
|`CStringArray`||`CMapStringToString`|
|`CWordArray`||`CMapWordToOb`|
|`CUIntArray`||`CMapWordToPtr`|

As características das Classes de coleção do MFC na tabela [recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md) descreve as classes de coleção MFC em termos dessas características (diferente de forma):

- Se a classe usa modelos de C++

- Se os elementos armazenados na coleção podem ser serializados

- Se os elementos armazenados na coleção podem ser despejados para diagnóstico

- Se a coleção é fortemente tipado

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer

#### <a name="general-collection-class-tasks"></a>Classe de coleção geral de tarefas

- [Recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md)

- [Como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)

- [Criando coleções de pilhas e filas](../mfc/creating-stack-and-queue-collections.md)

- [CArray::Add](../mfc/reference/carray-class.md#add)

#### <a name="template-based-collection-class-tasks"></a>Classe de coleção com base no modelo de tarefas

- [Classes com base no modelo](../mfc/template-based-classes.md)

#### <a name="accessing-the-members-of-a-collection-template-based-or-not"></a>Acessando os membros de uma coleção (com base no modelo ou não)

- [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)

- [Excluindo todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md)

## <a name="see-also"></a>Consulte também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

