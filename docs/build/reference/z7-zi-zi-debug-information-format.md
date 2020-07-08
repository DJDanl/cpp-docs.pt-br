---
title: /Z7, /Zi, /ZI (depurar formato de informações)
ms.date: 07/06/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.DebugInformationFormat
- /ZI
- /Zi
- /Z7
- VC.Project.VCCLWCECompilerTool.DebugInformationFormat
helpviewer_keywords:
- C7 compatible compiler option [C++]
- Debug Information Format compiler option
- ZI compiler option
- -Zi compiler option [C++]
- /ZI compiler option [C++]
- Z7 compiler option [C++]
- debugging [C++], debug information files
- Zi compiler option [C++]
- /Zi compiler option [C++]
- program database compiler option [C++]
- full symbolic debugging information
- /Z7 compiler option [C++]
- line numbers only compiler option [C++]
- cl.exe compiler, debugging options
- -Z7 compiler option [C++]
ms.openlocfilehash: bc3fd9c065219a128e29290084b1e1fb51fc773e
ms.sourcegitcommit: 85d96eeb1ce41d9e1dea947f65ded672e146238b
ms.contentlocale: pt-BR
ms.lasthandoff: 07/07/2020
ms.locfileid: "86058587"
---
# <a name="z7-zi-zi-debug-information-format"></a>/Z7, /Zi, /ZI (depurar formato de informações)

As **`/Z7`** **`/Zi`** Opções do compilador,, e **`/ZI`** especificam o tipo de informações de depuração criadas para o seu programa e se essas informações são mantidas em arquivos de objeto ou em um arquivo de banco de dados de programa (PDB).

## <a name="syntax"></a>Sintaxe

> **`/Z7`**\
> **`/Zi`**\
> **`/ZI`**

## <a name="remarks"></a>Comentários

Quando você especifica uma opção de depuração, o compilador produz nomes de símbolo para funções e variáveis, informações de tipo e locais de linha para uso pelo depurador. Essas informações de depuração simbólicas podem ser incluídas nos arquivos de objeto ( *`.obj`* arquivos) produzidos pelo compilador ou em um arquivo PDB separado (um *`.pdb`* arquivo) para o executável. As opções de formato de informações de depuração são descritas nas seções a seguir.

### <a name="none"></a>Nenhum

Por padrão, se nenhuma opção de formato de informações de depuração for especificada, o compilador não produzirá nenhuma informação de depuração, portanto, a compilação será mais rápida.

### <a name="z7"></a>/Z7

A **`/Z7`** opção produz arquivos de objeto que também contêm informações de depuração simbólicas completas para uso com o depurador. Esses arquivos de objeto e todas as bibliotecas criadas por meio deles podem ser consideravelmente maiores que os arquivos que não têm nenhuma informação de depuração. As informações de depuração simbólicas incluem os nomes e tipos de variáveis, funções e números de linha. Nenhum arquivo PDB é produzido pelo compilador. No entanto, um arquivo PDB ainda poderá ser gerado a partir desses arquivos de objeto ou bibliotecas se o vinculador passar a **`/DEBUG`** opção.

Para distribuidores de versões de depuração de bibliotecas de terceiros, há uma vantagem de não ter um arquivo PDB. No entanto, os arquivos de objeto para todos os cabeçalhos pré-compilados são necessários durante a fase de link da biblioteca e para depuração. Se houver apenas informações de tipo (e nenhum código) no *`.pch`* arquivo de objeto, você também deverá usar a opção [ `/Yl` (injetar referência PCH para biblioteca de depuração)](yl-inject-pch-reference-for-debug-library.md) , que é habilitada por padrão, quando você cria a biblioteca.

A opção preterido [ `/Gm` (habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) não está disponível quando **`/Z7`** é especificado.

### <a name="zi"></a>/Zi

A **`/Zi`** opção produz um arquivo PDB separado que contém todas as informações de depuração simbólicas para uso com o depurador. As informações de depuração não estão incluídas nos arquivos de objeto ou no executável, o que as torna muito menores.

O uso de **`/Zi`** não afeta otimizações. No entanto, **`/Zi`** o implica **`/debug`** . Para obter mais informações, consulte [ `/DEBUG` (gerar informações de depuração)](debug-generate-debug-info.md).

Quando você especifica **`/Zi`** e **`/clr`** , o <xref:System.Diagnostics.DebuggableAttribute> atributo não é colocado nos metadados do assembly. Se desejar, você deve especificá-lo no código-fonte. Esse atributo pode afetar o desempenho de tempo de execução do aplicativo. Para obter mais informações sobre como o `Debuggable` atributo afeta o desempenho e como você pode modificar o impacto no desempenho, consulte [tornando uma imagem mais fácil de depurar](/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug).

O compilador nomeia o arquivo PDB *`<project>.pdb`* , em que *`<project>`* é o nome do seu projeto. Se você compilar um arquivo fora de um projeto, o compilador criará um arquivo PDB chamado *`VC<x>.pdb`* , em que *`<x>`* é uma concatenação do número de versão principal e secundária da versão do compilador em uso. O compilador incorpora o nome do PDB e uma assinatura de identificação de carimbo de data/hora em cada arquivo de objeto criado usando essa opção. Esse nome e assinatura apontam o depurador para o local de informações simbólicas e de número de linha. O nome e a assinatura no arquivo PDB devem corresponder ao executável para que os símbolos sejam carregados no depurador. O depurador do WinDBG pode carregar símbolos incompatíveis usando o **`.symopt+0x40`** comando. O Visual Studio não tem uma opção semelhante para carregar símbolos incompatíveis.

Se você criar uma biblioteca a partir de objetos que foram compilados usando **`/Zi`** o, o arquivo PDB associado deverá estar disponível quando a biblioteca estiver vinculada a um programa. Isso significa que, se você distribuir a biblioteca, também deverá distribuir o arquivo PDB. Para criar uma biblioteca que contém informações de depuração sem usar arquivos PDB, você deve selecionar a **`/Z7`** opção. Se você usar as opções de cabeçalhos pré-compilados, as informações de depuração para o cabeçalho pré-compilado e o restante do código-fonte serão colocadas no arquivo PDB.

### <a name="zi"></a>/ZI

A **`/ZI`** opção é semelhante a **`/Zi`** , mas produz um arquivo PDB em um formato que dá suporte ao recurso [Editar e continuar](/visualstudio/debugger/edit-and-continue-visual-cpp) . Para usar os recursos de depuração editar e continuar, você deve usar essa opção. O recurso Editar e continuar é útil para a produtividade do desenvolvedor, mas pode causar problemas no tamanho do código, no desempenho e na conformidade do compilador. Como a maioria das otimizações são incompatíveis com editar e continuar, usar **`/ZI`** desabilita qualquer `#pragma optimize` instrução em seu código. A **`/ZI`** opção também é incompatível com o uso da [ `__LINE__` macro predefinida](../../preprocessor/predefined-macros.md); o código compilado com **`/ZI`** não pode `__LINE__` ser usado como um argumento de modelo sem tipo, embora `__LINE__` possa ser usado em expansões de macro.

A **`/ZI`** opção força as opções [ `/Gy` (habilitar vinculação no nível da função)](gy-enable-function-level-linking.md) e [ `/FC` (caminho completo do arquivo de código-fonte no diagnóstico)](fc-full-path-of-source-code-file-in-diagnostics.md) para serem usadas na sua compilação.

**`/ZI`** é incompatível com [ `/clr` (compilação em tempo de execução de linguagem comum)](clr-common-language-runtime-compilation.md).

> [!NOTE]
> A **`/ZI`** opção só está disponível nos compiladores que visam processadores x86 e x64. Essa opção de compilador não está disponível nos compiladores direcionando processadores ARM.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a página de propriedades de **configuração**  >  geral do**C/C++**  >  **General** .

1. Modifique a propriedade de **formato de informações de depuração** . Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
