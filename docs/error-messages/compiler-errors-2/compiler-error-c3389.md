---
title: C3389 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3389
dev_langs:
- C++
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
caps.latest.revision: 9
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
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 6cfe5a03ecbb370eaf290f94ee5e26a5d185a1ae
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3389"></a>C3389 de erro do compilador
__declspec(Keyword) não pode ser usado com o /clr: puro ou /CLR: safe  
  
 O **/clr: puro** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015.  
  
 A [declspec](../../cpp/declspec.md) modificador usado implica um segundo o estado do processo.  [/CLR: puro](../../build/reference/clr-common-language-runtime-compilation.md) implica um por [appdomain](../../cpp/appdomain.md) estado.  Portanto, declarando uma variável com o `keyword` **declspec** modificador e compilar com **/clr: puro** não é permitido.  
  
 O exemplo a seguir gera C3389:  
  
```  
// C3389.cpp  
// compile with: /clr:pure /c  
__declspec(dllexport) int g2 = 0;   // C3389  
```
