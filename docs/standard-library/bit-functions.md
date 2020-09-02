---
title: '&lt;funções de bit &gt;'
description: Funções para acessar, manipular e processar bits individuais e sequências de bits
ms.date: 08/28/2020
f1_keywords:
- bit/std::bit_cast
- bit/std::has_single_bit
- bit/std::bit_ceil
- bit/std::bit_floor
- bit/std::bit_width
- bit/std::rotl
- bit/std::rotr
- bit/std::countl_zero
- bit/std::countl_one
- bit/std::countr_zero
- bit/std::countr_one
- bit/std::popcount
helpviewer_keywords:
- std::bit [C++], bit_cast
- std::bit [C++], has_single_bit
- std::bit [C++], bit_ceil
- std::bit [C++], bit_floor
- std::bit [C++], bit_width
- std::bit [C++], rotl
- std::bit [C++], rotr
- std::bit [C++], countl_zero
- std::bit [C++], countl_one
- std::bit [C++], countr_zero
- std::bit [C++], countr_one
- std::bit [C++], popcount
ms.openlocfilehash: f06e181a4fe6683adb0cc63c016cbd879f2fc574
ms.sourcegitcommit: e58918c45316d799c1952ca7797a85adbcd0c472
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/01/2020
ms.locfileid: "89281803"
---
# <a name="ltbitgt-functions"></a>&lt;funções de bit &gt;

O \<bit> cabeçalho inclui as seguintes funções de modelo que não são de membro:

| **Funções não membro** | **Descrição** |
|--------|---------|
|[bit_cast](#bit_cast) | Reinterprete a representação de objeto de um tipo para outro. |
|[bit_ceil](#bit_ceil) | Localize a menor potência de dois maiores ou iguais a um valor. |
|[bit_floor](#bit_floor) | Localize a maior potência de dois que não seja maior que um valor. |
|[bit_width](#bit_width) | Localize o menor número de bits necessários para representar um valor. |
|[countl_zero](#countl_zero) | Conte o número de bits consecutivos definidos como zero, começando do bit mais significativo. |
|[countl_one](#countl_one) | Conte o número de bits consecutivos definidos como um, começando do bit mais significativo. |
|[countr_zero](#countr_zero) | Conte o número de bits consecutivos definidos como zero, começando do bit menos significativo. |
|[countr_one](#countl_one) | Conte o número de bits consecutivos definidos como um, começando do bit menos significativo. |
|[has_single_bit](#has_single_bit) | Verifique se um valor tem apenas um conjunto de bits único como um. Isso é o mesmo que testar se um valor é uma potência de dois. |
|[popcount](#popcount) | Conte o número de bits definidos como um. |
|[rotl](#rotl) | Computar o resultado de uma rotação de uma para a esquerda. |
|[rotr](#rotr) | Computar o resultado de uma rotação do lado a bit. |

## <a name="bit_cast"></a>`bit_cast`

Copiar um padrão de bit de um objeto do tipo `From` para um novo objeto do tipo `To` .

```cpp
template <class To, class From>
[[nodiscard]] constexpr To bit_cast(const From& from) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Para*\
O tipo da saída.

*De*\
O tipo do valor para converter.

*De*\
O valor a ser convertido.

### <a name="return-value"></a>Valor retornado

Um objeto do tipo `To`.

Cada bit no resultado corresponde ao bit correspondente em, `from` a menos que haja bits de preenchimento em `To` , nesse caso, os bits no resultado não são especificados.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <iostream>

int main()
{
    float f = std::numeric_limits<float>::infinity();
    int i = std::bit_cast<int>(f);
    std::cout << "float f = " << std::hex << f
              << "\nstd::bit_cat<int>(f) = " << std::hex << i << '\n';
    return 0;
}
```

```Output
float f = inf
std::bit_cat<int>(f) = 7f800000
```

### <a name="remarks"></a>Comentários

Geralmente, o código de nível baixo precisa interpretar um objeto de um tipo como outro tipo. O objeto reinterpretad tem a mesma representação de bit que o original, mas é um tipo diferente.

Em vez de usar `reinterpret_cast` o, ou `memcpy()` , `bit_cast()` é uma maneira melhor de fazer essas conversões. É melhor porque:
- `bit_cast()` é `constexpr`
- `bit_cast()` exige que os tipos sejam de fácil cópia e do mesmo tamanho. Isso evita possíveis problemas que você pode encontrar usando `reinterpret_cast` e `memcpy` porque eles podem ser usados para inadvertidamente e incorretamente converter tipos não triviais. Além disso, `memcpy()` pode ser usado para copiar inadvertidamente entre tipos que não têm o mesmo tamanho. Por exemplo, um Double (8 bytes) em um int não assinado (4 bytes) ou o contrário.

Essa sobrecarga só participará da resolução de sobrecarga se:
-  `sizeof(To) == sizeof(From)`
- `To` e `From` são [is_trivially_copyable](https://docs.microsoft.com/cpp/standard-library/is-trivially-copyable-class?view=vs-2019`).

Esse modelo de função é `constexpr` se e somente se `To` , e `From` os tipos de seus subobjetos forem:
- Não é um tipo de União ou ponteiro
- Não é um ponteiro para tipo de membro
- Não é qualificado por volátil
- Não há nenhum membro de dados não estático que seja um tipo de referência

## <a name="bit_ceil"></a>`bit_ceil`

Localize a menor potência de dois maiores ou iguais a um valor. Por exemplo, fornecido `3` , retorna `4` .

```cpp
template<class T>
[[nodiscard]] constexpr T bit_ceil(T value);
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

 A menor potência de dois maiores que ou igual a `value` .

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    for (auto i = 0u; i < 6u; ++i) // bit_ceil() takes an unsigned integer type
    {
        auto nextClosestPowerOf2 = std::bit_ceil(i);
        std::cout << "\nbit_ceil(0b" << std::bitset<4>(i) << ") = "
                  << "0b" << std::bitset<4>(nextClosestPowerOf2);
    }
    return 0;
}
```

```Output
bit_ceil(0b0000) = 0b0001
bit_ceil(0b0001) = 0b0001
bit_ceil(0b0010) = 0b0010
bit_ceil(0b0011) = 0b0100
bit_ceil(0b0100) = 0b0100
bit_ceil(0b0101) = 0b1000
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="bit_floor"></a>`bit_floor`

Localize a maior potência de dois que não seja maior que um valor. Por exemplo, fornecido `5` , retorna `4` .

```cpp
template< class T >
[[nodiscard]] constexpr T bit_floor(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

A maior potência de dois que não é maior que `value` . \
Se `value` for zero, retornará zero.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    for (auto i = 0u; i < 6u; ++i) // bit_floor() takes an unsigned integer type
    {
        auto previousPowerOf2 = std::bit_floor(i);
        std::cout << "\nbit_floor(0b" << std::bitset<4>(i) << ") = 0b"
                  << std::bitset<4>(previousPowerOf2);
    }
    return 0;
}
```

```Output
bit_floor(0b0000) = 0b0000
bit_floor(0b0001) = 0b0001
bit_floor(0b0010) = 0b0010
bit_floor(0b0011) = 0b0010
bit_floor(0b0100) = 0b0100
bit_floor(0b0101) = 0b0100
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="bit_width"></a>`bit_width`

Localize o menor número de bits necessários para representar um valor.

Por exemplo, dado 5 (0b101), retorna 3 porque leva 3 bits binários para expressar o valor 5.

```cpp
template<class T>
[[nodiscard]] constexpr T bit_width(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits necessários para representar `value` . \
Se `value` for zero, retornará zero.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <iostream>

int main()
{
    for (unsigned i=0u; i <= 8u; ++i)
    {
        std::cout << "\nbit_width(" << i << ") = "
                  << std::bit_width(i);
    }
    return 0;
}
```

```Output
bit_width(0) = 0
bit_width(1) = 1
bit_width(2) = 2
bit_width(3) = 2
bit_width(4) = 3
bit_width(5) = 3
bit_width(6) = 3
bit_width(7) = 3
bit_width(8) = 4
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="countl_zero"></a>`countl_zero`

Conte o número de bits consecutivos definidos como zero, começando do bit mais significativo.

```cpp
template<class T>
[[nodiscard]] constexpr int countl_zero(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits zero consecutivos, começando do bit mais significativo. \
Se `value` for zero, o número de bits no tipo de `value` .

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    for (unsigned char result = 0, i = 0; i < 9; i++)
    {
        std::cout << "\ncountl_zero(0b" << std::bitset<8>(result) << ") = " << std::countl_zero(result);
        result = result == 0 ? 1 : result * 2;
    }
    return 0;
}
```

```Output
countl_zero(0b00000000) = 8
countl_zero(0b00000001) = 7
countl_zero(0b00000010) = 6
countl_zero(0b00000100) = 5
countl_zero(0b00001000) = 4
countl_zero(0b00010000) = 3
countl_zero(0b00100000) = 2
countl_zero(0b01000000) = 1
countl_zero(0b10000000) = 0
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="countl_one"></a>`countl_one`

Conte o número de bits consecutivos definidos como um, começando do bit mais significativo.

```cpp
template<class T>
[[nodiscard]] constexpr int countl_one(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits consecutivos definidos como um, começando do bit mais significativo.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    unsigned char value = 0;
    for (unsigned char bit = 128; bit > 0; bit /= 2)
    {
        value |= bit;
        std::cout << "\ncountl_one(0b" << std::bitset<8>(value) << ") = "
                  << std::countl_one(value);
    }
    return 0;
}
```

```Output
countl_one(0b10000000) = 1
countl_one(0b11000000) = 2
countl_one(0b11100000) = 3
countl_one(0b11110000) = 4
countl_one(0b11111000) = 5
countl_one(0b11111100) = 6
countl_one(0b11111110) = 7
countl_one(0b11111111) = 8
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="countr_zero"></a>`countr_zero`

Conte o número de bits consecutivos definidos como zero, começando do bit menos significativo.

```cpp
template<class T>
[[nodiscard]] constexpr int countr_zero(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits zero consecutivos, começando do bit menos significativo. \
Se `value` for zero, o número de bits no tipo de `value` .

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    for (unsigned char result = 0, i = 0; i < 9; i++)
    {
        std::cout << "\ncountr_zero(0b" << std::bitset<8>(result) << ") = "
                  << std::countr_zero(result);
        result = result == 0 ? 1 : result * 2;
    }
    return 0;
}
```

```Output
countr_zero(0b00000000) = 8
countr_zero(0b00000001) = 0
countr_zero(0b00000010) = 1
countr_zero(0b00000100) = 2
countr_zero(0b00001000) = 3
countr_zero(0b00010000) = 4
countr_zero(0b00100000) = 5
countr_zero(0b01000000) = 6
countr_zero(0b10000000) = 7
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="countr_one"></a>`countr_one`

Conte o número de bits consecutivos definidos como um, começando do bit menos significativo.

```cpp
template<class T>
[[nodiscard]] constexpr int countr_one(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits consecutivos definidos como um, começando do bit menos significativo.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    unsigned char value = 0;
    for (int bit = 1; bit <= 128; bit *= 2)
    {
        value |= bit;
        std::cout << "\ncountr_one(0b" << std::bitset<8>(value) << ") = "
                  << std::countr_one(value);
    }
    return 0;
}
```

```Output
countr_one(0b00000001) = 1
countr_one(0b00000011) = 2
countr_one(0b00000111) = 3
countr_one(0b00001111) = 4
countr_one(0b00011111) = 5
countr_one(0b00111111) = 6
countr_one(0b01111111) = 7
countr_one(0b11111111) = 8
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="has_single_bit"></a>`has_single_bit`

Verifique se um valor tem apenas um conjunto de bits. Isso é o mesmo que testar se um valor é uma potência de dois.
 
```cpp
template <class T>
[[nodiscard]] constexpr bool has_single_bit(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

`true` Se `value` tiver apenas um conjunto de bits que também significa que `value` é uma potência de dois. Caso contrário, `false`.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>
#include <iomanip>

int main()
{
    for (auto i = 0u; i < 10u; ++i)
    {
        std::cout << "has_single_bit(0b" << std::bitset<4>(i) << ") = "
                  << std::boolalpha << std::has_single_bit(i) << '\n';
    }
    return 0;
}
```

```Output
has_single_bit(0b0000) = false
has_single_bit(0b0001) = true
has_single_bit(0b0010) = true
has_single_bit(0b0011) = false
has_single_bit(0b0100) = true
has_single_bit(0b0101) = false
has_single_bit(0b0110) = false
has_single_bit(0b0111) = false
has_single_bit(0b1000) = true
has_single_bit(0b1001) = false
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="popcount"></a>`popcount`

Conte o número de bits definidos como um em um valor inteiro sem sinal.
 
```cpp
template<class T>
[[nodiscard]] constexpr int popcount(T value) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser testado.

### <a name="return-value"></a>Valor retornado

O número de bits definido como um em `value` .

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
   for (unsigned char value = 0; value < 16; value++)
    {
        std::cout << "\npopcount(0b" << std::bitset<4>(value) << ") = "
                  << std::popcount(value);
    }
    return 0;
}
```

```Output
popcount(0b0000) = 0
popcount(0b0001) = 1
popcount(0b0010) = 1
popcount(0b0011) = 2
popcount(0b0100) = 1
popcount(0b0101) = 2
popcount(0b0110) = 2
popcount(0b0111) = 3
popcount(0b1000) = 1
popcount(0b1001) = 2
popcount(0b1010) = 2
popcount(0b1011) = 3
popcount(0b1100) = 2
popcount(0b1101) = 3
popcount(0b1110) = 3
popcount(0b1111) = 4
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="rotl"></a>`rotl`

Gira os bits de um valor inteiro sem sinal deixado o número especificado de vezes. Bits que "caem" do bit mais à esquerda são girados para o bit mais à direita.
 
```cpp
template<class T>
[[nodiscard]] constexpr T rotl(T value, int s) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser girado.

*&*\
O número de rotações à esquerda a serem executadas.

### <a name="return-value"></a>Valor retornado

O resultado da rotação `value` à esquerda, `s` horas. \
Se `s` for zero, retornará `value` . \
Se `s` for negativo, o fará `rotr(value, -s)` . Bits que "caem" do bit mais à direita são girados para o bit mais à esquerda.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    unsigned char bits = 1;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "rotl(0b" << std::bitset<8>(bits) << ", 1) = ";
        bits = std::rotl(bits, 1);
        std::cout << "0b" << std::bitset<8>(bits) << '\n';
    }
    std::cout << "rotl(0b" << std::bitset<8>(bits) << ",-1) = ";
    bits = std::rotl(bits, -1);
    std::cout << "0b" << std::bitset<8>(bits);
    return 0;
}
```

```Output
rotl(0b00000001, 1) = 0b00000010
rotl(0b00000010, 1) = 0b00000100
rotl(0b00000100, 1) = 0b00001000
rotl(0b00001000, 1) = 0b00010000
rotl(0b00010000, 1) = 0b00100000
rotl(0b00100000, 1) = 0b01000000
rotl(0b01000000, 1) = 0b10000000
rotl(0b10000000, 1) = 0b00000001
rotl(0b00000001,-1) = 0b10000000
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="rotr"></a>`rotr`

Gira os bits da `value` direita do número de vezes especificado. Bits que "caem" do bit mais à direita são girados de volta para o bit mais à esquerda.
 
```cpp
template<class T>
[[nodiscard]] constexpr T rotr(T value, int s) noexcept;
```

### <a name="parameters"></a>Parâmetros

*valor*\
O valor inteiro sem sinal a ser girado.

*&*\
O número de rotações à direita a serem executadas.

### <a name="return-value"></a>Valor retornado

O resultado da rotação `value` direita, `s` vezes. \
Se `s` for zero, retornará `value` . \
Se `s` for negativo, o fará `rotl(value, -s)` . Bits que "caem" do bit mais à esquerda são girados de volta para o bit mais à direita.

### <a name="example"></a>Exemplo

```cpp
#include <bit>
#include <bitset>
#include <iostream>

int main()
{
    unsigned char bits = 128;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "rotr(0b" << std::bitset<8>(bits) << ", 1) = ";
        bits = std::rotr(bits, 1);
        std::cout << "0b" << std::bitset<8>(bits) << '\n';
    }
    std::cout << "rotr(0b" << std::bitset<8>(bits) << ",-1) = ";
    bits = std::rotr(bits, -1);
    std::cout << "0b" << std::bitset<8>(bits);
    return 0;
}
```

```Output
rotr(0b10000000, 1) = 0b01000000
rotr(0b01000000, 1) = 0b00100000
rotr(0b00100000, 1) = 0b00010000
rotr(0b00010000, 1) = 0b00001000
rotr(0b00001000, 1) = 0b00000100
rotr(0b00000100, 1) = 0b00000010
rotr(0b00000010, 1) = 0b00000001
rotr(0b00000001, 1) = 0b10000000
rotr(0b10000000,-1) = 0b00000001
```

### <a name="remarks"></a>Comentários

Esta função de modelo só participará da resolução de sobrecarga se `T` for um tipo de inteiro sem sinal. Por exemplo: `unsigned int` , `unsigned long` , `unsigned short` , `unsigned char` e assim por diante.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<bit>

**Namespace:** std

`/std:c++latest` é necessário

## <a name="see-also"></a>Confira também

[\<bit>](bit.md)