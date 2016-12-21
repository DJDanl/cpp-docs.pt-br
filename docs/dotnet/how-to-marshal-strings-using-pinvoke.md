---
title: "Como realizar marshaling de cadeias de caracteres usando PInvoke | Microsoft Docs"
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
  - "realização de marshaling em dados [C++], cadeias de caracteres"
  - "interoperabilidade [C++], cadeias de caracteres"
  - "realização de marshaling [C++], cadeias de caracteres"
  - "invocação de plataforma [C++], cadeias de caracteres"
ms.assetid: bcc75733-7337-4d9b-b1e9-b95a98256088
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de cadeias de caracteres usando PInvoke
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico explica como as funções nativos que aceitam cadeias de caracteres de C \- estilo podem ser chamadas usando o tipo System::String de cadeia de caracteres de CLR usando o suporte da invocação de plataforma do.NET Framework.  Os desenvolvedores do Visual C\+\+ devem usar os recursos do C\+\+ Interoperabilidade vez \(quando possível P\/Invoke\) porque fornece vez relatório de erros de tempo de compilação, não são tipo seguro, e podem ser fastidiosos de implementar.  Se a API não gerenciado é empacotado como uma DLL, e o código\-fonte não estiver disponível, então P\/Invoke é a única opção, mas consulta de outra forma [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 As cadeias de caracteres gerenciados e não gerenciados são apresentadas diferentemente na memória, o que passar cadeias de caracteres de gerenciado para as funções não gerenciados requer o atributo de <xref:System.Runtime.InteropServices.MarshalAsAttribute> instruir o compilador para inserir os mecanismos necessários à conversão para o marshaling os dados de cadeia de caracteres corretamente e com segurança.  
  
 Como com funções que usam apenas tipos de dados do intrínsecos, <xref:System.Runtime.InteropServices.DllImportAttribute> é usado para declarar pontos de entrada gerenciados em funções nativos, mas\-\-para passar cadeias de caracteres\-\-em vez de definir esses pontos de entrada como a realização de cadeias de caracteres de C \- estilo, um identificador para o tipo de <xref:System.String> pode ser usado.  Isso solicita ao compilador a inserir o código que executa a conversão necessária.  Para cada argumento da função em uma função não gerenciado que usa uma cadeia de caracteres, o atributo de <xref:System.Runtime.InteropServices.MarshalAsAttribute> deve ser usado para indicar se o objeto String deve realizar marshaling para a função nativo como c o estilo da cadeia de caracteres.  
  
## Exemplo  
 O código a seguir consiste em um módulo não gerenciado e gerenciado.  O módulo não gerenciado é uma DLL que define uma função chamada TakesAString que aceita a c o estilo da cadeia de caracteres ANSI na forma de um char\*.  O módulo gerenciado é um aplicativo de linha de comando que importa a função de TakesAString por fim, mas como fazer um System.String gerenciado em vez de um char\*.  O atributo de <xref:System.Runtime.InteropServices.MarshalAsAttribute> é usado para indicar como a cadeia de caracteres gerenciado deve realizar marshaling quando TakesAString é.  
  
 O módulo gerenciado é compilado com \/clr, mas trabalho de \/clr:pure também.  
  
```  
// TraditionalDll2.cpp  
// compile with: /LD /EHsc  
#include <windows.h>  
#include <stdio.h>  
#include <iostream>  
  
using namespace std;  
  
#define TRADITIONALDLL_EXPORTS  
#ifdef TRADITIONALDLL_EXPORTS  
#define TRADITIONALDLL_API __declspec(dllexport)  
#else  
#define TRADITIONALDLL_API __declspec(dllimport)  
#endif  
  
extern "C" {  
   TRADITIONALDLL_API void TakesAString(char*);  
}  
  
void TakesAString(char* p) {  
   printf_s("[unmanaged] %s\n", p);  
}  
```  
  
```  
// MarshalString.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
value struct TraditionalDLL  
{  
   [DllImport("TraditionalDLL2.dll")]  
      static public void   
      TakesAString([MarshalAs(UnmanagedType::LPStr)]String^);  
};  
  
int main() {  
   String^ s = gcnew String("sample string");  
    Console::WriteLine("[managed] passing managed string to unmanaged function...");  
   TraditionalDLL::TakesAString(s);  
   Console::WriteLine("[managed] {0}", s);  
}  
```  
  
 Essa técnica causado uma cópia da cadeia de caracteres a ser criada no heap não gerenciado, alterações feitas na cadeia de caracteres pela função nativo não será refletida isso na cópia gerenciado de cadeia de caracteres.  
  
 Observe que nenhuma parte da DLL está exposta ao código gerenciado pela política tradicional de \#include.  De fato, o DLL está em tempo de execução, apenas assim que os problemas com as funções com `DllImport` importadas não serão detectados em tempo de compilação.  
  
## Consulte também  
 [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)