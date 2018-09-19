---
title: Constantes de heap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _HEAPBADPTR
- _HEAPEMPTY
- _HEAPBADBEGIN
- _HEAPOK
- _HEAPBADNODE
- _HEAPEND
dev_langs:
- C++
helpviewer_keywords:
- _HEAPOK constants
- _HEAPEND constants
- HEAPBADBEGIN constants
- _HEAPBADNODE constants
- HEAPBADNODE constants
- HEAPBADPTR constants
- _HEAPEMPTY constants
- HEAPEND constants
- HEAPOK constants
- HEAPEMPTY constants
- _HEAPBADBEGIN constants
- _HEAPBADPTR constants
- heap constants
ms.assetid: 3f751bb9-2dc4-486f-b5f5-9061c96d3754
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 791509a7c67f5fa47128fda97688c43e592724ed
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46115171"
---
# <a name="heap-constants"></a>Constantes de heap

## <a name="syntax"></a>Sintaxe

```

#include <malloc.h>

```

## <a name="remarks"></a>Comentários

Essas constantes informam o valor retornado que indica o status do heap.

|Constante|Significado|
|--------------|-------------|
|`_HEAPBADBEGIN`|As informações do cabeçalho inicial não foram encontradas ou são inválidas.|
|`_HEAPBADNODE`|Foi encontrado um nó inválido ou o heap está danificado.|
|`_HEAPBADPTR`|O campo **_pentry** da estrutura **_HEAPINFO** não contém um ponteiro válido para o heap (somente a rotina `_heapwalk`).|
|`_HEAPEMPTY`|O heap não foi inicializado.|
|`_HEAPEND`|O fim do heap foi alcançado com êxito (somente a rotina `_heapwalk`).|
|`_HEAPOK`|O heap é consistente (somente as rotinas `_heapset` e `_heapchk`). Nenhum erro até o momento; a estrutura **_HEAPINFO** contém informações a respeito da próxima entrada (somente a rotina `_heapwalk`).|

## <a name="see-also"></a>Consulte também

[_heapchk](../c-runtime-library/reference/heapchk.md)<br/>
[_heapset](../c-runtime-library/heapset.md)<br/>
[_heapwalk](../c-runtime-library/reference/heapwalk.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)