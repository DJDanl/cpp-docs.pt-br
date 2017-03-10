---
title: Operadores &lt;system_error&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: c14edefb-bd8a-4e90-88d3-c59c98e6f73c
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 82f7876aca66524ba50b1e01b74437d8a2117976
ms.lasthandoff: 02/25/2017

---
# <a name="ltsystemerrorgt-operators"></a>Operadores &lt;system_error&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator&lt;](#operator_lt_)|[operator==](#operator_eq_eq)|  
  
##  <a name="operator_eq_eq"></a>  operator==  
 Testa se o objeto à esquerda do operador é igual ao objeto à direita.  
  
```
bool operator==(const error_code& left,
    const error_condition& right);

bool operator==(const error_condition& left,
    const error_code& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|O objeto a ser testado quanto à igualdade.|  
|`right`|O objeto a ser testado quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos forem iguais; **false** se os objetos não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Essa função retorna `left.category() == right.category() && left.value() == right.value()`.  
  
##  <a name="operator_neq"></a>  operator!=  
 Testa se o objeto à esquerda do operador é diferente do objeto à direita.  
  
```
bool operator!=(const error_code& left,
    const error_condition& right);

bool operator!=(const error_condition& left,
    const error_code& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|O objeto a ser testado quanto à desigualdade.|  
|`right`|O objeto a ser testado quanto à desigualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto passado em `left` não for igual ao objeto passado em `right`; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Essa função retorna `!(left == right)`.  
  
##  <a name="operator_lt_"></a>  operator&lt;  
 Testa se um objeto é menor que o objeto passado para comparação.  
  
```
template <class _Enum>  
inline bool operator<(
    _Enum left,
    typename enable_if<is_error_code_enum<_Enum>::value,
    const error_code&>::type right);

template <class _Enum>  
inline bool operator<(
    typename enable_if<is_error_code_enum<_Enum>::value,
    const error_code&>::type left, _Enum right);

template <class _Enum>  
inline bool operator<(
    _Enum left,
    typename enable_if<is_error_condition_enum<_Enum>::value,
    const error_condition&>::type right);

template <class _Enum>  
inline bool operator<(
    typename enable_if<is_error_condition_enum<_Enum>::value,
    const error_condition&>::type left, _Enum right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|O objeto a ser comparado.|  
|`right`|O objeto a ser comparado.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto passado em `left` for menor que o objeto passado em `right`; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Essa função testa a ordem do erro.  
  
## <a name="see-also"></a>Consulte também  
 [<system_error>](../standard-library/system-error.md)




