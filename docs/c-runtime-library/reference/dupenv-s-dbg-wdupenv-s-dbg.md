---
title: "_dupenv_s_dbg, _wdupenv_s_dbg | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_dupenv_s_dbg"
  - "_wdupenv_s_dbg"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tdupenv_s_dbg"
  - "_dupenv_s_dbg"
  - "_wdupenv_s_dbg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tdupenv_s_dbg"
  - "Função dupenv_s_dbg"
  - "Função _wdupenv_s_dbg"
  - "variáveis de ambiente"
  - "Função tdupenv_s_dbg"
  - "Função wdupenv_s_dbg"
  - "Função _dupenv_s_dbg"
ms.assetid: e3d81148-e24e-46d0-a21d-fd87b5e6256c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _dupenv_s_dbg, _wdupenv_s_dbg
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obter um valor do ambiente atual.  Versões de [\_dupenv\_s, \_wdupenv\_s](../../c-runtime-library/reference/dupenv-s-wdupenv-s.md) que atribuem a memória com [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md) para fornecer informações de depuração adicional.  
  
## Sintaxe  
  
```  
errno_t _dupenv_s_dbg(  
   char **buffer,  
   size_t *numberOfElements,  
   const char *varname,  
   int blockType,  
   const char *filename,  
   int linenumber  
);  
errno_t _wdupenv_s_dbg(  
   wchar_t **buffer,  
   size_t * numberOfElements,  
   const wchar_t *varname,  
   int blockType,  
   const char *filename,  
   int linenumber  
);  
```  
  
#### Parâmetros  
 `buffer`  
 Buffer para armazenar o valor da variável.  
  
 `numberOfElements`  
 Tamanho do `buffer`.  
  
 `varname`  
 Nome de variável de ambiente.  
  
 `blockType`  
 O tipo solicitado do bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem ou de `NULL`.  
  
 `linenumber`  
 Número de linha no arquivo de origem ou em `NULL`.  
  
## Valor de retorno  
 Zero se tiver êxito, um código de erro em falha.  
  
 Essas funções validam seus parâmetros; se `buffer` ou `varname` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções serão definidas `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Se essas funções não puderem atribuir memória suficiente, definirão `buffer` para `NULL` e `numberOfElements` para 0, e retornarão `ENOMEM`.  
  
## Comentários  
 As funções de `_dupenv_s_dbg` e de `_wdupenv_s_dbg` são idênticas a `_dupenv_s` e a `_wdupenv_s` exceto que, quando `_DEBUG` é definido, essas funções usam a versão de depuração de [malloc](../../c-runtime-library/reference/malloc.md), [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md), para alocar memória para o valor da variável de ambiente.  Para obter informações sobre os recursos de depuração de `_malloc_dbg`, consulte [\_malloc\_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Você não precisa chamar explicitamente na maioria dos casos essas funções.  Em vez disso, você pode definir o sinalizador `_CRTDBG_MAP_ALLOC`.  Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas para `_dupenv_s` e `_wdupenv_s` remapeou a `_dupenv_s_dbg` e a `_wdupenv_s_dbg`, respectivamente, com `blockType` definido como `_NORMAL_BLOCK`.  Assim, você não precisa chamar explicitamente essas funções a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`.  Para obter mais informações sobre os tipos do bloco, consulte [Tipos de blocos na heap de depuração](../Topic/CRT%20Debug%20Heap%20Details.md#BKMK_Types_of_blocks_on_the_debug_heap).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tdupenv_s_dbg`|`_dupenv_s_dbg`|`_dupenv_s_dbg`|`_wdupenv_s_dbg`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_dupenv_s_dbg`|\<crtdbg.h\>|  
|`_wdupenv_s_dbg`|\<crtdbg.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_dupenv_s_dbg.c  
#include  <stdlib.h>  
#include <crtdbg.h>  
  
int main( void )  
{  
   char *pValue;  
   size_t len;  
   errno_t err = _dupenv_s_dbg( &pValue, &len, "pathext",  
      _NORMAL_BLOCK, __FILE__, __LINE__ );  
   if ( err ) return -1;  
   printf( "pathext = %s\n", pValue );  
   free( pValue );  
   err = _dupenv_s_dbg( &pValue, &len, "nonexistentvariable",  
      _NORMAL_BLOCK, __FILE__, __LINE__ );  
   if ( err ) return -1;  
   printf( "nonexistentvariable = %s\n", pValue );  
   free( pValue ); // It's OK to call free with NULL  
}  
```  
  
## Saída de Exemplo  
  
```  
pathext = .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.pl  
nonexistentvariable = (null)  
```  
  
## Equivalência do .NET Framework  
 [System::Environment::GetEnvironmentVariable](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)   
 [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md)   
 [\_putenv\_s, \_wputenv\_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md)