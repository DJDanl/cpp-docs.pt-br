---
title: /clr (compilação do Common Language Runtime)
ms.date: 05/16/2019
f1_keywords:
- /CLR
- VC.Project.VCNMakeTool.CompileAsManaged
- VC.Project.VCCLCompilerTool.CompileAsManaged
helpviewer_keywords:
- cl.exe compiler, common language runtime option
- -clr compiler option [C++]
- clr compiler option [C++]
- /clr compiler option [C++]
- Managed Extensions for C++, compiling
- common language runtime, /clr compiler option
ms.assetid: fec5a8c0-40ec-484c-a213-8dec918c1d6c
ms.openlocfilehash: fa2be3d3ce17df104cda121e4869c975ec6dd440
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837303"
---
# <a name="clr-common-language-runtime-compilation"></a>/clr (compilação do Common Language Runtime)

Permite que aplicativos e componentes usem recursos do CLR (Common Language Runtime).

## <a name="syntax"></a>Sintaxe

> **/clr**[ **:** _options_]

## <a name="arguments"></a>Arguments

*options*<br/>
Uma ou mais das opções a seguir, separadas por vírgula.

- nenhum

   Sem opções, **/clr** cria metadados para o aplicativo. Os metadados podem ser consumidos por outros aplicativos CLR e permitem que o aplicativo consuma tipos e dados nos metadados de outros componentes CLR. Para obter mais informações, confira [Assemblies mistos (nativos e gerenciados)](../../dotnet/mixed-native-and-managed-assemblies.md).

- **pure**

   **/clr:pure foi preterido**. A opção foi removida do Visual Studio 2017 e posterior. Recomendamos que você porte o código que precisa ser MSIL puro para o C#.

- **seguro**

   **/clr:safe foi preterido**. A opção foi removida do Visual Studio 2017 e posterior. Recomendamos que você porte o código que precisa ser MSIL seguro para o C#.

- **noAssembly**

   **/clr:noAssembly foi preterido**. Use [/LN (Criar módulo da MSIL)](ln-create-msil-module.md).

   Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída. Por padrão, a opção **noAssembly** não está em vigor.

   Um programa gerenciado que não tem metadados do assembly no manifesto é conhecido como um *módulo*. A opção **noAssembly** só pode ser usada para produzir um módulo. Se você fizer a compilação usando [/c](c-compile-without-linking.md) e **/clr:noAssembly**, especifique a opção [/NOASSEMBLY](noassembly-create-a-msil-module.md) na fase do vinculador para criar um módulo.

   Antes do Visual Studio 2005, **/clr:noAssembly** exigia **/LD**. Agora, **/LD** fica implícito quando você especifica **/clr:noAssembly**.

- **initialAppDomain**

   Permite que um aplicativo do Visual C++ seja executado na versão 1 do CLR.  Um aplicativo que é compilado usando **initialAppDomain** não deve ser usado por um aplicativo que usa o ASP.NET, porque não há suporte para ele na versão 1 do CLR.

- **nostdlib**

   Instrui o compilador a ignorar o diretório padrão de \clr. O compilador produzirá erros se você incluir várias versões de uma DLL como System.dll. O uso dessa opção permite especificar a estrutura específica a ser usada durante a compilação.

## <a name="remarks"></a>Comentários

Um código gerenciado é o código que pode ser inspecionado e gerenciado pelo CLR. O código gerenciado pode acessar objetos gerenciados. Para obter mais informações, consulte [/clr Restrições](clr-restrictions.md).

Para obter informações sobre como desenvolver aplicativos que definem e consomem tipos gerenciados, confira [Extensões de componentes para plataformas de tempo de execução](../../extensions/component-extensions-for-runtime-platforms.md).

Um aplicativo compilado com **/clr** pode ou não conter dados gerenciados.

Para habilitar a depuração em um aplicativo gerenciado, confira [/ASSEMBLYDEBUG (Adicionar DebuggableAttribute)](assemblydebug-add-debuggableattribute.md).

Somente os tipos CLR terão uma instância criada no heap coletado como lixo. Para obter mais informações, confira [Classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md). Para compilar uma função para código nativo, use o pragma `unmanaged`. Para obter mais informações, confira [managed, unmanaged](../../preprocessor/managed-unmanaged.md).

Por padrão, **/clr** não está em vigor. Quando **/clr** está em vigor, ocorre o mesmo com **/MD**. Para obter mais informações, consulte [/MD, /MT, /LD (usar biblioteca em tempo de execução)](md-mt-ld-use-run-time-library.md). **/MD** garante que as versões multi-threaded vinculadas dinamicamente das rotinas de tempo de execução sejam selecionadas dos arquivos de cabeçalho padrão (.h). O multithreading é necessário para a programação gerenciada porque o coletor de lixo do CLR executa os finalizadores em um thread auxiliar.

Se você compilar usando **/c**, poderá especificar o tipo CLR do arquivo de saída resultante com [/CLRIMAGETYPE](clrimagetype-specify-type-of-clr-image.md).

**/clr** implica **/EHa**, e não há suporte para nenhuma outra opção **/EH** em **/clr**. Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](eh-exception-handling-model.md).

Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, confira [/CLRHEADER](clrheader.md).

Todos os módulos passados para uma invocação especificada do vinculador precisam ser compilados com a mesma opção do compilador da biblioteca em tempo de execução ( **/MD** ou **/LD**).

Use a opção do vinculador [/ASSEMBLYRESOURCE](assemblyresource-embed-a-managed-resource.md) para inserir um recurso em um assembly. As opções do vinculador [/DELAYSIGN](delaysign-partially-sign-an-assembly.md), [/KEYCONTAINER](keycontainer-specify-a-key-container-to-sign-an-assembly.md) e [/KEYFILE](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) também permitem que você personalize como um assembly é criado.

Quando **/clr** é usado, o símbolo `_MANAGED` é definido como 1. Para obter mais informações, confira [Macros predefinidas](../../preprocessor/predefined-macros.md).

As variáveis globais em um arquivo-objeto nativo são inicializadas primeiro (durante DllMain se o executável é uma DLL) e, em seguida, as variáveis globais na seção gerenciada são inicializadas (antes da execução de qualquer código gerenciado). `#pragma` [init_seg](../../preprocessor/init-seg.md) só afeta a ordem de inicialização nas categorias gerenciadas e não gerenciadas.

## <a name="metadata-and-unnamed-classes"></a>Metadados e classes sem nome

As classes sem nome serão exibidas nos metadados e serão nomeadas da seguinte maneira: `$UnnamedClass$`*crc-of-current-file-name*`$`*índice*`$`, em que *índice* é uma contagem sequencial das classes sem nome na compilação. Por exemplo, o exemplo de código a seguir gera uma classe sem nome nos metadados.

```cpp
// clr_unnamed_class.cpp
// compile by using: /clr /LD
class {} x;
```

Use ildasm.exe para exibir os metadados.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
