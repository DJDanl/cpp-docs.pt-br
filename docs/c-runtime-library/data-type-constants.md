---
title: Constantes do Tipo de Dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- FLT_MIN
- SHRT_MAX
- CHAR_MIN
- MB_LEN_MAX
- DBL_EPSILON
- SHRT_MIN
- _FLT_RADIX
- FLT_DIG
- FLT_MAX_10_EXP
- FLT_MANT_DIG
- DBL_MAX_EXP
- SCHAR_MIN
- SCHAR_MAX
- DBL_MIN
- FLT_MIN_10_EXP
- _DBL_ROUNDS
- USHRT_MAX
- FLT_MAX_EXP
- LONG_MAX
- DBL_MAX
- DBL_DIG
- FLT_MIN_EXP
- INT_MIN
- DBL_MIN_10_EXP
- CHAR_BIT
- INT_MAX
- ULONG_MAX
- DBL_MIN_EXP
- LONG_MIN
- _FLT_ROUNDS
- DBL_MANT_DIG
- _DBL_RADIX
- CHAR_MAX
- FLT_MAX
- DBL_MAX_10_EXP
- UCHAR_MAX
- FLT_EPSILON
- UINT_MAX
dev_langs:
- C++
helpviewer_keywords:
- DBL_MAX_EXP constant
- _DBL_RADIX constant
- FLT_MIN_EXP constant
- DBL_EPSILON constant
- INT_MIN constant
- FLT_EPSILON constant
- DBL_MANT_DIG constant
- _FLT_RADIX constant
- DBL_MIN constant
- USHRT_MAX constant
- FLT_MAX_10_EXP constant
- _FLT_ROUNDS constant
- data type constants [C++]
- _DBL_ROUNDS constant
- CHAR_MAX constant
- FLT_MAX_EXP constant
- FLT_MIN constant
- CHAR_MIN constant
- FLT_MIN_10_EXP constant
- DBL_MIN_EXP constant
- SCHAR_MAX constant
- FLT_RADIX constant
- CHAR_BIT constant
- UCHAR_MAX constant
- DBL_RADIX constant
- FLT_ROUNDS constant
- LONG_MIN constant
- SHRT_MAX constant
- LONG_MAX constant
- DBL_MAX_10_EXP constant
- DBL_MIN_10_EXP constant
- INT_MAX constant
- constants [C++], data type
- ULONG_MAX constant
- FLT_DIG constant
- MB_LEN_MAX constant
- DBL_DIG constant
- SHRT_MIN constant
- DBL_MAX constant
- DBL_ROUNDS constant
- FLT_MAX constant
- UINT_MAX constant
- FLT_MANT_DIG constant
- SCHAR_MIN constant
ms.assetid: c0f1c405-0465-41d5-b5ff-e81cdb6f1622
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1702065a8157596d4366af31fed3f2a80d53149c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="data-type-constants"></a>Constantes de tipo de dados
Constantes de tipo de dados são dependentes de implementação intervalos de valores permitidos para tipos de dados integrais. As constantes listadas abaixo oferecem os intervalos para os tipos de dados integrais e são definidas em LIMITS.H.  
  
> [!NOTE]
>  A opção do compilador /J altera o padrão de `char` para `unsigned`.  
  
|Constante|Valor|Significado|  
|--------------|-----------|-------------|  
|**SCHAR_MAX**|127|Valor máximo `char` assinado|  
|**SCHAR_MIN**|-128|Valor mínimo `char` assinado|  
|**UCHAR_MAX**|255 (0xff)|Valor `unsigned char` Máximo|  
|**CHAR_BIT**|8|O número de bits em um `char`|  
|**USHRT_MAX**|65535 (0xffff)|Valor **curto máximo não assinado**|  
|**SHRT_MAX**|32767|Valor **curto máximo** assinado|  
|**SHRT_MIN**|-32768|Valor **curto mínimo** assinado|  
|**UINT_MAX**|4294967295 (0xffffffff)|Valor `unsigned int` Máximo|  
|**ULONG_MAX**|4294967295 (0xffffffff)|Valor `unsigned long` Máximo|  
|**INT_MAX**|2147483647|Valor máximo `int` (assinado)|  
|**INT_MIN**|-2147483647-1|Valor mínimo `int` (assinado)|  
|**LONG_MAX**|2147483647|Valor longo **máximo** (assinado)|  
|**LONG_MIN**|-2147483647-1|Valor longo **mínimo** (assinado)|  
|**CHAR_MAX**|127 (255 se opção /J for usada)|Valor `char` Máximo|  
|**CHAR_MIN**|-128 (0 se a opção /J for usada)|Valor `char` Mínimo|  
|**MB_LEN_MAX**|2|O número máximo de bytes em um multibyte `char`|  
|**_I64_MAX**|9223372036854775807|Valor _**int64** máximo (assinado)|  
|**_I64_MIN**|-9223372036854775807-1|Valor _**int64** mínimo (assinado)|  
|**_UI64_MAX**|0xffffffffffffffff|Valor _**int64** máximo (não assinado)|  
  
 As constantes a seguir fornecem o intervalo e outras características dos tipos de dados **double** e **float** e são definidos em FLOAT.H:  
  
|Constante|Valor|Descrição|  
|--------------|-----------|-----------------|  
|**DBL_DIG**|15|Nº de casas decimais de precisão|  
|**DBL_EPSILON**|2.2204460492503131e-016|Menores tais quais 1.0+**DBL_EPSILON** !=1.0|  
|**DBL_MANT_DIG**|53|Nº de bits da mantissa|  
|**DBL_MAX**|1.7976931348623158e+308|Valor máximo|  
|**DBL_MAX_10_EXP**|308|Expoente decimal máximo|  
|**DBL_MAX_EXP**|1024|Expoente binário máximo|  
|**DBL_MIN**|2.2250738585072014e-308|Valor positivo mínimo|  
|**DBL_MIN_10_EXP**|(-307)|Expoente decimal mínimo|  
|**DBL_MIN_EXP**|(-1021)|Expoente binário mínimo|  
|**_DBL_RADIX**|2|Expoente base|  
|**_DBL_ROUNDS**|1|Adição de arredondamento: próximo|  
|**FLT_DIG**|6|Número de dígitos decimais de precisão|  
|**FLT_EPSILON**|1.192092896e-07F|Menores tais quais 1.0+**FLT_EPSILON** !=1.0|  
|**FLT_MANT_DIG**|24|Número de bits da mantissa|  
|**FLT_MAX**|3.402823466e+38F|Valor máximo|  
|**FLT_MAX_10_EXP**|38|Expoente decimal máximo|  
|**FLT_MAX_EXP**|128|Expoente binário máximo|  
|**FLT_MIN**|1.175494351e-38F|Valor positivo mínimo|  
|**FLT_MIN_10_EXP**|(-37)|Expoente decimal mínimo|  
|**FLT_MIN_EXP**|(-125)|Expoente binário mínimo|  
|**FLT_RADIX**|2|Expoente base|  
|**FLT_ROUNDS**|1|Adição de arredondamento: próximo|  
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)