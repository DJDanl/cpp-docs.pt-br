---
title: Arquivos .netmodule como entrada de vinculador
ms.date: 05/16/2019
helpviewer_keywords:
- MSIL linking
- linking [C++], modules
- .netmodules
- modules, Visual C++
ms.assetid: a4bcbe8a-4255-451d-853b-f88cfd82f4e1
ms.openlocfilehash: 50a0f0a1ff5f65a7512e8372de2fe5296c866dca
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837432"
---
# <a name="netmodule-files-as-linker-input"></a>Arquivos .netmodule como entrada de vinculador

link.exe agora aceita .obj e .netmodules da MSIL como entrada. O arquivo de saída produzido pelo vinculador é um assembly ou um .netmodule sem dependência em tempo de execução de nenhum dos .netmodules ou .obj de entrada para o vinculador.

.netmodules são criados pelo compilador do MSVC com [/LN (Criar módulo da MSIL)](ln-create-msil-module.md) ou pelo vinculador com [/NOASSEMBLY (Criar um módulo da MSIL)](noassembly-create-a-msil-module.md). .objs são sempre criados em uma compilação do Visual C++. Para outros compiladores do Visual Studio, use a opção do compilador **/target:module**.

É necessário passar para o vinculador o arquivo .obj da compilação do Visual C++ que criou o .netmodule. Não há mais suporte para a passagem de um .netmodule, porque as opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior.

Para obter informações sobre como invocar o vinculador na linha de comando, confira [Sintaxe de linha de comando do vinculador](linking.md), [Usar o Conjunto de ferramentas do MSVC na linha de comando](../building-on-the-command-line.md) e [Definir o caminho e as variáveis de ambiente para builds de linha de comando](../setting-the-path-and-environment-variables-for-command-line-builds.md).

Passar um arquivo .dll ou .netmodule para o vinculador que foi compilado pelo compilador do MSVC com **/clr** poderá resultar em um erro do vinculador. Para obter mais informações, confira [Como escolher o formato dos arquivos de entrada .netmodule](choosing-the-format-of-netmodule-input-files.md).

O vinculador aceita arquivos .obj nativos, bem como arquivos .obj da MSIL compilados com **/clr**. Ao passar .objs mistos no mesmo build, a capacidade de verificação do arquivo de saída resultante, por padrão, será igual ao nível mais baixo da capacidade de verificação dos módulos de entrada.

Se, atualmente, você tiver um aplicativo que seja composto por dois ou mais assemblies e desejar que o aplicativo fique contido em um assembly, recompile os assemblies e, em seguida, vincule os .objs ou os .netmodules para produzir um único assembly.

É necessário especificar um ponto de entrada usando [/ENTRY (Símbolo de ponto de entrada)](entry-entry-point-symbol.md) durante a criação de uma imagem executável.

Durante a vinculação com um arquivo .obj ou .netmodule da MSIL, use [/LTCG (Geração de Código Durante o Tempo de Vinculação)](ltcg-link-time-code-generation.md); caso contrário, quando o vinculador encontrar o .obj ou o .netmodule da MSIL, ele reiniciará a vinculação com /LTCG.

Os arquivos .obj ou .netmodule da MSIL também podem ser passados para cl.exe.

Os arquivos de entrada .obj ou .netmodule da MSIL não podem ter recursos inseridos. Um recurso é inserido em um arquivo de saída (módulo ou assembly) com a opção do vinculador [/ASSEMBLYRESOURCE (Inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md) ou com a opção do compilador **/resource** em outros compiladores do Visual Studio.

Ao executar a vinculação da MSIL e se você não especificar também [/LTCG (Geração de Código Durante o Tempo de Vinculação)](ltcg-link-time-code-generation.md), verá uma mensagem informativa relatando que a vinculação está sendo reiniciada. Essa mensagem pode ser ignorada, mas para melhorar o desempenho com a vinculação da MSIL, especifique **/LTCG** explicitamente.

## <a name="example"></a>Exemplo

No código C++, o bloco **catch** de um **try** correspondente será invocado para uma exceção que não seja do sistema. No entanto, por padrão, o CLR encapsula as exceções que não são do sistema com <xref:System.Runtime.CompilerServices.RuntimeWrappedException>. Quando um assembly for criado com base em módulos do Visual C++ e não Visual C++ e você desejar que um bloco **catch** no código C++ seja invocado de sua cláusula **try** correspondente quando o bloco **try** gerar uma exceção que não seja do sistema, você precisará adicionar o atributo `[assembly:System::Runtime::CompilerServices::RuntimeCompatibility(WrapNonExceptionThrows=false)]` ao código-fonte para esses módulos que não são do C++.

```cpp
// MSIL_linking.cpp
// compile with: /c /clr
value struct V {};

ref struct MCPP {
   static void Test() {
      try {
         throw (gcnew V);
      }
      catch (V ^) {
         System::Console::WriteLine("caught non System exception in C++ source code file");
      }
   }
};

/*
int main() {
   MCPP::Test();
}
*/
```

## <a name="example"></a>Exemplo

Alterando o valor booliano do atributo `WrapNonExceptionThrows`, você modifica a capacidade de o código do Visual C++ capturar uma exceção que não seja do sistema.

```cpp
// MSIL_linking_2.cs
// compile with: /target:module /addmodule:MSIL_linking.obj
// post-build command: link /LTCG MSIL_linking.obj MSIL_linking_2.netmodule /entry:MLinkTest.Main /out:MSIL_linking_2.exe /subsystem:console
using System.Runtime.CompilerServices;

// enable non System exceptions
[assembly:RuntimeCompatibility(WrapNonExceptionThrows=false)]

class MLinkTest {
   public static void Main() {
      try {
         MCPP.Test();
      }
      catch (RuntimeWrappedException) {
         System.Console.WriteLine("caught a wrapped exception in C#");
      }
   }
}
```

```Output
caught non System exception in C++ source code file
```

## <a name="see-also"></a>Consulte também

- [Arquivos de entrada de LINK](link-input-files.md)
- [Opções de vinculador MSVC](linker-options.md)
