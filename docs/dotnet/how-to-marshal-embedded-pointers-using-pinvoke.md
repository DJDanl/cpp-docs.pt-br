---
title: 'Como: marshaling de ponteiros inseridos usando PInvoke | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs:
- C++
helpviewer_keywords:
- embedded pointers [C++]
- interop [C++], embedded pointers
- platform invoke [C++], embedded pointers
- marshaling [C++], embedded pointers
- data marshaling [C++], embedded pointers
ms.assetid: f12c1b9a-4f82-45f8-83c8-3fc9321dbb98
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: cd2717e5ffc5dc25f7a98f679a23d6f97fd335a5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="how-to-marshal-embedded-pointers-using-pinvoke"></a>Como realizar marshaling de ponteiros inseridos usando PInvoke
Funções que são implementadas em DLLs não gerenciados podem ser chamadas de código gerenciado usando a funcionalidade de invocação de plataforma (P/Invoke). Se o código-fonte para a DLL não estiver disponível, o P/Invoke é a única opção para interoperar. No entanto, ao contrário de outras linguagens .NET, o Visual C++ fornece uma alternativa para P/Invoke. Para obter mais informações, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md) e [como: marshaling incorporado ponteiros usando Interop C++](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).  
  
## <a name="example"></a>Exemplo  
 Passando estruturas para código nativo requer que uma estrutura gerenciada equivalente em termos de layout de dados para a estrutura nativa é criada. No entanto, as estruturas que contêm ponteiros requerem tratamento especial. Para cada ponteiro incorporado na estrutura de nativo, a versão gerenciada da estrutura deve conter uma instância das <xref:System.IntPtr> tipo. Além disso, memória para essas instâncias devem ser explicitamente alocadas, inicializado e liberadas usando o <xref:System.Runtime.InteropServices.Marshal.AllocCoTaskMem%2A>, <xref:System.Runtime.InteropServices.Marshal.StructureToPtr%2A>, e <xref:System.Runtime.InteropServices.Marshal.FreeCoTaskMem%2A> métodos.  
  
 O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função que aceita uma estrutura chamada ListString que contém um ponteiro e uma função chamada TakesListStruct. O módulo gerenciado é um aplicativo de linha de comando que importa a função TakesListStruct e define uma estrutura chamada MListStruct que é equivalente a ListStruct nativo, exceto que duplo * é representada com um <xref:System.IntPtr> instância. Antes de chamar TakesListStruct, a função principal aloca e inicializa a memória que faz referência a esse campo.  
  
```cpp  
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
  
```cpp  
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
  
 Observe que nenhuma parte da DLL é exposto para o código gerenciado usando o tradicional # diretiva include. Na verdade, a DLL é acessada no tempo de execução, para problemas com funções importados com <xref:System.Runtime.InteropServices.DllImportAttribute> não serão detectadas em tempo de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)