---
title: C2732 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2732
dev_langs:
- C++
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 38b364ac890118ce90164c3003a76e0d3c2e100d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2732"></a>C2732 de erro do compilador
especificação de vínculo contradiz especificação anterior para 'function'  
  
 A função já foi declarada com um especificador de vinculação diferentes.  
  
 Esse erro pode ser causado por incluem arquivos com especificadores de vinculação diferentes.  
  
 Para corrigir esse erro, altere o `extern` instruções para que os vínculos concordam. Em particular, não encapsule `#include` diretivas em `extern "C"` blocos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2732:  
  
```  
// C2732.cpp  
extern void func( void );   // implicit C++ linkage  
extern "C" void func( void );   // C2732  
```
