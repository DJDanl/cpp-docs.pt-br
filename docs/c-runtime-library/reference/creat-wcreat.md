---
title: _creat, _wcreat | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _creat
- _wcreat
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
- wcreat
- _wcreat
- _creat
- tcreat
- _tcreat
dev_langs:
- C++
helpviewer_keywords:
- wcreat function
- _wcreat function
- files [C++], creating
- _creat function
- tcreat function
- creat function
- _tcreat function
ms.assetid: 3b3b795d-1620-40ec-bd2b-a4bbb0d20fe5
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: f034e2b80cc1bd3e7b5fc4578a6f5e77a060593c
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="creat-wcreat"></a>_creat, _wcreat
Cria um novo arquivo. `_creat` e `_wcreat` foram preteridos; use [_sopen_s, _wsopen_s](../../c-runtime-library/reference/sopen-s-wsopen-s.md) em vez disso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _creat(   
   const char *filename,  
   int pmode   
);  
int _wcreat(   
   const wchar_t *filename,  
   int pmode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 Nome do novo arquivo.  
  
 `pmode`  
 Configuração de permissão.  
  
## <a name="return-value"></a>Valor de retorno  
 Essas funções, se tiverem êxito, retornarão um descritor de arquivo para o arquivo criado. Caso contrário, as funções de retornam -1 e defina `errno` conforme mostrado na tabela a seguir.  
  
|Configuração de `errno`|Descrição|  
|---------------------|-----------------|  
|`EACCES`|`filename` especifica um arquivo somente leitura existente ou especifica um diretório em vez de um arquivo.|  
|`EMFILE`|Nenhum outro descritor de arquivo disponível.|  
|`ENOENT`|Não foi possível encontrar o arquivo especificado.|  
  
 Se `filename` for NULL, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão -1.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_creat` cria um novo arquivo ou abre e trunca um existente. A função `_wcreat` é uma versão de caractere largo da função `_creat`; o argumento `filename` para `_wcreat` é uma cadeia de caracteres larga. Caso contrário, `_wcreat` e `_creat` se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tcreat`|`_creat`|`_creat`|`_wcreat`|  
  
 Se o arquivo especificado por `filename` não existir, um novo arquivo será criado com a configuração de permissão determinada e será aberto para gravação. Se o arquivo já existir e a configuração de permissão permitir gravação, `_creat` truncará o arquivo para o tamanho 0, destruindo o conteúdo anterior e o abrirá para gravação. A configuração de permissão, `pmode`, aplica-se somente a arquivos recém-criados. O novo arquivo recebe a configuração de permissão especificada depois que ele é fechado pela primeira vez. A expressão de inteiro `pmode` contém uma ou ambas as constantes de manifesto `_S_IWRITE` e `_S_IREAD`, definidas em SYS\Stat.h. Quando as duas constantes são fornecidas, elas são unidas com o operador `OR` bit a bit (**&#124;**). O parâmetro `pmode` é definido com um dos valores a seguir.  
  
|Valor|Definição|  
|-----------|----------------|  
|`_S_IWRITE`|Gravação permitida.|  
|`_S_IREAD`|Leitura permitida.|  
|`_S_IREAD &#124; _S_IWRITE`|Leitura e gravação permitidas.|  
  
 Se a permissão de gravação não for fornecida, o arquivo será somente leitura. Todos os arquivos são sempre legíveis; é impossível conceder permissão somente gravação. Os modos `_S_IWRITE` e `_S_IREAD | _S_IWRITE` são então equivalentes. Os arquivos abertos com o uso de `_creat` sempre são abertos no modo de compatibilidade (consulte [_sopen](../../c-runtime-library/reference/sopen-wsopen.md)) com `_SH_DENYNO`.  
  
 `_creat` aplica a máscara de permissão de arquivo atual a `pmode` antes que as permissões sejam configuradas (consulte [_umask](../../c-runtime-library/reference/umask.md)). `_creat` é fornecido principalmente para compatibilidade com bibliotecas anteriores. Uma chamada a `_open` com `_O_CREAT` e `_O_TRUNC` no parâmetro `oflag` é equivalente a `_creat` e é preferível para o novo código.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_creat`|\<io.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|  
|`_wcreat`|\<io.h> ou \<wchar.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_creat.c  
// compile with: /W3  
// This program uses _creat to create  
// the file (or truncate the existing file)  
// named data and open it for writing.  
  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int fh;  
  
   fh = _creat( "data", _S_IREAD | _S_IWRITE ); // C4996  
   // Note: _creat is deprecated; use _sopen_s instead  
   if( fh == -1 )  
      perror( "Couldn't create data file" );  
   else  
   {  
      printf( "Created data file.\n" );  
      _close( fh );  
   }  
}  
```  
  
```Output  
Created data file.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_chmod, _wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [_chsize](../../c-runtime-library/reference/chsize.md)   
 [_close](../../c-runtime-library/reference/close.md)   
 [_dup, _dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_sopen, _wsopen](../../c-runtime-library/reference/sopen-wsopen.md)   
 [_umask](../../c-runtime-library/reference/umask.md)
