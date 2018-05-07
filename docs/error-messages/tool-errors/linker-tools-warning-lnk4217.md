---
title: Aviso LNK4217 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4217
dev_langs:
- C++
helpviewer_keywords:
- LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 625f3a1b8a67f198b1cb4ca37bd1350229ec20db
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)
definidos localmente o símbolo 'symbol' importado na função 'function'  
  
 [__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo, mesmo que o símbolo é definido localmente. Remover o `__declspec` modificador para resolver este aviso.  
  
 `symbol` é o nome do símbolo que é definido dentro da imagem. `function` é a função que está importando o símbolo.  
  
 Esse aviso não aparecerá quando você compila usando a opção [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 LNK4217 também pode ocorrer se você tentar vincular dois módulos, quando em vez disso, você deve compilar o segundo módulo com a biblioteca de importação do módulo primeiro.  
  
```  
// LNK4217.cpp  
// compile with: /LD  
#include "windows.h"  
__declspec(dllexport) void func(unsigned short*) {}  
```  
  
 E, em seguida,  
  
```  
// LNK4217b.cpp  
// compile with: /c  
#include "windows.h"  
__declspec(dllexport) void func(unsigned short*) {}  
```  
  
 Tentando vincular esses dois módulos resultará em LNK4217, compile o segundo exemplo com a biblioteca de importação do primeiro exemplo para resolver.