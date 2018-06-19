---
title: Controle de diretório | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.programs
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], directory
- directory control routines
ms.assetid: a72dcf6f-f366-4d20-8850-0e19cc53ca18
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c0ab24a55cddc13b743a28a022475b0c0b84e77
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32389722"
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
|[_getdrive](../c-runtime-library/reference/getdrive.md)|Obtém unidade atual (padrão) |
|[_getdrives](../c-runtime-library/reference/getdrives.md)|Retorna um bitmask que representa as unidades de disco disponíveis no momento.|
|[_mkdir, _wmkdir](../c-runtime-library/reference/mkdir-wmkdir.md)|Criar novo diretório|
|[_rmdir, _wrmdir](../c-runtime-library/reference/rmdir-wrmdir.md)|Remover diretório|
|[_searchenv, _wsearchenv](../c-runtime-library/reference/searchenv-wsearchenv.md), [_searchenv_s, _wsearchenv_s](../c-runtime-library/reference/searchenv-s-wsearchenv-s.md)|Pesquisar por determinado arquivo em caminhos especificados|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
 [Manipulação de Arquivos](../c-runtime-library/file-handling.md)<br/>
 [Chamadas do sistema](../c-runtime-library/system-calls.md)<br/>
