---
title: Operadores de namespace de simultaneidade (AMP) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 77f1ae17-1eb2-480d-8fe5-66d4c24bb91e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 308c09af9989aa998a7e1f7d748f52a2d8dca391
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="concurrency-namespace-operators-amp"></a>Operadores de namespace de simultaneidade (AMP)
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator%](#operator_mod)|[operator*](#operator_star)|  
|[operator+](#operator_add)|[operator-](#operator-)|[operator/](#operator_div)|  
|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_eq_eq"></a>  operator==   
 Determina se os argumentos especificados são iguais.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
bool operator== (
    const _Tuple_type<_Rank>& _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 Uma das tuplas a ser comparado.  
  
 `_Rhs`  
 Uma das tuplas a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se as tuplas forem iguais; Caso contrário, `false`.  
  
##  <a name="operator_neq"></a>  operator!=   
 Determina se os argumentos especificados não são iguais.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
bool operator!= (
    const _Tuple_type<_Rank>& _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 Uma das tuplas a ser comparado.  
  
 `_Rhs`  
 Uma das tuplas a ser comparado.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se as tuplas não forem iguais; Caso contrário, `false`.  
  
##  <a name="operator_add"></a>  operator+   

 Calcula a soma de component-wise dos argumentos especificados.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    const _Tuple_type<_Rank>& _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    const _Tuple_type<_Rank>& _Lhs,  
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    typename _Tuple_type<_Rank>::value_type _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 Um dos argumentos para adicionar.  
  
 `_Rhs`  
 Um dos argumentos para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 A soma de component-wise dos argumentos especificados.  
  
##  <a name="operator-"></a>  operator-   

 Calcula a diferença component-wise entre os argumentos especificados.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator-(
    const _Tuple_type<_Rank>& _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator-(
    const _Tuple_type<_Rank>& _Lhs,  
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator-(
    typename _Tuple_type<_Rank>::value_type _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 O argumento deve ser subtraído.  
  
 `_Rhs`  
 O argumento para subtrair.  
  
### <a name="return-value"></a>Valor de retorno  
 A diferença component-wise entre os argumentos especificados.  
  
##  <a name="operator_star"></a>  operator*   

 Calcula o produto component-wise dos argumentos especificados.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator*(
    const _Tuple_type<_Rank>& _Lhs,  
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator*(
    typename _Tuple_type<_Rank>::value_type _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp, cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 Uma das tuplas multiplicar.  
  
 `_Rhs`  
 Uma das tuplas multiplicar.  
  
### <a name="return-value"></a>Valor de retorno  
 O produto component-wise dos argumentos especificados.  
  

##  <a name="operator_div"></a>  operator/   
 Calcula o quociente component-wise dos argumentos especificados.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator/(
    const _Tuple_type<_Rank>& _Lhs,  
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator/(
    typename _Tuple_type<_Rank>::value_type _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 A tupla a ser dividida.  
  
 `_Rhs`  
 A tupla pelo qual dividir.  
  
### <a name="return-value"></a>Valor de retorno  
 O quociente component-wise dos argumentos especificados.  
  
##  <a name="operator_mod"></a> operator%   

 Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.  
  
```  
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator%(
    const _Tuple_type<_Rank>& _Lhs,  
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

 
template <
    int _Rank,  
    template <int> class _Tuple_type  
>  
_Tuple_type<_Rank>   operator%(
    typename _Tuple_type<_Rank>::value_type _Lhs,  
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Rank`  
 A ordem dos argumentos de tupla.  
  
 `_Lhs`  
 A tupla do qual o módulo é calculado.  
  
 `_Rhs`  
 A tupla ao módulo por.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do módulo do argumento especificado primeiro o segundo argumento especificado.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade ](concurrency-namespace-cpp-amp.md)
