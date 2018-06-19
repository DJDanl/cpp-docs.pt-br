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
ms.openlocfilehash: 68d44a66f328465f2c59fb361f9bb6b2a76efa82
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385458"
---
# <a name="template-based-classes"></a>Classes com base no modelo
Este artigo explica as classes de coleção de baseado em modelo de segurança de tipos em MFC versão 3.0 e posterior. Usando esses modelos para criar coleções fortemente tipadas é mais conveniente e ajuda a fornecer segurança de tipo de forma mais eficiente do que usar as classes de coleção não baseadas em modelos.  
  
 MFC predefine duas categorias de coleções baseadas no modelo:  
  
-   [Matriz, lista e classes de mapa](#_core_using_simple_array.2c_.list.2c_.and_map_templates)  
  
     `CArray`, `CList`, `CMap`  
  
-   [Matrizes, listas e mapas de ponteiros tipados](#_core_using_typed.2d.pointer_collection_templates)  
  
     `CTypedPtrArray`, `CTypedPtrList`, `CTypedPtrMap`  
  
 As classes de coleção simples são derivadas da classe `CObject`, portanto, eles herdam a serialização, criação dinâmica e outras propriedades de `CObject`. As classes de coleção do tipo ponteiro exigem que você especifique a classe que deriva de — que deve ser uma das coleções de ponteiro de nontemplate predefinidas pelo MFC, como `CPtrList` ou `CPtrArray`. A nova classe de coleção herda da classe base especificada e funções de membro da classe nova usarem encapsuladas chamadas para os membros de classe base para impor a segurança de tipo.  
  
 Para obter mais informações sobre os modelos do C++, consulte [modelos](../cpp/templates-cpp.md) no *referência de linguagem C++*.  
  
##  <a name="_core_using_simple_array.2c_.list.2c_.and_map_templates"></a> Usando a matriz, lista e modelos de mapa  
 Para usar os modelos de coleção simples, você precisa saber o tipo de dados que você pode armazenar nessas coleções e os parâmetros que serão usados em suas declarações de coleção.  
  
###  <a name="_core_simple_array_and_list_usage"></a> Matriz e lista de uso  
 As classes de lista e uma matriz simple [CArray](../mfc/reference/carray-class.md) e [CList](../mfc/reference/clist-class.md), ter dois parâmetros: *tipo* e `ARG_TYPE`. Essas classes podem armazenar qualquer tipo de dados que você especificar o *tipo* parâmetro:  
  
-   Tipos de dados fundamentais do C++, como `int`, `char`, e **float**  
  
-   Classes e estruturas C++  
  
-   Outros tipos que você definir  
  
 Para conveniência e a eficiência, você pode usar o `ARG_TYPE` para especificar o tipo dos argumentos de função. Normalmente, você especifica `ARG_TYPE` como uma referência para o tipo de chamada no *tipo* parâmetro. Por exemplo:  
  
 [!code-cpp[NVC_MFCCollections#1](../mfc/codesnippet/cpp/template-based-classes_1.cpp)]  
  
 O primeiro exemplo declara uma coleção de matriz, `myArray`, que contém `int`s. O segundo exemplo declara uma coleção de lista, `myList`, que armazena `CPerson` objetos. Determinadas funções de membro das classes de coleção tem argumento cujo tipo é especificado pelo `ARG_TYPE` parâmetro do modelo. Por exemplo, o **adicionar** função de membro de classe `CArray` leva um `ARG_TYPE` argumento:  
  
 [!code-cpp[NVC_MFCCollections#2](../mfc/codesnippet/cpp/template-based-classes_2.cpp)]  
  
###  <a name="_core_simple_map_usage"></a> Uso de mapa simples  
 A classe de mapa simples, [CMap](../mfc/reference/cmap-class.md), tem quatro parâmetros: *chave*, `ARG_KEY`, *valor*, e `ARG_VALUE`. Como as classes de matriz e lista as classes de mapa podem armazenar qualquer tipo de dados. Ao contrário de matrizes e listas, que o índice e solicitar os dados que eles armazenam, mapas associar chaves e valores: acessar um valor armazenado em um mapa, especificando a chave associada do valor. O *chave* parâmetro especifica o tipo de dados das chaves usadas para acessar dados armazenados no mapa. Se o tipo de *chave* é uma estrutura ou classe, o `ARG_KEY` parâmetro normalmente é uma referência para o tipo especificado em *chave*. O *valor* parâmetro especifica o tipo dos itens armazenados no mapa. Se o tipo de `ARG_VALUE` é uma estrutura ou classe, o `ARG_VALUE` parâmetro normalmente é uma referência para o tipo especificado em *valor*. Por exemplo:  
  
 [!code-cpp[NVC_MFCCollections#3](../mfc/codesnippet/cpp/template-based-classes_3.cpp)]  
  
 Os repositórios de exemplo primeiro `MY_STRUCT` valores, acesse-os por `int` chaves e retorna acessada `MY_STRUCT` itens por referência. Os segundo repositórios de exemplo `CPerson` valores, acesse-os por `CString` chaves e retorna as referências a itens acessados. Este exemplo pode representar um catálogo de endereços simples, no qual você procurar pessoas por sobrenome.  
  
 Porque o *chave* parâmetro é do tipo `CString` e *KEY_TYPE* parâmetro é do tipo `LPCSTR`, as chaves são armazenadas no mapa como itens do tipo `CString` , mas são referenciados em funções como `SetAt` através de ponteiros de tipo `LPCSTR`. Por exemplo:  
  
 [!code-cpp[NVC_MFCCollections#4](../mfc/codesnippet/cpp/template-based-classes_4.cpp)]  
  
##  <a name="_core_using_typed.2d.pointer_collection_templates"></a> Usando modelos de coleção de ponteiro tipado  
 Para usar os modelos de coleção de ponteiro tipado, você precisa saber quais tipos de dados que você pode armazenar nessas coleções e os parâmetros que serão usados em suas declarações de coleção.  
  
###  <a name="_core_typed.2d.pointer_array_and_list_usage"></a> Matriz de ponteiro tipado e o uso de lista  
 O ponteiro tipado classes de matriz e lista, [CTypedPtrArray](../mfc/reference/ctypedptrarray-class.md) e [CTypedPtrList](../mfc/reference/ctypedptrlist-class.md), ter dois parâmetros: `BASE_CLASS` e *tipo*. Essas classes podem armazenar qualquer tipo de dados que você especificar o *tipo* parâmetro. Eles são derivados de uma das classes de coleção de nontemplate que armazena ponteiros; Especifique essa classe base em `BASE_CLASS`. Para matrizes, use `CObArray` ou `CPtrArray`. Para listas, use `CObList` ou `CPtrList`.  
  
 Na verdade, quando você declara uma coleção com base em, digamos que `CObList`, a nova classe herda não apenas os membros de sua classe base, mas também declara um número de membro de tipo seguro adicional funções e operadores que ajudam a fornecer a segurança de tipo, encapsulando chamadas para os membros da classe base. Esses encapsulamentos gerenciam todas as conversão de tipo necessário. Por exemplo:  
  
 [!code-cpp[NVC_MFCCollections#5](../mfc/codesnippet/cpp/template-based-classes_5.cpp)]  
  
 O primeiro exemplo declara uma matriz de ponteiro tipado, `myArray`, derivada de `CObArray`. A matriz armazena e retorna os ponteiros para `CPerson` objetos (onde `CPerson` é uma classe derivada de `CObject`). Você pode chamar qualquer `CObArray` função membro, ou você pode chamar o novo tipo seguro `GetAt` e `ElementAt` funções ou usar a segurança de tipo **[]** operador.  
  
 O segundo exemplo declara uma lista de ponteiro tipado, `myList`, derivada de `CPtrList`. A lista armazena e retorna os ponteiros para `MY_STRUCT` objetos. Uma classe com base em `CPtrList` é usado para armazenar ponteiros para objetos não derivados de `CObject`. `CTypedPtrList` tem um número de funções de membro de tipo seguro: `GetHead`, `GetTail`, `RemoveHead`, `RemoveTail`, `GetNext`, `GetPrev`, e `GetAt`.  
  
###  <a name="_core_typed.2d.pointer_map_usage"></a> Uso do mapa de ponteiro tipado  
 A classe de mapa de ponteiro tipado, [CTypedPtrMap](../mfc/reference/ctypedptrmap-class.md), usa três parâmetros: `BASE_CLASS`, *chave*, e *valor*. O `BASE_CLASS` parâmetro especifica a classe da qual derivar a nova classe: `CMapPtrToWord`, `CMapPtrToPtr`, `CMapStringToPtr`, `CMapWordToPtr`, `CMapStringToOb`e assim por diante. *CHAVE* equivale a *chave* em `CMap`: Especifica o tipo da chave usada para pesquisas. *VALOR* equivale a *valor* em `CMap`: Especifica o tipo de objeto armazenado em map. Por exemplo:  
  
 [!code-cpp[NVC_MFCCollections#6](../mfc/codesnippet/cpp/template-based-classes_6.cpp)]  
  
 O primeiro exemplo é um mapa com base em **CMapPtrToPt**r — usa `CString` chaves mapeadas para ponteiros para `MY_STRUCT`. Você pode procurar um ponteiro armazenado chamando fortemente tipado `Lookup` função de membro. Você pode usar o **[]** operador para pesquisar um ponteiro armazenado e adicioná-lo se não for encontrado. E você pode iterar o mapa usando a segurança de tipo `GetNextAssoc` função. Você também pode chamar outro membro funções da classe `CMapPtrToPtr`.  
  
 O segundo exemplo é um mapa com base em **CMapStringToO**b — ele usa chaves de cadeia de caracteres mapeados para armazenados ponteiros para `CMyObject` objetos. Você pode usar os mesmos membros fortemente tipado descritos no parágrafo anterior, ou você pode chamar os membros da classe `CMapStringToOb`.  
  
> [!NOTE]
>  Se você especificar um **classe** ou `struct` de tipo para o *valor* parâmetro, em vez de um ponteiro ou uma referência para o tipo, classe ou estrutura deve ter um construtor de cópia.  
  
 Para obter mais informações, consulte [como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md).  
  
## <a name="see-also"></a>Consulte também  
 [Coleções](../mfc/collections.md)

