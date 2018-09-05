---
title: '{1&gt;classe Platform::Collections::vectorview&lt;1} | Microsoft Docs'
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: reference
f1_keywords:
- COLLECTION/Platform::Collections::VectorView::VectorView
- COLLECTION/Platform::Collections::VectorView::First
- COLLECTION/Platform::Collections::VectorView::GetAt
- COLLECTION/Platform::Collections::VectorView::GetMany
- COLLECTION/Platform::Collections::VectorView::IndexOf
- COLLECTION/Platform::Collections::VectorView::Size
dev_langs:
- C++
helpviewer_keywords:
- VectorView Class
ms.assetid: 05cd461d-dce7-49d3-b0e7-2e5c78ed8192
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 598b5f6fcfefa03fe733ac7b6e5a8417278e6f01
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43690601"
---
# <a name="platformcollectionsvectorview-class"></a>Classe Platform::Collections::VectorView
Representa uma exibição somente leitura de uma coleção sequencial de objetos que podem ser acessados separadamente por índice. O tipo de cada objeto na coleção é especificado pelo parâmetro de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename T, typename E>  
   ref class VectorView sealed;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo dos elementos contidos no objeto `VectorView` .  
  
 `E`  
 Especifica um predicado binário para testar a igualdade com valores do tipo `T`. O valor padrão é `std::equal_to<T>`.  
  
### <a name="remarks"></a>Comentários  
 O `VectorView` classe implementa as [Windows::Foundation::Collections::IVectorView\<T >](/uwp/api/Windows.Foundation.Collections.IVectorView_T_) interface e suporte para iteradores da biblioteca de modelos padrão.  
  
### <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[VectorView::VectorView](#ctor)|Inicializa uma nova instância da classe VectorView.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[VectorView::First](#first)|Retorna um iterador que especifica o primeiro elemento em VectorView.|  
|[VectorView::GetAt](#getat)|Recupera o elemento de VectorView atual que é indicado pelo índice especificado.|  
|[VectorView::GetMany](#getmany)|Recupera uma sequência de itens de VectorView atual, começando no índice especificado.|  
|[VectorView::IndexOf](#indexof)|Procura o item especificado no VectorView atual e, se encontrado, retorna o índice do item.|  
|[VectorView::Size](#size)|Retorna o número de elementos no objeto VectorView atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `VectorView`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Platform::Collections  

## <a name="first"></a>  Método vectorview:: First
Retorna um iterador que especifica o primeiro elemento em VectorView.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
virtual Windows::Foundation::Collections::IIterator<T>^   
   First();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que especifica o primeiro elemento em VectorView.  
  
### <a name="remarks"></a>Comentários  
 Uma maneira conveniente de manter o iterador retornado por First () é atribuir o valor de retorno a uma variável que é declarada com o **automática** palavra-chave de dedução de tipo. Por exemplo, `auto x = myVectorView->First();`.  
  


## <a name="getat"></a>  Método vectorview:: Getat
Recupera o elemento de VectorView atual que é indicado pelo índice especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
T GetAt(  
   UInt32 index  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `index`  
 Um inteiro sem sinal de base zero que especifica um determinado elemento no objeto VectorView.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento especificado pelo parâmetro `index`. O tipo de elemento é especificado pelo parâmetro de modelo VectorView *T*.  
  


## <a name="getmany"></a>  Método vectorview:: Getmany
Recupera uma sequência de itens de VectorView atual, começando no índice especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
virtual unsigned int GetMany(  
   unsigned int startIndex,   
   ::Platform::WriteOnlyArray<T>^ dest  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `startIndex`  
 O índice com base zero do início dos itens a serem recuperados.  
  
 `dest`  
 Quando essa operação for concluída, uma matriz de itens que começam com o elemento especificado por `startIndex` e de término no último elemento no VectorView.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens recuperados.  
  


## <a name="indexof"></a>  Método vectorview:: IndexOf
Procura o item especificado no VectorView atual e, se encontrado, retorna o índice do item.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
virtual bool IndexOf(  
   T value,  
   unsigned int* index  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `value`  
 O item a ser localizado.  
  
 `index`  
 O índice com base zero do item se o parâmetro `value` for encontrado; caso contrário, 0.  
  
 O parâmetro `index` será 0 se o item for o primeiro elemento de VectorView ou se o item não for encontrado. Se o valor de retorno for `true`, o item foi encontrado e é o primeiro elemento; caso contrário, o item não foi encontrado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o item especificado for encontrado; caso contrário, `false`.  
  


## <a name="size"></a>  Método vectorview:: Size
Retorna o número de elementos no objeto VectorView atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
virtual property unsigned int Size;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos no VectorView atual.  
  


## <a name="ctor"></a>  Construtor vectorview:: Vectorview
Inicializa uma nova instância da classe VectorView.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
VectorView();  
explicit VectorView(  
   UInt32 size  
);  
VectorView(  
   UInt32 size,  
   T value  
);  
explicit VectorView(  
   const ::std::vector<T>& v  
);  
explicit VectorView(  
   ::std::vector<T>&& v  
);  
VectorView(  
   const T * ptr,  
   UInt32 size  
);  
  
template <  
   size_t N  
>  
explicit VectorView(  
   const T (&arr)[N]  
);  
  
template <  
   size_t N  
>  
explicit VectorView(  
   const ::std::array<T,  
   N>& a  
);  
  
explicit VectorView(  
   const ::Platform::Array<T>^ arr  
);  
  
template <  
   typename InIt  
>  
VectorView(  
   InItfirst,  
   InItlast  
);  
  
VectorView(  
   std::initializer_list<T> il  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `InIt`  
 O tipo de uma coleção de objetos que é usada para inicializar o VectorView atual.  
  
 il  
 Um [std:: initializer_list](../standard-library/initializer-list-class.md) cujos elementos serão usados para inicializar o VectorView.  
  
 `N`  
 O número de elementos em uma coleção de objetos que é usada para inicializar o VectorView atual.  
  
 `size`  
 O número de elementos no VectorView.  
  
 `value`  
 Um valor que é usado para inicializar cada elemento no VectorView atual.  
  
 `v`  
 Uma [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md) para um [std:: Vector](../standard-library/vector-class.md) que é usado para inicializar o VectorView atual.  
  
 `ptr`  
 Ponteiro para um `std::vector` que é usado para inicializar o VectorView atual.  
  
 `arr`  
 Um [Platform:: array](../cppcx/platform-array-class.md) objeto que é usado para inicializar o VectorView atual.  
  
 `a`  
 Um [std:: array](../standard-library/array-class-stl.md) objeto que é usado para inicializar o VectorView atual.  
  
 `first`  
 O primeiro elemento em uma sequência de objetos que é usado para inicializar o VectorView atual. O tipo de `first` é passado por meio da *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 `last`  
 O último elemento em uma sequência de objetos que é usado para inicializar o VectorView atual. O tipo de `last` é passado por meio da *encaminhamento perfeito*. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  


  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](platform-namespace-c-cx.md)   
 [Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)