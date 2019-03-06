---
title: /sdl (Habilitar verificações de segurança adicionais)
ms.date: 11/26/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.SDLCheck
ms.assetid: 3dcf86a0-3169-4240-9f29-e04a9f535826
ms.openlocfilehash: dd37dae4927531b86cfdac274493b945b066760a
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413089"
---
# <a name="sdl-enable-additional-security-checks"></a>/sdl (Habilitar verificações de segurança adicionais)

Adiciona verificações do Security Development Lifecycle (SDL) recomendado. Essas verificações incluem segurança extra relevantes avisos como erros e recursos de geração de código seguro adicional.

## <a name="syntax"></a>Sintaxe

```
/sdl[-]
```

## <a name="remarks"></a>Comentários

**/SDL** permite que um superconjunto das verificações de segurança da linha de base fornecido pelo [/GS](../../build/reference/gs-buffer-security-check.md) e substituições **/GS-**. Por padrão, **/sdl** está desativado. **/SDL-** desabilita as verificações de segurança adicional.

## <a name="compile-time-checks"></a>Verificações de tempo de compilação

**/SDL** habilita esses avisos como erros:

|Aviso habilitado por /sdl|Opção de linha de comando equivalente|Descrição|
|------------------------------|-------------------------------------|-----------------|
|[C4146](../../error-messages/compiler-warnings/compiler-warning-level-2-c4146.md)|/we4146|Operador de subtração unário foi aplicado a um tipo sem sinal, resultando em um resultado não assinado.|
|[C4308](../../error-messages/compiler-warnings/compiler-warning-level-2-c4308.md)|/we4308|Uma constante integral negativa convertida para tipo unsigned, resultando em um resultado possivelmente sem sentido.|
|[C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md)|/we4532|Uso de `continue`, `break` ou `goto` palavras-chave em um `__finally` / `finally` bloco tem um comportamento indefinido durante um encerramento anormal.|
|[C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md)|/we4533|Inicializando uma variável de código não será executado.|
|[C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|/we4700|Uso de uma variável local não inicializada.|
|[C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|/we4703|Uso de uma variável de ponteiro local potencialmente não inicializada.|
|[C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|/we4789|Estouro quando funções específicas de tempo de execução (CRT) de C são usadas de buffer.|
|[C4995](../../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md)|/we4995|Uso de uma função marcada com o pragma [preterido](../../preprocessor/deprecated-c-cpp.md).|
|[C4996](../../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md)|/we4996|Uso de uma função marcada como [preterido](../../cpp/deprecated-cpp.md).|

## <a name="runtime-checks"></a>Verificações de tempo de execução

Quando **/sdl** é habilitado, o compilador gera código para executar essas verificações em tempo de execução:

- Habilita o modo estrito de **/GS** detecção de estouro de buffer de tempo de execução, equivalente ao compilar com `#pragma strict_gs_check(push, on)`.

- Executa a limpeza de ponteiro limitado. Em expressões que não envolvem cancela a referência e tipos que não têm nenhum destruidor definido pelo usuário, as referências do ponteiro são definidas como um endereço inválido após uma chamada para `delete`. Isso ajuda a evitar a reutilização de referências do ponteiro obsoletos.

- Executa a inicialização de ponteiro de membro de classe. Automaticamente membros de tipo de ponteiro para a classe do inicializa **nullptr** na instanciação do objeto (antes da execução do construtor). Isso ajuda a impedir o uso de ponteiros não inicializados que o construtor inicializa explicitamente. A inicialização de ponteiro gerado pelo compilador membro é chamada, desde:

  - O objeto não é alocado usando um personalizado (definido pelo usuário) `operator new`

  - O objeto não está alocado como parte de uma matriz (por exemplo `new A[x]`)

  - A classe não é gerenciada ou importada

  - A classe tem um construtor padrão definido pelo usuário.

  Para ser inicializado pela função de inicialização de classe gerado pelo compilador, um membro deve ser um ponteiro e não uma propriedade ou constante.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [avisos, /sdl e melhorando a detecção de variáveis não inicializada](https://cloudblogs.microsoft.com/microsoftsecure/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection/).

#### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Sobre o **gerais** , selecione a opção do **verificações do SDL** lista suspensa.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
