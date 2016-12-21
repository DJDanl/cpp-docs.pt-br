---
title: "Como realizar marshaling de ponteiros de fun&#231;&#227;o usando PInvoke | Microsoft Docs"
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
  - "realização de marshaling em dados [C++], retornos de chamado e delegados"
  - "interoperabilidade [C++], retornos de chamado e delegados"
  - "realização de marshaling [C++], retornos de chamado e delegados"
  - "invocação de plataforma [C++], retornos de chamado e delegados"
ms.assetid: dcf396fd-a91d-49c0-ab0b-1ea160668a89
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de ponteiros de fun&#231;&#227;o usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como os representantes gerenciados podem ser usados em vez dos ponteiros da função ao interoperar com funções não gerenciados usando recursos do .NET Framework P\/Invoke.  No entanto, os desenvolvedores do Visual C\+\+ devem usar os recursos do C\+\+ Interoperabilidade vez \(quando possível P\/Invoke\) porque fornece vez relatório de erros de tempo de compilação, não são tipo seguro, e podem ser fastidiosos de implementar.  Se a API não gerenciado é empacotado como uma DLL e o código\-fonte não estiverem disponíveis, P\/Invoke é a única opção.  Se não, consulte os seguintes tópicos:  
  
-   [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)  
  
-   [Como realizar marshal de retornos de chamadas e delegados usando o C\+\+ Interop](../dotnet/how-to-marshal-callbacks-and-delegates-by-using-cpp-interop.md)  
  
 APIs não gerenciado que usam ponteiros de funções como argumentos podem ser chamados de código gerenciado com um representante gerenciado no lugar do ponteiro nativo da função.  Realiza marshaling do compilador os automaticamente o delegado a funções não gerenciado como um ponteiro de função e inserções transição gerenciado\/necessária código não gerenciado.  
  
## Exemplo  
 O código a seguir consiste em um módulo não gerenciado e gerenciado.  O módulo não gerenciado é uma DLL que define uma função chamada TakesCallback que aceita um ponteiro de função.  Este endereço é usado para executar a função.  
  
 O módulo gerenciado define um representante que marshaling para o código nativo como um ponteiro de função e usa o atributo de <xref:System.Runtime.InteropServices.DllImportAttribute> para expor a função nativo de TakesCallback ao código gerenciado.  Na função principal, uma instância do delegado é criada e passada à função de TakesCallback.  Saída de programa que demonstram essa função obtém executado pela função nativo de TakesCallback.  
  
 A função gerenciada suprime a coleta de lixo para que o representante gerenciado impede que a coleta de lixo do .NET Framework realocando o delegado quando a função nativo executar.  
  
 O módulo gerenciado é compilado com \/clr, mas trabalho de \/clr:pure também.  
  
```  
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
  
```  
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
  
 Observe que nenhuma parte da DLL está exposta ao código gerenciado usando a diretiva tradicional de \#include.  De fato, a DLL é acessado em tempo de execução, apenas assim que os problemas com as funções com <xref:System.Runtime.InteropServices.DllImportAttribute> importadas não serão detectados em tempo de compilação.  
  
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)