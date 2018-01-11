---
title: Operadores &lt;system_error&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- system_error/std::operator!=
- system_error/std::operator==
dev_langs: C++
ms.assetid: c14edefb-bd8a-4e90-88d3-c59c98e6f73c
caps.latest.revision: "11"
manager: ghogen
ms.openlocfilehash: ed01a5abeb54f5071968555b563849e2cd4ac1af
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltsystemerrorgt-operators"></a>Operadores &lt;system_error&gt;
||||  
|-|-|-|  
|[operator!=](#op_neq)|[operator&lt;](#op_lt)|[operator==](#op_eq_eq)|  
  
##  <a name="op_eq_eq"></a>  operator==  
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
  
##  <a name="op_neq"></a>  operator!=  
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
  
##  <a name="op_lt"></a>  operator&lt;  
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



