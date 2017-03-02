---
title: Ferramentas de vinculador LNK2020 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2020
dev_langs:
- C++
helpviewer_keywords:
- LNK2020
ms.assetid: 4dd017d0-5e83-471b-ac8a-538ac1ed6870
caps.latest.revision: 16
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 642e3e1b1217bdd45618742bb805a3351ab0443b
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2020"></a>Erro das Ferramentas de Vinculador LNK2020
token 'token' não resolvido  
  
 Semelhante a um erro externo indefinido, exceto que a referência é por meio de metadados. Nos metadados, todas as funções e os dados devem ser definidos.  
  
 Para resolver:  
  
-   Definir a função ausente ou os dados, ou  
  
-   Inclua o arquivo de objeto ou a biblioteca na qual a função ausente ou os dados já estão definidos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK2020.  
  
```  
// LNK2020.cpp  
// compile with: /clr /LD  
ref struct A {  
   A(int x);   // LNK2020  
   static int f();   // LNK2020  
};  
  
// OK  
ref struct B {  
   B(int x) {}  
   static int f() { return 0; }  
};  
```  
  
## <a name="example"></a>Exemplo  
 LNK2020 também ocorrerá se você cria uma variável de um tipo de modelo gerenciado, mas também, não criar uma instância do tipo.  
  
 O exemplo a seguir gera LNK2020.  
  
```  
// LNK2020_b.cpp  
// compile with: /clr   
  
template <typename T>  
ref struct Base {  
   virtual void f1() {};  
};  
  
template <typename T>  
ref struct Base2 {  
   virtual void f1() {};  
};  
  
int main() {  
   Base<int>^ p;   // LNK2020  
   Base2<int>^ p2 = gcnew Base2<int>();   // OK  
};  
```
