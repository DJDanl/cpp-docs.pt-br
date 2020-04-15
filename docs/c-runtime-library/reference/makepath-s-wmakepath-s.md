---
title: _makepath_s, _wmakepath_s
ms.date: 4/2/2020
api_name:
- _wmakepath_s
- _makepath_s
- _o__makepath_s
- _o__wmakepath_s
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 3a44651cb9ff8be806c45c6b6c5f41f810319a85
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341597"
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

*Sizeinbytes*<br/>
O tamanho do buffer em bytes.

*Dirigir*<br/>
Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. **_makepath_s** insere o cólon automaticamente no caminho composto se estiver faltando. Se *a unidade* for **NULL** ou apontapara uma seqüência de string vazia, nenhuma letra de unidade será exibida na seqüência de *caminho* composto.

*Dir*<br/>
Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra de arrasto é opcional, e uma barra\\para a frente (/) ou uma barra invertida ( ) ou ambas podem ser usadas em um único argumento *dir.* Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se *dir* for **NULL** ou apontar para uma seqüência de string vazia, nenhum caminho de diretório será inserido na string *de caminho* composto.

*Fname*<br/>
Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se *fname* for **NULL** ou aponta para uma seqüência de string vazia, nenhum nome de arquivo será inserido na seqüência *de caminho* composto.

*Ext*<br/>
Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). **_makepath_s** insere o período automaticamente se ele não aparecer em *ramal*. Se *o ramo* for **NULO** ou apontapara uma seqüência vazia, nenhuma extensão será inserida na seqüência *de caminho* composto.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|*path*|*tamanhoInWords* / *tamanhoInBytes*|Retorno|Conteúdo do *caminho*|
|------------|------------------------------------|------------|------------------------|
|**NULO**|any|**Einval**|não modificado|
|any|<= 0|**Einval**|não modificado|

Se qualquer uma das condições de erro acima ocorrer, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e as funções retornarão **EINVAL**. **NULL** é permitido para a *unidade*de parâmetros, *fname* *e ramal*. Para obter informações sobre o comportamento quando esses parâmetros forem ponteiros nulos ou strings vazios, consulte a seção Observações.

## <a name="remarks"></a>Comentários

A função **_makepath_s** cria uma seqüência de caminho composto a partir de componentes individuais, armazenando o resultado em *caminho*. O *caminho* pode incluir uma letra de unidade, caminho de diretório, nome do arquivo e extensão de nome do arquivo. **_wmakepath_s** é uma versão ampla do **_makepath_s;** os argumentos para **_wmakepath_s** são cordas de caracteres amplos. **_wmakepath_s** e **_makepath_s** se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tmakepath_s**|**_makepath_s**|**_makepath_s**|**_wmakepath_s**|

O argumento *do caminho* deve apontar para um buffer vazio grande o suficiente para manter o caminho completo. O *caminho* composto não deve ser maior do que **a** _MAX_PATH constante, definida em Stdlib.h.

Se o caminho for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Além disso, **errno** está definido **como EINVAL**. **Valores NULL** são permitidos para todos os outros parâmetros.

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

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

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
