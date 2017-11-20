---
title: "Compilador (nível 1) de aviso C4350 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4350
dev_langs: C++
helpviewer_keywords: C4350
ms.assetid: 4cc8ed67-64c4-4da5-a7a5-a639232baa23
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5484c1cb82230eb2bb26004af8a81dcdde1177e0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4350"></a>Compilador C4350 de aviso (nível 1)
alteração de comportamento: 'member1' chamado no lugar de 'member2'  
  
 Um rvalue não pode ser associado a uma referência não const. Nas versões do Visual C++ antes do Visual Studio 2003, era possível associar um rvalue a uma referência não const em uma inicialização direta. Esse código agora fornece um aviso.  
  
 Para compatibilidade com versões anteriores, ainda é possível associar rvalues a não const referências, mas conversões padrão são preferencial sempre que possível.  
  
 Esse aviso representa uma alteração de comportamento do compilador do Visual C++ .NET 2002. Se habilitado, este aviso possivelmente pode ser fornecido para código correto. Por exemplo, ele pode receber ao usar o **std::auto_ptr** modelo de classe.  
  
 Se você receber esse aviso, examine seu código para ver se ele depende rvalues de associação não-const referências. Adicionando uma constante para a referência ou fornecendo uma sobrecarga adicional de referência const pode resolver o problema.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).  
  
 O exemplo a seguir gera C4350:  
  
```cpp  
// C4350.cpp  
// compile with: /W1  
#pragma warning (default : 4350)  
class A {};  
  
class B  
{  
public:  
   B(B&){}  
   // try the following instead:  
   // B(const B&){}  
  
   B(A){}  
   operator A(){ return A();}  
};  
  
B source() { return A(); }  
  
int main()  
{  
   B ap(source());   // C4350  
}  
```