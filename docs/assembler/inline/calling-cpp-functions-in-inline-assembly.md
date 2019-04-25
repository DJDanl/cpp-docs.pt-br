---
title: Chamando funções C++ no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- functions [C++], calling in inline assembly
- function calls, C++ functions
- function calls, in inline assembly
- Visual C++, functions
- inline assembly, calling functions
- __asm keyword [C++], calling functions
ms.assetid: 1f0d1eb3-54cf-45d5-838d-958188616b38
ms.openlocfilehash: 666f7b2a59f0d48a14be54a439b6402f2a4d3128
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167264"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C++ no assembly embutido

**Seção específica da Microsoft**

Um `__asm` bloco pode chamar apenas funções de C++ globais que não são sobrecarregadas. Se você chamar uma função sobrecarregada de C++ global ou uma função de membro de C++, o compilador emitirá um erro.

Você também pode chamar quaisquer funções declaradas com **extern "C"** vinculação. Isso permite que um `__asm` bloco dentro de um programa C++ para chamar as funções da biblioteca C, porque todos os arquivos de cabeçalho padrão declara as funções de biblioteca ter **extern "C"** vinculação.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>