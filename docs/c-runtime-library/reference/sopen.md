---
title: sopen
ms.date: 12/16/2019
api_name:
- sopen
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
- sopen
helpviewer_keywords:
- sopen function
ms.assetid: 1ce0b707-0c9e-4942-8467-ce7f6cd68acc
ms.openlocfilehash: 83ec3ee87f16d37d651b2e7a37e0f7eaebe0f46d
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75300710"
---
# <a name="sopen"></a>sopen

O nome da função específica da Microsoft `sopen` é um alias preterido para a função [_sopen](sopen-wsopen.md) . Por padrão, ele gera o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). O nome é preterido porque não segue as regras padrão do C para nomes específicos da implementação. No entanto, a função ainda tem suporte.

É recomendável usar [_sopen](sopen-wsopen.md) ou a função de [_sopen_s](sopen-s-wsopen-s.md) com segurança avançada em vez disso. Ou, você pode continuar a usar esse nome de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.
