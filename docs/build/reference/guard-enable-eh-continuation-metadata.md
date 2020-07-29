---
title: /guard:ehcont (habilitar os metadados de continuação de EH)
description: 'Guia de referência para a opção de compilador/Guard: ehcont do Microsoft C++.'
ms.date: 06/03/2020
f1_keywords:
- /guard:ehcont
- VC.Project.VCCLCompilerTool.GuardEHContMetadata
helpviewer_keywords:
- /guard:ehcont
- /guard:ehcont compiler option
ms.openlocfilehash: c1b960bf13a6a7b7ff67996c9fa5119075216dae
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87190514"
---
# <a name="guardehcont-enable-eh-continuation-metadata"></a>/guard:ehcont (habilitar os metadados de continuação de EH)

Habilita a geração de metadados de EHCONT (continuidade de EH) pelo compilador.

## <a name="syntax"></a>Sintaxe

> **`/guard:ehcont`**[**`-`**]

## <a name="remarks"></a>Comentários

A **`/guard:ehcont`** opção faz com que o compilador gere uma lista classificada dos endereços virtuais relativos (RVA) de todos os destinos de continuação de tratamento de exceção válidos para um binário. Ele é usado durante o tempo de execução para `NtContinue` e a `SetThreadContext` validação do ponteiro de instrução. Por padrão, o **`/guard:ehcont`** está desativado e deve ser habilitado explicitamente. Para desabilitar explicitamente essa opção, use **`/guard:ehcont-`** .

A **`/guard:ehcont`** opção está disponível no Visual Studio 2019 versão 16,7 e posterior. O recurso tem suporte para processos de 64 bits em um sistema operacional de 64 bits.

A [tecnologia de aplicação de fluxo de controle (CET)](https://software.intel.com/sites/default/files/managed/4d/2a/control-flow-enforcement-technology-preview.pdf) é um recurso de segurança baseado em hardware que protege contra ataques baseados em ROP (programação orientada por retorno). Ele mantém uma "pilha de sombra" para cada pilha de chamadas para impor a integridade do fluxo de controle.

Quando as pilhas de sombra estão disponíveis para evitar ataques de ROP, os invasores se movem para usar outras técnicas de exploração. Uma técnica que eles podem usar é corromper o valor do ponteiro de instrução dentro da estrutura de [contexto](/windows/win32/api/winnt/ns-winnt-context) . Essa estrutura é passada em chamadas do sistema que redirecionam a execução de um thread, como `NtContinue` , [`RtlRestoreContext`](/windows/win32/api/winnt/nf-winnt-rtlrestorecontext) e [`SetThreadContext`](/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) . A `CONTEXT` estrutura é armazenada na memória. Corromper o ponteiro de instrução que ele contém pode fazer com que as chamadas do sistema transfiram a execução para um endereço controlado pelo invasor. No momento, `NTContinue` pode ser chamado com qualquer ponto de continuação. É por isso que é essencial validar o ponteiro de instrução quando as pilhas de sombra estão habilitadas.

`RtlRestoreContext`e `NtContinue` são usados durante o desenrolamento da exceção de manipulação de exceção estruturada (SEH) para desenrolar para o quadro de destino que contém o **`__except`** bloco. O ponteiro de instrução do **`__except`** bloco não deve estar na pilha de sombra, pois ele falharia na validação do ponteiro de instrução. A **`/guard:ehcont`** opção de compilador gera uma "tabela de continuação de eh". Ele contém uma lista classificada do RVAs de todos os destinos de continuação de tratamento de exceção válidos no binário. `NtContinue`Primeiro, verifica a pilha de sombra para o ponteiro de instrução fornecido pelo usuário e, se o ponteiro de instrução não for encontrado lá, ele continuará a verificar a tabela de continuação de EH a partir do binário que contém o ponteiro de instrução. Se o binário que o contém não tiver sido compilado com a tabela, então para compatibilidade com binários herdados, `NtContinue` poderá continuar. É importante distinguir entre binários herdados que não têm dados EHCONT e binários contendo dados EHCONT, mas sem entradas de tabela. O primeiro permitir todos os endereços dentro do binário como destinos de continuação válidos. O último não permite nenhum endereço dentro do binário como um destino de continuação válido.

A **`/guard:ehcont`** opção deve ser passada para o compilador e o vinculador para gerar RVAs de destino de continuação de eh para um binário. Se seu binário for criado usando um único `cl` comando, o compilador passará a opção para o vinculador. O compilador também passa a [**`/guard:cf`**](guard-enable-control-flow-guard.md) opção para o vinculador. Se você compilar e vincular separadamente, essas opções deverão ser definidas no compilador e nos comandos do vinculador.

Você pode vincular o código compilado usando o **`/guard:ehcont`** para bibliotecas e arquivos de objeto compilados sem ele. O vinculador retorna um erro fatal em qualquer um destes cenários:

- Uma seção de código tem "desenrolamento local". Para obter mais informações, consulte encerramento anormal na [instrução try-finally](../../cpp/try-finally-statement.md#abnormal-termination).

- Uma seção EH (XData) contém ponteiros para uma seção de código e elas não são para SEH.

- Os ponteiros são para SEH, mas o arquivo de objeto não foi compilado usando[/GY](gy-enable-function-level-linking.md)(vinculação no nível de função) para produzir COMDATs.

O vinculador retorna um erro fatal, pois não pode gerar metadados nesses cenários. Isso significa que gerar uma exceção provavelmente causará uma falha em tempo de execução.

Para informações da seção SEH encontradas em COMDATs, mas não compiladas usando **`/guard:ehcont`** , o vinculador emite o aviso **LNK4291**. Nesse caso, o vinculador gera metadados corretos, mas conservadores para a seção. Para ignorar esse aviso, use [/ignore (ignorar avisos específicos)](ignore-ignore-specific-warnings.md).

Se o vinculador não puder gerar metadados, ele emitirá um dos seguintes erros:

- **`LNK2046`**`: module contains _local_unwind but was not compiled with /guard:ehcont`

- **`LNK2047`**`: module contains C++ EH or complex EH metadata but was not compiled with /guard:ehcont.`

Para verificar se um binário contém dados EHCONT, procure os seguintes elementos ao despejar a configuração de carga do binário:

```cmd
e:\>link /dump /loadconfig CETTest.exe
...
            10417500 Guard Flags
...
                       EH Continuation table present      // EHCONT guard flag present
...
    0000000180018640 Guard EH continuation table
                  37 Guard EH continuation count          // May be 0 if no exception handling is used in the binary. Still counts has having EHCONT data.
...
    Guard EH Continuation Table                           // List of RVAs

          Address
          --------
           0000000180002CF5
           0000000180002F03
           0000000180002F0A
...
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração**de  >  geração de código**C/C++**  >  **Code Generation** .

1. Selecione a propriedade **habilitar metadados de continuação de eh** .

1. No controle suspenso, escolha **Sim (/Guard: ehcont)** para habilitar os metadados de continuação de eh ou **não (/Guard: ehcont-)** para desabilitá-lo.

## <a name="see-also"></a>Confira também

[/Guard (habilitar proteção de fluxo de controle)](guard-enable-control-flow-guard.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
