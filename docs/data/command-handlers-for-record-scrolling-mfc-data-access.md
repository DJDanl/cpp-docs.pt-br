---
title: Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views [C++], scrolling
- record scrolling [C++]
- scrolling records
ms.assetid: f8b13477-2a37-459e-a30c-806fb78165ac
ms.openlocfilehash: 8bbacd6625e846381d2bafc8133e8b36efe51b1a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213441"
---
# <a name="command-handlers-for-record-scrolling--mfc-data-access"></a>Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)

A classe [CRecordView](../mfc/reference/crecordview-class.md) fornece manipulação de comandos padrão para os seguintes comandos padrão:

- ID_RECORD_MOVE_FIRST

- ID_RECORD_MOVE_LAST

- ID_RECORD_MOVE_NEXT

- ID_RECORD_MOVE_PREV

A função membro `OnMove` fornece o tratamento de comandos padrão para todos os quatro comandos, que se movem de registro para registro. Como esses comandos são emitidos, RFX (ou DFX) carrega o novo registro nos campos do conjunto de registros e DDX move os valores para os controles do formulário de registro. Para obter informações sobre suporte RFX, consulte [Record Field Exchange (suporte RFX)](../data/odbc/record-field-exchange-rfx.md).

> [!NOTE]
>  Certifique-se de usar essas IDs de comando padrão para os objetos de interface de usuário associados com os comandos de navegação de registro padrão.

## <a name="see-also"></a>Confira também

[Suporte à navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)
