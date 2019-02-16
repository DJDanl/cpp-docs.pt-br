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
ms.openlocfilehash: 01b810d162da4d59c2044fe02a1da5c0929d41b9
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320595"
---
# <a name="how-to-create-symbols-c"></a>Como: Crie símbolos (C++)

Quando você começar um novo projeto, talvez seja conveniente para mapear os nomes de símbolo que você precisa antes de criar os recursos ao qual serão atribuídos.

O **símbolos de recurso** caixa de diálogo C++ permite que você adicione novos símbolos de recurso, altere os símbolos que são exibidos, ou pular para o local no código-fonte em que um símbolo está em uso.

A caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|--------------------------|------------------------------------------|
|**Nome**|Exibe o nome do símbolo. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).|
|**Valor**|Exibe o valor numérico do símbolo. Para obter mais informações, consulte [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).|
|**Em uso**|Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos. Um ou mais recursos são listados na usado pela caixa.|
|**Mostrar símbolos somente leitura**|Quando selecionado, exibe recursos somente leitura. Por padrão, o **símbolo de recurso** caixa de diálogo exibe somente os recursos pode ser modificados no arquivo de script de recurso, mas com essa opção selecionada, os recursos modificáveis aparecem em negrito e os recursos de somente leitura são exibidos em texto sem formatação.|
|**Usado por**|Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos. Para mover para o editor para um determinado recurso, selecione o recurso nas **usado por** caixa e escolha **Exibir uso**.|
|**Novo**|Abre o **novo símbolo** caixa de diálogo que permite que você defina o nome e, se necessário, um valor para um novo identificador simbólico do recurso.|
|**Alteração**|Abre o **alterar símbolo** caixa de diálogo que permite que você altere o nome ou o valor de um símbolo. Se o símbolo for para um controle ou recurso em uso, o símbolo pode ser alterado somente de editor de recursos correspondente. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).|
|**Exibir uso**|Abre o recurso que contém o símbolo no editor de recurso correspondente.|

## <a name="create-symbols"></a>Crie símbolos

### <a name="to-create-a-new-symbol"></a>Para criar um novo símbolo

1. No **símbolos de recurso** diálogo caixa, escolha **New**.

1. No **nome** , digite um nome de símbolo.

1. Aceite o valor atribuído de símbolo ou digite um novo valor na **valor** caixa.

1. Selecione **Okey** para adicionar o novo símbolo à lista de símbolos.

> [!NOTE]
> Se você digitar um nome de símbolo que já existe, uma caixa de mensagem será exibida, informando que um símbolo com este nome já está definido. Não é possível definir duas ou mais símbolos com o mesmo nome, mas você pode definir símbolos diferentes com o mesmo valor numérico. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md) e [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).

### <a name="to-view-resource-symbols"></a>Para exibir os símbolos de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. rc.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. Selecione **símbolos de recurso** no menu de atalho para exibir uma tabela de símbolos de recurso nas **símbolos de recurso** caixa de diálogo.

   > [!NOTE]
   > Para ver os símbolos predefinidos, verifique as **Mostrar símbolos somente leitura** caixa de seleção.

### <a name="to-open-the-resource-editor-for-a-given-symbol"></a>Para abrir o editor de recurso para um determinado símbolo

Quando você estiver navegando símbolos na **símbolos de recurso**, você poderá obter mais informações sobre como um símbolo específico é usado. O **uso do modo de exibição** botão fornece uma maneira rápida de obter essas informações.

#### <a name="to-move-to-the-resource-editor-where-a-symbol-is-being-used"></a>Para mover para o editor de recursos em que um símbolo está sendo usado

1. Selecione um símbolo na **nome** caixa da **símbolos de recurso** caixa de diálogo.

1. No **usado por** , selecione o tipo de recurso que lhe interessa.

1. Selecione o **uso do modo de exibição** botão.

   O recurso será exibido na janela do editor apropriado.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Identificadores de recurso (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>