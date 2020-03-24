---
title: 'Como: criar símbolos (C++)'
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
ms.openlocfilehash: 1c69e8878885acd80c285691fb0861a476af03ea
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160509"
---
# <a name="how-to-create-symbols-c"></a>Como: criar símbolos (C++)

Quando você estiver começando um novo projeto, talvez seja conveniente mapear os nomes de símbolo necessários antes de criar os recursos aos quais eles serão atribuídos.

> [!NOTE]
> Se o seu projeto ainda não contiver um arquivo. rc, consulte [como: criar recursos](../windows/how-to-create-a-resource-script-file.md).

A caixa de diálogo **símbolos de recurso** permite que você adicione novos símbolos de recurso, altere os símbolos que são exibidos ou pule para o local no código-fonte em que um símbolo está em uso.

A caixa de diálogo contém as seguintes propriedades:

|Propriedade|DESCRIÇÃO|
|--------------------------|------------------------------------------|
|**Nome**|Exibe o nome do símbolo.<br/><br/>Para obter mais informações, consulte [Symbol Name Restrictions](../windows/symbol-name-restrictions.md).|
|**Valor**|Exibe o valor numérico do símbolo.<br/><br/>Para obter mais informações, consulte [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).|
|**Em uso**|Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos.<br/><br/>O recurso ou os recursos são listados na caixa **usado por** .|
|**Mostrar símbolos somente leitura**|Quando selecionado, exibe recursos somente leitura.<br/><br/>Por padrão, a caixa de diálogo **símbolo de recurso** exibe somente os recursos modificáveis no arquivo de script de recurso, mas com essa opção selecionada, os recursos modificáveis aparecem em negrito e os recursos somente leitura são exibidos em texto sem formatação.|
|**Usado por**|Exibe o recurso ou os recursos usando o símbolo selecionado na lista de símbolos.<br/><br/>Para mover para o editor de um determinado recurso, selecione o recurso na caixa **usado por** e escolha **Exibir usar**.|
|**Novo**|Abre a caixa de diálogo **novo símbolo** que permite que você defina o nome e, se necessário, um valor para um novo identificador de recurso simbólico.|
|**Alteração**|Abre a caixa de diálogo **alterar símbolo** que permite alterar o nome ou o valor de um símbolo.<br/><br/>Se o símbolo for para um controle ou recurso em uso, o símbolo só poderá ser alterado do editor de recursos correspondente. Para obter mais informações, consulte [Gerenciar símbolos](../windows/changing-unassigned-symbols.md).|
|**Exibir uso**|Abre o recurso que contém o símbolo no editor de recursos correspondente.|

## <a name="create-symbols"></a>Criar símbolos

### <a name="to-create-a-new-symbol"></a>Para criar um novo símbolo

1. Na caixa de diálogo **símbolos de recurso** , escolha **novo**.

1. Na caixa **nome** , digite um nome de símbolo.

1. Aceite o valor de símbolo atribuído ou digite um novo valor na caixa **valor** .

1. Selecione **OK** para adicionar o novo símbolo à lista de símbolos.

> [!NOTE]
> Se você digitar um nome de símbolo que já existe, uma caixa de mensagem será exibida informando que um símbolo com esse nome já está definido. Você não pode definir dois ou mais símbolos com o mesmo nome, mas pode definir símbolos diferentes com o mesmo valor numérico.

## <a name="to-view-resource-symbols"></a>Para exibir os símbolos de recurso

Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e selecione **símbolos de recurso** para exibir uma tabela de símbolo de recurso na caixa de diálogo **símbolos de recurso** .

> [!NOTE]
> Para ver os símbolos predefinidos, marque a caixa de seleção **Mostrar símbolos somente leitura** .

### <a name="to-open-the-resource-editor-for-a-given-symbol"></a>Para abrir o editor de recursos para um determinado símbolo

Quando você estiver procurando símbolos nos **símbolos de recurso**, talvez queira mais informações sobre como um determinado símbolo é usado. O botão **Exibir usar** fornece uma maneira rápida de obter essas informações.

1. Na caixa de diálogo **símbolos de recurso** na caixa **nome** , selecione um símbolo.

1. Na caixa **usado por** , selecione o tipo de recurso que lhe interessa.

1. Selecione o botão **Exibir usar** .

   O recurso aparece na janela apropriada do editor.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Identificadores de recursos (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
[Como: Gerenciar símbolos](../windows/changing-a-symbol-or-symbol-name-id.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>
