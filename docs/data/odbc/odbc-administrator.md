---
title: Administrador de ODBC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- installing ODBC
- ODBC data sources [C++], ODBC Administrator
- ODBC drivers [C++], installing
- ODBC [C++], ODBC Administrator
- Administrator in ODBC
- administration ODBC Administrator
- ODBC Administrator [C++]
- drivers [C++], ODBC
ms.assetid: b8652790-3437-4e7d-bc83-6ea6981f008b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5c00527b5378805e0aa81c74c23175edd39bd144
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052571"
---
# <a name="odbc-administrator"></a>Administrador ODBC

Administrador de ODBC registra e configura o [fontes de dados](../../data/odbc/data-source-odbc.md) disponíveis para você localmente ou em uma rede. Os assistentes usam as informações fornecidas pelo administrador de ODBC para criar código em seus aplicativos que se conecta os usuários às fontes de dados.

Para configurar uma fonte de dados ODBC para uso com as classes MFC ODBC ou as classes de objeto de acesso a dados MFC (DAO), você deve primeiro registrar e configurar a fonte de dados. Use o administrador de ODBC para adicionar e remover fontes de dados. Dependendo do driver ODBC, você também pode criar novas fontes de dados.

Administrador de ODBC é instalado durante a instalação. Se você escolheu **personalizado** instalação e não tenha selecionado a todos os drivers ODBC na **opções de banco de dados** caixa de diálogo, você precisa executar a instalação novamente para instalar os arquivos necessários.

Durante a instalação, você deve selecionar os drivers ODBC que você deseja instalar. Posteriormente, você pode instalar drivers adicionais que são fornecidos com o Visual C++ usando o programa de instalação do Visual C++.

Se você quiser instalar os drivers ODBC não são fornecidas com o Visual C++, você deve executar o programa de instalação que acompanha o driver.

#### <a name="to-install-odbc-drivers-that-ship-with-visual-c"></a>Para instalar drivers ODBC que são fornecidos com o Visual C++

1. Execute a instalação do CD de distribuição do Visual C++.

   Abrir a caixa de diálogo do programa de instalação é aparece.

1. Clique em **próxima** em cada caixa de diálogo até que o **opções de instalação** caixa de diálogo. Selecione **personalizado**e, em seguida, clique em **próxima**.

1. Desmarque todas as caixas de seleção na **instalação do Microsoft Visual C++** caixa de diálogo, exceto o **opções de banco de dados** caixa de seleção e, em seguida, clique em **detalhes** para exibir o **Opções de banco de dados** caixa de diálogo.

1. Desmarque a **objetos do Microsoft Data Access** caixas de seleção a **Drivers ODBC da Microsoft** caixa de seleção e, em seguida, clique em **detalhes**.

   O **Drivers ODBC da Microsoft** caixa de diálogo é exibida.

1. Selecione os drivers que você deseja instalar e, em seguida, clique em **Okey** duas vezes.

1. Clique em **próxima** nas caixas de diálogo restantes para iniciar a instalação. Instalação notifica você quando a instalação for concluída.

Quando os drivers são instalados, você pode configurar a fonte de dados usando o administrador ODBC. Você encontrará o ícone do ODBC no painel de controle.

## <a name="see-also"></a>Consulte também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)