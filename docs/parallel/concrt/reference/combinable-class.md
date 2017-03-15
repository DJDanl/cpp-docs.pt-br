---
title: Classe combinable | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ppl/concurrency::combinable
dev_langs:
- C++
helpviewer_keywords:
- combinable class
ms.assetid: fe0bfbf6-6250-47da-b8d0-f75369f0b5be
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 4ed3ce3d441566a0fb301d01123335846d86a8af
ms.lasthandoff: 02/25/2017

---
# <a name="combinable-class"></a>Classe combinable
O `combinable<T>` objeto se destina a fornecer cópias de thread particular de dados, para executar computações subpropriedades de locais de thread sem bloqueio durante algoritmos paralelos. No final da operação em paralelo, as computações de subpropriedades thread privado, em seguida, podem ser mescladas em um resultado final. Essa classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho se há muita contenção naquela variável compartilhada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>
class combinable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados do resultado final mesclado. O tipo deve ter um construtor de cópia e um construtor padrão.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor combinable](#ctor)|Sobrecarregado. Constrói um novo `combinable` objeto.|  
|[~ Destruidor Combinável](#dtor)|Destrói um objeto `combinable`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Clear](#clear)|Limpa os resultados intermediários computacionais um uso anterior.|  
|[Método combine](#combine)|Calcula um valor final do conjunto de computações subpropriedades de thread local chamando o functor combinar fornecido.|  
|[Método combine_each](#combine_each)|Calcula um valor final do conjunto de computações subpropriedades de thread local chamando o functor fornecido combinar uma vez por computação subpropriedades de thread local. O resultado final é acumulado pelo objeto de função.|  
|[Método local](#local)|Sobrecarregado. Retorna uma referência ao cálculo thread private sub.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador Operator =](#operator_eq)|Atribui a um `combinable` objeto de outro `combinable` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `combinable`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namecleara-clear"></a><a name="clear"></a>Limpar 

 Limpa os resultados intermediários computacionais um uso anterior.  
  
```
void clear();
```  
  
##  <a name="a-namectora-combinable"></a><a name="ctor"></a>Combinável 

 Constrói um novo `combinable` objeto.  
  
```
combinable();

template <typename _Function>
explicit combinable(_Function _FnInitialize);

combinable(const combinable& _Copy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo de objeto de inicialização de functor.  
  
 `_FnInitialize`  
 Uma função que será chamada para inicializar cada novo valor de thread particular do tipo `T`. Ele deve oferecer suporte a um operador de chamada de função com a assinatura `T ()`.  
  
 `_Copy`  
 Existente `combinable` objeto a ser copiado para esta.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa novos elementos com o construtor padrão para o tipo `T`.  
  
 O segundo construtor inicializa novos elementos usando o functor de inicialização fornecida como o `_FnInitialize` parâmetro.  
  
 O terceiro construtor é o construtor de cópia.  
  
##  <a name="a-namedtora-combinable"></a><a name="dtor"></a>~ combinable 

 Destrói um objeto `combinable`.  
  
```
~combinable();
```  
  
##  <a name="a-namecombinea-combine"></a><a name="combine"></a>combinar 

 Calcula um valor final do conjunto de computações subpropriedades de thread local chamando o functor combinar fornecido.  
  
```
template<typename _Function>
T combine(_Function _FnCombine) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo de objeto de função que será chamado para combinar dois cálculos de subpropriedades de thread local.  
  
 `_FnCombine`  
 O functor é usado para combinar os cálculos de subpropriedades. A assinatura é `T (T, T)` ou `T (const T&, const T&)`, e ele deve ser associativa e comutativa.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado final da combinação de todos os threads privado sub computações.  
  
##  <a name="a-namecombineeacha-combineeach"></a><a name="combine_each"></a>combine_each 

 Calcula um valor final do conjunto de computações subpropriedades de thread local chamando o functor fornecido combinar uma vez por computação subpropriedades de thread local. O resultado final é acumulado pelo objeto de função.  
  
```
template<typename _Function>
void combine_each(_Function _FnCombine) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo de objeto de função que será chamado para combinar uma computação de subpropriedades de local de thread única.  
  
 `_FnCombine`  
 O functor é usado para combinar uma computação subpropriedades. A assinatura é `void (T)` ou `void (const T&)`e deve ser associativa e comutativa.  
  
##  <a name="a-namelocala-local"></a><a name="local"></a>local 

 Retorna uma referência ao cálculo thread private sub.  
  
```
T& local();

T& local(bool& _Exists);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Exists`  
 Uma referência a um valor booleano. O valor booliano referenciado por esse argumento será definido como `true` se a computação subpropriedades já existia neste thread e definido como `false` se esse foi o primeiro cálculo subpropriedades neste thread.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao cálculo thread private sub.  
  
##  <a name="a-nameoperatoreqa-operator"></a><a name="operator_eq"></a>operador = 

 Atribui a um `combinable` objeto de outro `combinable` objeto.  
  
```
combinable& operator= (const combinable& _Copy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Copy`  
 Existente `combinable` objeto a ser copiado para esta.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `combinable` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

