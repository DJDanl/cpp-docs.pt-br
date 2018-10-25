---
title: Classes com base no modelo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- type-safe collections
- CTypedPtrList class [MFC], template-based classes
- arrays [MFC], classes
- arrays [MFC], pointers
- typed pointers, collections of
- arrays [MFC], template-based
- CArray class [MFC], template-based classes
- simple template-based collections
- simple array collection classes [MFC]
- typed pointers
- collections, typed-pointer
- CList class [MFC], template-based classes
- collection classes [MFC], template-based
- CTypedPtrMap class [MFC], template-based classes
- pointers, collections of typed
- CTypedPtrArray class [MFC], template-based classes
- MFC collection classes [MFC], template-based
- template-based collection classes [MFC]
- simple list collection classes [MFC]
ms.assetid: c69fc95b-c8f6-4a99-abed-517c9898ef0c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b972d4552a8e41ca0dcea4ef57d48ef161ea35b9
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069224"
---
# <a name="template-based-classes"></a>Classes com base no modelo

Este artigo explica as classes fortemente tipadas com base no modelo de coleção MFC versão 3.0 e posterior. Usando esses modelos para criar coleções fortemente tipadas é mais conveniente e ajuda a fornecer segurança de tipos com mais eficiência do que usar as classes de coleção não baseadas em modelos.

MFC predefine duas categorias de coleções com base em modelo:

- [Matriz simples, lista e classes de mapa](#_core_using_simple_array.2c_.list.2c_.and_map_templates)

   `CArray`, `CList`, `CMap`

- [Matrizes, listas e mapas de ponteiros tipados](#_core_using_typed.2d.pointer_collection_templates)

   `CTypedPtrArray`, `CTypedPtrList`, `CTypedPtrMap`

As classes de coleção simples são derivadas da classe `CObject`, portanto, eles herdam a serialização, criação dinâmica e outras propriedades de `CObject`. As classes de coleção com tipo de ponteiro que você especifique a classe derivar de — que deve ser uma das coleções de ponteiro nontemplate predefinidas pelo MFC, como `CPtrList` ou `CPtrArray`. Sua nova classe de coleção herda da classe base especificado e funções de membro da classe nova usam encapsuladas chamadas para os membros da classe base para impor a segurança de tipos.

Para obter mais informações sobre modelos de C++, consulte [modelos](../cpp/templates-cpp.md) na *referência da linguagem C++*.

##  <a name="_core_using_simple_array.2c_.list.2c_.and_map_templates"></a> Usando a matriz simples, lista e modelos de mapa

Para usar os modelos de coleção simples, você precisa saber qual tipo de dados que você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleção.

###  <a name="_core_simple_array_and_list_usage"></a> Matriz simples e o uso de lista

As classes de lista e uma matriz simples [CArray](../mfc/reference/carray-class.md) e [CList](../mfc/reference/clist-class.md), usam dois parâmetros: *tipo* e `ARG_TYPE`. Essas classes podem armazenar qualquer tipo de dados, que você especificar na *tipo* parâmetro:

- Tipos de dados fundamental do C++, como **int**, **char**, e **float**

- Classes e estruturas do C++

- Outros tipos que você definir

Para conveniência e a eficiência, você pode usar o *ARG_TYPE* parâmetro para especificar o tipo dos argumentos da função. Normalmente, você especifica *ARG_TYPE* como uma referência para o tipo nomeado na *tipo* parâmetro. Por exemplo:

[!code-cpp[NVC_MFCCollections#1](../mfc/codesnippet/cpp/template-based-classes_1.cpp)]

O primeiro exemplo declara uma coleção de matrizes `myArray`, que contém **int**s. O segundo exemplo declara uma coleção de lista `myList`, que armazena `CPerson` objetos. Determinadas funções de membro das classes de coleção usam argumentos cujo tipo é especificado, o *ARG_TYPE* parâmetro de modelo. Por exemplo, o `Add` função de membro da classe `CArray` leva um *ARG_TYPE* argumento:

[!code-cpp[NVC_MFCCollections#2](../mfc/codesnippet/cpp/template-based-classes_2.cpp)]

###  <a name="_core_simple_map_usage"></a> Uso do mapa simples

A classe de mapa simples, [CMap](../mfc/reference/cmap-class.md), assume quatro parâmetros: *chave*, *ARG_KEY*, *valor*, e *ARG_VALUE*. Assim como as classes de matriz e lista, as classes de mapa podem armazenar qualquer tipo de dados. Ao contrário das matrizes e listas, o que o índice e ordem os dados que eles armazenam, mapas de associar as chaves e valores: você acessa um valor armazenado em um mapa especificando de chave associado um valor. O *chave* parâmetro especifica o tipo de dados das chaves usadas para acessar dados armazenados no mapa. Se o tipo de *chave* é uma estrutura ou classe, o *ARG_KEY* parâmetro normalmente é uma referência para o tipo especificado na *chave*. O *valor* parâmetro especifica o tipo dos itens armazenados no mapa. Se o tipo de *ARG_VALUE* é uma estrutura ou classe, o *ARG_VALUE* parâmetro normalmente é uma referência para o tipo especificado na *valor*. Por exemplo:

[!code-cpp[NVC_MFCCollections#3](../mfc/codesnippet/cpp/template-based-classes_3.cpp)]

A primeiro exemplo armazena `MY_STRUCT` valores, acesse-os por **int** chaves e retorna acessadas `MY_STRUCT` itens por referência. O segundo exemplo armazena `CPerson` valores, acesse-os por `CString` de chaves e retorna as referências a itens acessados. Este exemplo pode representar um catálogo de endereços simples, no qual você pesquisar pessoas por sobrenome.

Porque o *chave* parâmetro é do tipo `CString` e o *KEY_TYPE* parâmetro é do tipo `LPCSTR`, as chaves são armazenadas no mapa como itens do tipo `CString` , mas são referenciadas no as funções, como `SetAt` através de ponteiros do tipo `LPCSTR`. Por exemplo:

[!code-cpp[NVC_MFCCollections#4](../mfc/codesnippet/cpp/template-based-classes_4.cpp)]

##  <a name="_core_using_typed.2d.pointer_collection_templates"></a> Usando modelos de coleção do tipo de ponteiro

Para usar os modelos de coleção do tipo de ponteiro, você precisa saber quais tipos de dados que você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleção.

###  <a name="_core_typed.2d.pointer_array_and_list_usage"></a> Matriz de tipo de ponteiro e o uso de lista

As classes de lista e a matriz do tipo de ponteiro [CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md) e [CTypedPtrList](../mfc/reference/ctypedptrlist-class.md), usam dois parâmetros: *BASE_CLASS* e *tipo*. Essas classes podem armazenar qualquer tipo de dados, que você especificar na *tipo* parâmetro. Eles são derivados de uma das classes de coleção de fora do modelo que armazena ponteiros; Você especifica essa classe base no *BASE_CLASS*. Para matrizes, use `CObArray` ou `CPtrArray`. Para listas, use `CObList` ou `CPtrList`.

Na verdade, quando você declara uma coleção com base em, digamos que `CObList`, a nova classe herda não apenas os membros de sua classe base, mas também declara um número de membro de tipo seguro adicionais funções e operadores que ajudam a fornecer segurança de tipos, encapsulando chamadas para os membros da classe base. Esses encapsulamentos gerenciam todas as conversão de tipos necessária. Por exemplo:

[!code-cpp[NVC_MFCCollections#5](../mfc/codesnippet/cpp/template-based-classes_5.cpp)]

O primeiro exemplo declara uma matriz de ponteiro digitado `myArray`, derivado do `CObArray`. A matriz armazena e retorna os ponteiros para `CPerson` objetos (onde `CPerson` é uma classe derivada de `CObject`). Você pode chamar qualquer `CObArray` função de membro, ou você pode chamar novos fortemente tipados `GetAt` e `ElementAt` as funções ou usar fortemente tipados **[]** operador.

O segundo exemplo declara uma lista de tipo de ponteiro, `myList`, derivado do `CPtrList`. A lista armazena e retorna os ponteiros para `MY_STRUCT` objetos. Uma classe com base em `CPtrList` é usado para armazenar ponteiros para objetos não derivados de `CObject`. `CTypedPtrList` tem um número de funções de membro de tipo seguro: `GetHead`, `GetTail`, `RemoveHead`, `RemoveTail`, `GetNext`, `GetPrev`, e `GetAt`.

###  <a name="_core_typed.2d.pointer_map_usage"></a> Uso do mapa de tipo de ponteiro

A classe de mapa de ponteiros tipados, [CTypedPtrMap](../mfc/reference/ctypedptrmap-class.md), usa três parâmetros: *BASE_CLASS*, *chave*, e *valor*. O *BASE_CLASS* parâmetro especifica a classe da qual derivar a nova classe: `CMapPtrToWord`, `CMapPtrToPtr`, `CMapStringToPtr`, `CMapWordToPtr`, `CMapStringToOb`e assim por diante. *CHAVE* equivale a *chave* em `CMap`: Especifica o tipo da chave usada para pesquisas. *VALOR* equivale a *valor* em `CMap`: Especifica o tipo de objeto armazenado no mapa. Por exemplo:

[!code-cpp[NVC_MFCCollections#6](../mfc/codesnippet/cpp/template-based-classes_6.cpp)]

O primeiro exemplo é um mapa com base em `CMapPtrToPtr` — ele usa `CString` chaves mapeadas para ponteiros para `MY_STRUCT`. Você pode procurar um ponteiro armazenado por meio da chamada de um tipo seguro `Lookup` função de membro. Você pode usar o **[]** operador para pesquisar um ponteiro armazenado e adicioná-lo se não for encontrado. E você pode iterar o mapa usando fortemente tipados `GetNextAssoc` função. Você também pode chamar outro membro funções da classe `CMapPtrToPtr`.

O segundo exemplo é um mapa com base em `CMapStringToOb` — ele usa chaves de cadeia de caracteres mapeados para ponteiros armazenados para `CMyObject` objetos. Você pode usar os mesmos membros fortemente tipados descritos no parágrafo anterior, ou você pode chamar membros da classe `CMapStringToOb`.

> [!NOTE]
>  Se você especificar uma **classe** ou **struct** tipo para o *valor* parâmetro, em vez de um ponteiro ou referência para o tipo, classe ou estrutura deve ter um construtor de cópia.

Para obter mais informações, consulte [como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md).

## <a name="see-also"></a>Consulte também

[Coleções](../mfc/collections.md)

