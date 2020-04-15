---
title: Coleções
ms.date: 11/04/2016
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
ms.openlocfilehash: 3fba3a3c6cd3fecbda7f46575b1d72c450c44019
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361866"
---
# <a name="collections"></a>Coleções

A Biblioteca de Classes da Microsoft Foundation fornece classes de coleção para gerenciar grupos de objetos. Estas classes são de dois tipos:

- [Classes de coleção criadas a partir de modelos C++](#_core_the_template_based_collection_classes)

- [Classes de coleção não criadas a partir de modelos](#_core_the_collection_classes_not_based_on_templates)

> [!NOTE]
> Se o seu código já usa classes de coleta não-modelo, você pode continuar a usá-las. Se você escrever novas classes de coleta seguras para seus próprios tipos de dados, recomendamos que você use as classes mais novas baseadas em modelos.

## <a name="collection-shapes"></a><a name="_core_collection_shapes"></a>Formas de coleção

Uma classe de coleção é caracterizada por sua "forma" e pelos tipos de seus elementos. A forma refere-se à forma como os objetos são organizados e armazenados pela coleção. O MFC fornece três formas básicas de coleção: listas, matrizes e mapas (também conhecidos como dicionários). Você pode escolher a forma de coleção mais adequada ao seu problema de programação particular.

Cada uma das três formas de coleta fornecidas é descrita brevemente mais tarde neste tópico. Para comparar os recursos das formas para ajudá-lo a decidir qual é o melhor para o seu programa, consulte [Recomendações para Escolher uma Classe de Coleção](../mfc/recommendations-for-choosing-a-collection-class.md).

- Lista

   A classe de lista fornece uma lista ordenada e não indexada de elementos, implementada como uma lista duplamente vinculada. Uma lista tem uma "cabeça" e uma "cauda", e adicionar ou remover elementos da cabeça ou cauda, ou inserir ou excluir elementos no meio, é muito rápido.

- Array

   A classe de matriz fornece uma matriz de objetos de tamanho dinâmico, ordenado e indexado a inteiros.

- Mapa (também conhecido como dicionário)

   Um mapa é uma coleção que associa um objeto-chave a um objeto de valor.

## <a name="the-template-based-collection-classes"></a><a name="_core_the_template_based_collection_classes"></a>As classes de coleção baseadas em modelos

A maneira mais fácil de implementar uma coleção segura de tipo que contém objetos de qualquer tipo é usar uma das classes baseadas em modelos MFC. Para exemplos dessas classes, consulte a amostra de MFC [COLLECT](../overview/visual-cpp-samples.md).

A tabela a seguir lista as classes de coleção baseadas em modelos MFC.

### <a name="collection-template-classes"></a>Classes de modelo de coleção

|Conteúdo da coleção|Matrizes|Listas|Mapas|
|-------------------------|------------|-----------|----------|
|Coleções de objetos de qualquer tipo|`CArray`|`CList`|`CMap`|
|Coleções de ponteiros para objetos de qualquer tipo|`CTypedPtrArray`|`CTypedPtrList`|`CTypedPtrMap`|

## <a name="the-collection-classes-not-based-on-templates"></a><a name="_core_the_collection_classes_not_based_on_templates"></a>As classes de coleta não baseadas em modelos

Se o aplicativo já usar classes não-modelo mfc, você pode continuar a usá-las. No entanto, para novas coleções, recomendamos que você use as classes baseadas em modelos. A tabela a seguir lista as classes de coleção MFC que não são baseadas em modelos.

### <a name="nontemplate-collection-classes"></a>Classes de coleta não-modelo

|Matrizes|Listas|Mapas|
|------------|-----------|----------|
|`CObArray`|`CObList`|`CMapPtrToWord`|
|`CByteArray`|`CPtrList`|`CMapPtrToPtr`|
|`CDWordArray`|`CStringList`|`CMapStringToOb`|
|`CPtrArray`||`CMapStringToPtr`|
|`CStringArray`||`CMapStringToString`|
|`CWordArray`||`CMapWordToOb`|
|`CUIntArray`||`CMapWordToPtr`|

A tabela Características das Classes de Coleção MFC em [Recomendações para A Escolha de uma Classe de Coleção](../mfc/recommendations-for-choosing-a-collection-class.md) descreve as classes de coleta de MFC em termos dessas características (além da forma):

- Se a classe usa modelos C++

- Se os elementos armazenados na coleção podem ser serializados

- Se os elementos armazenados na coleção podem ser despejados para diagnóstico

- Se a coleção é segura para o tipo

### <a name="what-do-you-want-to-do"></a>O que você quer fazer?

#### <a name="general-collection-class-tasks"></a>Tarefas gerais da classe de coleta

- [Recomendações para escolher uma classe de coleção](../mfc/recommendations-for-choosing-a-collection-class.md)

- [Como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)

- [Criando coleções de pilhas e filas](../mfc/creating-stack-and-queue-collections.md)

- [CArray::Adicionar](../mfc/reference/carray-class.md#add)

#### <a name="template-based-collection-class-tasks"></a>Tarefas da classe de coleta baseadaem em modelos

- [Classes baseadas em modelos](../mfc/template-based-classes.md)

#### <a name="accessing-the-members-of-a-collection-template-based-or-not"></a>Acessando os Membros de uma Coleção (baseada em modelos ou não)

- [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)

- [Excluindo todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md)

## <a name="see-also"></a>Confira também

[Conceitos](../mfc/mfc-concepts.md)<br/>
[Tópicos MFC gerais](../mfc/general-mfc-topics.md)
