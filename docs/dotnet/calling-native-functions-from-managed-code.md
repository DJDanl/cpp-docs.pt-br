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
ms.openlocfilehash: 0cdd5db4fae8d9167fa9ab1aeb6a4e8cbfe76ded
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372517"
---
# <a name="calling-native-functions-from-managed-code"></a>Chamando funções nativas a partir do código gerenciado

O tempo de execução do idioma comum fornece Serviços de Invocação de Plataforma, ou PInvoke, que permite que o código gerenciado chame funções de estilo C em bibliotecas nativas vinculadas a dinâmicas (DLLs). O mesmo empacotamento de dados é usado como para interoperabilidade COM com o tempo de execução e para o mecanismo "It Just Works", ou IJW.

Para obter mais informações, consulte:

- [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)

- [Usando interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)

As amostras nesta seção `PInvoke` apenas ilustram como pode ser usado. `PInvoke`pode simplificar o empacotamento de dados personalizado porque você fornece informações de marshaling declarativamente em atributos em vez de escrever código de empacotamento processual.

> [!NOTE]
> A biblioteca de marshaling fornece uma maneira alternativa de reunir dados entre ambientes nativos e gerenciados de forma otimizada. Consulte [Visão geral do Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre a biblioteca de marshaling. A biblioteca de marshaling é utilizável apenas para dados, e não para funções.

## <a name="pinvoke-and-the-dllimport-attribute"></a>PInvoke e o atributo DllImport

O exemplo a seguir `PInvoke` mostra o uso de um programa Visual C++. A função nativa coloca é definida em msvcrt.dll. O atributo DllImport é usado para a declaração de puts.

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

A amostra a seguir é equivalente à amostra anterior, mas usa IJW.

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

### <a name="advantages-of-ijw"></a>Vantagens do IJW

- Não há necessidade `DLLImport` de escrever declarações de atributos para as APIs não gerenciadas que o programa usa. Basta incluir o arquivo de cabeçalho e vincular com a biblioteca de importação.

- O mecanismo IJW é um pouco mais rápido (por exemplo, os stubs do IJW não precisam verificar a necessidade de fixar ou copiar itens de dados porque isso é feito explicitamente pelo desenvolvedor).

- Ilustra claramente problemas de desempenho. Neste caso, o fato de que você está traduzindo de uma seqüência unicode para uma seqüência ANSI e que você tem uma alocação e desalocação de memória do atendente. Neste caso, um desenvolvedor que escreve o código `_putws` usando `PtrToStringChars` iJW perceberia que ligar e usar seria melhor para o desempenho.

- Se você chamar muitas APIs não gerenciadas usando os mesmos dados, empacotar uma vez e passar a cópia empacotada é muito mais eficiente do que re-marshaling todas as vezes.

### <a name="disadvantages-of-ijw"></a>Desvantagens do IJW

- O marshaling deve ser especificado explicitamente em código em vez de por atributos (que muitas vezes têm padrões apropriados).

- O código de empacotamento é inline, onde é mais invasivo no fluxo da lógica de aplicação.

- Como os tipos de `IntPtr` retorno de APIs de empacotamento explícito para `ToPointer` portabilidade de 32 bits a 64 bits, você deve usar chamadas extras.

O método específico exposto pelo C++ é o método mais eficiente e explícito, ao custo de alguma complexidade adicional.

Se o aplicativo usar principalmente tipos de dados não gerenciados ou se ele chamar mais APIs não gerenciadas do que ASI framework .NET, recomendamos que você use o recurso IJW. Para chamar uma API não gerenciada ocasionalmente em um aplicativo gerenciado, a escolha é mais sutil.

## <a name="pinvoke-with-windows-apis"></a>PInvoke com APIs do Windows

PInvoke é conveniente para funções de chamada no Windows.

Neste exemplo, um programa Visual C++ interopera com a função MessageBox que faz parte da API Win32.

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

A saída é uma caixa de mensagem que tem o título Teste PInvoke e contém o texto Hello World!.

As informações de empacotamento também são usadas pelo PInvoke para procurar funções na DLL. No user32.dll não há de fato nenhuma função MessageBox, mas CharSet=CharSet::Ansi permite que o PInvoke use messageBoxA, a versão ANSI, em vez do MessageBoxW, que é a versão Unicode. Em geral, recomendamos que você use versões Unicode de APIs não gerenciadas porque isso elimina a sobrecarga de tradução do formato unicode nativo de objetos de string .NET Framework para ANSI.

## <a name="when-not-to-use-pinvoke"></a>Quando não usar pinvoke

O uso do PInvoke não é apropriado para todas as funções de estilo C em DLLs. Por exemplo, suponha que há uma função MakeSpecial no mylib.dll declarada da seguinte forma:

`char * MakeSpecial(char * pszString);`

Se usarmos o PInvoke em um aplicativo Visual C++, podemos escrever algo semelhante ao seguinte:

```cpp
[DllImport("mylib")]
extern "C" String * MakeSpecial([MarshalAs(UnmanagedType::LPStr)] String ^);
```

A dificuldade aqui é que não podemos excluir a memória da seqüência não gerenciada devolvida pelo MakeSpecial. Outras funções chamadas através do PInvoke retornam um ponteiro para um buffer interno que não precisa ser desalocado pelo usuário. Neste caso, usar o recurso IJW é a escolha óbvia.

## <a name="limitations-of-pinvoke"></a>Limitações do PInvoke

Você não pode retornar o mesmo ponteiro exato de uma função nativa que você tomou como parâmetro. Se uma função nativa retornar o ponteiro que foi empacotado a ele pelo PInvoke, a corrupção de memória e as exceções podem ocorrer.

```cpp
__declspec(dllexport)
char* fstringA(char* param) {
   return param;
}
```

A amostra a seguir exibe esse problema, e mesmo que o programa possa parecer dar a saída correta, a saída vem da memória que havia sido liberada.

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

## <a name="marshaling-arguments"></a>Argumentos de Marechal

Com `PInvoke`, não é necessário empacotar entre os tipos primitivos nativos gerenciados e C++ com a mesma forma. Por exemplo, não é necessário empacotar entre Int32 e int, ou entre duplo e duplo.

No entanto, você deve marshal tipos que não têm a mesma forma. Isso inclui tipos de char, string e struct. A tabela a seguir mostra os mapeamentos utilizados pelo marshaler para vários tipos:

|wtypes.h|Visual C++|Visual C++ com /clr|Common Language Runtime|
|--------------|------------------|-----------------------------|-----------------------------|
|Lidar com|Vazio\*|Vazio\*|IntPtr|
|BYTE|unsigned char|unsigned char|Byte|
|SHORT|short|short|Int16|
|WORD|unsigned short|unsigned short|UInt16|
|INT|INT|INT|Int32|
|UINT|unsigned int|unsigned int|UInt32|
|LONG|long|long|Int32|
|BOOL|long|bool|Boolean|
|DWORD|unsigned long|unsigned long|UInt32|
|Ulong|unsigned long|unsigned long|UInt32|
|CHAR|char|char|Char|
|LPSTR|Char\*|String ^ [in], StringBuilder ^ [dentro, fora]|String ^ [in], StringBuilder ^ [dentro, fora]|
|LPCSTR|const char\*|String ^|String|
|LPWSTR|wchar_t \*|String ^ [in], StringBuilder ^ [dentro, fora]|String ^ [in], StringBuilder ^ [dentro, fora]|
|LPCWSTR|const wchar_t\*|String ^|String|
|FLOAT|FLOAT|FLOAT|Single|
|DOUBLE|double|double|Double|

O marshaler fixa automaticamente a memória alocada no heap de tempo de execução se seu endereço for passado para uma função não gerenciada. A fixação impede que o coletor de lixo mova o bloco alocado de memória durante a compactação.

No exemplo mostrado anteriormente neste tópico, o parâmetro CharSet do DllImport especifica como as strings gerenciadas devem ser empacotadas; neste caso, eles devem ser marshaled para ansi strings para o lado nativo.

Você pode especificar informações de empacotamento para argumentos individuais de uma função nativa usando o atributo MarshalAs. Existem várias opções \* para empacotar um argumento string: BStr, ANSIBStr, TBStr, LPStr, LPWStr e LPTStr. O padrão é LPStr.

Neste exemplo, a seqüência é empacotada como uma seqüência de caracteres Unicode de byte duplo, LPWStr. A saída é a primeira letra do Hello World! porque o segundo byte da seqüência de comando é nulo, e coloca interpreta isso como o marcador de fim de corda.

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

O atributo MarshalAs está no espaço de nome System::Runtime::InteropServices. O atributo pode ser usado com outros tipos de dados, como arrays.

Como mencionado anteriormente no tópico, a biblioteca de marshaling fornece um novo método otimizado de empacotar dados entre ambientes nativos e gerenciados. Para obter mais informações, consulte [Visão geral do Marshaling em C++](../dotnet/overview-of-marshaling-in-cpp.md).

## <a name="performance-considerations"></a>Considerações sobre desempenho

PInvoke tem uma sobrecarga entre 10 e 30 x86 instruções por chamada. Além desse custo fixo, o marshaling cria despesas adicionais. Não há custo de empacotamento entre tipos blittable que têm a mesma representação em código gerenciado e não gerenciado. Por exemplo, não há custo para traduzir entre int e Int32.

Para um melhor desempenho, tenha menos chamadas PInvoke que marshal o máximo de dados possível, em vez de mais chamadas que marechal menos dados por chamada.

## <a name="see-also"></a>Confira também

[Nativo e interoperabilidade .NET](../dotnet/native-and-dotnet-interoperability.md)
