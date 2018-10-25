---
title: Manipuladores de comando para rolagem de registro (acesso de dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views [C++], scrolling
- record scrolling [C++]
- scrolling records
ms.assetid: f8b13477-2a37-459e-a30c-806fb78165ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6733603ff95d4bf12b9eec142fff12b5ca0458a9
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50057758"
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