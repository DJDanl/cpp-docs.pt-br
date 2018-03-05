---
title: "Declaração de um tipo de classe gerenciada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- __gc types
- classes [C++], managed
- class keyword [C++], CLR
- __value keyword
- value types, declaring
- value keyword [C++]
- managed classes
- interface class keyword
- ref keyword [C++]
ms.assetid: 16de9c94-91d7-492f-8ac7-f0729cc627e9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c9e9aba6d2a0485a94385be5b8712d7552261ff1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="declaration-of-a-managed-class-type"></a>Declaração de um tipo de classe gerenciado
A maneira de declarar um tipo de classe de referência alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Em extensões gerenciadas, um tipo de classe de referência exibirá o `__gc` palavra-chave. Na nova sintaxe, o `__gc` palavra-chave é substituída por uma das duas palavras-chave espaçadas: `ref class` ou `ref struct`. A escolha de `struct` ou `class` indica público (para `struct`) ou privada (para `class`) o nível de acesso padrão de seus membros declarados em uma seção sem nome inicial do corpo do tipo.  
  
 Da mesma forma, das extensões gerenciadas, um tipo de classe de valor é precedido com o `__value` palavra-chave. Na nova sintaxe, o `__value` palavra-chave é substituída por uma das duas palavras-chave espaçadas: `value class` ou `value struct`.  
  
 Um tipo de interface, das extensões gerenciadas, foi indicado com a palavra-chave `__interface`. A nova sintaxe, ele é substituído por `interface class`.  
  
 Por exemplo, as seguintes declarações de classe em extensões gerenciadas:  
  
```  
public __gc class Block {};     // reference class  
public __value class Vector {}; // value class  
public __interface IFooBar {};  // interface class  
```  
  
 Sob a nova sintaxe esses são ainda declarados como se segue:  
  
```  
public ref class Block {};         // reference class  
public value class Vector {};      // value class  
public interface class IFooBar {}; // interface class  
```  
  
## <a name="specifying-the-class-as-abstract"></a>Especificar a classe como abstrato  
 Em extensões gerenciados, você colocar a palavra-chave `__abstract` antes do `class` palavra-chave (antes ou depois de `__gc`) para indicar que a classe está incompleta e que não podem ser criados objetos da classe dentro do programa:  
  
```  
public __gc __abstract class Shape {};  
public __gc __abstract class Shape2D: public Shape {};  
```  
  
 Sob a nova sintaxe, você deve especificar o `abstract` palavra-chave contextual a seguir a classe de nome e antes do corpo da classe, lista de derivação de classe base ou ponto e vírgula.  
  
```  
public ref class Shape abstract {};  
public ref class Shape2D abstract : public Shape{};  
```  
  
 Naturalmente, o significado semântico é alterado.  
  
## <a name="specifying-the-class-as-sealed"></a>Especificar a classe como lacrado  
 Em extensões gerenciados, você colocar a palavra-chave `__sealed` antes do `class` palavra-chave (antes ou depois `__gc`) para indicar que os objetos da classe não podem ser herdados de:  
  
```  
public __gc __sealed class String {};  
```  
  
 Sob a nova sintaxe, você deve especificar o `sealed` palavra-chave contextual a seguir a classe de nome e antes do corpo da classe, lista de derivação de classe base ou ponto e vírgula.  
  
 Você pode derivar uma classe e lacre. Por exemplo, o `String` classe implicitamente é derivada de `Object`. O benefício de fechamento de uma classe é que ele oferece suporte a resolução estática (ou seja, em tempo de compilação) de todas as chamadas de função virtual por meio do objeto de classe de referência lacrado. Isso ocorre porque o `sealed` especificador garante que o `String` manipulador de acompanhamento não pode se referir a uma classe derivada, posteriormente, que pode fornecer uma instância de substituição do método virtual que está sendo invocado. Aqui está um exemplo de uma classe sealed na nova sintaxe:  
  
```  
public ref class String sealed {};  
```  
  
 Um também pode especificar uma classe como ambos abstract e sealed - esta é uma condição de especial que indica uma classe estática. Isso é descrito na documentação do CLR da seguinte maneira:  
  
 "Um tipo que é ambos `abstract` e `sealed` devem ter somente membros estáticos e serve como o que algumas linguagens de chamar um namespace."  
  
 Por exemplo, aqui está uma declaração de uma classe sealed abstract usando a sintaxe das extensões gerenciadas:  
  
```  
public __gc __sealed __abstract class State {  
public:  
   static State() {}  
   static bool inParamList();  
  
private:  
   static bool ms_inParam;  
};  
```  
  
 e aqui está essa declaração traduzida para a nova sintaxe:  
  
```  
public ref class State abstract sealed {  
public:  
   static State();  
   static bool inParamList();  
  
private:  
   static bool ms_inParam;  
};  
```  
  
## <a name="clr-inheritance-specifying-the-base-class"></a>Herança de CLR: Especifica a classe Base  
 No modelo de objeto CLR, há suporte apenas herança única pública. No entanto, das extensões gerenciadas mantidos a interpretação padrão de ISO C++ de uma classe base sem uma palavra-chave de acesso que especificar uma derivação privada. Isso significava que cada declaração de herança do CLR tinha que fornecer o `public` palavra-chave para substituir a interpretação padrão.  
  
```  
// Managed Extensions: error: defaults to private derivation  
__gc class Derived : Base {};  
```  
  
 Na nova definição de sintaxe, ausência de uma palavra-chave de acesso indica uma derivação pública em uma definição de herança do CLR. Portanto, o `public` palavra-chave de acesso agora é opcional. Embora isso não requer nenhuma modificação das extensões gerenciadas para o código C++, eu lista essa alteração para fins de integridade.  
  
```  
// New syntax: ok: defaults to public derivation  
ref class Derived : Base{};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)   
 [Classes e structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [abstract](../windows/abstract-cpp-component-extensions.md)   
 [sealed](../windows/sealed-cpp-component-extensions.md)