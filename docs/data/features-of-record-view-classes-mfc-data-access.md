---
title: Recursos de registro Exibir Classes (MFC acesso a dados) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views, classes
- record view classes
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9b6717c0ef1167e01df2f5e8de14408b23a9dbb1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33089566"
---
# <a name="features-of-record-view-classes--mfc-data-access"></a>Recursos de classes de exibição de registro (Acesso a dados MFC)
Você pode fazer uma programação de acesso a dados baseado em formulário com a classe [CFormView](../mfc/reference/cformview-class.md), mas [CRecordView](../mfc/reference/crecordview-class.md) geralmente é uma classe melhor derivar. Além de seu `CFormView` recursos, `CRecordView`:  
  
-   Fornece a troca de dados de caixa de diálogo (DDX) entre os controles de formulário e o objeto de conjunto de registros associado.  
  
-   Controla os comandos mover primeiro, mover próximo, mover anterior e mover último para navegar entre os registros no objeto recordset associado.  
  
-   Atualiza as alterações feitas no registro atual quando o usuário se desloca para outro registro.  
  
 Para obter mais informações sobre a navegação, consulte [exibições de registro: navegação com suporte em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md).  
  
## <a name="see-also"></a>Consulte também  
 [Exibições de registro (acesso a dados MFC)](../data/record-views-mfc-data-access.md)   
 [Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)