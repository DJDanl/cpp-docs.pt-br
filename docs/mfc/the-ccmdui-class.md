---
title: A classe CCmdUI | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CCmdUI
dev_langs: C++
helpviewer_keywords:
- updating user interface objects [MFC]
- user interface objects [MFC], updating
- CCmdUI class [MFC], menu updating
- update handlers [MFC]
- toolbars [MFC], updating
ms.assetid: 2f2bae62-8c29-45a4-bbce-490eb01907d5
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 76f5dd1fa4ebaaa3a8c53f9eb27d6c83efd81bfd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="the-ccmdui-class"></a>A classe CCmdUI
Quando ele encaminha a um comando de atualização para seu manipulador, o framework passa o manipulador de um ponteiro para um `CCmdUI` objeto (ou a um objeto de um `CCmdUI`-classe derivada). Esse objeto representa o botão de barra de ferramentas ou item de menu ou outro objeto de interface do usuário que gerou o comando. O manipulador de atualização chama membro funções do `CCmdUI` estrutura através do ponteiro para atualizar o objeto de interface do usuário. Por exemplo, aqui está um manipulador de atualização para o item de menu Limpar tudo:  
  
 [!code-cpp[NVC_MFCDocView#3](../mfc/codesnippet/cpp/the-ccmdui-class_1.cpp)]  
  
 Este manipulador chama o **habilitar** função de membro de um objeto com acesso ao item de menu. **Habilitar** disponibiliza o item.  
  
## <a name="see-also"></a>Consulte também  
 [Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

