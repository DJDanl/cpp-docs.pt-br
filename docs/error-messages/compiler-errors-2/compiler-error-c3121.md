---
title: C3121 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3121
dev_langs:
- C++
helpviewer_keywords:
- C3121
ms.assetid: 1d3c7be4-d42d-4def-8d53-182c0c5cc237
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7bed28e3b209f11f170c0f3c63d9e7eecf1da81d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3121"></a>C3121 de erro do compilador
não é possível alterar o GUID para classe 'class_name'  
  
 Você tentou alterar a ID de classe com [__declspec(uuid)](../../cpp/uuid-cpp.md).  
  
 Por exemplo, o código a seguir gera C3121:  
  
```  
// C3121.cpp  
[emitidl];  
[module(name="MyLibrary")];  
  
[coclass, uuid="00000000-0000-0000-0000-111111111111"]  
class __declspec(uuid("00000000-0000-0000-0000-111111111112")) A   // C3121  
{  
};  
int main()  
{  
}  
```