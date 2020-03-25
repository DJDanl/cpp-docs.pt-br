---
title: Aviso U4010 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4010
helpviewer_keywords:
- U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
ms.openlocfilehash: f68da1893eec6325ccccfd0e2e2dd0e612f28eb9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193128"
---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)

' target ': falha na compilação; /K especificado, continuando...

Um comando no bloco de comandos para o destino fornecido retornou um código de saída diferente de zero. A opção/K disse NMAKE para continuar a processar partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Se o destino fornecido for, o próprio, um dependente para outro destino, NMAKE emitirá um aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após esse aviso.
