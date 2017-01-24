---
title: "Declara&#231;&#227;o de um tipo de classe gerenciado | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Tipos __gc"
  - "Palavra-chave __value"
  - "Palavra-chave class [C++], CLR"
  - "classes [C++], gerenciadas"
  - "palavra-chave interface class"
  - "classes gerenciadas"
  - "Palavra-chave ref [C++]"
  - "Palavra-chave value [C++]"
  - "tipos de valor, declarando"
ms.assetid: 16de9c94-91d7-492f-8ac7-f0729cc627e9
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o de um tipo de classe gerenciado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O modo de declarar um tipo de classe de referência foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Em extensões gerenciadas, um tipo de classe de referência é prefaciado com a palavra\-chave de `__gc` .  Na nova sintaxe, a palavra\-chave de `__gc` é substituído por um de dois palavra\-chave espaçados: `ref class` ou `ref struct`.  A escolha de `struct` ou de `class` indica o utilitário \(para `struct`\) ou \(para\) `class`o nível de acesso privado padrão de seus membros declarados em uma seção sem rótulo inicial do corpo do tipo.  
  
 Da mesma forma, em extensões gerenciadas, um tipo de classe do valor é prefaciado com a palavra\-chave de `__value` .  Na nova sintaxe, a palavra\-chave de `__value` é substituído por um de dois palavra\-chave espaçados: `value class` ou `value struct`.  
  
 Um tipo de interface, em extensões gerenciadas, foi declarado com a palavra\-chave `__interface`.  Na nova sintaxe, isso é substituído por `interface class`.  
  
 Por exemplo, as seguintes instruções da classe em extensões gerenciadas:  
  
```  
public __gc class Block {};     // reference class  
public __value class Vector {}; // value class  
public __interface IFooBar {};  // interface class  
```  
  
 Na nova sintaxe eles são declarados equivalente a seguinte maneira:  
  
```  
public ref class Block {};         // reference class  
public value class Vector {};      // value class  
public interface class IFooBar {}; // interface class  
```  
  
## Especificando a classe como o sumário  
 Em extensões gerenciadas, você coloca a palavra\-chave `__abstract` antes da palavra\-chave de `class` \(ou um antes ou depois de `__gc`\) para indicar que a classe está incompleta e que os objetos da classe não podem ser criados no programa:  
  
```  
public __gc __abstract class Shape {};  
public __gc __abstract class Shape2D: public Shape {};  
```  
  
 Na nova sintaxe, você especifica a palavra\-chave de contexto de `abstract` depois do nome da classe e antes que o corpo da classe, a lista de derivação da classe base, ou o ponto\-e\-vírgula.  
  
```  
public ref class Shape abstract {};  
public ref class Shape2D abstract : public Shape{};  
```  
  
 Naturalmente, o significado semântico está inalterado.  
  
## Especificando a classe como selada  
 Em extensões gerenciadas, você coloca a palavra\-chave `__sealed` antes da palavra\-chave de `class` \(um ou outro antes ou depois de `__gc`\) para indicar que os objetos da classe não podem ser herdados do:  
  
```  
public __gc __sealed class String {};  
```  
  
 Na nova sintaxe, você especifica a palavra\-chave de contexto de `sealed` depois do nome da classe e antes que o corpo da classe, a lista de derivação da classe base, ou o ponto\-e\-vírgula.  
  
 Você pode derivar uma classe e selá\-la.  Por exemplo, a classe de `String` é derivada de `Object`implicitamente.  O benefício de selar uma classe é que oferece suporte à resolução estático \(ou seja, em tempo de compilação\) de todas as chamadas de função virtuais pelo objeto selado da classe de referência.  Isso ocorre porque o especificador de `sealed` garante que `String` que acompanha o identificador não pode se referir a subsequentemente uma classe derivada que pode fornecer uma instância substituindo do método virtual que está sendo invocado.  Eis um exemplo de uma classe selada na nova sintaxe:  
  
```  
public ref class String sealed {};  
```  
  
 Se também pode especificar uma classe porque sumário e selado – esta é uma condição especial que indica uma classe estática.  Isso é descrito na documentação de CLR como segue:  
  
 “Um tipo que é `abstract` e `sealed` deve ter apenas membros estáticos, e serve como o que alguns idiomas chamam um namespace.”  
  
 Por exemplo, aqui é uma declaração de uma classe selada sumário que usa a sintaxe gerenciado de extensões:  
  
```  
public __gc __sealed __abstract class State {  
public:  
   static State() {}  
   static bool inParamList();  
  
private:  
   static bool ms_inParam;  
};  
```  
  
 e segue esta declaração convertida na nova sintaxe:  
  
```  
public ref class State abstract sealed {  
public:  
   static State();  
   static bool inParamList();  
  
private:  
   static bool ms_inParam;  
};  
```  
  
## Herança de CLR: Especificando a classe base  
 No modelo de objeto CLR, somente a única herança pública tem suporte.  No entanto, as extensões gerenciadas reteram a interpretação da opção de ISO\-C\+\+ de uma classe base sem uma palavra\-chave de acesso como especificar uma derivação particular.  Isso significou que cada declaração de herança de CLR que tinha fornecer a palavra\-chave de `public` para substituir a interpretação padrão.  
  
```  
// Managed Extensions: error: defaults to private derivation  
__gc class Derived : Base {};  
```  
  
 Na nova definição de sintaxe, a ausência de uma palavra\-chave de acesso indica uma derivação pública em uma definição de herança de CLR.  Assim, a palavra\-chave de acesso de `public` agora é opcional.  Quando isso não exige nenhuma alteração de extensões gerenciadas para o código C\+\+, eu listo essa alteração aqui para manter a integridade.  
  
```  
// New syntax: ok: defaults to public derivation  
ref class Derived : Base{};  
```  
  
## Consulte também  
 [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md)   
 [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [abstract](../windows/abstract-cpp-component-extensions.md)   
 [sealed](../windows/sealed-cpp-component-extensions.md)