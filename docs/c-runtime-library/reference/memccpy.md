---
title: _memccpy | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _memccpy
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _memccpy
dev_langs:
- C++
helpviewer_keywords:
- _memccpy function
- memccpy function
ms.assetid: 9a2337df-6e85-4eba-b247-dd0532f45ddb
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 289043b95095fbff3e25deaf464e9eca23c23457
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="memccpy"></a>_memccpy
Copia caracteres de um buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void *_memccpy(  
   void *dest,  
   const void *src,  
   int c,  
   size_t count   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dest*  
 Ponteiro para o destino.  
  
 *src*  
 Ponteiro para a origem.  
  
 `c`  
 Último caractere a ser copiado.  
  
 *count*  
 Número de caracteres.  
  
## <a name="return-value"></a>Valor de retorno  
 Se o caractere `c` for copiado, `_memccpy` retornará um ponteiro para caractere em *dest* imediatamente após o caractere. Se `c` não for copiado, ele retornará **NULL**.  
  
## <a name="remarks"></a>Comentários  
 A função `_memccpy` copia 0 ou mais caracteres de *src* para *dest*, interrompendo quando o caractere `c` tiver sido copiado ou quando *count* caracteres tiverem sido copiados, o que ocorrer primeiro.  
  
 **Observação de segurança** Certifique-se de que o buffer de destino seja do mesmo tamanho ou maior que o buffer de origem. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_memccpy`|\<memory.h> ou \<string.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_memccpy.c  
  
#include <memory.h>  
#include <stdio.h>  
#include <string.h>  
  
char string1[60] = "The quick brown dog jumps over the lazy fox";  
  
int main( void )  
{  
   char buffer[61];  
   char *pdest;  
  
   printf( "Function: _memccpy 60 characters or to character 's'\n" );  
   printf( "Source: %s\n", string1 );  
   pdest = _memccpy( buffer, string1, 's', 60 );  
   *pdest = '\0';  
   printf( "Result: %s\n", buffer );  
   printf( "Length: %d characters\n", strlen( buffer ) );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
Function: _memccpy 60 characters or to character 's'  
Source: The quick brown dog jumps over the lazy fox  
Result: The quick brown dog jumps  
Length: 25 characters  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de buffer](../../c-runtime-library/buffer-manipulation.md)   
 [memchr, wmemchr](../../c-runtime-library/reference/memchr-wmemchr.md)   
 [memcmp, wmemcmp](../../c-runtime-library/reference/memcmp-wmemcmp.md)   
 [memcpy, wmemcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md)   
 [memset, wmemset](../../c-runtime-library/reference/memset-wmemset.md)
