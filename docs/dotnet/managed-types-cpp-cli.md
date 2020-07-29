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
ms.openlocfilehash: c542151bda780e5306db35049d988e6514fffd62
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225599"
---
# <a name="managed-types-ccli"></a>Tipos gerenciados (C++/CLI)

Visual C++ permite o acesso a recursos do .NET por meio de tipos gerenciados, que fornecem suporte para recursos do Common Language Runtime e estão sujeitos às vantagens e restrições do tempo de execução.

## <a name="managed-types-and-the-main-function"></a><a name="main_functions"></a>Tipos gerenciados e a função main

Ao gravar um aplicativo usando **`/clr`** , os argumentos da função **Main ()** não podem ser de um tipo gerenciado.

Um exemplo de uma assinatura apropriada é:

```cpp
// managed_types_and_main.cpp
// compile with: /clr
int main(int, char*[], char*[]) {}
```

## <a name="net-framework-equivalents-to-c-native-types"></a><a name="dotnet"></a>.NET Framework equivalentes a tipos nativos do C++

A tabela a seguir mostra as palavras-chave para tipos de Visual C++ internos, que são aliases de tipos predefinidos no namespace **System** .

|Tipo de Visual C++|Tipo de .NET Framework|
|-----------------------|-------------------------|
|**`void`**|<xref:System.Void?displayProperty=nameWithType>|
|**`bool`**|<xref:System.Boolean?displayProperty=nameWithType>|
|**`signed char`** |<xref:System.SByte?displayProperty=nameWithType>|
|**`unsigned char`**|<xref:System.Byte?displayProperty=nameWithType>|
|**`wchar_t`**|<xref:System.Char?displayProperty=nameWithType>|
|**`short`** e**`signed short`**|<xref:System.Int16?displayProperty=nameWithType>|
|**`unsigned short`**|<xref:System.UInt16?displayProperty=nameWithType>|
|**`int`**, **`signed int`** , **`long`** e**`signed long`**|<xref:System.Int32?displayProperty=nameWithType>|
|**`unsigned int`** e**`unsigned long`**|<xref:System.UInt32?displayProperty=nameWithType>|
|**`__int64`** e**`signed __int64`**|<xref:System.Int64?displayProperty=nameWithType>|
|**`unsigned __int64`**|<xref:System.UInt64?displayProperty=nameWithType>|
|**`float`**|<xref:System.Single?displayProperty=nameWithType>|
|**`double`** e**`long double`**|<xref:System.Double?displayProperty=nameWithType>|

Para obter mais informações sobre a opção do compilador como padrão para **`signed char`** ou **`unsigned char`** , consulte [ `/J` (o **`char`** tipo padrão é **`unsigned`** )](../build/reference/j-default-char-type-is-unsigned.md).

## <a name="version-issues-for-value-types-nested-in-native-types"></a><a name="version_issues"></a>Problemas de versão para tipos de valor aninhados em tipos nativos

Considere um componente de assembly assinado (nome forte) usado para criar um assembly de cliente. O componente contém um tipo de valor que é usado no cliente como o tipo para um membro de uma União nativa, uma classe ou uma matriz. Se uma versão futura do componente alterar o tamanho ou o layout do tipo de valor, o cliente deverá ser recompilado.

Crie um keyfile com [sn.exe](/dotnet/framework/tools/sn-exe-strong-name-tool) ( `sn -k mykey.snk` ).

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

No entanto, se você adicionar outro membro a `struct S` no nested_value_types. cpp, (por exemplo, `double d;` ) e recompilar o componente sem recompilar o cliente, o resultado será uma exceção sem tratamento (do tipo <xref:System.IO.FileLoadException?displayProperty=fullName> ).

## <a name="how-to-test-for-equality"></a><a name="test_equality"></a>Como: testar a igualdade

No exemplo a seguir, um teste para igualdade que usa Managed Extensions for C++ é baseado no que os identificadores se referem.

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

O IL para este programa mostra que o valor de retorno é implementado usando uma chamada para op_Equality.

```MSIL
IL_0012:  call       bool [mscorlib]System.String::op_Equality(string,
                                                               string)
```

## <a name="how-to-diagnose-and-fix-assembly-compatibility-problems"></a><a name="diagnose_fix"></a>Como: diagnosticar e corrigir problemas de compatibilidade de assembly

Este tópico explica o que pode acontecer quando a versão de um assembly referenciada em tempo de compilação não corresponde à versão do assembly referenciada em tempo de execução e como evitar o problema.

Quando um assembly é compilado, outros assemblies podem ser referenciados com a `#using` sintaxe. Durante a compilação, esses assemblies são acessados pelo compilador. As informações desses assemblies são usadas para tomar decisões de otimização.

No entanto, se o assembly referenciado for alterado e recompilado, e você não recompilar o assembly de referência dependente dele, os assemblies talvez ainda não sejam compatíveis. As decisões de otimização que eram válidas a princípio podem não estar corretas em relação à nova versão do assembly. Vários erros de tempo de execução podem ocorrer devido a essas incompatibilidades. Não há nenhuma exceção específica que será produzida nesses casos. A maneira como a falha é relatada em tempo de execução depende da natureza da alteração do código que causou o problema.

Esses erros não devem ser um problema em seu código de produção final, desde que todo o aplicativo seja recriado para a versão de lançamento do seu produto. Os assemblies que são liberados para o público devem ser marcados com um número de versão oficial, o que garantirá que esses problemas sejam evitados. Para obter mais informações, consulte [Controle de versão do assembly](/dotnet/framework/app-domains/assembly-versioning).

### <a name="diagnosing-and-fixing-an-incompatibility-error"></a>Diagnosticando e corrigindo um erro de incompatibilidade

1. Se você encontrar exceções de tempo de execução ou outras condições de erro que ocorrem no código que referenciam outro assembly e não tiverem outra causa identificada, você pode estar lidando com um assembly desatualizado.

1. Primeiro, isole e reproduza a exceção ou outra condição de erro. Um problema que ocorre devido a uma exceção desatualizada deve ser reproduzível.

1. Verifique o carimbo de data/hora de quaisquer assemblies referenciados em seu aplicativo.

1. Se os carimbos de hora de quaisquer assemblies referenciados forem posteriores ao carimbo de data/hora da última compilação do seu aplicativo, o aplicativo estará desatualizado. Se isso ocorrer, recompile seu aplicativo com o assembly mais recente e faça as alterações de código necessárias.

1. Execute novamente o aplicativo, execute as etapas que reproduzem o problema e verifique se a exceção não ocorre.

### <a name="example"></a>Exemplo

O programa a seguir ilustra o problema reduzindo a acessibilidade de um método e tentando acessar esse método em outro assembly sem recompilação. Tente compilar `changeaccess.cpp` primeiro. Esse é o assembly referenciado que será alterado. Em seguida, compile `referencing.cpp` . A compilação é realizada com sucesso. Agora, reduza a acessibilidade do método chamado. Recompile `changeaccess.cpp` com o sinalizador `/DCHANGE_ACCESS` . Isso torna o método protegido, em vez de privado, para que ele possa mais ser chamado legalmente. Sem recompilar `referencing.exe` , execute novamente o aplicativo. <xref:System.MethodAccessException>Ocorrerá uma exceção.

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

## <a name="see-also"></a>Confira também

[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Interoperabilidade com outras linguagens .NET (C++/CLI)](../dotnet/interoperability-with-other-dotnet-languages-cpp-cli.md)<br/>
[Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)<br/>
[#using diretiva](../preprocessor/hash-using-directive-cpp.md)
