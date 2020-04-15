---
title: _splitpath_s, _wsplitpath_s
ms.date: 4/2/2020
api_name:
- _wsplitpath_s
- _splitpath_s
- _o__splitpath_s
- _o__wsplitpath_s
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
ms.openlocfilehash: 364544a9423668494747405e801d59b73de4e6c6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355628"
---
# <a name="_splitpath_s-_wsplitpath_s"></a>_splitpath_s, _wsplitpath_s

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

*Dirigir*<br/>
Carta de unidade, seguida de um cólon (**:**). Você pode passar **NULL** para este parâmetro se você não precisar da letra de unidade.

*unidadeNumberOfElements*<br/>
O tamanho do buffer de *unidade* em caracteres de byte único ou largo. Se *a unidade* for **NULA,** este valor deve ser 0.

*Dir*<br/>
Caminho do diretório, incluindo barra à direita. Cortes dianteiros **/** (), barras **\\** traseiras (), ou ambos podem ser usados. Você pode passar **NULL** para este parâmetro se você não precisar do caminho do diretório.

*dirNumberOfElements*<br/>
O tamanho do buffer *dir* em caracteres de byte único ou largo. Se *dir* for **NULL,** este valor deve ser 0.

*Fname*<br/>
Nome de arquivo base (sem extensão). Você pode passar **NULL** para este parâmetro se você não precisar do nome do arquivo.

*nomeNúmeronúmeroElementos*<br/>
O tamanho do buffer *fname* em caracteres single-byte ou wide. Se *fname* for **NULL,** este valor deve ser 0.

*Ext*<br/>
Extensão de nome de arquivo, incluindo o período principal **(.**). Você pode passar **NULL** para este parâmetro se você não precisar da extensão de nome de arquivo.

*extNumberOfElements*<br/>
O tamanho do *tampão ext* em caracteres single-byte ou wide. Se *o ramo* for **NULO,** este valor deve ser 0.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|Condição|Valor retornado|
|---------------|------------------|
|*caminho* é **NULO**|**Einval**|
|*unidade* é **NULL**, *unidadeNumberOfElements* não é zero|**Einval**|
|*unidade* **não-NULL,** *unidadeNumberOfElements* é zero|**Einval**|
|*dir* é **NULL**, *dirNumberOfElements* não é zero|**Einval**|
|*dir* é**não-NULL**, *dirNumberOfElements* é zero|**Einval**|
|*fname* é **NULL**, *nomeNumberOfElements* não é zero|**Einval**|
|*fname* é**não-NULL**, *nomeNumberOfElements* é zero|**Einval**|
|*ext* é **NULL,** *extNumberOfElements* não é zero|**Einval**|
|*ext* é**não-NULL,** *extNumberOfElements* é zero|**Einval**|

Se qualquer uma das condições acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **EINVAL**.

Se algum dos buffers for muito curto para segurar o resultado, essas funções limpam todos os buffers para as strings vazias, **definem errno** para **ERANGE**e retornam **ERANGE**.

## <a name="remarks"></a>Comentários

A função **_splitpath_s** quebra um caminho em seus quatro componentes. **_splitpath_s** lida automaticamente com argumentos de seqüência de caracteres de vários bytes conforme apropriado, reconhecendo seqüências de caracteres multibytes de acordo com a página de código multibyte atualmente em uso. **_wsplitpath_s** é uma versão ampla de **_splitpath_s;** os argumentos para **_wsplitpath_s** são cordas de caracteres amplos. Caso contrário, essas funções se comportam de forma idêntica

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsplitpath_s**|**_splitpath_s**|**_splitpath_s**|**_wsplitpath_s**|

Cada componente do caminho completo é armazenado em um buffer separado; as constantes manifestas **_MAX_DRIVE**, **_MAX_DIR,** **_MAX_FNAME**e **_MAX_EXT** (definidas em STDLIB. H) especifique o tamanho máximo permitido para cada componente do arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.

A tabela a seguir lista os valores das constantes do manifesto.

|Nome|Valor|
|----------|-----------|
|_MAX_DRIVE|3|
|_MAX_DIR|256|
|_MAX_FNAME|256|
|_MAX_EXT|256|

Se o caminho completo não contiver um componente (por exemplo, um nome de arquivo), **_splitpath_s** atribuir uma seqüência vazia ao buffer correspondente.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

As versões da biblioteca de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](crtsetdebugfillthreshold.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_splitpath_s**|\<stdlib.h>|
|**_wsplitpath_s**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_makepath_s, _wmakepath_s](makepath-s-wmakepath-s.md).

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_splitpath, _wsplitpath](splitpath-wsplitpath.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_setmbcp](setmbcp.md)<br/>
