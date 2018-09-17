---
title: /TC, /Tp, /TC, /TP (especificar tipo de fonte de arquivo) | Microsoft Docs
ms.date: 1/11/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.CompileAs
- VC.Project.VCCLCompilerTool.CompileAs
- /Tp
- /tc
dev_langs:
- C++
helpviewer_keywords:
- Tp compiler option [C++]
- /Tc compiler option [C++]
- -Tc compiler option [C++]
- source files, specifying to compiler
- Tc compiler option [C++]
- /Tp compiler option [C++]
- -Tp compiler option [C++]
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1c6c264a11e4cec478502fbd0e1837ceba450ba9
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714292"
---
# <a name="tc-tp-tc-tp-specify-source-file-type"></a>/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)

O **/Tc** opção especifica que o argumento de nome de arquivo é um arquivo de origem de C, mesmo se ele não tem uma extensão. c. O **/Tp** opção especifica que o argumento de nome de arquivo é um arquivo de origem do C++, mesmo se ele não tem uma extensão. cpp ou. cxx. Um espaço entre a opção e o nome do arquivo é opcional. Cada opção especifica um arquivo; para especificar arquivos adicionais, repita a opção.

**/TC** e **/TP** são variantes globais dos **/Tc** e **/Tp**. Ele especificar para o compilador trate todos os arquivos nomeados na linha de comando, como arquivos de origem de C (**/TC**) ou arquivos de origem do C++ (**/TP**), independentemente do local na linha de comando em relação a opção. Essas opções globais podem ser substituídas em um único arquivo por meio da **/Tc** ou **/Tp**.

## <a name="syntax"></a>Sintaxe

> **/TC** _filename_
>  **/Tp** _filename_
>  **/TC** 
>  **/TP**

## <a name="arguments"></a>Arguments

*filename*<br/>
Um arquivo de origem C ou C++.

## <a name="remarks"></a>Comentários

Por padrão, **CL** pressupõe que os arquivos com a extensão. c são arquivos de origem C e arquivos com o. cpp ou. cxx extensão são arquivos de origem C++.

Quando ambos os **TC** ou **Tc** opção for especificada, qualquer especificação da [/ZC: wchar_t (wchar_t Is Native Type)](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção será ignorada.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **avançado** página de propriedades.

1. Modificar a **compilar como** propriedade. Escolher **Okey** ou **aplicar** para aplicar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAs%2A>.

## <a name="examples"></a>Exemplos

Essa linha de comando CL Especifica que o Main. c, TEST.prg e COLLATE.prg são todos os arquivos de origem de C. CL não reconhecerá PRINT.prg.

> CL MAIN. C /TcTEST.PRG /TcCOLLATE.PRG PRINT. PRG

Essa linha de comando CL Especifica que TEST1.c, TEST2.cxx, TEST3.huh e TEST4.o são compilados como arquivos de C++ e TEST5.z é compilado como um arquivo de C.

> CL TEST1. C TEST2. CXX TEST3. NÉ TEST4. TEST5 de /Tc e S. /TP Z

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
