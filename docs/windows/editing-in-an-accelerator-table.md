---
title: Editando em uma tabela de aceleradores (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- accelerator tables [C++], editing
- keyboard shortcuts [C++], editing in an accelerator table
ms.assetid: 545b650b-4f26-4b20-8431-d942548443bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 57347b88fe7d54813e06cde6d5f4b3414e79f116
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46395798"
---
# <a name="editing-in-an-accelerator-table-c"></a>Editando em uma tabela de aceleradores (C++)

### <a name="to-edit-in-an-accelerator-table"></a>Para editar em uma tabela de aceleradores

1. Abra a tabela de aceleradores clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Selecione uma entrada na tabela e clique para ativar a edição in-loco.

3. Selecione a caixa de combinação suspensa ou digite para fazer alterações.

   - Para [ID](id-property.md), selecione na lista ou digite para editar.

   - Para [modificador](../windows/accelerator-modifier-property.md), selecione na lista.

   - Para [chave](../windows/accelerator-key-property.md), selecione na lista ou digite para editar.

   - Para [tipo](../windows/accelerator-type-property.md), selecione **ASCII** ou **VIRTKEY** na lista.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)<br/>
[Editor de aceleradores](../windows/accelerator-editor.md)