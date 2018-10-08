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
ms.openlocfilehash: 1c70c76292b62560b1d9895aca2851b4cf56802b
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861792"
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