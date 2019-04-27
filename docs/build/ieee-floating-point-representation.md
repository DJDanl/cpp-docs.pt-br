---
title: Representação de ponto flutuante IEEE
ms.date: 11/04/2016
helpviewer_keywords:
- float keyword
- real*8 value
- floating-point numbers, IEEE representation
- double data type, floating-point representation
- IEEE floating point representation
- real*10 value
- long double
- real*4 value
ms.assetid: 537833e8-fe05-49fc-8169-55fd0314b195
ms.openlocfilehash: 69686e7e1c8994b799607eebf7e50387ed688272
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62188828"
---
# <a name="ieee-floating-point-representation"></a>Representação de ponto flutuante IEEE

Microsoft Visual C++ é consistente com os padrões do IEEE numéricos. O padrão IEEE-754 descreve os formatos de ponto flutuantes, uma forma de representar números reais em hardware. Há pelo menos cinco formatos internos para números de ponto flutuante representáveis no hardware direcionada pelo compilador MSVC, mas o compilador usa apenas dois deles. O *precisão simples* (4 bytes) e *precisão dupla* formatos (8 bytes) são usados no Visual C++. Precisão única é declarado usando a palavra-chave **float**. Precisão dupla é declarado usando a palavra-chave **duplas**. Também especifica o padrão IEEE *meia precisão* (2 bytes) e *quádruplo precisão* formatos (16 bytes), bem como um *precisão estendida dupla* (10 bytes) formato, o que alguns compiladores C e C++ implementam como o **longo duplo** tipo de dados. No compilador MSVC, o **longo duplo** tipo de dados é tratado como um tipo distinto, mas o tipo de armazenamento mapeia para **duplo**. Há, no entanto, intrínsecos e suporte de linguagem de assembly para cálculos usando outros formatos, incluindo o formato de (10 bytes) de precisão estendida dupla, onde houver suporte pelo hardware.

Os valores são armazenados da seguinte maneira:

|Valor|Armazenado como|
|-----------|---------------|
|precisão simples|Se o bit, expoente de 8 bits, significando de 23 bits|
|precisão dupla|Se o bit, expoente de 11 bits, significando de 52 bits|
|double-extended-precision|Se o bit, expoente 15 bits, significando de 64 bits|

Em formatos de precisão simples e de precisão dupla, há uma suposta 1 à esquerda da parte fracionária, chamado de *significando* (e às vezes conhecida como o *mantissa*), que é não armazenados em memória, portanto, significands são, na verdade, 24 ou 53 bits, mesmo que apenas 23 ou 52 bits são armazenados. O formato estendido-precisão dupla, na verdade, armazena esse bit.

Os expoentes são deslocados pela metade de seu valor possível. Isso significa que você subtrair esse desvio do expoente armazenado para obter o expoente real. Se o expoente armazenado for menor que o bias, é realmente um expoente negativo.

Os expoentes são mais adequados da seguinte maneira:

|Expoente|Atrelados|
|--------------|---------------|
|8 bits (precisão única)|127|
|11-bit (precisão dupla)|1023|
|15 bits (extended-precisão dupla)|16383|

Esses expoentes não são potências de dez; eles são potências de dois. Ou seja, os expoentes de 8 bits armazenados podem variar de -127 a 127, armazenado como 0 para 254. O valor 2<sup>127</sup> é aproximadamente equivalente a 10<sup>38</sup>, que é o limite real de precisão simples.

O significando é armazenado como uma fração binária do formulário 1.XXX.... Essa fração tem um valor maior que ou igual a 1 e menor que 2. Observe que os números reais são sempre armazenados em *normalizados formulário*; ou seja, o significando é esquerda deslocado, de modo que o bit de ordem superior de significand é sempre 1. Como esse bit é sempre 1, supõe-se (não armazenados) nos formatos de precisão simples e de precisão dupla. O ponto (não decimal) binário é assumido para ser à direita do 1 à esquerda.

O formato, em seguida, para vários tamanhos é da seguinte maneira:

|Formatar|byte 1|byte 2|byte 3|byte 4|...|n bytes|
|------------|------------|------------|------------|------------|---------|------------|
|precisão simples| `SXXXXXXX`|`XMMMMMMM`|`MMMMMMMM`|`MMMMMMMM`|||
|precisão dupla|`SXXXXXXX`|`XXXXMMMM`|`MMMMMMMM`|`MMMMMMMM`|...|`MMMMMMMM`|
|double-extended-precision|`SXXXXXXX`|`XXXXXXXX`|`1MMMMMMM`|`MMMMMMMM`|...|`MMMMMMMM`|

`S` representa o bit de sinal, o `X`do são os bits de expoente polarizados e o `M`do são os bits significando. Observe que o bit mais à esquerda é considerado em formatos de precisão simples e de precisão dupla, mas está presente como "1" no byte 3 do formato estendido-precisão dupla.

Para mudar o ponto binário corretamente, você primeiro unbias o expoente e, em seguida, move o ponto binário para a direita ou à esquerda do número apropriado de bits.

## <a name="special-values"></a>Valores especiais

Os formatos de ponto flutuantes incluem alguns valores que são tratados especialmente.

### <a name="zero"></a>Zero

Zero não pode ser normalizada, o que torna não representável no formato normalizado de um valor de precisão dupla ou de precisão simples. Um padrão de bit especial de todos os zeros representa 0. Também é possível representar - 0 como zero com o sinal de conjunto de bits, mas - 0 e 0 sempre são comparados como iguais.

### <a name="infinities"></a>Infinitos

O + ∞ e −∞ valores são representados por um expoente de todos os índices e usam significandos de todos os zeros. Infinitos positivos e negativos podem ser representados usando o bit de sinal.

### <a name="subnormals"></a>Subnormals

É possível representar números de magnitude menor do que o menor número normalizado. Esses números são conhecidos como *subnormal* ou *desnormalizado* números. Se o expoente é todos os zeros e o significando for diferente de zero, implícita bit à esquerda do significando é considerado como zero, não um. A precisão dos números subnormal fica inativo, como o número de zeros à esquerda em significando sobe.

### <a name="nan---not-a-number"></a>NaN - não é um número

É possível representar os valores que não são um número real, como 0 0, no formato de ponto flutuante IEEE. Um valor desse tipo é chamado um *NaN*. Um NaN é representado por um expoente de todos os índices e usam significandos de diferente de zero. Há dois tipos de NaNs, *silencioso* NaNs ou QNaNs, e *sinalização* NaNs ou SNaNs. NaNs silencioso têm um líder em significando e geralmente são propagadas por meio de uma expressão. Eles representam um valor indeterminado, como o resultado da divisão de infinito ou multiplicar um infinito por zero. NaNs indicando têm um zero à esquerda em significando. Eles são usados para operações que não são válidas para sinalizar uma exceção de ponto flutuante de hardware.

## <a name="examples"></a>Exemplos

A seguir está alguns exemplos em formato de precisão simples:

- Para o valor 2, o bit de sinal for zero e o expoente armazenado é 128 ou 1000 0000 no binário, que é 127 mais 1. O significando binário armazenado é (1). ponto 000 0000 0000 0000 0000 0000, que tem um líder implícita 1 e binário, portanto, o significando real é um.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |2|1 * 2<sup>1</sup>|0100 0000 0000 0000 0000 0000 0000 0000|0x40000000|

- O valor de -2. Igual + 2, exceto pelo fato de que o bit de sinal é definido. Isso é verdadeiro para o negativo de todos os números de ponto flutuante do formato IEEE.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |-2|-1 * 2<sup>1</sup>|1100 0000 0000 0000 0000 0000 0000 0000|0xC0000000|

- O valor 4. Aumenta o expoente mesmo significando, por um (valor polarizada é 129 ou 100 0000 1 em binário.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |4|1 * 2<sup>2</sup>|0100 0000 1000 0000 0000 0000 0000 0000|0x40800000|

- O valor 6. Expoente mesmo, significando é ampliado pela metade — é (1). 100 0000 ... 0000 0000, que, como essa é uma fração binária, é 1 de 1/2 porque os valores dos dígitos fracionários são 1/2, 1 e 4, 1/8 e assim por diante.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |6|1.5 * 2<sup>2</sup>|0100 0000 1100 0000 0000 0000 0000 0000|0x40C00000|

- O valor 1. Mesmo significando como outros potências de dois, o expoente polarizado é um menos de dois em 127 ou 011 1111 1 em binário.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |1|1 * 2<sup>0</sup>|0011 1111 1000 0000 0000 0000 0000 0000|0x3F800000|

- O valor de 0,75. O expoente polarizado é 126, 011 1111 binário em 0 e o significando é (1). 100 0000 ... 0000 0000, 1 1/2.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0.75|1.5 * 2<sup>-1</sup>|0011 1111 0100 0000 0000 0000 0000 0000|0x3F400000|

- O valor 2.5. Exatamente dois exceto pelo fato de que o bit que representa 1 e 4 é definido em significando.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |2.5|1.25 * 2<sup>1</sup>|0100 0000 0010 0000 0000 0000 0000 0000|0x40200000|

- 1/10 é uma fração de repetição em binário. O significando é menos de 1.6, e o expoente polarizado diz que 1.6 deve ser dividido por 16 (é 011 1101 1 no binário, que é 123 em decimal). O expoente true é 127 123 = - 4, o que significa que o fator pelo qual multiplicar é 2<sup>-4</sup> = 1/16. Observe que o significando armazenado é arredondado para cima na última parte — uma tentativa para representar o número não representável de forma mais precisa possível. (O motivo pelo qual esse 1/10 e 1/100 são não exatamente representável no binário é semelhante ao motivo que 1/3 é representável não exatamente em decimais.)

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0.1|1.6 * 2<sup>-4</sup>|0011 1101 1100 1100 1100 1100 1100 1101|0x3DCCCCCD|

- Zero é um caso especial que usa a fórmula para o valor mínimo possível representável positivo, qual é a todos os zeros.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0|1 * 2<sup>-128</sup>|0000 0000 0000 0000 0000 0000 0000 0000|0x00000000|

## <a name="see-also"></a>Consulte também

[Por que números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md)