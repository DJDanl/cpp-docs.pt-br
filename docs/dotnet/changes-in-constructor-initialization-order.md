---
title: "Alterações na ordem de inicialização do construtor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: constructors, C++
ms.assetid: 8892c38d-6bf7-4cf7-ac8f-15e052135a79
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: bdcfea2339bfe7aac93192e88a6ec39ce919c596
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="changes-in-constructor-initialization-order"></a>Alterações na ordem de inicialização de construtor
A ordem de inicialização para construtores de classe foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
## <a name="comparison-of-constructor-initialization-order"></a>Comparação de ordem de inicialização de construtor  
 Nas extensões gerenciadas para C++, a inicialização de construtor ocorreu na seguinte ordem:  
  
1.  O construtor da classe base, se houver, é invocado.  
  
2.  A lista de inicialização da classe é avaliada.  
  
3.  O corpo de código do construtor de classe é executado.  
  
 Essa ordem de execução segue as mesmas convenções de programação C++ nativa. A nova linguagem Visual C++ determina a ordem de execução para classes CLR:  
  
1.  A lista de inicialização da classe é avaliada.  
  
2.  O construtor da classe base, se houver, é invocado.  
  
3.  O corpo de código do construtor de classe é executado.  
  
 Observe que essa alteração se aplica apenas às classes CLR; classes nativas no Visual C++ ainda seguem as convenções anteriores. Em ambos os casos, essas regras em cascata para cima em todo o grupo de toda a hierarquia de uma determinada classe.  
  
 Considere o seguinte exemplo de código usando extensões gerenciadas para C++:  
  
```  
__gc class A  
{  
public:  
   A() : _n(1)  
   {  
   }  
  
protected:  
   int _n;  
};  
  
__gc class B : public A  
{  
public:  
   B() : _m(_n)  
   {  
   }  
private:  
   int _m;  
};  
```  
  
 Na ordem de inicialização do construtor indicadas acima, vemos deve seguir a ordem de execução quando novas instâncias da classe `B` são construídos:  
  
1.  O construtor da classe base `A` é invocado. O `_n` membro é inicializado como `1`.  
  
2.  A lista de inicialização para a classe `B` é avaliada. O `_m` membro é inicializado como `1`.  
  
3.  O corpo de código da classe `B` é executado.  
  
 Agora, considere o mesmo código na nova sintaxe Visual C++:  
  
```  
ref class A  
{  
public:  
   A() : _n(1)  
   {  
   }  
  
protected:  
   int _n;  
};  
  
ref class B : A  
{  
public:  
   B() : _m(_n)  
   {  
   }  
private:  
   int _m;  
};  
```  
  
 A ordem de execução quando novas instâncias da classe `B` são construídos sob a nova sintaxe é:  
  
1.  A lista de inicialização para a classe `B` é avaliada. O `_m` membro é inicializado como `0` (`0` é o valor não inicializado o `_m` membro de classe).  
  
2.  O construtor da classe base `A` é invocado. O `_n` membro é inicializado como `1`.  
  
3.  O corpo de código da classe `B` é executado.  
  
 Observe que uma sintaxe similar produz resultados diferentes para esses exemplos de código. O construtor da classe `B` depende de um valor de classe base `A` para inicializar seus membros. No entanto, o construtor de classe `A` ainda não foi invocado. Tal dependência pode ser especialmente perigosa quando a classe herdada depende de alocação de memória ou recursos para ocorrer no construtor da classe base.  
  
## <a name="what-this-means-going-from-managed-extensions-for-c-to-visual-c-2010"></a>O que isso significa indo de extensões gerenciadas para C++ para Visual C++ 2010  
 Em muitos casos as alterações na ordem de execução dos construtores de classe devem ser transparentes para o programador como classes base não têm nenhuma noção do comportamento de classes herdadas. No entanto, como esses exemplos de código ilustram, construtores de classes herdadas podem ser bastante afetados quando suas listas de inicialização dependem dos valores de membros de classe base. Quando você move o código de extensões gerenciadas para C++ para a nova sintaxe, considere mover tais construções para o corpo do construtor de classe, onde a execução é garantida para ocorrer por último.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)   
 [Construtores](../cpp/constructors-cpp.md)   
 