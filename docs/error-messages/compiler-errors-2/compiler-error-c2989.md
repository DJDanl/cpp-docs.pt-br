---
title: C2989 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2989
dev_langs: C++
helpviewer_keywords: C2989
ms.assetid: 936303d8-eb3b-4746-82ec-2f18020a6f64
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: badfecd1c92b42a26682b714a16e24206ca05736
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2989"></a>C2989 de erro do compilador
'class': tipo de classe já foi declarado como um tipo diferente de classe  
  
 A classe genérica ou modelo redefine uma classe diferente do modelo ou não genérica. Verifique os arquivos de cabeçalho de conflitos.  
  
 Se você estiver usando especializações parciais de modelo de classe, consulte o artigo da Base de dados de Conhecimento Q240866.  
  
 O exemplo a seguir gera C2989:  
  
```  
// C2989.cpp  
// compile with: /c  
class C{};  
  
template <class T>  
class C{};  // C2989  
class C2{};  
```  
  
 C2989 também pode ocorrer ao usar genéricos:  
  
```  
// C2989b.cpp  
// compile with: /clr /c  
ref class GC1;  
  
generic <typename T> ref class GC1;   // C2989  
template <typename T> ref class GC2;  
  
generic <typename T> ref class GC2;   // C2989  
generic <typename T> ref class GCb;  
template <typename T> ref class GC2;  
generic <typename T> ref class GCc;  
```