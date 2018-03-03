---
title: "-FC (caminho completo do arquivo de código fonte no diagnóstico) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.UseFullPaths
- /FC
dev_langs:
- C++
helpviewer_keywords:
- /FC compiler option [C++]
- -FC compiler option [C++]
ms.assetid: 1f11414e-cb42-421b-be68-9d369aab036b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b055b5431d41bc09fbdd2750c01d3efca8f21287
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

- c:\test\compiler_option_FC.cpp(5): erro C2143: erro de sintaxe: faltando ';' antes '}'

**/FC** também é necessária se você quiser ver o caminho completo de um nome de arquivo ao usar o &#95; &#95; ARQUIVO &#95; &#95; macro.  Consulte [Macros predefinidas](../../preprocessor/predefined-macros.md) para obter mais informações sobre &#95; &#95; ARQUIVO &#95; &#95;.

O **/FC** opção indicada pelo **/ZI**. Para obter mais informações sobre **/ZI**, consulte [/Z7, /Zi, /ZI (Depurar formato de informações)](../../build/reference/z7-zi-zi-debug-information-format.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **propriedades de configuração** nó.

1. Expanda o **C/C++** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar o **usar caminhos completos** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UseFullPaths%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)