---
title: Personalização para MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- customizations, MFC Extensions
ms.assetid: 3b1b7532-8cc9-48dc-9bbe-7fd4060530b5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 640d6726623e8fb6d563153823f449f7caefcf30
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46384995"
---
# <a name="customization-for-mfc"></a>Personalização para MFC

Este tópico fornece dicas para personalizar um aplicativo do MFC.

## <a name="general-customizations"></a>Personalizações gerais

Você pode salvar e carregar o estado do seu aplicativo no registro. Quando você habilitar essa opção, seu aplicativo carregará seu estado inicial do registro. Se você alterar o layout de encaixe inicial para seu aplicativo, você precisará limpar os dados do registro para o seu aplicativo. Caso contrário, os dados no Registro substituirá todas as alterações feitas no layout inicial.

## <a name="class-specific-customizations"></a>Personalizações específicas de classe

Dicas de personalização adicionais podem ser encontradas nos tópicos a seguir:

- [Classe CBasePane](../mfc/reference/cbasepane-class.md)

- [Classe CDockablePane](../mfc/reference/cdockablepane-class.md)

- [Classe CDockingManager](../mfc/reference/cdockingmanager-class.md)

- [Classe CMFCBaseTabCtrl](../mfc/reference/cmfcbasetabctrl-class.md)

## <a name="additional-customization-tips"></a>Dicas de personalização adicional

[Personalização de teclado e mouse](../mfc/keyboard-and-mouse-customization.md)

[Ferramentas definidas pelo usuário](../mfc/user-defined-tools.md)

## <a name="see-also"></a>Consulte também

[Aplicativos da área de trabalho MFC](../mfc/mfc-desktop-applications.md)<br/>
[Implicações de segurança da personalização](../mfc/security-implications-of-customization.md)

