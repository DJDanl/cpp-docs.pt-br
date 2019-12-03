---
title: /w,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)
ms.date: 01/31/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.DisableSpecificWarnings
- VC.Project.VCCLCompilerTool.WarningLevel
- VC.Project.VCCLWCECompilerTool.DisableSpecificWarnings
- VC.Project.VCCLCompilerTool.WarnAsError
- VC.Project.VCCLWCECompilerTool.WarnAsError
- /wx
- VC.Project.VCCLWCECompilerTool.WarningLevel
- /wall
- VC.Project.VCCLCompilerTool.TreatSpecificWarningsAsErrors
- /Wv
- /w0
- /w1
- /w2
- /w3
- /w4
- /wd
- /we
- /wo
helpviewer_keywords:
- /W1 compiler option [C++]
- w compiler option [C++]
- -wo compiler option [C++]
- Warning Level compiler option
- W1 compiler option [C++]
- -we compiler option [C++]
- /WX compiler option [C++]
- -wd compiler option [C++]
- WX compiler option [C++]
- wo compiler option [C++]
- Wall compiler option [C++]
- /w compiler option
- W2 compiler option [C++]
- -W2 compiler option [C++]
- wd compiler option [C++]
- /we compiler option [C++]
- we compiler option [C++]
- -W1 compiler option [C++]
- -W4 compiler option [C++]
- -Wall compiler option [C++]
- /Wall compiler option [C++]
- -W0 compiler option [C++]
- W0 compiler option [C++]
- -WX compiler option [C++]
- /wo compiler option [C++]
- W4 compiler option [C++]
- W3 compiler option [C++]
- /wd compiler option [C++]
- warnings, as errors compiler option
- /W3 compiler option [C++]
- /W0 compiler option [C++]
- /W4 compiler option [C++]
- -W3 compiler option [C++]
- -w compiler option [C++]
- /W2 compiler option [C++]
- /Wv compiler option [C++]
ms.openlocfilehash: 7d2fd21c476ef4346aa86e682047ea644183b2f3
ms.sourcegitcommit: d0504e2337bb671e78ec6dd1c7b05d89e7adf6a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/02/2019
ms.locfileid: "74683053"
---
# <a name="w-w0-w1-w2-w3-w4-w1-w2-w3-w4-wall-wd-we-wo-wv-wx-warning-level"></a>/w,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)

Especifica como o compilador gera avisos para uma determinada compilação.

## <a name="syntax"></a>Sintaxe

> **/w**\
> \ **/W0**
> \ **/W1**
> \ **/W2**
> \ **/w3**
> \ **/W4**
> \ **/Wall**
> **/WV**\[ **:** _version_] \
> \ **/WX**
> \ de_aviso_ **/W1**
> \ de_aviso_ **/W2**
> \ de_aviso_ **/w3**
> \ de_aviso_ **/W4**
> \ de_aviso_ **/WD**
> \ de_aviso_ **/We**
> _aviso_ de/Wo

## <a name="remarks"></a>Comentários

As opções de aviso especificam quais avisos do compilador Exibir e o comportamento de aviso para toda a compilação.

As opções de aviso e os argumentos relacionados são descritos na tabela a seguir:

|Opção|Descrição|
------------|-----------------|
|**/w**|Suprime todos os avisos do compilador.|
|**/W0**<br /><br /> **/W1**<br /><br /> **/W2**<br /><br /> **/W3**<br /><br /> **/W4**|Especifica o nível de avisos a serem gerados pelo compilador. Os níveis de aviso válidos variam de 0 a 4:<br />**/W0** suprime todos os avisos. Isso é equivalente a **/w**.<br />**/W1** exibe avisos de nível 1 (grave). **/W1** é a configuração padrão no compilador de linha de comando.<br />**/W2** exibe avisos de nível 1 e nível 2 (significativos).<br />**/W3** exibe os avisos de nível 1, nível 2 e nível 3 (qualidade de produção). **/W3** é a configuração padrão no IDE.<br />**/W4** exibe os avisos nível 1, nível 2 e nível 3 e todos os avisos de nível 4 (informativo) que não são desativados por padrão. Recomendamos que você use essa opção para fornecer avisos sem fiapos. Para um novo projeto, pode ser melhor usar **/W4** em todas as compilações; Isso garantirá o menor número possível de defeitos de código difíceis de encontrar.|
|**/Wall**|Exibe todos os avisos exibidos por **/W4** e todos os outros avisos que o **/W4** não inclui, por exemplo, os avisos que estão desativados por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).|
|**/WV**\[ **:** _versão_]|Exibe somente os avisos introduzidos na *versão* da versão do compilador e versões anteriores. Você pode usar essa opção para suprimir novos avisos no código ao migrar para uma versão mais recente do compilador e para manter o processo de compilação existente enquanto você os corrige. A *versão* opcional do parâmetro assume a forma *NN*[. *mm*[. *bbbbb*]] em que *NN* é o número de versão principal, *mm* é o número de versão secundária opcional e *bbbbb* é o número de Build opcional do compilador. Por exemplo, use */WV: 17* para exibir avisos introduzidos no Visual Studio 2012 (ou seja, qualquer versão do compilador que tenha um número de versão principal de 17) ou anterior, mas suprimir avisos introduzidos em Visual Studio 2013 (versão mais recente 18) e posterior. Por padrão, **/WV** usa o número de versão do compilador atual e nenhum aviso é suprimido. Para obter informações sobre quais avisos são suprimidos pela versão do compilador, consulte [avisos do compilador por versão do compilador](../../error-messages/compiler-warnings/compiler-warnings-by-compiler-version.md).|
|**/WX**|Trata todos os avisos do compilador como erros. Para um novo projeto, pode ser melhor usar **/WX** em todas as compilações; resolver todos os avisos garante o menor número possível de defeitos de código difíceis de encontrar.<br /><br /> O vinculador também tem uma opção **/WX** . Para obter mais informações, consulte [/WX (Tratar Avisos do Vinculador como Erros)](wx-treat-linker-warnings-as-errors.md).|
|**/W1**_nnnn_<br /><br /> **/W2**_nnnn_<br /><br /> **/w3**_nnnn_<br /><br /> **/W4**_nnnn_|Define o nível de aviso para o número de aviso especificado por _nnnn_. Isso permite que você altere o comportamento do compilador para esse aviso quando um nível de aviso específico é definido. Você pode usar essas opções em combinação com outras opções de aviso para impor seus próprios padrões de codificação para avisos, em vez dos padrões fornecidos pelo Visual Studio.<br /><br /> Por exemplo, **/w34326** faz com que C4326 seja gerado como um aviso de nível 3 em vez de nível 1. Se você compilar usando a opção **/w34326** e a opção **/W2** , o aviso C4326 não será gerado.|
|**/WD**_nnnn_|Suprime o aviso do compilador que é especificado por _nnnn_.<br /><br /> Por exemplo, **/wd4326** suprime C4326 de aviso do compilador.|
|**/We**_nnnn_|Trata o aviso do compilador que é especificado por _nnnn_ como um erro.<br /><br /> Por exemplo, **/we4326** faz com que o número de aviso C4326 seja tratado como um erro pelo compilador.|
|**/wo**_nnnn_|Relata o aviso do compilador que é especificado por _nnnn_ apenas uma vez.<br /><br /> Por exemplo, **/wo4326** faz com que o aviso C4326 seja relatado apenas uma vez, na primeira vez que for encontrado pelo compilador.|

Se você usar qualquer uma das opções de aviso ao criar um cabeçalho pré-compilado usando a opção [/YC](yc-create-precompiled-header-file.md) , qualquer uso do cabeçalho pré-compilado usando a opção [/Yu](yu-use-precompiled-header-file.md) fará com que as mesmas opções de aviso entrem em vigor novamente. Você pode substituir as opções de aviso definidas no cabeçalho pré-compilado usando outra opção de aviso na linha de comando.

Você pode usar uma diretiva de [aviso #pragma](../../preprocessor/warning.md) para controlar o nível de aviso relatado em tempo de compilação em arquivos de origem específicos.

As diretivas pragma de aviso no código-fonte não são afetadas pela opção **/w** .

A [documentação de erros de compilação](../../error-messages/compiler-errors-1/c-cpp-build-errors.md) descreve os avisos e os níveis de aviso e indica por que determinadas instruções não podem ser compiladas como você pretende.

### <a name="to-set-the-compiler-options-in-the-visual-studio-development-environment"></a>Para definir as opções do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Para definir as opções **/W0**, **/W1**, **/W2**, **/w3**, **/W4**, **/Wall**, **/WV**, **/WX** ou **/WX-** , selecione as **Propriedades de configuração** > página de propriedades **geral** **C++ C/**  > .

   - Para definir as opções **/W0**, **/W1**, **/W2**, **/w3**, **/W4**ou **/Wall** , modifique a propriedade **nível de aviso** .

   - Para definir as opções **/WX** ou **/WX-** , modifique a propriedade **tratar avisos como erros** .

   - Para definir a versão para a opção **/WV** , insira o número de versão do compilador na propriedade **versão de aviso** .

1. Para definir as opções **/WD** ou **/We** , selecione as **Propriedades de configuração** > página de propriedades **avançado** **C/C++**  > .

   - Para definir a opção **/WD** , selecione o controle da lista suspensa desabilitar a propriedade **avisos específicos** e escolha **Editar**. Na caixa de edição do diálogo **desabilitar avisos específicos** , insira o número de aviso. Para inserir mais de um aviso, separe os valores usando um ponto-e-vírgula ( **;** ). Por exemplo, para desabilitar C4001 e C4010, digite **4001; 4010**. Escolha **OK** para salvar as alterações e retornar à caixa de diálogo **páginas de propriedades** .

   - Para definir a opção **/We** , selecione o controle de lista suspensa **tratar avisos específicos como erros** e escolha **Editar**. Na caixa de edição do diálogo **tratar avisos específicos como erros** , insira o número de aviso. Para inserir mais de um aviso, separe os valores usando um ponto-e-vírgula ( **;** ). Por exemplo, para tratar C4001 e C4010 como erros, digite **4001; 4010**. Escolha **OK** para salvar as alterações e retornar à caixa de diálogo **páginas de propriedades** .

1. Para definir a opção **/wo** , selecione as **Propriedades de configuração** > **CC++ /**  > página de propriedades de **linha de comando** . Insira a opção do compilador na caixa **Opções adicionais** .

1. Escolha **OK** para salvar suas alterações.

### <a name="to-set-the-compiler-option-programmatically"></a>Para definir a opção do compilador programaticamente

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarningLevel%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarnAsError%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableSpecificWarnings%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
