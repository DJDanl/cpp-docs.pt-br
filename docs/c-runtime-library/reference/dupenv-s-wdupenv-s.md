---
title: _dupenv_s, _wdupenv_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _dupenv_s
- _wdupenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- tdupenv_s
- _dupenv_s
- wdupenv_s
- dupenv_s
- _tdupenv_s
- _wdupenv_s
dev_langs:
- C++
helpviewer_keywords:
- _dupenv_s function
- _tdupenv_s function
- _wdupenv_s function
- environment variables
- wdupenv_s function
- dupenv_s function
- tdupenv_s function
ms.assetid: b729ecc2-a31d-4ccf-92a7-5accedb8f8c8
caps.latest.revision: 16
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
ms.openlocfilehash: b565543d5949da9870f094fff2d821e8e97ebf13
ms.lasthandoff: 02/25/2017

---
# <a name="dupenvs-wdupenvs"></a>_dupenv_s, _wdupenv_s
Obtém um valor do ambiente atual.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _dupenv_s(  
   char **buffer,  
   size_t *numberOfElements,  
   const char *varname  
);  
errno_t _wdupenv_s(  
   wchar_t **buffer,  
   size_t *numberOfElements,  
   const wchar_t *varname  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Buffer para armazenar o valor da variável.  
  
 `numberOfElements`  
 Tamanho de `buffer`.  
  
 `varname`  
 Nome da variável de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero em caso de êxito; código de erro em caso de falha.  
  
 Essas funções validam seus parâmetros. Se `buffer` ou `varname` for `NULL`, o manipulador de parâmetros inválido será invocado como descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Se essas funções não puderem alocar memória suficiente, elas definirão `buffer` como `NULL` e `numberOfElements` como 0, além de retornar `ENOMEM`.  
  
## <a name="remarks"></a>Comentários  
 A função `_dupenv_s` pesquisa `varname` na lista de variáveis de ambiente. Se a variável for encontrada, `_dupenv_s` alocará um buffer e copiará o valor da variável para o buffer. O endereço e o tamanho do buffer são retornados em `buffer` e `numberOfElements`. Ao alocar o próprio buffer, `_dupenv_s` oferece uma alternativa mais conveniente para [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
> [!NOTE]
>  É de responsabilidade do programa chamador liberar a memória chamando [free](../../c-runtime-library/reference/free.md).  
  
 Se a variável não for encontrada, `buffer` será definido como `NULL`, `numberOfElements` será definido como 0 e o valor retornado será 0, pois essa situação não é considerada uma condição de erro.  
  
 Se não tiver interesse no tamanho do buffer, você poderá passar `NULL` para `numberOfElements`.  
  
 `_dupenv_s` não diferencia maiúsculas de minúsculas no sistema operacional Windows. `_dupenv_s` usa a cópia do ambiente apontado pela variável global `_environ` para acessar o ambiente. Consulte os comentários na em [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md) para uma discussão sobre `_environ`.  
  
 O valor em `buffer` é uma cópia do valor da variável de ambiente. Modificá-lo não afeta o ambiente. Use a função [_putenv_s, _wputenv_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md) para modificar o valor de uma variável de ambiente.  
  
 `_wdupenv_s` é uma versão de caractere largo de `_dupenv_s`. Os argumentos de `_wdupenv_s` são cadeias de caracteres largas. A variável global `_wenviron` é uma versão de caractere largo de `_environ`. Consulte os comentários na em [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md) para mais sobre `_wenviron`.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tdupenv_s`|`_dupenv_s`|`_dupenv_s`|`_wdupenv_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_dupenv_s`|\<stdlib.h>|  
|`_wdupenv_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
pathext = .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.pl  
nonexistentvariable = (null)  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::Environment::GetEnvironmentVariable](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)   
 [_dupenv_s_dbg, _wdupenv_s_dbg](../../c-runtime-library/reference/dupenv-s-dbg-wdupenv-s-dbg.md)   
 [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md)   
 [_putenv_s, _wputenv_s](../../c-runtime-library/reference/putenv-s-wputenv-s.md)
