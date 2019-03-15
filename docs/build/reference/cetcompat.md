---
title: / CETCOMPAT (compatível com a tecnologia de imposição de fluxo de controle)
ms.date: 02/19/2019
f1_keywords:
- /CETCOMPAT
helpviewer_keywords:
- /CETCOMPAT linker option
- /CETCOMPAT
ms.openlocfilehash: 1a01dd45667f64dbcbe11acaf1180835bd0d6e31
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809841"
---
# <a name="cetcompat-control-flow-enforcement-technology-compatible"></a>/ CETCOMPAT (compatível com a tecnologia de imposição de fluxo de controle)

Especifica se é necessário marcar uma imagem executável como compatível com tecnologia de imposição de fluxo de controle (CET).

## <a name="syntax"></a>Sintaxe

> **/CETCOMPAT**\[**:NO**]

## <a name="arguments"></a>Arguments

**NÃO**<br/>
Especifica que o executável não deve ser marcados como compatível com CET.

## <a name="remarks"></a>Comentários

Tecnologia de imposição de fluxo de controle (CET) é um recurso de processador do computador que fornece recursos para proteger contra determinados tipos de ataques de malware. Para obter mais informações, consulte [visualização de tecnologia de imposição de fluxo de controle do Intel](https://software.intel.com/sites/default/files/managed/4d/2a/control-flow-enforcement-technology-preview.pdf).

O **/CETCOMPAT** a opção de vinculador instrui o vinculador para marcar o binário como compatível com o horário da Europa Central. **/CETCOMPAT:no** marca o binário como não compatível com o horário da Europa Central. Se ambas as opções são especificadas na linha de comando, a última especificada será usada. Atualmente, essa opção só é aplicável às arquiteturas x86 e x64.

O **/CETCOMPAT** opção está disponível a partir do conjunto de ferramentas da visualização 3 do Visual Studio de 2019.

### <a name="to-set-the-cetcompat-linker-option-in-visual-studio"></a>Para definir a opção de vinculador /CETCOMPAT no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. No **opções adicionais** caixa, adicione **/CETCOMPAT** ou **/CETCOMPAT:NO** e, em seguida, escolha **Okey** ou **aplicar**para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Opções do vinculador](linker-options.md)
