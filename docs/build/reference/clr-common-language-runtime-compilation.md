---
title: /clr (compilação do Common Language Runtime)
description: Use a opção de compilador do Microsoft C++/CLR para compilar o código C++/CLI e C++ como código gerenciado.
ms.date: 10/27/2020
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
ms.openlocfilehash: 9d27d9fb6226f84c4ea67a8f9387a595ba65468b
ms.sourcegitcommit: 9c801a43ee0d4d84956b03fd387716c818705e0d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/28/2020
ms.locfileid: "92907591"
---
# <a name="clr-common-language-runtime-compilation"></a>`/clr` (Compilação em tempo de execução de linguagem comum)

Permite que aplicativos e componentes usem recursos do Common Language Runtime (CLR) e habilita a compilação C++/CLI.

## <a name="syntax"></a>Syntax

> **`/clr`**\[**`:`**_Opções_ ]

## <a name="arguments"></a>Argumentos

*Opções*\
Um ou mais dos argumentos separados por vírgulas a seguir.

- nenhum

   Sem opções, o **`/clr`** cria metadados para o componente. Os metadados podem ser consumidos por outros aplicativos CLR e permitem que o componente consuma tipos e dados nos metadados de outros componentes do CLR. Para obter mais informações, confira [Assemblies mistos (nativos e gerenciados)](../../dotnet/mixed-native-and-managed-assemblies.md).

- **`NetCore`**

   **`/clr:NetCore`** cria metadados e código para o componente usando o .NET Framework de plataforma cruzada mais recente, também conhecido como .NET Core. Os metadados podem ser consumidos por outros aplicativos .NET Core. E a opção permite que o componente consuma tipos e dados nos metadados de outros componentes do .NET Core.

- **`nostdlib`**

   Instrui o compilador a ignorar o diretório padrão *`\clr`* . O compilador produzirá erros se você incluir várias versões de uma DLL, como System.dll. Essa opção permite especificar a estrutura específica a ser usada durante a compilação.

- **`pure`**

   **`/clr:pure` é preterido** . A opção foi removida do Visual Studio 2017 e posterior. Recomendamos que você porte o código que precisa ser MSIL puro para o C#.

- **`safe`**

   **`/clr:safe` é preterido** . A opção foi removida do Visual Studio 2017 e posterior. Recomendamos que você porte o código que precisa ser MSIL seguro para o C#.

- **`noAssembly`**

   **`/clr:noAssembly` é preterido** . Em vez disso, use [ `/LN` (criar módulo MSIL)](ln-create-msil-module.md) .

   Instrui o compilador a não inserir um manifesto do assembly no arquivo de saída. Por padrão, a **`noAssembly`** opção não está em vigor.

   Um programa gerenciado que não tem metadados de assembly no manifesto é conhecido como um *módulo* . A **`noAssembly`** opção pode ser usada somente para produzir um módulo. Se você compilar usando [`/c`](c-compile-without-linking.md) o e **`/clr:noAssembly`** o, especifique a [`/NOASSEMBLY`](noassembly-create-a-msil-module.md) opção na fase do vinculador para criar um módulo.

   Antes do Visual Studio 2005, **`/clr:noAssembly`** necessário **`/LD`** . **`/LD`** Agora é implícito quando você especifica **`/clr:noAssembly`** .

- **`initialAppDomain`**

   **`initialAppDomain` é obsoleto** . Permite que um aplicativo C++/CLI seja executado na versão 1 do CLR.  Um aplicativo que é compilado usando **`initialAppDomain`** o não deve ser usado por um aplicativo que usa ASP.net porque não tem suporte na versão 1 do CLR.

## <a name="remarks"></a>Comentários

*Código gerenciado* é o código que pode ser inspecionado e gerenciado pelo CLR. O código gerenciado pode acessar objetos gerenciados. Para obter mais informações, consulte [ `/clr` restrições](clr-restrictions.md).

Para obter informações sobre como desenvolver aplicativos que definem e consomem tipos gerenciados em C++, consulte [extensões de componente para plataformas de tempo de execução](../../extensions/component-extensions-for-runtime-platforms.md).

Um aplicativo compilado usando **`/clr`** maio ou não pode conter dados gerenciados.

Para habilitar a depuração em um aplicativo gerenciado, consulte [ `/ASSEMBLYDEBUG` (Adicionar DebuggableAttribute)](assemblydebug-add-debuggableattribute.md).

Somente os tipos CLR são instanciados no heap coletado pelo lixo. Para obter mais informações, confira [Classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md). Para compilar uma função para código nativo, use o pragma `unmanaged`. Para obter mais informações, [ `managed` consulte `unmanaged` . ](../../preprocessor/managed-unmanaged.md)

Por padrão, **`/clr`** não está em vigor. Quando **`/clr`** está em vigor, **`/MD`** também está em vigor. Para obter mais informações, consulte [ `/MD` , `/MT` `/LD` (use Run-Time Library)](md-mt-ld-use-run-time-library.md). **`/MD`** garante que as versões de vários threads vinculadas dinamicamente das rotinas de tempo de execução sejam selecionadas nos arquivos de cabeçalho padrão. O multithreading é necessário para a programação gerenciada porque o coletor de lixo do CLR executa os finalizadores em um thread auxiliar.

Se você compilar usando **`/c`** o, poderá especificar o tipo CLR do arquivo de saída resultante usando a opção de [`/CLRIMAGETYPE`](clrimagetype-specify-type-of-clr-image.md) vinculador.

**`/clr`** implica **`/EHa`** , e nenhuma outra **`/EH`** opção é compatível com o **`/clr`** . Para obter mais informações, consulte [ `/EH` (modelo de tratamento de exceção)](eh-exception-handling-model.md).

Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [`/CLRHEADER`](clrheader.md) .

Todos os módulos passados para uma determinada invocação do vinculador devem ser compilados usando a mesma opção de compilador de biblioteca de tempo de execução ( **`/MD`** ou **`/LD`** ).

Use a [`/ASSEMBLYRESOURCE`](assemblyresource-embed-a-managed-resource.md) opção de vinculador para inserir um recurso em um assembly. [`/DELAYSIGN`](delaysign-partially-sign-an-assembly.md), [`/KEYCONTAINER`](keycontainer-specify-a-key-container-to-sign-an-assembly.md) e [`/KEYFILE`](keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) as opções do vinculador também permitem personalizar como um assembly é criado.

Quando **`/clr`** é usado, o `_MANAGED` símbolo é definido como 1. Para obter mais informações, consulte [macros predefinidas](../../preprocessor/predefined-macros.md).

As variáveis globais em um arquivo de objeto nativo são inicializadas primeiro (durante `DllMain` se o executável for uma dll) e, em seguida, as variáveis globais na seção gerenciada são inicializadas (antes de qualquer código gerenciado ser executado). [`#pragma init_seg`](../../preprocessor/init-seg.md) afeta apenas a ordem de inicialização nas categorias gerenciadas e não gerenciadas.

### <a name="metadata-and-unnamed-classes"></a>Metadados e classes sem nome

As classes sem nome aparecem em metadados em nomes como  `$UnnamedClass$<crc-of-current-file-name>$<index>$` , em que `<index>` é uma contagem Sequencial das classes sem nome na compilação. Por exemplo, o exemplo de código a seguir gera uma classe sem nome nos metadados.

```cpp
// clr_unnamed_class.cpp
// compile by using: /clr /LD
class {} x;
```

Use ildasm.exe para exibir os metadados.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações** e defina a lista suspensa **plataforma** como **todas as plataformas** .

1. Selecione a **Configuration Properties**  >  página Geral do **C/C++** Propriedades de configuração  >  **General** .

1. Modifique a propriedade de **suporte Common Language Runtime** . Escolha **OK** para salvar suas alterações.

> [!NOTE]
> No IDE do Visual Studio, a **`/clr`** opção do compilador pode ser definida individualmente na página **Propriedades de configuração**  >  **C/C++**  >  **geral** da caixa de diálogo páginas de propriedades. No entanto, recomendamos que você use um modelo CLR para criar seu projeto. Ele define todas as propriedades necessárias para a criação bem-sucedida de um componente CLR. Outra maneira de definir essas propriedades é usar a propriedade de **suporte Common Language Runtime** na página **Configuration Properties**  >  **avançado** Propriedades de configuração da caixa de diálogo páginas de propriedades. Essa propriedade define todas as outras opções de ferramenta relacionadas ao CLR de uma vez.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAsManaged>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de Command-Line do compilador MSVC](compiler-command-line-syntax.md)
