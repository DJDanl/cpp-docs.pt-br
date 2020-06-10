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
ms.openlocfilehash: f2cd03afbb09dff38298454658c3d3dc2dfa6a8a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619356"
---
# <a name="collections"></a>Coleções

O biblioteca MFC fornece classes de coleção para gerenciar grupos de objetos. Essas classes são de dois tipos:

- [Classes de coleção criadas a partir de modelos C++](#_core_the_template_based_collection_classes)

- [Classes de coleção não criadas a partir de modelos](#_core_the_collection_classes_not_based_on_templates)

> [!NOTE]
> Se seu código já usa classes de coleção não modelo, você pode continuar a usá-las. Se você escrever novas classes de coleção de tipo seguro para seus próprios tipos de dados, recomendamos que você use as classes baseadas em modelo mais recentes.

## <a name="collection-shapes"></a><a name="_core_collection_shapes"></a>Formas de coleção

Uma classe de coleção é caracterizada por sua "forma" e pelos tipos de seus elementos. A forma refere-se à maneira como os objetos são organizados e armazenados pela coleção. O MFC fornece três formas de coleção básicas: listas, matrizes e mapas (também conhecidos como dicionários). Você pode escolher a forma de coleção mais adequada ao seu problema de programação específico.

Cada uma das três formas de coleção fornecidas é descrita brevemente mais adiante neste tópico. Para comparar os recursos das formas para ajudá-lo a decidir qual é a melhor para o seu programa, consulte [recomendações para escolher uma classe de coleção](recommendations-for-choosing-a-collection-class.md).

- Lista

   A classe List fornece uma lista ordenada e não indexada de elementos, implementada como uma lista vinculada dupla. Uma lista tem um "Head" e um "Tail", e adicionar ou remover elementos do cabeçalho ou da parte final, ou inserir ou excluir elementos no meio, é muito rápido.

- Array

   A classe Array fornece uma matriz de objetos de dimensionamento, ordenada e com índices inteiros.

- Mapa (também conhecido como um dicionário)

   Um mapa é uma coleção que associa um objeto de chave a um objeto de valor.

## <a name="the-template-based-collection-classes"></a><a name="_core_the_template_based_collection_classes"></a>As classes de coleção baseadas em modelo

A maneira mais fácil de implementar uma coleção com segurança de tipo que contém objetos de qualquer tipo é usar uma das classes baseadas em modelo MFC. Para obter exemplos dessas classes, consulte o exemplo de MFC [coletar](../overview/visual-cpp-samples.md).

A tabela a seguir lista as classes de coleção baseadas em modelo MFC.

### <a name="collection-template-classes"></a>Classes de modelo de coleção

|Conteúdo da coleção|Matrizes|Listas|Mapas|
|-------------------------|------------|-----------|----------|
|Coleções de objetos de qualquer tipo|`CArray`|`CList`|`CMap`|
|Coleções de ponteiros para objetos de qualquer tipo|`CTypedPtrArray`|`CTypedPtrList`|`CTypedPtrMap`|

## <a name="the-collection-classes-not-based-on-templates"></a><a name="_core_the_collection_classes_not_based_on_templates"></a>As classes de coleção não são baseadas em modelos

Se seu aplicativo já usa classes não modelo MFC, você pode continuar a usá-las. No entanto, para novas coleções, recomendamos que você use as classes baseadas em modelo. A tabela a seguir lista as classes de coleção do MFC que não são baseadas em modelos.

### <a name="nontemplate-collection-classes"></a>Classes de coleção não modelo

|Matrizes|Listas|Mapas|
|------------|-----------|----------|
|`CObArray`|`CObList`|`CMapPtrToWord`|
|`CByteArray`|`CPtrList`|`CMapPtrToPtr`|
|`CDWordArray`|`CStringList`|`CMapStringToOb`|
|`CPtrArray`||`CMapStringToPtr`|
|`CStringArray`||`CMapStringToString`|
|`CWordArray`||`CMapWordToOb`|
|`CUIntArray`||`CMapWordToPtr`|

As características da tabela de classes de coleção do MFC em [recomendações para escolher uma classe de coleção](recommendations-for-choosing-a-collection-class.md) descrevem as classes de coleção do MFC em termos dessas características (além da forma):

- Se a classe usa modelos C++

- Se os elementos armazenados na coleção podem ser serializados

- Se os elementos armazenados na coleção podem ser despejados para diagnóstico

- Se a coleção é de tipo seguro

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer

#### <a name="general-collection-class-tasks"></a>Coleção geral – tarefas de classe

- [Recomendações para escolher uma classe de coleção](recommendations-for-choosing-a-collection-class.md)

- [Como fazer uma coleção fortemente tipada](how-to-make-a-type-safe-collection.md)

- [Criando coleções de pilhas e filas](creating-stack-and-queue-collections.md)

- [CArray:: Adicionar](reference/carray-class.md#add)

#### <a name="template-based-collection-class-tasks"></a>Tarefas de classe de coleção baseada em modelo

- [Classes baseadas em modelo](template-based-classes.md)

#### <a name="accessing-the-members-of-a-collection-template-based-or-not"></a>Acessando os membros de uma coleção (baseado em modelo ou não)

- [Acessando todos os membros de uma coleção](accessing-all-members-of-a-collection.md)

- [Excluindo todos os objetos em uma coleção CObject](deleting-all-objects-in-a-cobject-collection.md)

## <a name="see-also"></a>Consulte também

[Conceitos](mfc-concepts.md)<br/>
[Tópicos MFC gerais](general-mfc-topics.md)
