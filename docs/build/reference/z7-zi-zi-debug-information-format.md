---
title: /Z7, /Zi, /ZI (depurar formato de informações)
ms.date: 04/08/2019
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
ms.openlocfilehash: aeaf435874b6d6b9dbc8a3d12ec06d38bf33aaae
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078260"
---
# <a name="z7-zi-zi-debug-information-format"></a>/Z7, /Zi, /ZI (depurar formato de informações)

Especifica o tipo de informações de depuração criadas para o seu programa e se essas informações são mantidas em arquivos de objeto ou em um arquivo de banco de dados de programa (PDB).

## <a name="syntax"></a>Sintaxe

> **/Z**{**7**|**i**|**i**}

## <a name="remarks"></a>Comentários

Quando o código é compilado e compilado no modo de depuração, o compilador produz nomes de símbolo para funções e variáveis, informações de tipo e locais de números de linha para uso pelo depurador. Essas informações de depuração simbólicas podem ser incluídas nos arquivos de objeto (arquivos. obj) produzidos pelo compilador ou em um arquivo PDB separado (um arquivo. pdb) para o executável.  As opções de formato de informações de depuração são descritas nas seções a seguir.

### <a name="none"></a>Nenhum

Por padrão, se nenhuma opção de formato de informações de depuração for especificada, o compilador não produzirá nenhuma informação de depuração, portanto, a compilação será mais rápida.

### <a name="z7"></a>/Z7

A opção **/Z7** produz arquivos de objeto que também contêm informações de depuração simbólicas completas para uso com o depurador. Esses arquivos de objeto e o executável compilado podem ser consideravelmente maiores do que arquivos que não têm nenhuma informação de depuração. As informações de depuração simbólicas incluem os nomes e tipos de variáveis, bem como funções e números de linha. Nenhum arquivo PDB é produzido.

Para distribuidores de versões de depuração de bibliotecas de terceiros, há uma vantagem de não ter um arquivo PDB. No entanto, os arquivos de objeto para todos os cabeçalhos pré-compilados são necessários durante a fase de link da biblioteca e para depuração. Se houver apenas informações de tipo (e nenhum código) no arquivo de objeto. pch, você também deverá usar a opção [/YL (injetar referência PCH para biblioteca de depuração)](yl-inject-pch-reference-for-debug-library.md) , que é habilitada por padrão, quando você cria a biblioteca.

A opção/GM preterida [(habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) não está disponível quando **/Z7** é especificado.

### <a name="zi"></a>/Zi

A opção **/Zi** produz um arquivo PDB separado que contém todas as informações de depuração simbólicas para uso com o depurador. As informações de depuração não são incluídas nos arquivos de objeto ou no executável, o que os torna muito menores.

O uso de **/Zi** não afeta as otimizações. No entanto, **/Zi** implica **/debug**; consulte [/debug (gerar informações de depuração)](debug-generate-debug-info.md) para obter mais informações.

Quando você especifica **/Zi** e **/CLR**, o atributo <xref:System.Diagnostics.DebuggableAttribute> não é colocado nos metadados do assembly. Se desejar, você deve especificá-lo no código-fonte. Esse atributo pode afetar o desempenho de tempo de execução do aplicativo. Para obter mais informações sobre como o atributo **depurável** afeta o desempenho e como você pode modificar o impacto no desempenho, consulte [tornando uma imagem mais fácil de depurar](/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug).

O compilador nomeia o arquivo PDB *Project*. pdb. Se você compilar um arquivo fora de um projeto, o compilador criará um arquivo PDB chamado VC*x*. pdb, em que *x* é uma concatenação do número de versão principal e secundária da versão do compilador em uso. O compilador incorpora o nome do PDB e identifica uma assinatura de carimbo de data/hora em cada arquivo de objeto criado usando essa opção, que aponta o depurador para o local de informações simbólicas e de número de linha. O nome e a assinatura no arquivo PDB devem corresponder ao executável para que os símbolos sejam carregados no depurador. O depurador do WinDBG pode carregar símbolos incompatíveis usando o comando `.symopt+0x40`. O Visual Studio não tem uma opção semelhante para carregar símbolos incompatíveis.

Se você criar uma biblioteca a partir de objetos que foram compilados usando **/Zi**, o arquivo. PDB associado deverá estar disponível quando a biblioteca estiver vinculada a um programa. Portanto, se você distribuir a biblioteca, também deverá distribuir o arquivo PDB. Para criar uma biblioteca que contém informações de depuração sem usar arquivos PDB, você deve selecionar a opção **/Z7** . Se você usar as opções de cabeçalhos pré-compilados, as informações de depuração para o cabeçalho pré-compilado e o restante do código-fonte serão colocadas no arquivo PDB.

### <a name="zi"></a>/ZI

A opção **/Zi** é semelhante a **/Zi**, mas produz um arquivo PDB em um formato que dá suporte ao recurso [Editar e continuar](/visualstudio/debugger/edit-and-continue-visual-cpp) . Para usar os recursos de depuração editar e continuar, você deve usar essa opção. O recurso Editar e continuar é útil para a produtividade do desenvolvedor, mas pode causar problemas no tamanho do código, no desempenho e na conformidade do compilador. Como a maioria das otimizações são incompatíveis com editar e continuar, usar **/Zi** desabilita qualquer instrução `#pragma optimize` em seu código. A opção **/Zi** também é incompatível com o [ &#95; &#95;uso da macro&#95; &#95; predefinida de linha](../../preprocessor/predefined-macros.md); o código compilado com **/Zi** não **&#95; &#95;pode&#95;** usar a linha como um argumento de modelo sem tipo, embora **&#95; &#95;a linha&#95;** possa ser usada em expansões de macro.

A opção **/Zi** força as opções [/GY (habilitar vinculação no nível de função)](gy-enable-function-level-linking.md) e [/FC (caminho completo do arquivo de código-fonte em diagnóstico)](fc-full-path-of-source-code-file-in-diagnostics.md) a serem usadas na compilação.

**/Zi** não é compatível com [/CLR (compilação em tempo de execução de linguagem comum)](clr-common-language-runtime-compilation.md).

> [!NOTE]
> A opção **/Zi** só está disponível nos compiladores destinados a processadores x86 e x64; Essa opção de compilador não está disponível nos compiladores direcionando processadores ARM.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra as **Propriedades de configuração** > página de propriedades **geral** **CC++ /**  > .

1. Modifique a propriedade de **formato de informações de depuração** . Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
