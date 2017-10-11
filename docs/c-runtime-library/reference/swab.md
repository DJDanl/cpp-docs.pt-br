---
title: _swab | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _swab
- stdlib/_swab
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
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _swab
- stdlib/_swab
dev_langs:
- C++
helpviewer_keywords:
- _swab function
- swapping bytes
- swab function
- bytes, swapping
ms.assetid: 017142f2-050c-4f6a-8b49-6b094f58ec94
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: a3043abf425055d8cb21108a30db2e6382e19c1a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="swab"></a>_swab
Troca bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _swab(  
   char *src,  
   char *dest,  
   int n   
);  
```  
  
## <a name="parameters"></a>Parâmetros  
 `src`  
 Dados a serem copiados e trocados.  
  
 `dest`  
 Local de armazenamento para os dados trocados.  
  
 `n`  
 Número de bytes a serem copiados e trocados.  
  
## <a name="return-value"></a>Valor retornado
 A função `swab` não retorna um valor. A função definirá `errno` como `EINVAL` se o ponteiro `src` ou `dest` for nulo ou se `n` for menor que zero e o manipulador de parâmetro inválido for invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.
 
## <a name="remarks"></a>Comentários  
 Se `n` for par, a função `_swab` copiará `n` bytes de `src`, trocará cada par de bytes adjacentes e armazenará o resultado em `dest`. Se `n` for ímpar, `_swab` copiará e trocará os primeiros `n-1` bytes de `src` e o byte final não será copiado. A função `_swab` geralmente é usada para preparar dados binários para transferência para um computador que usa uma ordem de byte diferente.  
  
## <a name="requirements"></a>Requisitos  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_swab`|C: \<stdlib.h> C++: \<cstdlib> ou \<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
```C 
// crt_swab.c  
  
#include <stdlib.h>  
#include <stdio.h>  
  
char from[] = "BADCFEHGJILKNMPORQTSVUXWZY";  
char to[] =   "...........................";  
  
int main()  
{  
    printf("Before: %s  %d bytes\n        %s\n\n", from, sizeof(from), to);  
    _swab(from, to, sizeof(from));  
    printf("After:  %s\n        %s\n\n", from, to);  
}  
```  
  
```Output  
Before: BADCFEHGJILKNMPORQTSVUXWZY  27 bytes  
        ...........................  
  
After:  BADCFEHGJILKNMPORQTSVUXWZY  
        ABCDEFGHIJKLMNOPQRSTUVWXYZ.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)
