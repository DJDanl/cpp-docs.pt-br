---
title: "Usando uma exibição de registro (acesso a dados MFC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- record views, customizing default code
ms.assetid: 91f2828f-0666-4273-ae28-e4703fd98521
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 18d3b4b36d63013fcb5e3762f96e5970644cbff0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-a-record-view--mfc-data-access"></a>Usando uma exibição do registro (Acesso a dados MFC)
Este tópico explica como você pode personalizar o código padrão de exibições de registro que o assistente grava para você. Normalmente, você deseja restringir a seleção de registro com um [filtro](../data/odbc/recordset-filtering-records-odbc.md) ou [parâmetros](../data/odbc/recordset-parameterizing-a-recordset-odbc.md), talvez [classificação](../data/odbc/recordset-sorting-records-odbc.md) registros, personalizar a instrução SQL.  
  
 Usando `CRecordView` é muito semelhante a usar [CFormView](../mfc/reference/cformview-class.md). A abordagem básica é usar a exibição do registro para exibir e atualizar talvez os registros de um único conjunto de registros. Além disso, talvez você queira usar outros conjuntos de registros, assim como discutido em [exibições de registro: preenchimento de uma caixa de listagem de um segundo conjunto de registros](../data/filling-a-list-box-from-a-second-recordset-mfc-data-access.md).  
  
## <a name="see-also"></a>Consulte também  
 [Exibições de registro (acesso a dados MFC)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)