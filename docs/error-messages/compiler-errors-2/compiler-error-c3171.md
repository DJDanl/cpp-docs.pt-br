---
title: C3171 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3171
dev_langs:
- C++
helpviewer_keywords:
- C3171
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ed053e37dfbf5f3c85cf1f8ec44912eca3148315
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3171"></a>C3171 de erro do compilador
'module': não é possível especificar atributos de módulo diferentes em um projeto  
  
 [módulo](../../windows/module-cpp.md) atributos com listas de parâmetros diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um único `module` atributo pode ser especificado por compilação.  
  
 Idêntico `module` atributos podem ser especificados em mais de um arquivo de código fonte.  
  
 Por exemplo, se o seguinte `module` atributos foram encontrados:  
  
```  
// C3171.cpp  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.0") ];  
int main() {}  
```  
  
 E, em seguida,  
  
```  
// C3171b.cpp  
// compile with: C3171.cpp  
// C3171 expected  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.1") ];  
```  
  
 o compilador gere C3171 (Observe os valores de versão diferente).