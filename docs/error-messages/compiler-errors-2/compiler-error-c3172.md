---
title: C3172 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3172
dev_langs:
- C++
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b3feadd9c8fc39edb707e8dbd3a80ed90d078d72
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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