---
title: /FC (demarcador completo do arquivo de código-fonte no diagnóstico)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.UseFullPaths
- /FC
helpviewer_keywords:
- /FC compiler option [C++]
- -FC compiler option [C++]
ms.assetid: 1f11414e-cb42-421b-be68-9d369aab036b
ms.openlocfilehash: 190174e1e2ac4d160140ddc54f9cc1c3a1b31709
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809022"
---
# <a name="fc-full-path-of-source-code-file-in-diagnostics"></a>/FC (demarcador completo do arquivo de código-fonte no diagnóstico)

Faz com que o compilador para exibir o caminho completo de arquivos de código-fonte passados para o compilador no diagnóstico.

## <a name="syntax"></a>Sintaxe

> /FC

## <a name="remarks"></a>Comentários

Considere o exemplo de código a seguir:

```cpp
// compiler_option_FC.cpp
int main( ) {
   int i   // C2143
}
```

Sem **/FC**, o texto de diagnóstico seria semelhante ao seguinte texto de diagnóstico:

- compiler_option_FC.cpp(5) : error C2143: syntax error : missing ';' before '}'

Com o **/FC**, o texto de diagnóstico seria semelhante ao seguinte texto de diagnóstico:

- c:\test\compiler_option_fc.cpp(5) : error C2143: syntax error : missing ';' before '}'

**/FC** também é necessário se você quiser ver o caminho completo de um nome de arquivo ao usar o &#95; &#95;arquivo&#95; &#95; macro. Ver [Macros predefinidas](../../preprocessor/predefined-macros.md) para obter mais informações sobre &#95; &#95;arquivo&#95;&#95;.

O **/FC** opção é indicada pela **/ZI**. Para obter mais informações sobre **/ZI**, consulte [/Z7, /Zi, /ZI (formato de informações de depuração)](z7-zi-zi-debug-information-format.md).

**/FC** gera caminhos completos em letras minúsculas.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **avançado** página de propriedades.

1. Modificar a **usar caminhos completos** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UseFullPaths%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
