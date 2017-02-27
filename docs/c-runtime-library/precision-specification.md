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
- msvcr100.dll
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr90.dll
- msvcr80.dll
apitype: DLLExport
f1_keywords:
- c.math
dev_langs:
- C++
helpviewer_keywords:
- printf function, format specification fields
ms.assetid: dc59ea4e-d23a-4f1f-9881-2c919ebefb82
caps.latest.revision: 10
author: corob-msft
ms.author: corob
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3da7c602e7af2110ccf46e07b11275c97b11c083

---
# <a name="precision-specification"></a>Especificação da precisão
Em uma especificação de formato, o terceiro campo opcional é a especificação de precisão. Ele consiste em um ponto (.) seguido de um inteiro de decimal não negativo que, dependendo do tipo de conversão, especifica o número de caracteres da cadeia de caracteres, o número de casas decimais ou o número de dígitos significativos para a saída.  
  
 Ao contrário da especificação de largura, a especificação de precisão pode causar o truncamento do valor de saída ou arredondamento de um valor de ponto flutuante. Se `precision` for especificado como 0 e o valor a ser convertido for 0, o resultado não será uma saída de caracteres, conforme mostrado neste exemplo:  
  
 `printf( "%.0d", 0 );      /* No characters output */`  
  
 Se a especificação de precisão for um asterisco (*), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento `precision` deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:  
  
 `printf( "%.*f", 3, 3.14159265 );  /* 3.142 output */`  
  
 O tipo determina se a interpretação de `precision` ou a precisão padrão quando `precision` for omitido, conforme mostrado na tabela a seguir.  
  
### <a name="how-precision-values-affect-type"></a>Como os valores de precisão afetam o tipo  
  
|Tipo|Significado|Padrão|  
|----------|-------------|-------------|  
|`a`, `A`|A precisão especifica o número de dígitos após a vírgula.|A precisão padrão é 6. Se a precisão for 0, nenhuma vírgula decimal será impressa, a menos que o sinalizador `#` seja usado.|  
|`c`, `C`|A precisão não tem nenhum efeito.|O caractere foi impresso.|  
|`d`, `i`, `u`, `o`, `x`, `X`|A precisão especifica o número mínimo de dígitos a ser impresso. Se o número de dígitos no argumento for menor que `precision`, o valor de saída será preenchido com zeros à esquerda. O valor não será truncado quando o número de dígitos exceder `precision`.|A precisão padrão é 1.|  
|`e`, `E`|A precisão especifica o número de dígitos a serem impressos após a vírgula decimal. O último dígito impresso será arredondado.|A precisão padrão é 6. Se `precision` for 0 ou a vírgula (,) aparecer sem um número a seguir, a vírgula decimal não será impressa.|  
|`f`|O valor de precisão especifica o número de dígitos após a vírgula decimal. Se uma vírgula decimal aparecer, pelo menos um dígito aparecerá antes dela. O valor é arredondado para o número apropriado de dígitos.|A precisão padrão é 6. Se `precision` for 0 ou se a vírgula (,) aparecer sem um número a seguir, a vírgula decimal não será impressa.|  
|`g`, `G`|A precisão especifica o número máximo de dígitos significativos impressos.|Seis dígitos significativos são impressos e os zeros à direita são truncados.|  
|`s`, `S`|A precisão especifica o número máximo de caracteres a serem impressos. Caracteres acima de `precision` não são impressos.|Os caracteres são impressos até que seja encontrado um caractere nulo.|  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)   
 [Diretivas de sinalizador](../c-runtime-library/flag-directives.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação de tamanho](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)


<!--HONumber=Feb17_HO4-->


