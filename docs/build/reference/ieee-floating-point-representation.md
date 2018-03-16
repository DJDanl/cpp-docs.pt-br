---
title: "Representação de ponto flutuante IEEE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 17fae0cbb16208d5c7e7346f354f3501e4803d96
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="ieee-floating-point-representation"></a>Representação de ponto flutuante IEEE
Microsoft Visual C++ é consistente com os padrões de IEEE numéricos. Há três tipos internos de números reais. Real\*4 e real\*8 são usados no Visual C++. Real\*4 é declarado usando a palavra **float**. Real\*8 é declarado usando a palavra **duplo**. Na programação do Windows de 32 bits, o `long double` tipo de dados mapeia para **duplo**. No entanto, há suporte de linguagem de assembly para cálculos usando o real * o tipo de dados de 10.  
  
 Os valores são armazenados como segue:  
  
|Valor|Armazenados como|  
|-----------|---------------|  
|real*4|assinar bit, expoente de 8 bits, 23 bits mantissa|  
|real*8|assinar bit, 11 bits expoente, mantissa 52 bits|  
|real*10|assinar bit, expoente 15 bits, 64 bits mantissa|  
  
 Em real * 4 e real\*8 formatos, há uma assumida 1 à esquerda em mantissa que não é armazenado na memória, portanto os mantissas são, na verdade, 24 ou 53 bits, mesmo que apenas 23 ou 52 bits são armazenadas. O real\*formato 10 realmente armazena esse bit.  
  
 Tendem os expoentes pela metade de seu valor possível. Isso significa que você subtrair essa tendência do expoente armazenado para obter o expoente real. Se o expoente armazenado for menor que a diferença, é realmente um expoente negativo.  
  
 Tendem os expoentes da seguinte maneira:  
  
|Expoente|Atrelados|  
|--------------|---------------|  
|8-bit (real * 4)|127|  
|11 bits (real * 8)|1023|  
|15 bits (real * 10)|16383|  
  
 Esses expoentes não são potências de dez; eles são potências de dois. Ou seja, expoentes armazenados de 8 bits podem ser até 127. O valor 2 * * 127 é aproximadamente equivalente a 10\*\*38, que é o limite real de real\*4.  
  
 Mantissa é armazenado como uma fração de binária do formulário 1.XXX.... Essa fração tem um valor maior que ou igual a 1 e menor que 2. Observe que os números reais são sempre armazenados na forma normalizada; ou seja, mantissa é esquerda deslocada, de modo que o bit de ordem alta de mantissa é sempre 1. Como esse bit é sempre 1, presume-se (não armazenado) no real * 4 e real\*8 formatos. O ponto (não decimal) binário é considerado à direita do 1 à esquerda.  
  
 O formato, em seguida, para vários tamanhos é da seguinte maneira:  
  
|Formatar|BYTES 1|BYTE 2|BYTES 3|BYTES 4|...|N bytes|  
|------------|------------|------------|------------|------------|---------|------------|  
|real*4|`SXXX XXXX`|`XMMM MMMM`|`MMMM MMMM`|`MMMM MMMM`|||  
|real*8|`SXXX XXXX`|`XXXX MMMM`|`MMMM MMMM`|`MMMM MMMM`|...|`MMMM MMMM`|  
|real*10|`SXXX XXXX`|`XXXX XXXX`|`1MMM MMMM`|`MMMM MMMM`|...|`MMMM MMMM`|  
  
 `S` representa o bit de sinal de `X`do são os expoente bits e o `M`do são os bits de mantissa. Observe que o bit mais à esquerda é considerado real * 4 e real\*8 formatos, mas está presente como "1" em 3 bytes do real\*formato 10.  
  
 Para alternar o ponto de binário corretamente, você primeiro unbias o expoente e, em seguida, move o ponto de binário para a direita ou esquerda o número apropriado de bits.  
  
## <a name="examples"></a>Exemplos  
 A seguir estão alguns exemplos em real * 4 formato:  
  
-   No exemplo a seguir, o bit de sinal é zero, e o expoente armazenado é 128 ou 100 0000 0 em binário, que é 127 mais 1. Mantissa armazenado é (1). 000 0000 ... 0000 0000, que tem uma implícita à esquerda 1 e binária ponto, portanto a mantissa real é um.  
  
    ```  
                        SXXX XXXX XMMM MMMM ... MMMM MMMM  
    2   =  1  * 2**1  = 0100 0000 0000 0000 ... 0000 0000 = 4000 0000  
    ```  
  
-   Mesmo que + 2, exceto que o bit de sinal é definido. Isso é verdadeiro para todos os números de ponto flutuante do formato IEEE.  
  
    ```  
    -2  = -1  * 2**1  = 1100 0000 0000 0000 ... 0000 0000 = C000 0000  
    ```  
  
-   Aumenta o expoente mantissa mesmo, por um (valor polarizada é 129 ou 100 0000 1 em binário.  
  
    ```  
    4  =  1  * 2**2  = 0100 0000 1000 0000 ... 0000 0000 = 4080 0000  
    ```  
  
-   Expoente mesmo, mantissa é maior pela metade — é (1). 100 0000... 0000 0000, que, como essa é uma fração binária, é 1 1/2 (os valores de dígitos fracionários são 1/2, 1/4, 1/8 e assim por diante).  
  
    ```  
    6  = 1.5 * 2**2  = 0100 0000 1100 0000 ... 0000 0000 = 40C0 0000  
    ```  
  
-   Expoente mesmo como outros potências de dois, mantissa é um menos de dois a 127 ou 011 1111 1 em binário.  
  
    ```  
    1  = 1   * 2**0  = 0011 1111 1000 0000 ... 0000 0000 = 3F80 0000  
    ```  
  
-   O expoente polarizado é 126, 011 1111 binário em 0 e mantissa é (1). 100 0000 ... 0000 0000, 1 1/2.  
  
    ```  
    .75 = 1.5 * 2**-1 = 0011 1111 0100 0000 ... 0000 0000 = 3F40 0000  
    ```  
  
-   Exatamente dois exceto pelo fato de que o bit que representa 1/4 é definido em mantissa.  
  
    ```  
    2.5 = 1.25 * 2**1 = 0100 0000 0010 0000 ... 0000 0000 = 4020 0000  
    ```  
  
-   1 a 10 é uma fração de repetição em binário. Mantissa é menos de 1.6, e o expoente polarizado diz que 1.6 é dividido por 16 (é 011 1101 1 em binário, que é 123 em decimal). O expoente true é 123-127 = - 4, o que significa que o fator pelo qual multiplicar é 2 * * -4 = 1/16. Observe que a mantissa armazenada é arredondada para cima na última parte — uma tentativa para representar o número unrepresentable com precisão possível. (O motivo que 1/10 e 1/100 são não representável no binário é semelhante ao que 1/3 é exatamente não representável em decimal.)  
  
    ```  
    0.1 = 1.6 * 2**-4 = 0011 1101 1100 1100 ... 1100 1101 = 3DCC CCCD  
    ```  
  
-   `0  = 1.0 * 2**-128 = all zeros--a special case.`  
  
## <a name="see-also"></a>Consulte também  
 [Por que números de ponto flutuante podem perder a precisão](../../build/reference/why-floating-point-numbers-may-lose-precision.md)