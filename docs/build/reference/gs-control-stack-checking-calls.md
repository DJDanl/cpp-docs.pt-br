---
title: -Gs (controlar pilha chamadas de verificação) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /GS
dev_langs:
- C++
helpviewer_keywords:
- disabling stack probes
- GS compiler option [C++]
- /GS compiler option [C++]
- stack, stack probes
- stack probes
- -GS compiler option [C++]
- stack checking calls
ms.assetid: 40daed7c-f942-4085-b872-01e12b37729e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 38b97354408d87d862955c0883c72d3e1459aa61
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45719260"
---
# <a name="gs-control-stack-checking-calls"></a>/Gs (controlar chamadas de verificação da pilha)

Controla investigações de pilha.

## <a name="syntax"></a>Sintaxe

```
/Gs[size]
```

## <a name="arguments"></a>Arguments

*size*<br/>
(Opcional) O número de bytes que as variáveis locais podem ocupar antes que uma sonda de pilha seja iniciada. Se o **/Gs** opção for especificada sem uma `size` argumento, ele é o mesmo que especificar **/Gs0**,

## <a name="remarks"></a>Comentários

Uma sonda de pilha é uma sequência de códigos que o compilador insere em cada chamada de função. Quando iniciada, uma sonda de pilha atinge de maneira favorável a memória pela quantidade de espaço necessária para armazenar as variáveis locais da função.

Se uma função exigir mais que `size` bytes de espaço de pilha para variáveis locais, sua sonda de pilha é iniciada. Por padrão, o compilador gera o código que inicia uma sonda de pilha quando uma função exige mais de uma página de espaço de pilha. Isso é equivalente a uma opção de compilador **/Gs4096** para plataformas ARM, x86 e x64. Esse valor permite que um aplicativo e o gerenciador de memória do Windows aumentem a quantidade de memória confirmada dinamicamente para a pilha do programa no tempo de execução.

> [!NOTE]
>  O valor padrão de **/Gs4096** permite que a pilha de aplicativos para Windows aumente corretamente no tempo de execução do programa. Recomendamos que o valor padrão não seja alterado a menos que você saiba exatamente por que deve alterá-lo.

Alguns programas, por exemplo, drivers de dispositivo virtual, não requerem esse mecanismo de aumento de pilha padrão. Nesses casos, as sondas de pilha não são necessárias e você pode fazer com que o compilador deixe de gerá-las configurando `size` para um valor maior que aquilo que qualquer função exigirá para o armazenamento local da variável. Não é permitido nenhum espaço entre **/Gs** e `size`.

**/ Gs0** ativa sondas de pilha para cada chamada de função que requer o armazenamento para variáveis locais. Isso pode causar um impacto negativo no desempenho.

Você pode ativar ou desativar as sondas de pilha usando [check_stack](../../preprocessor/check-stack.md). **/GS** e o `check_stack` pragma não têm efeito nas rotinas de biblioteca C padrão; elas afetam apenas as funções que você compilar.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)