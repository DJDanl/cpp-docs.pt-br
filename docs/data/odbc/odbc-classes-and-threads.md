---
title: Classes e threads ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC classes, and threads
- ODBC, multithreaded applications
- threading [MFC], ODBC support
ms.assetid: 16543926-7331-41a6-ba50-72288f2a61b7
ms.openlocfilehash: 8cb5df605bef31e177e976798f975bb4ca14ced7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213143"
---
# <a name="odbc-classes-and-threads"></a>Classes e threads ODBC

A partir do MFC 4,2, há suporte multithread para as classes ODBC do MFC. No entanto, observe que o MFC não fornece suporte multithread para as classes DAO.

O suporte a multithreading para as classes ODBC tem algumas limitações. Como essas classes encapsulam a API ODBC, elas são restritas ao suporte multithreading dos componentes nos quais elas são criadas. Por exemplo, muitos drivers ODBC não são thread-safe; Portanto, as classes ODBC do MFC não são thread-safe se você usá-las com um desses drivers. Você deve verificar se o seu driver específico é thread-safe.

Ao criar um aplicativo multi-threaded, você deve ser muito cuidadoso ao usar vários threads para manipular o mesmo objeto. Por exemplo, usar o mesmo objeto `CRecordset` em dois threads pode causar problemas ao recuperar dados; uma operação de busca em um thread pode substituir os dados buscados no outro thread. Um uso mais comum das classes ODBC do MFC em threads separados é compartilhar um objeto Open `CDatabase` entre threads para usar a mesma conexão ODBC, com um objeto `CRecordset` separado em cada thread. Observe que você não deve passar um objeto de `CDatabase` não aberto para um objeto `CRecordset` em outro thread.

> [!NOTE]
>  Se for necessário que vários threads manipulem o mesmo objeto, você deverá implementar os mecanismos de sincronização apropriados, como seções críticas. Lembre-se de que determinadas operações, como `Open`, não estão protegidas. Você deve ter certeza de que essas operações não serão chamadas simultaneamente de threads separados.

Para obter mais informações sobre como criar aplicativos multissegmentados, consulte os [Tópicos de multithreading](../../parallel/multithreading-support-for-older-code-visual-cpp.md).

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Programação de Acesso a Dados (MFC/ATL)](../../data/data-access-programming-mfc-atl.md)
