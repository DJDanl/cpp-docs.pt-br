---
title: "delegado (extens&#245;es de componentes C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "delegate_cpp"
  - "delegate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave delegate [C++]"
ms.assetid: 03caf23d-7873-4a23-9b34-becf42aaf429
caps.latest.revision: 26
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# delegado (extens&#245;es de componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara um tipo que representa um ponteiro de função.  
  
## Todos os Tempos de Execução  
 O [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e o common language runtime dão suporte a delegados.  
  
### Comentários  
 `delegate` é uma palavra\-chave contextual.  Para obter mais informações, consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
 Para detectar um tempo de compilação se um tipo for um delegado, use a característica do tipo `__is_delegate()`.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
## Tempo de execução do windows  
 C\+\+\/CX dá suporte a delegados com a sintaxe a seguir.  
  
### Sintaxe  
  
```cpp  
  
access delegate return-type delegate-type-identifier ([ parameters ])  
```  
  
### Parâmetros  
 *access*  
 \(opcional\) A acessibilidade do delegado, que pode ser `public` \(o padrão\) ou `private`.  O protótipo de função também pode ser qualificada com as palavras\-chave `const` ou de `volatile`.  
  
 *return\-type*  
 O tipo de retorno de protótipo de função.  
  
 *delegate\-type\-identifier*  
 O nome do tipo delegado declarado.  
  
 *parameters*  
 \(Opcional\) Os tipos e identificadores do protótipo de função.  
  
### Comentários  
 Use *delegate\-type\-identifier* para declarar um evento com o mesmo protótipo que o representante.  Para obter mais informações, consulte [Delegates \(C\+\+\/CX\)](../Topic/Delegates%20\(C++-CX\).md).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 O common language runtime dá suporte a delegados com a sintaxe a seguir.  
  
### Sintaxe  
  
```cpp  
  
access delegate function_declaration  
```  
  
### Parâmetros  
 *access*  
 \(opcional\) A acessibilidade de delegado fora do assembly pode ser pública ou particular.  O padrão é privado.  Dentro de uma classe, um delegado pode ter qualquer acessibilidade.  
  
 *function\_declaration*  
 A assinatura de função que pode ser associada ao delegado.  O tipo de retorno de um delegado pode ser qualquer tipo gerenciado.  Por motivos de interoperabilidade, é recomendável que o tipo de retorno de um delegado seja um tipo CLS.  
  
 Para definir um representante não associadas, o primeiro parâmetro em *function\_declaration* deve ser o tipo de ponteiro de `this` para o objeto.  Para obter mais informações, consulte [Delegados não associados](../Topic/Unbound%20Delegates.md).  
  
### Comentários  
 Delegados são multicast: o "ponteiro de função" pode ser associado a um ou mais métodos em uma classe gerenciada.  A palavra\-chave **delegate** define um tipo de destino multicast com uma assinatura específica do método.  
  
 Um delegado também pode ser associado a um método de uma classe de valor, como um método estático.  
  
 Um delegado tem as seguintes características:  
  
-   Herda de **System::MulticastDelegate**.  
  
-   Tem um construtor que utiliza dois argumentos: um ponteiro para uma classe gerenciada ou a **NULO** \(no caso de associação a um método estático\) e um método totalmente qualificado do tipo especificado.  
  
-   Tem um método chamado `Invoke`, cuja assinatura corresponde à assinatura do delegado declarado.  
  
 Quando um delegado é chamado, suas funções são chamadas na ordem em que foram anexadas.  
  
 O valor de retorno de um delegado é o valor de retorno da função do membro anexado por último.  
  
 Delegados não podem ser sobrecarregados.  
  
 Delegados podem ser associados ou não associados.  
  
 Quando você cria uma instância de um delegado associado, o primeiro argumento será uma referência de objeto.  O segundo argumento de uma instanciação de delegado deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor.   O segundo argumento de uma instanciação de delegado deve nomear o método com a sintaxe de escopo de classe completa e aplicar o operador address\-of.  
  
 Quando você cria uma instância de um delegado não associado, o primeiro argumento será o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor.   O argumento deve nomear o método com a sintaxe de escopo de classe completa e aplicar o operador address\-of.  
  
 Ao criar um delegado para uma função estática ou global, somente um parâmetro é necessário: a função \(opcionalmente, o endereço da função\).  
  
 Para obter mais informações sobre delegados, consulte  
  
-   [Delegados não associados](../Topic/Unbound%20Delegates.md)  
  
-   [Como definir e usar delegados](../Topic/How%20to:%20Define%20and%20Use%20Delegates%20\(C++-CLI\).md)  
  
-   [Delegar a um membro de uma classe de valor](../misc/how-to-associate-delegates-to-members-of-a-value-class.md)  
  
-   [Delegar a uma função não gerenciada](../misc/how-to-associate-delegates-to-unmanaged-functions.md)  
  
-   [Delegados compostos](../misc/how-to-compose-delegates.md)  
  
-   [Como transmitir um delegado^ para uma função nativa aguardando um ponteiro de função](../misc/how-to-pass-a-delegate-hat-to-a-native-function-expecting-a-function-pointer.md)  
  
-   [Generic Delegates \(Visual C\+\+\)](../Topic/Generic%20Delegates%20\(Visual%20C++\).md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo a seguir mostra como declarar, inicializar e invocar delegados.  
  
```cpp  
// mcppv2_delegate.cpp  
// compile with: /clr  
using namespace System;  
  
// declare a delegate  
public delegate void MyDel(int i);  
  
ref class A {  
public:  
   void func1(int i) {  
      Console::WriteLine("in func1 {0}", i);  
   }  
  
   void func2(int i) {  
      Console::WriteLine("in func2 {0}", i);  
   }  
  
   static void func3(int i) {  
      Console::WriteLine("in static func3 {0}", i);  
   }  
};  
  
int main () {  
   A ^ a = gcnew A;  
  
   // declare a delegate instance  
   MyDel^ DelInst;  
  
   // test if delegate is initialized  
   if (DelInst)  
      DelInst(7);  
  
   // assigning to delegate  
   DelInst = gcnew MyDel(a, &A::func1);  
  
   // invoke delegate  
   if (DelInst)  
      DelInst(8);  
  
   // add a function  
   DelInst += gcnew MyDel(a, &A::func2);  
  
   DelInst(9);  
  
   // remove a function  
   DelInst -= gcnew MyDel(a, &A::func1);  
  
   // invoke delegate with Invoke  
   DelInst->Invoke(10);  
  
   // make delegate to static function  
   MyDel ^ StaticDelInst = gcnew MyDel(&A::func3);  
   StaticDelInst(11);  
}  
```  
  
 **Saída**  
  
  **in func1 8**  
 **in func1 9**  
 **in func2 9**  
 **in func2 10**  
 **in static func3 11**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)