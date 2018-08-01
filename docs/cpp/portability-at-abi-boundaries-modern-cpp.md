---
title: Portabilidade em limites ABI (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: abbd405e-3038-427c-8c24-e00598f0936a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb9ce8012db8617afc7af3183bd7439ddeb8fab7
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402345"
---
# <a name="portability-at-abi-boundaries-modern-c"></a>Portabilidade em limites ABI (C++ moderno)
Use tipos suficientemente portáteis e convenções nos limites da interface binária. Um "tipo portátil" é um tipo interno de C ou um struct que contém apenas os tipos internos de C. Tipos de classe só podem ser usados quando o chamador e o receptor concordarem sobre layout, convenção de chamada etc. Isso é possível apenas quando ambas são compiladas com o mesmo compilador e as configurações do compilador.  
  
## <a name="how-to-flatten-a-class-for-c-portability"></a>Como mesclar uma classe para fins de portabilidade de C  
 Quando os chamadores podem ser compilados com outro compilador/idioma, em seguida, "mesclar" para um **extern "C"** API com uma convenção de chamada específica:  
  
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
 [Bem-vindo ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)