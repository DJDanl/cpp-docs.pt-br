---
title: A classe CCmdUI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CCmdUI
dev_langs:
- C++
helpviewer_keywords:
- updating user interface objects [MFC]
- user interface objects [MFC], updating
- CCmdUI class [MFC], menu updating
- update handlers [MFC]
- toolbars [MFC], updating
ms.assetid: 2f2bae62-8c29-45a4-bbce-490eb01907d5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18b5675aff2d10f224238a1ba6d3b919e1b285a7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374576"
---
# <a name="the-ccmdui-class"></a>A classe CCmdUI

Quando ele encaminha a um comando de atualização para o seu manipulador, o framework passa o manipulador de um ponteiro para um `CCmdUI` objeto (ou a um objeto de um `CCmdUI`-classe derivada). Este objeto representa o botão de barra de ferramentas ou item de menu ou outro objeto de interface do usuário que gerou o comando. O manipulador de atualização chama o membro de funções do `CCmdUI` estrutura através do ponteiro para atualizar o objeto de interface do usuário. Por exemplo, aqui está um manipulador de atualização para o item de menu Limpar tudo:

[!code-cpp[NVC_MFCDocView#3](../mfc/codesnippet/cpp/the-ccmdui-class_1.cpp)]

Esse manipulador chama o `Enable` a função de membro de um objeto com acesso ao item de menu. `Enable` o item torna disponível para uso.

## <a name="see-also"></a>Consulte também

[Como atualizar objetos da interface do usuário](../mfc/how-to-update-user-interface-objects.md)

