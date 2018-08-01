---
title: Numérico, booliano e literais de ponteiro (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- literals, C++
- constants, literals
- literals [C++]
ms.assetid: 17c09fc3-3ad7-47e2-8b48-ba8ae994edc8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a445e9c435f9e077899a2a473dc5862f98a36bf4
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405513"
---
# <a name="numeric-boolean-and-pointer-literals--c"></a>Numérico, booliano e literais de ponteiro (C++)
Um literal é um elemento de programa que representa diretamente a um valor. Este artigo aborda os literais do tipo inteiro, ponto flutuante, booleanos e ponteiro. Para obter informações sobre a cadeia de caracteres literais, consulte [cadeia de caracteres e literais de caracteres (C++)](../cpp/string-and-character-literals-cpp.md). Você também pode definir seus próprios literais com base em qualquer uma dessas categorias; Para obter mais informações, consulte [literais definidos pelo usuário (C++)](../cpp/user-defined-literals-cpp.md)  
  
 . Você pode usar literais em muitos contextos, mas a maioria comumente para inicializar variáveis nomeadas e passar argumentos para funções:  
  
```cpp 
const int answer = 42; // integer literal  
double d = sin(108.87);     //floating point literal passed to sin function  
bool b = true;              // boolean literal  
MyClass* mc = nullptr;      // pointer literal  
```  
  
 Às vezes, é importante indicar ao compilador como interpretar um literal ou tipo específico para dar a ele. Você pode fazer isso por meio do acréscimo prefixos ou sufixos para o literal. Por exemplo, o prefixo 0 x instrui o compilador a interpretar o número que vem a seguir como um valor hexadecimal, por exemplo 0x35. O sufixo MPLETO instrui o compilador a tratar o valor como um **longo longo sem sinal** tipo, como no 5894345ULL. Consulte as seções a seguir para obter uma lista de prefixos e sufixos para cada tipo de literal.  
  
## <a name="syntax"></a>Sintaxe  
  
## <a name="integer-literals"></a>Literais inteiros  
 Literais inteiros começam com um dígito e não tem nenhuma parte fracionária ou expoente. Você pode especificar literais inteiros em formato decimal, hexadecimal ou octal. Elas podem especificar tipos com sinal e sem sinal e longos ou curtos.  
  
 Quando nenhum prefixo ou sufixo estiver presente, o compilador fornecerá um tipo de valor literal inteiro **int** (32 bits), se o valor couber, caso contrário, ele fornecerá-tipo **long long** (64 bits).  
  
 Para especificar um literal de inteiro decimal, inicie a especificação com um dígito diferente de zero. Por exemplo:  
  
```cpp 
int i = 157;   // Decimal literal  
int j = 0198;       // Not a decimal number; erroneous octal literal  
int k = 0365;       // Leading zero specifies octal literal, not decimal  
int m = 36'000'000  // digit separators make large values more readable  
int   
```  
  
 Para especificar um literal de integral octal, inicie a especificação com 0, seguido por uma sequência de dígitos no intervalo de 0 a 7. Os dígitos 8 e 9 são erros na especificação de um literal octal. Por exemplo:  
  
```cpp 
int i = 0377;   // Octal literal  
int j = 0397;        // Error: 9 is not an octal digit  
```  
  
 Para especificar um literal de inteiro hexadecimal, inicie a especificação com `0x` ou `0X` (no caso do "x" não importa), seguido por uma sequência de dígitos no intervalo `0` por meio `9` e `a` (ou `A`) por meio `f` (ou `F`). Os dígitos hexadecimais de `a` (ou `A`) a `f` (ou `F`) representam valores no intervalo de 10 a 15. Por exemplo:  
  
```cpp 
int i = 0x3fff;   // Hexadecimal literal  
int j = 0X3FFF;        // Equal to i  
```  
  
 Para especificar um tipo sem sinal, use o `u` ou `U` sufixo. Para especificar um tipo longo, use o `l` ou `L` sufixo. Para especificar um tipo integral de 64 bits, use o LL ou sufixo ll. O sufixo i64 ainda tem suporte, mas deve ser evitado porque ele é específico da Microsoft e não é portátil. Por exemplo:  
  
```cpp 
unsigned val_1 = 328u;             // Unsigned value  
long val_2 = 0x7FFFFFL;                 // Long value specified   
                                        //  as hex literal  
unsigned long val_3 = 0776745ul;        // Unsigned long value  
auto val_4 = 108LL;                           // signed long long  
auto val_4 = 0x8000000000000000ULL << 16;     // unsigned long long   
```  
  
 **Separadores de dígito**: você pode usar o caractere de aspas simples (apóstrofo) para separar os valores de local em um número maior para torná-los mais fáceis para leitura humana. Separadores não terão efeito na compilação.  
  
```cpp 
long long i = 24'847'458'121  
```  
  
## <a name="floating-point-literals"></a>Literais de ponto flutuante  
 Literais de ponto flutuantes especificam valores que devem ter uma parte fracionária. Esses valores contêm pontos decimais (**.**) e podem conter expoentes.  
  
 Literais de ponto flutuantes têm uma "mantissa", que especifica o valor do número, um "expoente", que especifica a magnitude do número, e um sufixo opcional que especifica o tipo do literal. A mantissa é especificada como uma sequência de dígitos seguida por um ponto final, seguidos por uma sequência opcional de dígitos que representa a parte fracionária do número. Por exemplo:  
  
```cpp 
18.46  
38.  
```  
  
 O expoente, se presente, especifica a magnitude do número como uma potência de 10, como mostrado no seguinte exemplo:  
  
```cpp 
18.46e0      // 18.46  
18.46e1           // 184.6  
```  
  
 O expoente pode ser especificado usando `e` ou `E`, que têm o mesmo significado, seguido por um sinal opcional (+ ou -) e uma sequência de dígitos.  Se um expoente estiver presente, o ponto decimal à direita é desnecessário em números inteiros como `18E0`.  
  
 Literais de ponto flutuantes padrão para o tipo **duplas**. Usando os sufixos `f` ou `l` (ou `F` ou `L` — o sufixo não diferencia maiusculas de minúsculas), o literal pode ser especificado como **float** ou **longo duplo**, respectivamente.  
  
 Embora **longo duplo** e **duplo** têm a mesma representação, eles não são do mesmo tipo. Por exemplo, você pode ter funções sobrecarregadas como  
  
```cpp 
void func( double );  
```  
  
 e  
  
```cpp 
void func( long double );  
```  
  
## <a name="boolean-literals"></a>Literais boolianos  
 Literais booleanos são **verdadeira** e **falso**.  
  
## <a name="pointer-literal-c11"></a>Literais de ponteiro (C + + 11)  
 O C++ apresenta a [nullptr](../cpp/nullptr.md) literal para especificar um ponteiro inicializada do zero. No código portátil **nullptr** deve ser usado em vez de macros como nulo ou zero de tipo integral.  
  
## <a name="binary-literals-c14"></a>Literais binários (c++14)  
 Um literal binário pode ser especificado pelo uso do `0B` ou `0b` prefixo, seguido por uma sequência de 1 e 0:  
  
```cpp 
auto x = 0B001101 ; // int  
auto y = 0b000001 ; // int  
```  
  
## <a name="avoid-using-literals-as-magic-constants"></a>Evite usar literais como constantes"mágicas"  
 Você pode usar literais diretamente em expressões e instruções, embora nem sempre é uma boa prática de programação:  
  
```cpp 
if (num < 100)  
    return "Success";  
```  
  
 No exemplo anterior, talvez seja melhor usar uma constante nomeada que transmite um significado claro, por exemplo "MAXIMUM_ERROR_THRESHOLD". E se o valor de retorno "Success" é visto pelos usuários finais, em seguida, ele pode ser melhor usar uma constante de cadeia de caracteres nomeadas que pode ser armazenada em um único local em um arquivo de onde ele possa ser localizado em outros idiomas. Usando constantes nomeadas ajuda a outras pessoas, bem como para entender a intenção do código.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)   
 [Literais String C++](../cpp/string-and-character-literals-cpp.md)   
 [Literais definidos pelo usuário do C++](../cpp/user-defined-literals-cpp.md)