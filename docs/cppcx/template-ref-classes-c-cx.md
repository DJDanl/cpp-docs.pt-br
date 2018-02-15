---
title: "Classes de referência de modelo (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
ms.assetid: a24d5f45-8dbb-4540-958f-c76c90d8ed93
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f135907a4aba473db62734f9370ee82b7113c66d
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="template-ref-classes-ccx"></a>Classes de referência de modelo (C++/CX)
Os modelos do C++ não são publicados em metadados e, portanto, não podem ter acessibilidade pública ou protegida no seu programa. Naturalmente, você pode usar modelos padrão do C++ internamente em seu programa. Além disso, você pode definir uma classe ref privada como um modelo e pode declarar explicitamente uma classe ref de modelo especializado como um membro privado em uma classe ref pública.  
  
## <a name="authoring-ref-class-templates"></a>Criando modelos de classe ref  
 O exemplo a seguir mostra como declarar uma classe ref privada como um modelo, como declarar um modelo padrão do C++ e como declará-los como membros em uma classe ref pública. Observe que o modelo padrão do C++ pode ser especializado por um tipo de tempo de execução do Windows, neste caso um Platform:: String ^.  
  
 [!code-cpp[cx_templates#01](../cppcx/codesnippet/CPP/templatedemo/class1.h#01)]  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos (C++/CX)](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)