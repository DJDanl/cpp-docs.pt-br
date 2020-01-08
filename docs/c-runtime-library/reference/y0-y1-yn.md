---
title: y0, y1, yn
ms.date: 12/16/2019
api_name:
- y1
- yn
- y0
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- yn
- y1
- y0
helpviewer_keywords:
- y0 function
- y1 function
- yn function
ms.assetid: e14215f3-53d4-4ae8-816e-4c1ec2019316
ms.openlocfilehash: ade2978d9a052b481c8250933257cfa33493860f
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301711"
---
# <a name="y0-y1-yn"></a>y0, y1, yn

Os nomes de função POSIX implementados pela Microsoft `y0`, `y1`e `yn` são aliases preteridos para as funções [_y0, _y1 e _yn](bessel-functions-j0-j1-jn-y0-y1-yn.md) . Por padrão, eles geram o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Os nomes são preteridos porque não seguem as regras padrão do C para nomes específicos da implementação. No entanto, as funções ainda têm suporte.

É recomendável usar [_y0, _y1 e _yn](bessel-functions-j0-j1-jn-y0-y1-yn.md) em vez disso. Ou, você pode continuar a usar esses nomes de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
