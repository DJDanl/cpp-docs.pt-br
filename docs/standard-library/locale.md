---
title: '&lt;locale&gt;'
ms.date: 11/04/2016
f1_keywords:
- <locale>
- locale/std::<locale>
- std::<locale>
helpviewer_keywords:
- locale header
ms.assetid: ca56f9d2-7128-44da-8df1-f4c78c17fbf2
ms.openlocfilehash: 71182f4a527fba0ef2c91dc84be5a8faad9fc99f
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687805"
---
# <a name="ltlocalegt"></a>&lt;locale&gt;

Define modelos e funções de classe C++ que os programas podem usar para encapsular e manipular diferentes convenções culturais em relação à representação e formatação de dados numéricos, Monetários e calendric, incluindo suporte à internacionalização para classificação de caracteres e agrupamento de cadeias de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
#include <locale>
```

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[has_facet](../standard-library/locale-functions.md#has_facet)|Testa se uma determinada faceta é armazenada em uma localidade especificada.|
|[isalnum](../standard-library/locale-functions.md#isalnum)|Testa se um elemento em uma localidade é um caractere alfabético ou numérico.|
|[isalpha](../standard-library/locale-functions.md#isalpha)|Testa se um elemento em uma localidade é um caractere alfabético.|
|[iscntrl](../standard-library/locale-functions.md#iscntrl)|Testa se um elemento em uma localidade é um caractere de controle.|
|[isdigit](../standard-library/locale-functions.md#isdigit)|Testa se um elemento em uma localidade é um caractere numérico.|
|[isgraph](../standard-library/locale-functions.md#isgraph)|Testa se um elemento em uma localidade é um caractere alfanumérico ou de pontuação.|
|[islower](../standard-library/locale-functions.md#islower)|Testa se um elemento em uma localidade está em letras minúsculas.|
|[isprint](../standard-library/locale-functions.md#isprint)|Testa se um elemento em uma localidade é um caractere imprimível.|
|[ispunct](../standard-library/locale-functions.md#ispunct)|Testa se um elemento em uma localidade é um caractere de pontuação.|
|[isspace](../standard-library/locale-functions.md#isspace)|Testa se um elemento em uma localidade é um caractere de espaço em branco.|
|[isupper](../standard-library/locale-functions.md#isupper)|Testa se um elemento em uma localidade está em letras maiúsculas.|
|[isxdigit](../standard-library/locale-functions.md#isxdigit)|Testa se um elemento em uma localidade é um caractere usado para representar um número hexadecimal.|
|[tolower](../standard-library/locale-functions.md#tolower)|Converte um caractere em letra minúscula.|
|[toupper](../standard-library/locale-functions.md#toupper)|Converte um caractere em letra maiúscula.|
|[use_facet](../standard-library/locale-functions.md#use_facet)|Retorna uma referência para uma faceta de um tipo especificado armazenada em uma localidade.|

### <a name="classes"></a>Classes

|Class|Descrição|
|-|-|
|[codecvt](../standard-library/codecvt-class.md)|Um modelo de classe que fornece uma faceta usada para converter entre codificações de caracteres internas e externas.|
|[codecvt_base](../standard-library/codecvt-base-class.md)|Uma classe base para a classe codecvt que é usada para definir um tipo de enumeração referido como `result`, usada como o tipo de retorno para as funções de membro da faceta para indicar o resultado de uma conversão.|
|[codecvt_byname](../standard-library/codecvt-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas para uma área cultural em relação a conversões.|
|[collate](../standard-library/collate-class.md)|Um modelo de classe COLLATE que fornece uma faceta que lida com convenções de classificação de cadeias de caracteres.|
|[collate_byname](../standard-library/collate-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas para uma área cultural relacionada a convenções de classificação de cadeias de caracteres.|
|[ctype](../standard-library/ctype-class.md)|Um modelo de classe que fornece uma faceta que é usada para classificar caracteres, converter de letras maiúsculas e minúsculas e entre o conjunto de caracteres nativo e o conjunto usado pela localidade.|
|[CType \<char >](../standard-library/ctype-char-class.md)|Uma classe que é uma especialização explícita do modelo de classe `ctype<CharType>` para o tipo **Char**, descrevendo um objeto que pode servir como uma faceta de localidade para caracterizar várias propriedades de um caractere do tipo **Char**.|
|[ctype_base](../standard-library/ctype-base-class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|
|[ctype_byname](../standard-library/ctype-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta CType de uma determinada localidade, habilitando a classificação de caracteres e a conversão de caracteres entre os conjuntos de caracteres de maiúsculas e minúsculas e os especificados na localidade.|
|[locale](../standard-library/locale-class.md)|Uma classe que descreve um objeto de localidade que encapsula informações específicas à cultura como um conjunto de facetas que definem coletivamente um ambiente localizado específico.|
|[messages](../standard-library/messages-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para recuperar mensagens localizadas de um catálogo de mensagens internacionalizadas para uma determinada localidade.|
|[messages_base](../standard-library/messages-base-class.md)|Uma classe base que descreve um tipo **int** para o catálogo de mensagens.|
|[messages_byname](../standard-library/messages-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de mensagem de determinada localidade, habilitando a recuperação de mensagens localizadas.|
|[money_base](../standard-library/money-base-class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|
|[money_get](../standard-library/money-get-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** como valores monetários.|
|[money_put](../standard-library/money-put-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores monetários para sequências do tipo **CharType**.|
|[moneypunct](../standard-library/moneypunct-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para descrever as sequências do tipo **CharType** usado para representar um campo de entrada monetário ou um campo de saída monetária.|
|[moneypunct_byname](../standard-library/moneypunct-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta moneypunct de uma determinada localidade habilitando os campos de entrada ou saída monetárias de formatação.|
|[num_get](../standard-library/num-get-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** para valores numéricos.|
|[num_put](../standard-library/num-put-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores numéricos em sequências do tipo **CharType**.|
|[numpunct](../standard-library/numpunct-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta local para descrever as sequências do tipo **CharType** usado para representar informações sobre a formatação e a pontuação de expressões numéricas e booleanas.|
|[numpunct_byname](../standard-library/numpunct-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta moneypunct de uma determinada localidade, permitindo a formatação e a pontuação de expressões numéricas e booleanas.|
|[time_base](../standard-library/time-base-class.md)|Uma classe que serve como classe base para facetas do modelo de classe time_get, definindo apenas o tipo enumerado dateorder e várias constantes desse tipo.|
|[time_get](../standard-library/time-get-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** para valores de tempo.|
|[time_get_byname](../standard-library/time-get-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de localidade do tipo time_get \<**CharType**, **InputIterator**>.|
|[time_put](../standard-library/time-put-class.md)|Um modelo de classe que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores de tempo para sequências do tipo **CharType**.|
|[time_put_byname](../standard-library/time-put-byname-class.md)|Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put` \<**CharType**, **OutputIterator**>.|
|[Classe wbuffer_convert](../standard-library/wbuffer-convert-class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos de/para um buffer de fluxo de bytes.|
|[Classe wstring_convert](../standard-library/wstring-convert-class.md)|Um modelo de classe que executa conversões entre uma cadeia de caracteres larga e uma cadeia de caracteres de byte.|

## <a name="see-also"></a>Consulte também

[Páginas de código](../c-runtime-library/code-pages.md)\
[Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
