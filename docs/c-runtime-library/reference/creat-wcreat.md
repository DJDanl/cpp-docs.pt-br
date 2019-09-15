---
title: _creat, _wcreat
ms.date: 11/04/2016
api_name:
- _creat
- _wcreat
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wcreat
- _wcreat
- _creat
- tcreat
- _tcreat
helpviewer_keywords:
- wcreat function
- _wcreat function
- files [C++], creating
- _creat function
- tcreat function
- creat function
- _tcreat function
ms.assetid: 3b3b795d-1620-40ec-bd2b-a4bbb0d20fe5
ms.openlocfilehash: d278bffbfdf856956a20b01da4dad2ba00952359
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938889"
---
# <a name="_creat-_wcreat"></a>_creat, _wcreat

Cria um novo arquivo. **_creat** e **_wcreat** foram preteridos; em vez disso [, use _sopen_s, _wsopen_s](sopen-s-wsopen-s.md) .

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

Essas funções, se tiverem êxito, retornarão um descritor de arquivo para o arquivo criado. Caso contrário, as funções retornam-1 e define **errno** , conforme mostrado na tabela a seguir.

|configuração de **errno**|Descrição|
|---------------------|-----------------|
|**EACCES**|*filename* especifica um arquivo somente leitura existente ou especifica um diretório em vez de um arquivo.|
|**EMFILE**|Nenhum outro descritor de arquivo disponível.|
|**ENOENT**|Não foi possível encontrar o arquivo especificado.|

Se *filename* for **NULL**, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL** e retornam-1.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_creat** cria um novo arquivo ou abre e Trunca um existente. **_wcreat** é uma versão de caractere largo do **_creat**; o argumento *filename* para **_wcreat** é uma cadeia de caracteres largos. **_wcreat** e **_creat** se comportam de outra forma.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcreat**|**_creat**|**_creat**|**_wcreat**|

Se o arquivo especificado por *filename* não existir, um novo arquivo será criado com a configuração de permissão fornecida e será aberto para gravação. Se o arquivo já existir e sua configuração de permissão permitir gravação, **_creat** truncará o arquivo para o comprimento 0, destruindo o conteúdo anterior e o abrirá para gravação. A configuração de permissão, *pmode*, aplica-se somente a arquivos recém-criados. O novo arquivo recebe a configuração de permissão especificada depois que ele é fechado pela primeira vez. A expressão de inteiro *pmode* contém uma ou ambas as constantes de manifesto **_S_IWRITE** e **_S_IREAD**, definidas em SYS\Stat.h. Quando ambas as constantes são fornecidas, elas são unidas com o operador OR ( **&#124;** ). O parâmetro *pmode* é definido como um dos valores a seguir.

|Valor|Definição|
|-----------|----------------|
|**_S_IWRITE**|Gravação permitida.|
|**_S_IREAD**|Leitura permitida.|
|**_S_IREAD** &#124; **_S_IWRITE**|Leitura e gravação permitidas.|

Se a permissão de gravação não for fornecida, o arquivo será somente leitura. Todos os arquivos são sempre legíveis; é impossível conceder permissão somente gravação. Os modos **_S_IWRITE** e **_S_IREAD** |  **_S_IWRITE** são equivalentes. Os arquivos abertos usando **_creat** sempre são abertos no modo de compatibilidade (consulte [_Sopen](sopen-wsopen.md)) com **_SH_DENYNO**.

**_creat** aplica a máscara de permissão de arquivo atual a *pmode* antes de definir as permissões (consulte [_umask](umask.md)). o **_creat** é fornecido principalmente para compatibilidade com as bibliotecas anteriores. Uma chamada para **_open** com **_O_CREAT** e **_O_TRUNC** no parâmetro *oflag* é equivalente a **_creat** e é preferível para o novo código.

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
