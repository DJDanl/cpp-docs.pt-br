---
title: Classes ODBC e as banco de dados | Microsoft Docs
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
- database classes [C++], ODBC
- ODBC API functions [C++]
- ODBC classes [C++], MFC database classes
- MFC [C++], ODBC and
ms.assetid: b166f82d-6f85-4556-aac8-fb851235d22c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e3041a4fc027a8786fb62db7df6eaf486633ce97
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="odbc-and-the-database-classes"></a>Classes ODBC e de banco de dados
As classes de banco de dados ODBC MFC encapsulam as chamadas de função de API ODBC que você normalmente faria por conta própria no membro de funções do [CDatabase](../../mfc/reference/cdatabase-class.md) e [CRecordset](../../mfc/reference/crecordset-class.md) classes. Por exemplo, a sequências de chamada ODBC complexas, a associação de registros retornados em locais de armazenamento, manipulação de condições de erro e outras operações são gerenciadas para você por classes de banco de dados. Como resultado, você deve usar uma interface de classe consideravelmente mais simples para manipular registros por meio de um objeto de conjunto de registros.  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
 Embora as classes de banco de dados encapsulam funcionalidades ODBC, eles não fornecer um mapeamento de funções de API de ODBC. As classes de banco de dados fornecem um nível mais alto de abstração, modelada de objetos de acesso a dados localizados no Microsoft Access e o Microsoft Visual Basic. Para obter mais informações, consulte [ODBC e MFC](../../data/odbc/odbc-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)