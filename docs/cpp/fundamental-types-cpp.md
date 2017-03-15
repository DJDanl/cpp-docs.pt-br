---
title: "Tipos fundamentais (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__wchar_t_cpp"
  - "long_double_cpp"
  - "unsigned"
  - "wchar_t_cpp"
  - "float_cpp"
  - "wchar_t"
  - "char"
  - "char_cpp"
  - "signed"
  - "__wchar_t"
  - "signed_cpp"
  - "short"
  - "double_cpp"
  - "int_cpp"
  - "long"
  - "__intn_cpp"
  - "short_cpp"
  - "double"
  - "unsigned_cpp"
  - "float"
  - "__intn"
  - "long_cpp"
  - "int"
  - "long_double"
  - "unsigned_int"
  - "__int8"
  - "__int8_cpp"
  - "__int16"
  - "__int16_cpp"
  - "__int32"
  - "__int32_cpp"
  - "__int64"
  - "__int64_cpp"
  - "__int128"
  - "__int128_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __wchar_t [C++]"
  - "operações aritméticas [C++], tipos"
  - "palavra-chave char [C++]"
  - "tipos de dados [C++], void"
  - "tipo de dados double, resumo de tipos"
  - "palavra-chave float [C++]"
  - "números de ponto flutuante, tipos de dados C++"
  - "tipo de dados int"
  - "tipo de dados Integer, tipos de dados C++"
  - "tipos integrais"
  - "tipos integrais, C++"
  - "palavra-chave long double [C++]"
  - "palavra-chave long [C++]"
  - "palavra-chave long [C++], tipos de dados C++"
  - "palavra-chave long long [C++]"
  - "tipo de dados curto"
  - "tipos assinados [C++]"
  - "tipos assinados [C++], resumo de tipos de dados"
  - "especificadores [C++], Tipo "
  - "armazenamento [C++], tipo básico"
  - "armazenando tipos [C++]"
  - "especificadores de tipo [C++]"
  - "tipos não assinados [C++]"
  - "tipos não assinados [C++], resumo de tipos de dados"
  - "palavra-chave void [C++]"
  - "Palavra-chave wchar_t [C++]"
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos fundamentais (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Tipos fundamentais em C\+\+ são divididos em três categorias: integral, de ponto flutuante e void. Tipos integrais são capazes de manipular números inteiros. Tipos de ponto flutuante são capazes de especificar valores que podem ter partes fracionárias.  
  
 O [void](../cpp/void-cpp.md) tipo descreve um conjunto vazio de valores. Nenhuma variável do tipo `void` pode ser especificado — ele é usado principalmente para declarar funções que não retornam valores ou declarar ponteiros genéricos para não tipado ou arbitrariamente dados digitados. Qualquer expressão pode ser explicitamente convertido ou convertido no tipo `void`. No entanto, tais expressões estão restritas aos seguintes usos:  
  
-   Uma instrução de expressão. \(Consulte [expressões](../cpp/expressions-cpp.md), para obter mais informações.\)  
  
-   O operando esquerdo do operador vírgula. \(Consulte [operador vírgula](../cpp/comma-operator.md) para obter mais informações.\)  
  
-   O segundo ou terceiro operando do operador condicional \(`? :`\). \(Consulte [expressões com o operador condicional](../cpp/conditional-operator-q.md) para obter mais informações.\)  
  
 A tabela a seguir explica as restrições de tamanhos de tipo. Essas restrições são independentes da implementação da Microsoft.  
  
### Tipos fundamentais da linguagem C\+\+  
  
|Categoria|Tipo|Conteúdo|  
|---------------|----------|--------------|  
|Integral|`char`|Tipo `char` é um tipo integral que geralmente contém membros do conjunto de caracteres de execução básico — por padrão, esse é o ASCII no Microsoft C\+\+.<br /><br /> O compilador C\+\+ trata variáveis do tipo `char`, `signed` `char`, e `unsigned` `char` têm tipos diferentes.   Variáveis do tipo `char` são promovidos para `int` como se fossem do tipo `signed` `char` por padrão, a menos que a opção de compilação \/J for usada.  Nesse caso, eles são tratados como tipo `unsigned` `char` e forem promovidos para `int` sem extensão de sinal.|  
||`bool`|Tipo `bool` é um tipo integral que pode ter um dos dois valores `true` ou `false`. Seu tamanho é especificado.|  
||`short`|Tipo de `short` `int` \(ou simplesmente `short`\) é um tipo integral que é maior ou igual ao tamanho do tipo `char`, e menor ou igual ao tamanho do tipo `int`.<br /><br /> Objetos do tipo `short` podem ser declarados como `signed` `short` ou `unsigned short`. `Signed short` é um sinônimo para `short`.|  
||`int`|Tipo `int` é um tipo integral que é maior ou igual ao tamanho do tipo `short` `int`, e menor ou igual ao tamanho do tipo `long`.<br /><br /> Objetos do tipo `int` podem ser declarados como `signed` `int` ou `unsigned` `int`.  `Signed` `int` é um sinônimo para `int`.|  
||`__int8`, `__int16`, `__int32`, `__int64`|Inteiros dimensionados `__int``n`, onde `n` é o tamanho, em bits, da variável de inteiro.`__int8`, `__int16`, `__int32` e `__int64` são palavras\-chave específicas da Microsoft. Nem todos os tipos estão disponíveis em todas as arquiteturas.`(__int128` Não há suporte.\)|  
||`long`|Tipo de `long` \(ou `long` `int`\) é um tipo integral que é maior ou igual ao tamanho do tipo `int`.<br /><br /> Objetos do tipo `long` podem ser declarados como `signed` `long` ou `unsigned` `long`.  `Signed` `long` é um sinônimo para `long`.|  
||`long` `long`|Maior do que um unsigned `long`.<br /><br /> Objetos do tipo `long long` podem ser declarados como `signed` `long long` ou `unsigned` `long long`.  `Signed` `long long` é um sinônimo para `long long`.|  
||`wchar_t`, `__wchar_t`|Uma variável do tipo `wchar_t` designa um tipo de caractere largo ou multibyte. Por padrão, `wchar_t` é um tipo nativo, mas você pode usar [\/Zc:wchar\_t\-](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) fazer `wchar_t` um typedef para `unsigned short`. O `__wchar_t` tipo é um sinônimo de específicas da Microsoft para nativo `wchar_t` tipo.<br /><br /> Use o prefixo L antes que um caractere ou literal de cadeia de caracteres para designar o tipo de caractere largo.|  
|Ponto flutuante|`float`|Tipo `float` é flutuante menor tipo de ponto.|  
||`double`|Tipo `double` é um tipo de ponto de maior que ou igual ao tipo flutuante `float`, mas menor ou igual ao tamanho do tipo `long` `double`.<br /><br /> Específico da Microsoft: A representação de `long double` e `double` é idêntica. No entanto, `long double` e `double` são tipos separados.|  
||`long double`|Tipo `long` `double` é um tipo de ponto de maior que ou igual ao tipo flutuante `double`.|  
  
 **Específico da Microsoft**  
  
 A tabela a seguir lista a quantidade de armazenamento necessária para tipos fundamentais no Microsoft C\+\+.  
  
### Tamanhos de tipos fundamentais  
  
|Tipo|Tamanho|  
|----------|-------------|  
|`bool`, `char`, `unsigned char`, `signed char`, `__int8`|1 byte|  
|`__int16`, `short`, `unsigned short`, `wchar_t`, `__wchar_t`|2 bytes|  
|`float`, `__int32`, `int`, `unsigned int`, `long`, `unsigned long`|4 bytes|  
|`double`, `__int64`, `long double`, `long long`|8 bytes|  
  
 **FIM de específico da Microsoft**  
  
 Consulte [intervalos de tipos de dados](../cpp/data-type-ranges.md) para obter um resumo do intervalo de valores de cada tipo.  
  
 Para obter mais informações sobre conversão de tipo, consulte [conversões padrão](../cpp/standard-conversions.md).  
  
## Consulte também  
 [Intervalos de tipos de dados](../cpp/data-type-ranges.md)