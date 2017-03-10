---
title: toascii, __toascii | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __toascii
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __toascii
- toascii
- ctype/toascii
- ctype/__toascii
dev_langs:
- C++
helpviewer_keywords:
- toascii function
- string conversion, to ASCII characters
- __toascii function
- ASCII characters, converting to
ms.assetid: a07c0608-b0e2-4da2-a20c-7b64d6a9b77c
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.openlocfilehash: c86dc6ed69907b98b1fef5044acb86270ca25009
ms.lasthandoff: 02/25/2017

---
# <a name="toascii-toascii"></a>toascii, __toascii
Converte caracteres em ASCII de 7 bits por truncamento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int __toascii(  
   int c   
);  
#define toascii __toascii  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Caractere a ser convertido.  
  
## <a name="return-value"></a>Valor de retorno  
 `__toascii` converte o valor de `c` no intervalo de ASCII de 7 bits e retorna o resultado. Não há valor retornado reservado para indicar um erro.  
  
## <a name="remarks"></a>Comentários  
 A rotina `__toascii` converte o caractere especificado em um caractere ASCII truncando-o nos 7 bits de ordem inferior. Nenhuma outra transformação é aplicada.  
  
 A rotina `__toascii` é definida como uma macro, a menos que a macro do pré-processador _CTYPE_DISABLE_MACROS esteja definida. Para compatibilidade com versões anteriores, `toascii` é definido como uma macro somente quando [__STDC\_\_](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, será indefinido.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`toascii`, `__toascii`|C: \<ctype.h><br /><br /> C++: \<cctype> ou \<ctype.h>|  
  
 A macro `toascii` é uma extensão POSIX e `__toascii` é uma implementação específica à Microsoft da extensão POSIX. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão de Dados](../../c-runtime-library/data-conversion.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Funções to](../../c-runtime-library/to-functions.md)
