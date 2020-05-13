---
title: Representação de ponto flutuante IEEE
ms.date: 05/06/2019
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
ms.openlocfilehash: bb8523256c05479b303dec66ca79caa28e7cda03
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169806"
---
# <a name="ieee-floating-point-representation"></a>Representação de ponto flutuante IEEE

O Microsoft C++ (MSVC) é consistente com os padrões numéricos do IEEE. O padrão IEEE-754 descreve os formatos de ponto flutuante, uma maneira de representar números reais no hardware. Há pelo menos cinco formatos internos para números de ponto flutuante que podem ser representes no hardware de destino do compilador MSVC, mas o compilador usa apenas dois deles. Os formatos de *precisão única* (4 bytes) e *de precisão dupla* (8 bytes) são usados em MSVC. A precisão única é declarada usando a palavra-chave **float**. A precisão dupla é declarada usando a palavra-chave **Double**. O padrão IEEE também especifica formatos de *meia precisão* (2 bytes) e *de precisão quádrupla* (16 bytes), bem como um formato de *precisão estendida dupla* (10 bytes), que alguns compiladores C e C++ implementam como o tipo de dados **Double longo** . No compilador MSVC, o tipo de dados **Double longo** é tratado como um tipo distinto, mas o tipo de armazenamento é mapeado para **Double**. No entanto, há suporte à linguagem intrínseca e ao assembly para cálculos usando os outros formatos, incluindo o formato de precisão estendida dupla (10 bytes), em que o hardware dá suporte.

Os valores são armazenados da seguinte maneira:

|Valor|Armazenado como|
|-----------|---------------|
|precisão simples|sinal de bit, expoente de 8 bits, significante de 23 bits|
|precisão dupla|sinal de bit, expoente de 11 bits, significante-bit de 52 bits|
|precisão estendida dupla|bit de sinal, expoente de 15 bits, significante-bit de 64 bits|

Em formatos de precisão simples e de precisão dupla, há um 1 líder na parte fracionária, chamado de *significante* (e, às vezes, chamado de *mantissa*), que não é armazenado na memória, portanto, os significands são, na verdade, 24 ou 53 bits, embora apenas 23 ou 52 bits sejam armazenados. O formato de precisão estendida dupla realmente armazena esse bit.

Os expoentes são tendenciosas por metade de seu valor possível. Isso significa que você subtrai essa tendência do expoente armazenado para obter o expoente real. Se o expoente armazenado for menor que a tendência, ele será, na verdade, um expoente negativo.

Os expoentes são tendenciosas da seguinte maneira:

|Exponent|Tendenciosa por|
|--------------|---------------|
|8 bits (precisão única)|127|
|11 bits (precisão dupla)|1023|
|15 bits (precisão de extensão dupla)|16383|

Esses expoentes não são potências de dez; Eles são potências de dois. Ou seja, os expoentes armazenados de 8 bits podem variar de-127 a 127, armazenados como 0 a 254. O valor 2<sup>127</sup> é aproximadamente equivalente a 10<sup>38</sup>, que é o limite real de precisão simples.

O significante é armazenado como uma fração binária do formato 1.XXX.... Essa fração tem um valor maior ou igual a 1 e menor que 2. Observe que os números reais sempre são armazenados em *formato normalizado*; ou seja, o significante é deslocado para a esquerda de modo que o bit de ordem superior de significante seja sempre 1. Como esse bit é sempre 1, ele é presumido (não armazenado) nos formatos de precisão única e de precisão dupla. O ponto binário (não decimal) é considerado à direita da entrelinha 1.

O formato, em seguida, para os vários tamanhos é o seguinte:

|Formatar|byte 1|byte 2|byte 3|byte 4|...|byte n|
|------------|------------|------------|------------|------------|---------|------------|
|precisão simples| `SXXXXXXX`|`XMMMMMMM`|`MMMMMMMM`|`MMMMMMMM`|||
|precisão dupla|`SXXXXXXX`|`XXXXMMMM`|`MMMMMMMM`|`MMMMMMMM`|...|`MMMMMMMM`|
|precisão estendida dupla|`SXXXXXXX`|`XXXXXXXX`|`1MMMMMMM`|`MMMMMMMM`|...|`MMMMMMMM`|

`S`representa o bit de sinal, `X`os bits de expoente tendenciosa, e `M`são os bits significante. Observe que o bit mais à esquerda é considerado nos formatos de precisão simples e de precisão dupla, mas está presente como "1" em byte 3 do formato de precisão estendida dupla.

Para deslocar o ponto binário corretamente, você primeiro despolar o expoente e, em seguida, move o ponto binário para a direita ou para a esquerda do número apropriado de bits.

## <a name="special-values"></a>Valores especiais

Os formatos de ponto flutuante incluem alguns valores que são tratados especialmente.

### <a name="zero"></a>Zero

Zero não pode ser normalizado, o que o torna inrepresentado na forma normalizada de um valor de precisão simples ou de precisão dupla. Um padrão de bit especial de todos os zeros representa 0. Também é possível representar-0 como zero com o conjunto de bits de sinal, mas-0 e 0 sempre se comparam como iguais.

### <a name="infinities"></a>Infinitos

Os valores + ∞ e − ∞ são representados por um expoente de todos os e um significante de todos os zeros. Tanto os infinitos positivos quanto negativos podem ser representados usando o bit de sinal.

### <a name="subnormals"></a>Subnormals

É possível representar números de magnitude menor do que o menor número normalizado. Esses números são conhecidos como números *subnormals* ou *desnormals* . Se o expoente for todos os zeros e o significante for diferente de zero, o bit principal implícito do significante será considerado como zero, não um. A precisão dos números subnormals fica inativa conforme o número de zeros à esquerda no significante vai para cima.

### <a name="nan---not-a-number"></a>NaN – não é um número

É possível representar valores que não são um número real, como 0/0, no formato de ponto flutuante IEEE. Um valor desse tipo é chamado de *Nan*. Um NaN é representado por um expoente de todos aqueles e um significante diferente de zero. Há dois tipos de NaNs, *Quiet* Nans ou QNaNs e *sinalização* Nans ou SNaNs. O NaNs silencioso tem um líder na significante e geralmente é propagado por meio de uma expressão. Eles representam um valor indeterminado, como o resultado da divisão por infinito ou multiplicando um infinito por zero. a sinalização de NaNs tem um zero à esquerda no significante. Eles são usados para operações que não são válidas, para sinalizar uma exceção de hardware de ponto flutuante.

## <a name="examples"></a>Exemplos

Veja a seguir alguns exemplos no formato de precisão simples:

- Para o valor 2, o bit de sinal é zero e o expoente armazenado é 128 ou 1000 0000 em binary, que é 127 mais 1. O significante binário armazenado é (1.) 000 0000 0000 0000 0000 0000, que tem um ponto binário e 1 inicial implícito, portanto, o significante real é um.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |2|1 * 2<sup>1</sup>|0100 0000 0000 0000 0000 0000 0000 0000|0x40000000|

- O valor-2. O mesmo que + 2, exceto pelo fato de o bit de sinal ser definido. Isso é verdadeiro para o negativo de todos os números de ponto flutuante de formato IEEE.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |-2|-1 * 2<sup>1</sup>|1100 0000 0000 0000 0000 0000 0000 0000|0xC0000000|

- O valor 4. Mesmo significante, o expoente aumenta em um (valor polarizado é 129 ou 100 0000 1 em binário.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |4|1 * 2<sup>2</sup>|0100 0000 1000 0000 0000 0000 0000 0000|0x40800000|

- O valor 6. Mesmo expoente, significante é maior pela metade — é (1.) 100 0000... 0000 0000, que, como esta é uma fração binária, é 1 1/2 porque os valores dos dígitos fracionários são 1/2, 1/4, 1/8 e assim por diante.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |6|1,5 * 2<sup>2</sup>|0100 0000 1100 0000 0000 0000 0000 0000|0x40C00000|

- O valor 1. Mesmo significante como outras potências de dois, o expoente polarizado é um menor que dois em 127 ou 011 1111 1 em binário.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |1|1 * 2<sup>0</sup>|0011 1111 1000 0000 0000 0000 0000 0000|0x3F800000|

- O valor 0,75. O expoente polarizado é 126, 011 1111 0 em Binary e significante é (1.) 100 0000... 0000 0000, que é 1 1/2.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0.75|1,5 * 2<sup>-1</sup>|0011 1111 0100 0000 0000 0000 0000 0000|0x3F400000|

- O valor 2,5. Exatamente o mesmo que dois, exceto pelo fato de que o bit que representa 1/4 é definido no significante.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |2.5|1,25 * 2<sup>1</sup>|0100 0000 0010 0000 0000 0000 0000 0000|0x40200000|

- 1/10 é uma fração repetida em binário. O significante é apenas de 1,6, e o expoente polarizado diz que 1,6 deve ser dividido por 16 (é 011 1101 1 em binary, que é 123 em decimal). O expoente verdadeiro é 123-127 =-4, o que significa que o fator pelo qual multiplicar é 2<sup>-4</sup> = 1/16. Observe que o significante armazenado é arredondado para cima no último bit — uma tentativa de representar o número não representável o mais precisamente possível. (O motivo pelo qual 1/10 e 1/100 não são exatamente reapresentáveis em binário é semelhante ao motivo pelo qual 1/3 não é exatamente representável em decimal.)

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0,1|1,6 * 2<sup>-4</sup>|0011 1101 1100 1100 1100 1100 1100 1101|0x3DCCCCCD|

- Zero é um caso especial que usa a fórmula para o mínimo valor positivo possível representável, que é todos os zeros.

   |Valor|Fórmula|Representação binária|Hexadecimal|
   |-|-|-|-|
   |0|1 * 2<sup>-128</sup>|0000 0000 0000 0000 0000 0000 0000 0000|0x00000000|

## <a name="see-also"></a>Confira também

[Por que números de ponto flutuante podem perder a precisão](why-floating-point-numbers-may-lose-precision.md)
