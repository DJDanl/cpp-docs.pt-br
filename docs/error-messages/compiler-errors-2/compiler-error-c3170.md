---
title: Compilador erro C3170 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3170
dev_langs:
- C++
helpviewer_keywords:
- C3170
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: aa11ac93ab7e5637153a063a892d99e127b80f54
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3170"></a>C3170 de erro do compilador
não é possível ter identificadores de módulo diferentes em um projeto  
  
 [módulo](../../windows/module-cpp.md) atributos com nomes diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um único `module` atributo pode ser especificado por compilação.  
  
 Idêntico `module` atributos podem ser especificados em mais de um arquivo de código fonte.  
  
 Por exemplo, se os atributos de módulo a seguir foram encontrados:  
  
```  
// C3170.cpp  
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];  
int main() {}  
```  
  
 E, em seguida,  
  
```  
// C3170b.cpp  
// compile with: C3170.cpp  
// C3170 expected  
[ module(name="MyModule1", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];  
```  
  
 o compilador gere C3170 (Observe os nomes diferentes).
