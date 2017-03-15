---
title: "for each, in | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::foreach"
  - "for"
  - "each"
  - "in"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave foreach [C++]"
ms.assetid: 0c3a364b-2747-43f3-bb8d-b7d3b7023f79
caps.latest.revision: 24
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# for each, in
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Itera por meio de uma matriz ou coleção.  Essa palavra\-chave não padrão está disponível em projetos em C\+\+\/CLI e nativos em C\+\+.  No entanto, seu uso não é recomendado.  Considere usar [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md) padrão.  
  
## Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
        for each (type identifier in expression) {  
   statements  
}  
  
```  
  
 **Parâmetros**  
  
 `type`  
 O tipo de `identifier`.  
  
 `identifier`  
 A variável de iteração que representa o elemento da coleção.  Quando `identifier` é um [Tracking Reference Operator](../windows/tracking-reference-operator-cpp-component-extensions.md), você pode modificar o elemento.  
  
 `expression`  
 Uma expressão ou coleção de matriz.  O elemento de coleção deve permitir que o compilador converta\-o no tipo `identifier`.  
  
 `statements`  
 Uma ou mais instruções a serem executadas.  
  
 **Comentários**  
  
 A instrução `for each` é usada para iterar por meio de uma coleção.  Você pode alterar os elementos em uma coleção, mas não pode adicionar ou excluir elementos.  
  
 Os *statements* são executados para cada elemento na matriz ou na coleção.  Após a iteração ter sido concluída para todos os elementos na coleção, o controle é transferido para a próxima instrução que segue o bloco `for each`.  
  
 `for each` e `in` são [palavras\-chave sensíveis ao contexto](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
 Para obter mais informações:  
  
-   [Iterando na coleção STL usando for each](../dotnet/iterating-over-stl-collection-by-using-for-each.md)  
  
-   [Como iterar em matrizes com for each](../dotnet/how-to-iterate-over-arrays-with-for-each.md)  
  
-   [Como iterar em uma coleção genérica com for each](../dotnet/how-to-iterate-over-a-generic-collection-with-for-each.md)  
  
-   [Como iterar em uma coleção definida pelo usuário com for each](../Topic/How%20to:%20Iterate%20Over%20a%20User-Defined%20Collection%20with%20for%20each.md)  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
### Exemplo  
 Este exemplo mostra como usar `for each` para iterar por meio de uma cadeia de caracteres.  
  
```  
// for_each_string1.cpp  
// compile with: /ZW  
#include <stdio.h>  
using namespace Platform;  
  
ref struct MyClass {  
   property String^ MyStringProperty;  
};  
  
int main() {  
   String^ MyString = ref new String("abcd");  
  
   for each ( char c in MyString )  
      wprintf("%c", c);  
  
   wprintf("/n");  
  
   MyClass^ x = ref new MyClass();  
   x->MyStringProperty = "Testing";  
  
   for each( char c in x->MyStringProperty )  
      wprintf("%c", c);  
}  
```  
  
 **Saída**  
  
  **abcd**  
 **Testes**   
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 A sintaxe CLR é a mesma sintaxe de **Todos os Tempos de Execução**, exceto pelo seguinte:  
  
 *expression*  
 Uma expressão de matriz gerenciada ou coleção.  O elemento de coleção deve permitir que o compilador converta\-o de <xref:System.Object> para o tipo *identifier*.  
  
 *expression* é avaliado como um tipo que implementa <xref:System.Collections.IEnumerable>, <xref:System.Collections.Generic.IEnumerable%601> ou um tipo que define um método `GetEnumerator` que retorna um tipo que implementa <xref:System.Collections.IEnumerator> ou declara todos os métodos definidos em `IEnumerator`.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplo  
 Este exemplo mostra como usar `for each` para iterar por meio de uma cadeia de caracteres.  
  
```  
// for_each_string2.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct MyClass {  
   property String ^ MyStringProperty;  
};  
  
int main() {  
   String ^ MyString = gcnew String("abcd");  
  
   for each ( Char c in MyString )  
      Console::Write(c);  
  
   Console::WriteLine();  
  
   MyClass ^ x = gcnew MyClass();  
   x->MyStringProperty = "Testing";  
  
   for each( Char c in x->MyStringProperty )  
      Console::Write(c);  
}  
```  
  
 **Saída**  
  
  **abcd**  
 **Testes**    
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)