---
title: _splitpath, _wsplitpath
ms.date: 4/2/2020
api_name:
- _wsplitpath
- _splitpath
- _o__splitpath
- _o__wsplitpath
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
- wsplitpath
- _splitpath
- splitpath
- _wsplitpath
- _tsplitpath
helpviewer_keywords:
- _splitpath function
- pathnames
- wsplitpath function
- splitpath function
- _wsplitpath function
- tsplitpath function
- path names
- _tsplitpath function
ms.assetid: 32bd76b5-1385-4ee8-a64c-abcb541cd2e4
ms.openlocfilehash: 6798f93b2d1bc18a190b3b015bf8c882a3fa8a37
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355605"
---
# <a name="_splitpath-_wsplitpath"></a>_splitpath, _wsplitpath

Divida um nome de caminho em componentes. Versões mais seguras dessas funções estão disponíveis, consulte [_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md).

## <a name="syntax"></a>Sintaxe

```C
void _splitpath(
   const char *path,
   char *drive,
   char *dir,
   char *fname,
   char *ext
);
void _wsplitpath(
   const wchar_t *path,
   wchar_t *drive,
   wchar_t *dir,
   wchar_t *fname,
   wchar_t *ext
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho completo.

*Dirigir*<br/>
Carta de unidade, seguida de um cólon (**:**). Você pode passar **NULL** para este parâmetro se você não precisar da letra de unidade.

*Dir*<br/>
Caminho do diretório, incluindo barra à direita. Cortes dianteiros **/** (), barras **\\** traseiras (), ou ambos podem ser usados. Você pode passar **NULL** para este parâmetro se você não precisar do caminho do diretório.

*Fname*<br/>
Nome de arquivo base (sem extensão). Você pode passar **NULL** para este parâmetro se você não precisar do nome do arquivo.

*Ext*<br/>
Extensão de nome de arquivo, incluindo o período principal **(.**). Você pode passar **NULL** para este parâmetro se você não precisar da extensão de nome de arquivo.

## <a name="remarks"></a>Comentários

A função **_splitpath** quebra um caminho em seus quatro componentes. **_splitpath** lida automaticamente com argumentos de seqüência de caracteres de caracteres multibytes conforme apropriado, reconhecendo seqüências de caracteres multibytes de acordo com a página de código multibyte atualmente em uso. **_wsplitpath** é uma versão ampla do **_splitpath;** os argumentos para **_wsplitpath** são cordas de caracteres amplos. Caso contrário, essas funções se comportam de forma idêntica.

**Observação de segurança** Essas funções acarretam uma ameaça em potencial em relação a um problema de estouro de buffer. Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer). Versões mais seguras dessas funções estão disponíveis; veja [_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsplitpath**|**_splitpath**|**_splitpath**|**_wsplitpath**|

Cada componente do caminho completo é armazenado em um buffer separado; as constantes manifestas **_MAX_DRIVE**, **_MAX_DIR,** **_MAX_FNAME**e **_MAX_EXT** (definidas em STDLIB. H) especifique o tamanho máximo para cada componente do arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.

Cada buffer deve ser tão grande quanto a constante de manifesto correspondente para evitar um possível estouro de buffer.

A tabela a seguir lista os valores das constantes do manifesto.

|Nome|Valor|
|----------|-----------|
|**_MAX_DRIVE**|3|
|**_MAX_DIR**|256|
|**_MAX_FNAME**|256|
|**_MAX_EXT**|256|

Se o caminho completo não contiver um componente (por exemplo, um nome de arquivo), **_splitpath** atribuir strings vazias aos buffers correspondentes.

Você pode passar **NULL** para **_splitpath** para qualquer parâmetro que não seja *o caminho* que você não precisa.

Se *o caminho* for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_splitpath**|\<stdlib.h>|
|**_wsplitpath**|\<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_makepath](makepath-wmakepath.md).

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md)<br/>
