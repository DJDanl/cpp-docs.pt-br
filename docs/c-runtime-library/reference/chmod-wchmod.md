---
title: _chmod, _wchmod
ms.date: 4/2/2020
api_name:
- _chmod
- _wchmod
- _o__chmod
- _o__wchmod
api_location:
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _chmod
- _wchmod
- wchmod
helpviewer_keywords:
- _chmod function
- wchmod function
- file permissions [C++]
- chmod function
- files [C++], changing permissions
- _wchmod function
ms.assetid: 92f7cb86-b3b0-4232-a599-b8c04a2f2c19
ms.openlocfilehash: faceb49c921162da042f863abbebbe2ef0a52153
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81350084"
---
# <a name="_chmod-_wchmod"></a>_chmod, _wchmod

Altera as configurações de permissão de arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _chmod( const char *filename, int pmode );
int _wchmod( const wchar_t *filename, int pmode );
```

### <a name="parameters"></a>Parâmetros

*Filename*<br/>
Nome do arquivo existente.

*Pmode*<br/>
Configuração de permissão para o arquivo.

## <a name="return-value"></a>Valor retornado

Essas funções retornarão 0 se a configuração de permissão for alterada com êxito. Um valor de retorno de -1 indica falha. Se o arquivo especificado não puder ser encontrado, **errno** será definido **como ENOENT;** se um parâmetro for inválido, **errno** será definido **como EINVAL**.

## <a name="remarks"></a>Comentários

A função **_chmod** altera a configuração de permissão do arquivo especificado pelo *nome do arquivo*. A configuração de permissão controla o acesso de leitura e gravação para o arquivo. O *pmode* de expressão inteiro contém uma ou ambas as seguintes constantes de manifesto, definidas em SYS\Stat.h.

| *Pmode* | Significado |
|-|-|
| **\_S\_IREAD** | Somente a leitura é permitida. |
| **\_S\_IWRITE** | Gravação permitida. (Na verdade, permite leitura e gravação.) |
| **\_S\_IREAD** &#124; ** \_\_S IWRITE** | Leitura e gravação permitidas. |

Quando ambas as constantes são dadas, elas**\|** são unidas com o bitwise ou operador ( ). Se a permissão de gravação não for fornecida, o arquivo será somente leitura. Observe que todos os arquivos são sempre legíveis; não é possível dar permissão somente gravação. Assim, os modos **_S_IWRITE** e **_S_IREAD** \| **_S_IWRITE** são equivalentes.

**_wchmod** é uma versão ampla de **_chmod;** o argumento *de nome de arquivo* para **_wchmod** é uma seqüência de caracteres amplo. **_wchmod** e **_chmod** se comportam de forma idêntica.

Essa função valida seus parâmetros. Se *o pmode* não é uma combinação de uma das constantes manifestas ou incorpora um conjunto alternativo de constantes, a função simplesmente ignora essas. Se *o nome do arquivo* for **NULL,** o manipulador de parâmetros inválidos será invocado, conforme descrito na Validação de [Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna -1.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tchmod**|**_chmod**|**_chmod**|**_wchmod**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_chmod**|\<io.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|
|**_wchmod**|\<io.h> ou \<wchar.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_chmod.c
// This program uses _chmod to
// change the mode of a file to read-only.
// It then attempts to modify the file.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Change the mode and report error or success
void set_mode_and_report(char * filename, int mask)
{
   // Check for failure
   if( _chmod( filename, mask ) == -1 )
   {
      // Determine cause of failure and report.
      switch (errno)
      {
         case EINVAL:
            fprintf( stderr, "Invalid parameter to chmod.\n");
            break;
         case ENOENT:
            fprintf( stderr, "File %s not found\n", filename );
            break;
         default:
            // Should never be reached
            fprintf( stderr, "Unexpected error in chmod.\n" );
       }
   }
   else
   {
      if (mask == _S_IREAD)
        printf( "Mode set to read-only\n" );
      else if (mask & _S_IWRITE)
        printf( "Mode set to read/write\n" );
   }
   fflush(stderr);
}

int main( void )
{

   // Create or append to a file.
   system( "echo /* End of file */ >> crt_chmod.c_input" );

   // Set file mode to read-only:
   set_mode_and_report("crt_chmod.c_input ", _S_IREAD );

   system( "echo /* End of file */ >> crt_chmod.c_input " );

   // Change back to read/write:
   set_mode_and_report("crt_chmod.c_input ", _S_IWRITE );

   system( "echo /* End of file */ >> crt_chmod.c_input " );
}
```

```Output

A line of text.
```

```Output

      A line of text.Mode set to read-only
Access is denied.
Mode set to read/write
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
