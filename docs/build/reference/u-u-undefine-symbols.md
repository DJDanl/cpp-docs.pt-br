---
title: /U, /u (indefinir símbolos)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLWCECompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLCompilerTool.UndefineAllPreprocessorDefinitions
- /u
- VC.Project.VCCLWCECompilerTool.UndefineAllPreprocessorDefinitions
helpviewer_keywords:
- -U compiler option [C++]
- Undefine Symbols compiler option
- /U compiler option [C++]
- U compiler option [C++]
ms.assetid: 7bc0474f-6d1f-419b-807d-0d8816763b2a
ms.openlocfilehash: bfc03ebd5c900bf8bf81b4a50eed02111baf85ee
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822477"
---
# <a name="u-u-undefine-symbols"></a>/U, /u (indefinir símbolos)

O **/U** remoções de definições de opção de compilador o símbolo do pré-processador especificado. O **/u** os símbolos de específico da Microsoft que o compilador define remoções de definições de opção de compilador.

## <a name="syntax"></a>Sintaxe

```
/U[ ]symbol
/u
```

## <a name="arguments"></a>Arguments

*symbol*<br/>
O símbolo do pré-processador a excluir.

## <a name="remarks"></a>Comentários

Nem o **/U** ou **/u** opção pode excluir um símbolo criado usando o **#define** diretiva.

O **/U** opção pode excluir um símbolo que foi anteriormente definido usando o **/D** opção.

Por padrão, o compilador define símbolos de específico da Microsoft a seguir.

|Símbolo|Função|
|------------|--------------|
|_CHAR_UNSIGNED|O tipo char padrão não está assinado. Definido quando o [/J](j-default-char-type-is-unsigned.md) opção for especificada.|
|_CPPRTTI|Definido para o código compilado com o [/GR](gr-enable-run-time-type-information.md) opção.|
|_CPPUNWIND|Definido para o código compilado com o [/EHsc](eh-exception-handling-model.md) opção.|
|_DLL|Definido quando o [/MD](md-mt-ld-use-run-time-library.md) opção for especificada.|
|_M_IX86|Por padrão, definido como 600 para x86 de destinos.|
|_MSC_VER|Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).|
|_WIN32|Definido para aplicativos WIN32. Sempre definido.|
|_MT|Definido quando o [/MD ou /MT](md-mt-ld-use-run-time-library.md) opção for especificada.|

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **excluir definições de pré-processador** ou **cancele todas as definições de pré-processador** propriedades.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefineAllPreprocessorDefinitions%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefinePreprocessorDefinitions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/J (o tipo char padrão não é assinado)](j-default-char-type-is-unsigned.md)<br/>
[/GR (habilitar informações de tipo em tempo de execução)](gr-enable-run-time-type-information.md)<br/>
[/EH (modelo de tratamento de exceções)](eh-exception-handling-model.md)<br/>
[/MD, /MT, /LD (usar biblioteca de tempo de execução)](md-mt-ld-use-run-time-library.md)
