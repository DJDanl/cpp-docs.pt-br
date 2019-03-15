---
title: /Diagnostics (opções do compilador diagnóstico)
ms.date: 11/11/2016
f1_keywords:
- /diagnostics
- VC.Project.VCCLCompilerTool.DiagnosticsFormat
helpviewer_keywords:
- /diagnostics compiler diagnostic options [C++]
- -diagnostics compiler diagnostic options [C++]
- diagnostics compiler diagnostic options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
ms.openlocfilehash: 6b7d043e00204fa191530f03bbed069d71a25fc5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822295"
---
# <a name="diagnostics-compiler-diagnostic-options"></a>/Diagnostics (opções do compilador diagnóstico)

Use o **/diagnostics** opção de compilador para especificar a exibição de informações de local de erro e aviso.

## <a name="syntax"></a>Sintaxe

```
/diagnostics:{caret|classic|column}
```

## <a name="remarks"></a>Comentários

Essa opção tem suporte no Visual Studio 2017 e posterior.

O **/diagnostics** opção de compilador controla a exibição de informações de aviso e erro.

O **/diagnostics:classic** é a opção padrão, que informa apenas o número de linha em que o problema foi encontrado.

O **/diagnostics:column** opção também inclui a coluna onde o problema foi encontrado. Isso pode ajudá-lo a identificar o constructo de linguagem específica ou um caractere que está causando o problema.

O **/diagnostics:caret** opção inclui a coluna onde o problema foi encontrado e coloca um acento circunflexo (^) no local na linha de código em que o problema foi detectado.

Observe que, em alguns casos, o compilador não detecta um problema em que ele ocorreu. Por exemplo, um ponto e vírgula ausente pode não ser detectado até que os símbolos de outros, inesperados foram encontrados. A coluna é informada e o cursor é colocado em que o compilador detectou que algo estiver errado, o que nem sempre é onde você precisa fazer sua correção.

O **/diagnostics** opção está disponível a partir do Visual Studio 2017.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Sob **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **geral** página de propriedades.

1. Use o controle de lista suspensa na **formato de diagnóstico** opção de exibição de campo para selecionar um diagnóstico. Escolher **Okey** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
