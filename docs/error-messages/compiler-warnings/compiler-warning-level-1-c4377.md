---
title: "Compilador (nível 1) de aviso C4377 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4377
dev_langs: C++
helpviewer_keywords: C4377
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b2cf61aa35bcfc40a40febb9e066caba6decd682
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4377"></a>Compilador C4377 de aviso (nível 1)
tipos nativos são private por padrão. -d1PrivateNativeTypes é preterido  
  
 Em versões anteriores, os tipos nativos em assemblies foram públicos por padrão e uma opção de compilador interno, não documentada, (**/d1PrivateNativeTypes**) foi usado para torná-los em particular.  
  
 Todos os tipos, nativo e o CLR, agora são private por padrão em um assembly, para **/d1PrivateNativeTypes** não é mais necessário.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4377.  
  
```  
// C4377.cpp  
// compile with: /clr /d1PrivateNativeTypes /W1  
// C4377 warning expected  
int main() {}  
```