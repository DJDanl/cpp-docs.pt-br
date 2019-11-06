---
title: _makepath_s, _wmakepath_s
ms.date: 11/04/2016
api_name:
- _wmakepath_s
- _makepath_s
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
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wmakepath_s
- makepath_s
- _makepath_s
- wmakepath_s
helpviewer_keywords:
- _makepath_s function
- wmakepath_s function
- paths
- _wmakepath_s function
- makepath_s function
ms.assetid: 4405e43c-3d63-4697-bb80-9b8dcd21d027
ms.openlocfilehash: 7bd85734e71120a214d652048c02c176728474b2
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624351"
---
# <a name="_makepath_s-_wmakepath_s"></a>_makepath_s, _wmakepath_s

Cria um nome de caminho com base nos componentes. Estas são versões de [_makepath, _wmakepath](makepath-wmakepath.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _makepath_s(
   char *path,
   size_t sizeInBytes,
   const char *drive,
   const char *dir,
   const char *fname,
   const char *ext
);
errno_t _wmakepath_s(
   wchar_t *path,
   size_t sizeInWords,
   const wchar_t *drive,
   const wchar_t *dir,
   const wchar_t *fname,
   const wchar_t *ext
);
template <size_t size>
errno_t _makepath_s(
   char (&path)[size],
   const char *drive,
   const char *dir,
   const char *fname,
   const char *ext
); // C++ only
template <size_t size>
errno_t _wmakepath_s(
   wchar_t (&path)[size],
   const wchar_t *drive,
   const wchar_t *dir,
   const wchar_t *fname,
   const wchar_t *ext
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Buffer de caminho completo.

*sizeInWords*<br/>
O tamanho do buffer em palavras.

*sizeInBytes*<br/>
O tamanho do buffer em bytes.

*Dirigir*<br/>
Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. **_makepath_s** insere os dois-pontos automaticamente no caminho composto, se ele estiver ausente. Se a *unidade* for **nula** ou apontar para uma cadeia de caracteres vazia, nenhuma letra da unidade será exibida na cadeia de caracteres do *caminho* composto.

*comando*<br/>
Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra à direita é opcional e uma barra (/) ou uma barra invertida (\\) ou ambas podem ser usadas em um único argumento *dir* . Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se *dir* for **nulo** ou apontar para uma cadeia de caracteres vazia, nenhum caminho de diretório será inserido na cadeia de caracteres de *caminho* composto.

*fname*<br/>
Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se *fname* for **nulo** ou apontar para uma cadeia de caracteres vazia, Nenhum filename será inserido na cadeia de caracteres do *caminho* composto.

*externa*<br/>
Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). **_makepath_s** insere o período automaticamente se ele não aparecer em *ext*. Se *ext* for **nulo** ou apontar para uma cadeia de caracteres vazia, nenhuma extensão será inserida na cadeia de caracteres de *caminho* composto.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*path*|*sizeInWords* / *sizeInBytes*|Valor de|Conteúdo do *caminho*|
|------------|------------------------------------|------------|------------------------|
|**NULL**|qualquer|**EINVAL**|não modificado|
|qualquer|<= 0|**EINVAL**|não modificado|

Se qualquer uma das condições de erro acima ocorrer, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e as funções retornarão **EINVAL**. **NULL** é permitido para os parâmetros *drive*, *fname*e *ext*. Para obter informações sobre o comportamento quando esses parâmetros são ponteiros nulos ou cadeias de caracteres vazias, consulte a seção comentários.

## <a name="remarks"></a>Comentários

A função **_makepath_s** cria uma cadeia de caracteres de caminho composto de componentes individuais, armazenando o resultado no *caminho*. O *caminho* pode incluir uma letra de unidade, um caminho de diretório, um nome de arquivo e uma extensão de nome de arquivo. **_wmakepath_s** é uma versão de caractere largo do **_makepath_s**; os argumentos para **_wmakepath_s** são cadeias de caracteres largos. **_wmakepath_s** e **_makepath_s** se comportam de outra forma.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmakepath_s**|**_makepath_s**|**_makepath_s**|**_wmakepath_s**|

O argumento de *caminho* deve apontar para um buffer vazio grande o suficiente para manter o caminho completo. O *caminho* composto não deve ser maior que a constante **_MAX_PATH** , definida em STDLIB. h.

Se path for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, **errno** é definido como **EINVAL**. Valores **nulos** são permitidos para todos os outros parâmetros.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_makepath_s**|\<stdlib.h>|
|**_wmakepath_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_makepath_s.c

#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char path_buffer[_MAX_PATH];
   char drive[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fname[_MAX_FNAME];
   char ext[_MAX_EXT];
   errno_t err;

   err = _makepath_s( path_buffer, _MAX_PATH, "c", "\\sample\\crt\\",
                      "crt_makepath_s", "c" );
   if (err != 0)
   {
      printf("Error creating path. Error code %d.\n", err);
      exit(1);
   }
   printf( "Path created with _makepath_s: %s\n\n", path_buffer );
   err = _splitpath_s( path_buffer, drive, _MAX_DRIVE, dir, _MAX_DIR, fname,
                       _MAX_FNAME, ext, _MAX_EXT );
   if (err != 0)
   {
      printf("Error splitting the path. Error code %d.\n", err);
      exit(1);
   }
   printf( "Path extracted with _splitpath_s:\n" );
   printf( "   Drive: %s\n", drive );
   printf( "   Dir: %s\n", dir );
   printf( "   Filename: %s\n", fname );
   printf( "   Ext: %s\n", ext );
}
```

```Output
Path created with _makepath_s: c:\sample\crt\crt_makepath_s.c

Path extracted with _splitpath_s:
   Drive: c:
   Dir: \sample\crt\
   Filename: crt_makepath_s
   Ext: .c
```

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
