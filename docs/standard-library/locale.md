---
title: '&lt;localidade&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <locale>
- locale/std::<locale>
- std::<locale>
dev_langs: C++
helpviewer_keywords: locale header
ms.assetid: ca56f9d2-7128-44da-8df1-f4c78c17fbf2
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b2b617870bdeec43dcdc9bf5d9031c0c4d78d0aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ltlocalegt"></a>&lt;locale&gt;
Define funções e classes de modelo que os programas C++ podem usar para encapsular e manipular as diferentes convenções culturais em relação à representação e formatação de dados numéricos, monetários e de calendário, incluindo suporte à internacionalização para classificação de caracteres e agrupamento de cadeias de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <locale>  
  
```  
  
### <a name="functions"></a>Funções  
  
|||  
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
  
|||  
|-|-|  
|[codecvt](../standard-library/codecvt-class.md)|Uma classe de modelo que fornece uma faceta usada para conversão entre codificações de caractere internas e externas.|  
|[codecvt_base](../standard-library/codecvt-base-class.md)|Uma classe base da classe codecvt usada para definir um tipo de enumeração referenciado como **result**, usado como o tipo de retorno para as funções membro de faceta para indicar o resultado de uma conversão.|  
|[codecvt_byname](../standard-library/codecvt-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a conversões.|  
|[collate](../standard-library/collate-class.md)|Uma classe de modelo de agrupamento que fornece uma faceta que trata convenções de classificação de cadeia de caracteres.|  
|[collate_byname](../standard-library/collate-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a convenções de classificação de cadeia de caracteres.|  
|[ctype](../standard-library/ctype-class.md)|Uma classe de modelo que fornece uma faceta usada para classificar caracteres, fazer conversões de letras maiúsculas e minúsculas, bem como entre o conjunto de caracteres nativos e o conjunto usado pela localidade.|  
|[CType\<char >](../standard-library/ctype-char-class.md)|Uma classe que é uma especialização explícita da classe de modelo **ctype\<CharType**> para o tipo `char`, que descreve um objeto que pode servir como uma faceta de localidade para caracterizar a várias propriedades de um caractere de tipo `char`.|  
|[ctype_base](../standard-library/ctype-base-class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|  
|[ctype_byname](../standard-library/ctype-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta ctype de uma determinada localidade, permitindo a classificação de caracteres e a conversão de caracteres entre letras maiúsculas e minúsculas, assim como entre conjuntos de caracteres especificados de localidade e nativos.|  
|[locale](../standard-library/locale-class.md)|Uma classe que descreve um objeto de localidade que encapsula informações específicas à cultura como um conjunto de facetas que definem coletivamente um ambiente localizado específico.|  
|[messages](../standard-library/messages-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para recuperar mensagens localizadas em um catálogo de mensagens internacionalizadas de uma determinada localidade.|  
|[messages_base](../standard-library/messages-base-class.md)|Uma classe base que descreve um tipo `int` do catálogo de mensagens.|  
|[messages_byname](../standard-library/messages-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de mensagem de uma determinada localidade, permitindo a recuperação das mensagens localizadas.|  
|[money_base](../standard-library/money-base-class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|  
|[money_get](../standard-library/money-get-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de sequências de tipo **CharType** para valores monetários.|  
|[money_put](../standard-library/money-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de valores monetários para sequências de tipo **CharType**.|  
|[moneypunct](../standard-library/moneypunct-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para descrever as sequências de tipo **CharType** usado para representar um campo de entrada monetário ou de saída monetário.|  
|[moneypunct_byname](../standard-library/moneypunct-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta moneypunct de uma determinada localidade, permitindo a formatação de campos de entrada ou saída monetários.|  
|[num_get](../standard-library/num-get-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de sequências de tipo **CharType** para valores numéricos.|  
|[num_put](../standard-library/num-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de valores numéricos para sequências de tipo **CharType**.|  
|[numpunct](../standard-library/numpunct-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta local para descrever as sequências de tipo **CharType** usado para representar informações sobre a formatação e a pontuação de expressões numéricas e Boolianas.|  
|[numpunct_byname](../standard-library/numpunct-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta moneypunct de uma determinada localidade, permitindo a formatação e pontuação de expressões numéricas e boolianas.|  
|[time_base](../standard-library/time-base-class.md)|Uma classe que serve como uma classe base para facetas da classe de modelo time_get, definindo apenas o tipo enumerado dateorder e várias constantes desse tipo.|  
|[time_get](../standard-library/time-get-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de sequências de tipo **CharType** para valores de tempo.|  
|[time_get_byname](../standard-library/time-get-byname-class.md)|Uma classe derivada de modelo que descreve um objeto que pode servir como uma faceta de localidade do tipo time_get\<**CharType**, **InputIterator**>.|  
|[time_put](../standard-library/time-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar as conversões de valores de hora para sequências de tipo **CharType**.|  
|[time_put_byname](../standard-library/time-put-byname-class.md)|Uma classe derivada de modelo que descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put` \< **CharType**, **OutputIterator**>.|  
|[Classe wbuffer_convert](../standard-library/wbuffer-convert-class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos de/para um buffer de fluxo de bytes.|  
|[Classe wstring_convert](../standard-library/wstring-convert-class.md)|Uma classe de modelo que executa conversões entre uma cadeia de caracteres longa e uma cadeia de caracteres de byte.|  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de código](../c-runtime-library/code-pages.md)   
 [Nomes de localidade, idiomas e cadeias de caracteres de país/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



