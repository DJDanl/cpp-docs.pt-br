---
title: C2732 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2732
dev_langs:
- C++
helpviewer_keywords:
- C2732
ms.assetid: 01b7ad2c-93cf-456f-a4c0-c5f2fdc7c07c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ef2faf21eb6f0c73d02ea32c7d4ed53f86eec3de
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233025"
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