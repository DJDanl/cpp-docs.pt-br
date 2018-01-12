---
title: Classe Platform::Collections::InputIterator | Microsoft Docs
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: COLLECTION/Platform::Collections::InputIterator::InputIterator
dev_langs: C++
helpviewer_keywords: InputIterator Class
ms.assetid: ef72eea4-32a9-42b9-8119-ce87dbdcd3be
caps.latest.revision: "4"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a6041a3701bfac1561ab58ac2a6f504d255fc31c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="platformcollectionsinputiterator-class"></a>Classe Platform::Collections::InputIterator
Fornece um InputIterator da biblioteca de modelos padrão para coleções derivadas do tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename X>  
class InputIterator;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `X`  
 O typename da classe de modelo de InputIterator.  
  
### <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`difference_type`|Uma diferença de ponteiro (ptrdiff_t).|  
|`iterator_category`|A categoria de um iterador de entrada (::std::input_iterator_tag).|  
|`pointer`|Um ponteiro para um `const X`|  
|`reference`|Uma referência a um `const X`|  
|`value_type`|O typename `X` .|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Inputiterator:: Inputiterator](#ctor)|Inicializa uma nova instância da classe InputIterator.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador InputIterator::operator!=](#operator-inequality)|Indica se o InputIterator atual não é igual a um InputIterator especificado.|  
|[Operador InputIterator::operator*](#operator-decrement)|Recupera uma referência ao elemento especificado pelo InputIterator atual.|  
|[Operador InputIterator::operator++](#operator-increment)|Incrementa o InputIterator atual.|  
|[Operador InputIterator::operator==](#operator-equality)|Indica se o InputIterator atual é igual a um InputIterator especificado.|  
|[Operador InputIterator::operator->](#operator-arrow)|Recupera o endereço do elemento referenciado pelo InputIterator atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `InputIterator`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Platform::Collections  

## <a name="ctor"></a>Construtor inputiterator:: Inputiterator
Inicializa uma nova instância da classe InputIterator.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
InputIterator();  
explicit InputIterator(Windows::Foundation::Collections<X>^ iter);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `iter`  
 Um objeto do iterador.  
  


## <a name="operator-arrow"></a>Inputiterator:: Operator -&gt; operador
Recupera o endereço do elemento especificado pelo InputIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
pointer operator->() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço do elemento especificado pelo InputIterator atual.  
  


## <a name="operator-dereference"></a>Operador inputiterator:: Operator *
Recupera uma referência ao elemento especificado pelo InputIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
reference operator*() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento especificado pelo InputIterator atual.  
  


## <a name="operator-equality"></a>Inputiterator:: Operator = = operador
Indica se o InputIterator atual é igual a um InputIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator== (const InputIterator& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro InputIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o InputIterator atual for igual a `other`; caso contrário, `false`.  
  


## <a name="operator-increment"></a>Operador inputiterator:: Operator + +
Incrementa o InputIterator atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```    
InputIterator& operator++();   
InputIterator operator++(int);  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira sintaxe incrementa e, em seguida, retorna o InputIterator atual. A segunda sintaxe retorna uma cópia de InputIterator atual e, em seguida, incrementa o InputIterator atual.  
  
### <a name="remarks"></a>Comentários  
 A primeira sintaxe de InputIterator pré-incrementa o InputIterator atual.  
  
 A segunda sintaxe pós-incrementa o InputIterator atual. O tipo `int` na segunda sintaxe indica uma operação de pós-incremento, não um operando de inteiro real.  
  


## <a name="operator-inequality"></a>Inputiterator:: Operator! = operador
Indica se o InputIterator atual não é igual a um InputIterator especificado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
bool operator!=(const InputIterator& other) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `other`  
 Outro InputIterator.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o InputIterator atual não for igual a `other`; caso contrário, `false`.   

  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](platform-namespace-c-cx.md)