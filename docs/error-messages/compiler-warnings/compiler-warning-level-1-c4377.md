---
title: "Compilador aviso (nível 1) C4377 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4377
dev_langs:
- C++
helpviewer_keywords:
- C4377
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
caps.latest.revision: 5
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 702bcfdd0caa096b1e47354f9e38fcc4d135f2b7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4377"></a>Compilador C4377 de aviso (nível 1)
tipos nativos são private por padrão; -d1PrivateNativeTypes é preterido  
  
 Em versões anteriores, tipos nativos em assemblies foram públicos por padrão e uma opção de compilador internos, documentadas (**/d1PrivateNativeTypes**) foi usado para torná-los particulares.  
  
 Todos os tipos, nativos e o CLR, agora são privados por padrão em um assembly, portanto **/d1PrivateNativeTypes** não é mais necessária.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4377.  
  
```  
// C4377.cpp  
// compile with: /clr /d1PrivateNativeTypes /W1  
// C4377 warning expected  
int main() {}  
```
