---
title: C3172 de erro do compilador | Documentos do Microsoft
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f045f6aab578fe2a7657d661cb73536a33941a0d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3172"></a>C3172 de erro do compilador
'module_name': não é possível especificar atributos idl_module diferentes em um projeto  
  
 [idl_module](../../windows/idl-module.md) atributos com o mesmo nome mas diferentes `dllname` ou `version`parâmetros foram encontrados em dois dos arquivos em uma compilação. Somente um único `idl_module` atributo pode ser especificado por compilação.  
  
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
  
 o compilador poderia gerar C3172 (Observe os valores de versão diferente).
