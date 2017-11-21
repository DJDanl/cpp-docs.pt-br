---
title: C3034 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3034
dev_langs: C++
helpviewer_keywords: C3034
ms.assetid: 49db8bac-2720-4622-94e3-7988f1603fa3
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 65db8f94bbc6a37ded8a566e52acd7370037863a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3034"></a>C3034 de erro do compilador
Diretiva de OpenMP 'directive1' não pode ser aninhada diretamente dentro de diretiva 'directive2'  
  
 Algumas diretivas não podem ser aninhadas. Para corrigir esse erro, você pode mesclar as declarações de ambas as diretivas para o bloco de uma diretiva de, ou você pode construir diretivas consecutivas.  
  
 O exemplo a seguir gera C3034:  
  
```  
// C3034.cpp  
// compile with: /openmp /link vcomps.lib  
int main() {  
  
   #pragma omp single  
   {  
      #pragma omp single   // C3034   
      {  
      ;  
      }  
   }  
  
   // Two consecutive single clauses are OK.  
   #pragma omp single  
   {  
   }  
  
   #pragma omp single  
   {  
   }  
}  
```