---
title: 'Como: marshaling de matrizes usando PInvoke | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- marshaling [C++], arrays
- platform invoke [C++], arrays
- interop [C++], arrays
- data marshaling [C++], arrays
ms.assetid: a1237797-a2da-4df4-984a-6333ed3af406
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 03e3cf184828c33c63c5252344eb0041640729cb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33132525"
---
# <a name="how-to-marshal-arrays-using-pinvoke"></a>Como realizar marshaling de matrizes usando PInvoke
Este tópico explica como nativas funções que aceitam cadeias de caracteres de estilo C podem ser chamadas usando o tipo de cadeia de caracteres CLR <xref:System.String> usando o suporte de invocação de plataforma do .NET Framework. Programadores de Visual C++ são incentivados a usar os recursos de interoperabilidade C++ em vez disso (quando for possível) porque P/Invoke oferece pouco tempo de compilação relatório de erro, não é de tipo seguro e poderá ser tedioso implementar. Se a API não gerenciada é empacotada como uma DLL e o código-fonte não estiver disponível, o P/Invoke é a única opção (caso contrário, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)).  
  
## <a name="example"></a>Exemplo  
 Porque nativos e gerenciados matrizes são dispostas diferente na memória, transmiti-los com êxito entre o limite gerenciado/não gerenciado requer conversão, ou a realização de marshaling. Este tópico demonstra como uma matriz de itens simples (blitable) pode ser passada para funções nativas do código gerenciado.  
  
 De marshaling de dados gerenciado/não gerenciado em geral, o <xref:System.Runtime.InteropServices.DllImportAttribute> atributo é usado para criar um ponto de entrada gerenciado para cada função nativa que será usado. No caso de funções que usam matrizes como argumentos, o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo deve ser usado também para especificar para o compilador como os dados serão empacotados. No exemplo a seguir, o <xref:System.Runtime.InteropServices.UnmanagedType> enumeração é usada para indicar que a matriz gerenciada será empacotada como uma matriz C-style.  
  
 O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função que aceita uma matriz de inteiros. O segundo módulo é um aplicativo gerenciado de linha de comando que importa essa função, mas define em termos de uma matriz gerenciada e usa o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo para especificar que a matriz deve ser convertida em uma matriz nativa quando chamado.  
  
 O módulo gerenciado é compilado com /clr.  
  
```cpp  
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
  
```cpp  
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
  
 Observe que nenhuma parte da DLL é exposto para o código gerenciado por meio do tradicional # diretiva include. Na verdade, porque a DLL é acessada no tempo de execução apenas, problemas com funções importados com <xref:System.Runtime.InteropServices.DllImportAttribute> não serão detectadas em tempo de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)