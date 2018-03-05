---
title: 'Fonte de dados: Determinando o esquema da fonte de dados (ODBC) | Microsoft Docs'
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
- ODBC data sources [C++], schema
- schemas [C++], data sources
- data sources [C++], determining schema
ms.assetid: 17284acb-eb10-4f27-9944-ad1d973c0b05
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: fc425cf767db6939223288ebe74dcbc7fd4cf5b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="data-source-determining-the-schema-of-the-data-source-odbc"></a>Fonte de dados: determinando o esquema da fonte de dados (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Para configurar os membros de dados em seu `CRecordset` objetos, você precisa saber o esquema da fonte de dados ao qual você está se conectando. Determinando o esquema de fonte de dados envolve obter uma lista de tabelas na fonte de dados, uma lista de colunas em cada tabela, o tipo de dados de cada coluna e a existência de todos os índices.  
  
## <a name="see-also"></a>Consulte também  
 [Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)   
 [Fonte de dados: gerenciando conexões (ODBC)](../../data/odbc/data-source-managing-connections-odbc.md)