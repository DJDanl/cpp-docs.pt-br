---
title: C3172 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3172
dev_langs:
- C++
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6f6bc65ad1f62139e7131e7bb4fbd07a59cb9dd9
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3172"></a>C3172 de erro do compilador
'nome_de_módulo': não é possível especificar atributos de idl_module diferentes em um projeto  
  
 [idl_module](../../windows/idl-module.md) atributos com o mesmo nome mas diferentes `dllname` ou `version` foram encontrados parâmetros em dois dos arquivos em uma compilação. Somente um único `idl_module` atributo pode ser especificado por compilação.  
  
 Idêntico `idl_module` atributos podem ser especificados em mais de um arquivo de código fonte.  
  
 Por exemplo, se o seguinte `idl_module` atributos foram encontrados:  
  
```  
// C3172.cpp  
[module(name="MyMod")];  
[ idl_module(name="x", dllname="file.dll", version="1.1") ];  
int main() {}  
```  
  
 E, em seguida,  
  
```  
// C3172b.cpp  
// compile with: C3172.cpp  
// C3172 expected  
[ idl_module(name="x", dllname="file.dll", version="1.0") ];  
```  
  
 o compilador gere C3172 (Observe os valores de versão diferente).
