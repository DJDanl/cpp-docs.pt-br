---
title: /sdl (Habilitar verificações de segurança adicionais)
ms.date: 11/26/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.SDLCheck
ms.assetid: 3dcf86a0-3169-4240-9f29-e04a9f535826
ms.openlocfilehash: d5a85f9648ebcc4064146f22cf5da020e06b7ba3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218969"
---
# <a name="sdl-enable-additional-security-checks"></a>/sdl (Habilitar verificações de segurança adicionais)

Adiciona verificações recomendadas do SDL (ciclo de vida de desenvolvimento de segurança). Essas verificações incluem avisos adicionais relevantes de segurança como erros e recursos adicionais de geração de código seguro.

## <a name="syntax"></a>Sintaxe

> **`/sdl`**[**`-`**]

## <a name="remarks"></a>Comentários

o **/SDL** habilita um superconjunto das verificações de segurança de linha de base fornecidas pelo [`/GS`](gs-buffer-security-check.md) e pelas substituições **`/GS-`** . Por padrão, **`/sdl`** é off. **`/sdl-`** desabilita as verificações de segurança adicionais.

## <a name="compile-time-checks"></a>Verificações de tempo de compilação

**`/sdl`** habilita estes avisos como erros:

|Aviso habilitado por/SDL|Opção de linha de comando equivalente|Descrição|
|------------------------------|-------------------------------------|-----------------|
|[C4146](../../error-messages/compiler-warnings/compiler-warning-level-2-c4146.md)|/we4146|Um operador de subtração unário foi aplicado a um tipo não assinado, resultando em um resultado não assinado.|
|[C4308](../../error-messages/compiler-warnings/compiler-warning-level-2-c4308.md)|/we4308|Uma constante integral negativa convertida em tipo não assinado, resultando em um resultado possivelmente sem sentido.|
|[C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md)|/we4532|O uso de `continue` , `break` ou `goto` palavras-chave em um `__finally` / `finally` bloco tem comportamento indefinido durante o encerramento anormal.|
|[C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md)|/we4533|O código inicializando uma variável não será executado.|
|[C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|/we4700|Uso de uma variável local não inicializada.|
|[C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|/we4703|Uso de uma variável de ponteiro local potencialmente não inicializada.|
|[C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|/we4789|Saturação de buffer quando são usadas funções CRT (tempo de execução) de C específicas.|
|[C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|/we4995|Uso de uma função marcada com pragma [`deprecated`](../../preprocessor/deprecated-c-cpp.md) .|
|[C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|/we4996|Uso de uma função marcada como [`deprecated`](../../cpp/deprecated-cpp.md) .|

## <a name="runtime-checks"></a>verificações de runtime

Quando **`/sdl`** é habilitado, o compilador gera o código para executar essas verificações em tempo de execução:

- Habilita o modo estrito de **`/GS`** detecção de estouro de buffer de tempo de execução, equivalente a compilação com `#pragma strict_gs_check(push, on)` .

- Executa a limpeza limitada de ponteiro. Em expressões que não envolvem desreferenciamentos e em tipos que não têm um destruidor definido pelo usuário, referências de ponteiro são definidas como um endereço não válido após uma chamada para **`delete`** . Isso ajuda a evitar a reutilização de referências a ponteiros obsoletas.

- Executa a inicialização de ponteiro de membro de classe. Inicializa automaticamente os membros de classe do tipo de ponteiro para a **`nullptr`** instanciação de objeto (antes da execução do Construtor). Isso ajuda a impedir o uso de ponteiros não inicializados que o construtor não inicializa explicitamente. A inicialização do ponteiro do membro gerado pelo compilador é chamada desde que:

  - O objeto não é alocado usando um personalizado (definido pelo usuário)`operator new`

  - O objeto não é alocado como parte de uma matriz (por exemplo `new A[x]` )

  - A classe não é gerenciada ou importada

  - A classe tem um construtor padrão definido pelo usuário.

  Para ser inicializado pela função de inicialização de classe gerada pelo compilador, um membro deve ser um ponteiro e não uma propriedade ou constante.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Warnings,/SDL e melhorando a detecção de variáveis não inicializadas](https://cloudblogs.microsoft.com/microsoftsecure/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection/).

#### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a pasta **C/C++** .

1. Na página **geral** , selecione a opção na lista suspensa **verificações do SDL** .

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
