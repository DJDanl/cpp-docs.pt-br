---
title: Literais numéricos, Boolianos e de ponteiro (C++)
description: Os formatos de linguagem padrão do C++ para inteiros, ponto flutuante, booliano e literais de ponteiro.
ms.date: 11/04/2016
helpviewer_keywords:
- literals, C++
- constants, literals
- literals [C++]
ms.assetid: 17c09fc3-3ad7-47e2-8b48-ba8ae994edc8
ms.openlocfilehash: def223682b58f3d0c8bd3dd88f6d54fc5aa8b8a4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87186445"
---
# <a name="numeric-boolean-and-pointer-literals"></a>Literais de ponteiro, numéricos e boolianos

Um literal é um elemento de programa que representa diretamente um valor. Este artigo aborda literais do tipo inteiro, ponto flutuante, booliano e ponteiro. Para obter informações sobre cadeias de caracteres e literais de caracteres, consulte [cadeias de caracteres e literais de caracteres (C++)](../cpp/string-and-character-literals-cpp.md). Você também pode definir seus próprios literais com base em qualquer uma dessas categorias. Para obter mais informações, consulte [literais definidos pelo usuário (C++)](../cpp/user-defined-literals-cpp.md)

. Você pode usar literais em muitos contextos, mas mais comumente para inicializar variáveis nomeadas e para passar argumentos para funções:

```cpp
const int answer = 42;      // integer literal
double d = sin(108.87);     // floating point literal passed to sin function
bool b = true;              // boolean literal
MyClass* mc = nullptr;      // pointer literal
```

Às vezes, é importante dizer ao compilador como interpretar um literal ou qual tipo específico fornecer a ele. Isso é feito acrescentando prefixos ou sufixos ao literal. Por exemplo, o prefixo `0x` informa ao compilador para interpretar o número que o segue como um valor hexadecimal, por exemplo `0x35` . O `ULL` sufixo informa ao compilador para tratar o valor como um **`unsigned long long`** tipo, como em `5894345ULL` . Consulte as seções a seguir para obter a lista completa de prefixos e sufixos para cada tipo literal.

## <a name="integer-literals"></a>Literais inteiros

Os literais inteiros começam com um dígito e não têm partes fracionais ou expoentes. Você pode especificar literais inteiros em formato decimal, octal ou hexadecimal. Você pode especificar tipos assinados ou sem sinal e tipos longos ou curtos.

Quando nenhum prefixo ou sufixo estiver presente, o compilador fornecerá um tipo de valor literal inteiro **`int`** (32 bits), se o valor couber, caso contrário ele fornecerá o tipo **`long long`** (64 bits).

Para especificar um literal inteiro decimal, comece a especificação com um dígito diferente de zero. Por exemplo:

```cpp
int i = 157;        // Decimal literal
int j = 0198;       // Not a decimal number; erroneous octal literal
int k = 0365;       // Leading zero specifies octal literal, not decimal
int m = 36'000'000  // digit separators make large values more readable
```

Para especificar um literal inteiro octal, inicie a especificação com 0, seguido por uma sequência de dígitos no intervalo de 0 a 7. Os dígitos 8 e 9 são erros na especificação de um literal octal. Por exemplo:

```cpp
int i = 0377;   // Octal literal
int j = 0397;   // Error: 9 is not an octal digit
```

Para especificar um literal integral hexadecimal, comece a especificação com `0x` or `0X` (o caso do "x" não importa), seguido por uma sequência de dígitos no intervalo `0` até `9` e `a` (ou `A` ) por meio de `f` (ou `F` ). Os dígitos hexadecimais de `a` (ou `A`) a `f` (ou `F`) representam valores no intervalo de 10 a 15. Por exemplo:

```cpp
int i = 0x3fff;   // Hexadecimal literal
int j = 0X3FFF;   // Equal to i
```

Para especificar um tipo não assinado, use o `u` `U` sufixo ou. Para especificar um tipo longo, use o `l` sufixo ou `L` . Para especificar um tipo integral de 64 bits, use o sufixo LL ou ll. O sufixo i64 ainda tem suporte, mas não é recomendável. É específico da Microsoft e não é portátil. Por exemplo:

```cpp
unsigned val_1 = 328u;                  // Unsigned value
long val_2 = 0x7FFFFFL;                 // Long value specified
                                        //  as hex literal
unsigned long val_3 = 0776745ul;        // Unsigned long value
auto val_4 = 108LL;                           // signed long long
auto val_4 = 0x8000000000000000ULL << 16;     // unsigned long long
```

**Separadores de dígitos**: você pode usar o caractere de aspas simples (apóstrofo) para separar valores de local em números maiores para facilitar a leitura dos seres humanos. Os separadores não têm nenhum efeito na compilação.

```cpp
long long i = 24'847'458'121
```

## <a name="floating-point-literals"></a>Literais de ponto flutuante

Os literais de ponto flutuante especificam valores que devem ter uma parte fracionária. Esses valores contêm pontos decimais ( **`.`** ) e podem conter expoentes.

Os literais de ponto flutuante têm um *significante* (às vezes chamado de *mantissa*), que especifica o valor do número. Eles têm um *expoente*, que especifica a magnitude do número. E eles têm um sufixo opcional que especifica o tipo do literal. O significante é especificado como uma sequência de dígitos seguida por um ponto, seguido por uma sequência opcional de dígitos que representa a parte fracionária do número. Por exemplo:

```cpp
18.46
38.
```

O expoente, se presente, especifica a magnitude do número como uma potência de 10, como mostrado no seguinte exemplo:

```cpp
18.46e0      // 18.46
18.46e1      // 184.6
```

O expoente pode ser especificado usando `e` ou `E` , que têm o mesmo significado, seguido por um sinal opcional (+ ou-) e uma sequência de dígitos.  Se um expoente estiver presente, o ponto decimal à direita é desnecessário em números inteiros como `18E0`.

Os literais de ponto flutuante assumem como padrão o tipo **`double`** . Usando os sufixos `f` ou `l` or `F` ou `L` (o sufixo não diferencia maiúsculas de minúsculas), o literal pode ser especificado como **`float`** ou **`long double`** .

Embora **`long double`** e **`double`** tenham a mesma representação, elas não são do mesmo tipo. Por exemplo, você pode ter funções sobrecarregadas, como

```cpp
void func( double );
```

e

```cpp
void func( long double );
```

## <a name="boolean-literals"></a>Literais boolianos

Os literais boolianos são **`true`** e **`false`** .

## <a name="pointer-literal-c11"></a>Literal de ponteiro (C++ 11)

O C++ apresenta o [`nullptr`](../cpp/nullptr.md) literal para especificar um ponteiro inicializado com zero. No código portátil, **`nullptr`** deve ser usado em vez de zero de tipo integral ou macros como `NULL` .

## <a name="binary-literals-c14"></a>Literais binárias (C++ 14)

Um literal binário pode ser especificado pelo uso do `0B` `0b` prefixo ou, seguido por uma sequência de 1 e 0:

```cpp
auto x = 0B001101 ; // int
auto y = 0b000001 ; // int
```

## <a name="avoid-using-literals-as-magic-constants"></a>Evite usar literais como "constantes mágicas"

Você pode usar literais diretamente em expressões e instruções, embora não seja sempre boa prática de programação:

```cpp
if (num < 100)
    return "Success";
```

No exemplo anterior, uma prática melhor é usar uma constante nomeada que transmita um significado claro, por exemplo "MAXIMUM_ERROR_THRESHOLD". E se o valor de retorno "success" for visto pelos usuários finais, poderá ser melhor usar uma constante de cadeia de caracteres nomeada. Você pode manter constantes de cadeia de caracteres em um único local em um arquivo que pode ser localizado em outros idiomas. O uso de constantes nomeadas ajuda você mesmo e outras pessoas a entender a intenção do código.

## <a name="see-also"></a>Confira também

[Convenções lexicais](../cpp/lexical-conventions.md)<br/>
[Literais de cadeia de caracteres C++](../cpp/string-and-character-literals-cpp.md)<br/>
[Literais definidos pelo usuário do C++](../cpp/user-defined-literals-cpp.md)
