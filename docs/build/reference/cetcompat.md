---
title: /CETCOMPAT (compatível com pilha de sombra CET)
ms.date: 02/19/2019
f1_keywords:
- /CETCOMPAT
helpviewer_keywords:
- /CETCOMPAT linker option
- /CETCOMPAT
ms.openlocfilehash: 2c807d91d69b967fd62e01a077711dede5f55c44
ms.sourcegitcommit: 7e011c68ca7547469544fac87001a33a37e1792e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2020
ms.locfileid: "84421293"
---
# <a name="cetcompat-cet-shadow-stack-compatible"></a>/CETCOMPAT (compatível com pilha de sombra CET)

Especifica se uma imagem executável deve ser marcada como compatível com a pilha de sombra de CET (tecnologia de imposição de fluxo de controle).

## <a name="syntax"></a>Sintaxe

> **/CETCOMPAT** \[ **: Não**]

## <a name="arguments"></a>Argumentos

**Não**<br/>
Especifica que o executável não deve ser marcado como compatível com a pilha de sombra CET.

## <a name="remarks"></a>Comentários

A pilha de sombra da CET (Control-Flow imposição Technology) é um recurso de processador de computador que fornece recursos para se defender contra ataques de malware baseados em ROP (retorno orientado a programação). Para obter mais informações, consulte [Visualização da tecnologia de aplicação de fluxo de controle Intel](https://software.intel.com/sites/default/files/managed/4d/2a/control-flow-enforcement-technology-preview.pdf).

A opção vinculador **/CETCOMPAT** informa o vinculador para marcar o binário como compatível com pilha de sombra CET. **/CETCOMPAT: não** marca o binário como não compatível com a pilha de sombra CET. Se ambas as opções forem especificadas na linha de comando, o último especificado será usado. Atualmente, essa opção é aplicável somente a arquiteturas x86 e x64.

A opção **/CETCOMPAT** está disponível a partir do conjunto de ferramentas do Visual Studio 2019 Preview 3.

### <a name="to-set-the-cetcompat-linker-option-in-visual-studio"></a>Para definir a opção de vinculador/CETCOMPAT no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade avançada do**vinculador**de propriedades de configuração  >  **Advanced** .

1. Selecione a propriedade **compatível com pilha de sombra CET** .

1. No controle suspenso, escolha **Sim (/CETCOMPAT)** para habilitar os metadados de continuação de eh ou **não (/CETCOMPAT: no)** para desabilitá-lo.


### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Confira também

[Opções do vinculador](linker-options.md)
