---
title: Classe regex_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- regex/std::regex_error
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
ms.workload:
- cplusplus
ms.openlocfilehash: edcba7e378fc6b7f6bf9028778aa2911fa140dd6
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="regexerror-class"></a>Classe regex_error

Relata um objeto basic_regex incorreto.

## <a name="syntax"></a>Sintaxe

```cpp
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

## <a name="code"></a>  regex_error::code

Retorna o código de erro.

```cpp
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

## <a name="regex_error"></a>  regex_error::regex_error

Constrói o objeto.

```cpp
regex_error(regex_constants::error_code error);
```

### <a name="parameters"></a>Parâmetros

`error` O código de erro.

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

[\<regex>](../standard-library/regex.md)<br/>
[Classe regex_constants](../standard-library/regex-constants-class.md)<br/>
[\<Funções regex>](../standard-library/regex-functions.md)<br/>
[Classe regex_iterator](../standard-library/regex-iterator-class.md)<br/>
[\<Operadores regex>](../standard-library/regex-operators.md)<br/>
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)<br/>
[Classe regex_traits](../standard-library/regex-traits-class.md)<br/>
[\<Typedef regex>](../standard-library/regex-typedefs.md)<br/>
