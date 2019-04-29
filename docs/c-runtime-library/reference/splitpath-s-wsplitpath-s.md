---
title: _splitpath_s, _wsplitpath_s
ms.date: 11/04/2016
apiname:
- _wsplitpath_s
- _splitpath_s
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
- _wsplitpath_s
- splitpath_s
- _splitpath_s
- wsplitpath_s
helpviewer_keywords:
- splitpath_s function
- pathnames
- _splitpath_s function
- _wsplitpath_s function
- path names
- wsplitpath_s function
ms.assetid: 30fff3e2-cd00-4eb6-b5a2-65db79cb688b
ms.openlocfilehash: 87af8bac525844c06fdfc16d7d13a06eef4d61ab
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62355023"
---
# <a name="splitpaths-wsplitpaths"></a>_splitpath_s, _wsplitpath_s

Divide um nome de caminho em componentes. Estas são versões de [_splitpath, _wsplitpath](splitpath-wsplitpath.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _splitpath_s(
   const char * path,
   char * drive,
   size_t driveNumberOfElements,
   char * dir,
   size_t dirNumberOfElements,
   char * fname,
   size_t nameNumberOfElements,
   char * ext,
   size_t extNumberOfElements
);
errno_t _wsplitpath_s(
   const wchar_t * path,
   wchar_t * drive,
   size_t driveNumberOfElements,
   wchar_t *dir,
   size_t dirNumberOfElements,
   wchar_t * fname,
   size_t nameNumberOfElements,
   wchar_t * ext,
   size_t extNumberOfElements
);
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>
errno_t _splitpath_s(
   const char *path,
   char (&drive)[drivesize],
   char (&dir)[dirsize],
   char (&fname)[fnamesize],
   char (&ext)[extsize]
); // C++ only
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>
errno_t _wsplitpath_s(
   const wchar_t *path,
   wchar_t (&drive)[drivesize],
   wchar_t (&dir)[dirsize],
   wchar_t (&fname)[fnamesize],
   wchar_t (&ext)[extsize]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho completo.

*drive*<br/>
Letra da unidade, seguida por dois-pontos (**:**). Você pode passar **nulo** para esse parâmetro se você não precisa ter a letra da unidade.

*driveNumberOfElements*<br/>
O tamanho do *unidade* buffer em caracteres de byte único ou largos. Se *unidade* é **nulo**, esse valor deve ser 0.

*dir*<br/>
Caminho do diretório, incluindo barra à direita. Barras ( **/** ), barras invertidas ( **\\** ), ou ambos podem ser usadas. Você pode passar **nulo** para esse parâmetro se você não precisa o caminho do diretório.

*dirNumberOfElements*<br/>
O tamanho do *dir* buffer em caracteres de byte único ou largos. Se *dir* é **nulo**, esse valor deve ser 0.

*fname*<br/>
Nome de arquivo base (sem extensão). Você pode passar **nulo** para esse parâmetro se o nome do arquivo não é necessário.

*nameNumberOfElements*<br/>
O tamanho do *fname* buffer em caracteres de byte único ou largos. Se *fname* é **nulo**, esse valor deve ser 0.

*ext*<br/>
Extensão de nome de arquivo, incluindo ponto à esquerda (**.**). Você pode passar **nulo** para esse parâmetro se a extensão de nome de arquivo não é necessária.

*extNumberOfElements*<br/>
O tamanho de *ext* buffer em caracteres de byte único ou largos. Se *ext* é **nulo**, esse valor deve ser 0.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|Condição|Valor de retorno|
|---------------|------------------|
|*caminho* é **nulo**|**EINVAL**|
|*unidade* está **nulo**, *driveNumberOfElements* for diferente de zero|**EINVAL**|
|*unidade* não é**nulo**, *driveNumberOfElements* é zero|**EINVAL**|
|*dir* está **nulo**, *dirNumberOfElements* for diferente de zero|**EINVAL**|
|*dir* não é**nulo**, *dirNumberOfElements* é zero|**EINVAL**|
|*fname* está **nulo**, *nameNumberOfElements* for diferente de zero|**EINVAL**|
|*fname* não é**nulo**, *nameNumberOfElements* é zero|**EINVAL**|
|*ext* está **nulo**, *extNumberOfElements* for diferente de zero|**EINVAL**|
|*ext* não é**nulo**, *extNumberOfElements* é zero|**EINVAL**|

Se qualquer uma das condições acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **EINVAL**.

Se qualquer um dos buffers é curto demais para manter o resultado, essas funções limpam todos os buffers para cadeias de caracteres vazias, defina **errno** à **ERANGE**e retornar **ERANGE**.

## <a name="remarks"></a>Comentários

O **splitpath_s** função divide um caminho em seus quatro componentes. **splitpath_s** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo as sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento. **wsplitpath_s** é uma versão de caractere largo de **splitpath_s**; os argumentos a serem **wsplitpath_s** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsplitpath_s**|**_splitpath_s**|**_splitpath_s**|**_wsplitpath_s**|

Cada componente do caminho completo é armazenado em um buffer separado; as constantes de manifesto **max_drive**, **max_dir**, **max_fname**, e **max_ext** (definida em STDLIB. H) especificam o tamanho máximo permitido para cada componente de arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.

A tabela a seguir lista os valores das constantes do manifesto.

|Nome|Valor|
|----------|-----------|
|_MAX_DRIVE|3|
|_MAX_DIR|256|
|_MAX_FNAME|256|
|_MAX_EXT|256|

Se o caminho completo não contém um componente (por exemplo, um nome de arquivo), **splitpath_s** atribui uma cadeia de caracteres vazia ao buffer correspondente.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_splitpath_s**|\<stdlib.h>|
|**_wsplitpath_s**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_setmbcp](setmbcp.md)<br/>
