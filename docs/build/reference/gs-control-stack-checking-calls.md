---
title: /Gs (controlar chamadas de verificação da pilha)
ms.date: 10/25/2018
f1_keywords:
- /GS
helpviewer_keywords:
- disabling stack probes
- GS compiler option [C++]
- /GS compiler option [C++]
- stack, stack probes
- stack probes
- -GS compiler option [C++]
- stack checking calls
ms.assetid: 40daed7c-f942-4085-b872-01e12b37729e
ms.openlocfilehash: e31b42c1d9422d44c5f106f40c4a60a38f23425b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62270842"
---
# <a name="gs-control-stack-checking-calls"></a>/Gs (controlar chamadas de verificação da pilha)

Controla o limite de sondas de pilha.

## <a name="syntax"></a>Sintaxe

> **/Gs**[*size*]

## <a name="arguments"></a>Arguments

*size*<br/>
(Opcional) O número de bytes que as variáveis locais podem ocupar antes que uma sonda de pilha seja iniciada. Não é permitido nenhum espaço entre **/Gs** e *tamanho*.

## <a name="remarks"></a>Comentários

Um *sonda de pilha* é uma sequência de código que o compilador insere no início de uma chamada de função. Quando iniciada, uma sonda de pilha atinge de maneira favorável a memória pela quantidade de espaço necessária para armazenar as variáveis locais da função. Isso faz com que o sistema operacional para a página de forma transparente na memória de pilha adicional, se necessário, antes de executa o restante da função.

Por padrão, o compilador gera o código que inicia uma sonda de pilha quando uma função exige mais de uma página de espaço de pilha. Isso é equivalente a uma opção de compilador **/Gs4096** para x86, x64, ARM, ARM64 plataformas e. Esse valor permite que um aplicativo e o gerenciador de memória do Windows aumentem a quantidade de memória confirmada dinamicamente para a pilha do programa no tempo de execução.

> [!NOTE]
> O valor padrão de **/Gs4096** permite que a pilha de aplicativos para Windows aumente corretamente no tempo de execução do programa. Recomendamos que o valor padrão não seja alterado a menos que você saiba exatamente por que deve alterá-lo.

Alguns programas, por exemplo, drivers de dispositivo virtual, não requerem esse mecanismo de aumento de pilha padrão. Nesses casos, as sondas de pilha não são necessárias e você pode interromper o compilador de gerá-las definindo *tamanho* como um valor que é maior do que qualquer função exigirá para o armazenamento de variável local.

**/ Gs0** inicia testes para cada chamada de função que requer o armazenamento para variáveis locais da pilha. Isso pode causar um impacto negativo no desempenho.

Para x64 tem como destino, se o **/Gs** opção for especificada sem uma *tamanho* argumento, ele é o mesmo que **/Gs0**. Se o *tamanho* argumento é de 1 a 9, D9014 de aviso será emitido e o efeito é o mesmo que especificar **/Gs0**.

Para x86, ARM, ARM64 metas e o **/Gs** opção sem um *tamanho* argumento é o mesmo que **/Gs4096**. Se o *tamanho* argumento é de 1 a 9, D9014 de aviso será emitido e o efeito é o mesmo que especificar **/Gs4096**.

Para todos os destinos, um *tamanho* argumento entre 10 e 2147485647 define o limite no valor especificado. Um *tamanho* de erro fatal de causas 2147485648 ou maior C1049.

Você pode ativar ou desativar as sondas de pilha usando o [check_stack](../../preprocessor/check-stack.md) diretiva. **/GS** e o `check_stack` pragma não têm efeito nas rotinas de biblioteca C padrão; elas afetam apenas as funções que você compilar.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira o **/Gs** opção de compilador e um tamanho opcional na **opções adicionais**. Escolher **Okey** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
