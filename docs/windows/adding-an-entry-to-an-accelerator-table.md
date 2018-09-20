---
title: Adicionando uma entrada a uma tabela de aceleradores (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- accelerator tables [C++], adding entries
- New Accelerator command
ms.assetid: 559c2415-8323-4339-9447-6966665f8288
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0e0017e0c4d5462ef985b70b44120ff20066f626
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46391794"
---
# <a name="adding-an-entry-to-an-accelerator-table-c"></a>Adicionando uma entrada a uma tabela de aceleradores (C++)

### <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada para uma tabela de aceleradores

1. Em um projeto de C++, abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Clique dentro da tabela do acelerador e escolha **novo Acelerador** no menu de atalho, ou clique na entrada de linha vazia na parte inferior da tabela.

3. Selecione um [identificação](id-property.md) na lista suspensa na ID de caixa ou digite uma nova ID no **ID** caixa.

4. Tipo de [chave](../windows/accelerator-key-property.md) você deseja usar como um acelerador ou o botão direito do mouse e escolha **próxima chave digitada** no menu de atalho para definir uma combinação de teclas (o **próxima chave digitada** comando é também disponível na **editar** menu).

5. Alterar o [modificador](../windows/accelerator-modifier-property.md) e [tipo](../windows/accelerator-type-property.md), se necessário.

6. Pressione **ENTER**.

   > [!NOTE]
   > Verifique se todos os aceleradores que você define são exclusivos. Você pode ter várias combinações de teclas atribuídas para a mesma ID com nenhum efeito mal, por exemplo, **Ctrl** + **P** e **F8** podem ser atribuídos ao ID_PRINT. No entanto, ter atribuída a mais de uma ID não funcionará bem, por exemplo, uma combinação de teclas **Ctrl** + **Z** atribuídas a ID_SPELL_CHECK e ID_THESAURUS.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)<br/>
[Editor de aceleradores](../windows/accelerator-editor.md)