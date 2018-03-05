---
title: Portabilidade em limites ABI (C++ moderno) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: abbd405e-3038-427c-8c24-e00598f0936a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 06cb6c97580b4c4c9a6c961cb76f2c4d84d841ac
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="portability-at-abi-boundaries-modern-c"></a>Portabilidade em limites ABI (C++ moderno)
Use tipos suficientemente portáteis e convenções nos limites da interface binária. Um "tipo portátil" é um tipo interno de C ou uma estrutura que contém apenas os tipos internos de C. Tipos de classe só podem ser usados quando o chamador e o receptor concordarem com layout, chamando convenção, etc. Isso é possível somente quando ambos são compiladas com o mesmo compilador e as configurações do compilador.  
  
## <a name="how-to-flatten-a-class-for-c-portability"></a>Como mesclar uma classe para a portabilidade de C  
 Quando os chamadores podem ser compilados com outro compilador/idioma, "mesclar" para um **extern "C"** API com uma convenção de chamada específica:  
  
```cpp  
// class widget {  
//   widget();  
//   ~widget();  
//   double method( int, gadget& );  
// };  
extern "C" {        // functions using explicit "this"  
   struct widget;   // opaque type (forward declaration only)  
   widget* STDCALL widget_create();      // constructor creates new "this"  
   void STDCALL widget_destroy(widget*); // destructor consumes "this"  
   double STDCALL widget_method(widget*, int, gadget*); // method uses "this"  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)