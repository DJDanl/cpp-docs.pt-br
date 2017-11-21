---
title: _get_doserrno | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _get_doserrno
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _get_doserrno
- get_doserrno
dev_langs: C++
helpviewer_keywords:
- get_doserrno function
- _get_doserrno function
ms.assetid: 7fec7be3-6e39-4181-846b-8ef24489361c
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 67f546afa3059508787c7d3a5295d2b85651f125
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="getdoserrno"></a>_get_doserrno
Obtém o valor do erro retornado pelo sistema operacional antes de ele ser convertido para um valor `errno`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _get_doserrno(   
   int * pValue   
);   
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pValue`  
 Um ponteiro para um inteiro que deve ser preenchido com o valor atual da macro global `_doserrno`.  
  
## <a name="return-value"></a>Valor de retorno  
 Se `_get_doserrno` tiver êxito, o valor retornado é zero. Em caso de falha, o valor retornado é um código de erro. Se `pValue` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A macro global `_doserrno` é definida como zero durante a inicialização do CRT (tempo de execução C), antes do início do processo de execução. Ela é definida para o valor de erro do sistema operacional retornado por qualquer chamada de função de nível do sistema que retorne um erro de sistema operacional. Ela nunca é redefinida para zero durante a execução. Ao escrever o código para verificar o valor de erro retornado por uma função, sempre limpe `_doserrno` usando [_set_doserrno](../../c-runtime-library/reference/set-doserrno.md) antes da chamada de função. Como outra chamada de função pode substituir `_doserrno`, verifique o valor usando `_get_doserrno` logo após a chamada de função.  
  
 Recomendamos que você use [_get_errno](../../c-runtime-library/reference/get-errno.md) em vez de `_get_doserrno` para códigos de erro portáteis.  
  
 Os valores possíveis de `_doserrno` são definidos em \<errno.h>.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_get_doserrno`|\<stdlib.h>, \<cstdlib> (C++)|\<errno.h>, \<cerrno> (C++)|  
  
 `_get_doserrno` é uma extensão da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [_set_doserrno](../../c-runtime-library/reference/set-doserrno.md)   
 [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md)