---
title: Tipos fundamentais (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __int128_cpp
- __wchar_t_cpp
- char_cpp
- double_cpp
- float_cpp
- int_cpp
- long_cpp
- long_double_cpp
- short_cpp
- signed_cpp
- unsigned_cpp
- unsigned_int_cpp
- wchar_t_cpp
dev_langs:
- C++
helpviewer_keywords:
- specifiers [C++], type
- float keyword [C++]
- char keyword [C++]
- __wchar_t keyword [C++]
- signed types [C++], summary of data types
- Integer data type [C++], C++ data types
- arithmetic operations [C++], types
- int data type
- unsigned types [C++], summary of data types
- short data type [C++]
- double data type [C++], summary of types
- long long keyword [C++]
- long double keyword [C++]
- unsigned types [C++]
- signed types [C++]
- void keyword [C++]
- storage [C++], basic type
- integral types, C++
- wchar_t keyword [C++]
- floating-point numbers [C++], C++ data types
- long keyword [C++]
- type specifiers [C++]
- integral types
- long keyword [C++], C++ data types
- storing types [C++]
- data types [C++], void
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a5bd344744de39e73cd389c5592ff6794eb47c7
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405000"
---
# <a name="fundamental-types--c"></a>Tipos fundamentais (C++)
Tipos fundamentais no C++ são divididos em três categorias: integral, ponto, flutuante e void. Os tipos integrais são capazes de manipular números inteiros. Tipos de ponto flutuante são capazes de especificar valores que podem ter partes fracionárias.  
  
 O [void](../cpp/void-cpp.md) tipo descreve um conjunto vazio de valores. Nenhuma variável do tipo **void** pode ser especificada — ele é usado principalmente para declarar as funções que não retornam valores ou dados de tipo declarar ponteiros genéricos para não tipado ou arbitrariamente. Qualquer expressão pode ser explicitamente convertido ou convertido para o tipo **void**. No entanto, tais expressões estão restritas aos seguintes usos:  
  
-   Uma instrução de expressão. (Consulte [expressões](../cpp/expressions-cpp.md), para obter mais informações.)  
  
-   O operando esquerdo do operador vírgula. (Consulte [operador vírgula](../cpp/comma-operator.md) para obter mais informações.)  
  
-   O segundo ou terceiro operando do operador condicional (`? :`). (Consulte [expressões com o operador condicional](../cpp/conditional-operator-q.md) para obter mais informações.)  
  
 A tabela a seguir explica as restrições de tamanhos de tipo. Essas restrições são independentes da implementação da Microsoft.  
  
### <a name="fundamental-types-of-the-c-language"></a>Tipos fundamentais da linguagem C++  
  
|Categoria|Tipo|Conteúdo|  
|--------------|----------|--------------|  
|Integral|**char**|Tipo de **char** é um tipo integral que geralmente contém membros do conjunto de caracteres de execução básico — por padrão, esse é o ASCII no Microsoft C++.<br /><br /> O compilador do C++ trata variáveis do tipo **char**, **assinado char**, e **unsigned char** como tendo tipos diferentes. Variáveis do tipo **char** são promovidos à **int** como se fossem do tipo **assinado char** por padrão, a menos que a opção de compilação /J seja usada. Nesse caso, eles são tratados como tipo **unsigned char** e são promovidos à **int** sem extensão de sinal.|  
||**bool**|Tipo de **bool** é um tipo integral que pode ter um dos dois valores **verdadeiro** ou **false**. Seu tamanho não é especificado.|  
||**short**|Tipo de **short int** (ou simplesmente **curto**) é um tipo integral que é maior ou igual ao tamanho do tipo **char**e menor ou igual ao tamanho do tipo **int**.<br /><br /> Objetos do tipo **curto** podem ser declarados como **1&gt;signed** ou **unsigned short**. **1&gt;signed** é um sinônimo de **curto**.|  
||**int**|Tipo de **int** é um tipo integral que é maior ou igual ao tamanho do tipo **short int**e menor ou igual ao tamanho do tipo **longo**.<br /><br /> Objetos do tipo **int** podem ser declarados como **assinado int** ou **unsigned int**. **Assinado int** é um sinônimo de **int**.|  
||**__int8**, **__int16**, **__int32**, **__int64**|Inteiro dimensionado `__int n`, onde `n` é o tamanho, em bits, da variável de inteiro. **__int8**, **__int16**, **__int32** e **__int64** são palavras-chave específicas da Microsoft. Nem todos os tipos estão disponíveis em todas as arquiteturas. (**__int128** não tem suporte.)|  
||**long**|Tipo de **longo** (ou **long int**) é um tipo integral que é maior ou igual ao tamanho do tipo **int**.<br /><br /> Objetos do tipo **longo** podem ser declarados como **assinado longa** ou **unsigned long**. **Assinado longa** é um sinônimo de **longo**.|  
||**long long**|Maior do que um unsigned **longo**.<br /><br /> Objetos do tipo **long long** podem ser declarados como **assinado longo longo** ou **longo longo sem sinal**. **assinado longo longo** é um sinônimo de **long long**.|  
||**wchar_t**, **wchar_t**|Uma variável do tipo **wchar_t** designa um tipo de caractere multibyte ou caracteres largos. Por padrão, **wchar_t** é um tipo nativo, mas você pode usar [/Zc:wchar_t-](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) fazer **wchar_t** um typedef para **unsigned short**. O **wchar_t** tipo é um sinônimo de específico da Microsoft para nativo **wchar_t** tipo.<br /><br /> Use o prefixo L antes de um caractere ou literal de cadeia de caracteres para designar o tipo de caractere largo.|  
|Ponto flutuante|**float**|Tipo de **float** é flutuante menor tipo de ponto.|  
||**double**|Tipo de **duplas** é um tipo de ponto flutuante que é maior que ou igual ao tipo **float**, mas menor ou igual ao tamanho do tipo **longo duplo**.<br /><br /> Específico da Microsoft: A representação de **longo duplo** e **duplo** é idêntico. No entanto, **longo duplo** e **duplo** são tipos separados.|  
||**long double**|Tipo de **longo duplo** é um tipo de ponto que é maior que ou igual ao tipo flutuante **duplo**.|  
  
 **Seção específica da Microsoft**  
  
 A tabela a seguir lista a quantidade de armazenamento necessária para tipos fundamentais no Microsoft C++.  
  
### <a name="sizes-of-fundamental-types"></a>Tamanhos de tipos fundamentais  
  
|Tipo|Tamanho|  
|----------|----------|  
|**bool**, **char**, **unsigned char**, **assinado char**, **__int8**|1 byte|  
|**__int16**, **curto**, **unsigned short**, **wchar_t**, **wchar_t**|2 bytes|  
|**float**, **__int32**, **int**, **unsigned int**, **long**, **unsigned long**|4 bytes|  
|**duplo**, **__int64**, **long double**, **long long**|8 bytes|  
  
 **Fim da seção específica da Microsoft**  
  
 Ver [intervalos de tipos de dados](../cpp/data-type-ranges.md) para obter um resumo do intervalo de valores de cada tipo.  
  
 Para obter mais informações sobre conversão de tipo, consulte [conversões padrão](../cpp/standard-conversions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Intervalos de tipos de dados](../cpp/data-type-ranges.md)