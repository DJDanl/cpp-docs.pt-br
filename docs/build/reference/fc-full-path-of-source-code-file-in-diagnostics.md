---
title: -FC (caminho completo do arquivo de código fonte no diagnóstico) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.UseFullPaths
- /FC
dev_langs:
- C++
helpviewer_keywords:
- /FC compiler option [C++]
- -FC compiler option [C++]
ms.assetid: 1f11414e-cb42-421b-be68-9d369aab036b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4a721b6887b6c5c07d96a79b06f05e6d7855250b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32373199"
---
# <a name="fc-full-path-of-source-code-file-in-diagnostics"></a>/FC (demarcador completo do arquivo de código-fonte no diagnóstico)

Faz com que o compilador para exibir o caminho completo de arquivos de código de origem passado para o compilador no diagnóstico.

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

Sem **/FC**, o texto de diagnóstico seria semelhante a este texto de diagnóstico:

- compiler_option_FC.cpp(5): erro C2143: erro de sintaxe: faltando ';' antes '}'

Com **/FC**, o texto de diagnóstico seria semelhante a este texto de diagnóstico:

- c:\test\compiler_option_fc.cpp(5): erro C2143: erro de sintaxe: faltando ';' antes '}'

 **/FC** também é necessária se você quiser ver o caminho completo de um nome de arquivo ao usar o &#95; &#95;arquivo&#95; &#95; macro. Consulte [Macros predefinidas](../../preprocessor/predefined-macros.md) para obter mais informações sobre &#95; &#95;arquivo&#95;&#95;.

O **/FC** opção indicada pelo **/ZI**. Para obter mais informações sobre **/ZI**, consulte [/Z7, /Zi, /ZI (Depurar formato de informações)](../../build/reference/z7-zi-zi-debug-information-format.md).

**/FC** gera caminhos completos em minúsculas.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **avançado** página de propriedades.

1. Modificar o **usar caminhos completos** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UseFullPaths%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
