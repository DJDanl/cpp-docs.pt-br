---
title: strrev, wcsrev
ms.date: 12/16/2019
api_name:
- strrev
- wcsrev
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
- strrev
- wcsrev
helpviewer_keywords:
- strrev function
- wcsrev function
ms.assetid: 89e05854-a9ce-4fb7-993d-a9831cd7edf2
ms.openlocfilehash: b29ed572c52bb7e278f63c7c359fec7a79bf55eb
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301061"
---
# <a name="strrev-wcsrev"></a>strrev, wcsrev

Os nomes de função específicos da Microsoft `strrev` e `wcsrev` são aliases preteridos para as funções [_strrev e _wcsrev](strrev-wcsrev-mbsrev-mbsrev-l.md) . Por padrão, eles geram o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Os nomes são preteridos porque não seguem as regras padrão do C para nomes específicos da implementação. No entanto, as funções ainda têm suporte.

É recomendável usar [_strrev e _wcsrev](strrev-wcsrev-mbsrev-mbsrev-l.md) em vez disso. Ou, você pode continuar a usar esses nomes de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
