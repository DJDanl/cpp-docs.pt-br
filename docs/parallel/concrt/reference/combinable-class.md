---
title: Classe combinable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- combinable
- PPL/concurrency::combinable
- PPL/concurrency::combinable::combinable
- PPL/concurrency::combinable::clear
- PPL/concurrency::combinable::combine
- PPL/concurrency::combinable::combine_each
- PPL/concurrency::combinable::local
dev_langs: C++
helpviewer_keywords: combinable class
ms.assetid: fe0bfbf6-6250-47da-b8d0-f75369f0b5be
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 698c59614894314e70019fe2b4621755b4cd3085
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="combinable-class"></a>Classe combinable
O `combinable<T>` objeto destina-se a fornecer thread privada cópias de dados, para executar cálculos de subgrupos de local de thread livre de bloqueios durante os algoritmos paralelos. No final da operação em paralelo, os cálculos sub particular de thread, em seguida, podem ser mesclados em um resultado final. Esta classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho se caso contrário, haverá muita contenção nessa variável compartilhada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>
class combinable;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados do resultado final mesclado. O tipo deve ter um construtor de cópia e um construtor padrão.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[podem ser combinadas](#ctor)|Sobrecarregado. Constrói um novo objeto `combinable`.|  
|[~ Destruidor combinable](#dtor)|Destrói um objeto `combinable`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[clear](#clear)|Limpa os resultados intermediários computacionais um uso anterior.|  
|[combine](#combine)|Calcula um valor final do conjunto de cálculos de subgrupos de local de thread chamando o functor combinar fornecido.|  
|[combine_each](#combine_each)|Calcula um valor final do conjunto de cálculos de subgrupos de local de thread chamando o functor fornecido combinar uma vez por computação sub local de thread. O resultado final é acumulado pelo objeto de função.|  
|[local](#local)|Sobrecarregado. Retorna uma referência para a computação sub particular de thread.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Atribui a um `combinable` objeto de outro `combinable` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [objetos e contêineres paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `combinable`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ppl.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="clear"></a>Limpar 

 Limpa os resultados intermediários computacionais um uso anterior.  
  
```
void clear();
```  
  
##  <a name="ctor"></a>podem ser combinadas 

 Constrói um novo objeto `combinable`.  
  
```
combinable();

template <typename _Function>
explicit combinable(_Function _FnInitialize);

combinable(const combinable& _Copy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de functor de inicialização.  
  
 `_FnInitialize`  
 Uma função que será chamada para inicializar cada novo valor de thread particular do tipo `T`. Ele deve oferecer suporte a um operador de chamada de função com a assinatura `T ()`.  
  
 `_Copy`  
 Um existente `combinable` objeto a ser copiado a este.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa novos elementos com o construtor padrão para o tipo de `T`.  
  
 O segundo construtor inicializa novos elementos usando o functor de inicialização fornecida como o `_FnInitialize` parâmetro.  
  
 O construtor de terceiro é o construtor de cópia.  
  
##  <a name="dtor"></a>~ combinable 

 Destrói um objeto `combinable`.  
  
```
~combinable();
```  
  
##  <a name="combine"></a>combinar 

 Calcula um valor final do conjunto de cálculos de subgrupos de local de thread chamando o functor combinar fornecido.  
  
```
template<typename _Function>
T combine(_Function _FnCombine) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será invocado para combinar dois cálculos de subgrupos de local de thread.  
  
 `_FnCombine`  
 Functor que é usada para combinar os cálculos sub. A assinatura é `T (T, T)` ou `T (const T&, const T&)`, e ele deve ser comutativas e associativas.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado final da combinação de todos os cálculos de sub particular de thread.  
  
##  <a name="combine_each"></a>combine_each 

 Calcula um valor final do conjunto de cálculos de subgrupos de local de thread chamando o functor fornecido combinar uma vez por computação sub local de thread. O resultado final é acumulado pelo objeto de função.  
  
```
template<typename _Function>
void combine_each(_Function _FnCombine) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Function`  
 O tipo do objeto de função que será invocado para combinar uma computação de subgrupos de local de thread único.  
  
 `_FnCombine`  
 Functor que é usada para combinar uma computação sub. A assinatura é `void (T)` ou `void (const T&)`e deve ser associativas e comutativas.  
  
##  <a name="local"></a>local 

 Retorna uma referência para a computação sub particular de thread.  
  
```
T& local();

T& local(bool& _Exists);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Exists`  
 Uma referência a um valor booleano. O valor booliano referenciado por este argumento será definido como `true` se a computação sub já existia neste thread e definido como `false` se esta for a primeira computação sub neste thread.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a computação sub particular de thread.  
  
##  <a name="operator_eq"></a>operador = 

 Atribui a um `combinable` objeto de outro `combinable` objeto.  
  
```
combinable& operator= (const combinable& _Copy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Copy`  
 Um existente `combinable` objeto a ser copiado a este.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `combinable` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
