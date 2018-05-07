---
title: Ferramentas de vinculador LNK2020 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2020
dev_langs:
- C++
helpviewer_keywords:
- LNK2020
ms.assetid: 4dd017d0-5e83-471b-ac8a-538ac1ed6870
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33dd1b381d36a90f2e9b144e690e364ac512c081
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk2020"></a>Erro das Ferramentas de Vinculador LNK2020
token indefinido 'token'  
  
 Semelhante a um erro externo indefinido, exceto que a referência é por meio de metadados. Nos metadados, todas as funções e os dados devem ser definidos.  
  
 Para resolver:  
  
-   Definir a função ausente ou a dados, ou  
  
-   Inclua o arquivo de objeto ou a biblioteca na qual a função ou a dados ausentes já estão definidos.  
  
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