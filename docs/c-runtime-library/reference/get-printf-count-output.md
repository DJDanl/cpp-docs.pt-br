---
title: _get_printf_count_output | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _get_printf_count_output
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_printf_count_output
- _get_printf_count_output
dev_langs:
- C++
helpviewer_keywords:
- '%n format'
- get_printf_count_output function
- _get_printf_count_output function
ms.assetid: 850f9f33-8319-433e-98d8-6a694200d994
caps.latest.revision: 8
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 9f45a13d9911e82b2b624689fa6b9e5eb4b20d97
ms.lasthandoff: 02/25/2017

---
# <a name="getprintfcountoutput"></a>_get_printf_count_output
Indica se as funções da família [printf, _printf_l, wprintf, _wprintf_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) dão suporte ao formato `%n`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _get_printf_count_output();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `%n` tiver suporte, 0 se `%n` não tiver suporte.  
  
## <a name="remarks"></a>Comentários  
 Se `%n` não tiver suporte (padrão), encontrar `%n` na cadeia de caracteres de formato de qualquer uma das funções `printf` invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o suporte de `%n` estiver habilitado (consulte [_set_printf_count_output](../../c-runtime-library/reference/set-printf-count-output.md)), `%n` se comportará conforme descrito em [Caracteres de campo de tipo printf](../../c-runtime-library/printf-type-field-characters.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_printf_count_output`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_set_printf_count_output](../../c-runtime-library/reference/set-printf-count-output.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).
