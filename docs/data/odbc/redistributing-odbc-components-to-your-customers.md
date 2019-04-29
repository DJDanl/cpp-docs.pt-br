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
ms.openlocfilehash: 1a6ec6f5fdd3c32080d357ca58d31ccea271b7a4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62330070"
---
# <a name="redistributing-odbc-components-to-your-customers"></a>Redistribuindo componentes ODBC para os clientes

Se você incorporar a funcionalidade dos programas administrador ODBC em seu aplicativo, você deve também distribuir aos seus usuários os arquivos que executam esses programas. Esses arquivos ODBC residem no diretório \OS\System do CD-ROM do Visual C++. O contrato de licença no mesmo diretório e o arquivo Redistrb.wri contêm uma lista de arquivos ODBC que pode ser redistribuído.

Consulte a documentação para drivers ODBC que você planeja enviar. Você precisa determinar quais DLLs e outros arquivos para o envio. Você também deve ler [redistribuir componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md), que explica como redistribuir componentes ODBC.

Além disso, você precisa incluir um outro arquivo na maioria dos casos. O Odbccr32.dll é a biblioteca de cursores ODBC. Essa biblioteca fornece a capacidade de rolagem para frente e para trás de drivers de nível 1. Ele também fornece a capacidade de dar suporte a instantâneos. Para obter mais informações sobre a biblioteca de cursores ODBC, consulte [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).

Os tópicos a seguir fornecem mais informações sobre como usar o ODBC com as classes de banco de dados:

- [ODBC: a biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)

- [ODBC: configurar uma fonte de dados ODBC](../../data/odbc/odbc-configuring-an-odbc-data-source.md)

- [ODBC: chamar funções de API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md)

## <a name="see-also"></a>Consulte também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)<br/>
[Administrador do ODBC](../../data/odbc/odbc-administrator.md)