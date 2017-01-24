---
title: "&lt;locale&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<locale>"
  - "std.<locale>"
  - "locale/std::<locale>"
  - "std::<locale>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho locale"
ms.assetid: ca56f9d2-7128-44da-8df1-f4c78c17fbf2
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;locale&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define funções e classes de modelo que os programas C\+\+ podem usar para encapsular e manipular as diferentes convenções culturais em relação à representação e formatação de dados numéricos, monetários e de calendário, incluindo suporte à internacionalização para classificação de caracteres e agrupamento de cadeias de caracteres.  
  
## Sintaxe  
  
```  
  
#include <locale>  
  
```  
  
### Funções  
  
|||  
|-|-|  
|[has\_facet](../Topic/has_facet.md)|Testa se uma determinada faceta é armazenada em uma localidade especificada.|  
|[isalnum](../Topic/isalnum.md)|Testa se um elemento em uma localidade é um caractere alfabético ou numérico.|  
|[isalpha](../Topic/isalpha.md)|Testa se um elemento em uma localidade é um caractere alfabético.|  
|[iscntrl](../Topic/iscntrl.md)|Testa se um elemento em uma localidade é um caractere de controle.|  
|[isdigit](../Topic/isdigit.md)|Testa se um elemento em uma localidade é um caractere numérico.|  
|[isgraph](../Topic/isgraph.md)|Testa se um elemento em uma localidade é um caractere alfanumérico ou de pontuação.|  
|[islower](../Topic/islower.md)|Testa se um elemento em uma localidade está em letras minúsculas.|  
|[isprint](../Topic/isprint.md)|Testa se um elemento em uma localidade é um caractere imprimível.|  
|[ispunct](../Topic/ispunct.md)|Testa se um elemento em uma localidade é um caractere de pontuação.|  
|[isspace](../Topic/isspace.md)|Testa se um elemento em uma localidade é um caractere de espaço em branco.|  
|[isupper](../Topic/isupper.md)|Testa se um elemento em uma localidade está em letras maiúsculas.|  
|[isxdigit](../Topic/isxdigit.md)|Testa se um elemento em uma localidade é um caractere usado para representar um número hexadecimal.|  
|[tolower](../Topic/tolower.md)|Converte um caractere em letra minúscula.|  
|[toupper](../Topic/toupper.md)|Converte um caractere em letra maiúscula.|  
|[use\_facet](../Topic/use_facet.md)|Retorna uma referência para uma faceta de um tipo especificado armazenada em uma localidade.|  
  
### Classes  
  
|||  
|-|-|  
|[codecvt](../standard-library/codecvt-class.md)|Uma classe de modelo que fornece uma faceta usada para conversão entre codificações de caractere internas e externas.|  
|[codecvt\_base](../standard-library/codecvt-base-class.md)|Uma classe base para a classe codecvt que é usada para definir um tipo de enumeração referenciado como **result**, usado como o tipo de retorno para as funções membro de faceta para indicar o resultado de uma conversão.|  
|[codecvt\_byname](../Topic/codecvt_byname%20Class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a conversões.|  
|[collate](../standard-library/collate-class.md)|Uma classe de modelo de agrupamento que fornece uma faceta que trata convenções de classificação de cadeia de caracteres.|  
|[collate\_byname](../Topic/collate_byname%20Class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a convenções de classificação de cadeia de caracteres.|  
|[ctype](../standard-library/ctype-class.md)|Uma classe de modelo que fornece uma faceta usada para classificar caracteres, fazer conversões de letras maiúsculas e minúsculas, bem como entre o conjunto de caracteres nativos e o conjunto usado pela localidade.|  
|[ctype\<char\>](../standard-library/ctype-char-class.md)|Uma classe que é uma especialização explícita da classe de modelo **ctype \< CharType**\> digitar `char`, que descreve um objeto que pode servir como uma faceta de localidade para caracterizar várias propriedades de um caractere do tipo `char`.|  
|[ctype\_base](../standard-library/ctype-base-class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|  
|[ctype\_byname](../standard-library/ctype-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta ctype de uma determinada localidade, permitindo a classificação de caracteres e a conversão de caracteres entre letras maiúsculas e minúsculas, assim como entre conjuntos de caracteres especificados de localidade e nativos.|  
|[localidade](../standard-library/locale-class.md)|Uma classe que descreve um objeto de localidade que encapsula informações específicas à cultura como um conjunto de facetas que definem coletivamente um ambiente localizado específico.|  
|[messages](../standard-library/messages-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para recuperar mensagens localizadas em um catálogo de mensagens internacionalizadas de uma determinada localidade.|  
|[messages\_base](../Topic/messages_base%20Class.md)|Uma classe base que descreve um tipo `int` do catálogo de mensagens.|  
|[messages\_byname](../standard-library/messages-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de mensagem de uma determinada localidade, permitindo a recuperação das mensagens localizadas.|  
|[money\_base](../Topic/money_base%20Class.md)|Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.|  
|[money\_get](../standard-library/money-get-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** em valores monetários.|  
|[money\_put](../standard-library/money-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores monetários em sequências do tipo **CharType**.|  
|[moneypunct](../Topic/moneypunct%20Class.md)|Uma classe de modelo que descreve um objeto que pode funcionar como uma faceta de localidade para descrever as sequências do tipo **CharType** usadas para representar um campo de entrada monetário ou um campo de saída monetário.|  
|[moneypunct\_byname](../standard-library/moneypunct-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta moneypunct de uma determinada localidade, permitindo a formatação de campos de entrada ou saída monetários.|  
|[num\_get](../Topic/num_get%20Class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** em valores numéricos.|  
|[num\_put](../standard-library/num-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores numéricos em sequências do tipo **CharType**.|  
|[numpunct](../standard-library/numpunct-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de local para descrever as sequências do tipo **CharType** usadas para representar informações sobre a formatação e pontuação de expressões numéricas e boolianas.|  
|[numpunct\_byname](../standard-library/numpunct-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta moneypunct de uma determinada localidade, permitindo a formatação e pontuação de expressões numéricas e boolianas.|  
|[time\_base](../Topic/time_base%20Class.md)|Uma classe que serve como uma classe base para facetas da classe de modelo time\_get, definindo apenas o tipo enumerado dateorder e várias constantes desse tipo.|  
|[time\_get](../standard-library/time-get-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo **CharType** em valores de tempo.|  
|[time\_get\_byname](../standard-library/time-get-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode servir como uma faceta de localidade do tipo time\_get \<**CharType**, **InputIterator**\>.|  
|[time\_put](../standard-library/time-put-class.md)|Uma classe de modelo que descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de valores de tempo em sequências do tipo **CharType**.|  
|[time\_put\_byname](../standard-library/time-put-byname-class.md)|Uma classe de modelo derivada que descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put`\<**CharType**, **OutputIterator**\>.|  
|[Classe wbuffer\_convert](../standard-library/wbuffer-convert-class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos em um buffer de fluxo de bytes.|  
|[Classe wstring\_convert](../standard-library/wstring-convert-class.md)|Uma classe de modelo que executa conversões entre uma cadeia de caracteres larga e uma cadeia de caracteres de byte.|  
  
## Consulte também  
 [Páginas de código](../c-runtime-library/code-pages.md)   
 [Nomes de localidades, idiomas e cadeias de caracteres de país\/região](../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)