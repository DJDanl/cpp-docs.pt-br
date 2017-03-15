---
title: "Sintaxe de especificação de formato: funções printf e wprintf (CTR) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- wprintf
dev_langs:
- C++
helpviewer_keywords:
- format specification fields for printf function
- print flag directives
- printf function, precision
- type fields, printf function
- precision fields
- printf function, format specification fields
- flag directives printf function
- type fields
ms.assetid: 664b1717-2760-4c61-bd9c-22eee618d825
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
ms.openlocfilehash: 1843e4f826606f85aa96d1faf65e4af3f80769ea
ms.lasthandoff: 02/25/2017

---
# <a name="format-specification-syntax-printf-and-wprintf-functions"></a>Sintaxe de especificação de formato: funções printf e and wprintf
Descreve a sintaxe para argumentos de cadeia de caracteres de formato como `printf`, `wprintf` e funções relacionadas. Versões mais seguras dessas funções estão disponíveis; Para saber mais, veja [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md). Para obter informações sobre as funções individuais, veja a documentação para as funções específicas. Para obter uma lista dessas funções, veja [E/S de fluxo](../c-runtime-library/stream-i-o.md).  
  
 Uma especificação de formato, que consiste em campos necessários e opcionais, tem a seguinte forma:  
  
 `%`[[flags](../c-runtime-library/flag-directives.md)] [[width](../c-runtime-library/printf-width-specification.md)] [**.**[precision](../c-runtime-library/precision-specification.md)] [{`h` &#124; `l` &#124; `ll` &#124; `w` &#124; `I` &#124; `I32` &#124; `I64`}] [type](../c-runtime-library/printf-type-field-characters.md)  
  
 Cada campo da especificação de formato é um caractere ou um número que representa um especificador de opção ou conversão de formato específico. O caractere `type` necessário especifica o tipo de conversão a ser aplicado a um argumento. Os campos `flags`, `width`, e `precision` opcionais controlam outros aspectos de formato. Uma especificação de formato básico contém apenas o sinal de porcentagem e uma `type` caracteres — por exemplo, `%s`, que especifica uma conversão de cadeia de caracteres. Nas versões seguras de funções, se um sinal de porcentagem é seguido por um caractere que não tem nenhum significado como um campo de formato, o manipulador de parâmetro inválido é invocado. Para saber mais, confira [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Nas versões não seguras, o caractere é copiado inalterado para a saída. Para imprimir um caractere de sinal de porcentagem, use `%%`.  
  
 Os campos da especificação de formato controlam os seguintes aspectos da conversão de argumento e formatação:  
  
 `type`  
 Caractere de especificador de conversão necessária que determina se associado `argument` é interpretado como um caractere, uma cadeia de caracteres, um inteiro ou um número de ponto flutuante. Para saber mais, veja [Caracteres de campo de tipo scanf](../c-runtime-library/printf-type-field-characters.md).  
  
 `flags`  
 Opcional caractere ou caracteres que controlam a justificativa de saída e a saída de sinais, espaços em branco, zeros à esquerda, pontos decimais e prefixos octais e hexadecimais. Para saber mais, veja [Diretivas de sinalizador](../c-runtime-library/flag-directives.md). Mais de um sinalizador pode aparecer em uma especificação de formato e sinalizadores podem aparecer em qualquer ordem.  
  
 `width`  
 Número decimal opcional que especifica o número mínimo de caracteres de saída. Para saber mais, veja [Especificação de largura scanf](../c-runtime-library/printf-width-specification.md).  
  
 `precision`  
 Número decimal opcional que especifica o número máximo de caracteres impressos para cadeias de caracteres, o número de dígitos significativos ou o número de dígitos após o caractere de ponto decimal para valores de ponto flutuante, ou o número mínimo de dígitos impressos para valores inteiros. Para saber mais, veja "Como precisão valores afetam o tipo em" [especificação de precisão de](../c-runtime-library/precision-specification.md).  
  
 `h` &#124; `l` &#124; `ll` &#124; `w` &#124; `I` &#124; `I32` &#124; `I64`  
 Os prefixos opcionais para `type` que especificam o tamanho do argumento correspondente. Para saber mais, veja "Prefixos de tamanho" em [Especificação de tamanho](../c-runtime-library/size-specification.md).  
  
> [!IMPORTANT]
>  Verifique se as cadeias de caracteres de especificação de formato não são definidas pelo usuário. Por exemplo, considere um programa que solicita que o usuário insira um nome e armazena a entrada em uma variável de cadeia de caracteres chamado `name`. Para imprimir `name`, não faça isto:  
>   
>  `printf( name ); /* Danger!  If name contains "%s", program will crash */`  
>   
>  Em vez disso, faça o seguinte:  
>   
>  `printf( "%s", name );`  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)   
 [Parâmetros posicionais printf_p](../c-runtime-library/printf-p-positional-parameters.md)   
 [Diretivas de sinalizador](../c-runtime-library/flag-directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da Precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de tamanho](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)
