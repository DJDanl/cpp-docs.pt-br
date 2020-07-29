---
title: '#Diretiva using (C++/CLI)'
ms.date: 08/29/2019
f1_keywords:
- friend_as_cpp
- '#using'
- friend_as
- '#using_cpp'
helpviewer_keywords:
- using directive (#using)
- '#using directive'
- LIBPATH environment variable
- preprocessor, directives
ms.assetid: 870b15e5-f361-40a8-ba1c-c57d75c8809a
ms.openlocfilehash: 0da255957e92a570750da2687bf1444df2e6ab13
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219424"
---
# <a name="using-directive-ccli"></a>diretiva #using (C++/CLI)

Importa metadados para um programa compilado com [/CLR](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="syntax"></a>Sintaxe

> **`#using`***arquivo* [ **`as_friend`** ]

### <a name="parameters"></a>parâmetros

*Grupo*\
Um arquivo MSIL (Microsoft Intermediate Language) *`.dll`* ,, *`.exe`* *`.netmodule`* ou *`.obj`* . Por exemplo:

`#using <MyComponent.dll>`

**`as_friend`**\
Especifica que todos os tipos no *arquivo* estão acessíveis. Para obter mais informações, consulte [Friend Assemblies (C++)](../dotnet/friend-assemblies-cpp.md).

## <a name="remarks"></a>Comentários

o *arquivo* pode ser um arquivo MSIL (Microsoft Intermediate Language) que você importa para seus dados gerenciados e construções gerenciadas. Se uma DLL contiver um manifesto do assembly, todas as DLLs referenciadas no manifesto serão importadas. O assembly que você está criando irá listar o *arquivo* nos metadados como uma referência de assembly.

Talvez o *arquivo* não contenha um assembly (*arquivo* é um módulo) e você não pretende usar informações de tipo do módulo no aplicativo (assembly) atual. Você pode indicar que o módulo faz parte do assembly usando [/ASSEMBLYMODULE](../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md). Então, os tipos no módulo estariam disponíveis para qualquer aplicativo que fizesse referência ao assembly.

Uma alternativa a usar **`#using`** é a opção de compilador [/Fu](../build/reference/fu-name-forced-hash-using-file.md) .

os assemblies. exe passados para **`#using`** devem ser compilados usando um dos compiladores do .NET Visual Studio (Visual Basic ou Visual C#, por exemplo).  A tentativa de importar metadados de um assembly. exe compilado com **`/clr`** resultará em uma exceção de carregamento de arquivo.

> [!NOTE]
> Um componente que é referenciado com **`#using`** o pode ser executado com uma versão diferente do arquivo importado no momento da compilação, fazendo com que um aplicativo cliente forneça resultados inesperados.

Para que o compilador reconheça um tipo em um assembly (não um módulo), ele precisa ser forçado a resolver o tipo. Você pode forçá-lo, por exemplo, definindo uma instância do tipo. Há outras maneiras de resolver nomes de tipo em um assembly para o compilador. Por exemplo, se você herdar de um tipo em um assembly, o nome do tipo se tornará conhecido pelo compilador.

Ao importar metadados criados a partir do código-fonte usado [`__declspec(thread)`](../cpp/thread.md) , a semântica de thread não é mantida nos metadados. Por exemplo, uma variável declarada com **`__declspec(thread)`** , compilada em um programa criado para o .NET Framework Common Language Runtime e, em seguida, importada por meio **`#using`** do, não terá **`__declspec(thread)`** semântica na variável.

Todos os tipos importados (gerenciados e nativos) em um arquivo referenciado pelo **`#using`** estão disponíveis, mas o compilador trata tipos nativos como declarações, não definições.

mscorlib.dll é referenciado automaticamente ao compilar com **`/clr`** .

A variável de ambiente LIBPATH especifica os diretórios a serem pesquisados quando o compilador resolve nomes de arquivo passados para **`#using`** .

O compilador procura referências ao longo do seguinte caminho:

- Um caminho especificado na **`#using`** instrução.

- O diretório atual.

- O diretório do sistema do .NET Framework.

- Diretórios adicionados com a [`/AI`](../build/reference/ai-specify-metadata-directories.md) opção do compilador.

- Diretórios na variável de ambiente LIBPATH.

## <a name="example"></a>Exemplo

Você pode criar um assembly que faz referência a um segundo assembly que, por sua vez, faz referência a um terceiro assembly. Você só precisa referenciar explicitamente o terceiro assembly do primeiro, se você usar explicitamente um de seus tipos.

```cpp
// using_assembly_A.cpp
// compile with: /clr /LD
public ref class A {};
```

## <a name="example"></a>Exemplo

```cpp
// using_assembly_B.cpp
// compile with: /clr /LD
#using "using_assembly_A.dll"
public ref class B {
public:
   void Test(A a) {}
   void Test() {}
};
```

## <a name="example"></a>Exemplo

No exemplo a seguir, o compilador não relata um erro sobre como referenciar *using_assembly_A.dll*, porque o programa não usa nenhum dos tipos definidos em *using_assembly_A. cpp*.

```cpp
// using_assembly_C.cpp
// compile with: /clr
#using "using_assembly_B.dll"
int main() {
   B b;
   b.Test();
}
```

## <a name="see-also"></a>Confira também

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)
