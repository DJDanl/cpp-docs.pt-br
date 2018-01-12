---
title: Aviso LNK4217 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4217
dev_langs: C++
helpviewer_keywords: LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 09c984d7675c73bdf225bae7d3014f81153d20e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)
definidos localmente o símbolo 'symbol' importado na função 'function'  
  
 [__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo, mesmo que o símbolo é definido localmente. Remover o `__declspec` modificador para resolver este aviso.  
  
 `symbol`é o nome do símbolo que é definido dentro da imagem. `function`é a função que está importando o símbolo.  
  
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