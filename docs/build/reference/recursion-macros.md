---
title: Macros de recursão
description: Descreve as macros que você usa para chamar NMAKE em sessões recursivas.
ms.date: 11/20/2019
helpviewer_keywords:
- NMAKE program, recursion macros
- recursion macros
- macros, recursion
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
no-loc:
- MAKE
- MAKEDIR
- MAKEFLAGS
ms.openlocfilehash: f2bda23cb079e4fd7d12cea3598d33b3625c088d
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303144"
---
# <a name="recursion-macros"></a>Macros de recursão

Use macros de recursão para chamar NMAKE recursivamente. As sessões recursivas herdam as informações de linha de comando e variável de ambiente e ferramentas. ini. Eles não herdam regras de inferência definidas pelo makefile nem especificações de `.SUFFIXES` e `.PRECIOUS`. Há três maneiras de passar macros para uma sessão NMAKE recursiva: defina uma variável de ambiente com um comando :::no-loc text="SET"::: antes da chamada recursiva. Defina uma macro no comando para a chamada recursiva. Ou defina uma macro em Tools. ini.

|Macro|Definição|
|-----------|----------------|
|**MAKE**|Comando usado originalmente para invocar NMAKE.<br /><br /> A macro `$(MAKE)` fornece o caminho completo para NMAKE. exe.|
|**MAKEDIR**|Diretório atual quando NMAKE foi invocado.|
|**MAKEFLAGS**|Opções atualmente em vigor. Use as `/$(MAKEFLAGS)`. A opção **/f** não está incluída.|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](special-nmake-macros.md)
