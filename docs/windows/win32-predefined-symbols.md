---
title: Símbolos predefinidos Win32 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Win32 [C++], predefined symbols
- symbols [C++], Win32 predefined
- Windows API [C++], predefined symbols
ms.assetid: 45c8e193-ee2a-4024-bfc2-34d1ec9c9239
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 18edb56c03541f61607817d14fdbadb067a3630d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422773"
---
# <a name="win32-predefined-symbols"></a>Símbolos predefinidos Win32

Esses símbolos são definidos nos arquivos de cabeçalho do Win32, e eles dão suporte a ações e funções de aplicativo do Windows padrão. Esses símbolos são usados principalmente com elementos de interface do usuário comuns. Quando você estiver trabalhando com controles nos editores de recursos, esses símbolos aparecerá na [janela de propriedades](/visualstudio/ide/reference/properties-window) associados a controles comuns. Por exemplo, se sua barra de ferramentas deve exibir o ícone do aplicativo, o ícone será associado com o símbolo IDI_SMALL na **janela propriedade**.

|||
|-|-|
|IDABORT|Controle: Botão de anulação de caixa de diálogo|
|IDC_STATIC|Controle: O texto estático em uma caixa de diálogo|
|IDCANCEL|Controle: Botão de cancelamento de caixa de diálogo|
|IDD_ABOUTBOX|Caixa de diálogo: Produto caixa de diálogo sobre|
|IDI_PROJECTNAME|Ícone: Ícone de projeto atual|
|IDI_SMALL|Ícone: Ícone pequeno atual projeto|
|IDIGNORE|Controle: Usado com o botão Ignorar em caixas de diálogo|
|IDM_ABOUT|Item de menu: Usado com a Ajuda... Sobre...|
|IDM_EXIT|Item de menu: Usado com o arquivo... Sair...|
|IDNO|Controle: não caixa de diálogo nenhum botão|
|IDOK|Controle: Botão de Okey da caixa de diálogo|
|IDRETRY|Controle: Botão de repetição de caixa de diálogo|
|IDS_APP_TITLE|Cadeia de caracteres: Nome do aplicativo atual|
|IDYES|Controle: Caixa de diálogo Sim botão|

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>
[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)