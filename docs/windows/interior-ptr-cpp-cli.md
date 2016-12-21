---
title: "interior_ptr (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "stdcli::language::interior_ptr"
  - "interior_ptr_cpp"
  - "interior_ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interior_ptr keyword [C++]"
ms.assetid: 25160f74-569e-492d-9e3c-67ece7486baa
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# interior_ptr (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*Um ponteiro interior* declara um ponteiro dentro de um tipo de referência, mas não no próprio objeto.  Um ponteiro interior pode apontar para um identificador de referência, tipo de valor, encaixotada identificador do tipo, membro de um tipo gerenciado, ou um elemento de uma matriz gerenciado.  
  
## Todos os Tempos de Execução  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica a todos os tempos de execução\).  
  
## Tempo de execução do windows  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente Tempo de Execução do Windows\).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 A sintaxe a seguir demonstra um ponteiro interior.  
  
### Sintaxe  
  
```cpp  
cli::interior_ptr<cv_qualifier type> var = &initializer;  
```  
  
### Parâmetros  
 *cv\_qualifier*  
 **const** ou qualificadores de `volatile` .  
  
 *type*  
 O tipo de *initializer*.  
  
 *var*  
 O nome da variável de `interior_ptr` .  
  
 *initializer*  
 Um membro de um tipo de referência, do elemento de uma matriz gerenciado, ou qualquer outro objeto que você pode atribuir a um ponteiro nativo.  
  
### Comentários  
 Um ponteiro nativo não pode rastrear um item como seu local for alterado no heap gerenciado, que é o resultado das instâncias movendo do coletor de lixo de um objeto.  Para que um ponteiro consulte corretamente a instância, o tempo de execução precisa atualizar o ponteiro para o objeto recentemente posicionado.  
  
 `interior_ptr` representa um superconjunto da funcionalidade de um ponteiro nativo.  Em virtude disso, qualquer coisa que pode ser atribuído a um ponteiro nativo também pode ser atribuído a `interior_ptr`.  Um ponteiro interior tem permissão para executar o mesmo conjunto de operações que ponteiros nativos, incluindo a comparação e aritmética do ponteiro.  
  
 Um ponteiro interior só pode ser declarado na pilha.  Um ponteiro interior não pode ser declarado como um membro de uma classe.  
  
 Como os ponteiros interiores só existem na pilha, fazer o endereço de um ponteiro interior gerencie um ponteiro não gerenciado.  
  
 `interior_ptr` tem uma conversão implícita em `bool`, que permite seu uso em instruções condicionais.  
  
 Para obter informações sobre como declarar um ponteiro interior que aponta para um objeto que não pode ser movido para o heap com coletado, consulte [pin\_ptr](../Topic/pin_ptr%20\(C++-CLI\).md).  
  
 `interior_ptr` está no namespace cli.  Consulte [Platform, default, and cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) para maiores informações.  
  
 Para obter mais informações sobre os ponteiros interiores, consulte  
  
-   [How to: Declare and Use Interior Pointers and Managed Arrays \(C\+\+\/CLI\)](../windows/how-to-declare-and-use-interior-pointers-and-managed-arrays-cpp-cli.md)  
  
-   [How to: Declare Value Types with the interior\_ptr Keyword \(C\+\+\/CLI\)](../windows/how-to-declare-value-types-with-the-interior-ptr-keyword-cpp-cli.md)  
  
-   [How to: Overload Functions with Interior Pointers and Native Pointers \(C\+\+\/CLI\)](../windows/how-to-overload-functions-with-interior-pointers-and-native-pointers-cpp-cli.md)  
  
-   [How to: Declare Interior Pointers with the const Keyword \(C\+\+\/CLI\)](../windows/how-to-declare-interior-pointers-with-the-const-keyword-cpp-cli.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo a seguir mostra como declarar e usar um ponteiro dentro de um tipo de referência.  
  
```cpp  
// interior_ptr.cpp  
// compile with: /clr  
using namespace System;  
  
ref class MyClass {  
public:  
   int data;  
};  
  
int main() {  
   MyClass ^ h_MyClass = gcnew MyClass;  
   h_MyClass->data = 1;  
   Console::WriteLine(h_MyClass->data);  
  
   interior_ptr<int> p = &(h_MyClass->data);  
   *p = 2;  
   Console::WriteLine(h_MyClass->data);  
  
   // alternatively  
   interior_ptr<MyClass ^> p2 = &h_MyClass;  
   (*p2)->data = 3;  
   Console::WriteLine((*p2)->data);  
}  
```  
  
 **Saída**  
  
 **1**   
**2**   
**3**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)