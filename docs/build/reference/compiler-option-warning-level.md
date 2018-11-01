---
title: /w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)
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
ms.openlocfilehash: 4842e845013bf69a7bc033ba7b6abf5ecc7d5079
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50441737"
---
# <a name="w-w0-w1-w2-w3-w4-w1-w2-w3-w4-wall-wd-we-wo-wv-wx-warning-level"></a>/w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)

Especifica como o compilador gera avisos para uma determinada compilação.

## <a name="syntax"></a>Sintaxe

> **/w**
>  **/W0**
>  **/W1**
>  **/w2**
>  **/w3** 
>  **/W4**
>  **/Wall**
>  **/Wv**\[**:**_versão _] **/WX**
>  **/W1**_aviso_
>  **/w2** _ Aviso_
>  **/w3**_aviso_
>  **/W4**_aviso_ 
>  **/wd**_aviso_
>  **/we**_aviso_ 
>  **/wo**_aviso_

## <a name="remarks"></a>Comentários

As opções de aviso especificam quais avisos do compilador para exibição e o comportamento de aviso para a compilação inteiro.

As opções de aviso e argumentos relacionados são descritos na tabela a seguir:

|Opção|Descrição|
------------|-----------------|
|**/w**|Suprime todos os avisos do compilador.|
|**/W0**<br /><br /> **/W1**<br /><br /> **/W2**<br /><br /> **/W3**<br /><br /> **/W4**|Especifica o nível de avisos a ser gerado pelo compilador. Os níveis de aviso válido variam de 0 a 4:<br />**/ W0** Suprime todos os avisos. Isso é equivalente a **/w**.<br />**/ W1** exibe avisos de nível 1 (grave). **/ W1** é a configuração padrão no compilador de linha de comando.<br />**/ W2** exibe nível 1 e avisos do nível 2 (significativos).<br />**/ W3** monitores de nível 1, nível 2 e avisos de nível 3 (qualidade de produção). **/ W3** é a configuração padrão no IDE.<br />**/ W4** exibe nível 1, nível 2 e avisos de nível 3, e todos os nível 4 avisos (informativos) que não são desativados por padrão. É recomendável que você use esta opção para fornecer avisos de lint-like. Para um novo projeto, talvez seja melhor usar **/W4** em todas as compilações; Isso garantirá o menor número possível código de difícil de encontrar defeitos.|
|**/Wall**|Exibe todos os avisos são exibidos pelo **/W4** e todos os outros avisos que **/W4** não inclui — por exemplo, os avisos são desativados por padrão. Para obter mais informações, consulte [compilador avisos que são desativada por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).|
|**/Wv**\[**:**_version_]|Exibe apenas os avisos introduzidos na versão do compilador *versão* e versões anteriores. Você pode usar essa opção para suprimir avisos de novo no código quando você migra para uma versão mais recente do compilador e para manter o processo de compilação existente enquanto você corrigi-los. O parâmetro opcional *versão* assume a forma *nn*[. *mm*[. *bbbbb*]] em que *nn* é o número de versão principal *mm* é o número de versão secundária opcional, e *bbbbb* é o número da compilação opcional o compilador. Por exemplo, use */Wv:17* para exibir avisos introduzidos no Visual Studio 2012 (ou seja, qualquer versão do compilador que tem um número de versão principal de 17) ou anterior, mas suprimir avisos introduzidos no Visual Studio 2013 (versão principal 18) e posterior. Por padrão, **/Wv** usa o número de versão atual do compilador e sem avisos estão suprimidos. Para obter informações sobre quais os avisos são suprimidos pela versão do compilador, consulte [avisos do compilador pela versão do compilador](../../error-messages/compiler-warnings/compiler-warnings-by-compiler-version.md).|
|**/WX**|Trata todos os avisos do compilador como erros. Para um novo projeto, talvez seja melhor usar **/WX** em todas as compilações; resolver todos os avisos garante o menor número possível código de difícil de encontrar defeitos.<br /><br /> O vinculador também tem um **/WX** opção. Para obter mais informações, consulte [/WX (Tratar Avisos do Vinculador como Erros)](../../build/reference/wx-treat-linker-warnings-as-errors.md).|
|**/ W1**_nnnn_<br /><br /> **/ w2**_nnnn_<br /><br /> **/ W3**_nnnn_<br /><br /> **/ W4**_nnnn_|Define o nível de aviso para o número de aviso especificado por _nnnn_. Isso lhe permite alterar o comportamento do compilador para que o aviso quando um nível de aviso específico é definido. Você pode usar essas opções em combinação com outras opções de aviso para impor suas própria codificação padrões para avisos, em vez dos valores padrão fornecidos pelo Visual Studio.<br /><br /> Por exemplo, **/w34326** faz com que o C4326 a ser gerado como um aviso de nível 3, em vez de nível 1. Se você compilar usando ambos os **/w34326** opção e o **/w2** opção, o aviso C4326 não é gerado.|
|**/WD**_nnnn_|Suprime o aviso do compilador que é especificado pelo _nnnn_.<br /><br /> Por exemplo, **/wd4326** suprime o aviso C4326 do compilador.|
|**/We**_nnnn_|Trata o aviso do compilador que é especificado pelo _nnnn_ como um erro.<br /><br /> Por exemplo, **/we4326** faz com que o número de aviso C4326 seja tratado como um erro pelo compilador.|
|**/WO**_nnnn_|Relatórios de aviso do compilador que é especificado por _nnnn_ apenas uma vez.<br /><br /> Por exemplo, **/wo4326** causas aviso C4326 seja relatado somente uma vez, na primeira vez que ela for encontrada pelo compilador.|

Se você usar qualquer uma das opções de aviso quando você cria um cabeçalho pré-compilado usando o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção, qualquer uso do cabeçalho pré-compilado usando o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção faz com que essas mesmas opções de aviso para estar em vigor novamente. Você pode substituir as opções de aviso definidas no cabeçalho pré-compilado usando outra opção de aviso na linha de comando.

Você pode usar um [#pragma aviso](../../preprocessor/warning.md) diretiva para controlar o nível de aviso que é relatado em tempo de compilação nos arquivos de origem específico.

Diretivas pragma de aviso no código-fonte não são afetadas pela **/w** opção.

O [documentação de erros de compilação](../../error-messages/compiler-errors-1/c-cpp-build-errors.md) descreve os avisos e os níveis de aviso e indica por que determinadas instruções podem não ser compilados como você deseja.

### <a name="to-set-the-compiler-options-in-the-visual-studio-development-environment"></a>Para definir as opções do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Para definir a **/W0**, **/W1**, **/w2**, **/w3**, **/W4**, **/Wall**m **/Wv**, **/WX** ou **/WX-** opções, selecionadas o **propriedades de configuração** > **C / C++** > **geral** página de propriedades.

   - Para definir a **/W0**, **/W1**, **/w2**, **/w3**, **/W4**, ou **/Wall** modificar opções, o **nível de aviso** propriedade.

   - Para definir a **/WX** ou **/WX-** modificar opções, o **tratar avisos como erros** propriedade.

   - Para definir a versão para o **/Wv** opção, insira o número de versão do compilador na **aviso versão** propriedade.

1. Para definir a **/wd** ou **/we** opções, selecionadas o **propriedades de configuração** > **C/C++**  >   **Advanced** página de propriedades.

   - Para definir a **/wd** opção, selecione a **desabilita avisos específicos** propriedade controle de lista suspensa e, em seguida, escolha **editar**. Na caixa de edição do **desabilitar avisos específicos** caixa de diálogo, insira o número de aviso. Para inserir mais de um aviso, separe os valores por meio de um ponto e vírgula (**;**). Por exemplo, para desabilitar C4001 e C4010, insira **4001; 4010**. Escolher **Okey** para salvar suas alterações e retornar para o **páginas de propriedade** caixa de diálogo.

   - Para definir a **/we** opção, selecione a **tratar avisos específicos como erros** propriedade controle de lista suspensa e, em seguida, escolha **editar**. Na caixa de edição do **tratar avisos específicos como erros** caixa de diálogo, insira o número de aviso. Para inserir mais de um aviso, separe os valores por meio de um ponto e vírgula (**;**). Por exemplo, para tratar C4001 e C4010 como erros, insira **4001; 4010**. Escolher **Okey** para salvar suas alterações e retornar para o **páginas de propriedade** caixa de diálogo.

1. Para definir a **/wo** opção, selecione a **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades. Insira a opção de compilador na **opções adicionais** caixa.

1. Escolher **Okey** para salvar suas alterações.

### <a name="to-set-the-compiler-option-programmatically"></a>Definir a opção do compilador de maneira programática

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarningLevel%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarnAsError%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableSpecificWarnings%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
