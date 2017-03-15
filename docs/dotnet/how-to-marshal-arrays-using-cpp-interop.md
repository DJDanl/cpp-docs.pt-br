---
title: "Como realizar marshaling de matrizes usando interop C++ | Microsoft Docs"
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
  - "matrizes [C++], marshaling"
  - "Interoperabilidade C++, matrizes"
  - "realização de marshaling em dados [C++], matrizes"
  - "interoperabilidade [C++], matrizes"
  - "realização de marshaling [C++], matrizes"
ms.assetid: c2b37ab1-8acf-4855-ad3c-7d2864826b14
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de matrizes usando interop C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra uma faceta de interoperabilidade do Visual C\+\+.  Para obter mais informações, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas essas funções interoperam da mesma forma que se definido em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como passar uma matriz gerenciada em uma função não gerenciado.  A função gerenciado usa [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md) para suprimir a coleta de lixo para a matriz antes de chamar a função não gerenciado.  Fornecendo a função não gerenciado um ponteiro fixado no heap de GC, a sobrecarga de fazer uma cópia da matriz pode ser evitado.  Para demonstrar que a função não gerenciado está acessando a memória heap de GC, altera o conteúdo da matriz e as alterações são refletidas quando o controle gerenciado de resumos da função.  
  
```  
// PassArray1.cpp  
// compile with: /clr  
#ifndef _CRT_RAND_S  
#define _CRT_RAND_S  
#endif  
  
#include <iostream>  
#include <stdlib.h>  
using namespace std;  
  
using namespace System;  
  
#pragma unmanaged  
  
void TakesAnArray(int* a, int c) {  
   cout << "(unmanaged) array received:\n";  
   for (int i=0; i<c; i++)  
      cout << "a[" << i << "] = " << a[i] << "\n";  
  
   unsigned int number;  
   errno_t err;  
  
   cout << "(unmanaged) modifying array contents...\n";  
   for (int i=0; i<c; i++) {  
      err = rand_s( &number );  
      if ( err == 0 )  
         a[i] = number % 100;  
   }  
}  
  
#pragma managed  
  
int main() {  
   array<int>^ nums = gcnew array<int>(5);  
  
   nums[0] = 0;  
   nums[1] = 1;  
   nums[2] = 2;  
   nums[3] = 3;  
   nums[4] = 4;  
  
   Console::WriteLine("(managed) array created:");  
   for (int i=0; i<5; i++)  
      Console::WriteLine("a[{0}] = {1}", i, nums[i]);  
  
   pin_ptr<int> pp = &nums[0];  
   TakesAnArray(pp, 5);  
  
   Console::WriteLine("(managed) contents:");  
   for (int i=0; i<5; i++)  
      Console::WriteLine("a[{0}] = {1}", i, nums[i]);  
}  
```  
  
## Exemplo  
 O exemplo a seguir demonstra passe uma matriz não gerenciada em uma função gerenciada.  A função gerenciado acessa a memória da matriz diretamente \(em vez de criar uma matriz gerenciado e de copiar o conteúdo da matriz\), que permite que as modificações feitas pela função gerenciada a ser refletido na função não gerenciado quando recupera o controle.  
  
```  
// PassArray2.cpp  
// compile with: /clr   
#include <iostream>  
using namespace std;  
  
using namespace System;  
  
#pragma managed  
  
void ManagedTakesAnArray(int* a, int c) {  
   Console::WriteLine("(managed) array received:");  
   for (int i=0; i<c; i++)  
      Console::WriteLine("a[{0}] = {1}", i, a[i]);  
  
   cout << "(managed) modifying array contents...\n";  
   Random^ r = gcnew Random(DateTime::Now.Second);  
   for (int i=0; i<c; i++)  
      a[i] = r->Next(100);  
}  
  
#pragma unmanaged  
  
void NativeFunc() {  
   int nums[5] = { 0, 1, 2, 3, 4 };  
  
   printf_s("(unmanaged) array created:\n");  
   for (int i=0; i<5; i++)  
      printf_s("a[%d] = %d\n", i, nums[i]);  
  
   ManagedTakesAnArray(nums, 5);  
  
   printf_s("(ummanaged) contents:\n");  
   for (int i=0; i<5; i++)  
      printf_s("a[%d] = %d\n", i, nums[i]);  
}  
  
#pragma managed  
  
int main() {  
   NativeFunc();  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)