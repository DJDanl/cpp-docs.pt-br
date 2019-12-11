---
title: Chamando funções nativas a partir do código gerenciado
ms.date: 11/04/2016
helpviewer_keywords:
- native functions called from managed code [C++]
- managed code [C++], interoperability
- platform invoke [C++], interoperability
- interoperabiliy [C++], calling native functions from managed code
- calling native functions from managed code
- interop [C++], calling native functions from managed code
ms.assetid: 982cef18-20d9-42b4-8242-a77fa65f2e36
ms.openlocfilehash: 50f40cc147daaa26a7fa4e607f0d4dd42cf22d61
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988661"
---
# <a name="calling-native-functions-from-managed-code"></a>Chamando funções nativas a partir do código gerenciado

O common language runtime fornece Serviços de Invocação de Plataforma, ou PInvoke, que permite que o código gerenciado chame funções no estilo do C em DLLs nativas. O mesmo empacotamento de dados é usado para a interoperabilidade COM com o tempo de execução e para o mecanismo IJW ("It Just Works").

Para obter mais informações, consulte .

- [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)

- [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)

Os exemplos nesta seção só ilustram como `PInvoke` pode ser usado. `PInvoke` pode simplificar o empacotamento de dados personalizados porque você fornece informações de empacotamento declarativamente em atributos em vez de escrever o código procedural.

> [!NOTE]
>  A biblioteca de empacotamento oferece uma maneira alternativa de empacotar dados entre ambientes nativos e gerenciados de uma forma otimizada. Consulte [visão geral do marshaling C++ em](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre a biblioteca de marshaling. A biblioteca de empacotamento só será utilizável para dados e não para funções.

## <a name="pinvoke-and-the-dllimport-attribute"></a>PInvoke e o atributo DllImport

O exemplo a seguir mostra o uso de `PInvoke` em um programa Visual C++. A função nativa puts é definida em msvcrt.dll. O atributo DllImport é usado para a declaração de puts.

```cpp
// platform_invocation_services.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("msvcrt", CharSet=CharSet::Ansi)]
extern "C" int puts(String ^);

int main() {
   String ^ pStr = "Hello World!";
   puts(pStr);
}
```

O exemplo a seguir é equivalente ao exemplo anterior, mas usa o IJW.

```cpp
// platform_invocation_services_2.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

#include <stdio.h>

int main() {
   String ^ pStr = "Hello World!";
   char* pChars = (char*)Marshal::StringToHGlobalAnsi(pStr).ToPointer();
   puts(pChars);

   Marshal::FreeHGlobal((IntPtr)pChars);
}
```

### <a name="advantages-of-ijw"></a>Vantagens de IJW

- Não há necessidade de escrever declarações de atributo `DLLImport` para APIs não gerenciadas usadas pelo programa. Inclua apenas o arquivo e o link de cabeçalho com a biblioteca de importação.

- O mecanismo do IJW é ligeiramente mais rápido (por exemplo, os modelos do IJW não precisam verificar a necessidade de fixar ou copiar itens de dados porque isso é feito explicitamente pelo desenvolvedor).

- Ilustra claramente problemas de desempenho. Nesse caso, o fato de você estar traduzindo a partir de uma cadeia de caracteres Unicode para uma cadeia de caracteres ANSI e de ter uma alocação e desalocação de memória de atendimento. Nesse caso, um desenvolvedor que escreve o código usando IJW perceberia que chamar `_putws` e usar `PtrToStringChars` seria melhor para desempenho.

- Se você chamar várias APIs não gerenciadas usando os mesmos dados, empacotá-las uma vez e passar a cópia empacotada é muito mais eficiente do que reempacotar todas as vezes.

### <a name="disadvantages-of-ijw"></a>Desvantagens de IJW

- O marshaling deve ser especificado explicitamente no código, e não pelos atributos (que geralmente têm padrões apropriados).

- O código de empacotamento é embutido, onde é mais invasivo no fluxo da lógica do aplicativo.

- Como as APIs de marshaling explícitas retornam tipos `IntPtr` para a portabilidade de 32 bits para 64 bits, você deve usar chamadas `ToPointer` extras.

O método específico exposto pelo método C++ é o método mais eficiente e explícito ao custo de alguma complexidade adicional.

Se o aplicativo usar especialmente tipos de dados não gerenciados ou se chamar mais APIs não gerenciadas do que as APIs do .NET Framework, recomendamos que você use o recurso IJW. Para chamar a API não gerenciada casual em um aplicativo basicamente gerenciado, a opção é mais sutil.

## <a name="pinvoke-with-windows-apis"></a>PInvoke com APIs do Windows

PInvoke é conveniente para a chamada de funções no Windows.

Nesse exemplo, um programa Visual C++ interopera com a função MessageBox que é parte da API do Win32.

```cpp
// platform_invocation_services_4.cpp
// compile with: /clr /c
using namespace System;
using namespace System::Runtime::InteropServices;
typedef void* HWND;
[DllImport("user32", CharSet=CharSet::Ansi)]
extern "C" int MessageBox(HWND hWnd, String ^ pText, String ^ pCaption, unsigned int uType);

int main() {
   String ^ pText = "Hello World! ";
   String ^ pCaption = "PInvoke Test";
   MessageBox(0, pText, pCaption, 0);
}
```

A saída é uma caixa de mensagem com o Teste de PInvoke do título e contém o texto Hello World!.

As informações de empacotamento também é usada por PInvoke para pesquisar funções na DLL. No user32.dll na verdade não há nenhuma função MessageBox, mas CharSet=CharSet::Ansi permite PInvoke a usar MessageBoxA, a versão ANSI, em vez de MessageBoxW, que é a versão Unicode. Em geral, recomendamos que você use versões Unicode de APIs não gerenciadas porque isso elimina a sobrecarga de tradução do formato nativo Unicode de objetos de cadeia de caracteres do .NET Framework para ANSI.

## <a name="when-not-to-use-pinvoke"></a>Quando não é para usar PInvoke

O uso do PInvoke não é apropriado para todas as funções estilo C nas DLLs. Por exemplo, suponha que haja uma função MakeSpecial em mylib.dll declarada como a seguir:

`char * MakeSpecial(char * pszString);`

Se usarmos PInvoke em um aplicativo Visual C++, nós podemos escrever algo semelhante ao seguinte:

```cpp
[DllImport("mylib")]
extern "C" String * MakeSpecial([MarshalAs(UnmanagedType::LPStr)] String ^);
```

A dificuldade aqui é que nós não podemos excluir a memória para a cadeia de caracteres não gerenciada retornada por MakeSpecial. Outras funções chamadas por meio do PInvoke retornam um ponteiro para um buffer interno que não precisa ser desalocado pelo usuário. Nesse caso, usar o recurso de IJW é a opção óbvia.

## <a name="limitations-of-pinvoke"></a>Limitações de PInvoke

Não é possível retornar o mesmo ponteiro de uma função nativa que você recebe como um parâmetro. Se uma função nativa retorna o ponteiro que foi empacotado a ela pelo PInvoke, danos de memória e exceções podem surgir.

```cpp
__declspec(dllexport)
char* fstringA(char* param) {
   return param;
}
```

O exemplo a seguir exibe este problema, e mesmo que o programa aparentemente ofereça a entrada correta, a saída está vindo da memória que foi liberada.

```cpp
// platform_invocation_services_5.cpp
// compile with: /clr /c
using namespace System;
using namespace System::Runtime::InteropServices;
#include <limits.h>

ref struct MyPInvokeWrap {
public:
   [ DllImport("user32.dll", EntryPoint = "CharLower", CharSet = CharSet::Ansi) ]
   static String^ CharLower([In, Out] String ^);
};

int main() {
   String ^ strout = "AabCc";
   Console::WriteLine(strout);
   strout = MyPInvokeWrap::CharLower(strout);
   Console::WriteLine(strout);
}
```

## <a name="marshaling-arguments"></a>Argumentos Marshaling

Com o `PInvoke`, nenhum empacotamento é necessário entre os tipos gerenciados e os tipos primitivos nativos de C++ com o mesmo formulário. Por exemplo, nenhum marshaling é necessário entre Int32 e int, ou entre Double e double.

Entretanto, você deve empacotar os tipos que não têm o mesmo formulário. Isso inclui os tipos char, string e struct. A tabela a seguir mostra os mapeamentos usados pelo empacotador para vários tipos:

|wtypes.h|Visual C++|Visual C++ com /clr|Common Language Runtime|
|--------------|------------------|-----------------------------|-----------------------------|
|MANIPULAR|\* void|\* void|IntPtr, UIntPtr|
|BYTE|unsigned char|unsigned char|Byte|
|SHORT|short|short|Int16|
|WORD|unsigned short|unsigned short|UInt16|
|INT|int|int|Int32|
|UINT|unsigned int|unsigned int|UInt32|
|LONG|long|long|Int32|
|BOOL|long|{1&gt;bool&lt;1}|Booliano|
|DWORD|unsigned long|unsigned long|UInt32|
|ULONG|unsigned long|unsigned long|UInt32|
|CHAR|char|char|Char|
|LPCSTR|\* de caracteres|String ^ [in], StringBuilder ^ [in, out]|String ^ [in], StringBuilder ^ [in, out]|
|LPCSTR|\* const char|String ^|Cadeia de Caracteres|
|LPWSTR|wchar_t \*|String ^ [in], StringBuilder ^ [in, out]|String ^ [in], StringBuilder ^ [in, out]|
|LPCWSTR|const wchar_t \*|String ^|Cadeia de Caracteres|
|FLOAT|float|float|Simples|
|DOUBLE|double|double|Duplo|

O empacotador fixará automaticamente a memória alocada na pilha de tempo de execução se seu endereço for passado para uma função não gerenciada. A fixação impede que o coletor de lixo mova o bloco de memória alocado durante a compactação.

No exemplo mostrado anteriormente neste tópico, o parâmetro de CharSet do DllImport especifica como deve ser realizado o marshaling das cadeias de caracteres gerenciadas; nesse caso, elas devem ser empacotadas para cadeias de caracteres ANSI para o lado nativo.

É possível especificar informações de empacotamento para argumentos individuais de uma função nativa usando o atributo MarshalAs. Há várias opções para realizar o marshaling de uma cadeia de caracteres \* argumento: BStr, ANSIBStr, TBStr, LPStr, LPWStr e LPTStr. O padrão é LPStr.

Nesse exemplo, é realizado marshaling na cadeia de caracteres como se ela fosse uma cadeia de caracteres Unicode de dois bytes, LPWStr. A saída é a primeira letra do Olá, Mundo! Porque o segundo byte da cadeia de caracteres empacotada é nulo e coloca a interpretação como o marcador de fim de cadeia de caracteres.

```cpp
// platform_invocation_services_3.cpp
// compile with: /clr
using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("msvcrt", EntryPoint="puts")]
extern "C" int puts([MarshalAs(UnmanagedType::LPWStr)] String ^);

int main() {
   String ^ pStr = "Hello World!";
   puts(pStr);
}
```

O atributo MarshalAs está no namespace System::Runtime::InteropServices. O atributo pode ser usado com outros tipos de dados como matrizes.

Como mencionado anteriormente no tópico, a biblioteca de marshaling fornece um método novo e otimizado de dados de marshaling entre ambientes nativos e gerenciados. Para obter mais informações, consulte [visão geral do marshaling no C++ ](../dotnet/overview-of-marshaling-in-cpp.md).

## <a name="performance-considerations"></a>Considerações sobre desempenho

PInvoke tem uma sobrecarga entre 10 e 30 de instruções x86 por chamada. Além desse custo fixo, o marshaling cria uma sobrecarga adicional. Não há custos de empacotamento entre os tipos blittable que têm a mesma representação em código gerenciado e não gerenciado. Por exemplo, não há custos ao converter entre int e Int32.

Para melhor desempenho, tenha menos chamadas de PInvoke que efetuam marshal de tantos dados quanto possível, em vez de mais chamadas que efetuam marshal de menos dados por chamada.

## <a name="see-also"></a>Consulte também

[Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)
