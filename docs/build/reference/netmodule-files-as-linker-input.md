---
title: Arquivos .netmodule como entrada de vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- MSIL linking
- linking [C++], modules
- .netmodules
- modules, Visual C++
ms.assetid: a4bcbe8a-4255-451d-853b-f88cfd82f4e1
ms.openlocfilehash: fcba363cff567c69ac0fbd0a541953dfe2c8e910
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320663"
---
# <a name="netmodule-files-as-linker-input"></a>Arquivos .netmodule como entrada de vinculador

link.exe agora aceita MSIL obj e. netmodules como entrada. O arquivo de saída produzido pelo vinculador é um assembly ou um. netmodule sem dependência de tempo de execução em qualquer um dos netmodules eram de entrada para o vinculador ou. obj.

netmodules são criadas pelo compilador MSVC com [/LN (Criar módulo de MSIL)](ln-create-msil-module.md) ou pelo vinculador com [/NOASSEMBLY (criar um módulo de MSIL)](noassembly-create-a-msil-module.md). .objs são sempre criadas em uma compilação do Visual C++. Para outros compiladores do Visual Studio, use o **/target: Module** opção de compilador.

Você deve passar para o vinculador de arquivo. obj da compilação do Visual C++ que criou o. netmodule. Passando um. netmodule não é mais suportado porque o **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter informações sobre como invocar o vinculador da linha de comando, consulte [sintaxe de linha de comando do vinculador](linking.md), [usam o conjunto de ferramentas da linha de comando MSVC](../building-on-the-command-line.md), e [definir o caminho e variáveis de ambiente para compilações de linha de comando](../setting-the-path-and-environment-variables-for-command-line-builds.md).

Passando um arquivo. netmodule ou. dll para o vinculador que foi compilado pelo compilador MSVC com **/clr** pode resultar em um erro de vinculador. Para obter mais informações, consulte [escolhendo o formato dos arquivos de entrada. netmodule](choosing-the-format-of-netmodule-input-files.md).

O vinculador aceita arquivos. obj nativo, bem como arquivos do MSIL. obj compilados com **/clr**. Ao passar .objs mistos na mesma compilação, a capacidade de verificação do arquivo de saída resultante, por padrão, será igual ao nível mais baixo de capacidade de verificação dos módulos de entrada.

Se você tiver um aplicativo que é composto de dois ou mais assemblies e você deseja que o aplicativo a ser contido em um assembly, você deve recompilar os assemblies e, em seguida, vincule o .objs ou netmodules para produzir um único assembly.

Você deve especificar um ponto de entrada usando [/ENTRY (símbolo de ponto de entrada)](entry-entry-point-symbol.md) durante a criação de uma imagem executável.

Ao vincular com um arquivo. obj ou. netmodule MSIL, use [/LTCG (geração de código Link-time)](ltcg-link-time-code-generation.md), caso contrário, quando o vinculador encontra o. netmodule ou. obj MSIL, ele reiniciará o link com /LTCG.

Arquivos. obj ou. netmodule MSIL também podem ser passados para cl.exe.

Arquivos de. obj ou. netmodule MSIL entrada não podem ter recursos inseridos. Um recurso é inserido em um arquivo de saída (módulo ou assembly) com [/ASSEMBLYRESOURCE. (inserir um recurso gerenciado)](assemblyresource-embed-a-managed-resource.md) opção de vinculador ou com o **/resource** opção do compilador em outros compiladores do Visual Studio.

Ao executar a vinculação MSIL, e se você não especificar também [/LTCG (geração de código Link-time)](ltcg-link-time-code-generation.md), você verá uma mensagem informativa relatar que o link está reiniciando. Essa mensagem pode ser ignorado, mas to melhorar performance do vinculador com vinculação MSIL, especifique explicitamente **/LTCG**.

## <a name="example"></a>Exemplo

No código C++ a **catch** bloco de um correspondente **tente** será invocado para uma exceção não são do sistema. No entanto, por padrão, o CLR encapsula exceções não são do sistema com <xref:System.Runtime.CompilerServices.RuntimeWrappedException>. Quando um assembly é criado a partir de módulos do Visual C++ e não do Visual C++ e você desejar uma **catch** bloquear em código C++ para ser invocado a partir de seu correspondente **tente** cláusula quando o **tente**bloco lançar uma exceção não são do sistema, você deve adicionar o `[assembly:System::Runtime::CompilerServices::RuntimeCompatibility(WrapNonExceptionThrows=false)]` de atributo no código-fonte para os módulos não C++.

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

Alterando o valor booliano do `WrapNonExceptionThrows` atributo, você modifica a capacidade do código do Visual C++ para capturar uma exceção não são do sistema.

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
