---
title: memccpy
ms.date: 12/16/2019
api_name:
- memccpy
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
- memccpy
helpviewer_keywords:
- memccpy function
ms.assetid: e9951812-2b69-43e9-bbee-a0001bce4d80
ms.openlocfilehash: 1d092b31b3c372321c37fbf82772e2abd268c8cc
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75300892"
---
# <a name="memccpy"></a>memccpy

O nome da função POSIX implementada pela Microsoft `memccpy` é um alias preterido para a função [_memccpy](memccpy.md) . Por padrão, ele gera o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). O nome é preterido porque não segue as regras padrão do C para nomes específicos da implementação. No entanto, a função ainda tem suporte.

É recomendável usar [_memccpy](memccpy.md) em vez disso. Ou, você pode continuar a usar esse nome de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
