---
title: Chamando funções C++ em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- functions [C++], calling in inline assembly
- function calls, C++ functions
- function calls, in inline assembly
- Visual C++, functions
- inline assembly, calling functions
- __asm keyword [C++], calling functions
ms.assetid: 1f0d1eb3-54cf-45d5-838d-958188616b38
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4717ae24dc1a0b6f51f7a00f68f6569c2f988c65
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43678938"
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C++ no assembly embutido

**Seção específica da Microsoft**

Um `__asm` bloco pode chamar apenas funções de C++ globais que não são sobrecarregadas. Se você chamar uma função sobrecarregada de C++ global ou uma função de membro de C++, o compilador emitirá um erro.

Você também pode chamar quaisquer funções declaradas com **extern "C"** vinculação. Isso permite que um `__asm` bloco dentro de um programa C++ para chamar as funções da biblioteca C, porque todos os arquivos de cabeçalho padrão declara as funções de biblioteca ter **extern "C"** vinculação.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>