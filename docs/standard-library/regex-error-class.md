---
title: Classe regex_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- regex_error
- std::regex_error
- regex/std::regex_error
- std::regex_error::code
- regex/std::regex_error::code
dev_langs:
- C++
helpviewer_keywords:
- regex_error class
ms.assetid: 3333a1a3-ca6f-4612-84b2-1b4c7e3db5a4
caps.latest.revision: 19
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
translationtype: Machine Translation
ms.sourcegitcommit: 248e9ba676b906af62f6804f4939e04158a8e2ef
ms.openlocfilehash: e5eab496a34eaef6f6d382ce8b1d10055c6b4422
ms.lasthandoff: 02/25/2017

---
# <a name="regexerror-class"></a>Classe regex_error
Relata um objeto basic_regex incorreto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class regex_error  
 : public std::runtime_error {  
public:  
    explicit regex_error(regex_constants::error_code error);

    regex_constants::error_code code() const;

 
 };  
```  
  
## <a name="remarks"></a>Comentários  
 A classe descreve um objeto de exceção gerado para relatar um erro na construção ou uso de um objeto `basic_regex`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<regex>  
  
 **Namespace:** std  
  
##  <a name="a-nameregexerrorcodea--regexerrorcode"></a><a name="regex_error__code"></a>  regex_error::code  
 Retorna o código de erro.  
  
```  
regex_constants::error_code code() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o valor que foi passado para o construtor do objeto.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__regex_error_code.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    std::regex_error paren(std::regex_constants::error_paren);   
  
    try   
        {   
        std::regex rx("(a");   
        }   
    catch (const std::regex_error& rerr)   
        {   
        std::cout << "regex error: "   
            << (rerr.code() == paren.code()   
                 "unbalanced parentheses" : "")   
            << std::endl;   
        }   
    catch (...)   
        {   
        std::cout << "unknown exception" << std::endl;   
        }   
  
    return (0);   
    }  
  
```  
  
```Output  
regex error: unbalanced parentheses  
```  
  
##  <a name="a-nameregexerrorregexerrora--regexerrorregexerror"></a><a name="regex_error__regex_error"></a>  regex_error::regex_error  
 Constrói o objeto.  
  
```  
regex_error(regex_constants::error_code error);
```  
  
### <a name="parameters"></a>Parâmetros  
 `error`  
 O código de erro.  
  
### <a name="remarks"></a>Comentários  
 O construtor cria um objeto que contém o valor `error`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std__regex__regex_error_construct.cpp   
// compile with: /EHsc   
#include <regex>   
#include <iostream>   
  
int main()   
    {   
    std::regex_error paren(std::regex_constants::error_paren);   
  
    try   
        {   
        std::regex rx("(a");   
        }   
    catch (const std::regex_error& rerr)   
        {   
        std::cout << "regex error: "   
            << (rerr.code() == paren.code()   
                 "unbalanced parentheses" : "")   
            << std::endl;   
        }   
    catch (...)   
        {   
        std::cout << "unknown exception" << std::endl;   
        }   
  
    return (0);   
    }  
  
```  
  
```Output  
regex error: unbalanced parentheses  
```  
  
## <a name="see-also"></a>Consulte também  
[\<regex>](../standard-library/regex.md)  
[Classe regex_constants](../standard-library/regex-constants-class.md)  
[\<Funções regex>](../standard-library/regex-functions.md)  
[Classe regex_iterator](../standard-library/regex-iterator-class.md)  
[\<Operadores regex>](../standard-library/regex-operators.md)  
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)  
[Classe regex_traits](../standard-library/regex-traits-class.md)  
[\<Typedef regex>](../standard-library/regex-typedefs.md)  

