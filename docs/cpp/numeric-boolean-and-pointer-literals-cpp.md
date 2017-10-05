---
title: "Numérico, booleano e literais de ponteiro (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- literals, C++
- constants, literals
- literals
ms.assetid: 17c09fc3-3ad7-47e2-8b48-ba8ae994edc8
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 5c4a9a7aca2f11956e0ba47cced37a86733dcce8
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="numeric-boolean-and-pointer-literals--c"></a>Numérico, booleano e literais de ponteiro (C++)
Um literal é um elemento do programa que representa diretamente a um valor. Este artigo aborda os literais do tipo inteiro, ponto flutuante, boolean e ponteiro. Para obter informações sobre literais de cadeia de caracteres e caracteres, consulte [cadeia de caracteres e literais de caracteres (C++)](../cpp/string-and-character-literals-cpp.md). Você também pode definir seus próprios literais com base em qualquer uma dessas categorias; Para obter mais informações, consulte [literais definidos pelo usuário (C++)](../cpp/user-defined-literals-cpp.md)  
  
 . Você pode usar literais em vários contextos, mas a maioria geralmente inicializar variáveis nomeadas e passar argumentos para funções:  
  
```  
const int answer = 42; // integer literal  
double d = sin(108.87);     //floating point literal passed to sin function  
bool b = true;              // boolean literal  
MyClass* mc = nullptr;      // pointer literal  
  
```  
  
 Às vezes, é importante saber o compilador como interpretar um literal ou o tipo específico para dar a ele. Isso é feito acrescentando prefixos ou sufixos para literal. Por exemplo, o prefixo 0 x informa ao compilador para interpretar o número seguinte como um valor hexadecimal, por exemplo 0x35. O sufixo BTER informa ao compilador para tratar o valor como um `unsigned long long` tipo, como 5894345ULL. Consulte as seções a seguir para obter uma lista de prefixos e sufixos para cada tipo de literal.  
  
## <a name="syntax"></a>Sintaxe  
  
## <a name="integer-literals"></a>Literais inteiros  
 Literais inteiros começam com um dígito e não têm partes fracionários ou expoentes. Você pode especificar literais inteiros em formato decimal, hexadecimal ou octal. Elas podem especificar tipos com sinal e sem sinal e longos ou curtos.  
  
 Quando nenhum prefixo ou sufixo estiver presente, o compilador fornecerá um tipo de valor literal inteiro `int` (32 bits), se ajustará o valor, caso contrário, ele lhe dará tipo `long long` (64 bits).  
  
 Para especificar um literal de inteiro decimal, comece a especificação com um dígito zero. Por exemplo:  
  
```  
int i = 157;   // Decimal literal  
int j = 0198;       // Not a decimal number; erroneous octal literal  
int k = 0365;       // Leading zero specifies octal literal, not decimal  
int m = 36'000'000  // digit separators make large values more readable  
int   
```  
  
 Para especificar um literal de inteiro octal, comece a especificação com 0, seguido por uma sequência de dígitos no intervalo de 0 a 7. Os dígitos 8 e 9 são erros na especificação de um literal octal. Por exemplo:  
  
```  
int i = 0377;   // Octal literal  
int j = 0397;        // Error: 9 is not an octal digit  
```  
  
 Para especificar um literal de inteiro hexadecimal, começar com a especificação de `0x` ou `0X` (no caso de "x" não importa), seguido por uma sequência de dígitos no intervalo `0` por meio de `9` e `a` (ou `A`) por meio de `f` (ou `F`). Os dígitos hexadecimais de `a` (ou `A`) a `f` (ou `F`) representam valores no intervalo de 10 a 15. Por exemplo:  
  
```  
int i = 0x3fff;   // Hexadecimal literal  
int j = 0X3FFF;        // Equal to i  
```  
  
 Para especificar um tipo não assinado, use o **u** ou **U** sufixo. Para especificar um tipo longo, utilize o **l** ou **L** sufixo. Para especificar um tipo integral de 64 bits, use o LL ou ll sufixo. O sufixo i64 ainda tem suporte, mas deve ser evitado porque ele é específico da Microsoft e não é portátil. Por exemplo:  
  
```  
unsigned val_1 = 328u;             // Unsigned value  
long val_2 = 0x7FFFFFL;                 // Long value specified   
                                        //  as hex literal  
unsigned long val_3 = 0776745ul;        // Unsigned long value  
auto val_4 = 108LL;                           // signed long long  
auto val_4 = 0x8000000000000000ULL << 16;     // unsigned long long   
```  
  
 **Separadores de dígitos**: você pode usar o caractere de aspas simples (apóstrofo) para separar os valores do local em um número maior para torná-los mais fácil para humanos ler. Separadores não têm nenhum efeito na compilação.  
  
```  
long long i = 24'847'458'121  
```  
  
## <a name="floating-point-literals"></a>Literais de ponto flutuante  
 Literais de ponto flutuantes especificar valores que devem ter uma parte fracionária. Esses valores contêm pontos decimais (**.**) e pode conter expoentes.  
  
 Literais de ponto flutuantes tem um "mantissa," que especifica o valor do número, um "expoente," que especifica a magnitude do número, e um sufixo opcional que especifica o tipo do literal. A mantissa é especificada como uma sequência de dígitos seguida por um ponto final, seguidos por uma sequência opcional de dígitos que representa a parte fracionária do número. Por exemplo:  
  
```  
18.46  
38.  
```  
  
 O expoente, se presente, especifica a magnitude do número como uma potência de 10, como mostrado no seguinte exemplo:  
  
```  
18.46e0      // 18.46  
18.46e1           // 184.6  
```  
  
 O expoente pode ser especificado usando **e** ou **E**, que tem o mesmo significado, seguido por um sinal opcional (+ ou -) e uma sequência de dígitos.  Se um expoente estiver presente, o ponto decimal à direita é desnecessário em números inteiros como `18E0`.  
  
 Literais de ponto flutuantes padrão para o tipo **duplo**. Usando os sufixos **f** ou **l** (ou **F** ou **L** — o sufixo não diferencia maiusculas de minúsculas), o literal pode ser especificado como ** float** ou `long double`, respectivamente.  
  
 Embora `long double` e **duplo** tem a mesma representação, eles não são do mesmo tipo. Por exemplo, você pode ter funções sobrecarregadas como  
  
```  
void func( double );  
```  
  
 e  
  
```  
void func( long double );  
```  
  
## <a name="boolean-literals"></a>Literais boolianos  
 As literais Boolianas são `true` e `false`.  
  
## <a name="pointer-literal-c11"></a>Literal de ponteiro (C++ 11)  
 C++ apresenta o [nullptr](../cpp/nullptr.md) literal para especificar um ponteiro inicializada do zero. No código portátil, `nullptr` deve ser usado em vez de macros como nulo ou zero de tipo integral.  
  
## <a name="binary-literals-c14"></a>Literais binários (C++ 14)  
 Um literal binário pode ser especificado com o uso do `0B` ou `0b` prefixo, seguido por uma sequência de 1 e 0:  
  
```  
  
auto x = 0B001101 ; // int  
auto y = 0b000001 ; // int  
```  
  
## <a name="avoid-using-literals-as-magic-constants"></a>Evite usar literais como "magic constantes"  
 Embora nem sempre é uma boa prática de programação, você pode usar literais diretamente em expressões e instruções:  
  
```  
if (num < 100)  
    return "Success";  
  
```  
  
 No exemplo anterior, talvez seja melhor usar uma constante nomeada que transmite um significado claro, por exemplo "MAXIMUM_ERROR_THRESHOLD". E se o valor de retorno "Êxito" é visto por usuários finais, ele pode ser melhor usar uma constante de cadeia de caracteres nomeadas que pode ser armazenada em um único local em um arquivo de onde ele pode ser localizado em outros idiomas. Usando constantes nomeadas ajuda a outras pessoas, bem como para entender a intenção do código.  
  
## <a name="see-also"></a>Consulte também  
 [Convenções lexicais](../cpp/lexical-conventions.md)   
 [Literais de cadeia de caracteres C++](../cpp/string-and-character-literals-cpp.md)   
 [Literais definidos pelo usuário do C++](../cpp/user-defined-literals-cpp.md)
