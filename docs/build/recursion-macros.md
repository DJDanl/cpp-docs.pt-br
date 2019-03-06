---
title: Macros de recursão
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, recursion macros
- recursion macros
- macros, recursion
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
ms.openlocfilehash: c04b23d4c8116fdf898c2f732b63c5e02adf5661
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416404"
---
# <a name="recursion-macros"></a>Macros de recursão

Use macros de recursão para chamar recursivamente NMAKE. Sessões recursiva herdam macros de variável de ambiente e de linha de comando e as informações do Tools. ini. Eles não herdam as regras de inferência de tipos definidos pelo makefile ou **. SUFIXOS** e **. PRECIOSOS** especificações. Para passar a uma sessão NMAKE recursiva macros, definir uma variável de ambiente com SET antes da chamada recursiva, defina uma macro no comando para a chamada recursiva ou definir uma macro em Tools. ini.

|Macro|Definição|
|-----------|----------------|
|**VERIFIQUE**|Comando usado originalmente para invocar o NMAKE.<br /><br /> A macro $ (Make) fornece o caminho completo para nmake.exe.|
|**MAKEDIR**|Diretório atual quando NMAKE foi invocado.|
|**MAKEFLAGS**|Opções atualmente em vigor. Usar como `/$(MAKEFLAGS)`.  Observe que, /F não está incluído.|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](../build/special-nmake-macros.md)
