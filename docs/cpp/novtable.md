---
title: novtable | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: novtable_cpp
dev_langs: C++
helpviewer_keywords:
- novtable __declspec keyword
- __declspec keyword [C++], novtable
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 26dc6677c6fcc7ab3834d3bb13d9e85dd0d8ede0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="novtable"></a>novtable
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Esse é um atributo `__declspec` estendido.  
  
 Essa forma de `__declspec` pode ser aplicada a qualquer declaração de classe, mas só deve ser aplicada às classes puras da interface, ou seja, classes que nunca serão instanciadas por conta própria. `__declspec` impede que o compilador gere códigos para inicializar vfptr nos construtores e destruidores da classe. Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá. Usar esta forma de `__declspec` pode resultar em uma redução significativa do tamanho do código.  
  
 Se você tentar instanciar uma classe marcada com `novtable` e, em seguida, acessar em um membro da classe, você receberá uma violação de acesso (AV).  
  
## <a name="example"></a>Exemplo  
  
```  
// novtable.cpp  
#include <stdio.h>  
  
struct __declspec(novtable) X {  
   virtual void mf();  
};  
  
struct Y : public X {  
   void mf() {  
      printf_s("In Y\n");  
   }  
};  
  
int main() {  
   // X *pX = new X();  
   // pX->mf();   // Causes a runtime access violation.  
  
   Y *pY = new Y();  
   pY->mf();  
}  
```  
  
```Output  
In Y  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)