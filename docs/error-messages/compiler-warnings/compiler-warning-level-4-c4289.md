---
title: "Compilador aviso (nível 4) C4289 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4289
dev_langs:
- C++
helpviewer_keywords:
- C4289
ms.assetid: 0dbd2863-4cde-4e16-894b-104a2d5fa724
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
ms.openlocfilehash: 9e23937ad5b9116df63c7c2db4b993eb8ef563cd
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4289"></a>Compilador C4289 de aviso (nível 4)
extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo do loop for  
  
 Ao compilar com [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc:forScope-**, uma variável declarada em um [para](../../cpp/for-statement-cpp.md) loop foi usado após o **para**-escopo de loop.  
  
 Consulte [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar o comportamento padrão em **para** loops com **/Ze**.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4289:  
  
```  
// C4289.cpp  
// compile with: /W4 /Zc:forScope-  
#pragma warning(default:4289)  
int main() {  
   for (int i = 0 ; ; )   // C4289  
      break;  
   i++;  
}  
```
