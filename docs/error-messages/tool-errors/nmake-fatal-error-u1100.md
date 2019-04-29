---
title: Erro fatal U1100 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1100
helpviewer_keywords:
- U1100
ms.assetid: c71910a7-c581-4d9c-a38c-d2d557d56289
ms.openlocfilehash: a1474acab4ca4929fb4db4b7b78d7a96637a0745
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298276"
---
# <a name="nmake-fatal-error-u1100"></a>Erro fatal U1100 (NMAKE)

macro 'macroname' é ilegal no contexto da regra de lote 'rule'

NMAKE gera esse erro quando o bloco de comando de uma regra de modo de lote, direta ou indiretamente, referencia uma macro de arquivo especial que não é $<.

$< é permitido apenas para macro para regras de modo de lote.