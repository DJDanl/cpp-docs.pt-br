---
title: /GR (habilitar informações de tipo de tempo de execução)
ms.date: 11/04/2016
f1_keywords:
- /gr
- VC.Project.VCCLWCECompilerTool.RuntimeTypeInfo
- VC.Project.VCCLCompilerTool.RuntimeTypeInfo
helpviewer_keywords:
- -Gr compiler option [C++]
- Gr compiler option [C++]
- RTTI compiler option
- /Gr compiler option [C++]
- enable run-time type information compiler option [C++]
ms.assetid: d1f9f850-dcec-49fd-96ef-e72d01148906
ms.openlocfilehash: 15ad453b10fd31de97bbc25f8062e628129076f5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292114"
---
# <a name="gr-enable-run-time-type-information"></a>/GR (habilitar informações de tipo de tempo de execução)

Adiciona código para verificar tipos de objeto em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
/GR[-]
```

## <a name="remarks"></a>Comentários

Quando **/GR** estiver ativado, o compilador define o `_CPPRTTI` macro do pré-processador. Por padrão, **/GR** está em. **/GR-.** desabilita as informações de tipo de tempo de execução.

Use **/GR** se o compilador não consegue resolver estaticamente um tipo de objeto em seu código. Normalmente, você precisa de **/GR** quando seu código usa a opção [operador dynamic_cast](../../cpp/dynamic-cast-operator.md) ou [typeid](../../cpp/typeid-operator.md). No entanto, **/GR** aumenta o tamanho das seções da imagem. RDATA. Se seu código não usa **dynamic_cast** ou **typeid**, **/GR-.** pode produzir uma imagem menor.

Para obter mais informações sobre a verificação de tipo de tempo de execução, consulte [informações de tipo de tempo de execução](../../cpp/run-time-type-information.md) na *referência da linguagem C++*.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linguagem** página de propriedades.

1. Modificar a **habilitar informações de tipo de tempo de execução** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeTypeInfo%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
