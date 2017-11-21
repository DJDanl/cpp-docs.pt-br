---
title: C3839 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3839
dev_langs: C++
helpviewer_keywords: C3839
ms.assetid: 0957faff-1e9f-439b-876b-85bd8d2c578d
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8a8c9fa9112128b86123693aea7443d68e8531d0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3839"></a>C3839 de erro do compilador
não é possível alterar alinhamento em gerenciada ou tipo de WinRT  
  
 Alinhamento de variáveis em gerenciado ou tipos de tempo de execução do Windows é controlado pelo tempo de execução do Windows ou do CLR e não pode ser modificado com [alinhar](../../cpp/align-cpp.md).  
  
 O exemplo a seguir gera C3839:  
  
```  
// C3839a.cpp  
// compile with: /clr  
ref class C  
{  
public:  
   __declspec(align(32)) int m_j; // C3839  
};  
  
int main()  
{  
}  
```