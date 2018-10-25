---
title: Classes e Threads ODBC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC classes, and threads
- ODBC, multithreaded applications
- threading [MFC], ODBC support
ms.assetid: 16543926-7331-41a6-ba50-72288f2a61b7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ab115db1387adb71a69b735d676fa657d370752f
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052467"
---
# <a name="odbc-classes-and-threads"></a>Classes e threads ODBC

Começando com o MFC 4.2, não há suporte de multithreading para as classes MFC ODBC. No entanto, observe que o MFC não fornece suporte de multithreading para as classes DAO.

O suporte de multithreading para as classes ODBC tem algumas limitações. Porque essas classes envolvem a API do ODBC, eles são restritos ao multithreading suporte dos componentes nos quais eles são criados. Por exemplo, muitos drivers ODBC não são thread-safe; Portanto, as classes MFC ODBC não são thread-safe se usá-los com um desses drivers. Você deve verificar se o seu driver específico é thread-safe.

Ao criar um aplicativo multi-threaded, você deve ter muito cuidado com usando vários threads para manipular o mesmo objeto. Por exemplo, usando a mesma `CRecordset` objeto em dois threads pode causar problemas ao recuperar dados; uma operação de busca em um thread pode substituir os dados buscados o outro thread. Um uso mais comum das classes ODBC do MFC em threads separados é compartilhar um aberto `CDatabase` objeto entre threads para usar a mesma conexão do ODBC, com um separado `CRecordset` objeto em cada thread. Observe que você não deve passar um não abertos `CDatabase` do objeto para um `CRecordset` objeto em outro thread.

> [!NOTE]
>  Se você precisar ter vários threads manipular o mesmo objeto, você deve implementar os mecanismos de sincronização apropriado, como seções críticas. Esteja ciente que certas operações, como `Open`, não estão protegidos. Você deve ter certeza de que essas operações não serão chamadas simultaneamente de threads separados.

Para obter mais informações sobre a criação de aplicativos multi-threaded, consulte [tópicos de Multithreading](../../parallel/multithreading-support-for-older-code-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Acesso a dados (MFC/ATL) de programação](../../data/data-access-programming-mfc-atl.md)