---
title: C3172 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: a53e7bc0b8543813e5745773f6a7548eb9a83442
ms.lasthandoff: 04/04/2017

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
