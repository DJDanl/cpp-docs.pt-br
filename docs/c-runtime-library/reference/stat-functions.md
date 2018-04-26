---
title: _stat, _stat32, _stat64, _stati64, _stat32i64, _stat64i32, _wstat, _wstat32, _wstat64, _wstati64, _wstat32i64, _wstat64i32 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wstat64
- _stati64
- _stat32
- _stat32i64
- _stat
- _wstati64
- _wstat32
- _wstat64i32
- _wstat
- _stat64
- _stat64i32
- _wstat32i64
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
- tstat32
- tstat
- _tstat64i32
- tstati64
- _wstat64
- _wstat32
- wstati64
- tstat64
- _stati64
- _wstat
- wstat64i32
- stat32i64
- tstat32i64
- _tstat
- _wstati64
- _tstati64
- _wstat32i64
- wstat32
- _wstat64i32
- _stat
- _tstat32
- stat64i32
- wstat64
- stat
- _stat32i64
- _stat32
- stati64
- wstat
- _stat64i32
- stat32
- _tstat32i64
- tstat64i32
- _tstat64
- _stat64
- stat/_stat
- stat/_stat32
- stat/_stat64
- stat/_stati64
- stat/_stat32i64
- stat/_stat64i32
- stat/_wstat
- stat/_wstat32
- stat/_wstat64
- stat/_wstati64
- stat/_wstat32i64
- stat/_wstat64i32
dev_langs:
- C++
helpviewer_keywords:
- files [C++], status information
- _stat function
- _wstat function
- _stat64i32 function
- tstat function
- _tstat64i32 function
- _stati64 function
- _stat64 function
- tstati64 function
- wstati64 function
- wstat64 function
- _wstat64i32 function
- _tstat32i64 function
- _stat32i64 function
- stat function
- status of files
- _tstat32 function
- tstat64 function
- _wstat64 function
- _tstat function
- _stat32 function
- wstat function
- _wstat32i64 function
- _tstati64 function
- _wstat32 function
- stat64 function
- stati64 function
- _wstati64 function
- _tstat64 function
- files [C++], getting status information
ms.assetid: 99a75ae6-ff26-47ad-af70-5ea7e17226a5
caps.latest.revision: 26
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fb70840985c7d6f574a37aef535f35f63c0f4333
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="stat-stat32-stat64-stati64-stat32i64-stat64i32-wstat-wstat32-wstat64-wstati64-wstat32i64-wstat64i32"></a>_stat, _stat32, _stat64, _stati64, _stat32i64, _stat64i32, _wstat, _wstat32, _wstat64, _wstati64, _wstat32i64, _wstat64i32

Obtenha informações de status em um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _stat(
   const char *path,
   struct _stat *buffer
);
int _stat32(
   const char *path,
   struct __stat32 *buffer
);
int _stat64(
   const char *path,
   struct __stat64 *buffer
);
int _stati64(
   const char *path,
   struct _stati64 *buffer
);
int _stat32i64(
   const char *path,
   struct _stat32i64 *buffer
);
int _stat64i32(
   const char *path,
   struct _stat64i32 *buffer
);
int _wstat(
   const wchar_t *path,
   struct _stat *buffer
);
int _wstat32(
   const wchar_t *path,
   struct __stat32 *buffer
);
int _wstat64(
   const wchar_t *path,
   struct __stat64 *buffer
);
int _wstati64(
   const wchar_t *path,
   struct _stati64 *buffer
);
int _wstat32i64(
   const wchar_t *path,
   struct _stat32i64 *buffer
);
int _wstat64i32(
   const wchar_t *path,
   struct _stat64i32 *buffer
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Ponteiro para uma cadeia de caracteres contendo o caminho do arquivo ou diretório existente.

*buffer*<br/>
Ponteiro para estrutura que armazena os resultados.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retornará 0 se as informações de status do arquivo forem obtidas. Um valor de retorno de -1 indica um erro, caso em que **errno** é definido como **ENOENT**, indicando que o caminho ou nome de arquivo não pôde ser encontrado. Um valor de retorno **EINVAL** indica um parâmetro inválido; **errno** também é definido como **EINVAL** nesse caso.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

O carimbo de data em um arquivo pode ser representado se ele é posterior de 1º de janeiro de 1970, meia-noite e antes de 23:59:59, 31 de dezembro de 3000 a UTC, a menos que você use **stat32** ou **wstat32**, ou definiu **_ USE_32BIT_TIME_T**, caso em que a data pode ser representada somente até 23:59:59 18 de janeiro de 2038, UTC.

## <a name="remarks"></a>Comentários

O **STAT** função obtém informações sobre o arquivo ou diretório especificado por *caminho* e o armazena na estrutura apontada pelo *buffer*. **STAT** manipula automaticamente os argumentos da cadeia de caracteres multibyte conforme apropriado, reconhecer sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento.

**wstat** é uma versão de caractere largo de **STAT**; o *caminho* argumento **wstat** é uma cadeia de caracteres largos. **wstat** e **STAT** tenham comportamento idêntico, exceto que **wstat** não trata cadeias de caracteres multibyte.

Variações dessas funções dão suporte a tipos de hora de 32 ou 64 bits e a tamanhos de arquivo de 32 ou 64 bits. O primeiro sufixo numérico (**32** ou **64**) indica o tamanho do tempo tipo usado; é o sufixo do segundo **i32** ou **i64**, que indica se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits.

**STAT** é equivalente a **_stat64i32**, e **struct** **STAT** contém um tempo de 64 bits. Isso é verdadeiro, a menos que **_USE_32BIT_TIME_T** for definido, caso em que o comportamento antigo está em vigor; **STAT** usa um tempo de 32 bits, e **struct** **STAT** contém um tempo de 32 bits. O mesmo é verdadeiro para **stati64**.

> [!NOTE]
> **wstat** não funciona com links simbólicos do Windows Vista. Nesses casos, **wstat** sempre relatará um tamanho de arquivo de 0. **STAT** funcionar corretamente com links simbólicos.

Essa função valida seus parâmetros. Se qualquer um dos *caminho* ou *buffer* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md).

### <a name="time-type-and-file-length-type-variations-of-stat"></a>Variações de tipo de hora e de tipo de tamanho de arquivo de _stat

|Funções|_USE_32BIT_TIME_T definido?|Tipo de hora|Tipo de tamanho de arquivo|
|---------------|------------------------------------|---------------|----------------------|
|**STAT**, **wstat**|Não definido|64 bits|32 bits|
|**STAT**, **wstat**|Definido|32 bits|32 bits|
|**stat32**, **wstat32**|Não afetado pela definição de macro|32 bits|32 bits|
|**stat64**, **wstat64**|Não afetado pela definição de macro|64 bits|64 bits|
|**stati64**, **wstati64**|Não definido|64 bits|64 bits|
|**stati64**, **wstati64**|Definido|32 bits|64 bits|
|**_stat32i64**, **_wstat32i64**|Não afetado pela definição de macro|32 bits|64 bits|
|**_stat64i32**, **_wstat64i32**|Não afetado pela definição de macro|64 bits|32 bits|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tstat**|**_stat**|**_stat**|**_wstat**|
|**tstat64**|**_stat64**|**_stat64**|**_wstat64**|
|**tstati64**|**_stati64**|**_stati64**|**_wstati64**|
|**_tstat32i64**|**_stat32i64**|**_stat32i64**|**_wstat32i64**|
|**_tstat64i32**|**_stat64i32**|**_stat64i32**|**_wstat64i32**|

O **STAT** estrutura, definida em SYS\STAT. H, inclui os seguintes campos.

|Campo||
|-|-|
**st_gid**|Identificador numérico do grupo que possui o arquivo (específico do UNIX). Esse campo sempre será zero em sistemas Windows. Um arquivo redirecionado é classificado como um arquivo do Windows.
**st_atime**|Hora do último acesso ao arquivo. Válido em unidades de disco formatadas como NTFS, mas não naquelas formatadas como FAT.
**st_ctime**|Hora de criação do arquivo. Válido em unidades de disco formatadas como NTFS, mas não naquelas formatadas como FAT.
**st_dev**|Número do disco que contém o arquivo da unidade (mesmo que **st_rdev**).
**st_ino**|Número de nó de informações (o **inode**) para o arquivo (específico para UNIX). Em sistemas de arquivos UNIX, o **inode** descreve a data do arquivo e os carimbos de hora, permissões e conteúdo. Quando arquivos são vinculados entre si, eles compartilham o mesmo **inode**. O **inode**e, portanto, **st_ino**, não tem nenhum significado nos sistemas de arquivos FAT, HPFS ou NTFS.
**st_mode**|Máscara de bits para informações sobre o modo de arquivo. O **s_ifdir** bit é definido se *caminho* Especifica um diretório; o **s_ifreg** bit é definido se *caminho* Especifica um arquivo comum ou um dispositivo. Bits de leitura/gravação do usuário são definidos de acordo com o modo de permissão do arquivo; bits de execução do usuário são definidos de acordo com a extensão de nome de arquivo.
**st_mtime**|Hora da última modificação do arquivo.
**st_nlink**|Sempre 1 em sistemas de arquivos diferentes de NTFS.
**st_rdev**|Número do disco que contém o arquivo da unidade (mesmo que **st_dev**).
**st_size**|Tamanho do arquivo em bytes. um inteiro de 64 bits para variações com o **i64** sufixo.
**st_uid**|Identificador numérico do usuário que possui o arquivo (específico do UNIX). Esse campo sempre será zero em sistemas Windows. Um arquivo redirecionado é classificado como um arquivo do Windows.

Se *caminho* refere-se a um dispositivo, o **st_size**, vários campos de hora, **st_dev**, e **st_rdev** campos de **STAT**  estrutura não fazem sentido. Já que STAT.H usa o tipo [_dev_t](../../c-runtime-library/standard-types.md), que é definido em TYPES.H, você deve incluir TYPES.H antes de STAT.H em seu código.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|
|-------------|---------------------|----------------------|
|**STAT**, **stat32**, **stat64**, **stati64**, **_stat32i64**, **_stat64i32**|\<sys/types.h> seguido de \<sys/stat.h>|\<errno.h>|
|**wstat**, **wstat32**, **wstat64**, **wstati64**, **_wstat32i64**, **_wstat64i32**|\<sys/types.h> seguido de \<sys/stat.h> ou \<wchar.h>|\<errno.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_stat.c
// This program uses the _stat function to
// report information about the file named crt_stat.c.

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main( void )
{
   struct _stat buf;
   int result;
   char timebuf[26];
   char* filename = "crt_stat.c";
   errno_t err;

   // Get data associated with "crt_stat.c":
   result = _stat( filename, &buf );

   // Check if statistics are valid:
   if( result != 0 )
   {
      perror( "Problem getting information" );
      switch (errno)
      {
         case ENOENT:
           printf("File %s not found.\n", filename);
           break;
         case EINVAL:
           printf("Invalid parameter to _stat.\n");
           break;
         default:
           /* Should never be reached. */
           printf("Unexpected error in _stat.\n");
      }
   }
   else
   {
      // Output some of the statistics:
      printf( "File size     : %ld\n", buf.st_size );
      printf( "Drive         : %c:\n", buf.st_dev + 'A' );
      err = ctime_s(timebuf, 26, &buf.st_mtime);
      if (err)
      {
         printf("Invalid arguments to ctime_s.");
         exit(1);
      }
      printf( "Time modified : %s", timebuf );
   }
}
```

```Output
File size     : 732
Drive         : C:
Time modified : Thu Feb 07 14:39:36 2002
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32](fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_setmbcp](setmbcp.md)<br/>
