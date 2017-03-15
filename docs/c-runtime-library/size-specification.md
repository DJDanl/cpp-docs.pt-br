---
title: "Especificação de precisão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr120.dll
- msvcr80.dll
- msvcr110.dll
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- size
dev_langs:
- C++
helpviewer_keywords:
- printf function, format specification fields
ms.assetid: 525dc5d8-e70a-4797-a6a0-ec504a27355c
caps.latest.revision: 14
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
ms.openlocfilehash: 9041b6c8cc2789b275bf7a62c73102812e5c9c48
ms.lasthandoff: 02/25/2017

---
# <a name="size-specification"></a>Especificação de arquivo
Em uma especificação de formato, o quarto campo é um modificador de comprimento do argumento para o especificador de conversão. O `size` campo prefixos para o `type` campo —`h`, `l`, `w`, `I`, `I32`, `I64`, e `ll`— especifique o "tamanho" do argumento correspondente — longo ou curto, 32 bits ou 64 bits, caracteres de byte único ou de caractere largo — dependendo do especificador de conversão que eles modificam. Esses prefixos de tamanho são usados com `type` caracteres de `printf` e `wprintf` famílias de funções para especificar a interpretação dos tamanhos de argumento, como mostrado na tabela a seguir. O campo `size` é opcional para alguns tipos de argumentos. Quando nenhum prefixo de tamanho é especificado, o formatador consome argumentos inteiros — por exemplo, com sinal ou `char`, `short`, `int`, `long`e tipos de enumeração — como 32 bits `int` tipos e argumentos de ponto flutuante são consumidos de 64 bits `double` tipos. Isso coincide com as regras de promoção de argumento padrão para listas de argumentos variáveis. Para saber mais sobre a promoção de argumento, veja reticências e argumentos padrão em [expressões de sufixo](../cpp/postfix-expressions.md). Em sistemas de 32 bits e 64 bits, a especificação de formato de um argumento de inteiro de 64 bits deve incluir um prefixo de tamanho de `ll` ou `I64`. Caso contrário, o comportamento do formatador será indefinido.  
  
 Alguns tipos têm tamanhos diferentes no código de 32 bits e 64 bits. Por exemplo, `size_t` é de 32 bits longa no código compilado para x86 e 64 bits no código compilado para x64. Para criar o código de formatação independente de plataforma para tipos de largura variável, você pode usar um modificador de comprimento do argumento de largura variável. Como alternativa, use um modificador de comprimento do argumento de 64 bits e promover explicitamente o tipo de argumento de largura variável 64 bits. Específicos do Microsoft `I` argumento modificador comprimento lida com argumentos inteiros de largura variável.  
  
> [!NOTE]
>  O `I`, `I32`, e `I64` prefixos de modificador de comprimento são extensões da Microsoft e não são compatíveis com ANSI. O `h` prefixo quando ele é usado com o tipo de dados `char`, o `w` prefixo quando ele é usado com o tipo de dados `wchar_t`e o `l` prefixo quando ele é usado com o tipo de dados `double` são extensões da Microsoft. Os prefixos de comprimento `hh`, `j`, `z` e `t` não tem suporte.  
  
### <a name="size-prefixes-for-printf-and-wprintf-format-type-specifiers"></a>Prefixos de Tamanho para Especificadores de Tipo de Tamanho printf e wpprintf  
  
|Para especificar|Use o prefixo|Com especificador de tipo|  
|----------------|----------------|-------------------------|  
|`long int`|`l` (L minúsculo)|`d`, `i`, `o`, `x` ou `X`|  
|`long unsigned int`|`l`|`o`, `u`, `x` ou `X`|  
|`long long`|`ll`|`d`, `i`, `o`, `x` ou `X`|  
|`short int`|`h`|`d`, `i`, `o`, `x` ou `X`|  
|`short unsigned int`|`h`|`o`, `u`, `x` ou `X`|  
|`__int32`|`I32`|`d`, `i`, `o`, `x` ou `X`|  
|`unsigned __int32`|`I32`|`o`, `u`, `x` ou `X`|  
|`__int64`|`I64`|`d`, `i`, `o`, `x` ou `X`|  
|`unsigned __int64`|`I64`|`o`, `u`, `x` ou `X`|  
|`ptrdiff_t`(ou seja, `__int32` em plataformas de 32 bits, `__int64` em plataformas de 64 bits)|`I`|`d`, `i`, `o`, `x` ou `X`|  
|`size_t`(ou seja, `unsigned __int32` em plataformas de 32 bits, `unsigned __int64` em plataformas de 64 bits)|`I`|`o`, `u`, `x` ou `X`|  
|`long double`(No [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], embora `long double` seja um tipo diferente, ele tem a mesma representação interna de `double`).|`l` ou `L`|`a`, `A`, `e`, `E`, `f`, `g` ou `G`|  
|Caractere de byte único com funções `printf` e `wprintf`. (Um especificador de tipo `hc` ou `hC` é sinônimo de `c` em funções `printf` e com `C` em funções `wprintf`).|`h`|`c` ou `C`|  
|Caracteres largos com funções `printf` e `wprintf`. (Um especificador de tipo `lc`, `lC`, `wc` ou `wC` é sinônimo de `C` em funções `printf` e com `c` em funções `wprintf`).|`l` ou `w`|`c` ou `C`|  
|Cadeia de caracteres de byte único com funções `printf` e `wprintf`. (Um especificador de tipo `hs` ou `hS` é sinônimo de `s` em funções `printf` e com `S` em funções `wprintf`).|`h`|`s`, `S` ou `Z`|  
|Cadeia de caracteres largos com funções `printf` e `wprintf`. (Um especificador de tipo `ls`, `lS`, `ws` ou `wS` é sinônimo de `S` em funções `printf` e com `s` em funções `wprintf`).|`l` ou `w`|`s`, `S` ou `Z`|  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)   
 [Diretivas de sinalizador](../c-runtime-library/flag-directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da Precisão](../c-runtime-library/precision-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)
