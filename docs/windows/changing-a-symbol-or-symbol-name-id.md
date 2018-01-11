---
title: "Alterando um símbolo ou um nome de símbolo (ID) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.symbol.changing
dev_langs: C++
helpviewer_keywords:
- symbol names
- symbols, names
ms.assetid: 26541832-8dba-4177-b642-e08f94502ea7
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b0ed56fc3663b99af311c52e463bd2f16fcef0a2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-a-symbol-or-symbol-name-id"></a>Alterando um símbolo ou um nome de símbolo (ID)
Quando você cria um novo recurso ou o objeto de recurso, o ambiente de desenvolvimento atribui a ele um nome de símbolo padrão, por exemplo, IDD_DIALOG1. Você pode usar o [janela propriedades](/visualstudio/ide/reference/properties-window) para alterar o nome do símbolo padrão ou para alterar o nome de qualquer símbolo já está associado com um recurso.  
  
### <a name="to-change-a-resources-symbol-name"></a>Para alterar o nome do símbolo do recurso  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), selecione o recurso.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **propriedades** janela, digite um novo nome de símbolo ou selecione na lista de símbolos existentes no **ID** caixa.  
  
     Se você digitar um novo nome de símbolo, ele é automaticamente atribuído um valor.  
  
 Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar os nomes de símbolos não atualmente atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).  
  

  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)