---
title: Tipos gerenciados (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- data types [C++], managed
- managed data types [C++]
- .NET Framework [C++], managed types
- data types [C++], .NET feature access
- main function, in managed applications
- managed code, main() function
- .NET Framework [C++], C++ equivalents
- __nogc type declarations
- __value keyword, issues when nesting
- equality, testing for
- versioning, diagnosing conflicts
- versioning
- exceptions, diagnosing odd behavior
- compatibility, between assemblies
ms.assetid: 679b8ed3-d966-4a0c-b627-2a3f3ec96b74
ms.openlocfilehash: b91918d526d83d4cf47436d02b7c67038576bafb
ms.sourcegitcommit: 42e65c171aaa17a15c20b155d22e3378e27b4642
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2019
ms.locfileid: "58356173"
---
# <a name="managed-types-ccli"></a>Tipos gerenciados (C++/CLI)

Visual C++ permite acesso a recursos do .NET por meio de tipos gerenciados que dão suporte para recursos do common language runtime e estão sujeitos às vantagens e as restrições de tempo de execução.

## <a name="main_functions"></a> Tipos gerenciados e a função principal

Ao escrever um aplicativo usando **/clr**, os argumentos da **Main ()** função não pode ser de um tipo gerenciado.

É um exemplo de uma assinatura apropriada:

```cpp
// managed_types_and_main.cpp
// compile with: /clr
int main(int, char*[], char*[]) {}
```

## <a name="dotnet"></a> Equivalentes do .NET framework aos tipos nativos do C++

A tabela a seguir mostra as palavras-chave para tipos internos do Visual C++, que são aliases de tipos predefinidos na **sistema** namespace.

|Tipo de Visual C++|Tipo do .NET Framework|
|-----------------------|-------------------------|
|**void**|<xref:System.Void?displayProperty=nameWithType>|
|**bool**|<xref:System.Boolean?displayProperty=nameWithType>|
|**signed char** |<xref:System.SByte?displayProperty=nameWithType>|
|**unsigned char**|<xref:System.Byte?displayProperty=nameWithType>|
|**wchar_t**|<xref:System.Char?displayProperty=nameWithType>|
|**curto** e **1&gt;signed**|<xref:System.Int16?displayProperty=nameWithType>|
|**unsigned short**|<xref:System.UInt16?displayProperty=nameWithType>|
|**int**, **assinado int**, **longo**, e **assinado longa**|<xref:System.Int32?displayProperty=nameWithType>|
|**int sem sinal** e **unsigned long**|<xref:System.UInt32?displayProperty=nameWithType>|
|**__int64** e **assinado __int64**|<xref:System.Int64?displayProperty=nameWithType>|
|**unsigned __int64**|<xref:System.UInt64?displayProperty=nameWithType>|
|**float**|<xref:System.Single?displayProperty=nameWithType>|
|**duplo** e **longo duplo**|<xref:System.Double?displayProperty=nameWithType>|

Para obter mais informações sobre a opção de compilador padrão para com ou sem sinal **char**, consulte [/J (o tipo char padrão é sem sinal)](../build/reference/j-default-char-type-is-unsigned.md).

## <a name="version_issues"></a> Problemas de versão para tipos de valor aninhados em tipos nativos

Considere a possibilidade de um componente de assembly assinado (nome forte) usado para criar um assembly de cliente. O componente contém um tipo de valor que é usado no cliente como o tipo para um membro de uma união nativa, uma classe ou uma matriz. Se uma versão futura do componente mudar o tamanho ou o layout do tipo de valor, o cliente deverá ser recompilado.

Criar um keyfile com [sn.exe](/dotnet/framework/tools/sn-exe-strong-name-tool) (`sn -k mykey.snk`).

### <a name="example"></a>Exemplo

O exemplo a seguir é o componente.

```cpp
// nested_value_types.cpp
// compile with: /clr /LD
using namespace System::Reflection;
[assembly:AssemblyVersion("1.0.0.*"),
assembly:AssemblyKeyFile("mykey.snk")];

public value struct S {
   int i;
   void Test() {
      System::Console::WriteLine("S.i = {0}", i);
   }
};
```

### <a name="example"></a>Exemplo

Este exemplo é o cliente:

```cpp
// nested_value_types_2.cpp
// compile with: /clr
#using <nested_value_types.dll>

struct S2 {
   S MyS1, MyS2;
};

int main() {
   S2 MyS2a, MyS2b;
   MyS2a.MyS1.i = 5;
   MyS2a.MyS2.i = 6;
   MyS2b.MyS1.i = 10;
   MyS2b.MyS2.i = 11;

   MyS2a.MyS1.Test();
   MyS2a.MyS2.Test();
   MyS2b.MyS1.Test();
   MyS2b.MyS2.Test();
}
```

### <a name="output"></a>Saída

```Output
S.i = 5
S.i = 6
S.i = 10
S.i = 11
```

### <a name="comments"></a>Comentários

No entanto, se você adicionar outro membro para `struct S` em nested_value_types.cpp, (por exemplo, `double d;`) e recompilar o componente sem recompilar o cliente, o resultado é uma exceção sem tratamento (do tipo <xref:System.IO.FileLoadException?displayProperty=fullName>).

## <a name="test_equality"></a> Como: Testar a igualdade

No exemplo a seguir, um teste de igualdade que usa extensões gerenciadas para C++ com base no que se refere os identificadores.

### <a name="example"></a>Exemplo

```cpp
// mcppv2_equality_test.cpp
// compile with: /clr /LD
using namespace System;

bool Test1() {
   String ^ str1 = "test";
   String ^ str2 = "test";
   return (str1 == str2);
}
```

O IL para este programa mostra que o valor de retorno é implementado por meio de uma chamada para op_Equality.

```MSIL
IL_0012:  call       bool [mscorlib]System.String::op_Equality(string,
                                                               string)
```

## <a name="diagnose_fix"></a> Como: Diagnosticar e corrigir problemas de compatibilidade do Assembly

Este tópico explica o que pode acontecer quando a versão de um assembly referenciado em tempo de compilação não corresponde à versão do assembly referenciado em tempo de execução e como evitar o problema.

Quando um assembly é compilado, outros assemblies podem ser referenciados com o `#using` sintaxe. Durante a compilação, esses assemblies são acessados pelo compilador. Informações desses assemblies são usadas para tomar decisões de otimização.

No entanto, se o assembly referenciado é alterado e recompilado, e você não recompilar o assembly de referência que depende dele, os assemblies podem não ser ainda compatível. Decisões de otimização que eram válidas no primeiro podem não estar corretas em relação à nova versão do assembly. Vários erros de tempo de execução podem ocorrer devido a essas incompatibilidades. Não há nenhuma exceção específica que será produzida em tais casos. A maneira como a falha será relatada em tempo de execução depende da natureza da alteração de código que causou o problema.

Esses erros não devem ser um problema no seu código de produção final, desde que o aplicativo inteiro é reconstruído para a versão de lançamento do seu produto. Assemblies que são lançados ao público devem ser marcados com um número de versão oficial, que garante que esses problemas são evitados. Para obter mais informações, consulte [Controle de versão do assembly](/dotnet/framework/app-domains/assembly-versioning).

### <a name="diagnosing-and-fixing-an-incompatibility-error"></a>Diagnosticar e corrigir um erro de incompatibilidade

1. Se você encontrar exceções de tempo de execução ou outras condições de erro que ocorrem no código que faz referência a outro assembly e ter nenhuma outra causa identificada, talvez você esteja lidando com um assembly desatualizado.

1. Primeiro, isolar e reproduzir a exceção ou outra condição de erro. Um problema que ocorre devido a uma exceção desatualizada deve ser reproduzível.

1. Verifique o carimbo de hora de todos os assemblies referenciados em seu aplicativo.

1. Se os carimbos de hora de todos os assemblies referenciados forem posteriores ao carimbo de hora da última compilação de seu aplicativo, seu aplicativo está desatualizado. Se isso ocorrer, recompilar seu aplicativo com o assembly mais recente e fazer as alterações de código necessárias.

1. Executar novamente o aplicativo, execute as etapas que reproduzem o problema e verificar que a exceção não ocorre.

### <a name="example"></a>Exemplo

O programa a seguir ilustra o problema, reduzindo a acessibilidade de um método e tentar acessar esse método em outro assembly sem recompilar. Tente compilar `changeaccess.cpp` primeiro. Isso é o assembly referenciado que será alterado. Em seguida, compilar `referencing.cpp`. A compilação for bem-sucedida. Agora, reduza a acessibilidade do método chamado. Recompilar `changeaccess.cpp` com o sinalizador `/DCHANGE_ACCESS`. Isso torna o método protegido, em vez de particular, para que mais pode ser chamado legalmente. Sem recompilar `referencing.exe`, executar novamente o aplicativo. Uma exceção <xref:System.MethodAccessException> resultará.

```cpp
// changeaccess.cpp
// compile with: /clr:safe /LD
// After the initial compilation, add /DCHANGE_ACCESS and rerun
// referencing.exe to introduce an error at runtime. To correct
// the problem, recompile referencing.exe

public ref class Test {
#if defined(CHANGE_ACCESS)
protected:
#else
public:
#endif

  int access_me() {
    return 0;
  }

};
```

```cpp
// referencing.cpp
// compile with: /clr:safe
#using <changeaccess.dll>

// Force the function to be inline, to override the compiler's own
// algorithm.
__forceinline
int CallMethod(Test^ t) {
  // The call is allowed only if access_me is declared public
  return t->access_me();
}

int main() {
  Test^ t = gcnew Test();
  try
  {
    CallMethod(t);
    System::Console::WriteLine("No exception.");
  }
  catch (System::Exception ^ e)
  {
    System::Console::WriteLine("Exception!");
  }
  return 0;
}
```

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Interoperabilidade com outras linguagens .NET (C++/CLI)](../dotnet/interoperability-with-other-dotnet-languages-cpp-cli.md)<br/>
[Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)<br/>
[Diretiva #using](../preprocessor/hash-using-directive-cpp.md)
