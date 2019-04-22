---
title: 'Como: Crie símbolos (C++)'
ms.date: 02/14/2019
f1_keywords:
- vc.editors.symbol.creating
- vc.editors.symbol.managing
- vc.editors.resourcesymbols
- vc.editors.symbol.resource
helpviewer_keywords:
- New Symbol dialog box [C++]
- symbols [C++], creating
- resources [C++], viewing
- resource symbols
- symbols [C++], viewing
- New Symbol dialog box [C++]
- Resource Symbols dialog box [C++]
- Change Symbol dialog box [C++]
- resource symbols
- View Use button
- resource editors [C++], resource symbols
ms.assetid: 35168d31-3af6-4ecd-9362-3707d47b53f3
ms.openlocfilehash: 8bb73c1a9e8d253492a7068c444dd7ddea8417da
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59026351"
---
# <a name="how-to-create-symbols-c"></a>Como: Crie símbolos (C++)

Quando você começar um novo projeto, talvez seja conveniente para mapear os nomes de símbolo que você precisa antes de criar os recursos ao qual serão atribuídos.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [como: Criar recursos](../windows/how-to-create-a-resource-script-file.md).

O **símbolos de recurso** caixa de diálogo permite que você adicione novos símbolos de recurso, altere os símbolos que são exibidos, ou pular para o local no código-fonte em que um símbolo está em uso.

A caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|--------------------------|------------------------------------------|
|**Nome**|Exibe o nome do símbolo.<br/><br/>Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).|
|**Valor**|Exibe o valor numérico do símbolo.<br/><br/>Para obter mais informações, consulte [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).|
|**Em uso**|Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos.<br/><br/>Um ou mais recursos são listados na **usados pelo** caixa.|
|**Mostrar símbolos somente leitura**|Quando selecionado, exibe recursos somente leitura.<br/><br/>Por padrão, o **símbolo de recurso** caixa de diálogo exibe somente os recursos pode ser modificados no arquivo de script de recurso, mas com essa opção selecionada, os recursos modificáveis aparecem em negrito e os recursos de somente leitura são exibidos em texto sem formatação.|
|**Usado por**|Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos.<br/><br/>Para mover para o editor para um determinado recurso, selecione o recurso nas **usado pelo** caixa e escolha **Exibir uso**.|
|**Novo**|Abre o **novo símbolo** caixa de diálogo que permite que você defina o nome e, se necessário, um valor para um novo identificador simbólico do recurso.|
|**Alteração**|Abre o **alterar símbolo** caixa de diálogo que permite que você altere o nome ou o valor de um símbolo.<br/><br/>Se o símbolo for para um controle ou recurso em uso, o símbolo pode ser alterado somente de editor de recursos correspondente. Para obter mais informações, consulte [gerenciar símbolos](../windows/changing-unassigned-symbols.md).|
|**Exibir uso**|Abre o recurso que contém o símbolo no editor de recurso correspondente.|

## <a name="create-symbols"></a>Crie símbolos

### <a name="to-create-a-new-symbol"></a>Para criar um novo símbolo

1. No **símbolos de recurso** diálogo caixa, escolha **New**.

1. No **nome** , digite um nome de símbolo.

1. Aceite o valor atribuído de símbolo ou digite um novo valor na **valor** caixa.

1. Selecione **Okey** para adicionar o novo símbolo à lista de símbolos.

> [!NOTE]
> Se você digitar um nome de símbolo que já existe, uma caixa de mensagem será exibida, informando que um símbolo com este nome já está definido. Não é possível definir duas ou mais símbolos com o mesmo nome, mas você pode definir símbolos diferentes com o mesmo valor numérico.

## <a name="to-view-resource-symbols"></a>Para exibir os símbolos de recurso

No [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), clique com botão direito seu *. rc* arquivo e selecione **símbolos de recurso** para exibir uma tabela de símbolos de recurso no **símbolos de recurso**caixa de diálogo.

> [!NOTE]
> Para ver os símbolos predefinidos, verifique as **Mostrar símbolos somente leitura** caixa de seleção.

### <a name="to-open-the-resource-editor-for-a-given-symbol"></a>Para abrir o editor de recurso para um determinado símbolo

Quando você estiver navegando símbolos na **símbolos de recurso**, você poderá obter mais informações sobre como um símbolo específico é usado. O **uso do modo de exibição** botão fornece uma maneira rápida de obter essas informações.

1. No **símbolos de recurso** da caixa de diálogo do **nome** , selecione um símbolo.

1. No **usado por** , selecione o tipo de recurso que lhe interessa.

1. Selecione o **uso do modo de exibição** botão.

   O recurso será exibido na janela do editor apropriado.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Identificadores de recursos (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Como: gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>