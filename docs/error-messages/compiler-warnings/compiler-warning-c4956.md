---
title: C4956 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4956
dev_langs: C++
helpviewer_keywords: C4956
ms.assetid: 9154f2d1-d49f-4e07-90d2-0e9bc028011a
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0cda1c616eabbbbd2972f9d60f6d140758103aa6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4956"></a>C4956 de aviso do compilador
'type': este tipo não é verificável  
  
 Esse aviso é gerado quando [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) for especificado e seu código contém um tipo que não é verificável.  
  
 Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Esse aviso é emitido como um erro e pode ser desabilitado com o [aviso](../../preprocessor/warning.md) pragma ou [/wd](../../build/reference/compiler-option-warning-level.md) opção de compilador.  
  
 O exemplo a seguir gera C4956:  
  
```  
// C4956.cpp  
// compile with: /clr:safe  
int* p;   // C4956  
```