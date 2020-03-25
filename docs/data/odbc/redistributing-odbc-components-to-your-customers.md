---
title: Redistribuindo componentes ODBC para os clientes
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC components, redistributing
- ODBC, distributing components
- components [C++], distributing
- ODBC Administrator
- components [C++]
- components [C++], redistributing
ms.assetid: 17b065b4-a307-4b89-99ac-d05831cfab87
ms.openlocfilehash: 0d4d3948add665c54be3d3b0596a7a6fc0e414f5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212726"
---
# <a name="redistributing-odbc-components-to-your-customers"></a>Redistribuindo componentes ODBC para os clientes

Se você incorporar a funcionalidade dos programas de Administrador ODBC em seu aplicativo, também deverá distribuir para os usuários os arquivos que executam esses programas. Esses arquivos ODBC residem no diretório \OS\System do CD-ROM C++ do Visual. O arquivo Redistrb. wri e o contrato de licença no mesmo diretório contêm uma lista de arquivos ODBC que você pode redistribuir.

Consulte a documentação de quaisquer drivers ODBC que você planeja enviar. Você precisa determinar quais DLLs e outros arquivos enviar. Você também deve ler [a redistribuição de componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md), o que explica como redistribuir componentes ODBC.

Além disso, você precisa incluir um outro arquivo na maioria dos casos. O Odbccr32. dll é a biblioteca de cursores ODBC. Essa biblioteca fornece aos drivers de nível 1 o recurso de rolagem para frente e para trás. Ele também fornece a capacidade de dar suporte a instantâneos. Para obter mais informações sobre a biblioteca de cursores ODBC, consulte [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

Os tópicos a seguir fornecem mais informações sobre como usar o ODBC com as classes de banco de dados:

- [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)

- [ODBC: configurando uma fonte de dados ODBC](../../data/odbc/odbc-configuring-an-odbc-data-source.md)

- [ODBC: chamando funções de API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md)

## <a name="see-also"></a>Confira também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)<br/>
[Administrador do ODBC](../../data/odbc/odbc-administrator.md)
