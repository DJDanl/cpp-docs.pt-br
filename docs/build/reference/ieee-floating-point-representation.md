---
title: "Representa&#231;&#227;o de ponto flutuante IEEE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipo de dados double, representação de ponto flutuante"
  - "palavra-chave float"
  - "números de ponto flutuante, representação IEEE"
  - "representação de ponto flutuante IEEE"
  - "duplo longo"
  - "valor real*10"
  - "valor real*4"
  - "valor real*8"
ms.assetid: 537833e8-fe05-49fc-8169-55fd0314b195
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Representa&#231;&#227;o de ponto flutuante IEEE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Microsoft Visual C\+\+ é consistente com os padrões numéricos IEEE.  Há três tipos internas de números reais.  Real\*4 e real\*8 são usados no Visual C\+\+.  Real\*4 é declarado usando as palavras **float**.  Real\*8 é declarado usando as palavras **double**.  Em programação de 32 bits do windows, o tipo de dados de `long double` a **double**.  Há, porém, um suporte à linguagem assembly para computações usando o tipo de dados real\*10.  
  
 Os valores são armazenados como se segue:  
  
|Valor|Como armazenado|  
|-----------|---------------------|  
|real\*4|bit de sinal, expoente de 8 bits, mantissa de 23 bits|  
|real\*8|bit de sinal, expoente de 11 bits, mantissa de 52 bits|  
|real\*10|bit de sinal, expoente de 15 bits, mantissa de 64 bits|  
  
 Os formatos real\*4 e real\*8, há um 1 à esquerda em mantissa assumido que não são armazenadas na memória, de modo que as mantissas são de fato 24 ou 53 bits, mesmo que apenas os 23 ou 52 bits sejam armazenados.  O formato real\*10 a realidade armazena este bit.  
  
 Os expoentes são inclinados pela metade do valor possível.  Isso significa que você subtrai essa diferença do expoente armazenado para obter o expoente real.  Se o expoente armazenado é menor que a diferença, é realmente um expoente negativo.  
  
 Os expoentes são inclinados como segue:  
  
|Expoente|Removido por|  
|--------------|------------------|  
|de 8 bits \(real\*4\)|127|  
|11\- bit \(real\*8\)|1023|  
|15 bits \(real\*10\)|16383|  
  
 Esses expoentes não são potências de dez; é a potência de dois.  Ou seja, os expoentes armazenados de 8 bits podem ter até 127.  O valor 2 \*\* 127 é aproximadamente equivalente a 10 \*\* 38, que é o limite real de real\*4.  
  
 A mantissa é armazenada como uma fração binário do formulário 1.XXX… .  Essa fração tiver um valor maior ou igual a 1 e menor que 2.  Observe que os números reais são sempre armazenados em formato normalizado; isto é, a mantissa deslocamento é deslocada de modo que o bit de ordem alta mantissa é sempre 1.  Como esse bit é sempre 1, será assumido \(não\) armazenado em formatos real\*4 e real\*8.  O ponto decimal \(não\) binário é considerado como apenas à direita do 1. a esquerda.  
  
 O formato, em seguida, para os vários tamanhos é a seguinte:  
  
|Formato|BYTE 1|BYTE 2|BYTE 3|BYTE 4|...|BYTE em|  
|-------------|------------|------------|------------|------------|---------|-------------|  
|real\*4|`SXXX XXXX`|`XMMM MMMM`|`MMMM MMMM`|`MMMM MMMM`|||  
|real\*8|`SXXX XXXX`|`XXXX MMMM`|`MMMM MMMM`|`MMMM MMMM`|...|`MMMM MMMM`|  
|real\*10|`SXXX XXXX`|`XXXX XXXX`|`1MMM MMMM`|`MMMM MMMM`|...|`MMMM MMMM`|  
  
 `S` representa o bit de sinal, `X` é os bits do expoente, e `M` é os bits de mantissa.  Observe que o mais à esquerda será assumido em formatos real\*4 e real\*8, mas estiver presente como “1 " em BYTE 3 de formato real\*10.  
  
 Para deslocar\-lo corretamente o ponto binário, primeiro unbias o expoente e mover o ponto de binário em direita ou esquerda o número apropriado de bit.  
  
## Exemplos  
 Estes são alguns exemplos no formato real\*4:  
  
-   No exemplo a seguir, o bit de sinal é zero, e o expoente armazenado for 128, 100 ou 0000 a 0 no binário, que é 127 mais 1.  Mantissa é armazenada como 1 \(0000…\) 000. 0000 a 0000, que tem um 1 à esquerda implícito e um ponto binário, a mantissa real é uma.  
  
    ```  
                        SXXX XXXX XMMM MMMM ... MMMM MMMM  
    2   =  1  * 2**1  = 0100 0000 0000 0000 ... 0000 0000 = 4000 0000  
    ```  
  
-   Mesmo que \+2 exceto que o bit de sinal são definidos.  Isso é verdadeiro para todos os números de ponto flutuante IEEE de formato.  
  
    ```  
    -2  = -1  * 2**1  = 1100 0000 0000 0000 ... 0000 0000 = C000 0000  
    ```  
  
-   A mesma mantissa, fica um expoente \(o valor é mais adequado 129, 100 ou 0000 a 1 no binário.  
  
    ```  
    4  =  1  * 2**2  = 0100 0000 1000 0000 ... 0000 0000 = 4080 0000  
    ```  
  
-   O expoente mesmo, mantissa é maior que a metade — é \(1\) 100. 0000… 0000 a 0000, que, uma vez que essas são uma fração binário, são 1 \* 1\/2 \(os valores dos dígitos fracionários são 1\/2, 1\/4, 1\/8, e assim por diante\).  
  
    ```  
    6  = 1.5 * 2**2  = 0100 0000 1100 0000 ... 0000 0000 = 40C0 0000  
    ```  
  
-   Expoente mesmo que outras a potência de dois, mantissa é um o menos dois em 127, 011 ou 1111 a 1 no binário.  
  
    ```  
    1  = 1   * 2**0  = 0011 1111 1000 0000 ... 0000 0000 = 3F80 0000  
    ```  
  
-   Expoente removido é 126, 011 1111 a 0 no binário, e a mantissa o for \(1 100 0000…\). 0000 a 0000, que é 1 \* 1\/2.  
  
    ```  
    .75 = 1.5 * 2**-1 = 0011 1111 0100 0000 ... 0000 0000 = 3F40 0000  
    ```  
  
-   Exatamente o mesmo que dois exceto que o bit representando 1\/4 são definidos em mantissa.  
  
    ```  
    2.5 = 1.25 * 2**1 = 0100 0000 0010 0000 ... 0000 0000 = 4020 0000  
    ```  
  
-   1\/10 é uma fração de repetição em binário.  A mantissa é apenas tímida de 1,6, e o expoente inclinado diz que 1,6 será dividido por 16 é 011 \(1101 a 1 no binário, que é o decimal 123\).  O expoente true é 123 – 127 \= – 4, que significa que o fator pela qual multiplicar é \*\* 2 – 4 \= 1\/16.  Observe que a mantissa armazenada será arredondada acima no bit o último — uma tentativa de representar o com precisão o número unrepresentable possível. \(A razão pela qual 1\/10 e 1\/100 não são exatamente representable em binário é semelhante à razão pela qual 1\/3 não são exatamente representable em decimal.\)  
  
    ```  
    0.1 = 1.6 * 2**-4 = 0011 1101 1100 1100 ... 1100 1101 = 3DCC CCCD  
    ```  
  
-   `0  = 1.0 * 2**-128 = all zeros--a special case.`  
  
## Consulte também  
 [Por que números de ponto flutuante podem perder a precisão](../../build/reference/why-floating-point-numbers-may-lose-precision.md)