---
title: /sdl (Habilitar verificações de segurança adicionais)
description: A opção Microsoft C/C++ Compiler/SDL permite verificações e avisos do SDL (ciclo de vida de desenvolvimento de segurança) recomendados.
ms.date: 10/02/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.SDLCheck
ms.assetid: 3dcf86a0-3169-4240-9f29-e04a9f535826
ms.openlocfilehash: 8d679bb3fc48e52bcc42a85d507618c38fd3dcdc
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765199"
---
# <a name="sdl-enable-additional-security-checks"></a>/sdl (Habilitar verificações de segurança adicionais)

Habilita verificações do SDL (ciclo de vida de desenvolvimento de segurança) recomendadas. Essas verificações alteram avisos relevantes de segurança em caso de erros e definem recursos de geração de código seguro adicionais.

## <a name="syntax"></a>Sintaxe

> **`/sdl`**[**`-`**]

## <a name="remarks"></a>Comentários

o **/SDL** habilita um superconjunto das verificações de segurança de linha de base fornecidas pelo [`/GS`](gs-buffer-security-check.md) e pelas substituições **`/GS-`** . Por padrão, **`/sdl`** é off. **`/sdl-`** desabilita as verificações de segurança adicionais.

### <a name="compile-time-checks"></a>Verificações de tempo de compilação

**`/sdl`** habilita estes avisos como erros:

| Aviso habilitado por/SDL | Opção de linha de comando equivalente | Descrição |
|--|--|--|
| [C4146](../../error-messages/compiler-warnings/compiler-warning-level-2-c4146.md) | /we4146 | Um operador de subtração unário foi aplicado a um tipo não assinado, resultando em um resultado não assinado. |
| [C4308](../../error-messages/compiler-warnings/compiler-warning-level-2-c4308.md) | /we4308 | Uma constante integral negativa convertida em tipo não assinado, resultando em um resultado possivelmente sem sentido. |
| [C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md) | /we4532 | O uso `continue` de `break` `goto` palavras-chave,, ou em um `__finally` / `finally` bloco tem comportamento indefinido durante o encerramento anormal. |
| [C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md) | /we4533 | O código inicializando uma variável não será executado. |
| [C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md) | /we4700 | Uso de uma variável local não inicializada. |
| [C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md) | /we4703 | Uso de uma variável de ponteiro local potencialmente não inicializada. |
| [C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md) | /we4789 | Saturação de buffer quando são usadas funções CRT (tempo de execução) de C específicas. |
| [C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md) | /we4995 | Uso de uma função marcada com pragma [`deprecated`](../../preprocessor/deprecated-c-cpp.md) . |
| [C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) | /we4996 | Uso de uma função marcada como [`deprecated`](../../cpp/deprecated-cpp.md) . |

### <a name="runtime-checks"></a>verificações de runtime

Quando **`/sdl`** é habilitado, o compilador gera o código que faz essas verificações em tempo de execução:

- Habilita o modo estrito de **`/GS`** detecção de estouro de buffer de tempo de execução, equivalente a compilação com `#pragma strict_gs_check(push, on)` .

- A limpeza de ponteiro é limitada. Em expressões que não envolvem desreferenciamentos e em tipos que não têm um destruidor definido pelo usuário, referências de ponteiro são definidas como um endereço não válido após uma chamada para **`delete`** . Essa limpeza ajuda a impedir a reutilização de referências de ponteiro obsoletas.

- Inicializa ponteiros de membro de classe. Inicializa automaticamente os membros de classe do tipo de ponteiro para a **`nullptr`** instanciação de objeto (antes da execução do Construtor). Ele ajuda a impedir o uso de ponteiros não inicializados que o construtor não inicializa explicitamente. A inicialização do ponteiro do membro gerado pelo compilador é chamada desde que:

  - O objeto não está alocado usando um personalizado (definido pelo usuário) `operator new`

  - O objeto não é alocado como parte de uma matriz (por exemplo `new A[x]` )

  - A classe não é gerenciada ou importada

  - A classe tem um construtor padrão definido pelo usuário.

  Para ser inicializado pela função de inicialização de classe gerada pelo compilador, um membro deve ser um ponteiro e não uma propriedade ou constante.

Para obter mais informações, consulte [Warnings,/SDL e melhorando a detecção de variáveis não inicializadas](https://www.microsoft.com/security/blog/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection/).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade geral**C/C++** Propriedades de configuração  >  **General** .

1. Defina a propriedade de **verificações do SDL** usando o controle suspenso propriedade. Escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
