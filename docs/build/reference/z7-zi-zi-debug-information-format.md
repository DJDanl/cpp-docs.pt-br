---
title: -/Z7, - Zi, - ZI (formato de informações de depuração) | Microsoft Docs
ms.custom: ''
ms.date: 02/22/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.DebugInformationFormat
- /ZI
- /Zi
- /Z7
- VC.Project.VCCLWCECompilerTool.DebugInformationFormat
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a86605b8fd47c0febedfc9ab022dfc2c2728822a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="z7-zi-zi-debug-information-format"></a>/Z7, /Zi, /ZI (depurar formato de informações)

Especifica o tipo de informação de depuração criado para o programa e se essas informações são mantidas em arquivos de objeto ou em um arquivo de programa (PDB) de banco de dados.

## <a name="syntax"></a>Sintaxe

> **/Z**{**7**|**i**|**I**}  

## <a name="remarks"></a>Comentários

Quando o código é compilado e compilado no modo de depuração, o compilador gera nomes de símbolos para funções e variáveis, informações de tipo e locais de número de linha para uso pelo depurador. Essas informações de depuração simbólicas podem ser incluídas nos arquivos (arquivos. obj) do objeto produzidos pelo compilador, ou em um arquivo PDB separado (um arquivo. PDB) para o executável.  As opções de formato de informações de depuração são descritas nas seções a seguir.  
  
### <a name="none"></a>Nenhum

Por padrão, se nenhuma opção de formato de informações de depuração for especificada, o compilador não produz nenhuma informação de depuração para a compilação é mais rápida.  
  
### <a name="z7"></a>/Z7

O **/Z7** opção produz arquivos de objeto que também contêm informações de depuração simbólicas completas para uso com o depurador. Esses arquivos de objeto e o executável criado podem ser significativamente maiores do que arquivos com nenhuma informação de depuração. As informações de depuração simbólicas incluem os nomes e tipos de variáveis, bem como funções e os números de linha. Nenhum arquivo PDB é produzido.

Para distribuidores de versões de depuração das bibliotecas de terceiros, há uma vantagem de não ter um arquivo PDB. No entanto, os arquivos de objeto para todos os cabeçalhos pré-compilados são necessários durante a fase de link da biblioteca e de depuração. Se houver apenas digite informações (e nenhum código) no arquivo de objeto. pch, você também deve usar o [/Yl (injetar referência PCH para biblioteca de depuração)](../../build/reference/yl-inject-pch-reference-for-debug-library.md) opção, que é habilitada por padrão, quando você cria a biblioteca.

O [/GM (habilitar mínimo recriar) de manual](../../build/reference/gm-enable-minimal-rebuild.md) opção não está disponível quando **/Z7** for especificado.

### <a name="zi"></a>/Zi

O **/Zi** opção produz um arquivo PDB separado que contém todas as informações de depuração simbólicas para uso com o depurador. As informações de depuração não estão incluídas nos arquivos de objeto ou executável, que os torna muito menor.

O uso de **/Zi** não afeta otimizações. No entanto, **/Zi** implicam **/Debug**; consulte [/DEBUG (gerar informações de depuração)](../../build/reference/debug-generate-debug-info.md) para obter mais informações.


Quando você especifica ambos **/Zi** e **/clr**, o <xref:System.Diagnostics.DebuggableAttribute> atributo não é colocado nos metadados do assembly. Se desejar, você deve especificar isto no código-fonte. Esse atributo pode afetar o desempenho de tempo de execução do aplicativo. Para obter mais informações sobre como o **Debuggable** atributo afeta o desempenho e como você pode modificar o impacto no desempenho, consulte [facilitando uma imagem para depuração](/dotnet/framework/debug-trace-profile/making-an-image-easier-to-debug).

O compilador nomeia o arquivo PDB *projeto*. PDB. Se você compilar um arquivo fora de um projeto, o compilador cria um arquivo PDB chamado VC*x*. PDB, onde *x* é uma concatenação do número de versão principal e secundária da versão do compilador em uso. O compilador incorpora o nome do PDB e uma assinatura de marca de identificação em cada arquivo de objeto criado usando essa opção, que aponta o depurador para o local das informações simbólicos e número da linha. O nome e assinatura no arquivo PDB devem corresponder o executável de símbolos ser carregado no depurador. O depurador WinDBG pode carregar símbolos incompatíveis com o uso de `.symopt+0x40` comando. O Visual Studio não tem uma opção similar ao carregar os símbolos não correspondentes.

Se você criar uma biblioteca de objetos que foram compilados usando **/Zi**, o arquivo. PDB associado deve estar disponível quando a biblioteca está vinculada a um programa. Portanto, se você distribuir a biblioteca, você também deve distribuir o arquivo PDB. Para criar uma biblioteca que contém informações de depuração sem o uso de arquivos PDB, você deve selecionar o **/Z7** opção. Se você usar as opções de cabeçalhos pré-compilados, as informações de cabeçalho pré-compilado e o restante do código-fonte de depuração é colocada no arquivo PDB.

### <a name="zi"></a>/ZI

O **/ZI** opção é semelhante a **/Zi**, mas ele produz um arquivo PDB em um formato que oferece suporte a [editar e continuar](/visualstudio/debugger/edit-and-continue-visual-cpp) recurso. Para usar Editar e continuar a depuração de recursos, você deve usar essa opção. O recurso Editar e continuar, é útil para a produtividade do desenvolvedor, mas pode causar problemas de conformidade de tamanho, o desempenho e o compilador de código. Como a maioria das otimizações são incompatíveis com editar e continuar, usando **/ZI** desativa qualquer `#pragma optimize` no seu código. O **/ZI** opção também é incompatível com o uso do [ &#95; &#95;linha&#95; &#95; macro predefinida](../../preprocessor/predefined-macros.md); o código compilado com **/ZI** não é possível usar **&#95; &#95;Linha&#95; &#95;** como um argumento de modelo sem tipo, embora **&#95; &#95;linha&#95; &#95;** podem ser usados em expansões de macro.

O **/ZI** opção força ambos o [/Gy (habilitar vinculação do nível de função)](../../build/reference/gy-enable-function-level-linking.md) e [/FC (completo caminho do arquivo de código fonte no diagnóstico)](../../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md) opções a serem usadas na sua compilação.

**/Zi** não é compatível com [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md).

> [!NOTE]
> O **/ZI** opção só está disponível nos compiladores direcionamento processadores x86 e x64; essa opção de compilador não está disponível nos compiladores direcionamento processadores ARM.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

1. Modificar o **formato informações de depuração** propriedade. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  

