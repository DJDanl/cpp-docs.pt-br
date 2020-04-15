---
title: _makepath, _wmakepath
ms.date: 4/2/2020
api_name:
- _makepath
- _wmakepath
- _o__makepath
- _o__wmakepath
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
- _wmakepath
- _tmakepath
- makepath
- tmakepath
- wmakepath
- _makepath
helpviewer_keywords:
- _makepath function
- wmakepath function
- makepath function
- _tmakepath function
- paths
- _wmakepath function
- tmakepath function
ms.assetid: 5930b197-a7b8-46eb-8519-2841a58cd026
ms.openlocfilehash: b92e056816183b4bbb07edb3efec4415655d655e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341586"
---
# <a name="_makepath-_wmakepath"></a>_makepath, _wmakepath

Crie um nome de caminho com base em componentes. Versões mais seguras dessas funções estão disponíveis; consulte [_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md).

## <a name="syntax"></a>Sintaxe

```C
void _makepath(
   char *path,
   const char *drive,
   const char *dir,
   const char *fname,
   const char *ext
);
void _wmakepath(
   wchar_t *path,
   const wchar_t *drive,
   const wchar_t *dir,
   const wchar_t *fname,
   const wchar_t *ext
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Buffer de caminho completo.

*Dirigir*<br/>
Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. **_makepath** insere o cólon automaticamente no caminho composto se estiver faltando. Se *a unidade* for **NULL** ou apontapara uma seqüência de string vazia, nenhuma letra de unidade será exibida na seqüência de *caminho* composto.

*Dir*<br/>
Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra de arrasto é opcional, e uma barra\\para a frente (/) ou uma barra invertida ( ) ou ambas podem ser usadas em um único argumento *dir.* Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se *dir* for **NULL** ou apontar para uma seqüência de string vazia, nenhum caminho de diretório será inserido na string *de caminho* composto.

*Fname*<br/>
Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se *fname* for **NULL** ou aponta para uma seqüência de string vazia, nenhum nome de arquivo será inserido na seqüência *de caminho* composto.

*Ext*<br/>
Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). **_makepath** insere o período automaticamente se ele não aparecer em *ramal*. Se *o ramo* for **NULO** ou apontapara uma seqüência vazia, nenhuma extensão será inserida na seqüência *de caminho* composto.

## <a name="remarks"></a>Comentários

A função **_makepath** cria uma seqüência de caminho composto a partir de componentes individuais, armazenando o resultado em *caminho*. O *caminho* pode incluir uma letra de unidade, caminho de diretório, nome de arquivo e extensão de nome de arquivo. **_wmakepath** é uma versão ampla de **_makepath;** os argumentos para **_wmakepath** são cordas de caracteres largos. **_wmakepath** e **_makepath** se comportam de forma idêntica.

**Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. Para evitar a ultraserção do buffer, a seqüência de terminação nula não deve exceder o tamanho do buffer de *caminho.* **_makepath** não garante que o comprimento da seqüência de caminho composto não exceda **_MAX_PATH**. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmakepath**|**_makepath**|**_makepath**|**_wmakepath**|

O argumento *do caminho* deve apontar para um buffer vazio grande o suficiente para manter o caminho completo. O *caminho* composto não deve ser maior do que **a** _MAX_PATH constante, definida em Stdlib.h.

Se o caminho for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Além disso, **errno** está definido **como EINVAL**. **Valores NULL** são permitidos para todos os outros parâmetros.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_makepath**|\<stdlib.h>|
|**_wmakepath**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_makepath.c
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char path_buffer[_MAX_PATH];
   char drive[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fname[_MAX_FNAME];
   char ext[_MAX_EXT];

   _makepath( path_buffer, "c", "\\sample\\crt\\", "makepath", "c" ); // C4996
   // Note: _makepath is deprecated; consider using _makepath_s instead
   printf( "Path created with _makepath: %s\n\n", path_buffer );
   _splitpath( path_buffer, drive, dir, fname, ext ); // C4996
   // Note: _splitpath is deprecated; consider using _splitpath_s instead
   printf( "Path extracted with _splitpath:\n" );
   printf( "   Drive: %s\n", drive );
   printf( "   Dir: %s\n", dir );
   printf( "   Filename: %s\n", fname );
   printf( "   Ext: %s\n", ext );
}
```

```Output
Path created with _makepath: c:\sample\crt\makepath.c

Path extracted with _splitpath:
   Drive: c:
   Dir: \sample\crt\
   Filename: makepath
   Ext: .c
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
[_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md)<br/>
