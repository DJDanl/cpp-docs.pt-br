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
ms.openlocfilehash: e809c7af7465cde98db11eac8628b76d04f7e8b5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316282"
---
# <a name="z7-zi-zi-debug-information-format"></a>/Z7, /Zi, /ZI (depurar formato de informações)

Especifica o tipo de informações de depuração criados para o seu programa e se essas informações são mantidas em arquivos de objeto ou em um arquivo de programa (PDB) do banco de dados.

## <a name="syntax"></a>Sintaxe

> **/Z**{**7**|**i**|**I**}

## <a name="remarks"></a>Comentários

Quando o código é compilado e criado no modo de depuração, o compilador gera nomes de símbolo para funções e variáveis, informações de tipo e locais de número de linha para uso pelo depurador. Essas informações simbólicas de depuração podem ser incluídas nos arquivos de objeto (arquivos. obj) produzidos pelo compilador, ou em um arquivo PDB (um arquivo. PDB) separado para o executável.  As opções de formato de informações de depuração são descritas nas seções a seguir.

### <a name="none"></a>Nenhum

Por padrão, se nenhuma opção de formato de informações de depuração for especificada, o compilador não produz nenhuma informação de depuração, então a compilação é mais rápida.

### <a name="z7"></a>/Z7

O **/Z7** opção produz arquivos de objeto que também contêm informações de depuração simbólicas completas para uso com o depurador. Esses arquivos de objeto e o executável compilado podem ser significativamente maiores do que os arquivos que não têm nenhuma informação de depuração. Informações de depuração simbólicas incluem os nomes e tipos de variáveis, bem como funções e os números de linha. Nenhum arquivo PDB é gerado.

Para distribuidores de versões de depuração das bibliotecas de terceiros, há uma vantagem de não ter um arquivo PDB. No entanto, os arquivos de objeto para quaisquer cabeçalhos pré-compilados são necessários durante a fase de link de biblioteca e para depuração. Se houver apenas digite informações (e nenhum código) no arquivo de objeto. pch, você também deve usar o [/Yl (injetar referência PCH para biblioteca de depuração)](yl-inject-pch-reference-for-debug-library.md) opção, que é habilitada por padrão, quando você compila a biblioteca.

Preteridas [/Gm (habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) opção não está disponível quando **/Z7** for especificado.

### <a name="zi"></a>/Zi

O **/Zi** opção produz um arquivo PDB separado que contém todas as informações de depuração simbólicas para uso com o depurador. As informações de depuração não estão incluídas nos arquivos de objeto ou executável, que os torna muito menor.

Uso de **/Zi** não afeta otimizações. No entanto, **/Zi** implicam **/Debug**; consulte [/DEBUG (gerar informações de depuração)](debug-generate-debug-info.md) para obter mais informações.

Quando você especifica ambos **/Zi** e **/clr**, o <xref:System.Diagnostics.DebuggableAttribute> atributo não é colocado nos metadados do assembly. Se desejar, você deve especificá-lo no código-fonte. Esse atributo pode afetar o desempenho de tempo de execução do aplicativo. Para obter mais informações sobre como o **Debuggable** atributo afeta o desempenho e como você pode modificar o impacto no desempenho, consulte [facilitando uma imagem para depuração](/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug).

O compilador nomeia o arquivo PDB *projeto*. PDB. Se você compilar um arquivo fora de um projeto, o compilador cria um arquivo PDB chamado VC*x*. PDB, onde *x* é uma concatenação do número de versão principal e secundária da versão do compilador em uso. O compilador insere o nome do PDB e uma assinatura de data/hora de identificação em cada arquivo de objeto criado usando essa opção, que aponta o depurador para o local das informações simbólicas de número de linha. O nome e assinatura no arquivo PDB devem corresponder ao executável para símbolos a serem carregados no depurador. O depurador WinDBG poderá carregar símbolos incompatíveis usando a `.symopt+0x40` comando. Visual Studio não tem uma opção similar para carregar símbolos incompatíveis.

Se você cria uma biblioteca de objetos que foram compilados usando **/Zi**, o arquivo. PDB associado deve estar disponível quando a biblioteca é vinculada a um programa. Assim, se você distribuir a biblioteca, você também deve distribuir o arquivo PDB. Para criar uma biblioteca que contém informações de depuração sem o uso de arquivos PDB, você deve selecionar o **/Z7** opção. Se você usar as opções de cabeçalhos pré-compilados, informações de depuração para o cabeçalho pré-compilado e o restante do código-fonte é colocada no arquivo PDB.

### <a name="zi"></a>/ZI

O **/ZI** opção é semelhante ao **/Zi**, mas produz um arquivo PDB em um formato que oferece suporte a [editar e continuar](/visualstudio/debugger/edit-and-continue-visual-cpp) recurso. Para usar recursos de depuração editar e continuar, você deve usar essa opção. O recurso Editar e continuar é útil para a produtividade do desenvolvedor, mas pode causar problemas em conformidade de tamanho, o desempenho e o compilador de código. Como a maioria das otimizações são incompatíveis com editar e continuar, usando **/ZI** desativa quaisquer `#pragma optimize` no seu código. O **/ZI** opção também é incompatível com o uso das [ &#95; &#95;linha&#95; &#95; a macro predefinida](../../preprocessor/predefined-macros.md); o código compilado com **/ZI** não é possível usar **&#95; &#95;Linha&#95; &#95;** como um argumento de modelo sem tipo, embora **&#95; &#95;linha&#95; &#95;** podem ser usados em expansões de macro.

O **/ZI** opção força a ambos os [/Gy (habilitar vinculação do nível de função)](gy-enable-function-level-linking.md) e [/FC (caminho completo da fonte de código de arquivo no diagnóstico)](fc-full-path-of-source-code-file-in-diagnostics.md) opções a serem usadas na sua compilação.

**/Zi** não é compatível com [/clr (compilação de tempo de execução de linguagem comum)](clr-common-language-runtime-compilation.md).

> [!NOTE]
> O **/ZI** opção só está disponível nos compiladores destinados a processadores x86 e x64; essa opção do compilador não está disponível nos compiladores destinados a processadores ARM.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

1. Modificar a **formato de informações de depuração** propriedade. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)

