---
title: Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views [C++], scrolling
- record scrolling [C++]
- scrolling records
ms.assetid: f8b13477-2a37-459e-a30c-806fb78165ac
ms.openlocfilehash: 66944221910dbd23d78a78fc951030efbee86bd0
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038506"
---
# <a name="command-handlers-for-record-scrolling--mfc-data-access"></a>Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)

O [CRecordView](../mfc/reference/crecordview-class.md) classe fornece padrão manipulação de comando para os seguintes comandos:

- ID_RECORD_MOVE_FIRST

- ID_RECORD_MOVE_LAST

- ID_RECORD_MOVE_NEXT

- ID_RECORD_MOVE_PREV

O `OnMove` função de membro fornece manipulação para todos os quatro comandos, que move de um registro para o registro de comando padrão. Como esses comandos são emitidos, RFX (ou DFX) carrega o novo registro nos campos do conjunto de registros e DDX move os valores para os controles do formulário de registro. Para obter informações sobre RFX, consulte [Exchange RFX (Record Field)](../data/odbc/record-field-exchange-rfx.md).

> [!NOTE]
>  Certifique-se de usar essas IDs de comando padrão para os objetos de interface de usuário associados com os comandos de navegação de registro padrão.

## <a name="see-also"></a>Consulte também

[Suporte à navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)