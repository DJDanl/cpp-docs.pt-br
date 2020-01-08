---
title: strnset, wcsnset
ms.date: 12/16/2019
api_name:
- strnset
- wcsnset
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
- wcsnset
- strnset
helpviewer_keywords:
- strnset function
- wcsnset function
ms.assetid: e7868ac9-dc34-4606-bd3c-0fb2e7c51631
ms.openlocfilehash: c1f00410dc15a329d6381af893eab44bb938f248
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301087"
---
# <a name="strnset-wcsnset"></a>strnset, wcsnset

Os nomes de função específicos da Microsoft `strnset` e `wcsnset` são aliases preteridos para as funções [_strnset e _wcsnset](strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md) . Por padrão, eles geram o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Os nomes são preteridos porque não seguem as regras padrão do C para nomes específicos da implementação. No entanto, as funções ainda têm suporte.

É recomendável que você use [_strnset e _wcsnset](strnset-strnset-l-wcsnset-wcsnset-l-mbsnset-mbsnset-l.md) ou as funções [_strnset_s e _wcsnset_s](strnset-s-strnset-s-l-wcsnset-s-wcsnset-s-l-mbsnset-s-mbsnset-s-l.md) com segurança avançada em vez disso. Ou, você pode continuar a usar esses nomes de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
