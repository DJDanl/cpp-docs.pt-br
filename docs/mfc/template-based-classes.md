---
title: Classes com base no modelo
ms.date: 11/04/2016
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
ms.openlocfilehash: eceee4421b43515b9b246f4af26a1a3741c6b25b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230448"
---
# <a name="template-based-classes"></a>Classes com base no modelo

Este artigo explica as classes de coleção com base em modelo com segurança de tipo no MFC versão 3,0 e posterior. Usar esses modelos para criar coleções com segurança de tipos é mais conveniente e ajuda a fornecer segurança de tipo com mais eficiência do que usar as classes de coleção não baseadas em modelos.

O MFC predefine duas categorias de coleções baseadas em modelo:

- [Classes simples de matriz, lista e mapeamento](#_core_using_simple_array.2c_.list.2c_.and_map_templates)

   `CArray`, `CList`, `CMap`

- [Matrizes, listas e mapas de ponteiros tipados](#_core_using_typed.2d.pointer_collection_templates)

   `CTypedPtrArray`, `CTypedPtrList`, `CTypedPtrMap`

As classes de coleção simples são todas derivadas da classe `CObject` , portanto, elas herdam a serialização, a criação dinâmica e outras propriedades do `CObject` . As classes de coleção de ponteiro tipado exigem que você especifique a classe da qual você deriva — que deve ser uma das coleções de ponteiros não modelo predefinidas pelo MFC, como `CPtrList` ou `CPtrArray` . A nova classe de coleção herda da classe base especificada, e as funções de membro da nova classe usam chamadas encapsuladas para os membros da classe base para impor a segurança do tipo.

Para obter mais informações sobre modelos C++, consulte [modelos](../cpp/templates-cpp.md) na *referência da linguagem c++*.

## <a name="using-simple-array-list-and-map-templates"></a><a name="_core_using_simple_array.2c_.list.2c_.and_map_templates"></a>Usando matriz simples, lista e modelos de mapa

Para usar os modelos de coleção simples, você precisa saber que tipo de dados você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleção.

### <a name="simple-array-and-list-usage"></a><a name="_core_simple_array_and_list_usage"></a>Uso simples de matriz e lista

As classes de matriz e lista simples, [CArray](../mfc/reference/carray-class.md) e [CList](../mfc/reference/clist-class.md), usam dois parâmetros: *Type* e `ARG_TYPE` . Essas classes podem armazenar qualquer tipo de dados, que você especifica no parâmetro de *tipo* :

- Tipos de dados C++ fundamentais, como **`int`** , **`char`** e**`float`**

- Estruturas e classes do C++

- Outros tipos que você define

Para conveniência e eficiência, você pode usar o parâmetro *ARG_TYPE* para especificar o tipo de argumentos de função. Normalmente, você especifica *ARG_TYPE* como uma referência ao tipo nomeado no parâmetro de *tipo* . Por exemplo:

[!code-cpp[NVC_MFCCollections#1](../mfc/codesnippet/cpp/template-based-classes_1.cpp)]

O primeiro exemplo declara uma coleção de matriz, `myArray` , que contém **`int`** s. O segundo exemplo declara uma coleção de lista, `myList` , que armazena `CPerson` objetos. Determinadas funções de membro das classes de coleção assumem argumentos cujo tipo é especificado pelo parâmetro de modelo *ARG_TYPE* . Por exemplo, a `Add` função membro da classe `CArray` usa um argumento *ARG_TYPE* :

[!code-cpp[NVC_MFCCollections#2](../mfc/codesnippet/cpp/template-based-classes_2.cpp)]

### <a name="simple-map-usage"></a><a name="_core_simple_map_usage"></a>Uso de mapa simples

A classe de mapa simples, o [CMap](../mfc/reference/cmap-class.md), usa quatro parâmetros: *Key*, *ARG_KEY*, *Value*e *ARG_VALUE*. Assim como as classes Array e List, as classes MAP podem armazenar qualquer tipo de dados. Ao contrário de matrizes e listas, que indexam e ordenam os dados que armazenam, mapeiam chaves e valores associados: você acessa um valor armazenado em um mapa especificando a chave associada ao valor. O parâmetro *Key* especifica o tipo de dados das chaves usadas para acessar os dados armazenados no mapa. Se o tipo de *chave* for uma estrutura ou classe, o parâmetro *ARG_KEY* normalmente será uma referência ao tipo especificado na *chave*. O parâmetro *Value* especifica o tipo dos itens armazenados no mapa. Se o tipo de *ARG_VALUE* for uma estrutura ou classe, o parâmetro *ARG_VALUE* normalmente será uma referência ao tipo especificado em *valor*. Por exemplo:

[!code-cpp[NVC_MFCCollections#3](../mfc/codesnippet/cpp/template-based-classes_3.cpp)]

O primeiro exemplo armazena `MY_STRUCT` valores, acessa-os por **`int`** chaves e retorna itens acessados `MY_STRUCT` por referência. O segundo exemplo armazena `CPerson` valores, acessa-os por `CString` chaves e retorna referências a itens acessados. Este exemplo pode representar um catálogo de endereços simples, no qual você procura pessoas por sobrenome.

Como o parâmetro *Key* é do tipo `CString` e o parâmetro *KEY_TYPE* é do tipo `LPCSTR` , as chaves são armazenadas no mapa como itens do tipo, `CString` mas são referenciadas em funções como `SetAt` por meio de ponteiros do tipo `LPCSTR` . Por exemplo:

[!code-cpp[NVC_MFCCollections#4](../mfc/codesnippet/cpp/template-based-classes_4.cpp)]

## <a name="using-typed-pointer-collection-templates"></a><a name="_core_using_typed.2d.pointer_collection_templates"></a>Usando modelos de coleção de ponteiros tipados

Para usar os modelos de coleção de ponteiros tipados, você precisa saber quais tipos de dados você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleção.

### <a name="typed-pointer-array-and-list-usage"></a><a name="_core_typed.2d.pointer_array_and_list_usage"></a>Uso de matriz e lista de ponteiros tipados

A matriz de ponteiro tipado e as classes de lista, [CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md) e [CTypedPtrList](../mfc/reference/ctypedptrlist-class.md), usam dois parâmetros: *BASE_CLASS* e *Type*. Essas classes podem armazenar qualquer tipo de dados, que você especifica no parâmetro de *tipo* . Elas são derivadas de uma das classes de coleção não modelo que armazena ponteiros; Você especifica essa classe base em *BASE_CLASS*. Para matrizes, use o `CObArray` ou o `CPtrArray` . Para listas, use o `CObList` ou o `CPtrList` .

Na verdade, quando você declara uma coleção com base em, digamos `CObList` , a nova classe não só herda os membros de sua classe base, mas também declara um número de funções de membro e operadores de tipo seguro adicionais que ajudam a fornecer segurança de tipo ao encapsular chamadas para os membros da classe base. Essas encapsulações gerenciam toda a conversão de tipo necessária. Por exemplo:

[!code-cpp[NVC_MFCCollections#5](../mfc/codesnippet/cpp/template-based-classes_5.cpp)]

O primeiro exemplo declara uma matriz de ponteiro tipado, `myArray` derivada de `CObArray` . A matriz armazena e retorna ponteiros para `CPerson` objetos (onde `CPerson` é uma classe derivada de `CObject` ). Você pode chamar qualquer `CObArray` função de membro ou pode chamar o novo tipo-seguro `GetAt` e `ElementAt` funções ou usar o operador de tipo seguro **[]** .

O segundo exemplo declara uma lista de ponteiros tipados, `myList` , derivada de `CPtrList` . A lista armazena e retorna ponteiros para `MY_STRUCT` objetos. Uma classe baseada em `CPtrList` é usada para armazenar ponteiros para objetos não derivados do `CObject` . `CTypedPtrList`tem um número de funções de membro de tipo seguro:,,,,, `GetHead` `GetTail` `RemoveHead` `RemoveTail` `GetNext` `GetPrev` e `GetAt` .

### <a name="typed-pointer-map-usage"></a><a name="_core_typed.2d.pointer_map_usage"></a>Uso de mapa de ponteiro tipado

A classe de mapa de ponteiro tipado, [CTypedPtrMap](../mfc/reference/ctypedptrmap-class.md), usa três parâmetros: *BASE_CLASS*, *Key*e *Value*. O parâmetro *BASE_CLASS* especifica a classe da qual deriva a nova classe:,,,, `CMapPtrToWord` `CMapPtrToPtr` `CMapStringToPtr` `CMapWordToPtr` `CMapStringToOb` e assim por diante. A *chave* é análoga à *chave* em `CMap` : especifica o tipo da chave usada para pesquisas. O *valor* é análogo ao *valor* em `CMap` : especifica o tipo de objeto armazenado no mapa. Por exemplo:

[!code-cpp[NVC_MFCCollections#6](../mfc/codesnippet/cpp/template-based-classes_6.cpp)]

O primeiro exemplo é um mapa baseado em `CMapPtrToPtr` — ele usa `CString` chaves mapeadas para ponteiros para `MY_STRUCT` . Você pode pesquisar um ponteiro armazenado chamando uma função de membro de tipo seguro `Lookup` . Você pode usar o operador **[]** para pesquisar um ponteiro armazenado e adicioná-lo se não for encontrado. E você pode iterar o mapa usando a função de tipo seguro `GetNextAssoc` . Você também pode chamar outras funções de membro da classe `CMapPtrToPtr` .

O segundo exemplo é um mapa baseado em `CMapStringToOb` — ele usa chaves de cadeia de caracteres mapeadas para ponteiros armazenados para `CMyObject` objetos. Você pode usar os mesmos membros de tipo seguro descritos no parágrafo anterior, ou você pode chamar membros da classe `CMapStringToOb` .

> [!NOTE]
> Se você especificar um **`class`** **`struct`** tipo ou para o parâmetro de *valor* , em vez de um ponteiro ou referência para o tipo, a classe ou a estrutura deverá ter um construtor de cópia.

Para obter mais informações, consulte [como criar uma coleção de tipo seguro](../mfc/how-to-make-a-type-safe-collection.md).

## <a name="see-also"></a>Confira também

[Coleções](../mfc/collections.md)
