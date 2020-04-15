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
ms.openlocfilehash: 29f5f815b62835aedbca1f79b797f826ea53d83b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370462"
---
# <a name="template-based-classes"></a>Classes com base no modelo

Este artigo explica as classes de coleção baseadas em modelos com segurança de tipo na versão 3.0 do MFC e posteriores. Usar esses modelos para criar coleções seguras de tipo é mais conveniente e ajuda a fornecer segurança de tipo de forma mais eficaz do que usar as classes de coleta não baseadas em modelos.

O MFC predefine duas categorias de coleções baseadas em modelos:

- [Classes simples de matriz, lista e mapa](#_core_using_simple_array.2c_.list.2c_.and_map_templates)

   `CArray`, `CList`, `CMap`

- [Matrizes, listas e mapas de ponteiros digitados](#_core_using_typed.2d.pointer_collection_templates)

   `CTypedPtrArray`, `CTypedPtrList`, `CTypedPtrMap`

As classes de coleção simples `CObject`são todas derivadas da classe, por isso `CObject`herdam a serialização, criação dinâmica e outras propriedades de . As classes de coleta de ponteiro sumido exigem que você especifique a classe da qual `CPtrList` `CPtrArray`você deriva — que deve ser uma das coleções de ponteiros não-modelo predefinidas pelo MFC, como ou . Sua nova classe de coleta herda da classe base especificada, e as funções de membro da nova classe usam chamadas encapsuladas para os membros da classe base para impor a segurança do tipo.

Para obter mais informações sobre os modelos C++, consulte [Templates](../cpp/templates-cpp.md) na *referência de linguagem C++.*

## <a name="using-simple-array-list-and-map-templates"></a><a name="_core_using_simple_array.2c_.list.2c_.and_map_templates"></a>Usando modelos simples de matriz, lista e mapa

Para usar os modelos de coleta simples, você precisa saber que tipo de dados você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleta.

### <a name="simple-array-and-list-usage"></a><a name="_core_simple_array_and_list_usage"></a>Uso de matriz simples e list

As classes de matriz simples e lista, [CArray](../mfc/reference/carray-class.md) e `ARG_TYPE` [CList,](../mfc/reference/clist-class.md)tomam dois parâmetros: *TYPE* e . Essas classes podem armazenar qualquer tipo de dados, que você especifica no parâmetro *TYPE:*

- Tipos de dados C++ fundamentais, como **int,** **char,** e **float**

- Estruturas e classes C++

- Outros tipos que você define

Para conveniência e eficiência, você pode usar o parâmetro *ARG_TYPE* para especificar o tipo de argumentos de função. Normalmente, você especifica *ARG_TYPE* como uma referência ao tipo que você nomeou no parâmetro *TYPE.* Por exemplo:

[!code-cpp[NVC_MFCCollections#1](../mfc/codesnippet/cpp/template-based-classes_1.cpp)]

O primeiro exemplo declara uma `myArray`coleção de matrizes, que contém **int**s. O segundo exemplo declara uma `myList`coleção `CPerson` de listas, que armazena objetos. Certas funções de membro das classes de coleta levam argumentos cujo tipo é especificado pelo parâmetro de modelo *ARG_TYPE.* Por exemplo, `Add` a função `CArray` membro da classe tem um *argumento ARG_TYPE:*

[!code-cpp[NVC_MFCCollections#2](../mfc/codesnippet/cpp/template-based-classes_2.cpp)]

### <a name="simple-map-usage"></a><a name="_core_simple_map_usage"></a>Uso de mapa simples

A classe de mapa simples, [CMap,](../mfc/reference/cmap-class.md)tem quatro parâmetros: *KEY*, *ARG_KEY*, *VALUE*e *ARG_VALUE*. Como as classes de matriz e lista, as classes de mapa podem armazenar qualquer tipo de dados. Ao contrário de matrizes e listas, que indexam e ordenam os dados que armazenam, mapeia chaves e valores associados: Você acessa um valor armazenado em um mapa especificando a chave associada do valor. O parâmetro *KEY* especifica o tipo de dados das chaves usadas para acessar os dados armazenados no mapa. Se o tipo de *CHAVE* for uma estrutura ou classe, o parâmetro *ARG_KEY* é tipicamente uma referência ao tipo especificado em *KEY*. O parâmetro *VALUE* especifica o tipo de itens armazenados no mapa. Se o tipo de *ARG_VALUE* for uma estrutura ou classe, o parâmetro *ARG_VALUE* é tipicamente uma referência ao tipo especificado em *VALUE*. Por exemplo:

[!code-cpp[NVC_MFCCollections#3](../mfc/codesnippet/cpp/template-based-classes_3.cpp)]

O primeiro `MY_STRUCT` exemplo armazena valores, os acessa `MY_STRUCT` por chaves **int** e devolve itens acessados por referência. O segundo `CPerson` exemplo armazena valores, os acessa por `CString` chaves e retorna referências aos itens acessados. Este exemplo pode representar um simples catálogo de endereços, no qual você procura pessoas pelo sobrenome.

Como o parâmetro *KEY* `CString` é de tipo e o *parâmetro KEY_TYPE* é do tipo, `LPCSTR`as `CString` teclas são armazenadas `SetAt` no mapa como itens de tipo, mas são referenciadas em funções como através de ponteiros do tipo `LPCSTR`. Por exemplo:

[!code-cpp[NVC_MFCCollections#4](../mfc/codesnippet/cpp/template-based-classes_4.cpp)]

## <a name="using-typed-pointer-collection-templates"></a><a name="_core_using_typed.2d.pointer_collection_templates"></a>Usando modelos de coleção de ponteiros digitados

Para usar os modelos de coleta de ponteiros digitados, você precisa saber que tipos de dados você pode armazenar nessas coleções e quais parâmetros usar em suas declarações de coleta.

### <a name="typed-pointer-array-and-list-usage"></a><a name="_core_typed.2d.pointer_array_and_list_usage"></a>Matriz de ponteiro digitado e uso de lista

As classes de matriz de ponteiro digitado e lista, [CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md) e [CTypedPtrList,](../mfc/reference/ctypedptrlist-class.md)têm dois parâmetros: *BASE_CLASS* e *TYPE*. Essas classes podem armazenar qualquer tipo de dados, que você especifica no parâmetro *TYPE.* Eles são derivados de uma das classes de coleção não-modelo que armazena ponteiros; você especifica esta classe base em *BASE_CLASS*. Para matrizes, `CObArray` use `CPtrArray`ou . Para listas, `CObList` use `CPtrList`um ou .

Com efeito, quando você declara uma `CObList`coleção baseada em, digamos, a nova classe não apenas herda os membros de sua classe base, mas também declara uma série de funções adicionais de membros e operadores seguros de tipo que ajudam a fornecer segurança do tipo encapsulando chamadas para os membros da classe base. Esses encapsulamentos gerenciam toda a conversão de tipo necessária. Por exemplo:

[!code-cpp[NVC_MFCCollections#5](../mfc/codesnippet/cpp/template-based-classes_5.cpp)]

O primeiro exemplo declara uma matriz `myArray`de ponteiro `CObArray`digitado, derivada de . A matriz armazena e `CPerson` devolve ponteiros para objetos (onde `CPerson` é uma classe derivada `CObject`). Você pode `CObArray` ligar para qualquer função de membro, `GetAt` `ElementAt` ou pode chamar o novo tipo de segurança e funções ou usar o operador de segurança de **tipo [ ]** operador.

O segundo exemplo declara uma lista `myList`de pontos `CPtrList`digitados, derivada de . A lista armazena e `MY_STRUCT` devolve ponteiros para objetos. Uma classe `CPtrList` baseada é usada para armazenar ponteiros para `CObject`objetos não derivados . `CTypedPtrList`tem uma série de funções `GetHead`de `GetTail` `RemoveHead`membro `RemoveTail` `GetNext`com segurança de tipo: , , , , `GetPrev`, e `GetAt`.

### <a name="typed-pointer-map-usage"></a><a name="_core_typed.2d.pointer_map_usage"></a>Uso do mapa do ponteiro digitado

A classe de mapa de ponteiro digitado, [CTypedPtrMap,](../mfc/reference/ctypedptrmap-class.md)tem três parâmetros: *BASE_CLASS*, *KEY*e *VALUE*. O *parâmetro BASE_CLASS* especifica a classe a partir `CMapPtrToWord`da `CMapPtrToPtr` `CMapStringToPtr`qual `CMapWordToPtr` `CMapStringToOb`se deve derivar a nova classe: , , , , , e assim por diante. *Key* é análogo `CMap`a *KEY* in : Ele especifica o tipo da chave usada para as pesquisas. *VALUE* é análogo `CMap`ao *VALUE* em : Ele especifica o tipo de objeto armazenado no mapa. Por exemplo:

[!code-cpp[NVC_MFCCollections#6](../mfc/codesnippet/cpp/template-based-classes_6.cpp)]

O primeiro exemplo é `CMapPtrToPtr` um mapa `CString` baseado em — `MY_STRUCT`ele usa chaves mapeadas para ponteiros para . Você pode procurar um ponteiro armazenado chamando uma função de membro com segurança `Lookup` de tipo. Você pode usar o **operador []** para procurar um ponteiro armazenado e adicioná-lo se não for encontrado. E você pode iterar o mapa `GetNextAssoc` usando a função de segurança de tipo. Você também pode chamar outras `CMapPtrToPtr`funções de membro de classe .

O segundo exemplo é `CMapStringToOb` um mapa baseado em — ele `CMyObject` usa teclas de string mapeadas para ponteiros armazenados em objetos. Você pode usar os mesmos membros de segurança de tipo descritos no parágrafo anterior, ou pode chamar membros de classe `CMapStringToOb`.

> [!NOTE]
> Se você especificar um tipo **de classe** ou **estrutura** para o parâmetro *VALUE,* em vez de um ponteiro ou referência ao tipo, a classe ou estrutura deve ter um construtor de cópia.

Para obter mais informações, consulte [Como fazer uma coleção de tipo seguro](../mfc/how-to-make-a-type-safe-collection.md).

## <a name="see-also"></a>Confira também

[Coleções](../mfc/collections.md)
