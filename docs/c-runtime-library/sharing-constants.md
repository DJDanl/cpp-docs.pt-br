---
title: Compartilhando constantes
ms.date: 11/04/2016
f1_keywords:
- _SH_DENYNO
- _SH_DENYRD
- _SH_DENYRW
- _SH_DENYWR
- _SH_COMPAT
helpviewer_keywords:
- _SH_DENYRW constant
- SH_DENYRD constant
- _SH_COMPAT constant
- _SH_DENYRD constant
- SH_DENYRW constant
- sharing constants
- SH_DENYNO constant
- _SH_DENYWR constant
- SH_DENYWR constant
- _SH_DENYNO constant
- SH_COMPAT constant
ms.assetid: 95fadc3a-55dc-473d-98b5-e8211900465d
ms.openlocfilehash: dc27b3af0d430aedb8159b4591004f46d197ccd5
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57751538"
---
# <a name="sharing-constants"></a>Compartilhando constantes

Constantes para modos de compartilhamento de arquivos.

## <a name="syntax"></a>Sintaxe

```
#include <share.h>
```

## <a name="remarks"></a>Comentários

O argumento *shflag* determina o modo de compartilhamento, que consiste em uma ou mais constantes de manifesto. Elas podem ser combinadas com os argumentos *oflag* (consulte [Constantes de arquivo](../c-runtime-library/file-constants.md)).

A tabela a seguir lista as constantes e seus significados:

|Constante|Significado|
|--------------|-------------|
|`_SH_DENYRW`|Nega acesso de leitura e gravação a um arquivo|
|`_SH_DENYWR`|Nega acesso de gravação a um arquivo|
|`_SH_DENYRD`|Nega acesso de leitura a um arquivo|
|`_SH_DENYNO`|Permite acesso de leitura e gravação|
|`_SH_SECURE`|Define o modo seguro (leitura compartilhada, acesso de gravação exclusivo).|

## <a name="see-also"></a>Consulte também

[_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md)<br/>
[_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
