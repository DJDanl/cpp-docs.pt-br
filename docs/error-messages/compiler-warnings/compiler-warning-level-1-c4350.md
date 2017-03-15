---
title: "Compilador aviso (nível 1) C4350 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4350
dev_langs:
- C++
helpviewer_keywords:
- C4350
ms.assetid: 4cc8ed67-64c4-4da5-a7a5-a639232baa23
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c3a5411475d898562b8cba62ddeffcaf1dfec095
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4350"></a>Compilador C4350 de aviso (nível 1)
alteração de comportamento: 'member1' chamado no lugar de 'member2'  
  
 Um rvalue não pode ser associado a uma referência não const. Nas versões anteriores do Visual C++, era possível ligar um rvalue para uma referência não const em uma inicialização direta. Esse código agora fornece um aviso.  
  
 Para compatibilidade com versões anteriores, ainda é possível vincular rvalues referências não const, mas conversões padrão são preferenciais sempre que possível.  
  
 Esse aviso representa uma alteração de comportamento do compilador do Visual C++ .NET 2002. Se habilitada, este aviso possivelmente foi fornecido para o código correto. Por exemplo, ele poderia receber ao usar o **std::auto_ptr** modelo de classe.  
  
 Se você receber esse aviso, examine seu código para ver se ele depende da associação rvalues referências não const. Adicionando uma constante para a referência ou fornecer uma sobrecarga adicional de referência const pode resolver o problema.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).  
  
 O exemplo a seguir gera C4350:  
  
```  
// C4350.cpp  
// compile with: /W1  
#pragma warning (default : 4350)  
class A {};  
  
class B  
{  
public:  
   B(B&){}  
   // try the following instead  
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
