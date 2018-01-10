---
title: C4936 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4936
dev_langs: C++
helpviewer_keywords: C4936
ms.assetid: 6676de35-bf1b-4d0b-a70f-b5734130336c
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 995cd7b2b774b768d6bccf10ddcec18101580e74
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4936"></a>C4936 de aviso do compilador
Este declspec é suportado apenas quando compilado com /clr ou /clr: pure  
  
 O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015.  
  
 Um `__declspec` modificador foi usado, mas que `__declspec` modificador só é válido quando compilado com uma da [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opções.  
  
 Para obter mais informações, consulte [appdomain](../../cpp/appdomain.md) e [processo](../../cpp/process.md).  
  
 C4936 sempre é emitido como um erro.  Você pode desabilitar C4936 com o [aviso](../../preprocessor/warning.md) pragma.  
  
 O exemplo a seguir gera C4936:  
  
```  
// C4936.cpp  
// compile with: /c  
// #pragma warning (disable : 4936)  
__declspec(process) int i;   // C4936  
__declspec(appdomain) int j;   // C4936  
```