---
title: Classes ODBC e as banco de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- database classes [C++], ODBC
- ODBC API functions [C++]
- ODBC classes [C++], MFC database classes
- MFC [C++], ODBC and
ms.assetid: b166f82d-6f85-4556-aac8-fb851235d22c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: abbb20b76f8e24a9b0f20961728dd8e428733654
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33088461"
---
# <a name="odbc-and-the-database-classes"></a>Classes ODBC e de banco de dados
As classes de banco de dados ODBC MFC encapsulam as chamadas de função de API ODBC que você normalmente faria por conta própria no membro de funções do [CDatabase](../../mfc/reference/cdatabase-class.md) e [CRecordset](../../mfc/reference/crecordset-class.md) classes. Por exemplo, a sequências de chamada ODBC complexas, a associação de registros retornados em locais de armazenamento, manipulação de condições de erro e outras operações são gerenciadas para você por classes de banco de dados. Como resultado, você deve usar uma interface de classe consideravelmente mais simples para manipular registros por meio de um objeto de conjunto de registros.  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
 Embora as classes de banco de dados encapsulam funcionalidades ODBC, eles não fornecer um mapeamento de funções de API de ODBC. As classes de banco de dados fornecem um nível mais alto de abstração, modelada de objetos de acesso a dados localizados no Microsoft Access e o Microsoft Visual Basic. Para obter mais informações, consulte [ODBC e MFC](../../data/odbc/odbc-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)