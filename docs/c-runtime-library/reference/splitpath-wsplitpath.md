---
title: _splitpath, _wsplitpath | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wsplitpath
- _splitpath
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
- wsplitpath
- _splitpath
- splitpath
- _wsplitpath
- _tsplitpath
dev_langs:
- C++
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
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 29102810363e6501d622ac065b63d0bfe978911a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="splitpath-wsplitpath"></a>_splitpath, _wsplitpath

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

*caminho* caminho completo.

*unidade* letra da unidade, seguida por dois-pontos (**:**). Você pode passar **nulo** para esse parâmetro se você não precisa a letra da unidade.

*dir* caminho de diretório, incluindo a barra à direita. Barras duplas ( **/** ), barras invertidas ( **\\** ), ou ambos podem ser usadas. Você pode passar **nulo** para esse parâmetro se o caminho do diretório não é necessário.

*fname* basear o nome do arquivo (sem extensão). Você pode passar **nulo** para esse parâmetro se o nome do arquivo não é necessário.

*ext* extensão de nome de arquivo, incluindo à esquerda período (**.**). Você pode passar **nulo** para esse parâmetro se a extensão de nome de arquivo não é necessário.

## <a name="remarks"></a>Comentários

O **splitpath** função quebras de um caminho em quatro componentes. **splitpath** manipula automaticamente os argumentos da cadeia de caracteres multibyte conforme apropriado, reconhecer sequências de caracteres multibyte de acordo com a página de código multibyte em uso no momento. **wsplitpath** é uma versão de caractere largo de **splitpath**; os argumentos para **wsplitpath** são cadeias de caracteres do caractere largo. Caso contrário, essas funções se comportam de forma idêntica.

**Observação de segurança** Essas funções acarretam uma ameaça em potencial em relação a um problema de estouro de buffer. Os problemas de estouro de buffer são um método frequente de ataque ao sistema, resultando em uma elevação de privilégio sem garantia. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer). Versões mais seguras dessas funções estão disponíveis; consulte [_splitpath_s, _wsplitpath_s](splitpath-s-wsplitpath-s.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tsplitpath**|**_splitpath**|**_splitpath**|**_wsplitpath**|

Cada componente do caminho completo é armazenado em um buffer separado; as constantes de manifesto **max_drive**, **max_dir**, **max_fname**, e **max_ext** (definido em STDLIB. H) Especifique o tamanho máximo para cada componente de arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.

Cada buffer deve ser tão grande quanto a constante de manifesto correspondente para evitar um possível estouro de buffer.

A tabela a seguir lista os valores das constantes do manifesto.

|Nome|Valor|
|----------|-----------|
|**MAX_DRIVE**|3|
|**MAX_DIR**|256|
|**MAX_FNAME**|256|
|**MAX_EXT**|256|

Se o caminho completo não tem um componente (por exemplo, um nome de arquivo), **splitpath** atribui vazio cadeias de caracteres para os buffers correspondentes.

Você pode passar **nulo** para **splitpath** para qualquer parâmetro diferente de *caminho* que não é necessário.

Se *caminho* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EINVAL** e a função retorna **EINVAL**.

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
