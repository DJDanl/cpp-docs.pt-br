---
title: collection_adapter (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::collection_adapter
dev_langs:
- C++
helpviewer_keywords:
- collection_adapter class [STL/CLR]
ms.assetid: 31964058-1f50-48bf-82c2-b0b3cc8a7887
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4a1a03dd6ecc52cd3921428e681fe5affa11d275
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="collectionadapter-stlclr"></a>collection_adapter (STL/CLR)
Encapsula uma coleção .NET para uso como um contêiner STL/CLR. A `collection_adapter` é uma classe de modelo que descreve um objeto de contêiner STL/CLR simples. Ele encapsula uma interface de classe biblioteca BCL (Base) e retorna um par de iterador que é usada para manipular a sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Coll>  
    ref class collection_adapter;  
  
template<>  
    ref class collection_adapter<  
        System::Collections::ICollection>;  
template<>  
    ref class collection_adapter<  
        System::Collections::IEnumerable>;  
template<>  
    ref class collection_adapter<  
        System::Collections::IList>;  
template<>  
    ref class collection_adapter<  
        System::Collections::IDictionary>;  
template<typename Value>  
    ref class collection_adapter<  
        System::Collections::Generic::ICollection<Value>>;  
template<typename Value>  
    ref class collection_adapter<  
        System::Collections::Generic::IEnumerable<Value>>;  
template<typename Value>  
    ref class collection_adapter<  
        System::Collections::Generic::IList<Value>>;  
template<typename Key,  
    typename Value>  
    ref class collection_adapter<  
        System::Collections::Generic::IDictionary<Key, Value>>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Coll  
 O tipo de coleção encapsulado.  
  
## <a name="specializations"></a>Especializações  
  
|Especialização|Descrição|  
|--------------------|-----------------|  
|IEnumerable|Sequências de elementos.|  
|ICollection|Mantém um grupo de elementos.|  
|IList|Mantém um grupo ordenado de elementos.|  
|IDictionary|Manter um conjunto de {chave, valor} pares.|  
|IEnumerable\<valor >|Sequências de elementos com tipo.|  
|ICollection\<valor >|Mantém um grupo de elementos com tipo.|  
|IList\<valor >|Mantém um grupo ordenado de elementos com tipo.|  
|IDictionary\<valor >|Mantém um conjunto de digitado {chave, valor} pares.|  
  
## <a name="members"></a>Membros  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|[collection_adapter::difference_type (STL/CLR)](../dotnet/collection-adapter-difference-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[collection_adapter::iterator (STL/CLR)](../dotnet/collection-adapter-iterator-stl-clr.md)|O tipo de um iterador para a sequência controlada.|  
|[collection_adapter::key_type (STL/CLR)](../dotnet/collection-adapter-key-type-stl-clr.md)|O tipo de uma chave de dicionário.|  
|[collection_adapter::mapped_type (STL/CLR)](../dotnet/collection-adapter-mapped-type-stl-clr.md)|O tipo de um valor de dicionário.|  
|[collection_adapter::reference (STL/CLR)](../dotnet/collection-adapter-reference-stl-clr.md)|O tipo de uma referência para um elemento.|  
|[collection_adapter::size_type (STL/CLR)](../dotnet/collection-adapter-size-type-stl-clr.md)|O tipo de uma distância com sinal entre dois elementos.|  
|[collection_adapter::value_type (STL/CLR)](../dotnet/collection-adapter-value-type-stl-clr.md)|O tipo de um elemento.|  
  
|Função membro|Descrição|  
|---------------------|-----------------|  
|[collection_adapter::base (STL/CLR)](../dotnet/collection-adapter-base-stl-clr.md)|Designa a interface BCL encapsulada.|  
|[collection_adapter::begin (STL/CLR)](../dotnet/collection-adapter-begin-stl-clr.md)|Designa o início da sequência controlada.|  
|[collection_adapter::collection_adapter (STL/CLR)](../dotnet/collection-adapter-collection-adapter-stl-clr.md)|Constrói um objeto de adaptador.|  
|[collection_adapter::end (STL/CLR)](../dotnet/collection-adapter-end-stl-clr.md)|Designa o fim da sequência controlada.|  
|[collection_adapter::size (STL/CLR)](../dotnet/collection-adapter-size-stl-clr.md)|Conta o número de elementos.|  
|[collection_adapter::swap (STL/CLR)](../dotnet/collection-adapter-swap-stl-clr.md)|Alterna o conteúdo de dois contêineres.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|[collection_adapter::operator= (STL/CLR)](../dotnet/collection-adapter-operator-assign-stl-clr.md)|Substitui o identificador BCL armazenado.|  
  
## <a name="remarks"></a>Comentários  
 Você pode usar essa classe de modelo para manipular um contêiner BCL como um contêiner STL/CLR. O `collection_adapter` armazena um identificador para uma interface BCL, que por sua vez, controla uma sequência de elementos. Um `collection_adapter` objeto `X` retorna um par de iteradores entrados `X.begin()` e `X.end()` que você use a visitar os elementos, em ordem. Alguns das especializações também permitem que você escreva `X.size()` para determinar o comprimento da sequência controlada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext adaptador >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [range_adapter (STL/CLR)](../dotnet/range-adapter-stl-clr.md)   
 [make_collection (STL/CLR)](../dotnet/make-collection-stl-clr.md)