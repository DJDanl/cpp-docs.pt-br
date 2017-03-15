---
title: Caracteres de campo de tipo printf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr100.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr80.dll
- msvcr90.dll
apitype: DLLExport
dev_langs:
- C++
helpviewer_keywords:
- printf function, format specification fields
- printf function, type field characters
ms.assetid: 699cb438-cd14-402e-9f81-c7a32acc3317
caps.latest.revision: 15
author: corob-msft
ms.author: corob
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c0ba5b4af699557bf97340c50185572aadce85d0
ms.lasthandoff: 02/25/2017

---
# <a name="printf-type-field-characters"></a>Caracteres de campo de tipo printf
Em uma especificação de formato, o caractere `type` é um especificador de conversão que diz se o argumento correspondente deve ser interpretado como um caractere, uma cadeia de caracteres, um ponteiro, um inteiro ou um número de ponto flutuante. O caractere `type` é o único campo de especificação de formato necessário, e aparece depois de quaisquer campos opcionais.  
  
 Os argumentos que seguem o formato cadeia de caracteres são interpretados de acordo com o caractere `type` correspondente e o prefixo [size](../c-runtime-library/size-specification.md) opcional. As conversões dos tipos de caracteres `char` e `wchar_t` são especificadas usando `c` ou `C`, e as cadeias de caracteres de byte único e vários bytes ou de caracteres largos são especificadas usando `s` ou `S`, dependendo de qual função de formatação está sendo usada. Argumentos de caractere e de cadeia de caracteres que são especificados usando `c` e `s` são interpretados como `char` e `char*` pelas funções da família `printf`, ou como `wchar_t` e `wchar_t*` pelas funções da família `wprintf`. Argumentos de caractere e de cadeia de caracteres que são especificados usando `C` e `S` são interpretados como `wchar_t` e `wchar_t*` pelas funções da família `printf`, ou como `char` e `char*` pelas funções da família `wprintf`.  
  
 Tipos de inteiro como `short`, `int`, `long`, `long long` e suas variações `unsigned`, são especificados usando `d`, `i`, `o`, `u`, `x` e `X`. Tipos de ponto flutuante como `float`, `double` e `long double` são especificados usando `a`, `A`, `e`, `E`, `f`, `g` e `G`. Por padrão, a menos que sejam modificados por um prefixo de tamanho de campo `size`, os argumentos inteiros são forçados para o tipo `int`, e argumentos de ponto flutuante são forçados a `double`. Em sistemas de 64 bits, um `int` é um valor de 32 bits; portanto, inteiros de 64 bits serão truncados quando forem formatados para saída, a menos que um prefixo `size` de `ll` ou `I64` seja usado. Tipos de ponteiro que são especificados por `p` usam o tamanho padrão para a plataforma.  
  
> [!NOTE]
>  Os caracteres de tipo `C`, `S` e `Z`, e o comportamento dos caracteres de tipo `c` e `s`, quando são usados com as funções `printf` e `wprintf`, são extensões da Microsoft e não são compatíveis com ANSI. O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] não oferece suporte ao caractere de tipo `F`.  
  
### <a name="printf-type-field-characters"></a>Caracteres de campo de tipo printf  
  
|Caractere de tipo|Argumento|Formato de saída|  
|--------------------|--------------|-------------------|  
|`c`|Caractere|Quando usado com funções `printf`, especifica um caractere de byte único; quando usado com funções `wprintf`, especifica um caractere largo.|  
|`C`|Caractere|Quando usado com funções `printf`, especifica um caractere largo; quando usado com funções `wprintf`, especifica um caractere de byte único.|  
|`d`|Inteiro|Inteiro decimal assinado.|  
|`i`|Inteiro|Inteiro decimal assinado.|  
|`o`|Inteiro|inteiro octal não assinado.|  
|`u`|Inteiro|Inteiro decimal sem sinal.|  
|`x`|Inteiro|Inteiro hexadecimal não assinado; usa "abcdef".|  
|`X`|Inteiro|Inteiro hexadecimal não assinado; usa "ABCDEF".|  
|`e`|Ponto flutuante|Valor assinado que tem a forma [-]`d`**.**`dddd` e [*sign*]`dd[d]` em que `d` é um dígito decimal, `dddd` é um ou mais dígitos decimais, `dd[d]` são dois ou três dígitos decimais dependendo do [formato de saída](../c-runtime-library/set-output-format.md) e o tamanho do expoente, e *sign* é + ou –.|  
|`E`|Ponto flutuante|Idêntico ao formato `e`, com a exceção de que **E** em vez de **e** apresenta o expoente.|  
|`f`|Ponto flutuante|Valor assinado que tem a forma [ – ]`dddd`**.** `dddd`, em que `dddd` é um ou mais dígitos decimais. O número de dígitos antes do ponto decimal depende da magnitude do número, e o número de dígitos após o ponto decimal depende da precisão solicitada.|  
|`g`|Ponto flutuante|Valores assinados são exibidos no formato `f` ou `e`, o que for mais compacto para o valor e a precisão especificados. O formato `e` é usado somente quando o expoente do valor é menor do que –&4; ou maior ou igual ao argumento `precision`. Zeros à esquerda são truncados, e o ponto decimal é exibido somente se um ou mais dígitos vierem na sequência.|  
|`G`|Ponto flutuante|Idêntico ao formato `g`, com a exceção de que **E** em vez de **e** apresenta o expoente (quando apropriado).|  
|`a`|Ponto flutuante|Valor hexadecimal de ponto flutuante, precisão dupla e assinado que tem o formato [−]0x*h.hhhh* **p±**`dd`, em que *h.hhhh* são os dígitos hexadecimais (usando letras minúsculas) da mantissa, e `dd` são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|  
|`A`|Ponto flutuante|Valor hexadecimal de ponto flutuante, precisão dupla e assinado que tem o formato [−]0X*h.hhhh* **P±**`dd`, em que *h.hhhh* são os dígitos hexadecimais (usando letras maiúsculas) da mantissa, e `dd` são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|  
|`n`|Ponteiro para o inteiro|Número de caracteres gravados com êxito até o momento no fluxo ou no buffer. Esse valor é armazenado no inteiro cujo endereço é fornecido como o argumento. Consulte a seção Nota de segurança mais adiante neste artigo.|  
|`p`|Tipo ponteiro|Exibe o argumento como um endereço usando dígitos hexadecimais.|  
|`s`|Cadeia de caracteres|Quando usado com funções `printf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres largos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor `precision` seja atingido.|  
|`S`|Cadeia de caracteres|Quando usado com funções `printf`, especifica uma cadeia de caracteres largos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor `precision` seja atingido.|  
|`Z`|Estrutura `ANSI_STRING` ou `UNICODE_STRING`|Quando o endereço de uma estrutura [ANSI_STRING](http://msdn.microsoft.com/library/windows/hardware/ff540605.aspx) ou [UNICODE_STRING](http://msdn.microsoft.com/library/windows/hardware/ff564879.aspx) é passado como o argumento, exibe a cadeia de caracteres contida no buffer que está apontado para o campo `Buffer` da estrutura. Use um prefixo modificador de comprimento de `w` para especificar um argumento `UNICODE_STRING` — por exemplo, `%wZ`. O campo `Length` da estrutura deve ser definido como a duração, em bytes, da cadeia de caracteres. O campo `MaximumLength` da estrutura deve ser definido como a duração, em bytes, do buffer.<br /><br /> Normalmente, o caractere de tipo `Z` é usado somente em funções de depuração de driver que usam uma especificação de formato, como `dbgPrint` e `kdPrint`.|  
  
 Se o argumento que corresponde a um especificador de conversão de ponto flutuante for infinito, indefinido ou NAN, a tabela a seguir listará a saída formatada.  
  
|Valor|Saída|  
|-----------|------------|  
|+ infinity|`1.#INF` *random-digits*|  
|– infinity|`–1.#INF` *random-digits*|  
|Indefinite (mesmo que NaN silencioso)|*dígito* `.#IND` *random-digits*|  
|NAN|*dígito* `.#NAN` *random-digits*|  
  
> [!NOTE]
>  Se o campo `Buffer` do argumento que corresponde a `%Z`, ou do argumento que corresponde a `%s` ou `%S` for um ponteiro nulo, "(null)" será exibido.  
  
> [!NOTE]
>  Em todos os formatos exponenciais, o número padrão de dígitos do expoente para exibição é de três. Usando a função [set_output_format](../c-runtime-library/set-output-format.md), você pode definir o número de dígitos exibidos como dois, mas expandindo para três se o tamanho do expoente exigir.  
  
> [!IMPORTANT]
>  Pela insegurança inerente do formato `%n`, ela fica desabilitada por padrão. Se `%n` for encontrado em um formato de cadeia de caracteres, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Para habilitar o suporte a `%n`, confira [set_printf_count_output](../c-runtime-library/reference/set-printf-count-output.md).  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)   
 [Diretivas de sinalizador](../c-runtime-library/flag-directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de tamanho](../c-runtime-library/size-specification.md)   
 [_set_output_format](../c-runtime-library/set-output-format.md)
