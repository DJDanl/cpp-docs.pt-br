---
title: "Especificação de largura printf | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
dev_langs:
- C++
helpviewer_keywords:
- printf function, width specification
- printf function, format specification fields
ms.assetid: 8b4a1b1e-bf6e-414f-a1b6-a9b6f1b6ce92
caps.latest.revision: 9
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
ms.openlocfilehash: f88368da3fb54a47f47f6a2d180291de98bcef16
ms.lasthandoff: 02/25/2017

---
# <a name="printf-width-specification"></a>Especificação de largura printf
Em uma especificação de formato, o segundo campo opcional é a especificação de largura. O argumento `width` é um inteiro decimal não negativo que controla o número mínimo de caracteres de saída. Se o número de caracteres no valor de saída for menor que a largura especificada, espaços em branco serão adicionados à esquerda ou à direita dos valores — dependendo se o sinalizador de alinhamento à esquerda (`-`) for especificado — até que a largura mínima seja atingida. Se `width` for prefixado por 0, zeros à esquerda serão adicionados ao inteiro ou conversões de ponto flutuantes até que a largura mínima seja atingida, exceto quando a conversão for a um infinito ou NAN.  
  
 A especificação de largura nunca faz com que um valor seja truncado. Se o número de caracteres no valor de saída for maior que a largura especificada ou se `width` não for fornecido, todos os caracteres do valor serão saída, sujeitos a especificação de [precisão](../c-runtime-library/precision-specification.md).  
  
 Se a especificação de precisão for um asterisco (`*`), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento `width` deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:  
  
 `printf("%0*f", 5, 3);  /* 00003 is output */`  
  
 Um valor `width` ausente ou pequeno em uma especificação de formato não causa o truncamento de um valor de saída. Se o resultado de uma conversão for maior do que o valor `width`, o campo se expandirá para conter o resultado da conversão.  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)   
 [Diretivas de sinalizador](../c-runtime-library/flag-directives.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de tamanho](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)
