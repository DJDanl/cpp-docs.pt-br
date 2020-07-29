---
title: /guard (habilitar proteção do fluxo de controle)
ms.date: 11/04/2016
f1_keywords:
- /guard
- VC.Project.VCCLCompilerTool.ControlFlowGuard
ms.assetid: be495323-f59f-4cf3-a6b6-8ee69e6a19dd
ms.openlocfilehash: 8661f94e0ee35f8d5e2c8caba1fc01bbf4072876
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87190683"
---
# <a name="guard-enable-control-flow-guard"></a>/guard (habilitar proteção do fluxo de controle)

Habilitar a geração de compilador de verificações de segurança de proteção de fluxo de controle.

## <a name="syntax"></a>Sintaxe

```
/guard:cf[-]
```

## <a name="remarks"></a>Comentários

A opção **/Guard: CF** faz com que o compilador analise o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, insira o código para verificar os destinos em tempo de execução. Por padrão, **/Guard: CF** está desativado e deve ser habilitado explicitamente. Para desabilitar explicitamente essa opção, use **/Guard: CF-**.

**Visual Studio 2017 e posterior**: essa opção adiciona proteções para **`switch`** instruções que geram tabelas de salto.

Quando a opção de proteção de fluxo de controle (CFG) **/Guard: CF** é especificada, o compilador e o vinculador inserem verificações de segurança de tempo de execução extras para detectar tentativas de comprometer seu código. Durante a compilação e a vinculação, todas as chamadas indiretas em seu código são analisadas para localizar cada local que o código pode acessar quando é executado corretamente. Essas informações são armazenadas em estruturas extras nos cabeçalhos dos seus binários. O compilador também injeta uma verificação antes de cada chamada indireta em seu código que garante que o destino seja um dos locais verificados. Se a verificação falhar em tempo de execução em um sistema operacional com reconhecimento de CFG, o sistema operacional fechará o programa.

Um ataque comum ao software aproveita os bugs no tratamento de entradas extremas ou inesperadas. A entrada cuidadosamente criada para o aplicativo pode substituir um local que contém um ponteiro para código executável. Isso pode ser usado para redirecionar o fluxo de controle para o código controlado pelo invasor. As verificações de tempo de execução do CFG não corrigem os bugs de corrupção de dados no seu executável. Em vez disso, eles tornam mais difícil para um invasor usá-los para executar código arbitrário. CFG é uma ferramenta de mitigação que impede chamadas a locais diferentes de pontos de entrada de função em seu código. É semelhante a como a DEP (prevenção de execução de dados), as verificações de pilha [/GS](gs-buffer-security-check.md) e [/DynamicBase](dynamicbase-use-address-space-layout-randomization.md) e o [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md) de layout de espaço de endereço (ASLR), reduzem as chances de que seu código se torne um vetor de exploração.

A opção **/Guard: CF** deve ser passada para o compilador e o vinculador para compilar o código que usa a técnica de mitigação de exploração do cfg. Se seu binário for criado usando um único `cl` comando, o compilador passará a opção para o vinculador. Se você compilar e vincular separadamente, a opção deverá ser definida nos comandos do compilador e do vinculador. A opção de vinculador/DYNAMICBASE também é necessária. Para verificar se o binário tem dados CFG, use o `dumpbin /headers /loadconfig` comando. Os binários habilitados para CFG têm `Guard` a lista de características de exe ou dll, e os sinalizadores de proteção incluem `CF Instrumented` e `FID table present` .

A opção **/Guard: CF** é incompatível com [/Zi](z7-zi-zi-debug-information-format.md) (informações de depuração de editar e continuar) ou [/CLR](clr-common-language-runtime-compilation.md) (compilação em tempo de execução de linguagem comum).

Código compilado usando **/Guard: CF** pode ser vinculado a bibliotecas e arquivos de objeto que não são compilados usando a opção. Somente esse código, quando também vinculado usando a opção **/Guard: CF** e executado em um sistema operacional com reconhecimento de cfg, tem a proteção cfg. Como o código compilado sem a opção não interromperá um ataque, recomendamos que você use a opção em todo o código compilado. Há um pequeno custo de tempo de execução para as verificações de CFG, mas a análise do compilador tenta otimizar as verificações em saltos indiretos que podem ser comprovadamente seguros.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione **Propriedades de configuração**, **C/C++**, **geração de código**.

1. Selecione a propriedade de **proteção de fluxo de controle** .

1. No controle suspenso, escolha **Sim** para habilitar a proteção de fluxo de controle ou **não** para desabilitá-la.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
