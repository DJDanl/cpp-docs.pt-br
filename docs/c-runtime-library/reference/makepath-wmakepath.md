---
title: _makepath, _wmakepath | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _makepath
- _wmakepath
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
- _wmakepath
- _tmakepath
- makepath
- tmakepath
- wmakepath
- _makepath
dev_langs:
- C++
helpviewer_keywords:
- _makepath function
- wmakepath function
- makepath function
- _tmakepath function
- paths
- _wmakepath function
- tmakepath function
ms.assetid: 5930b197-a7b8-46eb-8519-2841a58cd026
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21cfcfb8a1c82fb351b85b0fb169a94dd3c2c5d4
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44105081"
---
# <a name="makepath-wmakepath"></a>_makepath, _wmakepath

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
Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. **makepath** insere os dois-pontos automaticamente no caminho de composição se ele estiver ausente. Se *unidade* é **nulo** ou aponta para uma cadeia de caracteres vazia, nenhuma letra da unidade é exibida na composição *caminho* cadeia de caracteres.

*dir*<br/>
Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra à direita é opcional e uma barra (/) ou uma barra invertida (\\) ou ambas podem ser usadas em uma única *dir* argumento. Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se *dir* é **nulo** ou apontar para uma cadeia de caracteres vazia, nenhum caminho de diretório é inserido na composição *caminho* cadeia de caracteres.

*fname*<br/>
Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se *fname* é **nulo** ou apontar para uma cadeia de caracteres vazia, nenhum nome de arquivo é inserido na composição *caminho* cadeia de caracteres.

*ext*<br/>
Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). **makepath** insere o período automaticamente se ele não aparecer na *ext*. Se *ext* é **nulo** ou aponta para uma cadeia de caracteres vazia, nenhuma extensão será inserido na composição *caminho* cadeia de caracteres.

## <a name="remarks"></a>Comentários

O **makepath** função cria uma cadeia de caracteres de caminho de composição de componentes individuais e armazena o resultado na *caminho*. O *caminho* pode incluir uma letra de unidade, caminho de diretório, nome de arquivo e extensão de nome de arquivo. **wmakepath** é uma versão de caractere largo de **makepath**; os argumentos a serem **wmakepath** são cadeias de caracteres largos. **wmakepath** e **makepath** se comportam de forma idêntica caso contrário.

**Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. Para evitar a saturação do buffer, a cadeia de caracteres terminada em nulo não deve exceder o tamanho do *caminho* buffer. **makepath** Certifique-se que o comprimento da cadeia de caracteres de caminho de composição não exceda **MAX_PATH**. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/desktop/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tmakepath**|**_makepath**|**_makepath**|**_wmakepath**|

O *caminho* argumento deve apontar para um buffer vazio grande o suficiente para conter o caminho completo. A composição *caminho* deve ser maior do que o **MAX_PATH** constante, definida em stdlib. h.

Se o caminho estiver **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, **errno** é definido como **EINVAL**. **NULO** são permitidos valores para todos os outros parâmetros.

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

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
[_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md)<br/>
