---
title: "Compilador aviso (nível 3) C4373 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4373
dev_langs:
- C++
helpviewer_keywords:
- C4373
ms.assetid: 670c0ba3-b7d6-4aed-b207-1cb84da3bcde
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1312105941bf5da138c9757209e522b22ed42bce
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4373"></a>Compilador C4373 de aviso (nível 3)
'%$S': função virtual substitui '%$pS', versões anteriores do compilador não substituíam quando parâmetros diferiam apenas em qualificadores const/volatile  
  
 Seu aplicativo contém um método em uma classe derivada que substitui um método virtual em uma classe base, e os parâmetros no método de substituição diferem somente por um [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md) qualificador dos parâmetros do método virtual. Isso significa que o compilador deve vincular uma referência de função para o método em uma base ou classe derivada.  
  
 Versões do compilador antes [!INCLUDE[cpp_orcas_long](../../cpp/includes/cpp_orcas_long_md.md)] associar a função para o método na classe base, em seguida, emitir uma mensagem de aviso. As versões subsequentes do compilador ignoram o `const` ou `volatile` qualificador, associar a função para o método na classe derivada, em seguida, emitir aviso `C4373`. Esse último comportamento compatível com o padrão de C++.  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir gera um aviso C4373.  
  
```  
// c4373.cpp  
// compile with: /c /W3  
#include <stdio.h>  
struct Base  
{  
    virtual void f(int i) {  
        printf("base\n");  
    }  
};  
struct Derived : Base  
{  
    void f(const int i) {  // C4373  
        printf("derived\n");  
    }  
};  
void main()  
{  
    Derived d;  
    Base* p = &d;  
    p->f(1);  
}  
```  
  
```Output  
derived  
```
