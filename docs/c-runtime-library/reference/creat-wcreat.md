---
title: _creat, _wcreat | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: 73ed20925501e9f797e7a5a2b7895ff0f80a5b1a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="creat-wcreat"></a>_creat, _wcreat

Cria um novo arquivo. **Creat** e **wcreat** foram preteridos; use [sopen_s, wsopen_s](sopen-s-wsopen-s.md) em vez disso.

## <a name="syntax"></a>Sintaxe

```C
int _creat(
   const char *filename,
   int pmode
);
int _wcreat(
   const wchar_t *filename,
   int pmode
);
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Nome do novo arquivo.

*pmode*<br/>
Configuração de permissão.

## <a name="return-value"></a>Valor de retorno

Essas funções, se tiverem êxito, retornarão um descritor de arquivo para o arquivo criado. Caso contrário, as funções de retornam -1 e defina **errno** conforme mostrado na tabela a seguir.

|**errno** configuração|Descrição|
|---------------------|-----------------|
|**EACCES**|*nome de arquivo* Especifica um arquivo somente leitura existente ou especifica um diretório em vez de um arquivo.|
|**EMFILE**|Nenhum outro descritor de arquivo disponível.|
|**ENOENT**|Não foi possível encontrar o arquivo especificado.|

Se *filename* for NULL, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL** e retorne -1.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **Creat** função ou cria um novo arquivo é aberto e trunca um existente. **wcreat** é uma versão de caractere largo de **Creat**; o *filename* argumento **wcreat** é uma cadeia de caracteres largos. **wcreat** e **Creat** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tcreat**|**_creat**|**_creat**|**_wcreat**|

Se o arquivo especificado por *filename* não existir, um novo arquivo é criado com a configuração de permissão fornecida e está aberto para gravação. Se o arquivo já existe e sua configuração de permissão permite gravar, **Creat** trunca o arquivo para o comprimento 0, o conteúdo anterior, a destruição e abre-o para gravação. A configuração de permissão, *pmode*, aplica-se a somente os arquivos recém-criados. O novo arquivo recebe a configuração de permissão especificada depois que ele é fechado pela primeira vez. A expressão de inteiro *pmode* contém uma ou ambas as constantes manifestos **s_iwrite** e **s_iread**, definido em SYS\Stat.h. Quando ambas as constantes são fornecidas, elas estão unidas com o bit a bit ou operador ( **&#124;** ). O *pmode* parâmetro é definido como um dos valores a seguir.

|Valor|Definição|
|-----------|----------------|
|**S_IWRITE**|Gravação permitida.|
|**S_IREAD**|Leitura permitida.|
|**S_IREAD** &AMP;#124; **S_IWRITE**|Leitura e gravação permitidas.|

Se a permissão de gravação não for fornecida, o arquivo será somente leitura. Todos os arquivos são sempre legíveis; é impossível conceder permissão somente gravação. Os modos de **s_iwrite** e **s_iread** | **s_iwrite** , em seguida, são equivalentes. Arquivos abertos com **Creat** são sempre abertos no modo de compatibilidade (consulte [sopen](sopen-wsopen.md)) com **sh_denyno**.

**Creat** aplica-se a máscara de permissão de arquivo atual para *pmode* antes de definir as permissões (consulte [umask](umask.md)). **Creat** é fornecida principalmente para compatibilidade com bibliotecas anteriores. Uma chamada para **abrir** com **o_creat** e **o_trunc** no *oflag* parâmetro é equivalente à **Creat**e é preferível para o novo código.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_creat**|\<io.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|
|**_wcreat**|\<io.h> ou \<wchar.h>|\<sys/types.h>, \<sys/stat.h>, \<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_chsize](chsize.md)<br/>
[_close](close.md)<br/>
[_dup, _dup2](dup-dup2.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_sopen, _wsopen](sopen-wsopen.md)<br/>
[_umask](umask.md)<br/>
