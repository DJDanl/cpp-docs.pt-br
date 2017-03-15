---
title: "Como realizar marshaling de matrizes usando PInvoke | Microsoft Docs"
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
  - "realização de marshaling em dados [C++], matrizes"
  - "interoperabilidade [C++], matrizes"
  - "realização de marshaling [C++], matrizes"
  - "invocação de plataforma [C++], matrizes"
ms.assetid: a1237797-a2da-4df4-984a-6333ed3af406
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de matrizes usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como as funções nativos que aceitam cadeias de caracteres de C \- estilo podem ser chamadas usando o tipo <xref:System.String> de cadeia de caracteres de CLR usando o suporte da invocação de plataforma do.NET Framework.  Os desenvolvedores do Visual C\+\+ devem usar os recursos do C\+\+ Interoperabilidade vez \(quando possível P\/Invoke\) porque fornece vez relatório de erros de tempo de compilação, não são tipo seguro, e podem ser fastidiosos de implementar.  Se a API não gerenciado é empacotado como uma DLL e o código\-fonte não estiverem disponíveis, P\/Invoke é a única opção \(se não, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)\).  
  
## Exemplo  
 Como as matrizes gerenciados e nativos são apresentadas diferentemente na memória, transmiti\-los com êxito por limite gerenciados e não gerenciados exige conversão, ou marshaling.  Este tópico mostra como uma matriz de itens blitable simples \(\) pode ser passada a funções nativos de código gerenciado.  
  
 Como é verdadeiro dados gerenciados e não gerenciados marshaling em geral, o atributo de <xref:System.Runtime.InteropServices.DllImportAttribute> é usado para criar um ponto de entrada gerenciado para cada função nativo que será usada.  No caso das funções que usam matrizes como argumentos, o atributo de <xref:System.Runtime.InteropServices.MarshalAsAttribute> deve ser usado também para especifique ao compilador como marshaling dos dados.  No exemplo a seguir, a enumeração de <xref:System.Runtime.InteropServices.UnmanagedType> é usada para indicar que a matriz marshaling gerenciado como c o estilo da matriz.  
  
 O código a seguir consiste em um módulo não gerenciado e gerenciado.  O módulo não gerenciado é uma DLL que define uma função que aceita uma matriz de inteiros.  O segundo módulo é um aplicativo gerenciado de linha de comando que importa essa função por fim, mas em termos de uma matriz gerenciado, e usá\-los o atributo de <xref:System.Runtime.InteropServices.MarshalAsAttribute> para especificar que a matriz deve ser convertida em uma matriz nativo quando chamada.  
  
 O módulo gerenciado é compilado com \/clr, mas trabalho de \/clr:pure também.  
  
```  
// TraditionalDll4.cpp  
// compile with: /LD /EHsc  
#include <iostream>  
  
#define TRADITIONALDLL_EXPORTS  
#ifdef TRADITIONALDLL_EXPORTS  
#define TRADITIONALDLL_API __declspec(dllexport)  
#else  
#define TRADITIONALDLL_API __declspec(dllimport)  
#endif  
  
extern "C" {  
   TRADITIONALDLL_API void TakesAnArray(int len, int[]);  
}  
  
void TakesAnArray(int len, int a[]) {  
   printf_s("[unmanaged]\n");  
   for (int i=0; i<len; i++)  
      printf("%d = %d\n", i, a[i]);  
}  
```  
  
```  
// MarshalBlitArray.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
value struct TraditionalDLL {  
   [DllImport("TraditionalDLL4.dll")]  
   static public void TakesAnArray(  
   int len,[MarshalAs(UnmanagedType::LPArray)]array<int>^);  
};  
  
int main() {  
   array<int>^ b = gcnew array<int>(3);  
   b[0] = 11;  
   b[1] = 33;  
   b[2] = 55;  
   TraditionalDLL::TakesAnArray(3, b);  
  
   Console::WriteLine("[managed]");  
   for (int i=0; i<3; i++)  
      Console::WriteLine("{0} = {1}", i, b[i]);  
}  
```  
  
 Observe que nenhuma parte da DLL está exposta ao código gerenciado com a política tradicional de \#include.  De fato, como a DLL está em tempo de execução, somente os problemas com as funções com <xref:System.Runtime.InteropServices.DllImportAttribute> importadas não serão detectados em tempo de compilação.  
  
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)