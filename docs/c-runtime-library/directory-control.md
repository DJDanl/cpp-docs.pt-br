---
title: Controle de diretório
ms.date: 11/04/2016
helpviewer_keywords:
- controls [C++], directory
- directory control routines
ms.assetid: a72dcf6f-f366-4d20-8850-0e19cc53ca18
ms.openlocfilehash: 640ce8a8665936b604c6e8e6270e358a200c880a
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438544"
---
# <a name="directory-control"></a>Controle de diretório

Essas rotinas acessam, modificam e obtêm informações sobre a estrutura do diretório.

## <a name="directory-control-routines"></a>Rotinas de controle de diretório

|Rotina|Use|
|-------------|---------|
|[_chdir, _wchdir](../c-runtime-library/reference/chdir-wchdir.md)|Alterar diretório de trabalho atual|
|[_chdrive](../c-runtime-library/reference/chdrive.md)|Alterar a unidade atual|
|[_getcwd, _wgetcwd](../c-runtime-library/reference/getcwd-wgetcwd.md)|Obter o diretório de trabalho atual para a unidade padrão|
|[_getdcwd, _wgetdcwd](../c-runtime-library/reference/getdcwd-wgetdcwd.md)|Obter o diretório de trabalho atual para a unidade especificada|
|[_getdiskfree](../c-runtime-library/reference/getdiskfree.md)|Popula uma estrutura **_diskfree_t** com informações sobre a unidade de disco.|
|[_getdrive](../c-runtime-library/reference/getdrive.md)|Obtém unidade atual (padrão)|
|[_getdrives](../c-runtime-library/reference/getdrives.md)|Retorna um bitmask que representa as unidades de disco disponíveis no momento.|
|[_mkdir, _wmkdir](../c-runtime-library/reference/mkdir-wmkdir.md)|Criar novo diretório|
|[_rmdir, _wrmdir](../c-runtime-library/reference/rmdir-wrmdir.md)|Remover diretório|
|[_searchenv, _wsearchenv](../c-runtime-library/reference/searchenv-wsearchenv.md), [_searchenv_s, _wsearchenv_s](../c-runtime-library/reference/searchenv-s-wsearchenv-s.md)|Pesquisar por determinado arquivo em caminhos especificados|

## <a name="see-also"></a>Consulte também

[Rotinas de runtime C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[Manipulação de Arquivos](../c-runtime-library/file-handling.md)<br/>
[Chamadas do sistema](../c-runtime-library/system-calls.md)<br/>
