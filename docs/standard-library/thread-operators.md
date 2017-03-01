---
title: Operadores de &lt;thread&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: e6bb6c0f-64f9-4cb2-9ff2-05b88a6ba7ac
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 7e849e8585b372b5b423a6c960aa926ac7d5cfec
ms.lasthandoff: 02/25/2017

---
# <a name="ltthreadgt-operators"></a>Operadores &lt;thread&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|[operator&gt;=](#operator_gt__eq)|  
|[operator&lt;](#operator_lt_)|[operator&lt;&lt;](#operator_lt__lt_)|[operator&lt;=](#operator_lt__eq)|  
|[operator==](#operator_eq_eq)|  
  
##  <a name="a-nameoperatorgteqa--operatorgt"></a><a name="operator_gt__eq"></a>  operator&gt;=  
 Determina se um objeto `thread::id` é maior ou igual a outro.  
  
```cpp  
bool operator>= (
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `!(Left < Right)`  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatorgta--operatorgt"></a><a name="operator_gt_"></a>  operator&gt;  
 Determina se um objeto `thread::id` é maior que outro.  
  
```cpp  
bool operator> (
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `Right < Left`  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatorlteqa--operatorlt"></a><a name="operator_lt__eq"></a>  operator&lt;=  
 Determina se um objeto `thread::id` é menor ou igual a outro.  
  
```cpp  
bool operator<= (
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `!(Right < Left)`  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatorlta--operatorlt"></a><a name="operator_lt_"></a>  operator&lt;  
 Determina se um objeto `thread::id` é menor que outro.  
  
```cpp  
bool operator<(
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se `Left` preceder `Right` na ordenação total; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 O operador define uma ordenação total em todos os objetos `thread::id`. Esses objetos podem ser usados como chaves em contêineres associativos.  
  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
 Compara dois objetos `thread::id` quanto à desigualdade.  
  
```cpp  
bool operator!= (
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `!(Left == Right)`  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
 Compara dois objetos `thread::id` quanto à igualdade.  
  
```cpp  
bool operator== (
    thread::id Left,
    thread::id Right) noexcept
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `thread::id` à esquerda.  
  
 `Right`  
 O objeto `thread::id` à direita.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os dois objetos representarem o mesmo thread de execução ou se nenhum dos objetos representar um thread de execução; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Essa função não gera exceções.  
  
##  <a name="a-nameoperatorltlta--operatorltlt"></a><a name="operator_lt__lt_"></a>  operator&lt;&lt;  
 Insere uma representação de texto de um objeto `thread::id` em um fluxo.  
  
```cpp  
template <class Elem, class Tr>
basic_ostream<Elem, Tr>& operator<<(
    basic_ostream<Elem, Tr>& Ostr, thread::id Id);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Ostr`  
 Um objeto [basic_ostream](../standard-library/basic-ostream-class.md).  
  
 `Id`  
 Um objeto `thread::id`.  
  
### <a name="return-value"></a>Valor de retorno  
 `Ostr`.  
  
### <a name="remarks"></a>Comentários  
 Essa função insere `Id` em `Ostr`.  
  
 Se dois objetos `thread::id` forem comparados como iguais, as representações de texto inseridas desses objetos serão as mesmas.  
  
## <a name="see-also"></a>Consulte também  
 [\<thread>](../standard-library/thread.md)




