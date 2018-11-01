---
title: /await (Habilitar suporte de corrotina)
ms.date: 08/15/2017
f1_keywords:
- /await
- -await
helpviewer_keywords:
- /await enable coroutine support [C++]
- -await enable coroutine support [C++]
- await enable coroutine support [C++]
ms.assetid: 302c8e69-09b6-4c58-bcdd-0a6a8713a8df
ms.openlocfilehash: e3f7359b60e1ba22c2646cecfd35b827919ae033
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590419"
---
# <a name="await-enable-coroutine-support"></a>/await (Habilitar suporte de corrotina)

Use o **/ await** opção do compilador para habilitar o suporte de compilador para as co-rotinas.

## <a name="syntax"></a>Sintaxe

> / await

## <a name="remarks"></a>Comentários

O **/await** opção de compilador habilita o suporte de compilador para as corrotinas do C++ e as palavras-chave **co_await**, **co_yield**, e **co_return**. Essa opção fica desativada por padrão. Para obter informações sobre o suporte para corrotinas no Visual Studio, consulte o [Blog da equipe do Visual Studio](https://blogs.msdn.microsoft.com/vcblog/category/coroutine/). Para obter mais informações sobre a proposta de co-rotinas padrão, consulte [N4628 rascunho de trabalho, especificação técnica para extensões de C++ para as co-rotinas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/n4628.pdf).

O **/ await** opção está disponível a partir no Visual Studio 2015.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

1. Sob **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **linha de comando** página de propriedades.

1. Insira o **/ await** opção de compilador na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
