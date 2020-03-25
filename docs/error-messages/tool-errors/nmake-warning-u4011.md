---
title: Aviso U4011 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4011
helpviewer_keywords:
- U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
ms.openlocfilehash: 6b1701ffc83f849d2482bd14b25d65c04c496899
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193141"
---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)

' target ': nem todos os dependentes disponíveis; destino não compilado

Um dependente do destino fornecido não existia ou estava desatualizado, e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção/K disse NMAKE para continuar a processar partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Esse aviso é precedido por [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) de aviso para cada dependente que não pôde ser criado ou atualizado.
