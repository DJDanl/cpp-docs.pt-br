---
title: /Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)
ms.date: 01/11/2018
f1_keywords:
- VC.Project.VCCLWCECompilerTool.CompileAs
- VC.Project.VCCLCompilerTool.CompileAs
- /Tp
- /tc
helpviewer_keywords:
- Tp compiler option [C++]
- /Tc compiler option [C++]
- -Tc compiler option [C++]
- source files, specifying to compiler
- Tc compiler option [C++]
- /Tp compiler option [C++]
- -Tp compiler option [C++]
ms.openlocfilehash: c93da6d2498d46e4b7bf3ad37dde852bb6bc82a1
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70927624"
---
# <a name="tc-tp-tc-tp-specify-source-file-type"></a>/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)

A opção **/TC** especifica que seu argumento filename é um arquivo de origem C, mesmo que não tenha uma extensão. C. A opção **/TP** especifica que seu argumento filename é um C++ arquivo de origem, mesmo que ele não tenha uma extensão. cpp ou. cxx. Um espaço entre a opção e o nome de arquivo é opcional. Cada opção especifica um arquivo; para especificar arquivos adicionais, repita a opção.

**/TC** e **/TP** são variantes globais de **/TC** e **/TP**. Eles especificam o compilador para tratar todos os arquivos nomeados na linha de comando como C **/TC**(arquivos de C++ origem) ou **/TP**(arquivos de origem), sem considerar o local na linha de comando em relação à opção. Essas opções globais podem ser substituídas em um único arquivo por meio de **/TC** ou **/TP**.

## <a name="syntax"></a>Sintaxe

> **/Tc** _filename_
>  **/Tp** _filename_
>  **/TC**
>  **/TP**

## <a name="arguments"></a>Arguments

*filename*<br/>
Um arquivo C C++ ou de origem.

## <a name="remarks"></a>Comentários

Por padrão, **CL** pressupõe que os arquivos com a extensão. c são arquivos de origem c e arquivos com a extensão. cpp ou. cxx C++ são arquivos de origem.

Quando a opção **TC** ou **TC** for especificada, qualquer especificação da opção [/Zc: Wchar_t (wchar_t é do tipo nativo)](zc-wchar-t-wchar-t-is-native-type.md) será ignorada.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração** >  > **C/C++** **avançado** .

1. Modifique a propriedade **Compilar como** . Escolha **OK** ou **aplicar** para aplicar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAs%2A>.

## <a name="examples"></a>Exemplos

Essa linha de comando CL especifica que MAIN. c, TEST. prg e COLLATE. prg são todos os arquivos de origem C. CL não reconhecerá PRINT. prg.

> CL PRINCIPAL. C/TcTEST.PRG/TcCOLLATE.PRG PRINT. PRG

Essa linha de comando CL especifica que TEST1. c, TEST2. cxx, TEST3. e TEST4. o são compilados C++ como arquivos e TEST5. z é compilado como um arquivo c.

> CL TEST1.C TEST2.CXX TEST3.HUH TEST4.O /Tc TEST5.Z /TP

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
