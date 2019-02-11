---
title: Alterando ou excluindo símbolos não atribuídos
ms.date: 11/04/2016
f1_keywords:
- vc.editors.symbol.changing.unassigned
helpviewer_keywords:
- symbols [C++], unassigned
- Change Symbol dialog box [C++]
- unassigned symbols
- symbols [C++], deleting
ms.assetid: b6abee4a-3c24-4697-a166-fe6a86cad35f
ms.openlocfilehash: 47cc3d7a387092afe77fdbcf4bbdb6d085eeda25
ms.sourcegitcommit: 966e4466f10c93fc12faf33d28e03b39489423fc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2019
ms.locfileid: "55987008"
---
# <a name="changing-or-deleting-unassigned-symbols"></a>Alterando ou excluindo símbolos não atribuídos

Enquanto estiver na [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md), você pode editar ou excluir símbolos existentes que já não são atribuídos a um recurso ou objeto.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="to-change-an-unassigned-symbol"></a>Para alterar um símbolo não atribuído

1. No **nome** caixa, selecione o símbolo não atribuído e escolha **alteração**.

1. Editar o nome do símbolo ou um valor nas caixas fornecidas na **alterar símbolo** caixa de diálogo.

   > [!NOTE]
   > Para alterar um símbolo que *está* atribuído a um recurso ou objeto, você deve usar o editor de recursos ou **propriedades** janela. Para obter mais informações, consulte [alterando um símbolo ou um nome de símbolo](../windows/changing-a-symbol-or-symbol-name-id.md).

## <a name="to-delete-an-unassigned-unused-symbol"></a>Para excluir um símbolo (não usado) não atribuído

No [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md), selecione o símbolo que você deseja excluir e escolha **excluir**.

   > [!NOTE]
   > Antes de excluir um símbolo não utilizado em um arquivo de recurso, verifique se que ele não é usado em outro lugar no programa ou pelos arquivos de recursos incluídos no tempo de compilação.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)<br/>
[Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)<br/>
[Restrições de valor de símbolo](../windows/symbol-value-restrictions.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)