---
title: Erro fatal U1100 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1100
helpviewer_keywords:
- U1100
ms.assetid: c71910a7-c581-4d9c-a38c-d2d557d56289
ms.openlocfilehash: d5c62c1465bbb6463afbac2bc9ad5f4290473471
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193258"
---
# <a name="nmake-fatal-error-u1100"></a>Erro fatal U1100 (NMAKE)

a macro ' macroname ' é inválida no contexto da regra de lote ' rule '

NMAKE gera esse erro quando o bloco de comando de uma regra de modo de lote faz referência direta ou indiretamente a uma macro de arquivo especial que não é $ <.

$ < é a única macro permitida para regras de modo de lote.
