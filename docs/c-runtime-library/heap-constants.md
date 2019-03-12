---
title: Constantes de heap
ms.date: 11/04/2016
f1_keywords:
- _HEAPBADPTR
- _HEAPEMPTY
- _HEAPBADBEGIN
- _HEAPOK
- _HEAPBADNODE
- _HEAPEND
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
ms.openlocfilehash: 44c7a280ebffd0073f1dfb3a0a3cbdbd2efee0fb
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745370"
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
