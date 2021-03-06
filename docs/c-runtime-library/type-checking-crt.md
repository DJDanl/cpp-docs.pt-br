---
title: Verificação de tipo (CRT)
ms.date: 11/04/2016
f1_keywords:
- c.types
helpviewer_keywords:
- checking type
- variable argument functions
- type checking
ms.assetid: 1ba7590b-d1c0-4636-b6a0-e231395abdad
ms.openlocfilehash: bb5aecc2b47aa8e88666f42d8022395bf99fd85e
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57747677"
---
# <a name="type-checking-crt"></a>Verificação de tipo (CRT)

O compilador executa verificação de tipo limitada em funções que podem pegar um número variável de argumentos, como segue:

|Chamada de função|Argumentos com tipo verificado|
|-------------------|-----------------------------|
|`_cprintf_s`, `_cscanf_s`, `printf_s`, `scanf_s`|Primeiro argumento (cadeia de caracteres de formato)|
|`fprintf_s`, `fscanf_s`, `sprintf_s`, `sscanf_s`|Dois primeiros argumentos (arquivo ou buffer e cadeia de caracteres de formato)|
|`_snprintf_s`|Três primeiros argumentos (arquivo ou buffer, contagem e cadeia de caracteres de formato)|
|`_open`|Dois primeiros argumentos (caminho e sinalizador `_open`)|
|`_sopen_s`|Três primeiros argumentos (caminho, sinalizador `_open` e modo de compartilhamento)|
|`_execl`, `_execle`, `_execlp`, `_execlpe`|Dois primeiros argumentos (caminho e ponteiro do primeiro argumento)|
|`_spawnl`, `_spawnle`, `_spawnlp`, `_spawnlpe`|Três primeiros argumentos (sinalização do modo, caminho e ponteiro do primeiro argumento)|

O compilador executa a mesma verificação de tipo limitada nos equivalentes de caractere largo dessas funções.

## <a name="see-also"></a>Consulte também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
