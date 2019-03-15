---
title: /GZ (habilitar verificação do erro de tempo de execução do quadro da pilha)
ms.date: 11/04/2016
f1_keywords:
- /gz
helpviewer_keywords:
- -GZ compiler option [C++]
- release-build errors
- /GZ compiler option [C++]
- GZ compiler option [C++]
- debug builds, catch release-build errors
ms.assetid: b3efeeff-d5e3-4057-91c9-f6fc73d0270c
ms.openlocfilehash: 3e6ffce487cc8183e45f3a911e7060ea22b28216
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810491"
---
# <a name="gz-enable-stack-frame-run-time-error-checking"></a>/GZ (habilitar verificação do erro de tempo de execução do quadro da pilha)

Executa as mesmas operações como o [/RTC (verificações de erro em tempo de execução)](rtc-run-time-error-checks.md) opção. Preterido.

## <a name="syntax"></a>Sintaxe

```
/GZ
```

## <a name="remarks"></a>Comentários

**/GZ** é apenas para uso em uma não otimizado ([/Od (desabilitar (Depurar))](od-disable-debug.md)) compilar.

**/GZ** foi preterido desde o Visual Studio 2005; use [/RTC (verificações de erro em tempo de execução)](rtc-run-time-error-checks.md) em vez disso. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
