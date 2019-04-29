---
title: Aviso U4010 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4010
helpviewer_keywords:
- U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
ms.openlocfilehash: aa4d2355b18a3c6cc6fc3151c7662fbbbaa665d6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298107"
---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)

'target': compilação falhada; /K especificado, continuando...

Um comando no bloco de comandos para o destino especificado retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando as partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Se for o destino especificado, em si, um dependente para outro destino, NMAKE emite aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após este aviso.