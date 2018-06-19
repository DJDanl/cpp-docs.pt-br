---
title: Compilador erro C3170 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3170
dev_langs:
- C++
helpviewer_keywords:
- C3170
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8bb077bcad95de0be17e630803b5d4ea9825be61
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33255907"
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