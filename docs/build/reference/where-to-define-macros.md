---
title: Onde definir macros
ms.date: 11/04/2016
helpviewer_keywords:
- defining macros
- macros, NMAKE
- NMAKE program, defining macros
ms.assetid: 0fc59ec5-5f58-4644-b7da-7b021f7001af
ms.openlocfilehash: dc03644adea4619b3eabe33c481d71f704a9f410
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316360"
---
# <a name="where-to-define-macros"></a>Onde definir macros

Defina macros em uma linha de comando, o arquivo de comando, o makefile ou o arquivo Tools. ini.

Em um makefile ou o arquivo Tools. ini, cada definição de macro deve aparecer em uma linha separada e não pode começar com um espaço ou tabulação. São ignoradas espaços ou tabulações em torno do sinal de igual. Todos os [cadeia de caracteres](defining-an-nmake-macro.md) são literais, incluindo que cercam as aspas e espaços inseridos.

Em uma linha de comando ou arquivo de comando, espaços e guias delimitam argumentos em não podem envolver o sinal de igual. Se `string` tem inseridos espaços ou tabulações, coloque a cadeia de caracteres em si ou a macro inteira entre aspas duplas ("").

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](defining-an-nmake-macro.md)
