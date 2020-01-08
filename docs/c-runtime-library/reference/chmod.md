---
title: chmod
ms.date: 12/16/2019
api_name:
- chmod
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
- chmod
helpviewer_keywords:
- chmod function
ms.assetid: c3294722-2194-4ff4-ac87-d69f155e279b
ms.openlocfilehash: 7852a2e8cfb6719e7120291e6a74500e660a7fba
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75299904"
---
# <a name="chmod"></a>chmod

O nome da função POSIX implementada pela Microsoft `chmod` é um alias preterido para a função [_chmod](chmod-wchmod.md) . Por padrão, ele gera o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). O nome é preterido porque não segue as regras padrão do C para nomes específicos da implementação. No entanto, a função ainda tem suporte.

É recomendável usar [_chmod](chmod-wchmod.md) em vez disso. Ou, você pode continuar a usar esse nome de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
