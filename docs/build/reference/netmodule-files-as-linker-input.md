---
title: .netmodule arquivos como entrada do vinculador
description: Descreve como usar mistos.obj e.netmodule arquivos como entrada de vinculador ao criar assemblies .NET.
ms.date: 01/30/2020
helpviewer_keywords:
- MSIL linking
- linking [C++], modules
- .netmodule files
- modules, Visual C++
ms.assetid: a4bcbe8a-4255-451d-853b-f88cfd82f4e1
no-loc:
- obj
- netmodule
- clr
- pure
- safe
ms.openlocfilehash: 83eab25624bdb81ba9191e4efe6a774551502ee0
ms.sourcegitcommit: c4528a7424d35039454f17778baf1b5f98fbbee7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2020
ms.locfileid: "76912824"
---
# <a name="opno-locnetmodule-files-as-linker-input"></a>.netmodule arquivos como entrada do vinculador

o link. exe aceita *`.obj`* MSIL e arquivos de *`.netmodule`* como entrada. O arquivo de saída produzido pelo vinculador é um assembly ou um arquivo de *`.netmodule`* sem dependência de tempo de execução em qualquer um dos arquivos *`.obj`* ou *`.netmodule`* que eram inseridos para o vinculador.

## <a name="remarks"></a>Comentários

*`.netmodule`* arquivos são criados pelo compilador MSVC com [/LN (módulo Create MSIL)](ln-create-msil-module.md) ou pelo vinculador com [/NOASSEMBLY (criar um módulo MSIL)](noassembly-create-a-msil-module.md). *`.obj`* arquivos são sempre criados em uma C++ compilação. Para outros compiladores do Visual Studio, use a opção do compilador **/target:module**.

O vinculador deve ser passado para o arquivo de`.obj`C++ da compilação que criou a *`.netmodule`* . Não há mais suporte para a passagem de um *`.netmodule`* porque o **/clr:pure** e **/clr:safe** opções do compilador foram preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017 e versões posteriores.

Para obter informações sobre como invocar o vinculador a partir da linha de comando, consulte [sintaxe de linha de comando do vinculador](linking.md), [usar o conjunto de ferramentas MSVC na linha de comando](../building-on-the-command-line.md)e [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../setting-the-path-and-environment-variables-for-command-line-builds.md).

Passar um arquivo de *`.netmodule`* ou *`.dll`* para o vinculador que foi compilado pelo compilador MSVC com **/clr** pode resultar em um erro de vinculador. Para obter mais informações, consulte [escolhendo o formato de.netmodule arquivos de entrada](choosing-the-format-of-netmodule-input-files.md).

O vinculador aceita arquivos de *`.obj`* nativos e arquivos MSIL *`.obj`* compilados com **/clr** . Você pode passar arquivos mistos *`.obj`* na mesma compilação. A verificação padrão do arquivo de saída resultante é igual à capacidade de verificação do módulo de entrada mais baixa.

Você pode alterar um aplicativo composto por dois ou mais assemblies que estão contidos em um assembly. Recompile as fontes dos assemblies e, em seguida, vincule os arquivos de *`.obj`* ou *`.netmodule`* arquivos para produzir um único assembly.

Especifique um ponto de entrada usando [/Entry (símbolo de ponto de entrada)](entry-entry-point-symbol.md) ao criar uma imagem executável.

Ao vincular com um *`.obj`* MSIL ou arquivo de *`.netmodule`* , use [/LTCG (geração de código de tempo de vinculação)](ltcg-link-time-code-generation.md), caso contrário, quando o vinculador encontrar o *`.obj`* MSIL ou *`.netmodule`* , ele reiniciará o link com **/LTCG**. Você verá uma mensagem informativa de que o link está reiniciando. Você pode ignorar essa mensagem, mas para melhorar o desempenho do vinculador, especifique explicitamente **/LTCG**.

Os arquivos *`.obj`* ou *`.netmodule`* MSIL também podem ser passados para o CL. exe.

Os arquivos *`.obj`* MSIL de entrada ou *`.netmodule`* não podem ter recursos inseridos. Insira recursos em um módulo de saída ou arquivo de assembly usando a opção de vinculador [/ASSEMBLYRESOURCE (inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md) . Ou use a opção de compilador **/Resource** em outros compiladores do Visual Studio.

## <a name="examples"></a>Exemplos

No C++ código, o bloco de **`catch`** de um **`try`** correspondente será invocado para uma exceção não`System`. No entanto, por padrão, o CLR encapsula exceções não`System` com <xref:System.Runtime.CompilerServices.RuntimeWrappedException>. Quando um assembly é criado a C++ C++ partir de módulos e não, e você deseja que um bloco C++ de **`catch`** no código seja invocado de sua cláusula **`try`** correspondente quando o bloco de **`try`** gera uma exceção que não é`System`, você deve adicionar o atributo `[assembly:System::Runtime::CompilerServices::RuntimeCompatibility(WrapNonExceptionThrows=false)]` ao código-C++ fonte para os não módulos.

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

Ao alterar o valor de `Boolean` do atributo `WrapNonExceptionThrows`, você modifica a capacidade do C++ código de capturar uma exceção não`System`.

```csharp
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

## <a name="see-also"></a>Veja também

- [Arquivos de entrada de LINK](link-input-files.md)
- [Opções de vinculador MSVC](linker-options.md)
