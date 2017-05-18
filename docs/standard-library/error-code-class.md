---
title: Classe error_code | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- error_code
- system_error/std::error_code
- system_error/std::error_code::value_type
- system_error/std::error_code::assign
- system_error/std::error_code::category
- system_error/std::error_code::clear
- system_error/std::error_code::default_error_condition
- system_error/std::error_code::message
- system_error/std::error_code::operator bool
dev_langs:
- C++
helpviewer_keywords:
- error_code class
ms.assetid: c09b4a96-cb14-4281-a319-63543f9b2b4a
caps.latest.revision: 17
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 82c70317383fe096c56b0d5b79bab24175d2872a
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="errorcode-class"></a>Classe error_code
Representa os erros de sistema de nível inferior específicos à implementação.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class error_code;
```  
  
## <a name="remarks"></a>Comentários  
 Um objeto do tipo de classe `error_code` armazena um valor de código de erro e um ponteiro para um objeto que representa uma [categoria](../standard-library/error-category-class.md) de códigos de erro que descrevem erros de sistema de nível inferior relatados.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[error_code](#error_code)|Constrói um objeto do tipo `error_code`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[value_type](#value_type)|Um tipo que representa o valor do código de erro armazenado.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[assign](#assign)|Atribui um valor de código de erro e categoria a um código de erro.|  
|[category](#category)|Retorna a categoria de erro.|  
|[clear](#clear)|Limpa o valor do código de erro e a categoria.|  
|[default_error_condition](#default_error_condition)|Retorna a condição de erro padrão.|  
|[message](#message)|Retorna o nome do código de erro.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator==](#op_eq_eq)|Testa a igualdade entre objetos `error_code`.|  
|[operator!=](#op_neq)|Testa a desigualdade entre objetos `error_code`.|  
|[operator<](#op_lt)|Testa se o objeto `error_code` é menor que o objeto `error_code` passado para comparação.|  
|[operator=](#op_eq)|Atribui um novo valor de enumeração ao objeto `error_code`.|  
|[operator bool](#op_bool)|Converte uma variável do tipo `error_code`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
##  <a name="assign"></a>  error_code::assign  
 Atribui um valor de código de erro e categoria a um código de erro.  
  
```
void assign(value_type val, const error_category& _Cat);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O valor de código de erro para armazenar em `error_code`.|  
|`_Cat`|A categoria de erro para armazenar em `error_code`.|  
  
### <a name="remarks"></a>Comentários  
 A função de membro armazena `val` como o valor de código de erro e um ponteiro para `_Cat`.  
  
##  <a name="category"></a>  error_code::category  
 Retorna a categoria de erro.  
  
```
const error_category& category() const;
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="clear"></a>  error_code::clear  
 Limpa o valor do código de erro e a categoria.  
  
```
clear();
```  
  
### <a name="remarks"></a>Comentários  
 A função de membro armazena um valor zero de código de erro e um ponteiro para o objeto [generic_category](../standard-library/system-error-functions.md#generic_category).  
  
##  <a name="default_error_condition"></a>  error_code::default_error_condition  
 Retorna a condição de erro padrão.  
  
```
error_condition default_error_condition() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O [error_condition](../standard-library/error-condition-class.md) especificado por [default_error_condition](../standard-library/error-category-class.md#default_error_condition).  
  
### <a name="remarks"></a>Comentários  
 Essa função membro retorna `category().default_error_condition(value())`.  
  
##  <a name="error_code"></a>  error_code::error_code  
 Constrói um objeto do tipo `error_code`.  
  
```
error_code();

error_code(value_type val, const error_category& _Cat);

template <class _Enum>
error_code(_Enum _Errcode,
    typename enable_if<is_error_code_enum<_Enum>::value,
    error_code>::type* = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`val`|O valor de código de erro para armazenar em `error_code`.|  
|`_Cat`|A categoria de erro para armazenar em `error_code`.|  
|`_Errcode`|O valor da enumeração para armazenar em `error_code`.|  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor armazena um valor zero de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).  
  
 O segundo construtor armazena `val` como o valor de código de erro e um ponteiro para [error_category](http://msdn.microsoft.com/en-us/6fe57a15-63a1-4e79-8af4-6738e43e19c8).  
  
 O terceiro construtor armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category).  
  
##  <a name="message"></a>  error_code::message  
 Retorna o nome do código de erro.  
  
```
string message() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma `string` que representa o nome do código de erro.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro retorna `category().message(value())`.  
  
##  <a name="op_eq_eq"></a>  error_code::operator==  
 Testa a igualdade entre objetos `error_code`.  
  
```
bool operator==(const error_code& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto a ser testado quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os objetos forem iguais; **false** se os objetos não forem iguais.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna `category() == right.category() && value == right.value()`.  
  
##  <a name="op_neq"></a>  error_code::operator!=  
 Testa a desigualdade entre objetos `error_code`.  
  
```
bool operator!=(const error_code& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto a ser testado quanto à desigualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto `error_code` não for igual ao objeto `error_code` passado em `right`. Caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna `!(*this == right)`.  
  
##  <a name="op_lt"></a>  error_code::operator&lt;  
 Testa se o objeto [error_code](http://msdn.microsoft.com/en-us/09c6ef90-b6f8-430a-b584-e168716c7e31) é menor que o objeto `error_code` passado para comparação.  
  
```
bool operator<(const error_code& right) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto error_code a ser comparado.|  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o objeto `error_code` for menor que o objeto `error_code` passado para comparação. Caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro retorna `category() < right.category() || category() == right.category() && value < right.value()`.  
  
##  <a name="op_eq"></a>  error_code::operator=  
 Atribui um novo valor de enumeração ao objeto [error_code](http://msdn.microsoft.com/en-us/09c6ef90-b6f8-430a-b584-e168716c7e31).  
  
```
template <class _Enum>
typename enable_if<is_error_code_enum<_Enum>::value,
    error_code>::type&
 operator=(_Enum _Errcode);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Errcode`|O valor de enumeração a ser atribuído ao objeto `error_code`.|  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao objeto `error_code` ao qual está sendo atribuído um novo valor de enumeração pela função de membro.  
  
### <a name="remarks"></a>Comentários  
 O operador membro armazena `(value_type)_Errcode` como o valor de código de erro e um ponteiro para [generic_category](../standard-library/system-error-functions.md#generic_category). Ele retorna `*this`.  
  
##  <a name="op_bool"></a>  error_code::operator bool  
 Converte uma variável do tipo `error_code`.  
  
```
explicit operator bool() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor booliano do objeto `error_code`.  
  
### <a name="remarks"></a>Comentários  
 O operador retornará um valor que pode ser convertido em `true` somente se o [valor](#value) não for igual a zero. O tipo de retorno é pode ser convertido apenas para `bool`, não para `void *` ou outros tipos escalares conhecidos.  
  
##  <a name="value"></a>  error_code::value  
 Retorna o valor de código de erro armazenado.  
  
```
value_type value() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do código de erro armazenado do tipo [value_type](#value_type).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="value_type"></a>  error_code::value_type  
 Um tipo que representa o valor do código de erro armazenado.  
  
```
typedef int value_type;
```  
  
### <a name="remarks"></a>Comentários  
 Esta definição de tipo é um sinônimo para `int`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe error_category](../standard-library/error-category-class.md)   
 [<system_error>](../standard-library/system-error.md)




