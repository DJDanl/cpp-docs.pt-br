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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aeecaab0fd9faaa6a876aa57781160df6bb26502
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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