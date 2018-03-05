---
title: Recursos de registro Exibir Classes (MFC acesso a dados) | Microsoft Docs
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
- record views, classes
- record view classes
ms.assetid: e7b2820f-09c4-483f-83c0-317e8be42bdf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1c975aac0459a13a3fb95fdec3dff1a648b0efec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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