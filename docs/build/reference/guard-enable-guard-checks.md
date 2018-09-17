---
title: -GUARD (habilitar verificações de proteção) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: 72758e23-70ac-4616-94d7-d767477406d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d775e9c42ceb8a564e2cc7992cb95ac9717a966d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707675"
---
# <a name="guard-enable-guard-checks"></a>/GUARD (habilitar verificações de proteção)

Especifica o suporte para verificações de proteção de fluxo de controle na imagem executável.

## <a name="syntax"></a>Sintaxe

```
/GUARD:{CF|NO}
```

## <a name="remarks"></a>Comentários

Quando /Guard: CF for especificado, o vinculador modifica o cabeçalho de um arquivo. dll ou .exe para indicar o suporte para verificações de tempo de execução do protetor de fluxo de controle (CFG). O vinculador também adiciona os dados de endereço de destino de fluxo de controle necessário para o cabeçalho. Por padrão, o /Guard: CF está desabilitado. Ele pode ser desabilitado explicitamente usando /GUARD:NO. Para ser eficaz, /Guard: CF também requer o [/DYNAMICBASE (randomização de layout do espaço de endereço de uso)](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) opção de vinculador, que é ativado por padrão.

Quando o código-fonte é compilado usando o [/Guard: CF](../../build/reference/guard-enable-control-flow-guard.md) opção, o compilador analisa o fluxo de controle por meio do exame todas as chamadas indiretas para endereços de destino possíveis. O compilador insere o código para verificar se que o endereço de destino de uma instrução de chamada indireta está na lista de endereços de destino conhecidos em tempo de execução. Verifique se os sistemas operacionais que dão suporte a parada CFG um programa que falha um tempo de execução do CFG. Isso torna mais difícil para um invasor execute código mal-intencionado usando dados corrompidos para alterar um destino de chamada.

A opção /Guard: CF deve ser especificada para o compilador e vinculador para criar imagens executáveis CFG habilitado. Código compilado, mas não vinculada usando /Guard: CF gera o custo das verificações de tempo de execução, mas não habilitar a proteção do CFG. Quando a opção /Guard: CF é especificada para o `cl` comando para compilar e vincular-se em uma única etapa, o compilador passa o sinalizador para o vinculador. Quando o **proteção de fluxo de controle** propriedade é definida no Visual Studio, a opção /Guard: CF é passada para o compilador e vinculador. Quando os arquivos de objeto ou bibliotecas foram compiladas separadamente, a opção deve ser especificada explicitamente no `link` comando.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **vinculador**, **linha de comando**.

1. Na **opções adicionais**, insira `/GUARD:CF`.

## <a name="see-also"></a>Consulte também

[/Guard (habilitar o controle de fluxo de proteção)](../../build/reference/guard-enable-control-flow-guard.md)
[definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)