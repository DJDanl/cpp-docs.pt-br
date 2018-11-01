---
title: Recursos de classes de exibição de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views, classes
- record view classes
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
ms.openlocfilehash: 2feda8f8f446e02a5056287c656707ea038f5387
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461146"
---
# <a name="features-of-record-view-classes--mfc-data-access"></a>Recursos de classes de exibição de registro (Acesso a dados MFC)

Você pode fazer programação de acesso a dados baseado em formulário com classe [CFormView](../mfc/reference/cformview-class.md), mas [CRecordView](../mfc/reference/crecordview-class.md) geralmente é uma classe melhor derivar. Além seus `CFormView` recursos, `CRecordView`:

- Fornece a troca de dados de caixa de diálogo (DDX) entre os controles de formulário e o objeto de conjunto de registros associado.

- Lida com os comandos mover primeiro, mover próximo, mover anterior e mover último para navegar pelos registros no objeto de conjunto de registros associado.

- Atualiza as alterações feitas no registro atual quando o usuário move para outro registro.

Para obter mais informações sobre navegação, consulte [exibições de registro: suportando navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md).

## <a name="see-also"></a>Consulte também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)