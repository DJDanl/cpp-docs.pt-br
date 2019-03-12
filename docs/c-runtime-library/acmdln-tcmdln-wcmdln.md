---
title: _acmdln, _tcmdln, _wcmdln
ms.date: 11/04/2016
apiname:
- _wcmdln
- _acmdln
apilocation:
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- _acmdln
- acmdln
- _wcmdln
- wcmdln
- _tcmdln
- tcmdln
helpviewer_keywords:
- _wcmdln global variable
- wcmdln global variable
- _acmdln global variable
- _tcmdln global variable
- tcmdln global variable
- acmdln global variable
ms.assetid: 4fc0a6a0-3f93-420a-a19f-5276061ba539
ms.openlocfilehash: f4cacb512cb9b5bb6ea22f4dc4014ac2a2eeebe6
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57747015"
---
# <a name="acmdln-tcmdln-wcmdln"></a>_acmdln, _tcmdln, _wcmdln

Variável interna de CRT global. A linha de comando.

## <a name="syntax"></a>Sintaxe

```
char * _acmdln;
wchar_t * _wcmdln;

#ifdef WPRFLAG
   #define _tcmdln _wcmdln
#else
   #define _tcmdln _acmdln
```

## <a name="remarks"></a>Comentários

Essas variáveis internas de CRT armazenam toda a linha de comando. Elas ficam expostas nos símbolos exportados para o CRT, mas não devem ser usadas no seu código. `_acmdln` armazena os dados como uma cadeia de caracteres. `_wcmdln` armazena os dados como uma cadeia de caracteres larga. `_tcmdln` pode ser definido como `_acmdln` ou `_wcmdln`, conforme apropriado.

## <a name="see-also"></a>Consulte também

[Variáveis globais](../c-runtime-library/global-variables.md)
