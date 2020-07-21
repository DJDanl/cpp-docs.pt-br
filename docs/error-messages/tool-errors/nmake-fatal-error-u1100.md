---
title: Erro fatal U1100 (NMAKE)
description: Uma descrição das causas do erro fatal do Microsoft NMAKE U1100.
ms.date: 07/17/2020
f1_keywords:
- U1100
helpviewer_keywords:
- U1100
ms.assetid: c71910a7-c581-4d9c-a38c-d2d557d56289
ms.openlocfilehash: f908514469a6c9fdb53df3b2bded1b30bddc5a41
ms.sourcegitcommit: 00af3df3331854b23693ee844e5e7c10c8b05a90
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/20/2020
ms.locfileid: "86491382"
---
# <a name="nmake-fatal-error-u1100"></a>Erro fatal U1100 (NMAKE)

> a macro '*nome*da macro ' é inválida no contexto da regra de lote '*rule-name*'

NMAKE gera esse erro quando o bloco de comando de uma regra de modo de lote faz referência direta ou indiretamente a uma macro de arquivo especial que não é `$<` .

`$<`é a única macro permitida para regras de modo de lote.

Para obter mais informações sobre as macros do NMAKE em regras do lote, consulte [macros especiais do NMAKE](../../build/reference/special-nmake-macros.md).
