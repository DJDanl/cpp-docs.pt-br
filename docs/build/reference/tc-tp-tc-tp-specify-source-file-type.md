---
title: /TC, /Tp, /TC, /TP (especificar tipo de arquivo de origem) | Microsoft Docs
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
ms.openlocfilehash: 9cb612d5c26fd4db51222c480539867d5e506b70
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="tc-tp-tc-tp-specify-source-file-type"></a>/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)

O **/Tc** opção especifica que o argumento de nome de arquivo é um arquivo de origem C, mesmo se ele não tem uma extensão. c. O **/Tp** opção especifica que o argumento de nome de arquivo é um arquivo de origem do C++, mesmo se ele não tem uma extensão. cpp ou. cxx. Um espaço entre a opção e o nome do arquivo é opcional. Cada opção especifica um arquivo. para especificar arquivos adicionais, repita a opção.

**/TC** e **/TP** global variantes de **/Tc** e **/Tp**. Eles especificam para o compilador trate todos os arquivos nomeados na linha de comando, como arquivos de origem C (**/TC**) ou arquivos de origem do C++ (**/TP**), independentemente do local na linha de comando em relação a opção. Essas opções global podem ser substituídas em um único arquivo por meio de **/Tc** ou **/Tp**.

## <a name="syntax"></a>Sintaxe

> **/Tc** _filename_  
> **/Tp** _filename_  
> **/TC**  
> **/TP**  

## <a name="arguments"></a>Arguments

*filename*  
Um arquivo de origem C ou C++.

## <a name="remarks"></a>Comentários

Por padrão, **CL** pressupõe que arquivos com a extensão. c são arquivos de origem C e arquivos com o. cpp ou. cxx extensão são arquivos de origem do C++.

Quando ambos os **TC** ou **Tc** opção for especificada, qualquer especificação do [/ZC: (wchar_t é do tipo nativo)](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção será ignorada.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **avançado** página de propriedades.

1. Modificar o **compilar como** propriedade. Escolha **Okey** ou **aplicar** para aplicar as alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAs%2A>.

## <a name="examples"></a>Exemplos

Esta linha de comando CL Especifica que MAIN.c, TEST.prg e COLLATE.prg são todos os arquivos de origem C. CL não reconhecerá PRINT.prg.

> CL PRINCIPAL. C /TcTEST.PRG /TcCOLLATE.PRG impressão. PRG

Esta linha de comando CL Especifica que TEST1.c, TEST2.cxx, TEST3.huh e TEST4.o são compilados como arquivos C++ e TEST5.z é compilado como um arquivo de C.

> CL TEST1. C TEST2. REALIZADO NO MERCADO3 CXX. NÃO É TEST4. O /Tc TEST5. /TP Z

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
