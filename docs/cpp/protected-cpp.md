---
title: protegido (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- protected_cpp
dev_langs:
- C++
helpviewer_keywords:
- protected keyword [C++], member access
- protected keyword [C++]
ms.assetid: 863d299f-fc0d-45d5-a1a7-bd24b7778a93
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: b65c73c7ecc3419f4a2a40e4bf693049226bd8b7
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="protected-c"></a>protected (C++)
## <a name="syntax"></a>Sintaxe  
  
```  
protected:  
   [member-list]  
protected base-class  
```  
  
## <a name="remarks"></a>Comentários  
 O `protected` palavra-chave especifica o acesso a membros de classe no *lista de membros* até o próximo especificador de acesso (**pública** ou `private`) ou no final da definição de classe. Os membros de classe declarados como `protected` podem ser usados somente por:  
  
-   Funções de membro da classe que declarou originalmente esses membros.  
  
-   Friends da classe que declarou originalmente esses membros.  
  
-   Classes derivadas com acesso público ou protegido da classe que declarou originalmente esses membros.  
  
-   Direcionar classes derivadas de modo particular que também têm acesso aos membros protegidos.  
  
 Para preceder o nome de uma classe base, a palavra-chave `protected` especifica que os membros públicos e protegidos da classe base são membros protegidos de suas classes derivadas.  
  
 Membros protegidos não são como privados como `private` membros, que são acessíveis apenas a membros da classe na qual eles são declarados, mas não são como públicos como **pública** membros, que podem ser acessados em qualquer função.  
  
 Membros que também são declarados como protegidos **estático** estão acessíveis para qualquer função friend ou membro de uma classe derivada. Membros que não são declarados como protegidos **estático** são acessíveis para amigos e funções de membro em uma classe derivada apenas por meio de um ponteiro para fazer referência a, ou o objeto da classe derivada.  
  
 Para obter informações relacionadas, consulte [friend](../cpp/friend-cpp.md), [pública](../cpp/public-cpp.md), [privada](../cpp/private-cpp.md)e a tabela de acesso de membro na [controlando o acesso a membros de classe](member-access-control-cpp.md) .  
  
## <a name="clr-specific"></a>Específico do /clr  
 Em tipos CLR, o C++ acessar palavras-chave do especificador (**pública**, `private`, e `protected`) podem afetar a visibilidade de tipos e métodos em relação a assemblies. Para obter mais informações, consulte [controle de acesso de membro](member-access-control-cpp.md).  
  
> [!NOTE]
>  Arquivos compilados com [/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento. Nesse caso, todas as classes gerenciadas (públicas ou particulares) serão visíveis.  
  
## <a name="end-clr-specific"></a>Específico de END /clr  
  
## <a name="example"></a>Exemplo  
  
```  
// keyword_protected.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class X {  
public:  
   void setProtMemb( int i ) { m_protMemb = i; }  
   void Display() { cout << m_protMemb << endl; }  
protected:  
   int  m_protMemb;  
   void Protfunc() { cout << "\nAccess allowed\n"; }  
} x;  
  
class Y : public X {  
public:  
   void useProtfunc() { Protfunc(); }  
} y;  
  
int main() {  
   // x.m_protMemb;         error, m_protMemb is protected  
   x.setProtMemb( 0 );   // OK, uses public access function  
   x.Display();  
   y.setProtMemb( 5 );   // OK, uses public access function  
   y.Display();  
   // x.Protfunc();         error, Protfunc() is protected  
   y.useProtfunc();      // OK, uses public access function  
                        // in derived class  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controlando o acesso a membros de classe](member-access-control-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
