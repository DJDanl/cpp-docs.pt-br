---
title: "Tipo float | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "tipo de dados double, tipo float"
  - "comprimento do expoente"
  - "palavra-chave float [C]"
  - "números de ponto flutuante, tipo float"
  - "números de ponto flutuante, variáveis"
  - "representação de ponto flutuante IEEE"
  - "comprimentos, expoente"
  - "comprimentos, mantissa"
  - "mantissas, comprimento"
  - "intervalos, tipos de ponto flutuante"
  - "tipo float"
ms.assetid: 706e332b-17a0-4a30-b7d8-5d6cd372524b
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipo float
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os números de ponto flutuante usam o formato IEEE \(Instituto de Engenheiros Eletricistas e Eletrônicos\).  Os valores de precisão simples com tipo float têm 4 bytes, que consistem em um bit de sinal, um expoente binário de 8 bits no formato de 127 em excesso e uma mantissa de 23 bits.  A mantissa representa um número entre 1,0 e 2,0.  Como o bit de ordem superior da mantissa é sempre 1, ele não é armazenado no número.  Essa representação fornece um intervalo de aproximadamente 3,4E–38 a 3,4E\+38 para o tipo float.  
  
 Você pode declarar variáveis como float ou double, dependendo das necessidades de seu aplicativo.  As principais diferenças entre os dois tipos são a significação que podem representar, o armazenamento que exigem e o intervalo que ocupam.  A tabela a seguir mostra a relação entre a significação e os requisitos de armazenamento.  
  
### Tipos de ponto flutuante  
  
|Tipo|Dígitos significativos|Número de bytes|  
|----------|----------------------------|---------------------|  
|float|6 – 7|4|  
|double|15 – 16|8|  
  
 As variáveis de ponto flutuante são representadas por uma mantissa, que contém o valor do número, e um expoente, que contém a ordem de grandeza do número.  
  
 A tabela a seguir mostra o número de bits alocados à mantissa e ao expoente para cada tipo de ponto flutuante.  O bit mais significativo de qualquer float ou double é sempre o bit de sinal.  Se ele for 1, o número será considerado negativo; caso contrário, será considerado um número positivo.  
  
### Comprimentos de expoentes e de mantissas  
  
|Tipo|Comprimento do expoente|Comprimento da mantissa|  
|----------|-----------------------------|-----------------------------|  
|float|8 bits|23 bits|  
|double|11 bits|52 bits|  
  
 Como são armazenados em um formato sem sinal, os expoentes são deslocados pela metade do valor possível.  Para o tipo float, o deslocamento é 127; para o tipo double, é 1023.  Você pode calcular o valor real do expoente subtraindo o valor do deslocamento do valor do expoente.  
  
 A mantissa é armazenada como uma fração binária maior ou igual a 1 e menor que 2.  Para os tipos float e double, existe um 1 à esquerda implícito na mantissa na posição de bit mais significativa; assim, na verdade, as mantissas têm 24 e 53 bits de comprimento, respectivamente, embora o bit mais significativo nunca seja armazenado na memória.  
  
 Em vez do método de armazenamento descrito acima, o pacote de ponto flutuante pode armazenar números de ponto flutuante binários como números desnormalizados. "Números desnormalizados" são números de ponto flutuante diferentes de zero com valores de expoente reservados nos quais o bit mais significativo da mantissa é 0.  Usando o formato desnormalizado, o intervalo de um número de ponto flutuante pode ser estendido, perdendo em precisão.  Você não pode controlar se um número de ponto flutuante é representado no formato normalizado ou desnormalizado; o pacote de ponto flutuante determina a representação.  O pacote de ponto flutuante nunca usa um formato desnormalizado, a menos que o expoente se torne menor do que o valor mínimo que pode ser representado em um formato normalizado.  
  
 A tabela a seguir mostra os valores mínimo e máximo que você pode armazenar em variáveis de cada tipo de ponto flutuante.  Os valores listados na tabela só se aplicam aos números de ponto flutuante normalizados; os números de ponto flutuante desnormalizados têm um valor mínimo menor.  Observe que os números retidos nos registros 80*x*87 são sempre representados no formato normalizado de 80 bits; os números só podem ser representados no formato desnormalizado quando armazenados em variáveis de ponto flutuante de 32 bits ou de 64 bits \(variáveis do tipo float e do tipo long\).  
  
### Intervalo de tipos de ponto flutuante  
  
|Tipo|Valor mínimo|Valor máximo|  
|----------|------------------|------------------|  
|float|1,175494351 E – 38|3,402823466 E \+ 38|  
|double|2,2250738585072014 E – 308|1,7976931348623158 E \+ 308|  
  
 Se a precisão preocupa menos que o armazenamento, considere usar o tipo float para as variáveis de ponto flutuante.  Ao contrário, se a precisão é o critério mais importante, use o tipo double.  
  
 As variáveis de ponto flutuante podem ser promovidas a um tipo de maior significação \(do tipo float para o tipo double\).  Muitas vezes, a promoção ocorre quando você executa uma aritmética em variáveis de ponto flutuante.  Essa aritmética é sempre realizada no mesmo grau de precisão que a variável com o grau de precisão mais alto.  Por exemplo, considere as seguintes declarações de tipo:  
  
```  
float f_short;  
double f_long;  
long double f_longer;  
  
f_short = f_short * f_long;  
```  
  
 No exemplo acima, a variável `f_short` é promovida para o tipo double e multiplicada por `f_long`; o resultado é arredondado para o tipo float antes de ser atribuído a `f_short`.  
  
 No exemplo a seguir \(que usa as declarações do exemplo anterior\), a aritmética é realizada com precisão de float \(32 bits\) nas variáveis; o resultado é promovido para o tipo double:  
  
```  
f_longer = f_short * f_short;  
```  
  
## Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)