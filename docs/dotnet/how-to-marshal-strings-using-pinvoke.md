---
title: Como realizar marshaling de cadeias de caracteres usando PInvoke
ms.custom: get-started-article
ms.date: 09/09/2016
helpviewer_keywords:
- interop [C++], strings
- marshaling [C++], strings
- data marshaling [C++], strings
- platform invoke [C++], strings
ms.assetid: bcc75733-7337-4d9b-b1e9-b95a98256088
ms.openlocfilehash: e89177261aa32d34ea392030078d4088ea61e2a5
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988441"
---
# <a name="how-to-marshal-strings-using-pinvoke"></a>Como realizar marshaling de cadeias de caracteres usando PInvoke

Este tópico explica como as funções nativas que aceitam cadeias de caracteres C-style podem ser chamadas usando o tipo de String CLR System:: String usando o suporte à invocação de plataforma .NET Framework. Os C++ programadores visuais são incentivados a C++ usar os recursos de interoperabilidade (quando possível) porque P/Invoke fornece pouco relatório de erros em tempo de compilação, não é de tipo seguro e pode ser entediante de implementar. Se a API não gerenciada for empacotada como uma DLL e o código-fonte não estiver disponível, P/Invoke será a única opção, mas, caso contrário, consulte [usando C++ a interoperabilidade (o PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md).

As cadeias de caracteres gerenciadas e não gerenciadas são dispostas de forma diferente na memória; portanto, passar cadeias de caracteres de funções gerenciadas para não gerenciadas requer que o atributo <xref:System.Runtime.InteropServices.MarshalAsAttribute> instrua o compilador a inserir os mecanismos de conversão necessários para realizar o marshaling dos dados da cadeia de caracteres de maneira correta e

Assim como acontece com as funções que usam apenas tipos de dados intrínsecos, <xref:System.Runtime.InteropServices.DllImportAttribute> é usado para declarar pontos de entrada gerenciados nas funções nativas, mas--para passar cadeias de caracteres – em vez de definir esses pontos de entrada como obter cadeias de estilo C, um identificador para o tipo de <xref:System.String> pode ser usado em vez disso. Isso solicita que o compilador Insira o código que executa a conversão necessária. Para cada argumento de função em uma função não gerenciada que usa uma cadeia de caracteres, o atributo <xref:System.Runtime.InteropServices.MarshalAsAttribute> deve ser usado para indicar que o objeto de cadeia de caracteres deve ser empacotado para a função nativa como uma cadeia de estilo C.

O marshaler encapsula a chamada para a função não gerenciada em uma rotina de wrapper oculta que fixa e copia a cadeia de caracteres gerenciada em uma cadeia de caracteres alocada localmente no contexto não gerenciado, que é passada para a função não gerenciada. Quando a função não gerenciada retorna, o wrapper exclui o recurso ou, se ele estava na pilha, ele é recuperado quando o wrapper sai do escopo. A função não gerenciada não é responsável por essa memória. O código não gerenciado cria e exclui apenas a memória no heap configurado por seu próprio CRT, portanto, nunca há um problema com o marshaler usando uma versão do CRT diferente.

Se a função não gerenciada retornar uma cadeia de caracteres, como um valor de retorno ou um parâmetro de saída, o marshaler a copiará para uma nova cadeia de caracteres gerenciada e, em seguida, liberará a memória. Para obter mais informações, consulte [comportamento de marshaling padrão](/dotnet/framework/interop/default-marshaling-behavior) e [empacotamento de dados com a invocação de plataforma](/dotnet/framework/interop/marshaling-data-with-platform-invoke).

## <a name="example"></a>Exemplo

O código a seguir consiste em um módulo não gerenciado e um gerenciado. O módulo não gerenciado é uma DLL que define uma função chamada TakesAString que aceita uma cadeia de caracteres ANSI no estilo C na forma de um Char *. O módulo gerenciado é um aplicativo de linha de comando que importa a função TakesAString, mas a define como pegar um System. String gerenciado em vez de um Char\*. O atributo <xref:System.Runtime.InteropServices.MarshalAsAttribute> é usado para indicar como a cadeia de caracteres gerenciada deve ser empacotada quando TakesAString é chamado.

```cpp
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

```cpp
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

Essa técnica faz com que uma cópia da cadeia de caracteres seja construída no heap não gerenciado, portanto, as alterações feitas na cadeia de caracteres pela função nativa não serão refletidas na cópia gerenciada da cadeia de caracteres.

Observe que nenhuma parte da DLL é exposta ao código gerenciado por meio da diretiva de #include tradicional. Na verdade, a DLL é acessada somente em tempo de execução, de modo que os problemas com funções importadas com `DllImport` não serão detectados no momento da compilação.

## <a name="see-also"></a>Consulte também

[Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)
