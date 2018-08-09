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
- status bars, associating menu items
- menus, status bar text
ms.assetid: 757c0e02-bc97-493f-bccd-6cc6887ebc64
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d868c9270e23e2ee1fa0dcdc1845d9762cefb16c
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39649395"
---
# <a name="associating-menu-commands-with-status-bar-text-in-mfc-applications"></a>Associando comandos de menu ao texto da barra de status em aplicativos MFC
O aplicativo pode exibir o texto descritivo para cada um dos comandos de menu, que um usuário pode selecionar. Você pode fazer isso atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade no **propriedades** janela. Se você tiver uma cadeia de caracteres na [tabela de cadeia de caracteres](../windows/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC exibirá automaticamente esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando um usuário passa o mouse sobre um item de menu.  
  
### <a name="to-associate-a-menu-command-with-a-status-bar-text-string"></a>Para associar um comando de menu com um cadeia de caracteres de texto da barra de status  
  
1.  No **Menu** editor, selecione o comando de menu.  
  
2.  No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite o texto da barra de status associado na **Prompt** caixa.  
  
## <a name="requirements"></a>Requisitos  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)   
 [Adicionando comandos a um Menu](../windows/adding-commands-to-a-menu.md)   
 [Editor de Menu](../windows/menu-editor.md)