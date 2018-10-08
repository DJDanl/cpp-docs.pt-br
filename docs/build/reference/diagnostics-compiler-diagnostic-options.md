---
title: -diagnostics (opções do compilador diagnóstico) | Microsoft Docs
ms.custom: ''
ms.date: 11/11/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /diagnostics
- VC.Project.VCCLCompilerTool.DiagnosticsFormat
dev_langs:
- C++
helpviewer_keywords:
- /diagnostics compiler diagnostic options [C++]
- -diagnostics compiler diagnostic options [C++]
- diagnostics compiler diagnostic options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2d0e6567f8666df4ec170ad7911ef08f5a1d335
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861623"
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

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
