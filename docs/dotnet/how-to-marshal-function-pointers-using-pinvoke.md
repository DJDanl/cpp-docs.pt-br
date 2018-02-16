---
title: "Como: marshaling de ponteiros de função usando PInvoke | Microsoft Docs"
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
- data marshaling [C++], callbacks and delegates
- interop [C++], callbacks and delegates
- platform invoke [C++], callbacks and delegates
- marshaling [C++], callbacks and delegates
ms.assetid: dcf396fd-a91d-49c0-ab0b-1ea160668a89
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 38854e3debbaf34c9068ed9fbc22e34274512687
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="how-to-marshal-function-pointers-using-pinvoke"></a>Como realizar marshaling de ponteiros de função usando PInvoke
Este tópico explica como gerenciados delegados pode ser usado no lugar de ponteiros de função quando interoperar com não gerenciados funções usando recursos do .NET Framework P/Invoke. No entanto, os programadores de Visual C++ são incentivados a usar os recursos de interoperabilidade C++ em vez disso (quando for possível) porque P/Invoke oferece pouco tempo de compilação relatório de erro, não é de tipo seguro e poderá ser tedioso implementar. Se a API não gerenciada é empacotada como uma DLL e o código-fonte não estiver disponível, o P/Invoke é a única opção. Caso contrário, consulte os tópicos a seguir:  
  
-   [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)  
  
-   [Como realizar marshaling de retornos de chamada e delegados usando interop do C++](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)  
  
 APIs não gerenciadas que usam ponteiros de funções como argumentos podem ser chamados de código gerenciado com um delegado gerenciado em vez do ponteiro de função nativa. O compilador automaticamente empacota o delegado para funções não gerenciadas como um ponteiro de função e insere o código necessário transição gerenciado/não gerenciado.  
  
## <a name="example"></a>Exemplo  
 O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função chamada TakesCallback que aceita um ponteiro de função. Este endereço é usado para executar a função.  
  
 O módulo gerenciado define um delegado que passa por marshaling para o código nativo como um ponteiro de função e usa o <xref:System.Runtime.InteropServices.DllImportAttribute> atributo para expor a função TakesCallback nativa para o código gerenciado. A função principal, uma instância do representante é criada e passada para a função TakesCallback. A saída de programa demonstra que essa função seja executada pela função TakesCallback nativo.  
  
 A função gerenciada suprime a coleta de lixo para o representante gerenciado para evitar a coleta de lixo do .NET Framework de realocar o representante enquanto executa a função nativa.  
  
```cpp  
// TraditionalDll5.cpp  
// compile with: /LD /EHsc  
#include <iostream>  
#define TRADITIONALDLL_EXPORTS  
#ifdef TRADITIONALDLL_EXPORTS  
#define TRADITIONALDLL_API __declspec(dllexport)  
#else  
#define TRADITIONALDLL_API __declspec(dllimport)  
#endif  
  
extern "C" {  
   /* Declare an unmanaged function type that takes two int arguments  
      Note the use of __stdcall for compatibility with managed code */  
   typedef int (__stdcall *CALLBACK)(int);  
   TRADITIONALDLL_API int TakesCallback(CALLBACK fp, int);  
}  
  
int TakesCallback(CALLBACK fp, int n) {  
   printf_s("[unmanaged] got callback address, calling it...\n");  
   return fp(n);  
}  
```  
  
```cpp  
// MarshalDelegate.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
public delegate int GetTheAnswerDelegate(int);  
public value struct TraditionalDLL {  
   [DllImport("TraditionalDLL5.dll")]  
   static public int TakesCallback(GetTheAnswerDelegate^ pfn, int n);  
};  
  
int GetNumber(int n) {  
   Console::WriteLine("[managed] callback!");  
   static int x = 0;  
   ++x;  
   return x + n;  
}  
  
int main() {  
   GetTheAnswerDelegate^ fp = gcnew GetTheAnswerDelegate(GetNumber);  
   pin_ptr<GetTheAnswerDelegate^> pp = &fp;  
   Console::WriteLine("[managed] sending delegate as callback...");  
  
   int answer = TraditionalDLL::TakesCallback(fp, 42);  
}  
```  
  
 Observe que nenhuma parte da DLL é exposto para o código gerenciado usando o tradicional # diretiva include. Na verdade, a DLL é acessada no tempo de execução, para problemas com funções importados com <xref:System.Runtime.InteropServices.DllImportAttribute> não serão detectadas em tempo de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)