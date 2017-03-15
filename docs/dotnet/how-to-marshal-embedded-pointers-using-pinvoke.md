---
title: "Como realizar marshaling de ponteiros inseridos usando PInvoke | Microsoft Docs"
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
  - "realização de marshaling em dados [C++], ponteiros inseridos"
  - "ponteiros inseridos [C++]"
  - "interoperabilidade [C++], ponteiros inseridos"
  - "realização de marshaling [C++], ponteiros inseridos"
  - "invocação de plataforma [C++], ponteiros inseridos"
ms.assetid: f12c1b9a-4f82-45f8-83c8-3fc9321dbb98
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de ponteiros inseridos usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções que são implementadas na DLL não gerenciado podem ser chamadas de código gerenciado usando a funcionalidade de invocação de plataforma \(P\/Invoke\).  Se o código\-fonte do DLL não estiver disponível, P\/Invoke é a única opção para interoperar.  No entanto, diferentemente de outras linguagens .NET, Visual C\+\+ fornece uma alternativa a P\/Invoke.  Para obter mais informações, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md) e [Como realizar marshaling de ponteiros inseridos usando interop C\+\+](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).  
  
## Exemplo  
 Passe estruturas em código nativo que requer uma estrutura gerenciado que é equivalente em termos de layout de dados à estrutura nativo é criada.  No entanto, as estruturas que contêm ponteiros exigem tratamento especial.  Para cada ponteiro inserido na estrutura nativo, a versão gerenciado da estrutura deve conter uma instância do tipo de <xref:System.IntPtr> .  Além disso, a memória para essas instâncias deve ser atribuída explicitamente, inicializado, e liberada usando <xref:System.Runtime.InteropServices.Marshal.AllocCoTaskMem%2A>, <xref:System.Runtime.InteropServices.Marshal.StructureToPtr%2A>, e os métodos de <xref:System.Runtime.InteropServices.Marshal.FreeCoTaskMem%2A> .  
  
 O código a seguir consiste em um módulo não gerenciado e gerenciado.  O módulo não gerenciado é uma DLL que define uma função que aceita uma estrutura chamada ListString que contém um ponteiro, e uma função chamada TakesListStruct.  O módulo gerenciado é um aplicativo de linha de comando que importa a função de TakesListStruct e define uma estrutura chamada MListStruct que é equivalente a ListStruct nativo com exceção de que o double\* é representado por uma instância de <xref:System.IntPtr> .  Antes de chamar TakesListStruct, a função principal e atribui inicializa a memória que faz referência a esse campo.  
  
 O módulo gerenciado é compilado com \/clr, mas trabalho de \/clr:pure também.  
  
```  
// TraditionalDll6.cpp  
// compile with: /EHsc /LD  
#include <stdio.h>  
#include <iostream>  
#define TRADITIONALDLL_EXPORTS  
#ifdef TRADITIONALDLL_EXPORTS  
#define TRADITIONALDLL_API __declspec(dllexport)  
#else  
#define TRADITIONALDLL_API __declspec(dllimport)  
#endif  
  
#pragma pack(push, 8)  
struct ListStruct {  
   int count;  
   double* item;  
};  
#pragma pack(pop)  
  
extern "C" {  
   TRADITIONALDLL_API void TakesListStruct(ListStruct);  
}  
  
void TakesListStruct(ListStruct list) {  
   printf_s("[unmanaged] count = %d\n", list.count);  
   for (int i=0; i<list.count; i++)  
      printf_s("array[%d] = %f\n", i, list.item[i]);  
}  
```  
  
```  
// EmbeddedPointerMarshalling.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
[StructLayout(LayoutKind::Sequential, Pack=8)]  
value struct MListStruct {  
   int count;  
   IntPtr item;  
};  
  
value struct TraditionalDLL {  
    [DllImport("TraditionalDLL6.dll")]  
   static public void TakesListStruct(MListStruct);  
};  
  
int main() {  
   array<double>^ parray = gcnew array<double>(10);  
   Console::WriteLine("[managed] count = {0}", parray->Length);  
  
   Random^ r = gcnew Random();  
   for (int i=0; i<parray->Length; i++) {  
      parray[i] = r->NextDouble() * 100.0;  
      Console::WriteLine("array[{0}] = {1}", i, parray[i]);  
   }  
  
   int size = Marshal::SizeOf(double::typeid);  
   MListStruct list;  
   list.count = parray->Length;  
   list.item = Marshal::AllocCoTaskMem(size * parray->Length);  
  
   for (int i=0; i<parray->Length; i++) {  
      IntPtr t = IntPtr(list.item.ToInt32() + i * size);  
      Marshal::StructureToPtr(parray[i], t, false);  
   }  
  
   TraditionalDLL::TakesListStruct( list );  
   Marshal::FreeCoTaskMem(list.item);  
}  
```  
  
 Observe que nenhuma parte da DLL está exposta ao código gerenciado usando a diretiva tradicional de \#include.  De fato, a DLL é acessado em tempo de execução, apenas assim que os problemas com as funções com <xref:System.Runtime.InteropServices.DllImportAttribute> importadas não serão detectados em tempo de compilação.  
  
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)