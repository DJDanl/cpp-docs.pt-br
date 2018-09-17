---
title: Onde definir Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- defining macros
- macros, NMAKE
- NMAKE program, defining macros
ms.assetid: 0fc59ec5-5f58-4644-b7da-7b021f7001af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29a2899d7dba0b34c0ac3319c253c8056912d883
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713796"
---
# <a name="where-to-define-macros"></a>Onde definir macros

Defina macros em uma linha de comando, o arquivo de comando, o makefile ou o arquivo Tools. ini.

Em um makefile ou o arquivo Tools. ini, cada definição de macro deve aparecer em uma linha separada e não pode começar com um espaço ou tabulação. São ignoradas espaços ou tabulações em torno do sinal de igual. Todos os [cadeia de caracteres](../build/defining-an-nmake-macro.md) são literais, incluindo que cercam as aspas e espaços inseridos.

Em uma linha de comando ou arquivo de comando, espaços e guias delimitam argumentos em não podem envolver o sinal de igual. Se `string` tem inseridos espaços ou tabulações, coloque a cadeia de caracteres em si ou a macro inteira entre aspas duplas ("").

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)