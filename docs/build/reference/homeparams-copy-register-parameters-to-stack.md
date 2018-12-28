---
title: /homeparams (copiar parâmetros de registro para pilha)
ms.date: 12/17/2018
f1_keywords:
- /homeparams
helpviewer_keywords:
- /homeparams compiler option [C++]
- -homeparams compiler option [C++]
ms.assetid: 51067de4-24f7-436b-b8d9-bc867a7d53aa
ms.openlocfilehash: ffb5ca602feb7a369bb31d0277834786d66ac12a
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53627391"
---
# <a name="homeparams-copy-register-parameters-to-stack"></a>/homeparams (copiar parâmetros de registro para pilha)

Força os parâmetros passados em registros também ser gravados em seus locais na pilha mediante a entrada da função.

## <a name="syntax"></a>Sintaxe

> **/homeparams**

## <a name="remarks"></a>Comentários

Essa opção do compilador só está disponível nos compiladores que direcionam x64 e nativo.

A convenção de chamada de x64 requer espaço na pilha a ser alocado para todos os parâmetros, mesmo para os parâmetros passados em registros. Para obter mais informações, consulte [passagem de parâmetro](../../build/x64-calling-convention.md#parameter-passing). Por padrão, os parâmetros de registro não são copiados para o espaço de pilha alocado para eles em compilações de versão. Isso torna difícil de depurar um build de versão otimizada do programa.

Para builds de versão, você pode usar o **/homeparams** opção para forçar o compilador para copiar registrar parâmetros para a pilha, para garantir que você pode depurar seu aplicativo. **/homeparams** implica uma desvantagem de desempenho, porque ele requer um ciclo extra para carregar os parâmetros de registro para a pilha.

Em compilações de depuração, a pilha sempre é preenchida com os parâmetros passados em registros.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)