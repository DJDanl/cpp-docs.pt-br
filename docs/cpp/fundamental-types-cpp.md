---
title: Tipos fundamentais (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __wchar_t_cpp
- long_double_cpp
- unsigned
- wchar_t_cpp
- float_cpp
- wchar_t
- char
- char_cpp
- signed
- __wchar_t
- signed_cpp
- short
- double_cpp
- int_cpp
- long
- __intn_cpp
- short_cpp
- double
- unsigned_cpp
- float
- __intn
- long_cpp
- int
- long_double
- unsigned_int
- __int8
- __int8_cpp
- __int16
- __int16_cpp
- __int32
- __int32_cpp
- __int64
- __int64_cpp
- __int128
- __int128_cpp
dev_langs:
- C++
helpviewer_keywords:
- specifiers [C++], type
- float keyword [C++]
- char keyword [C++]
- __wchar_t keyword [C++]
- signed types [C++], summary of data types
- Integer data type, C++ data types
- arithmetic operations [C++], types
- int data type
- unsigned types [C++], summary of data types
- short data type
- double data type, summary of types
- long long keyword [C++]
- long double keyword [C++]
- unsigned types [C++]
- signed types [C++]
- void keyword [C++]
- storage [C++], basic type
- integral types, C++
- wchar_t keyword [C++]
- floating-point numbers, C++ data types
- long keyword [C++]
- type specifiers [C++]
- integral types
- long keyword [C++], C++ data types
- storing types [C++]
- data types [C++], void
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 595c2d84ad18cae0c15ddba36388f66f10fecd49
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="fundamental-types--c"></a>Tipos fundamentais (C++)
Tipos fundamentais em C++ são divididos em três categorias: integral, ponto, flutuante e void. Os tipos integrais são capazes de manipular números inteiros. Tipos de ponto flutuante são capazes de especificar os valores que podem ter partes fracionários.  
  
 O [void](../cpp/void-cpp.md) tipo descreve um conjunto vazio de valores. Nenhuma variável do tipo `void` pode ser especificada — ele é usado basicamente para declarar funções que não retornam nenhum valor ou para declarar ponteiros genéricos para dados não tipados ou tipados arbitrariamente. Qualquer expressão pode ser explicitamente convertida no tipo `void`. No entanto, tais expressões estão restritas aos seguintes usos:  
  
-   Uma instrução de expressão. (Consulte [expressões](../cpp/expressions-cpp.md), para obter mais informações.)  
  
-   O operando esquerdo do operador vírgula. (Consulte [operador vírgula](../cpp/comma-operator.md) para obter mais informações.)  
  
-   O segundo ou terceiro operando do operador condicional (`? :`). (Consulte [expressões com o operador condicional](../cpp/conditional-operator-q.md) para obter mais informações.)  
  
 A tabela a seguir explica as restrições de tamanhos de tipo. Essas restrições são independentes da implementação da Microsoft.  
  
### <a name="fundamental-types-of-the-c-language"></a>Tipos fundamentais da linguagem C++  
  
|Categoria|Tipo|Conteúdo|  
|--------------|----------|--------------|  
|Integral|`char`|Tipo `char` é um tipo integral que geralmente contém membros do conjunto de caracteres de execução básico — por padrão, isso é ASCII em C++ da Microsoft.<br /><br /> O compilador do C++ trata variáveis do tipo `char`, `signed` `char`, e `unsigned` `char` têm tipos diferentes. Variáveis do tipo `char` são promovidos para `int` como se fossem tipo `signed` `char` por padrão, a menos que a opção de compilação /J é usada. Nesse caso, eles são tratados como tipo `unsigned` `char` e são promovidos para `int` sem extensão de entrada.|  
||`bool`|Tipo `bool` é um tipo integral que pode ter um dos dois valores `true` ou `false`. Seu tamanho não é especificado.|  
||`short`|Tipo `short` `int` (ou simplesmente `short`) é um tipo integral que seja maior ou igual ao tamanho do tipo `char`e menor que ou igual ao tamanho do tipo `int`.<br /><br /> Objetos do tipo `short` podem ser declarados como `signed` `short` ou `unsigned short`. `Signed short`é um sinônimo para `short`.|  
||`int`|Tipo `int` é um tipo integral que seja maior ou igual ao tamanho do tipo `short` `int`e menor que ou igual ao tamanho do tipo `long`.<br /><br /> Objetos do tipo `int` podem ser declarados como `signed` `int` ou `unsigned` `int`. `Signed``int` é um sinônimo para `int`.|  
||`__int8`, `__int16`, `__int32`, `__int64`|Inteiros dimensionados `__int n`, onde `n` é o tamanho, em bits, da variável de inteiro. `__int8`, `__int16`, `__int32` e `__int64` são palavras-chave específicas da Microsoft. Nem todos os tipos estão disponíveis em todas as arquiteturas. `(__int128`Não há suporte.)|  
||`long`|Tipo `long` (ou `long` `int`) é um tipo integral que seja maior ou igual ao tamanho do tipo `int`.<br /><br /> Objetos do tipo `long` podem ser declarados como `signed` `long` ou `unsigned` `long`. `Signed``long` é um sinônimo para `long`.|  
||`long` `long`|Maior do que sem um sinal `long`.<br /><br /> Objetos do tipo `long long` podem ser declarados como `signed` `long long` ou `unsigned` `long long`. `Signed``long long` é um sinônimo para `long long`.|  
||`wchar_t`, `__wchar_t`|Uma variável do tipo `wchar_t` designa um tipo de caracteres multibyte ou de caractere largo. Por padrão, `wchar_t` é um tipo nativo, mas você pode usar [/Zc:wchar_t-](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) fazer `wchar_t` um typedef para `unsigned short`. O `__wchar_t` tipo é um sinônimo específicas da Microsoft para o nativo `wchar_t` tipo.<br /><br /> Use o prefixo L antes de um caractere ou uma cadeia de caracteres literal para designar o tipo de caractere largo.|  
|Ponto flutuante|`float`|Tipo `float` é flutuante menor tipo de ponto.|  
||`double`|Tipo `double` é um tipo de ponto que é maior que ou igual ao tipo flutuante `float`, mas menor que ou igual ao tamanho do tipo `long` `double`.<br /><br /> Específico da Microsoft: A representação de `long double` e `double` é idêntica. No entanto, `long double` e `double` são tipos separados.|  
||`long double`|Tipo `long` `double` é um tipo de ponto que é maior que ou igual ao tipo flutuante `double`.|  
  
 **Seção específica da Microsoft**  
  
 A tabela a seguir lista a quantidade de armazenamento necessária para tipos fundamentais no Microsoft C++.  
  
### <a name="sizes-of-fundamental-types"></a>Tamanhos de tipos fundamentais  
  
|Tipo|Tamanho|  
|----------|----------|  
|`bool`, `char`, `unsigned char`, `signed char`, `__int8`|1 byte|  
|`__int16`, `short`, `unsigned short`, `wchar_t`, `__wchar_t`|2 bytes|  
|`float`, `__int32`, `int`, `unsigned int`, `long`, `unsigned long`|4 bytes|  
|`double`, `__int64`, `long double`, `long long`|8 bytes|  
  
 **Fim da seção específica da Microsoft**  
  
 Consulte [intervalos de tipos de dados](../cpp/data-type-ranges.md) para obter um resumo do intervalo de valores de cada tipo.  
  
 Para obter mais informações sobre conversão de tipo, consulte [conversões padrão](../cpp/standard-conversions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Intervalos de tipos de dados](../cpp/data-type-ranges.md)
