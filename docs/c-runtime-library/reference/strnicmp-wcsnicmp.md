---
title: strnicmp, wcsnicmp
ms.date: 12/16/2019
api_name:
- wcsnicmp
- strnicmp
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
- wcsnicmp
- strnicmp
helpviewer_keywords:
- strnicmp function
- wcsnicmp function
ms.assetid: 01324ee4-0bd9-43e9-b2a3-53d180270a64
ms.openlocfilehash: 6f52df6d0a75922fefb63ee233250f20b1209f74
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75300489"
---
# <a name="strnicmp-wcsnicmp"></a>strnicmp, wcsnicmp

Os nomes de função específicos da Microsoft `strnicmp` e `wcsnicmp` são aliases preteridos para as funções [_strnicmp e _wcsnicmp](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md) . Por padrão, eles geram o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Os nomes são preteridos porque não seguem as regras padrão do C para nomes específicos da implementação. No entanto, as funções ainda têm suporte.

É recomendável usar [_strnicmp e _wcsnicmp](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md) em vez disso. Ou, você pode continuar a usar esses nomes de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
