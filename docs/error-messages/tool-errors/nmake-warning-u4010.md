---
title: Aviso de NMAKE U4010 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4010
dev_langs:
- C++
helpviewer_keywords:
- U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a640245db460f4cd8cd658c097955a69a59d1fb7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117485"
---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)

'target': compilação falhada; /K especificado, continuando...

Um comando no bloco de comandos para o destino especificado retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando as partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Se for o destino especificado, em si, um dependente para outro destino, NMAKE emite aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após este aviso.