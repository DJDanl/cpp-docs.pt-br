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
ms.openlocfilehash: ee1398b2f9ee78c62fb84aa591e77708cd0d9d83
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439590"
---
# <a name="gr-enable-run-time-type-information"></a>/GR (habilitar informações de tipo de tempo de execução)

Adiciona o código para verificar os tipos de objeto em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
/GR[-]
```

## <a name="remarks"></a>Comentários

Quando **/gr** está on, o compilador define a macro de pré-processador de `_CPPRTTI`. Por padrão, **/gr** está on. **/Gr-** desabilita informações de tipo em tempo de execução.

Use **/gr** se o compilador não puder resolver estaticamente um tipo de objeto em seu código. Normalmente, você precisa da opção **/gr** quando seu código usa [dynamic_cast operador](../../cpp/dynamic-cast-operator.md) ou [typeid](../../cpp/typeid-operator.md). No entanto, **/gr** aumenta o tamanho das seções. rdata da sua imagem. Se o seu código não usar **dynamic_cast** ou **typeid**, **/gr-** poderá produzir uma imagem menor.

Para obter mais informações sobre a verificação de tipo em tempo de execução, consulte [informações de tipo de tempo de execução](../../cpp/run-time-type-information.md) na referência de  *C++ linguagem*.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades **idioma** .

1. Modifique a propriedade de **informações do tipo habilitar tempo de execução** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeTypeInfo%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
