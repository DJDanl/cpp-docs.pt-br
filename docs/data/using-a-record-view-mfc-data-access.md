---
title: Usando uma exibição do registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- record views, customizing default code
ms.assetid: 91f2828f-0666-4273-ae28-e4703fd98521
ms.openlocfilehash: 9d64fc26e1c78bad0431bc9b10dd5117c4866159
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59029350"
---
# <a name="using-a-record-view--mfc-data-access"></a>Usando uma exibição do registro (Acesso a dados MFC)

Este tópico explica como você pode personalizar o código padrão de exibições de registro que o assistente grava para você. Normalmente, você pode restringir a seleção de registro com um [filtro](../data/odbc/recordset-filtering-records-odbc.md) ou [parâmetros](../data/odbc/recordset-parameterizing-a-recordset-odbc.md), talvez [classificação](../data/odbc/recordset-sorting-records-odbc.md) os registros, personalizar a instrução SQL.

Usando o `CRecordView` é muito semelhante a usar [CFormView](../mfc/reference/cformview-class.md). A abordagem básica é usar a exibição do registro para exibir e atualizar talvez os registros de um único conjunto de registros. Além disso, você talvez queira usar outros conjuntos de registros também, conforme discutido em [exibições de registro: Preenchendo uma caixa de listagem de um segundo conjunto de registros](../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).

## <a name="see-also"></a>Consulte também

[Exibição de registro (Acesso a dados MFC)](../data/record-views-mfc-data-access.md)<br/>
[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)