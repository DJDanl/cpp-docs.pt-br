---
title: _get_output_format | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _get_output_format
apilocation:
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr80.dll
- msvcrt.dll
- msvcr90.dll
- msvcr120.dll
- msvcr110.dll
apitype: DLLExport
f1_keywords:
- get_output_format
- _get_output_format
dev_langs:
- C++
helpviewer_keywords:
- output formatting
- get_output_format function
- _get_output_format function
ms.assetid: 0ce42f3b-3479-41c4-bcbf-1d21f7ee37e7
caps.latest.revision: 13
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
ms.openlocfilehash: e923c8f4dcfbf2a2392c6b70fee2c5dc423c34c6

---
# <a name="getoutputformat"></a>_get_output_format
Obtém o valor atual do sinalizador de formato de saída.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
unsigned int _get_output_format();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O valor atual do sinalizador de formato de saída.  
  
## <a name="remarks"></a>Comentários  
 O sinalizador de formato de saída controla os recursos da E/S formatada. No momento, o sinalizador tem dois valores possíveis: 0 e `_TWO_DIGIT_EXPONENT`. Se `_TWO_DIGIT_EXPONENT` for definido, os números de ponto flutuante serão impressos com apenas dois dígitos no expoente, a menos que um terceiro dígito seja exigido pelo tamanho do expoente. Se o sinalizador for zero, a saída de ponto flutuante exibirá três dígitos do expoente, usando zeros se necessário para preencher o valor até atingir os três dígitos.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_output_format`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)   
 [Caracteres de campo de tipo printf](../c-runtime-library/printf-type-field-characters.md)   
 [_set_output_format](../c-runtime-library/set-output-format.md)


<!--HONumber=Feb17_HO4-->


