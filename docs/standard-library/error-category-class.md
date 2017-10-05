---
title: Classe error_category | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- system_error/std::error_category
- system_error/std::error_category::value_type
- system_error/std::error_category::default_error_condition
- system_error/std::error_category::equivalent
- system_error/std::error_category::message
- system_error/std::error_category::name
dev_langs:
- C++
helpviewer_keywords:
- std::error_category
- std::error_category::value_type
- std::error_category::default_error_condition
- std::error_category::equivalent
- std::error_category::message
- std::error_category::name
ms.assetid: e0a71e14-852d-4905-acd6-5f8ed426706d
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 3e1b51db369a5f36b4c7428083d7dde4728642c3
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="errorcategory-class"></a>Classe error_category
Representa a base abstrata e comum para objetos e descreve uma categoria de códigos de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class error_category;
```  
  
## <a name="remarks"></a>Comentários  
 Dois objetos predefinidos implementam `error_category`: [generic_category](../standard-library/system-error-functions.md#generic_category) e [system_category](../standard-library/system-error-functions.md#system_category).  
  
### <a name="typedefs"></a>TypeDefs  
  
|||  
|-|-|  
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[default_error_condition](#default_error_condition)|Armazena o valor de código de erro para um objeto de condição de erro.|  
|[equivalent](#equivalent)|Retorna um valor que especifica se os objetos de erro são equivalentes.|  
|[message](#message)|Retorna o nome do código de erro especificado.|  
|[name](#name)|Retorna o nome da categoria.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator==](#op_eq_eq)|Testa a igualdade entre objetos `error_category`.|  
|[operator!=](#op_neq)|Testa a desigualdade entre objetos `error_category`.|  
|[operator<](#op_lt)|Testa se um objeto [error_category](../standard-library/error-category-class.md) é menor que o objeto `error_category` passado para comparação.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
##  <a name="default_error_condition"></a>  error_category::default_error_condition  
 Armazena o valor de código de erro para um objeto de condição de erro.  
  
```
virtual error_condition default_error_condition(int _Errval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Errval`|O valor de código de erro para armazenar em [error_condition](../standard-library/error-condition-class.md).|  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `error_condition(_Errval, *this)`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="equivalent"></a>  error_category::equivalent  
 Retorna um valor que especifica se os objetos de erro são equivalentes.  
  
```
virtual bool equivalent(value_type _Errval,
    const error_condition& _Cond) const;

virtual bool equivalent(const error_code& _Code,
    value_type _Errval) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Errval`|O valor do código de erro a ser comparado.|  
|`_Cond`|O objeto [error_condition](../standard-library/error-condition-class.md) a ser comparado.|  
|`_Code`|O objeto [error_code](../standard-library/error-code-class.md) a ser comparado.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se a categoria e valor forem iguais. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro retorna `*this == _Cond.category() && _Cond.value() == _Errval`.  
  
 A segunda função membro retorna `*this == _Code.category() && _Code.value() == _Errval`.  
  
##  <a name="message"></a>  error_category::message  
 Retorna o nome do código de erro especificado.  
  
```
virtual string message(error_code::value_type val) const = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O valor do código de erro a ser descrito.|  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um nome descritivo do código de erro `val` para a categoria.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="name"></a>  error_category::name  
 Retorna o nome da categoria.  
  
```
virtual const char *name() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o nome da categoria como uma cadeia de caracteres de byte com terminação nula.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="op_eq_eq"></a>  error_category::operator==  
 Testa a igualdade entre objetos `error_category`.  
  
```
bool operator==(const error_category& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto a ser testado quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos forem iguais; **false** se os objetos não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 Esse operador de membro retorna `this == &right`.  
  
##  <a name="op_neq"></a>  error_category::operator!=  
 Testa a desigualdade entre objetos `error_category`.  
  
```
bool operator!=(const error_category& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto a ser testado quanto à desigualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto `error_category` não for igual ao objeto `error_category` passado em `right`. Caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna `(!*this == right)`.  
  
##  <a name="op_lt"></a>  error_category::operator&lt;  
 Testa se um objeto [error_category](../standard-library/error-category-class.md) é menor que o objeto `error_category` passado para comparação.  
  
```
bool operator<(const error_category& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto `error_category` a ser comparado.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto `error_category` for menor que o objeto `error_category` passado para comparação. Caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna `this < &right`.  
  
##  <a name="value_type"></a>  error_category::value_type  
 Um tipo que representa o valor do código de erro armazenado.  
  
```
typedef int value_type;
```  
  
### <a name="remarks"></a>Comentários  
 Esta definição de tipo é um sinônimo para `int`.  
  
## <a name="see-also"></a>Consulte também  
 [<system_error>](../standard-library/system-error.md)




