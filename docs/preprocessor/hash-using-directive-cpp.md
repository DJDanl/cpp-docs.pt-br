---
title: '#usando a diretivaC++(/CLI)'
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
ms.openlocfilehash: 5dae5c277055157aef5451c19ee020fbbd2aaccb
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220204"
---
# <a name="using-directive-ccli"></a>Diretiva de #usingC++(/CLI)

Importa metadados para um programa compilado com [/CLR](../build/reference/clr-common-language-runtime-compilation.md).

## <a name="syntax"></a>Sintaxe

> **#using** do *arquivo* [**as_friend**]

### <a name="parameters"></a>Parâmetros

*Grupo*\
Um MSIL .dll, .exe, .netmodule ou .obj. Por exemplo,

`#using <MyComponent.dll>`

**as_friend**\
Especifica que todos os tipos no *arquivo* estão acessíveis. Para obter mais informações, consulte [Friend AssembliesC++()](../dotnet/friend-assemblies-cpp.md).

## <a name="remarks"></a>Comentários

o *arquivo* pode ser um arquivo MSIL (Microsoft Intermediate Language) que você importa para seus dados gerenciados e construções gerenciadas. Se um arquivo. dll contiver um manifesto do assembly, todas as. DLLs referenciadas no manifesto serão importadas e o assembly que você está criando listará o *arquivo* nos metadados como uma referência de assembly.

Se o *arquivo* não contiver um assembly (se o *arquivo* for um módulo) e se você não pretender usar informações de tipo do módulo no aplicativo atual (assembly), terá a opção de apenas indicar que o módulo é parte do assembly; Use [/ASSEMBLYMODULE](../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md). Então, os tipos no módulo estariam disponíveis para qualquer aplicativo que fizesse referência ao assembly.

Uma alternativa para usar **#using** é a opção de compilador [/Fu](../build/reference/fu-name-forced-hash-using-file.md) .

os assemblies. exe passados para **#using** devem ser compilados usando um dos compiladores do .NET Visual Studio (Visual Basic ou C#Visual, por exemplo).  Tentar importar metadados de um assembly .exe compilado com `/clr` resultará em uma exceção de carregamento de arquivo.

> [!NOTE]
> Um componente que é referenciado com **#using** pode ser executado com uma versão diferente do arquivo importado no momento da compilação, fazendo com que um aplicativo cliente forneça resultados inesperados.

Para que o compilador reconheça um tipo em um assembly (não um módulo), ele precisa ser forçado a resolver o tipo. Você pode forçá-lo, por exemplo, definindo uma instância do tipo. Há outras maneiras de resolver nomes de tipo em um assembly para o compilador. Por exemplo, se você herdar de um tipo em um assembly, o nome do tipo se tornará conhecido pelo compilador.

Ao importar metadados criados a partir do código-fonte que usaram [_ declspec (thread)](../cpp/thread.md), a semântica do thread não é mantida nos metadados. Por exemplo, uma variável declarada com **_ declspec (thread)** , compilada em um programa que é criado para o .NET Framework Common Language Runtime e, em seguida, importada via **#using**, não terá a semântica **_ _ declspec (thread)** na variável.

Todos os tipos importados (gerenciados e nativos) em um arquivo referenciado por **#using** estão disponíveis, mas o compilador trata tipos nativos como declarações, não definições.

mscorlib.dll é referenciado automaticamente durante a compilação com `/clr`.

A variável de ambiente LIBPATH especifica os diretórios a serem pesquisados quando o compilador resolve nomes de arquivo passados para **#using**.

O compilador procura referências ao longo do seguinte caminho:

- Um caminho especificado na instrução **#using** .

- O diretório atual.

- O diretório do sistema do .NET Framework.

- Diretórios adicionados com a opção de compilador [/ai](../build/reference/ai-specify-metadata-directories.md) .

- Diretórios na variável de ambiente LIBPATH.

## <a name="example"></a>Exemplo

Se você criar um assembly (C) e referenciar um assembly (B) que, por sua vez, faz referência a outro assembly (A), não terá de referenciar explicitamente o assembly A, a menos que você use explicitamente um dos tipos de A em C.

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

No exemplo a seguir, não há nenhum erro do compilador para não fazer referência a *using_assembly_A. dll*, pois o programa não usa nenhum dos tipos definidos em *using_assembly_A. cpp*.

```cpp
// using_assembly_C.cpp
// compile with: /clr
#using "using_assembly_B.dll"
int main() {
   B b;
   b.Test();
}
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
