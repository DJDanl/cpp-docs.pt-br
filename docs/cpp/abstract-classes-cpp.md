---
title: Classes (C++) abstratas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- classes [C++], abstract
- base classes [C++], abstract classes [C++]
- abstract classes [C++]
- derived classes [C++], abstract classes [C++]
ms.assetid: f0c5975b-39de-4d68-9640-6ce57f4632e6
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: d8ee7473b77f943c4f9958dabb0baa4998c284f4
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="abstract-classes-c"></a>Classes abstratas (C++)
As classes abstratas agem como expressões de conceitos gerais das quais classes mais específicas podem ser derivadas. Não é possível criar um objeto de um tipo de classe abstrata; no entanto, é possível usar ponteiros e referências para tipos de classes abstratas.  
  
 Uma classe que contenha ao menos uma função virtual pura é considerada uma classe abstrata. Classes derivadas da classe abstrata devem implementar a função virtual pura, ou serão também classes abstratas.  
  
 Uma função virtual é declarada como "pura" usando o *especificador puro* sintaxe (descrito na [implementação de protocolo da classe](http://msdn.microsoft.com/en-us/a319f1b3-05e8-400e-950a-1ca6eb105ab5)). Considere o exemplo apresentado [funções virtuais](../cpp/virtual-functions.md). A intenção da classe `Account` é fornecer a funcionalidade geral, mas os objetos do tipo `Account` são muito gerais para serem úteis. Portanto, `Account` é um bom candidato para uma classe abstrata:  
  
```  
// deriv_AbstractClasses.cpp  
// compile with: /LD  
class Account {  
public:  
   Account( double d );   // Constructor.  
   virtual double GetBalance();   // Obtain balance.  
   virtual void PrintBalance() = 0;   // Pure virtual function.  
private:  
    double _balance;  
};  
  
```  
  
 A única diferença entre essa declaração e a anterior é que `PrintBalance` é declarado com o especificador puro (`= 0`).  
  
## <a name="restrictions-on-abstract-classes"></a>Restrições em classes abstratas  
 As classes abstratas não podem ser usadas para:  
  
-   Variáveis ou dados de membro  
  
-   Tipos de argumento  
  
-   Tipos de retorno de função  
  
-   Tipos de conversões explícitas  
  
 Outra restrição é que se o construtor para uma classe abstrata chamar uma função virtual pura, direta ou indiretamente, o resultado será indefinido. No entanto, os construtores e os destruidores para classes abstratas podem chamar outras funções de membro.  
  
 As funções virtuais puras podem ser definidas para classes abstratas, mas podem ser chamadas diretamente somente usando a sintaxe:  
  
 *nome de classe abstrata* `::` *nome de função***)**  
  
 Isso ajuda a criar hierarquias de classes cujas classes base incluem destruidores virtuais puros, porque os destruidores de classe base sempre são chamados no processo de destruição de um objeto. Considere o exemplo a seguir:  
  
```  
// Declare an abstract base class with a pure virtual destructor.  
// deriv_RestrictionsonUsingAbstractClasses.cpp  
class base {  
public:  
    base() {}  
    virtual ~base()=0;  
};  
  
// Provide a definition for destructor.  
base::~base() {}  
  
class derived:public base {  
public:  
    derived() {}  
    ~derived(){}  
};  
  
int main() {  
    derived *pDerived = new derived;  
    delete pDerived;  
}  
```  
  
 Quando o objeto apontado por `pDerived` é excluído, o destruidor da classe `derived` é chamado e o destruidor da classe `base` é chamado. A implementação vazia para a função virtual pura garante que pelo menos uma implementação exista para a função.  
  
> [!NOTE]
>  No exemplo anterior, a função virtual pura `base::~base` é chamada implicitamente de `derived::~derived`. Também é possível chamar funções virtuais puras explicitamente usando um nome de função de membro totalmente qualificado.  
  
## <a name="see-also"></a>Consulte também  
 [Herança](../cpp/inheritance-cpp.md)
