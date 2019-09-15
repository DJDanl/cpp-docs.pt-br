---
title: _splitpath, _wsplitpath
ms.date: 11/04/2016
api_name:
- _wsplitpath
- _splitpath
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
ms.openlocfilehash: a502977faf91d744868c4aef79b3a40ca240a90f
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70958033"
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

*drive*<br/>
Letra da unidade, seguida por dois-pontos ( **:** ). Você pode passar **NULL** para esse parâmetro se não precisar da letra da unidade.

*dir*<br/>
Caminho do diretório, incluindo barra à direita. Barras invertidas **/** (), barras invertidas ( **\\** ) ou ambas podem ser usadas. Você pode passar **NULL** para esse parâmetro se não precisar do caminho do diretório.

*fname*<br/>
Nome de arquivo base (sem extensão). Você pode passar **NULL** para esse parâmetro se não precisar do nome de arquivo.

*externa*<br/>
Extensão de nome de arquivo, incluindo o ponto à esquerda ( **.** ). Você pode passar **NULL** para esse parâmetro se não precisar da extensão de nome de arquivo.

## <a name="remarks"></a>Comentários

A função **_splitpath** quebra um caminho em seus quatro componentes. o **_splitpath** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento. **_wsplitpath** é uma versão de caractere largo do **_splitpath**; os argumentos para **_wsplitpath** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

**Observação de segurança** Essas funções acarretam uma ameaça em potencial em relação a um problema de estouro de buffer. Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/win32/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer). Versões mais seguras dessas funções estão disponíveis; consulte [_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsplitpath**|**_splitpath**|**_splitpath**|**_wsplitpath**|

Cada componente do caminho completo é armazenado em um buffer separado; as constantes de manifesto **_MAX_DRIVE**, **_MAX_DIR**, **_MAX_FNAME**e **_MAX_EXT** (definidas em STDLIB. H) especifique o tamanho máximo para cada componente de arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.

Cada buffer deve ser tão grande quanto a constante de manifesto correspondente para evitar um possível estouro de buffer.

A tabela a seguir lista os valores das constantes do manifesto.

|Nome|Valor|
|----------|-----------|
|**_MAX_DRIVE**|3|
|**_MAX_DIR**|256|
|**_MAX_FNAME**|256|
|**_MAX_EXT**|256|

Se o caminho completo não contiver um componente (por exemplo, um nome de arquivo), o **_splitpath** atribuirá cadeias de caracteres vazias aos buffers correspondentes.

Você pode passar **NULL** para **_splitpath** para qualquer parâmetro que não seja o *caminho* que não seja necessário.

Se *Path* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_splitpath**|\<stdlib.h>|
|**_wsplitpath**|\<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_makepath](makepath-wmakepath.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_makepath, _wmakepath](makepath-wmakepath.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md)<br/>
