---
title: /Od (desabilitar [depuração])
ms.date: 11/04/2016
f1_keywords:
- /od
helpviewer_keywords:
- no optimizations
- fast compiling
- /Od compiler option [C++]
- disable optimizations
- Od compiler option [C++]
- -Od compiler option [C++]
- disable (debug) compiler option [C++]
ms.assetid: b1ac31b7-e086-4eeb-be5e-488f7513f5f5
ms.openlocfilehash: b7cbf8de06e698e67e370eb399da5bb00b262895
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595787"
---
# <a name="od-disable-debug"></a>/Od (desabilitar [depuração])

Desativa todas as otimizações no programa e acelera a compilação.

## <a name="syntax"></a>Sintaxe

```
/Od
```

## <a name="remarks"></a>Comentários

Essa opção é o padrão. Porque **/Od** suprime a movimentação de código, ele simplifica o processo de depuração. Para obter mais informações sobre as opções do compilador para depuração, consulte [/Z7, /Zi, /ZI (formato de informações de depuração)](../../build/reference/z7-zi-zi-debug-information-format.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **otimização** página de propriedades.

1. Modificar a **otimização** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Z7, /Zi, /ZI (Formato de Informações de Depuração)](../../build/reference/z7-zi-zi-debug-information-format.md)