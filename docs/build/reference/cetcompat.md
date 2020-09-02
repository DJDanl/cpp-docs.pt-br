---
title: /CETCOMPAT (compatível com pilha de sombra CET)
ms.date: 09/01/2020
f1_keywords:
- /CETCOMPAT
helpviewer_keywords:
- /CETCOMPAT linker option
- /CETCOMPAT
ms.openlocfilehash: 7de7c2007c29769cb3ac8f89d07de8b00bf44c26
ms.sourcegitcommit: e58918c45316d799c1952ca7797a85adbcd0c472
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/01/2020
ms.locfileid: "89281816"
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

1. No controle suspenso, escolha **`Yes (/CETCOMPAT)`** marcar o binário como compatível com pilha de sombra CET ou **`No (/CETCOMPAT:NO)`** para marcá-lo como não compatível.

Em versões anteriores do Visual Studio 2019:

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. No controle de edição de **Opções adicionais** , adicione *`/CETCOMPAT`* para marcar o binário como compatível com a pilha de sombra CET ou *`/CETCOMPAT:NO`* marcá-la explicitamente como não compatível.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Confira também

[Opções do vinculador](linker-options.md)
