---
title: Associando comandos de Menu ao texto da barra de Status em aplicativos MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- status bars [C++], associating menu items
- menus [C++], status bar text
ms.assetid: 757c0e02-bc97-493f-bccd-6cc6887ebc64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 718766a8fc475f20bcbcc328973b38e486769d9c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46389063"
---
# <a name="associating-menu-commands-with-status-bar-text-in-mfc-applications"></a>Associando comandos de menu ao texto da barra de status em aplicativos MFC

Seu aplicativo do MFC pode exibir o texto descritivo para cada um dos comandos de menu, que um usuário pode selecionar. Você pode fazer isso atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade no **propriedades** janela. Se você tiver uma cadeia de caracteres na [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC exibirá automaticamente esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando um usuário passa o mouse sobre um item de menu.

### <a name="to-associate-a-menu-command-with-a-status-bar-text-string"></a>Para associar um comando de menu com um cadeia de caracteres de texto da barra de status

1. No **Menu** editor, selecione o comando de menu.

2. No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associado na **Prompt** caixa.

## <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Adicionando comandos a um menu](../windows/adding-commands-to-a-menu.md)<br/>
[Editor de Menu](../windows/menu-editor.md)