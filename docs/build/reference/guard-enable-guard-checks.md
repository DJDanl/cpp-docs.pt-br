---
title: /GUARD (habilitar verificações de proteção)
ms.date: 11/04/2016
ms.assetid: 72758e23-70ac-4616-94d7-d767477406d1
ms.openlocfilehash: e48921e57977cc7a1ca6a580fed78a6a2a960a02
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292244"
---
# <a name="guard-enable-guard-checks"></a>/GUARD (habilitar verificações de proteção)

Especifica o suporte para verificações de proteção de fluxo de controle na imagem executável.

## <a name="syntax"></a>Sintaxe

```
/GUARD:{CF|NO}
```

## <a name="remarks"></a>Comentários

Quando /Guard: CF for especificado, o vinculador modifica o cabeçalho de um arquivo. dll ou .exe para indicar o suporte para verificações de tempo de execução do protetor de fluxo de controle (CFG). O vinculador também adiciona os dados de endereço de destino de fluxo de controle necessário para o cabeçalho. Por padrão, o /Guard: CF está desabilitado. Ele pode ser desabilitado explicitamente usando /GUARD:NO. Para ser eficaz, /Guard: CF também requer o [/DYNAMICBASE (randomização de layout do espaço de endereço de uso)](dynamicbase-use-address-space-layout-randomization.md) opção de vinculador, que é ativado por padrão.

Quando o código-fonte é compilado usando o [/Guard: CF](guard-enable-control-flow-guard.md) opção, o compilador analisa o fluxo de controle por meio do exame todas as chamadas indiretas para endereços de destino possíveis. O compilador insere o código para verificar se que o endereço de destino de uma instrução de chamada indireta está na lista de endereços de destino conhecidos em tempo de execução. Verifique se os sistemas operacionais que dão suporte a parada CFG um programa que falha um tempo de execução do CFG. Isso torna mais difícil para um invasor execute código mal-intencionado usando dados corrompidos para alterar um destino de chamada.

A opção /Guard: CF deve ser especificada para o compilador e vinculador para criar imagens executáveis CFG habilitado. Código compilado, mas não vinculada usando /Guard: CF gera o custo das verificações de tempo de execução, mas não habilitar a proteção do CFG. Quando a opção /Guard: CF é especificada para o `cl` comando para compilar e vincular-se em uma única etapa, o compilador passa o sinalizador para o vinculador. Quando o **proteção de fluxo de controle** propriedade é definida no Visual Studio, a opção /Guard: CF é passada para o compilador e vinculador. Quando os arquivos de objeto ou bibliotecas foram compiladas separadamente, a opção deve ser especificada explicitamente no `link` comando.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **vinculador**, **linha de comando**.

1. Na **opções adicionais**, insira `/GUARD:CF`.

## <a name="see-also"></a>Consulte também

[/guard (habilitar proteção de fluxo de controle)](guard-enable-control-flow-guard.md)<br/>
[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
