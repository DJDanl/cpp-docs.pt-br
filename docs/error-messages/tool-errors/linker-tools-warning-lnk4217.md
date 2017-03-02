---
title: Aviso LNK4217 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4217
dev_langs:
- C++
helpviewer_keywords:
- LNK4217
ms.assetid: 280dc03e-5933-4e8d-bb8c-891fbe788738
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5f52555af529561f7665aea86307b78ff7e6fdba
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4217"></a>Aviso LNK4217 (Ferramentas de Vinculador)
definida localmente o símbolo 'symbol' importado na função 'function'  
  
 [__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para um símbolo, embora o símbolo é definido localmente. Remover o `__declspec` modificador para resolver esse aviso.  
  
 `symbol`é o nome do símbolo que é definido dentro da imagem. `function`é a função que está importando o símbolo.  
  
 Esse aviso não aparecerá quando você compila com a opção [/clr](../../build/reference/clr-common-language-runtime-compilation.md).  
  
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
  
 A tentativa de vincular esses dois módulos resultará em LNK4217, compile o segundo exemplo com a biblioteca de importação do primeiro exemplo para resolver.
