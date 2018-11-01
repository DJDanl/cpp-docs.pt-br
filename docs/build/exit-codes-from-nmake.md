---
title: Códigos de saída de NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, exit codes
- exit codes
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
ms.openlocfilehash: 08aceadf107112b446844b09fad24a11fbe7a731
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499580"
---
# <a name="exit-codes-from-nmake"></a>Códigos de saída de NMAKE

NMAKE retorna os seguintes códigos de saída:

|Código|Significado|
|----------|-------------|
|0|Nenhum erro (possivelmente um aviso)|
|1|Compilação incompleta (emitida somente quando /K é usado)|
|2|Erro de programa, possivelmente devido a um dos seguintes:|
||-Um erro de sintaxe no makefile|
||-Um código de erro ou sair de um comando|
||-Uma interrupção pelo usuário|
|4|Erro do sistema — sem memória|
|255|Destino não está atualizado (emitido somente quando /Q é usado)|

## <a name="see-also"></a>Consulte também

[Executando NMAKE](../build/running-nmake.md)