---
title: _makepath_s, _wmakepath_s
ms.date: 11/04/2016
apiname:
- _wmakepath_s
- _makepath_s
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
- ntoskrnl.exe
apitype: DLLExport
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
ms.openlocfilehash: 3536569fd3e77a353003e1372d5dc4ee6e4ee3fb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62156922"
---
# <a name="makepaths-wmakepaths"></a>_makepath_s, _wmakepath_s

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

*drive*<br/>
Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. **makepath_s** insere os dois-pontos automaticamente no caminho de composição se ele estiver ausente. Se *unidade* é **nulo** ou aponta para uma cadeia de caracteres vazia, nenhuma letra da unidade é exibida na composição *caminho* cadeia de caracteres.

*dir*<br/>
Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra à direita é opcional e uma barra (/) ou uma barra invertida (\\) ou ambas podem ser usadas em uma única *dir* argumento. Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se *dir* é **nulo** ou apontar para uma cadeia de caracteres vazia, nenhum caminho de diretório é inserido na composição *caminho* cadeia de caracteres.

*fname*<br/>
Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se *fname* é **nulo** ou apontar para uma cadeia de caracteres vazia, nenhum nome de arquivo é inserido na composição *caminho* cadeia de caracteres.

*ext*<br/>
Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). **makepath_s** insere o período automaticamente se ele não aparecer na *ext*. Se *ext* é **nulo** ou aponta para uma cadeia de caracteres vazia, nenhuma extensão será inserido na composição *caminho* cadeia de caracteres.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*path*|*sizeInWords* / *sizeInBytes*|Valor de|Conteúdo de *caminho*|
|------------|------------------------------------|------------|------------------------|
|**NULL**|qualquer|**EINVAL**|não modificado|
|qualquer|<= 0|**EINVAL**|não modificado|

Se qualquer uma das condições de erro acima ocorrer, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e as funções retornarão **EINVAL**. **NULO** é permitido para os parâmetros *unidade*, *fname*, e *ext*. Para obter informações sobre o comportamento quando esses parâmetros são ponteiros nulos ou cadeias de caracteres vazias, consulte a seção de Comentários.

## <a name="remarks"></a>Comentários

O **makepath_s** função cria uma cadeia de caracteres de caminho de composição de componentes individuais e armazena o resultado na *caminho*. O *caminho* pode incluir uma letra de unidade, caminho de diretório, nome de arquivo e extensão de nome de arquivo. **wmakepath_s** é uma versão de caractere largo de **makepath_s**; os argumentos a serem **wmakepath_s** são cadeias de caracteres largos. **wmakepath_s** e **makepath_s** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmakepath_s**|**_makepath_s**|**_makepath_s**|**_wmakepath_s**|

O *caminho* argumento deve apontar para um buffer vazio grande o suficiente para conter o caminho completo. A composição *caminho* deve ser maior do que o **MAX_PATH** constante, definida em stdlib. h.

Se o caminho estiver **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, **errno** é definido como **EINVAL**. **NULO** são permitidos valores para todos os outros parâmetros.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_makepath_s**|\<stdlib.h>|
|**_wmakepath_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
