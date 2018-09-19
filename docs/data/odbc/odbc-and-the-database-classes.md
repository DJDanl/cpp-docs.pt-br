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
ms.openlocfilehash: bce3140818b46bd6cbb255794a08e9b0fa92fbd4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114963"
---
# <a name="odbc-and-the-database-classes"></a>Classes ODBC e de banco de dados

As classes de banco de dados ODBC MFC encapsulam as chamadas de função de API ODBC que você normalmente faria por conta própria no membro de funções do [CDatabase](../../mfc/reference/cdatabase-class.md) e [CRecordset](../../mfc/reference/crecordset-class.md) classes. Por exemplo, a associação de registros retornados em locais de armazenamento, manipulação de condições de erro e outras operações, sequências complexas de chamada ODBC são gerenciadas para você pelas classes de banco de dados. Como resultado, você deve usar uma interface de classe consideravelmente mais simples para manipular registros por meio de um objeto de conjunto de registros.  
  
> [!NOTE]
>  Fontes de dados ODBC são acessíveis por meio de classes MFC ODBC, conforme descrito neste tópico, ou as classes de objeto de acesso a dados MFC (DAO).  
  
Embora as classes de banco de dados encapsulam a funcionalidade de ODBC, eles não fornecem um mapeamento de funções API ODBC. As classes de banco de dados fornecem um nível mais alto de abstração, modelada de objetos de acesso a dados localizados no Microsoft Access e Microsoft Visual Basic. Para obter mais informações, consulte [ODBC e MFC](../../data/odbc/odbc-and-mfc.md).  
  
## <a name="see-also"></a>Consulte também  

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)