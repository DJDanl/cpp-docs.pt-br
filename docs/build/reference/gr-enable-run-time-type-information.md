---
title: /GR (habilitar informações de tipo de tempo de execução)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.RuntimeTypeInfo
- VC.Project.VCCLCompilerTool.RuntimeTypeInfo
helpviewer_keywords:
- -Gr compiler option [C++]
- Gr compiler option [C++]
- RTTI compiler option
- /Gr compiler option [C++]
- enable run-time type information compiler option [C++]
ms.assetid: d1f9f850-dcec-49fd-96ef-e72d01148906
ms.openlocfilehash: 974a2b38c793b21abc9f17f5b7ca5c9f5e3305f5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215225"
---
# <a name="gr-enable-run-time-type-information"></a>/GR (habilitar informações de tipo de tempo de execução)

Adiciona o código para verificar os tipos de objeto em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
/GR[-]
```

## <a name="remarks"></a>Comentários

Quando **/gr** está on, o compilador define a `_CPPRTTI` macro de pré-processador. Por padrão, **/gr** está on. **/Gr-** desabilita informações de tipo em tempo de execução.

Use **/gr** se o compilador não puder resolver estaticamente um tipo de objeto em seu código. Normalmente, você precisa da opção **/gr** quando seu código usa [dynamic_cast operador](../../cpp/dynamic-cast-operator.md) ou [typeid](../../cpp/typeid-operator.md). No entanto, **/gr** aumenta o tamanho das seções. rdata da sua imagem. Se seu código não usar **`dynamic_cast`** ou **`typeid`** , **/gr-** poderá produzir uma imagem menor.

Para obter mais informações sobre a verificação de tipo em tempo de execução, consulte [informações de tipo de tempo de execução](../../cpp/run-time-type-information.md) na referência de linguagem do *C++*.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++** .

1. Clique na página de propriedades **idioma** .

1. Modifique a propriedade de **informações do tipo habilitar tempo de execução** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeTypeInfo%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
