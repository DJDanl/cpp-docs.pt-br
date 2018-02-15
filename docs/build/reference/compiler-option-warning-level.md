---
title: "-w,-W0,-W1, - W2,-W3, - W4,-S1,-w2,-w3,-w4,-parede, -wd,-, -wo, -Wv, - WX (nível de aviso) | Microsoft Docs"
ms.custom: 
ms.date: 01/31/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: be7e86065b52ee5c55058b9a672f3bf543454cf8
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="w-w0-w1-w2-w3-w4-w1-w2-w3-w4-wall-wd-we-wo-wv-wx-warning-level"></a>/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Warning Level)

Especifica como o compilador gerará avisos para uma determinada compilação.

## <a name="syntax"></a>Sintaxe

> **/w**  
> **/W0**  
> **/W1**  
> **/W2**  
> **/W3**  
> **/W4**  
> **/Wall**  
> **/Wv**\[**:**_version_]  
> **/WX**  
> **/w1**_warning_  
> **/w2**_warning_  
> **/w3**_warning_  
> **/w4**_warning_  
> **/wd**_warning_  
> **/we**_warning_  
> **/wo**_warning_  

## <a name="remarks"></a>Comentários

As opções de aviso especificam quais avisos do compilador para exibição e o comportamento de aviso para a compilação inteira.

As opções de aviso e argumentos relacionados são descritos na tabela a seguir:

|Opção|Descrição|
------------|-----------------|
|**/w**|Suprime todos os avisos do compilador.|
|**/W0**<br /><br /> **/W1**<br /><br /> **/W2**<br /><br /> **/W3**<br /><br /> **/W4**|Especifica o nível de avisos a serem gerados pelo compilador. Os níveis de aviso válido variam de 0 a 4:<br />**/ W0** Suprime todos os avisos. Isso é equivalente a **/w**.<br />**/ W1** exibe avisos de nível 1 (grave). **/ W1** é a configuração padrão, o compilador de linha de comando.<br />**/ W2** exibe nível 1 e avisos de nível 2 (significativos).<br />**/ W3** exibe nível 1, nível 2 e avisos de nível 3 (qualidade de produção). **/ W3** é a configuração padrão no IDE.<br />**/ S4** exibe nível 1, nível 2 e avisos de nível 3, e todos os nível 4 avisos (informativos) que não estão desativados por padrão. É recomendável que você use esta opção para fornecer pano como avisos. Para um novo projeto, talvez seja melhor usar **/W4** em todas as compilações; Isso garantirá os menor número defeitos de código de para localizar possíveis.|
|**/Wall**|Exibe todos os avisos são exibidos por **/W4** e todos os outros avisos que **/W4** não inclui — por exemplo, os avisos que são desativados por padrão. Para obter mais informações, consulte [compilador avisos que está desativada por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).|
|**/Wv**\[**:**_version_]|Exibe somente os avisos introduzidos na versão do compilador *versão* e versões anteriores. Você pode usar essa opção para suprimir avisos de novo no código, quando você migra para uma versão mais recente do compilador e para manter o processo de compilação existente enquanto você corrigi-los. O parâmetro opcional *versão* assume a forma  *nn* [. *mm*[. *bbbbb*]] onde  *nn*  é o número de versão principal, *mm* é o número de versão secundária opcional e *bbbbb* é o número de compilação opcional do compilador. Por exemplo, use */Wv:17* para exibir avisos introduzidos no Visual Studio 2012 (ou seja, qualquer versão do compilador que tem um número de versão principal de 17) ou anterior, mas suprimir avisos introduzidos no Visual Studio 2013 (versão principal 18) e posterior. Por padrão, **/Wv** usa o número de versão atual do compilador e não há avisos são suprimidos. Para obter informações sobre os quais os avisos são suprimidos pela versão do compilador, consulte [avisos do compilador pela versão do compilador](../..//error-messages/compiler-warnings/compiler-warnings-by-compiler-version.md).|
|**/WX**|Trata todos os avisos do compilador como erros. Para um novo projeto, talvez seja melhor usar **/WX** em todas as compilações; eliminar todos os avisos garante os menor número defeitos de código de para localizar possíveis.<br /><br /> O vinculador também tem um **/WX** opção. Para obter mais informações, consulte [/WX (Tratar Avisos do Vinculador como Erros)](../../build/reference/wx-treat-linker-warnings-as-errors.md).|
|**/w1**_nnnn_<br /><br /> **/w2**_nnnn_<br /><br /> **/w3**_nnnn_<br /><br /> **/w4**_nnnn_|Define o nível de aviso para o número de aviso especificado por  _nnnn_ . Isso lhe permite alterar o comportamento do compilador para que o aviso quando um nível de aviso específico é definido. Você pode usar essas opções em combinação com outras opções de aviso para impor padrões de seus próprio código para avisos, em vez do padrão fornecido pelo Visual Studio.<br /><br /> Por exemplo, **/w34326** faz com que C4326 seja gerado como um aviso de nível 3, em vez de nível 1. Se você compilar usando o **/w34326** opção e o **/W2** opção aviso C4326 não é gerado.|
|**/wd**_nnnn_|Suprime o aviso do compilador que é especificado pelo  _nnnn_ .<br /><br /> Por exemplo, **/wd4326** suprime C4326 de aviso do compilador.|
|**/we**_nnnn_|Trata o aviso do compilador que é especificado pelo  _nnnn_  como um erro.<br /><br /> Por exemplo, **/we4326** faz com que o número de aviso C4326 deve ser tratado como um erro pelo compilador.|
|**/wo**_nnnn_|Relatórios de aviso de compilador que é especificado pelo  _nnnn_  apenas uma vez.<br /><br /> Por exemplo, **/wo4326** causas aviso C4326 a ser relatado somente uma vez, na primeira vez que ela for encontrada pelo compilador.|

Se você usar qualquer uma das opções de aviso quando você criar um cabeçalho pré-compilado usando o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção, qualquer uso do cabeçalho pré-compilado usando o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção faz com que as mesmas opções de aviso estar em vigor novamente. Você pode substituir as opções de aviso definidas no cabeçalho pré-compilado usando outra opção de aviso na linha de comando.

Você pode usar um [#pragma aviso](../../preprocessor/warning.md) diretiva para controlar o nível de aviso que é relatado em tempo de compilação em arquivos de origem específico.

Diretivas pragma de aviso no código-fonte não são afetadas pelo **/w** opção.

O [documentação de erros de compilação](../../error-messages/compiler-errors-1/c-cpp-build-errors.md) descreve os avisos e níveis de aviso e indica por que determinadas instruções podem não ser compilados como você deseja.

### <a name="to-set-the-compiler-options-in-the-visual-studio-development-environment"></a>Para definir as opções de compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Para definir o **/W0**, **/W1**, **/W2**, **/W3**, **/W4**, **/parede**m **/Wv**, **/WX** ou **/WX-** opções, selecionadas o **propriedades de configuração** > **C / C++** > **geral** página de propriedades.

   - Para definir o **/W0**, **/W1**, **/W2**, **/W3**, **/W4**, ou **/parede** Opções, modificar o **nível de aviso** propriedade.

   - Para definir o **/WX** ou **/WX-** opções, modificar o **tratar avisos como erros** propriedade.

   - Para definir a versão para o **/Wv** opção, insira o número de versão do compilador no **aviso versão** propriedade.

1. Para definir o **/wd** ou **/we** opções, selecionadas o **propriedades de configuração** > **C/C++**  >   **Advanced** página de propriedades.

   - Para definir o **/wd** opção, selecione o **desativar avisos específicos** propriedade suspensa controle e, em seguida, escolha **editar**. Na caixa de edição no **desativar avisos específicos** caixa de diálogo, insira o número de aviso. Para inserir mais de um aviso, separe os valores por meio de um ponto e vírgula (**;**). Por exemplo, para desativar C4001 e C4010, digite **4001; 4010**. Escolha **Okey** para salvar suas alterações e retornar para o **páginas de propriedade** caixa de diálogo.

   - Para definir o **/we** opção, selecione o **tratar avisos específicos como erros** propriedade suspensa controle e, em seguida, escolha **editar**. Na caixa de edição no **tratar avisos específicos como erros** caixa de diálogo, insira o número de aviso. Para inserir mais de um aviso, separe os valores por meio de um ponto e vírgula (**;**). Por exemplo, para tratar C4001 e C4010 como erros, digite **4001; 4010**. Escolha **Okey** para salvar suas alterações e retornar para o **páginas de propriedade** caixa de diálogo.

1. Para definir o **/wo** opção, selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades. Insira a opção de compilador no **opções adicionais** caixa.

1. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-the-compiler-option-programmatically"></a>Para definir a opção de compilador programaticamente

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarningLevel%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarnAsError%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableSpecificWarnings%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
