---
title: Operadores de &lt;thread&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- thread/std::operator!=
- thread/std::operator&gt;
- thread/std::operator&gt;=
- thread/std::operator&lt;
- thread/std::operator&lt;&lt;
- thread/std::operator&lt;=
- thread/std::operator==
dev_langs:
- C++
ms.assetid: e6bb6c0f-64f9-4cb2-9ff2-05b88a6ba7ac
caps.latest.revision: 11
manager: ghogen
helpviewer_keywords:
- std::operator!= (thread)
- std::operator&gt; (thread)
- std::operator&gt;= (thread)
- std::operator&lt; (thread)
- std::operator&lt;&lt; (thread)
- std::operator&lt;= (thread)
- std::operator== (thread)
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: ff0fa361845c7bf64dd15bfc4e23be7b92b6cc39
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="ltthreadgt-operators"></a>Operadores &lt;thread&gt;
||||  
|-|-|-|  
|[operator!=](#op_neq)|[operator&gt;](#op_gt)|[operator&gt;=](#op_gt_eq)|  
|[operator&lt;](#op_lt)|[operator&lt;&lt;](#op_lt_lt)|[operator&lt;=](#op_lt_eq)|  
|[operator==](#op_eq_eq)|  
  
##  <a name="op_gt_eq"></a>  operator&gt;=  
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
  
##  <a name="op_gt"></a>  operator&gt;  
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
  
##  <a name="op_lt_eq"></a>  operator&lt;=  
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
  
##  <a name="op_lt"></a>  operator&lt;  
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
  
##  <a name="op_neq"></a>  operator!=  
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
  
##  <a name="op_eq_eq"></a>  operator==  
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
  
##  <a name="op_lt_lt"></a>  operator&lt;&lt;  
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




