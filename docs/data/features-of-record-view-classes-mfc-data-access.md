---
title: Recursos de classes de exibição de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views, classes
- record view classes
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
ms.openlocfilehash: 62597a3eb3f7a7e779ca57c9781565176df568d4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213428"
---
# <a name="features-of-record-view-classes--mfc-data-access"></a>Recursos de classes de exibição de registro (Acesso a dados MFC)

Você pode fazer a programação de acesso a dados baseada em formulário com a classe [CFormView](../mfc/reference/cformview-class.md), mas o [CRecordView](../mfc/reference/crecordview-class.md) geralmente é uma classe melhor da qual derivar. Além de seus recursos de `CFormView`, `CRecordView`:

- Fornece troca de dados de caixa de diálogo (campo DDX) entre os controles de formulário e o objeto Recordset associado.

- Manipula os comandos mover primeiro, mover próximo, mover anterior e mover último para navegar pelos registros no objeto Recordset associado.

- Atualiza as alterações no registro atual quando o usuário passa para outro registro.

Para obter mais informações sobre navegação, consulte [exibições de registro: suporte à navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md).

## <a name="see-also"></a>Confira também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)
