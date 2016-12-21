---
title: "Declara&#231;&#227;o de uma matriz CLR | Microsoft Docs"
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
  - "palavra-chave array [C++]"
ms.assetid: 36a8883c-2663-43f0-a90c-28f27035e036
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o de uma matriz CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para declarar, criar uma instância do, e inicializar uma matriz gerenciada foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 A declaração de um objeto da matriz de CLR em extensões gerenciadas era uma extensão de declaração de matriz padrão em que uma palavra\-chave de `__gc` foi colocado entre o nome do objeto da matriz e sua dimensão possivelmente vírgula\- preenchida, como as dos pares de exemplos:  
  
```  
void PrintValues( Object* myArr __gc[]);  
void PrintValues( int myArr __gc[,,]);  
```  
  
 Isso foi simplificado na nova sintaxe em que, usamos a modelos como a instrução semelhante à declaração de STL `vector` .  O primeiro parâmetro indica o tipo de elemento.  O segundo parâmetro especifica a dimensão da matriz \(com um valor padrão de 1, de forma que apenas as várias dimensões exigem um segundo argumento\).  O próprio objeto da matriz é um identificador de rastreamento, e assim que deve ser fornecido um chapéu.  Se o tipo de elemento também for um tipo de referência, também requer um chapéu.  Por exemplo, o exemplo anterior, quando expresso na nova sintaxe, temos como segue:  
  
```  
void PrintValues( array<Object^>^ myArr );  
void PrintValues( array<int,3>^ myArr );  
```  
  
 Como um tipo de referência é um identificador de rastreamento em vez de um objeto, é possível especificar uma matriz de CLR como o tipo de retorno de uma função. \(Em vez, não é possível especificar a matriz nativo como o tipo de retorno de uma função.\) A sintaxe para fazer isso em extensões gerenciadas fosse um pouco não intuitiva.  Por exemplo:  
  
```  
Int32 f() [];  
int GetArray() __gc[];  
```  
  
 Em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], a declaração é muito mais simples.  Por exemplo,  
  
```  
array<Int32>^ f();  
array<int>^ GetArray();  
```  
  
 A inicialização de taquigrafia de uma matriz gerenciada local tem suporte em ambas as versões de idioma.  Por exemplo:  
  
```  
int GetArray() __gc[] {  
   int a1 __gc[] = { 1, 2, 3, 4, 5 };  
   Object* myObjArray __gc[] = {   
      __box(26), __box(27), __box(28), __box(29), __box(30)  
   };  
   return a1;  
}  
```  
  
 é simplificado consideravelmente na nova sintaxe \(observe que porque o caso é implícito na nova sintaxe, o operador de `__box` foi eliminada – consulte [Tipos de valor e seus comportamentos \(C\+\+\/CLI\)](../dotnet/value-types-and-their-behaviors-cpp-cli.md) para obter uma discussão\):  
  
```  
array<int>^ GetArray() {  
   array<int>^ a1 = {1,2,3,4,5};  
   array<Object^>^ myObjArray = {26,27,28,29,30};  
   return a1;  
}  
```  
  
 Como uma matriz é um tipo de referência de CLR, a declaração de cada objeto de matriz é um identificador de rastreamento.  Consequentemente, os objetos da matriz devem ser atribuídos no heap de CLR. \(A notação de taquigrafia oculta a alocação gerenciado do heap.\) Aqui está o formulário explícito da inicialização de um objeto da matriz em extensões gerenciadas:  
  
```  
Object* myArray[] = new Object*[2];  
String* myMat[,] = new String*[4,4];  
```  
  
 Na nova sintaxe, a expressão de `new` é substituída por `gcnew`.  Os tamanhos de dimensão são passados como parâmetros à expressão de `gcnew` , como segue:  
  
```  
array<Object^>^ myArray = gcnew array<Object^>(2);  
array<String^,2>^ myMat = gcnew array<String^,2>(4,4);  
```  
  
 Na nova sintaxe, uma lista explícita de inicialização pode acompanhar a expressão de `gcnew` ; isso não foi suporte em extensões gerenciadas.  Por exemplo:  
  
```  
// explicit initialization list following gcnew   
// was not supported in Managed Extensions  
array<Object^>^ myArray =   
   gcnew array<Object^>(4){ 1, 1, 2, 3 };  
```  
  
## Consulte também  
 [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md)   
 [Arrays](../windows/arrays-cpp-component-extensions.md)