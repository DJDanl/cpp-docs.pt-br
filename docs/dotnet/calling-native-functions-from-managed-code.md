---
title: Chamando funções nativas do código gerenciado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- native functions called from managed code [C++]
- managed code [C++], interoperability
- platform invoke [C++], interoperability
- interoperabiliy [C++], calling native functions from managed code
- calling native functions from managed code
- interop [C++], calling native functions from managed code
ms.assetid: 982cef18-20d9-42b4-8242-a77fa65f2e36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3ef47e3aeb8cfb18dd1eb6497c593d8cec26081b
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43678444"
---
# <a name="calling-native-functions-from-managed-code"></a>Chamando funções nativas a partir do código gerenciado
O common language runtime fornece serviços de invocação de plataforma, ou PInvoke, que permite que código gerenciado chame funções de estilo C em nativas bibliotecas de vínculo dinâmico (DLLs). Os mesmo empacotamento de dados são usados para a interoperabilidade COM o tempo de execução e para o mecanismo IJW, ou "Simplesmente funciona".  
  
 Para obter mais informações, consulte:  
  
-   [Usando PInvoke explícito no C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)  
  
-   [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)  
  
 Os exemplos nesta seção só ilustram como `PInvoke` pode ser usado. `PInvoke` pode simplificar o empacotamento de dados personalizados porque você fornece informações de empacotamento declarativamente em atributos em vez de escrever o código procedural.  
  
> [!NOTE]
>  A biblioteca de marshaling fornece uma maneira alternativa de realizar marshaling de dados entre ambientes nativos e gerenciados de forma otimizada. Ver [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre a biblioteca de marshaling. A biblioteca de marshaling é útil somente para dados e não para funções.  
  
## <a name="pinvoke-and-the-dllimport-attribute"></a>PInvoke e o atributo DllImport  
 O exemplo a seguir mostra o uso de `PInvoke` em um programa do Visual C++. A função nativa puts é definida em Msvcrt. dll. O atributo DllImport é usado para a declaração de puts.  
  
```  
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
  
```  
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
  
-   Não é necessário gravar `DLLImport` declarações para as APIs não gerenciadas que usa o programa de atributo. Apenas inclua o arquivo de cabeçalho e o link com a biblioteca de importação.  
  
-   O mecanismo do IJW é ligeiramente mais rápido (por exemplo, os modelos do IJW não é necessário verificar se há a necessidade de fixar ou copiar itens de dados porque isso é feito explicitamente pelo desenvolvedor).  
  
-   Ele ilustra claramente problemas de desempenho. Nesse caso, o fato de você está traduzindo a partir de uma cadeia de caracteres Unicode para uma cadeia de caracteres ANSI e que você tem uma alocação de memória e desalocação. Nesse caso, um desenvolvedor escreve o código usando IJW perceberia que chamar `_putws` e usando `PtrToStringChars` seria melhor para o desempenho.  
  
-   Se você chamar várias APIs não gerenciadas usando os mesmos dados, empacotá-las uma vez e passar a cópia empacotada é muito mais eficiente do que reempacotar todas as vezes.  
  
### <a name="disadvantages-of-ijw"></a>Desvantagens de IJW  
  
-   Marshaling deve ser especificado explicitamente no código, em vez de por atributos (que geralmente têm padrões apropriados).  
  
-   O código de empacotamento é embutido, onde é mais invasivo no fluxo da lógica do aplicativo.  
  
-   Como as APIs de marshaling explícitas retornam `IntPtr` tipos para fins de portabilidade de 32 bits para 64 bits, você deve usar extra `ToPointer` chamadas.  
  
 O método específico exposto pelo C++ é o método mais eficiente e explícito, às custas de alguma complexidade adicional.  
  
 Se o aplicativo usa principalmente os tipos de dados não gerenciados ou se ele chamar mais APIs não gerenciadas que APIs do .NET Framework, recomendamos que você use o recurso IJW. Para chamar uma API não gerenciada casual em um aplicativo basicamente gerenciado, a opção é mais sutil.  
  
## <a name="pinvoke-with-windows-apis"></a>PInvoke com APIs do Windows  
 PInvoke é conveniente para chamar funções no Windows.  
  
 Neste exemplo, um programa do Visual C++ interopera com a função MessageBox que faz parte da API do Win32.  
  
```  
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
  
 A saída é uma caixa de mensagem que tem o teste de PInvoke do título e contém o texto Olá, mundo!.  
  
 As informações de marshaling também são usadas por PInvoke para pesquisar funções na DLL. No User32. dll não existe na verdade nenhuma função MessageBox, mas CharSet = charset:: ANSI permite PInvoke a usar MessageBoxA, a versão ANSI, em vez de MessageBoxW, que é a versão Unicode. Em geral, é recomendável que você use versões Unicode dessas APIs não gerenciadas porque isso elimina a sobrecarga de tradução do formato nativo Unicode de objetos de cadeia de caracteres do .NET Framework para ANSI.  
  
## <a name="when-not-to-use-pinvoke"></a>Quando não usar PInvoke  
 Usando PInvoke não é apropriado para todas as funções de estilo C em DLLs. Por exemplo, suponha que haja é uma função MakeSpecial em myLib. dll declarada da seguinte maneira:  
  
 `char * MakeSpecial(char * pszString);`  
  
 Se usarmos PInvoke em um aplicativo do Visual C++, nós podemos escrever algo semelhante ao seguinte:  
  
 `[DllImport("mylib")]`  
  
 `extern "C" String * MakeSpecial([MarshalAs(UnmanagedType::LPStr)] String ^);`  
  
 A dificuldade aqui é que nós não podemos excluir a memória para a cadeia de caracteres não gerenciada retornada por MakeSpecial. Outras funções chamadas por meio do PInvoke retornam um ponteiro para um buffer interno que não precisa ser desalocada pelo usuário. Nesse caso, usando o recurso IJW é a opção óbvia.  
  
## <a name="limitations-of-pinvoke"></a>Limitações de PInvoke  
 Você não pode retornar o mesmo ponteiro exato de uma função nativa que você recebe como um parâmetro. Se uma função nativa retorna o ponteiro que foi empacotado a ela pelo PInvoke, corrupção de memória e exceções podem surgir.  
  
```  
__declspec(dllexport)  
char* fstringA(char* param) {  
   return param;  
}  
```  
  
 O exemplo a seguir exibe este problema e, mesmo que o programa aparentemente ofereça a entrada correta, a saída está vindo da memória que foi liberada.  
  
```  
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
  
## <a name="marshaling-arguments"></a>Argumentos marshaling  
 Com `PInvoke`, nenhum empacotamento é necessário entre gerenciados e tipos primitivos de nativos de C++ com o mesmo formulário. Por exemplo, nenhum marshaling é necessário entre Int32 e int ou entre Double e double.  
  
 No entanto, você deve realizar marshaling de tipos que não têm o mesmo formulário. Isso inclui tipos char, string e struct. A tabela a seguir mostra os mapeamentos usados pelo empacotador para vários tipos:  
  
|wtypes. h|Visual C++|Visual C++ com /clr|Common Language Runtime|  
|--------------|------------------|-----------------------------|-----------------------------|  
|IDENTIFICADOR|void \*|void \*|IntPtr, UIntPtr|  
|BYTE|unsigned char|unsigned char|Byte|  
|CURTO|short|short|Int16|  
|WORD|unsigned short|unsigned short|UInt16|  
|INT|int|int|Int32|  
|UINT|unsigned int|unsigned int|UInt32|  
|LONG|long|long|Int32|  
|BOOL|long|bool|Boolean|  
|DWORD|unsigned long|unsigned long|UInt32|  
|ULONG|unsigned long|unsigned long|UInt32|  
|CHAR|char|char|Char|  
|LPCSTR|Char \*|Cadeia de caracteres ^ [in], StringBuilder ^ [no, out]|Cadeia de caracteres ^ [in], StringBuilder ^ [no, out]|  
|LPCSTR|Const char \*|Cadeia de caracteres ^|Cadeia de Caracteres|  
|LPWSTR|wchar_t \*|Cadeia de caracteres ^ [in], StringBuilder ^ [no, out]|Cadeia de caracteres ^ [in], StringBuilder ^ [no, out]|  
|LPCWSTR|Const wchar_t \*|Cadeia de caracteres ^|Cadeia de Caracteres|  
|FLOAT|float|float|Simples|  
|DUPLA|double|double|Duplo|  
  
 O empacotador fixará automaticamente a memória alocada no heap de tempo de execução se seu endereço for passado para uma função não gerenciada. A fixação impede que o coletor de lixo mover o bloco de memória alocado durante a compactação.  
  
 No exemplo mostrado anteriormente neste tópico, o parâmetro de CharSet do DllImport Especifica cadeias de caracteres gerenciadas como deve ser empacotado; Nesse caso, eles devem ser empacotados para cadeias de caracteres ANSI para o lado nativo.  
  
 Você pode especificar informações de marshaling para argumentos individuais de uma função nativa usando o atributo MarshalAs. Há várias opções de marshaling de uma cadeia de caracteres \* argumento: BStr, ANSIBStr, TBStr, LPStr, LPWStr e LPTStr. O padrão é LPStr.  
  
 Neste exemplo, a cadeia de caracteres é empacotada como uma cadeia de caracteres de Unicode de dois bytes, LPWStr. A saída é a primeira letra de Hello World! porque o segundo byte de cadeia de caracteres empacotada é nulo e coloca interpreta isso como o marcador de fim da cadeia de caracteres.  
  
```  
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
  
 Conforme mencionado anteriormente no tópico, a biblioteca de marshaling fornece um método novo e otimizado de marshaling dos dados entre ambientes nativos e gerenciados. Para obter mais informações, consulte [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md).  
  
## <a name="performance-considerations"></a>Considerações sobre desempenho  
 PInvoke tem uma sobrecarga entre 10 e 30 x86 instruções por chamada. Além desse custo fixo, marshaling cria uma sobrecarga adicional. Não há nenhum custo de marshaling entre tipos blittable que têm a mesma representação em código gerenciado e não gerenciado. Por exemplo, não há nenhum custo para converter entre int e Int32.  
  
 Para obter melhor desempenho, ter menos chamadas de PInvoke que empacotar a quantidade de dados possível, em vez de mais chamadas que menos dados por chamada de marshaling.  
  
## <a name="see-also"></a>Consulte também  
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)