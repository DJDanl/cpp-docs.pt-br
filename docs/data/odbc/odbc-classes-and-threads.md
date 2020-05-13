---
title: Classes e threads ODBC
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC classes, and threads
- ODBC, multithreaded applications
- threading [MFC], ODBC support
ms.assetid: 16543926-7331-41a6-ba50-72288f2a61b7
ms.openlocfilehash: aaf54a3a1d616cde5742dad45955bd415f612d60
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368695"
---
# <a name="odbc-classes-and-threads"></a>Classes e threads ODBC

Começando com o MFC 4.2, há suporte multithreading para as classes MFC ODBC. Observe, no entanto, que o MFC não fornece suporte multithreading para as classes DAO.

O suporte multithreading para as classes ODBC tem algumas limitações. Como essas classes envolvem a API ODBC, elas estão restritas ao suporte multithreading dos componentes nos quais são construídas. Por exemplo, muitos drivers ODBC não são seguros para threads; portanto, as classes MFC ODBC não são seguras para threads se você usá-las com um desses drivers. Você deve verificar se o driver em particular é seguro para rosca.

Ao criar um aplicativo multithreaded, você deve ter muito cuidado ao usar vários threads para manipular o mesmo objeto. Por exemplo, usar `CRecordset` o mesmo objeto em dois segmentos pode causar problemas ao recuperar dados; uma operação de buscar em um segmento pode substituir os dados buscados no outro segmento. Um uso mais comum das classes MFC ODBC em `CDatabase` segmentos separados é compartilhar um objeto aberto `CRecordset` entre os segmentos para usar a mesma conexão ODBC, com um objeto separado em cada segmento. Observe que você não deve `CDatabase` passar `CRecordset` um objeto não aberto para um objeto em outro segmento.

> [!NOTE]
> Se você deve ter vários segmentos manipulando o mesmo objeto, você deve implementar os mecanismos de sincronização apropriados, como seções críticas. Esteja ciente de que `Open`certas operações, tais como , não estão protegidas. Você deve ter certeza de que essas operações não serão chamadas simultaneamente de segmentos separados.

Para obter mais informações sobre a criação de aplicativos multithreaded, consulte [Multithreading Topics](../../parallel/multithreading-support-for-older-code-visual-cpp.md).

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Programação de Acesso a Dados (MFC/ATL)](../../data/data-access-programming-mfc-atl.md)
