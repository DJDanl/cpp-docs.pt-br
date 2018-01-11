---
title: Adicionando uma entrada para uma tabela de aceleradores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- accelerator tables [C++], adding entries
- New Accelerator command
ms.assetid: 559c2415-8323-4339-9447-6966665f8288
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9fe2df81aae0b9b7232443de1db091a9cbb0c0d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-an-entry-to-an-accelerator-table"></a>Adicionando uma entrada a uma tabela de aceleradores
### <a name="to-add-an-entry-to-an-accelerator-table"></a>Para adicionar uma entrada para uma tabela de aceleradores  
  
1.  Abra a tabela de teclas aceleradoras clicando duas vezes em seu ícone no [exibição recursos](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique dentro da tabela de teclas aceleradoras e escolha **novo Acelerador** do menu de atalho, ou clique na entrada de linha vazia na parte inferior da tabela.  
  
3.  Selecione um [ID](id-property.md) na lista suspensa na ID de caixa ou digite uma nova ID a **ID** caixa.  
  
4.  Tipo de [chave](../windows/accelerator-key-property.md) você deseja usar como um acelerador ou o botão direito do mouse e escolha **próxima chave digitada** no menu de atalho para definir uma combinação de teclas (o **próxima chave digitada** comando é também disponível no **editar** menu).  
  
5.  Alterar o [modificador](../windows/accelerator-modifier-property.md) e [tipo](../windows/accelerator-type-property.md), se necessário.  
  
6.  Pressione **ENTER**.  
  
    > [!NOTE]
    >  Verifique se todos os aceleradores que você definir são exclusivos. Você pode ter várias combinações de teclas atribuídas para a mesma ID sem efeito de preenchimento, por exemplo, CTRL + P e F8 podem ser atribuídos ao ID_PRINT. No entanto, ter uma combinação de teclas atribuído a mais de uma que ID não funcionarão bem, por exemplo, CTRL + Z atribuído a ID_SPELL_CHECK e ID_THESAURUS.  
  

  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)