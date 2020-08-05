---
title: '&lt;&gt;funções charconv'
ms.date: 07/22/2020
f1_keywords:
- charconv/std::to_chars
- charconv/std::from_chars
helpviewer_keywords:
- std::charconv [C++], to_chars
- std::charconv [C++], from_chars
ms.openlocfilehash: 92f838ededad3e2b8493e934ae2b614247f18458
ms.sourcegitcommit: 4eda68a0b3c23d8cefa56b7ba11583412459b32f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/04/2020
ms.locfileid: "87565943"
---
# <a name="ltcharconvgt-functions"></a>&lt;&gt;funções charconv

O \<charconv> cabeçalho inclui as seguintes funções não-membro:

| **Funções não membro** | **Descrição** |
|-|-|
|[to_chars](#to_chars) | Converta um valor inteiro ou de ponto flutuante em uma sequência de **`char`** . |
|[from_chars](#from_chars) | Converta uma sequência de **`char`** em um valor inteiro ou de ponto flutuante. |

Essas funções de conversão são ajustadas para desempenho e também oferecem suporte ao comportamento de viagem de ida e volta mais curto. O comportamento de viagem de ida e volta mais curto significa que quando um número é convertido em caracteres, apenas precisão suficiente é gravada para habilitar a recuperação do número original ao converter esses caracteres de volta em um ponto flutuante.

- Ao converter caracteres em um número, o valor numérico não precisa ser encerrado em nulo. Da mesma forma, ao converter um número em caracteres, o resultado não é terminado em nulo.
- As funções de conversão não alocam memória. Você possui o buffer em todos os casos.
- As funções de conversão não são lançadas. Um resultado é retornado do qual você pode determinar se a conversão foi bem-sucedida.
- As funções de conversão não são confidenciais no modo de arredondamento de tempo de execução.
- As funções de conversão não têm reconhecimento de localidade. Eles sempre imprimem e analisam pontos decimais como `'.'` , e nunca como ', ' para localidades que usam vírgulas.

## `to_chars`

Converta um valor inteiro ou de ponto flutuante em uma sequência de **`char`** .

Converte `value` em uma cadeia de caracteres preenchendo o intervalo \[ `first` , `last` ), onde \[ `first` , `last` ) deve ser um intervalo válido.
Retorna uma [estrutura de to_chars_result](to-chars-result-structure.md). Se a conversão for bem-sucedida, conforme indicado pelo `to_char_result.ec` , o membro `ptr` será o ponteiro de uma extremidade passada dos caracteres gravados. Caso contrário, `to_char_result.ec` tem o valor, `errc::value_too_large` `to_char_result.ptr` tem o valor `last` e o conteúdo do intervalo \[ `first` , `last` ) não são especificados.

A única maneira de `to_chars` falha se você fornecer um buffer insuficientemente grande para manter o resultado.

```cpp
// integer to chars

to_chars_result to_chars(char* first, char* last, char value, int base = 10);
to_chars_result to_chars(char* first, char* last, signed char value, int base = 10);
to_chars_result to_chars(char* first, char* last, unsigned char value, int base = 10);
to_chars_result to_chars(char* first, char* last, short value, int base = 10);
to_chars_result to_chars(char* first, char* last, unsigned short value, int base = 10);
to_chars_result to_chars(char* first, char* last, int value, int base = 10);
to_chars_result to_chars(char* first, char* last, unsigned int value, int base = 10);
to_chars_result to_chars(char* first, char* last, long value, int base = 10);
to_chars_result to_chars(char* first, char* last, unsigned long value, int base = 10);
to_chars_result to_chars(char* first, char* last, long long value, int base = 10);
to_chars_result to_chars(char* first, char* last, unsigned long long value, int base = 10);
to_chars_result to_chars(char* first, char* last, bool value, int base = 10) = delete;

// floating-point to chars

to_chars_result to_chars(char* first, char* last, float value);
to_chars_result to_chars(char* first, char* last, double value);
to_chars_result to_chars(char* first, char* last, long double value);
to_chars_result to_chars(char* first, char* last, float value, chars_format fmt);
to_chars_result to_chars(char* first, char* last, double value, chars_format fmt);
to_chars_result to_chars(char* first, char* last, long double value, chars_format fmt);
to_chars_result to_chars(char* first, char* last, float value, chars_format fmt, int precision);
to_chars_result to_chars(char* first, char* last, double value, chars_format fmt, int precision);
to_chars_result to_chars(char* first, char* last, long double value, chars_format fmt, int precision);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Aponta para o início do buffer a ser preenchido.

*última*\
Aponta um caractere após o final do buffer para preencher.

*valor*\
O valor a ser convertido. Se `value` for negativo, a representação começará com `-` .

*polybase*\
Para conversões de inteiros, a base a ser usada ao converter `value` em caracteres. Deve estar entre 2 e 36, inclusive. Não haverá zeros à esquerda. Os dígitos no intervalo de 10.35 (inclusivo) são representados como caracteres minúsculos a.. z

*fmt*\
Para conversões de ponto flutuante, um bitmask que especifica o formato de conversão a ser usado, como científico, Fixed ou hexadecimal. Consulte [chars_format](chars-format-class.md) para obter detalhes.

*Preciso*\
Para conversões de ponto flutuante, o número de dígitos de precisão para o valor convertido.

### <a name="return-value"></a>Valor retornado

Uma [to_chars_result](to-chars-result-structure.md) que contém o resultado da conversão.

### <a name="remarks"></a>Comentários

As funções que tomam um parâmetro [chars_format](chars-format-class.md) determinam o especificador de conversão como se estivessem usando da `printf()` seguinte maneira: o especificador de conversão é se for, `'f'` `fmt` `chars_format::fixed` `'e'` `fmt` `chars_format::scientific` `'a'` (sem a entrelinha do `0x` resultado) se `fmt` for e `chars_format::hex` `'g'` se `fmt` for `chars_format::general` . A especificação da notação fixa mais curta ainda pode resultar em uma saída longa porque pode ser a representação mais curta possível quando o valor é muito grande ou muito pequeno.

A tabela a seguir descreve o comportamento de conversão dadas diferentes combinações de `fmt` `precision` parâmetros e. O termo "comportamento de viagem de ida e volta mais curto" refere-se à gravação do menor número de dígitos necessários, de modo que a análise dessa representação usando a `from_chars` função correspondente irá recuperar o valor exatamente.

| `fmt`e a `precision` combinação | Saída |
|--|--|
|  Nenhum | O que for uma notação fixa ou científica é menor, preferindo-se fixo como um desempate.</br>Esse comportamento não pode ser simulado por qualquer sobrecarga que usa o `fmt` parâmetro. |
| `fmt` | O comportamento de viagem de ida e volta mais curto para o formato especificado, como o formato científico mais curto. |
| `fmt` e `precision` | Usa a precisão fornecida, seguindo o estilo, sem o comportamento de viagem de ida e volta `printf()` mais curto. |

### <a name="return-value"></a>Valor retornado

Um [to_chars_result](to-chars-result-structure.md) que contém o resultado da conversão.

### <a name="example"></a>Exemplo

```cpp
#include <charconv>
#include <stdio.h>
#include <system_error>

template <typename T> void TestToChars(const T t)
{
    static_assert(std::is_floating_point_v<T>);
    constexpr bool IsFloat = std::is_same_v<T, float>;

    char buf[100]; // 100 is large enough for double and long double values because the longest possible outputs are "-1.23456735e-36" and "-1.2345678901234567e-100".
    constexpr size_t size = IsFloat ? 15 : 24;
    const std::to_chars_result res = std::to_chars(buf, buf + size, t);  // points to buffer area it can use. Must be char, not wchar_t, etc.
    
    if (res.ec == std::errc{}) // no error
    {
        // %.*s provides the exact number of characters to output because the output range, [buf, res.ptr), isn't null-terminated
        printf("success: %.*s\n", static_cast<int>(res.ptr - buf), buf);
    }
    else // probably std::errc::value_too_large
    {
        printf("Error: %d\n", static_cast<int>(res.ec));
    }
}

int main()
{
    TestToChars(123.34);
    return 0;
}
```

## `from_chars`

Converta uma sequência de **`char`** em um valor inteiro ou de ponto flutuante.

```cpp
// char to an integer value

from_chars_result from_chars(const char* first, const char* last, char& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, signed char& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, unsigned char& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, short& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, unsigned short& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, int& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, unsigned int& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, long& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, unsigned long& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, long long& value, int base = 10);
from_chars_result from_chars(const char* first, const char* last, unsigned long long& value, int base = 10);

// char to a floating-point value

from_chars_result from_chars(const char* first, const char* last, float& value, chars_format fmt = chars_format::general);
from_chars_result from_chars(const char* first, const char* last, double& value, chars_format fmt = chars_format::general);
from_chars_result from_chars(const char* first, const char* last, long double& value, chars_format fmt = chars_format::general);
```

### <a name="parameters"></a>Parâmetros

*primeiro*\
Aponta para o início do buffer de caracteres a serem convertidos.

*última*\
Aponta um para o elemento final do buffer de caracteres a ser convertido.

*valor*\
Se a conversão for bem-sucedida, conterá o resultado da conversão.

*polybase*\
Para conversões de inteiros, a base a ser usada durante a conversão. Deve estar entre 2 e 36, inclusive.

*fmt*\
Para conversões de ponto flutuante, o formato da sequência de caracteres que está sendo convertido. Consulte [chars_format](chars-format-class.md) para obter detalhes.

### <a name="remarks"></a>Comentários

As `from_chars()` funções analisam a cadeia de caracteres \[ `first` , `last` ) para um padrão de número, onde \[ `first` , `last` ) é necessário para ser um intervalo válido.

Ao analisar caracteres, o espaço em branco não é ignorado. Ao contrário de `strtod()` , por exemplo, o buffer deve começar com uma representação numérica válida.

Retorna uma [estrutura de from_chars_result](from-chars-result-structure.md).

Se nenhum caractere corresponder a um padrão numérico, o não `value` será modificado, `from_chars_result.ptr` apontará para `first` e `from_chars_result.ec` será `errc::invalid_argument` .

Se apenas alguns caracteres corresponderem a um padrão numérico, `from_chars_result.ptr` o apontará para o primeiro caractere que não corresponde ao padrão ou terá o valor do `last` parâmetro se todos os caracteres forem correspondentes.

Se o valor analisado não estiver no intervalo representável pelo tipo de, o `value` `value` não será modificado e `from_chars_result.ec` será `errc::result_out_of_range` .

Caso contrário, `value` é definido como o valor analisado, após o arredondamento e `from_chars_result.ec` é igual a `errc{}` .

### <a name="example"></a>Exemplo

```cpp
#include <charconv>
#include <stdio.h>
#include <string_view>
#include <system_error>

double TestFromChars(const std::string_view sv)
{
    const char* const first = sv.data();
    const char* const last = first + sv.size();
    double dbl;

    const std::from_chars_result res = std::from_chars(first, last, dbl);

    if (res.ec == std::errc{}) // no error
    {
        printf("success: %g\n", dbl);
    }
    else
    {
        printf("Error: %d\n", static_cast<int>(res.ec));
    }

    return dbl;
}

int main()
{
    double dbl = TestFromChars("123.34");
    return 0;
}
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

/std: c++ 17 ou posterior, é necessário.

## <a name="see-also"></a>Confira também

[\<charconv>](charconv.md)  
[A cadeia de caracteres decimal mais curta que as viagens](https://www.exploringbinary.com/the-shortest-decimal-string-that-round-trips-examples/) 
 de ida e volta [especificadores de formato printf ()](..\c-runtime-library\format-specification-syntax-printf-and-wprintf-functions.md)