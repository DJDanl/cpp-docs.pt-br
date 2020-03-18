---
title: A classe CCmdUI
ms.date: 11/04/2016
helpviewer_keywords:
- updating user interface objects [MFC]
- user interface objects [MFC], updating
- CCmdUI class [MFC], menu updating
- update handlers [MFC]
- toolbars [MFC], updating
ms.assetid: 2f2bae62-8c29-45a4-bbce-490eb01907d5
ms.openlocfilehash: 105aa7ad6c5cc6a5563dbde8145327a2b3d066a1
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447148"
---
# <a name="the-ccmdui-class"></a>A classe CCmdUI

Quando ele roteia um comando Update para seu manipulador, a estrutura passa o manipulador de um ponteiro para um objeto `CCmdUI` (ou para um objeto de uma classe derivada de `CCmdUI`). Esse objeto representa o item de menu ou o botão da barra de ferramentas ou outro objeto de interface de usuário que gerou o comando. O manipulador de atualização chama funções de membro da estrutura `CCmdUI` por meio do ponteiro para atualizar o objeto user-interface. Por exemplo, aqui está um manipulador de atualização para o item de menu limpar tudo:

[!code-cpp[NVC_MFCDocView#3](../mfc/codesnippet/cpp/the-ccmdui-class_1.cpp)]

Esse manipulador chama a função membro `Enable` de um objeto com acesso ao item de menu. `Enable` torna o item disponível para uso.

## <a name="see-also"></a>Consulte também

[Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)
