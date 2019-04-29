---
title: Macros de recursão
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, recursion macros
- recursion macros
- macros, recursion
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
ms.openlocfilehash: 064bc40906bcf3a126c225585a6df43443b5c38e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62319233"
---
# <a name="recursion-macros"></a>Macros de recursão

Use macros de recursão para chamar recursivamente NMAKE. Sessões recursiva herdam macros de variável de ambiente e de linha de comando e as informações do Tools. ini. Eles não herdam as regras de inferência de tipos definidos pelo makefile ou **. SUFIXOS** e **. PRECIOSOS** especificações. Para passar a uma sessão NMAKE recursiva macros, definir uma variável de ambiente com SET antes da chamada recursiva, defina uma macro no comando para a chamada recursiva ou definir uma macro em Tools. ini.

|Macro|Definição|
|-----------|----------------|
|**VERIFIQUE**|Comando usado originalmente para invocar o NMAKE.<br /><br /> A macro $ (Make) fornece o caminho completo para nmake.exe.|
|**MAKEDIR**|Diretório atual quando NMAKE foi invocado.|
|**MAKEFLAGS**|Opções atualmente em vigor. Usar como `/$(MAKEFLAGS)`.  Observe que, /F não está incluído.|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](special-nmake-macros.md)
