---
title: Alterando um símbolo ou um nome de símbolo (ID) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.changing
dev_langs:
- C++
helpviewer_keywords:
- symbol names
- symbols [C++], names
ms.assetid: 26541832-8dba-4177-b642-e08f94502ea7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8b80c854d144f0f2010d1482a03f692062ea81ef
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315893"
---
# <a name="changing-a-symbol-or-symbol-name-id"></a>Alterando um símbolo ou um nome de símbolo (ID)

Quando você cria um novo recurso ou objeto de recurso, o ambiente de desenvolvimento atribui a ele um nome de símbolo padrão, por exemplo, IDD_DIALOG1. Você pode usar o [janela de propriedades](/visualstudio/ide/reference/properties-window) para alterar o nome de símbolo padrão ou para alterar o nome de qualquer símbolo já está associado com um recurso.

### <a name="to-change-a-resources-symbol-name"></a>Para alterar o nome do símbolo do recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o recurso.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **propriedades** janela, digite um novo nome de símbolo ou selecione na lista de símbolos existentes na **ID** caixa.

   Se você digitar um novo nome de símbolo, ele é automaticamente atribuído a um valor.

Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar os nomes de símbolos que não estão atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)  
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)