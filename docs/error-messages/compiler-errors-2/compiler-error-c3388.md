---
title: C3388 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3388
dev_langs: C++
helpviewer_keywords: C3388
ms.assetid: 34336545-ed13-4d81-ab5f-f869799fe4c2
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: dce412e8998448cdbf746b4598804f2645e10237
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3388"></a>C3388 de erro do compilador
'type': não é permitido como uma restrição, assumindo 'classe ref' para continuar análise  
  
 Uma restrição foi especificada em um tipo genérico, mas a restrição não foi especificada corretamente. Consulte [restrições em parâmetros de tipo genérico (C + + CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3388.  
  
```  
// C3388.cpp  
// compile with: /clr /c  
interface class AA {};  
  
generic <class T>  
where T : interface class   // C3388  
ref class C {};  
  
// OK  
generic <class T>  
where T : AA  
ref class D {};  
```