---
title: Classe Platform::Collections::VectorIterator | Microsoft Docs
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: COLLECTION/Platform::Collections::VectorIterator::VectorIterator
dev_langs: C++
helpviewer_keywords: VectorIterator Class
ms.assetid: d531cb42-27e0-48a6-bf5e-c265891a18ff
caps.latest.revision: "7"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.openlocfilehash: 703035c7a5b2b32df95f83b42327b0965c98b4fb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="platformcollectionsvectoriterator-class"></a>Classe Platform::Collections::VectorIterator
Fornece um iterador da biblioteca de modelos padrão para objetos derivados da interface IVector de tempo de execução do Windows.  
  
 VectorIterator é um iterador proxy que armazena elementos do tipo VectorProxy\<T >. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename T>  
class VectorIterator;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O typename da classe de modelo de VectorIterator.  
  
### <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|  
|`iterator_category`|A categoria de um iterador de acesso aleatório (::std::random_access_iterator_tag).|  
|`pointer`|Um ponteiro para um tipo interno, Platform::Collections::Details::VectorProxy\<T >, que é necessário para a implementação de VectorIterator.|  
|`reference`|Uma referência a um tipo interno, Platform::Collections::Details::VectorProxy\<T >, que é necessário para a implementação de VectorIterator.|  
|`value_type`|O typename `T` .|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Vectoriterator:: Vectoriterator](#ctor)|Inicializa uma nova instância da classe VectorIterator.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador VectorIterator::operator-](#operator-minus)|Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.|  
|[Operador VectorIterator::operator--](#operator-decrement)|Decrementa o VectorIterator atual.|  
|[Operador VectorIterator::operator!=](#operator-inequality)|Indica se o VectorIterator atual não é igual a um VectorIterator especificado.|  
|[Operador VectorIterator::operator*](#operator-dereference)|Recupera uma referência ao elemento especificado pelo VectorIterator atual.|  
|[Vectoriterator:: Operator\[\]](#operator-at)|Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.|  
|[Operador VectorIterator::operator+](#operator-plus)|Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.|  
|[Operador VectorIterator::operator++](#operator-increment)|Incrementa o VectorIterator atual.|  
|[Operador VectorIterator::operator+=](#operator-plus-assign)|Incrementa o VectorIterator atual pelo deslocamento especificado.|  
|[Operador VectorIterator::operator<](#operator-less-than)|Indica se o VectorIterator atual é menor que um VectorIterator especificado.|  
|[Vectoriterator:: Operator\<operador =](#operator-less-than-or-equals)|Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.|  
|[Operador VectorIterator::operator-=](#operator-subtract-assign)|Decrementa o VectorIterator atual pelo deslocamento especificado.|  
|[Operador VectorIterator::operator==](#operator-equality)|Indica se o VectorIterator atual é igual a um VectorIterator especificado.|  
|[Operador VectorIterator::operator>](#operator-greater-than)|Indica se o VectorIterator atual é maior que um VectorIterator especificado.|  
|[Operador VectorIterator::operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo VectorIterator atual.|  
|[Operador VectorIterator::operator>=](#operator-greater-than-or-equal)|Indica se o VectorIterator atual é maior ou igual a um VectorIterator especificado.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `VectorIterator`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Platform::Collections  

## <a name="operator-arrow"></a>Vectoriterator:: Operator -&gt; operador
Recupera o endereço do elemento referenciado pelo VectorIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
Detail::ArrowProxy<T> operator->() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do elemento que é referenciado pelo VectorIterator atual.  
  
 O tipo do valor retornado é um tipo interno não especificado que é necessário para a implementação desse operador.  
  


## <a name="operator-decrement"></a>Vectoriterator:: Operator - operador
Decrementa o VectorIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
VectorIterator& operator--();  
VectorIterator operator--(int);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sintaxe diminui e, em seguida, retorna o VectorIterator atual. A segunda sintaxe retorna uma cópia do VectorIterator atual e, em seguida, diminui o VectorIterator atual.  
  
### <a name="remarks"></a>Comentários  
 A primeira sintaxe de VectorIterator pré-diminui o VectorIterator atual.  
  
 A segunda sintaxe pós-diminui o VectorIterator atual. O `int` tipo na segunda sintaxe indica uma operação de pós-diminuição, não um operando de inteiro real.  
  


## <a name="operator-dereference"></a>Operador vectoriterator:: Operator *
Recupera o endereço do elemento especificado pelo VectorIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference operator*() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento especificado pelo VectorIterator atual.  
  


## <a name="operator-equality"></a>Vectoriterator:: Operator = = operador
Indica se o VectorIterator atual é igual a um VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator==(const VectorIterator& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o VectorIterator atual for igual a `other`; caso contrário, `false`.  
  


## <a name="operator-greater-than"></a>Vectoriterator:: Operator&gt; operador
Indica se o VectorIterator atual é maior que um VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
bool operator>(const VectorIterator& other) const   
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o VectorIterator atual é maior do que `other`; caso contrário, `false`.  
  


## <a name="operator-greater-than-or-equals"></a>Vectoriterator:: Operator&gt;operador =
Indica se o VectorIterator atual é maior ou igual ao VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
bool operator>=(const VectorIterator& other) const   
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o VectorIterator for maior ou igual ao `other`; caso contrário, `false`.    


## <a name="operator-increment"></a>Operador vectoriterator:: Operator + +
Incrementa o VectorIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```    
VectorIterator& operator++();  
VectorIterator operator++(int);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sintaxe incrementa e, em seguida, retorna o VectorIterator atual. A segunda sintaxe retorna uma cópia de VectorIterator atual e, em seguida, incrementa VectorIterator atual.  
  
### <a name="remarks"></a>Comentários  
 A primeira sintaxe de VectorIterator pré-incrementa o VectorIterator atual.  
  
 A segunda sintaxe pós-incrementa o VectorIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.  
  


## <a name="operator-inequality"></a>Vectoriterator:: Operator! = operador
Indica se o VectorIterator atual não é igual a um VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator!=(const VectorIterator& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o VectorIterator atual não é igual a `other`; caso contrário, `false`.  
  


## <a name="operator-less-than"></a>Vectoriterator:: Operator&lt; operador
Indica se o VectorIterator atual é menor que um VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
bool operator<(const VectorIterator& other) const   
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o VectorIterator atual for menor que `other`; caso contrário, `false`.  
  


## <a name="operator-less-than-or-equals"></a>Vectoriterator:: Operator&lt;operador =
Indica se o VectorIterator atual é menor ou igual a um VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
  
bool operator<=(const VectorIterator& other) const   
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o VectorIterator atual é menor ou igual a `other`; caso contrário, `false`.  
  


## <a name="operator-minus"></a>Operador vectoriterator:: Operator
Subtrai um número especificado de elementos do iterador atual, gerando um novo iterador, ou um iterador especificado do iterador atual, gerando o número de elementos entre os iteradores.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
VectorIterator operator-(difference_type n) const;  
  
difference_type operator-(const VectorIterator& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `n`  
 Um número de elementos.  
  
 `other`  
 Outro VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sintaxe do operador retorna um objeto VectorIterator que é `n` elementos menos o vectoriterator atual. A segunda sintaxe do operador retorna o número de elementos entre atual e o `other` VectorIterator.  
  


## <a name="operator-plus-assign"></a>Vectoriterator:: Operator + = operador
Incrementa o VectorIterator atual pelo deslocamento especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
VectorIterator& operator+=(difference_type n);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `n`  
 Um deslocamento de inteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 O VectorIterator atualizado.  
  


## <a name="operator-plus"></a>ectorIterator::operator + operador
Retorna um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
  
VectorIterator operator+(difference_type n);  
  
template <typename T>  
inline VectorIterator<T> operator+(
  ptrdiff_t n, 
  const VectorIterator<T>& i);  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 Na segunda sintaxe, o typename de VectorIterator.  
  
 `n`  
 Um deslocamento de inteiro.  
  
 `i`  
 Na segunda sintaxe, um VectorIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do VectorIterator atual.  
  
 Na segunda sintaxe, um VectorIterator que referencia o elemento no deslocamento especificado do início do parâmetro `i`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro exemplo de sintaxe  
  


## <a name="operator-minus-equals"></a>Vectoriterator:: Operator-= operador
Decrementa o VectorIterator atual pelo deslocamento especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
VectorIterator& operator-=(difference_type n);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `n`  
 Um deslocamento de inteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 O VectorIterator atualizado.  
  


## <a name="operator-at"></a>Vectoriterator:: Operator\[\]
Recupera uma referência ao elemento que é um deslocamento especificado de VectorIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```    
reference operator[](difference_type n) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `n`  
 Um deslocamento de inteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento que é deslocado pelos elementos `n` de VectorIterator atual.  
  


## <a name="ctor"></a>Construtor vectoriterator:: Vectoriterator
Inicializa uma nova instância da classe VectorIterator.  
  
### <a name="syntax"></a>Sintaxe  
  
```    
VectorIterator();  
  
explicit VectorIterator(  
   Windows::Foundation::Collections::IVector<T>^ v);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `v`  
 Um IVector\<T > objeto.  
  
### <a name="remarks"></a>Comentários  
 O primeiro exemplo de sintaxe é o construtor padrão. O segundo exemplo de sintaxe é um construtor explícito que é usado para construir um VectorIterator de um IVector\<T > objeto.  
  


  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](platform-namespace-c-cx.md)