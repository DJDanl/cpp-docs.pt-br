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
ms.openlocfilehash: ca19064ec35ba27564dc2e9abbe96087b08823e4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060272"
---
# <a name="odbc-driver-requirements-for-dynasets"></a>Requisitos de driver ODBC para dynasets

As classes de banco de dados ODBC do MFC, dynasets são conjuntos de registros com propriedades dinâmicas; eles permanecem sincronizados com a fonte de dados de determinadas maneiras. MFC dynasets (mas não apenas de encaminhamento de conjuntos de registros) exigem um driver ODBC com conformidade com a API do nível 2. Se o driver para o seu [fonte de dados](../../data/odbc/data-source-odbc.md) está de acordo com a API de nível 1 definido, você ainda pode usar instantâneos atualizáveis tanto como somente leitura e somente de encaminhamento de conjuntos de registros, mas não dynasets. No entanto, um driver de nível 1 pode dar suporte a dynasets se ele dá suporte a busca estendida e cursores controlados por conjunto de chaves.  
  
Na terminologia do ODBC, dynasets e os instantâneos são denominados cursores. Um cursor é um mecanismo usado para controlar sua posição em um conjunto de registros. Para obter mais informações sobre os requisitos de driver para dynasets, consulte [Dynaset](../../data/odbc/dynaset.md). Para obter mais informações sobre cursores, consulte o [conectividade aberta de banco de dados (ODBC)](/previous-versions/windows/desktop/ms710252\(v=vs.85\)) SDK na documentação do MSDN.  
  
> [!NOTE]
>  Para conjuntos de registros pode ser atualizados, o driver ODBC deve oferecer suporte das instruções de atualização posicionada ou o `::SQLSetPos` função ODBC API. Se ambos forem compatíveis, o MFC usa `::SQLSetPos` para maior eficiência. Como alternativa, para instantâneos, você pode usar a biblioteca de cursores, que fornece o suporte necessário para instantâneos atualizáveis (Cursores estáticos e instruções update posicionadas).  
  
## <a name="see-also"></a>Consulte também  

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)