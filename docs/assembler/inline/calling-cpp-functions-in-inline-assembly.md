---
title: Chamando funções C++ em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: ffbd8038d240bc2ab0240d172d914790b6ca02ab
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="calling-c-functions-in-inline-assembly"></a>Chamando funções C++ no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Um `__asm` bloco pode chamar somente funções de C++ globais que não estão sobrecarregadas. Se você chamar uma função sobrecarregada de C++ global ou uma função de membro de C++, o compilador emite um erro.  
  
 Você também pode chamar quaisquer funções declaradas com **extern "C"** vinculação. Isso permite que um `__asm` blocos dentro de um programa do C++ para chamar as funções de biblioteca C, porque todos os arquivos de cabeçalho padrão declarar as funções da biblioteca tenham **extern "C"** vinculação.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)