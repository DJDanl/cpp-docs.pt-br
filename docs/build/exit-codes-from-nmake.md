---
title: Códigos de saída de NMAKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, exit codes
- exit codes
ms.assetid: 75f6913c-1da5-4572-a2d3-8a4e058bed15
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b5a593e38efb5230630ed01e65f4bfb1f2ba92a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722612"
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