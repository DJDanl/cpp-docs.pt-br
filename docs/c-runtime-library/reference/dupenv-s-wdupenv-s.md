---
title: "_dupenv_s, _wdupenv_s | Microsoft Docs"
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
  - "_dupenv_s"
  - "_wdupenv_s"
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
  - "api-ms-win-crt-environment-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "tdupenv_s"
  - "_dupenv_s"
  - "wdupenv_s"
  - "dupenv_s"
  - "_tdupenv_s"
  - "_wdupenv_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _dupenv_s"
  - "Função _tdupenv_s"
  - "Função _wdupenv_s"
  - "Função dupenv_s"
  - "variáveis de ambiente"
  - "Função tdupenv_s"
  - "Função wdupenv_s"
ms.assetid: b729ecc2-a31d-4ccf-92a7-5accedb8f8c8
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _dupenv_s, _wdupenv_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um valor do ambiente atual.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t _dupenv_s(    char **buffer,    size_t *numberOfElements,    const char *varname ); errno_t _wdupenv_s(    wchar_t **buffer,    size_t *numberOfElements,    const wchar_t *varname );  
```  
  
#### Parâmetros  
 `buffer`  
 Buffer para armazenar o valor da variável.  
  
 `numberOfElements`  
 Tamanho de `buffer`.  
  
 `varname`  
 Nome da variável de ambiente.  
  
## Valor de retorno  
 Zero em caso de êxito; código de erro em caso de falha.  
  
 Essas funções validam seus parâmetros. Se `buffer` ou `varname` for `NULL`, o manipulador de parâmetros inválido será invocado como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Se essas funções não puderem alocar memória suficiente, elas definirão `buffer` como `NULL` e `numberOfElements` como 0, além de retornar `ENOMEM`.  
  
## Comentários  
 A função `_dupenv_s` pesquisa `varname` na lista de variáveis de ambiente.  Se a variável for encontrada, `_dupenv_s` alocará um buffer e copiará o valor da variável para o buffer.  O endereço e o tamanho do buffer são retornados em `buffer` e `numberOfElements`.  Alocando o próprio buffer, `_dupenv_s` oferece uma alternativa mais conveniente para [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
> [!NOTE]
>  É de responsabilidade do programa chamador liberar a memória chamando [free](../../c-runtime-library/reference/free.md).  
  
 Se a variável não for encontrada, `buffer` será definido como `NULL`, `numberOfElements` será definido como 0 e o valor retornado será 0, pois essa situação não é considerada uma condição de erro.  
  
 Se não tiver interesse no tamanho do buffer, você poderá passar `NULL` para `numberOfElements`.  
  
 `_dupenv_s` não diferencia maiúsculas de minúsculas no sistema operacional Windows.  `_dupenv_s` usa a cópia do ambiente apontado pela variável global `_environ` para acessar o ambiente.  Consulte os Comentários em [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md) para ver uma discussão de `_environ`.  
  
 O valor em `buffer` é uma cópia do valor da variável de ambiente. Modificá\-lo não afeta o ambiente.  Use a função [\_putenv\_s, \_wputenv\_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md) para modificar o valor de uma variável de ambiente.  
  
 `_wdupenv_s` é uma versão de caractere largo de `_dupenv_s`. Os argumentos de `_wdupenv_s` são cadeias de caracteres largas.  A variável global `_wenviron` é uma versão de caractere largo de `_environ`.  Consulte os Comentários em [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md) para obter mais informações em `_wenviron`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tdupenv_s`|`_dupenv_s`|`_dupenv_s`|`_wdupenv_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_dupenv_s`|\<stdlib.h\>|  
|`_wdupenv_s`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_dupenv_s.c  
#include  <stdlib.h>  
  
int main( void )  
{  
   char *pValue;  
   size_t len;  
   errno_t err = _dupenv_s( &pValue, &len, "pathext" );  
   if ( err ) return -1;  
   printf( "pathext = %s\n", pValue );  
   free( pValue );  
   err = _dupenv_s( &pValue, &len, "nonexistentvariable" );  
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
 [\_dupenv\_s\_dbg, \_wdupenv\_s\_dbg](../../c-runtime-library/reference/dupenv-s-dbg-wdupenv-s-dbg.md)   
 [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md)   
 [\_putenv\_s, \_wputenv\_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md)