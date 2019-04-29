---
title: A classe CCmdUI
ms.date: 11/04/2016
f1_keywords:
- CCmdUI
helpviewer_keywords:
- updating user interface objects [MFC]
- user interface objects [MFC], updating
- CCmdUI class [MFC], menu updating
- update handlers [MFC]
- toolbars [MFC], updating
ms.assetid: 2f2bae62-8c29-45a4-bbce-490eb01907d5
ms.openlocfilehash: 8e0af0703924d6fae626d3753b8523efe0c56652
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62306295"
---
# <a name="the-ccmdui-class"></a>A classe CCmdUI

Quando ele encaminha a um comando de atualização para o seu manipulador, o framework passa o manipulador de um ponteiro para um `CCmdUI` objeto (ou a um objeto de um `CCmdUI`-classe derivada). Este objeto representa o botão de barra de ferramentas ou item de menu ou outro objeto de interface do usuário que gerou o comando. O manipulador de atualização chama o membro de funções do `CCmdUI` estrutura através do ponteiro para atualizar o objeto de interface do usuário. Por exemplo, aqui está um manipulador de atualização para o item de menu Limpar tudo:

[!code-cpp[NVC_MFCDocView#3](../mfc/codesnippet/cpp/the-ccmdui-class_1.cpp)]

Esse manipulador chama o `Enable` a função de membro de um objeto com acesso ao item de menu. `Enable` o item torna disponível para uso.

## <a name="see-also"></a>Consulte também

[Como: atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)
