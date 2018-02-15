---
title: _isatty | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _isatty
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
- _isatty
dev_langs:
- C++
helpviewer_keywords:
- isatty function
- character device checking
- _isatty function
- checking character devices
ms.assetid: 9f1b2e87-0cd7-4079-b187-f2b7ca15fcbe
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bea907f22496c3c1abe86462357ba14514a4aca7
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="isatty"></a>_isatty
Determina se um descritor de arquivo está associado a um dispositivo de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _isatty(  
int fd   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`  
 Descritor de arquivo que se refere ao dispositivo a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 `_isatty` retornará um valor diferente de zero se o descritor estiver associado a um dispositivo de caracteres. Caso contrário, `_isatty` retorna 0.  
  
## <a name="remarks"></a>Comentários  
 A função `_isatty` determina se `fd` está associado a um dispositivo de caracteres (um terminal, console, impressora ou porta serial).  
  
 Essa função valida o parâmetro `fd`. Se `fd` for um ponteiro de arquivo incorreto, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará 0 e definirá `errno` como `EBADF`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_isatty`|\<io.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_isatty.c  
/* This program checks to see whether  
 * stdout has been redirected to a file.  
 */  
  
#include <stdio.h>  
#include <io.h>  
  
int main( void )  
{  
   if( _isatty( _fileno( stdout ) ) )  
      printf( "stdout has not been redirected to a file\n" );  
   else  
      printf( "stdout has been redirected to a file\n");  
}  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
stdout has not been redirected to a file  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)