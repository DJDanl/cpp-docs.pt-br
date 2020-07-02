---
title: /CETCOMPAT (compatível com pilha de sombra CET)
ms.date: 06/30/2020
f1_keywords:
- /CETCOMPAT
helpviewer_keywords:
- /CETCOMPAT linker option
- /CETCOMPAT
ms.openlocfilehash: 35078ac9e6177e34562db14b30f4ef8f987d98bc
ms.sourcegitcommit: 83ea5df40917885e261089b103d5de3660314104
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/01/2020
ms.locfileid: "85813557"
---
# <a name="cetcompat-cet-shadow-stack-compatible"></a>/CETCOMPAT (compatível com pilha de sombra CET)

Especifica se uma imagem executável deve ser marcada como compatível com a pilha de sombra de CET (tecnologia de imposição de fluxo de controle).

## <a name="syntax"></a>Sintaxe

> **`/CETCOMPAT`**\
> **`/CETCOMPAT:NO`**

## <a name="arguments"></a>Argumentos

**`NO`**<br/>
Especifica que o executável não deve ser marcado como compatível com a pilha de sombra CET.

## <a name="remarks"></a>Comentários

A pilha de sombra da CET (Control-Flow imposição Technology) é um recurso de processador de computador que fornece recursos para se defender contra ataques de malware com base em ROP (programação orientada a retorno). Para obter mais informações, consulte [Visualização da tecnologia de aplicação de fluxo de controle Intel](https://software.intel.com/sites/default/files/managed/4d/2a/control-flow-enforcement-technology-preview.pdf).

A **`/CETCOMPAT`** opção de vinculador informa o vinculador para marcar o binário como compatível com pilha de sombra CET. **`/CETCOMPAT:NO`** marca o binário como não compatível com a pilha de sombra CET. Se ambas as opções forem especificadas na linha de comando, o último especificado será usado. Atualmente, essa opção é aplicável somente a arquiteturas x86 e x64.

A **`/CETCOMPAT`** opção está disponível a partir do Visual Studio 2019.

### <a name="to-set-the-cetcompat-linker-option-in-visual-studio"></a>Para definir a `/CETCOMPAT` opção de vinculador no Visual Studio

A partir do Visual Studio 2019 versão 16,7:

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade avançada do**vinculador**de propriedades de configuração  >  **Advanced** .

1. Selecione a propriedade **compatível com pilha de sombra CET** .

1. No controle suspenso, escolha **`Yes (/CETCOMPAT)`** habilitar metadados de continuação de eh ou **`No (/CETCOMPAT:NO)`** para desabilitá-lo.

Em versões anteriores do Visual Studio 2019:

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. No controle de edição de **Opções adicionais** , adicione *`/CETCOMPAT`* para habilitar os metadados de continuação de eh ou *`/CETCOMPAT:NO`* desabilitá-lo explicitamente.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Veja também

[Opções do vinculador](linker-options.md)
