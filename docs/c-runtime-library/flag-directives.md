---
title: Diretivas de sinalizador | Microsoft Docs
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
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- c.flags
dev_langs:
- C++
helpviewer_keywords:
- format specification fields for printf function
- print flag directives
- printf function, format specification fields
- flag directives printf function
ms.assetid: b00cbdc9-1e5c-4b30-9f56-c1ef8d383767
caps.latest.revision: 12
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
ms.openlocfilehash: 36f7db99d3fc9bb5346ae5f1dc96b846ae964714
ms.lasthandoff: 02/25/2017

---
# <a name="flag-directives"></a>Diretivas de sinalizador
Em uma especificação de formato, o primeiro campo opcional é `flags`. Uma diretiva de sinalizador é um caractere que especifica a justificativa de saída e a saída de sinais, espaços em branco, zeros à esquerda, pontos decimais e prefixos octais e hexadecimais. Mais de uma diretiva de sinalizador pode aparecer em uma especificação de formato e sinalizadores podem aparecer em qualquer ordem.  
  
### <a name="flag-characters"></a>Caracteres de sinalizador  
  
|Sinalizador|Significado|Padrão|  
|----------|-------------|-------------|  
|`–`|Alinhar à esquerda o resultado dentro da largura de campo determinada.|Alinhar à direita.|  
|`+`|Use um sinal (+ ou -) como prefixo o valor de saída se for de um tipo assinado.|O sinal será exibido somente para valores de sinal negativos (-).|  
|`0`|Se `width` é prefixado por `0`, zeros à esquerda são adicionados até que a largura mínima seja atingida. Se ambos os `0` e `–` aparecem, o `0` é ignorado. Se `0` é especificado como um formato inteiro (`i`, `u`, `x`, `X`, `o`, `d`) e uma especificação de precisão também está presente, por exemplo, `%04.d`, o `0` é ignorado.|Nenhum preenchimento.|  
|espaço em branco (' ')|Use um espaço em branco como prefixo do valor de saída se tiver um sinal e for positivo. O espaço em branco será ignorado se o espaço em branco e os sinalizadores + forem exibidos.|Nenhum espaço em branco é exibido.|  
|`#`|Quando ele é usado com o formato `o`, `x` ou `X`, o sinalizador `#` usa 0, 0x ou 0X, respectivamente, para o prefixo de qualquer valor de saída diferente de zero.|Nenhum espaço em branco é exibido.|  
||Quando ele é usado com o formato `e`, `E`, `f`, `a` ou `A`, o sinalizador `#` obriga o valor de saída a conter um ponto decimal.|O ponto decimal será exibido somente se os dígitos o seguirem.|  
||Quando ele é usado com o formato `g` ou `G`, o sinalizador `#` obriga o valor de saída a conter um ponto decimal e evita o truncamento de zeros à direita.<br /><br /> Ignorado quando usado com `c`, `d`, `i`, `u` ou `s`.|O ponto decimal será exibido somente se os dígitos o seguirem. Zeros à direita são truncados.|  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [Sintaxe de especificação de formato: funções printf e wprintf](../c-runtime-library/format-specification-syntax-printf-and-wprintf-functions.md)   
 [Especificação de largura printf](../c-runtime-library/printf-width-specification.md)   
 [Especificação da precisão](../c-runtime-library/precision-specification.md)   
 [Especificação de tamanho](../c-runtime-library/size-specification.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)
