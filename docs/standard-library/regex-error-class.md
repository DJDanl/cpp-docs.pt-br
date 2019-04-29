---
title: Classe regex_error
ms.date: 09/10/2018
f1_keywords:
- regex/std::regex_error
- regex/std::regex_error::code
helpviewer_keywords:
- regex_error class
ms.assetid: 3333a1a3-ca6f-4612-84b2-1b4c7e3db5a4
ms.openlocfilehash: eed961ea698591935c22fc748ff79583ae636b27
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62369612"
---
# <a name="regexerror-class"></a>Classe regex_error

Relata um objeto basic_regex incorreto.

## <a name="syntax"></a>Sintaxe

```cpp
class regex_error
: public std::runtime_error
```

## <a name="remarks"></a>Comentários

A classe descreve um objeto de exceção gerado para relatar um erro na construção ou uso de um objeto `basic_regex`.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[regex_error](#regex_error)|Constrói o objeto.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[code](#code)|Retorna o código de erro.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="example"></a>Exemplo

```cpp
// std__regex__regex_error.cpp
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
            << (rerr.code() == paren.code() ? "unbalanced parentheses" : "")
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

## <a name="code"></a>  regex_error::code

Retorna o código de erro.

```cpp
regex_constants::error_code code() const;
```

### <a name="remarks"></a>Comentários

A função membro retorna o valor que foi passado para o construtor do objeto.

## <a name="regex_error"></a>  regex_error::regex_error

Constrói o objeto.

```cpp
regex_error(regex_constants::error_code error);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O código de erro.

### <a name="remarks"></a>Comentários

O construtor constrói um objeto que contém o valor *erro*.

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)<br/>
[Classe regex_constants](../standard-library/regex-constants-class.md)<br/>
[\<Funções regex>](../standard-library/regex-functions.md)<br/>
[Classe regex_iterator](../standard-library/regex-iterator-class.md)<br/>
[\<Operadores regex>](../standard-library/regex-operators.md)<br/>
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)<br/>
[Classe regex_traits](../standard-library/regex-traits-class.md)<br/>
[\<Typedef regex>](../standard-library/regex-typedefs.md)<br/>
