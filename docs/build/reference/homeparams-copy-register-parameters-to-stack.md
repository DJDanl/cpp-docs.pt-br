---
title: /homeparams (copiar parâmetros de registro para pilha)
ms.date: 11/04/2016
f1_keywords:
- /homeparams
helpviewer_keywords:
- /homeparams compiler option [C++]
- -homeparams compiler option [C++]
ms.assetid: 51067de4-24f7-436b-b8d9-bc867a7d53aa
ms.openlocfilehash: 952a38d2ab1268ee3dc1fda0899a3ba047281b44
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50518450"
---
# <a name="homeparams-copy-register-parameters-to-stack"></a>/homeparams (copiar parâmetros de registro para pilha)

Força os parâmetros passados em registros a serem gravados em seus locais na pilha mediante a entrada da função.

## <a name="syntax"></a>Sintaxe

```
/homeparams
```

## <a name="remarks"></a>Comentários

Essa opção do compilador é apenas para x64 compiladores (native e compilação cruzada).

Quando os parâmetros são passados em x64 compilação, as convenções de chamada exigem stackspace para parâmetros, mesmo para os parâmetros passados em registros. Para obter mais informações, consulte [passagem de parâmetro](../../build/parameter-passing.md). No entanto, por padrão na compilação de versão, os parâmetros de registro serão não gravados para a pilha, no espaço do que já é fornecido para os parâmetros. Isso torna difícil de depurar uma compilação otimizada (versão) do seu programa.

Para um build de versão, use **/homeparams** para garantir que você pode depurar seu aplicativo. **/homeparams** implica uma desvantagem de desempenho, porque ele requer um ciclo para carregar os parâmetros de registro na pilha.

Em uma compilação de depuração, a pilha sempre é preenchida com os parâmetros passados em registros.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)