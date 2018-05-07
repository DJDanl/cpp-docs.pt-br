---
title: 'Como: marshaling de cadeias de caracteres usando PInvoke | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- data marshaling [C++], strings
- platform invoke [C++], strings
ms.assetid: bcc75733-7337-4d9b-b1e9-b95a98256088
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1a377e7074e72693a1a63e392c64a6d60c5995b7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-marshal-strings-using-pinvoke"></a>Como realizar marshaling de cadeias de caracteres usando PInvoke
Este tópico explica como nativas funções que aceitam cadeias de caracteres de estilo C podem ser chamadas usando a cadeia de caracteres CLR usando o suporte de invocação de plataforma do .NET Framework System:: string de tipo. Programadores de Visual C++ são incentivados a usar os recursos de interoperabilidade C++ em vez disso (quando for possível) porque P/Invoke oferece pouco tempo de compilação relatório de erro, não é de tipo seguro e poderá ser tedioso implementar. Se a API não gerenciada é empacotada como uma DLL, e o código-fonte não está disponível, o P/Invoke é a única opção, mas, caso contrário, consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 Cadeias de caracteres gerenciadas e são dispostas diferente na memória, portanto passar cadeias de caracteres de gerenciado para funções não gerenciadas requer o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo para instruir o compilador para inserir os mecanismos de conversão necessária para realizar marshaling de dados de cadeia de caracteres corretamente e com segurança.  
  
 Assim como acontece com funções que usam somente tipos de dados intrínseca, <xref:System.Runtime.InteropServices.DllImportAttribute> é usada para declarar os pontos de entrada gerenciado para as funções nativas, mas – para passar cadeias de caracteres – em vez de definir esses pontos de entrada como colocar cadeias de caracteres de estilo C, um identificador para o <xref:System.String> tipo pode ser usado em vez disso. Isso solicita que o compilador para inserir o código que executa a conversão necessária. Para cada argumento de função em uma função não gerenciada que usa uma cadeia de caracteres, o <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo deve ser usado para indicar que o objeto de cadeia de caracteres deve ser empacotado para a função nativa como uma cadeia de caracteres de estilo C.  
  
## <a name="example"></a>Exemplo  
 O código a seguir consiste em uma não gerenciado e um módulo gerenciado. O módulo não gerenciado é uma DLL que define uma função chamada TakesAString que aceita uma cadeia de caracteres ANSI C-style na forma de um char *. O módulo gerenciado é um aplicativo de linha de comando que importa a função TakesAString, mas define como colocar um System. String gerenciado em vez de um caractere\*. O <xref:System.Runtime.InteropServices.MarshalAsAttribute> atributo é usado para indicar como a cadeia de caracteres gerenciada deve ser empacotada quando TakesAString é chamado.  
  
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
  
 Essa técnica faz com que uma cópia da cadeia de caracteres a ser construído no heap gerenciado, então as alterações feitas à cadeia de caracteres, a função nativa não serão refletidas na cópia gerenciada da cadeia de caracteres.  
  
 Observe que nenhuma parte da DLL é exposto para o código gerenciado por meio do tradicional # diretiva include. Na verdade, a DLL é acessada no tempo de execução, para problemas com funções importados com `DllImport` não serão detectadas em tempo de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)