---
title: putenv
ms.date: 12/16/2019
api_name:
- putenv
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
- api-ms-win-crt-environment-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- putenv
helpviewer_keywords:
- putenv function
ms.assetid: 1dc49ef3-6b12-484c-8e60-7048bcc999f1
ms.openlocfilehash: 0a2a86753f1d9780f1dd8e3baf60f50ff1e79ea2
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75300762"
---
# <a name="putenv"></a>putenv

O nome da função POSIX implementada pela Microsoft `putenv` é um alias preterido para a função [_putenv](putenv-wputenv.md) . Por padrão, ele gera o [aviso do compilador (nível 3) C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). O nome é preterido porque não segue as regras padrão do C para nomes específicos da implementação. No entanto, a função ainda tem suporte.

É recomendável usar [_putenv](putenv-wputenv.md) ou [_putenv_s](putenv-s-wputenv-s.md) função com segurança avançada em vez disso. Ou, você pode continuar a usar esse nome de função e desabilitar o aviso. Para obter mais informações, consulte desligar os nomes de [função](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names) [de aviso](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#turn-off-the-warning) e POSIX.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).
