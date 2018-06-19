---
title: Adicionando uma entrada para uma tabela de aceleradores | Microsoft Docs
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
ms.openlocfilehash: 22f3e00c8ba6523f6cc615e4a766ad9206560b5e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33855364"
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