---
title: "Como realizar marshaling de ponteiros inseridos usando interop C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interoperabilidade C++, ponteiros inseridos"
  - "realização de marshaling em dados [C++], ponteiros inseridos"
  - "interoperabilidade [C++], ponteiros inseridos"
  - "realização de marshaling [C++], ponteiros inseridos"
  - "ponteiros [C++], marshaling"
  - "estruturas [C++], realizando marshaling em ponteiros inseridos"
ms.assetid: 05fb8858-97f2-47aa-86b2-2c0ad713bdb2
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de ponteiros inseridos usando interop C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas essas funções interoperam da mesma forma que se definido em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como uma função não gerenciado que usa uma estrutura que contém ponteiros pode ser chamada de uma função gerenciada.  A função gerenciada cria uma instância de estrutura e inicializa o ponteiro inserido com a nova palavra\-chave \(em vez da palavra\-chave de [ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md) \).  Isso porque aloca memória heap nativo, não há necessidade de manter a matriz para suprimir a coleta de lixo.  No entanto, a memória deve ser explicitamente excluída para evitar o escapamento de memória.  
  
```  
// marshal_embedded_pointer.cpp  
// compile with: /clr  
#include <iostream>  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
// unmanaged struct  
struct ListStruct {  
   int count;  
   double* item;  
};  
  
#pragma unmanaged  
  
void UnmanagedTakesListStruct(ListStruct list) {  
   printf_s("[unmanaged] count = %d\n", list.count);  
   for (int i=0; i<list.count; i++)  
      printf_s("array[%d] = %f\n", i, list.item[i]);  
}  
  
#pragma managed  
  
int main() {  
   ListStruct list;  
   list.count = 10;  
   list.item = new double[list.count];  
  
   Console::WriteLine("[managed] count = {0}", list.count);  
   Random^ r = gcnew Random(0);  
   for (int i=0; i<list.count; i++) {  
      list.item[i] = r->NextDouble() * 100.0;  
      Console::WriteLine("array[{0}] = {1}", i, list.item[i]);  
   }  
  
   UnmanagedTakesListStruct( list );  
   delete list.item;  
}  
```  
  
  **contagem gerenciado \[\] \= 10**  
**matriz \[0\] \= 72,624326996796**  
**matriz \[1\] \= 81,7325359590969**  
**matriz \[2\] \= 76,8022689394663**  
**matriz \[3\] \= 55,8161191436537**  
**matriz \[4\] \= 20,6033154021033**  
**matriz \[5\] \= 55,8884794618415**  
**matriz \[6\] \= 90,6027066011926**  
**matriz \[7\] \= 44,2177873310716**  
**matriz \[8\] \= 97,754975314138**  
**matriz \[9\] \= 27,370445768987**  
**contagem não gerenciado \[\] \= 10**  
**matriz \[0\] \= 72,624327**  
**matriz \[1\] \= 81,732536**  
**matriz \[2\] \= 76,802269**  
**matriz \[3\] \= 55,816119**  
**matriz \[4\] \= 20,603315**  
**matriz \[5\] \= 55,888479**  
**matriz \[6\] \= 90,602707**  
**matriz \[7\] \= 44,217787**  
**matriz \[8\] \= 97,754975**  
**matriz \[9\] \= 27,370446**   
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)