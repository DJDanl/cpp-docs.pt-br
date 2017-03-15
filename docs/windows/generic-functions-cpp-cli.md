---
title: "Generic Functions (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "functions [C++], generic"
  - "generic methods"
  - "generics [C++], functions"
  - "methods [C++], generic"
  - "generic functions"
ms.assetid: 8e409364-58f9-4360-b486-e7d555e0c218
caps.latest.revision: 21
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Generic Functions (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma função genérico é uma função que é declarada com parâmetros de tipo.  Quando chamado, os tipos reais são usados em vez dos parâmetros de tipo.  
  
## Todas as Plataformas  
 **Comentários**  
  
 Esse recurso não se aplica a todas as plataformas.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 Esse recurso não tem suporte em [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 Uma função genérico é uma função que é declarada com parâmetros de tipo.  Quando chamado, os tipos reais são usados em vez dos parâmetros de tipo.  
  
 **Sintaxe**  
  
```  
[attributes] [modifiers]  
return-type identifier <type-parameter identifier(s)>  
[type-parameter-constraints clauses]  
  
([formal-parameters])  
{  
   function-body  
}  
```  
  
 **Parâmetros**  
  
 *attributes* \(opcional\)  
 Declarativa informações adicional.  Para obter mais informações sobre os atributos e das classes de atributo, consulte atributos.  
  
 *modifiers* \(opcional\)  
 Um modificador para a função, como static.  `virtual` não é permitido desde que os métodos virtuais não podem ser genéricas.  
  
 *return\-type*  
 O tipo retornado pelo método.  Se o tipo de retorno será nulo, nenhum valor de retorno será necessário.  
  
 *identifier*  
 O nome da função.  
  
 *type\-parameter identifier\(s\)*  
 Lista separada por vírgula de identificadores.  
  
 *formal\-parameters* \(opcional\)  
 Lista de parâmetros.  
  
 *type\-parameter\-constraints\-clauses*  
 Isso especifica restrições em tipos que podem ser usados como argumentos de tipo, e usa o formato especificado em [Constraints on Generic Type Parameters \(C\+\+\/CLI\)](../Topic/Constraints%20on%20Generic%20Type%20Parameters%20\(C++-CLI\).md).  
  
 *function\-body*  
 O corpo do método, que pode fazer referência aos identificadores de parâmetro de tipo.  
  
 **Comentários**  
  
 As funções genéricas funções são declaradas com um parâmetro de tipo genérico.  Podem ser métodos em uma classe ou em uma estrutura, ou funções autônomas.  Uma única declaração genérico declara implicitamente uma família de funções que diferem apenas na substituição de um tipo real diferente para o parâmetro de tipo genérico.  
  
 Em [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], a classe ou os construtores da estrutura não podem ser declaradas com parâmetros de tipo genéricas.  
  
 Quando chamado, o parâmetro de tipo genérico é substituído por um tipo real.  O tipo real pode ser explicitamente especificado entre colchetes angulares usando a sintaxe semelhante a uma chamada de função do modelo.  Se for chamado sem os parâmetros de tipo, o compilador tentará deduzir o tipo real dos parâmetros fornecidos na chamada de função.  Se o argumento desejado do tipo não for possível deduzir os parâmetros usados, o compilador relatará um erro.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra uma função genérico.  
  
```  
// generics_generic_function_1.cpp  
// compile with: /clr  
generic <typename ItemType>  
void G(int i) {}  
  
ref struct A {  
   generic <typename ItemType>  
   void G(ItemType) {}  
  
   generic <typename ItemType>  
   static void H(int i) {}  
};  
  
int main() {  
   A myObject;  
  
   // generic function call  
   myObject.G<int>(10);  
  
   // generic function call with type parameters deduced  
   myObject.G(10);  
  
   // static generic function call  
   A::H<int>(10);  
  
   // global generic function call  
   G<int>(10);  
}  
```  
  
 **Exemplo**  
  
 As funções genéricas podem ser sobrecarregadas com base na assinatura ou no arity, o número de parâmetros de tipo em uma função.  Além disso, as funções genéricas podem ser sobrecarregadas com as funções não genéricas de mesmo nome, como as funções difere em alguns parâmetros de tipo.  Por exemplo, as seguintes funções podem ser sobrecarregadas:  
  
```  
// generics_generic_function_2.cpp  
// compile with: /clr /c  
ref struct MyClass {  
   void MyMythod(int i) {}  
  
   generic <class T>   
   void MyMythod(int i) {}  
  
   generic <class T, class V>   
   void MyMythod(int i) {}  
};  
```  
  
 **Exemplo**  
  
 O exemplo a seguir usa uma função genérica para localizar o primeiro elemento em uma matriz.  Declara `MyClass`, que herda da classe base `MyBaseClass`.  `MyClass` contém uma função genérico, `MyFunction`, que chama outra função genérico, `MyBaseClassFunction`, na classe base.  Em **main**, a função genérico, `MyFunction`, é chamada usando argumentos diferentes do tipo.  
  
```  
// generics_generic_function_3.cpp  
// compile with: /clr  
using namespace System;  
  
ref class MyBaseClass {  
protected:  
   generic <class ItemType>  
   ItemType MyBaseClassFunction(ItemType item) {  
      return item;  
   }  
};  
  
ref class MyClass: public MyBaseClass {  
public:  
   generic <class ItemType>  
   ItemType MyFunction(ItemType item) {  
      return MyBaseClass::MyBaseClassFunction<ItemType>(item);  
   }  
};  
  
int main() {  
   MyClass^ myObj = gcnew MyClass();  
  
   // Call MyFunction using an int.  
   Console::WriteLine("My function returned an int: {0}",  
                           myObj->MyFunction<int>(2003));  
  
   // Call MyFunction using a string.  
   Console::WriteLine("My function returned a string: {0}",  
   myObj->MyFunction<String^>("Hello generic functions!"));  
}  
```  
  
 **Saída**  
  
  **Minha função retornou um int: 2003**  
 **Minha função retornou uma cadeia de caracteres: Hello world funções genéricas\!**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)   
 [Generics](../windows/generics-cpp-component-extensions.md)