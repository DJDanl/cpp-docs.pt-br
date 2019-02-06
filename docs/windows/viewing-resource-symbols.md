---
title: Exibindo símbolos de recurso (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.symbol.managing
- vc.editors.resourcesymbols
helpviewer_keywords:
- resources [C++], viewing
- resource symbols
- symbols [C++], viewing
- New Symbol dialog box [C++]
- Resource Symbols dialog box [C++]
- Change Symbol dialog box [C++]
ms.assetid: 4bcc06d9-7d36-486a-8a37-71da0541643c
ms.openlocfilehash: e61269261fc9172288f1edf58419009178c755d9
ms.sourcegitcommit: 63c072f5e941989636f5a2b13800b68bb7129931
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/06/2019
ms.locfileid: "55763967"
---
# <a name="viewing-resource-symbols"></a>Exibindo símbolos de recurso

O **símbolos de recurso** caixa de diálogo C++ permite que você adicione novos símbolos de recurso, altere os símbolos que são exibidos, ou pular para o local no código-fonte em que um símbolo está em uso.

A caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Nome**|Exibe o nome do símbolo. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).|
|**Valor**|Exibe o valor numérico do símbolo. Para obter mais informações, consulte [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).|
|**Em uso**|Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos. Um ou mais recursos são listados na usado pela caixa.|
|**Mostrar símbolos somente leitura**|Quando selecionado, exibe recursos somente leitura. Por padrão, o **símbolo de recurso** caixa de diálogo exibe somente os recursos pode ser modificados no arquivo de script de recurso, mas com essa opção selecionada, os recursos modificáveis aparecem em negrito e os recursos de somente leitura são exibidos em texto sem formatação.|
|**Usado por**|Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos. Para mover para o editor para um determinado recurso, selecione o recurso nas **usado por** caixa e clique em **Exibir uso**. Para obter mais informações, consulte [abrindo o Editor de recursos para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).|
|**Novo**|Abre o **novo símbolo** caixa de diálogo que permite que você defina o nome e, se necessário, um valor para um novo identificador simbólico do recurso. Para obter mais informações, consulte [criando novos símbolos](../windows/creating-new-symbols.md).|
|**Alteração**|Abre o **alterar símbolo** caixa de diálogo que permite que você altere o nome ou o valor de um símbolo. Se o símbolo for para um controle ou recurso em uso, o símbolo pode ser alterado somente de editor de recursos correspondente. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).|
|**Exibir uso**|Abre o recurso que contém o símbolo no editor de recurso correspondente. Para obter mais informações, consulte [abrindo o Editor de recursos para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).|

## <a name="to-view-resource-symbols"></a>Para exibir os símbolos de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. rc.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. Selecione **símbolos de recurso** no menu de atalho para exibir uma tabela de símbolos de recurso nas **símbolos de recurso** caixa de diálogo.

   > [!NOTE]
   > Para ver os símbolos predefinidos, verifique as **Mostrar símbolos somente leitura** caixa de seleção.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)