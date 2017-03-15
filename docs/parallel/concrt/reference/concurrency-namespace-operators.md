---
title: namespace Concurrency operadores | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8e373f23-fc8e-49f7-82e6-ba0c57b822f8
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: fa774c7f025b581d65c28d65d83e22ff2d798230
ms.openlocfilehash: 7fc7b500d882bb4e023904a147a7736996b5c5de
ms.lasthandoff: 02/25/2017

---
# <a name="concurrency-namespace-operators"></a>Operadores de namespace de simultaneidade
||||  
|-|-|-|  
|[operador! = operador](#operator_neq)|[operador&amp; &amp; operador](#operator_amp_amp)|[operador&gt; operador](#operator_gt)|  
|[operador&gt;operador =](#operator_gt_eq)|[operador&lt; operador](#operator_lt)|[operador&lt;operador =](#operator_lt_eq)|  
|[operador Operator = =](#operator_eq_eq)|[operator|| Operator](#operator_lor)|  
  
##  <a name="a-nameoperatorlora--operator124124-operator"></a><a name="operator_lor"></a>operador | | Operador  
 Cria uma tarefa que será concluída com êxito quando qualquer uma das tarefas fornecidas como argumentos forem concluídas com êxito.  
  
```  
template<
    typename _ReturnType  
>  
task<_ReturnType>   operator||(
    const task<_ReturnType>& _Lhs,  
    const task<_ReturnType>& _Rhs);

 
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>   operator||(
    const task<std::vector<_ReturnType>>& _Lhs,  
    const task<_ReturnType>& _Rhs);

 
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>   operator||(
    const task<_ReturnType>& _Lhs,  
    const task<std::vector<_ReturnType>>& _Rhs);

 
inline task<void>   operator||(
    const task<void>& _Lhs,  
    const task<void>& _Rhs);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_ReturnType`  
 O tipo da tarefa retornada.  
  
 `_Lhs`  
 A primeira tarefa a combinar na tarefa resultante.  
  
 `_Rhs`  
 A segunda tarefa a combinar na tarefa resultante.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma tarefa concluída com êxito quando qualquer uma das tarefas de entrada foi concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.  
  
### <a name="remarks"></a>Comentários  
 Se ambas as tarefas são canceladas ou lançam exceções, a tarefa retornada será concluída em estado cancelado, e uma das exceções, se nenhum for encontrado, será gerada quando você chamar `get()` ou `wait()` nessa tarefa.  
  
##  <a name="a-nameoperatorampampa--operatorampamp-operator"></a><a name="operator_amp_amp"></a>operador&amp; &amp; operador  
 Cria uma tarefa que será concluída com êxito quando ambas as tarefas fornecidas como argumentos forem concluídas com êxito.  
  
```  
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>    operator&&(
    const task<_ReturnType>& _Lhs,  
    const task<_ReturnType>& _Rhs);

 
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>    operator&&(
    const task<std::vector<_ReturnType>>& _Lhs,  
    const task<_ReturnType>& _Rhs);

 
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>    operator&&(
    const task<_ReturnType>& _Lhs,  
    const task<std::vector<_ReturnType>>& _Rhs);

 
template<
    typename _ReturnType  
>  
task<std::vector<_ReturnType>>    operator&&(
    const task<std::vector<_ReturnType>>& _Lhs,  
    const task<std::vector<_ReturnType>>& _Rhs);

 
inline task<void>    operator&&(
    const task<void>& _Lhs,  
    const task<void>& _Rhs);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_ReturnType`  
 O tipo da tarefa retornada.  
  
 `_Lhs`  
 A primeira tarefa a combinar na tarefa resultante.  
  
 `_Rhs`  
 A segunda tarefa a combinar na tarefa resultante.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma tarefa que foi concluída com êxito quando ambas as tarefas de entrada foram concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.  
  
### <a name="remarks"></a>Comentários  
 Se uma das tarefas for cancelada ou gerar uma exceção, a tarefa retornada será concluída antecipadamente, no estado cancelado, e a exceção, se alguma for encontrada, será gerada se você chamar `get()` ou `wait()` nessa tarefa.  
  
##  <a name="a-nameoperatoreqeqa--operator-operator"></a><a name="operator_eq_eq"></a>operador Operator = =  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual do `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator== (
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o vetor simultâneo no lado esquerdo do operador é igual ao vetor simultâneo no lado direito do operador; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Dois vetores simultâneas são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
##  <a name="a-nameoperatorneqa--operator-operator"></a><a name="operator_neq"></a>operador! = operador  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual do `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator!= (
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se os vetores simultâneos não forem iguais; `false` se os vetores simultâneos são iguais.  
  
### <a name="remarks"></a>Comentários  
 Dois vetores simultâneas são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
##  <a name="a-nameoperatorlta--operatorlt-operator"></a><a name="operator_lt"></a>operador&lt; operador  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor do que o `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator<(
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o vetor simultâneo no lado esquerdo do operador for menor que o vetor simultâneo no lado direito do operador; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
##  <a name="a-nameoperatorlteqa--operatorlt-operator"></a><a name="operator_lt_eq"></a>operador&lt;operador =  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual a `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator<= (
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o vetor simultâneo no lado esquerdo do operador é menor ou igual ao vetor simultâneo no lado direito do operador; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
##  <a name="a-nameoperatorgta--operatorgt-operator"></a><a name="operator_gt"></a>operador&gt; operador  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator>(
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o vetor simultâneo no lado esquerdo do operador for maior que o vetor simultâneo no lado direito do operador; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
##  <a name="a-nameoperatorgteqa--operatorgt-operator"></a><a name="operator_gt_eq"></a>operador&gt;operador =  
 Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que ou igual a `concurrent_vector` objeto no lado direito.  
  
```  
template<
    typename T,  
    class A1,  
    class A2  
>  
inline bool operator>= (
    const concurrent_vector<T, A1>& _A,  
    const concurrent_vector<T, A2>& _B);
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados dos elementos armazenados em vetores de simultâneas.  
  
 `A1`  
 O tipo de alocador do primeiro `concurrent_vector` objeto.  
  
 `A2`  
 O tipo de alocador do segundo `concurrent_vector` objeto.  
  
 `_A`  
 Um objeto do tipo `concurrent_vector`.  
  
 `_B`  
 Um objeto do tipo `concurrent_vector`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o vetor simultâneo no lado esquerdo do operador é maior que ou igual ao vetor simultâneo no lado direito do operador; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.  
  
 Esse método não é uma prova de simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneas `_A` ou `_B`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

