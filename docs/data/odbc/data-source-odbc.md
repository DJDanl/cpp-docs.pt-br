---
title: Fonte de dados (ODBC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC data sources, configuring
- CDatabase class, data source connections
- ODBC data sources
- configuring ODBC data sources
- ODBC data sources, represented by CDatabase
ms.assetid: b246721f-b9e1-49bd-a6c7-f348b8c3d537
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6ad24a7be5c46c8019b22629003306ea99c56fd3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106930"
---
# <a name="data-source-odbc"></a>Fonte de dados (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Em termos de banco de dados, uma fonte de dados é um conjunto específico de dados, as informações necessárias para acessar esses dados e o local da fonte de dados, que pode ser descrito usando um nome de fonte de dados. Para trabalhar com a classe [CDatabase](../../mfc/reference/cdatabase-class.md), a fonte de dados deve ser um que você configurou por meio do administrador de conectividade de banco de dados aberto (ODBC). Exemplos de fontes de dados incluem um banco de dados remoto em execução no Microsoft SQL Server em uma rede ou um arquivo do Microsoft Access em um diretório local. Do seu aplicativo, você pode acessar qualquer fonte de dados para o qual você tem um driver ODBC.  
  
Você pode ter uma ou mais fontes de dados Active Directory em seu aplicativo ao mesmo tempo, cada um representado por um `CDatabase` objeto. Você também pode ter várias conexões simultâneas a qualquer fonte de dados. Você pode se conectar remotamente, bem como para fontes de dados locais, dependendo dos drivers instalados por você e os recursos de seus drivers ODBC. Para obter mais informações sobre fontes de dados e o administrador de ODBC, consulte [ODBC](../../data/odbc/odbc-basics.md) e [administrador ODBC](../../data/odbc/odbc-administrator.md).  
  
Os tópicos a seguir explicam mais sobre fontes de dados:  
  
- [Fonte de dados: gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md)  
  
- [Fonte de dados: determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)  
  
## <a name="see-also"></a>Consulte também  

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)