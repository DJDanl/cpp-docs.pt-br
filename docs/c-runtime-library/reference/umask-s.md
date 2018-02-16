---
title: _umask_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _umask_s
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- unmask_s
- _umask_s
dev_langs:
- C++
helpviewer_keywords:
- masks, file-permission-setting
- _umask_s function
- masks
- file permissions [C++]
- umask_s function
- files [C++], permission settings for
ms.assetid: 70898f61-bf2b-4d8d-8291-0ccaa6d33145
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 315473748d64e572c73746ce6f6fc97ccc912bb0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="umasks"></a>_umask_s
Define a máscara de permissão de arquivo padrão. Uma versão de [_unmask](../../c-runtime-library/reference/umask.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _umask_s(  
   int mode,  
   int * pOldMode  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `mode`  
 Configuração de permissão padrão.  
  
 [out] `oldMode`  
 O valor anterior da configuração de permissão.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um código de erro se `Mode` não especifica um modo válido ou o ponteiro `pOldMode` é `NULL`.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`mode`|`pOldMode`|**Valor retornado**|**Conteúdo de**  `oldMode`|  
|------------|----------------|----------------------|--------------------------------|  
|qualquer|`NULL`|`EINVAL`|não modificado|  
|modo inválido|qualquer|`EINVAL`|não modificado|  
  
 Se uma das condições de erro acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `_umask_s` retornará `EINVAL` e definirá `errno` como `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 O `_umask_s` função define a máscara de permissão de arquivo do processo atual para o modo especificado por `mode`. A máscara de permissão de arquivo modifica a configuração de permissão de novos arquivos criados por `_creat`, `_open` ou `_sopen`. Se um bit na máscara for 1, o bit correspondente no valor da permissão solicitada do arquivo será definido como 0 (não permitido). Se um bit na máscara for 0, o bit correspondente será deixado inalterado. A configuração de permissão para um novo arquivo não é definida até que o arquivo é seja fechado pela primeira vez.  
  
 A expressão de inteiro `pmode` contém uma ou ambas as seguintes constantes de manifesto, definidas em SYS\STAT.H:  
  
 `_S_IWRITE`  
 Gravação permitida.  
  
 `_S_IREAD`  
 Leitura permitida.  
  
 `_S_IREAD | _S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Quando as duas constantes são informadas, elas são associadas com o operador OR bit a bit ( `|` ). Se o argumento `mode` for `_S_IREAD`, a leitura não será permitida (o arquivo será somente gravação). Se o argumento `mode` for `_S_IWRITE`, a gravação não será permitida (o arquivo será somente leitura). Por exemplo, se o bit de gravação estiver definido na máscara, quaisquer novos arquivos serão somente leitura. Observe que nos sistemas operacionais MS-DOS e Windows, todos os arquivos podem ser lidos; não é possível conceder permissão somente gravação. Portanto, a configuração do bit de leitura `_umask_s` não tem efeito nos modos do arquivo.  
  
 Se `pmode` não for uma combinação de uma das constantes do manifesto nem incorporar um conjunto alternativo de constantes, a função simplesmente as ignorará.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_umask_s`|\<io.h> e \<sys/stat.h> e \<sys/types.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_umask_s.c  
/* This program uses _umask_s to set  
 * the file-permission mask so that all future  
 * files will be created as read-only files.  
 * It also displays the old mask.  
 */  
  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <io.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int oldmask, err;  
  
   /* Create read-only files: */  
   err = _umask_s( _S_IWRITE, &oldmask );  
   if (err)  
   {  
      printf("Error setting the umask.\n");  
      exit(1);  
   }  
   printf( "Oldmask = 0x%.4x\n", oldmask );  
}  
```  
  
```Output  
Oldmask = 0x0000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_chmod, _wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [_mkdir, _wmkdir](../../c-runtime-library/reference/mkdir-wmkdir.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_umask](../../c-runtime-library/reference/umask.md)