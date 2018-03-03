---
title: C2441 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2441
dev_langs:
- C++
helpviewer_keywords:
- C2441
ms.assetid: ffbd6573-777a-48dd-892f-5cf4a758dcab
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 645e06a0685f00359d468a4a4b9bd3522921b511
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2441"></a>C2441 de erro do compilador
'variável': um símbolo declarado com __declspec(process) deve ser const em /clr: pure modo  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Por padrão, as variáveis são por domínio de aplicativo em **/clr: pure**. Marcado como uma variável `__declspec(process)` em **/clr: pure** é propensa a erros se modificado em um domínio do aplicativo e de leitura em outro.  
  
 Portanto, o compilador aplica por processo ser variáveis `const` em **/clr: puro**, tornando-os de leitura apenas em todos os domínios de aplicativo.  
  
 Para obter mais informações, consulte [processo](../../cpp/process.md) e [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2441.  
  
```  
// C2441.cpp  
// compile with: /clr:pure /c  
__declspec(process) int i;   // C2441  
__declspec(process) const int j = 0;   // OK  
```