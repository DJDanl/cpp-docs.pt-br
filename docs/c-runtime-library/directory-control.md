---
title: "Controle de diretório | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.programs
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], directory
- directory control routines
ms.assetid: a72dcf6f-f366-4d20-8850-0e19cc53ca18
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e4674029fe5bdfc4323f580fcc0567b2ceeb1929
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="directory-control"></a>Controle de diretório
Essas rotinas acessam, modificam e obtêm informações sobre a estrutura do diretório.  
  
### <a name="directory-control-routines"></a>Rotinas de controle de diretório  
  
|Rotina|Use|  
|-------------|---------|  
|[_chdir, _wchdir](../c-runtime-library/reference/chdir-wchdir.md)|Alterar diretório de trabalho atual|  
|[_chdrive](../c-runtime-library/reference/chdrive.md)|Alterar a unidade atual|  
|[_getcwd, _wgetcwd](../c-runtime-library/reference/getcwd-wgetcwd.md)|Obter o diretório de trabalho atual para a unidade padrão|  
|[_getdcwd, _wgetdcwd](../c-runtime-library/reference/getdcwd-wgetdcwd.md)|Obter o diretório de trabalho atual para a unidade especificada|  
|[_getdiskfree](../c-runtime-library/reference/getdiskfree.md)|Popula uma `_diskfree_t` estrutura com informações sobre a unidade de disco.|  
|[_getdrive](../c-runtime-library/reference/getdrive.md)|Obtém unidade atual (padrão) |  
|[_getdrives](../c-runtime-library/reference/getdrives.md)|Retorna um bitmask que representa as unidades de disco disponíveis no momento.|  
|[_mkdir, _wmkdir](../c-runtime-library/reference/mkdir-wmkdir.md)|Criar novo diretório|  
|[_rmdir, _wrmdir](../c-runtime-library/reference/rmdir-wrmdir.md)|Remover diretório|  
|[_searchenv, _wsearchenv](../c-runtime-library/reference/searchenv-wsearchenv.md), [_searchenv_s, _wsearchenv_s](../c-runtime-library/reference/searchenv-s-wsearchenv-s.md)|Pesquisar por determinado arquivo em caminhos especificados|  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)   
 [Manipulação de Arquivos](../c-runtime-library/file-handling.md)   
 [Chamadas do sistema](../c-runtime-library/system-calls.md)