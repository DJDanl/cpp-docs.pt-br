---
title: Tipos internos (C++)
ms.date: 12/11/2019
f1_keywords:
- __int128_cpp
- __wchar_t_cpp
- char_cpp
- char8_t_cpp
- char16_t_cpp
- char32_t_cpp
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
- long keyword [C++]
- storing types [C++]
- data types [C++], void
ms.assetid: 58b0106a-0406-4b74-a430-7cbd315c0f89
ms.openlocfilehash: e67d31e18ebbb6afd9d98542e4a6aa236b2d3e71
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445314"
---
# <a name="built-in-types-c"></a>Tipos internos (C++)

Os C++ tipos internos (também chamados de *tipos fundamentais*) são especificados pelo idioma padrão e são criados no compilador. Os tipos internos não são definidos em nenhum arquivo de cabeçalho. Os tipos internos são divididos em três categorias: integral, ponto flutuante e nulo. Os tipos integrais são capazes de manipular números inteiros. Os tipos de ponto flutuante são capazes de especificar valores que podem ter partes fracionárias.

O tipo [void](void-cpp.md) descreve um conjunto vazio de valores. Nenhuma variável do tipo **void** pode ser especificada — ela é usada principalmente para declarar funções que não retornam valores ou para declarar ponteiros genéricos para dados tipados sem tipo ou arbitrariamente. Qualquer expressão pode ser convertida explicitamente ou converter para o tipo **void**. No entanto, tais expressões estão restritas aos seguintes usos:

- Uma instrução de expressão. (Para obter mais informações, consulte [Expressions](expressions-cpp.md).)

- O operando esquerdo do operador vírgula. (Para obter mais informações, consulte [operador de vírgula](comma-operator.md).)

- O segundo ou terceiro operando do operador condicional (`? :`). (Para obter mais informações, consulte [expressões com o operador condicional](conditional-operator-q.md).)

A tabela a seguir explica as restrições de tamanhos de tipo em relação umas com as outras. Essas restrições são obrigatórias pelo C++ padrão e são independentes da implementação da Microsoft. O tamanho absoluto de determinados tipos internos não é especificado no padrão.

### <a name="built-in-type-size-restrictions"></a>Restrições de tamanho de tipo interno

|Categoria|Tipo|{1&gt;Conteúdo&lt;1}|
|--------------|----------|--------------|
|Integral|**char**|Tipo **Char** é um tipo integral que geralmente contém membros do conjunto de caracteres de execução básica — por padrão, isso é ASCII na C++Microsoft.<br /><br /> O C++ compilador trata variáveis do tipo **Char**, **sinal assinado**e **caractere não assinado** como tendo tipos diferentes. Variáveis do tipo **Char** são promovidas para **int** como se fossem **caracteres assinados** por tipo por padrão, a menos que a opção de compilação/j seja usada. Nesse caso, eles são tratados como tipo de **caractere não assinado** e são promovidos para **int** sem a extensão de assinatura.|
||**bool**|O tipo **bool** é um tipo integral que pode ter um dos dois valores **true** ou **false**. Seu tamanho não é especificado.|
||**short**|Digite **int Short** (ou simplesmente **Short**) é um tipo integral maior ou igual ao tamanho do tipo **Char**e menor que ou igual ao tamanho do tipo **int**.<br /><br /> Objetos do tipo **Short** podem ser declarados como **assinados** de forma curta ou **sem sinal**. A **assinatura curta** é um sinônimo de **curto**.|
||**int**|O tipo **int** é um tipo integral que é maior ou igual ao tamanho do tipo **int inteiro**e menor que ou igual ao tamanho do tipo **Long**.<br /><br /> Objetos do tipo **int** podem ser declarados como **int assinados** ou **não assinados**. **Int assinado** é um sinônimo para **int**.|
||**__int8**, **__int16**, **__int32** **__int64**|`__int n`inteiro dimensionado, em que `n` é o tamanho, em bits, da variável de inteiro. **__int8**, **__int16**, **__int32** e **__Int64** são palavras-chave específicas da Microsoft. Nem todos os tipos estão disponíveis em todas as arquiteturas. (não há suporte para **__int128** .)|
||**long**|Tipo **Long** (ou **Long int**) é um tipo integral maior ou igual ao tamanho do tipo **int**. (No Windows **Long** tem o mesmo tamanho que **int**.)<br /><br /> Objetos do tipo **Long** podem ser declarados como **assinados** longos ou **não**assinados. O **Long assinado** é um sinônimo de **longo**.|
||**long long**|Maior que um **longo**não assinado.<br /><br /> Objetos do tipo **longo** longo podem ser declarados como **assinados** longos longos ou **não assinados**longos. um **longo tempo assinado** é um sinônimo por **longos**longos.|
||**wchar_t**, **__wchar_t**|Uma variável do tipo **wchar_t** designa um tipo de caractere largo ou multibyte. Por padrão, **wchar_t** é um tipo nativo, mas você pode usar [/Zc: wchar_t-](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para fazer **wchar_t** um typedef para **não assinado**. O tipo de **__wchar_t** é um sinônimo específico da Microsoft para o tipo de **wchar_t** nativo.<br /><br /> Use o prefixo L antes de um literal de caractere ou de cadeia de caracteres para designar o tipo de caractere largo.|
|Ponto flutuante|**float**|O tipo **float** é o menor tipo de ponto flutuante.|
||**double**|Tipo **Double** é um tipo de ponto flutuante que é maior ou igual ao tipo **float**, mas menor que ou igual ao tamanho do tipo **Long double**.<br /><br /> Específico da Microsoft: a representação de **Long double** e **Double** é idêntica. No entanto, **Long double** e **Double** são tipos separados.|
||**long double**|Tipo **Long double** é um tipo de ponto flutuante que é maior ou igual ao tipo **Double**.|

**Seção específica da Microsoft**

A tabela a seguir lista a quantidade de armazenamento necessária para tipos internos no Microsoft C++. Em particular, observe que **Long** é de 4 bytes mesmo em sistemas operacionais de 64 bits.

### <a name="sizes-of-built-in-types"></a>Tamanhos de tipos internos

|Tipo|Size|
|----------|----------|
|**bool**, **Char**, **Char não assinado**, **signed char**, **__int8**|1 byte|
|**__int16**, **curto**, **sem sinal**, **wchar_t**, **__wchar_t**|2 bytes|
|**float**, **__int32**, **int**, **não assinado int**, **Long**, **longo não assinado**|4 bytes|
|**Double**, **__int64**, **longa dupla**, **longa longa**|8 bytes|

**Fim da seção específica da Microsoft**

Consulte [intervalos de tipos de dados](data-type-ranges.md) para obter um resumo do intervalo de valores de cada tipo.

Para obter mais informações sobre conversão de tipo, consulte [conversões padrão](standard-conversions.md).

## <a name="see-also"></a>Consulte também

[Intervalos de tipos de dados](data-type-ranges.md)