---
title: novtable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- novtable_cpp
dev_langs:
- C++
helpviewer_keywords:
- novtable __declspec keyword
- __declspec keyword [C++], novtable
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ad0c50330d174a6139ce6e588b278e03cd99562
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942262"
---
# <a name="novtable"></a>novtable
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Esse é um **declspec** atributo estendido.  
  
 Essa forma de **declspec** podem ser aplicadas a qualquer declaração de classe, mas só deve ser aplicado a classes puras da interface, ou seja, classes que nunca serão instanciadas por conta própria. O **declspec** interrompe o compilador gere código para inicializar vfptr nos construtores e destruidores da classe. Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá. Usando essa forma de **declspec** pode resultar em uma redução significativa no tamanho do código.  
  
 Se você tentar instanciar uma classe marcada com `novtable` e, em seguida, acessar em um membro da classe, você receberá uma violação de acesso (AV).  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)