---
title: 'ODBC: Configurando uma fonte de dados ODBC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC data sources, configuring
- ODBC connections, configuring
- configuring ODBC data sources
ms.assetid: 1cd03e6a-8d59-4eca-a8c6-1010582d5e67
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a9a0cd385596f62432f16b7e5abc4259a267dd76
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50080306"
---
# <a name="odbc-configuring-an-odbc-data-source"></a>ODBC: configurando uma fonte de dados ODBC

Para usar um [fonte de dados](../../data/odbc/data-source-odbc.md) com um aplicativo que você desenvolveu, você deve usar o administrador de ODBC para configurá-lo. Administrador de ODBC controla de fontes de dados disponíveis e suas informações de conexão no registro do Windows. Use o administrador de ODBC para adicionar, modificar e excluir fontes de dados de **fontes de dados** caixa de diálogo para adicionar e excluir os drivers ODBC.

> [!NOTE]
>  Essas informações se aplicam quando você usa as classes de objeto de acesso a dados MFC (DAO) para acesso a ODBC e quando você usa as classes MFC ODBC.

Administrador de ODBC é instalado automaticamente com o suporte de banco de dados de biblioteca Microsoft Foundation Classes (MFC). Para obter mais informações sobre o programa Administrador de ODBC, consulte [administrador de ODBC](../../data/odbc/odbc-administrator.md) e o sistema de ajuda de referência de API do ODBC online.

Para obter informações sobre como escrever programas de instalação do ODBC e administração para aplicativos de banco de dados do MFC,[48 de observação técnica](../../mfc/tn048-writing-odbc-setup-and-administration-programs.md).

## <a name="see-also"></a>Consulte também

[Noções básicas de ODBC](../../data/odbc/odbc-basics.md)<br/>
[ODBC: chamando funções de API ODBC diretamente](../../data/odbc/odbc-calling-odbc-api-functions-directly.md)