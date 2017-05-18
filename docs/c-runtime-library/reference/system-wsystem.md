---
title: system, _wsystem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- system
- _wsystem
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
- _tsystem
- _wsystem
dev_langs:
- C++
helpviewer_keywords:
- _wsystem function
- wsystem function
- tsystem function
- _tsystem function
- system function
- commands, executing
- command interpreter
ms.assetid: 7d3df2b6-f742-49ce-bf52-012b0aee3df5
caps.latest.revision: 17
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 3ce182dd28fa5af0fef9c2c51c14fc54aa5af972
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="system-wsystem"></a>system, _wsystem
Executa um comando.  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int system(  
   const char *command   
);  
int _wsystem(  
   const wchar_t *command   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `command`  
 O comando a ser executado.  
  
## <a name="return-value"></a>Valor de retorno  
 Se `command` for `NULL` e o interpretador de comandos for encontrado, retornará um valor diferente de zero. Se o interpretador de comandos não for encontrado, retornará 0 e definirá `errno` como `ENOENT`. Se `command` não for `NULL`, `system` retornará o valor retornado pelo interpretador de comandos. Retornará o valor 0 somente se o interpretador de comandos retornar o valor 0. Um valor de retorno - 1 indica um erro, e `errno` é definido como um dos seguintes valores:  
  
 `E2BIG`  
 A lista de argumentos (que é dependente do sistema) é muito grande.  
  
 `ENOENT`  
 Não foi possível encontrar o interpretador de comandos.  
  
 `ENOEXEC`  
 O arquivo do interpretador de comandos não pode ser executado porque o formato não é válido.  
  
 `ENOMEM`  
 Não há memória suficiente disponível para executar o comando, a memória disponível foi corrompida ou há um bloco inválido, indicando que o processo que está fazendo a chamada não foi alocado corretamente.  
  
 Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de retorno.  
  
## <a name="remarks"></a>Comentários  
 A função `system` passa `command` para o interpretador de comandos, que executa a cadeia de caracteres como um comando do sistema operacional. `system` usa as variáveis de ambiente `COMSPEC` e `PATH` para localizar o CMD.exe do arquivo do interpretador de comandos. Se `command` for `NULL`, a função apenas verificará se o interpretador de comandos existe.  
  
 É necessário liberar explicitamente – usando `fflush` ou `_flushall` – ou fechar qualquer fluxo antes de chamar `system`.  
  
 A função `_wsystem` é uma versão de caractere largo da função `system`; o argumento `command` para `_wsystem` é uma cadeia de caracteres larga. Caso contrário, essas funções se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tsystem`|`system`|`system`|`_wsystem`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`system`|\<process.h> ou \<stdlib.h>|  
|`_wsystem`|\<process.h>, \<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Esse exemplo usa `system` para usar TYPE em um arquivo de texto.  
  
```  
// crt_system.c  
  
#include <process.h>  
  
int main( void )  
{  
   system( "type crt_system.txt" );  
}  
```  
  
## <a name="input-crtsystemtxt"></a>Entrada: crt_system.txt  
  
```  
Line one.  
Line two.  
```  
  
### <a name="output"></a>Saída  
  
```  
Line one.  
Line two.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_flushall](../../c-runtime-library/reference/flushall.md)   
 [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)
