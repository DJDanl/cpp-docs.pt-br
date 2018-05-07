---
title: Requisitos de Driver ODBC para Dynasets | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC recordsets, dynasets
- drivers, for dynasets
- drivers, ODBC
- recordsets, dynasets
- dynasets
- ODBC drivers, dynasets
ms.assetid: 585cc67b-4d92-404b-9903-d769cd17badc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d9fad26440cea2c8ec2efd7d07dacb83547252e3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="odbc-driver-requirements-for-dynasets"></a>Requisitos de driver ODBC para dynasets
As classes de banco de dados ODBC MFC, dynasets são conjuntos de registros com as propriedades dinâmicas; eles permanecem sincronizados com a fonte de dados de determinadas maneiras. MFC dynasets (mas conjuntos de registros somente de encaminhamento não) requerem um driver ODBC com conformidade de API do nível 2. Se o driver para o seu [fonte de dados](../../data/odbc/data-source-odbc.md) está em conformidade com a API de nível 1 definido, você ainda pode usar instantâneos atualizáveis tanto somente leitura e conjuntos de registros somente de encaminhamento, mas não dynasets. No entanto, um driver de nível 1 pode suporta dynasets se ele dá suporte a busca estendida e os cursores controlados por conjunto de chaves.  
  
 Na terminologia ODBC, dynasets e instantâneos são denominados cursores. Um cursor é um mecanismo usado para controlar sua posição em um conjunto de registros. Para obter mais informações sobre requisitos de driver para dynasets, consulte [Dynaset](../../data/odbc/dynaset.md). Para obter mais informações sobre cursores, consulte o [conectividade aberta de banco de dados (ODBC)](https://msdn.microsoft.com/en-us/library/ms710252.aspx) SDK na documentação do MSDN.  
  
> [!NOTE]
>  Para conjuntos de registros pode ser atualizados, o driver ODBC deve oferecer suporte das instruções update posicionadas ou **:: SQLSetPos** função da API do ODBC. Se ambos são suportadas, MFC usa **:: SQLSetPos** para maior eficiência. Como alternativa, para instantâneos, você pode usar a biblioteca de cursores, que fornece o suporte necessário para instantâneos atualizáveis (Cursores estáticos e instruções update posicionadas).  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)