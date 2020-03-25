---
title: Administrador ODBC
ms.date: 11/04/2016
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
ms.openlocfilehash: 9e88492919eac80a4f3db2f94202d49011aa69de
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213144"
---
# <a name="odbc-administrator"></a>Administrador ODBC

O Administrador ODBC registra e configura as [fontes de dados](../../data/odbc/data-source-odbc.md) disponíveis para você localmente ou através de uma rede. Os assistentes usam as informações fornecidas pelo Administrador ODBC para criar código em seus aplicativos que conectam seus usuários a fontes de dados.

Para configurar uma fonte de dados ODBC para uso com as classes ODBC do MFC ou as classes do objeto de acesso a dados do MFC (DAO), primeiro você deve registrar e configurar a fonte de dados. Use o Administrador ODBC para adicionar e remover fontes de dados. Dependendo do driver ODBC, você também pode criar novas fontes de dados.

O Administrador ODBC é instalado durante a instalação. Se você escolher instalação **personalizada** e não tiver selecionado nenhum driver ODBC na caixa de diálogo **Opções de banco de dados** , será necessário executar a instalação novamente para instalar os arquivos necessários.

Durante a instalação, você seleciona os drivers ODBC que deseja instalar. Posteriormente, você poderá instalar drivers adicionais que acompanham C++ o Visual usando C++ o programa de instalação Visual.

Se você quiser instalar drivers ODBC que não são fornecidos com o Visual C++, deverá executar o programa de instalação que acompanha o driver.

#### <a name="to-install-odbc-drivers-that-ship-with-visual-c"></a>Para instalar drivers ODBC que acompanham o VisualC++

1. Execute a instalação de seu C++ CD de distribuição Visual.

   A caixa de diálogo de abertura no programa de instalação é exibida.

1. Clique em **Avançar** em cada caixa de diálogo até chegar à caixa de diálogo **Opções de instalação** . Selecione **personalizado**e clique em **Avançar**.

1. Desmarque todas as caixas de seleção na caixa de diálogo  **C++ instalação do Microsoft Visual** , exceto a caixa de seleção opções de banco de **dados** e clique em **detalhes** para exibir a caixa de diálogo opções de **banco de dados** .

1. Desmarque a caixa de seleção **objetos do Microsoft Data Access** , marque a caixa de seleção **drivers do Microsoft ODBC** e clique em **detalhes**.

   A caixa de diálogo **Microsoft ODBC drivers** é exibida.

1. Selecione os drivers que você deseja instalar e clique em **OK** duas vezes.

1. Clique em **Avançar** nas caixas de diálogo restantes para iniciar a instalação. A instalação o notifica quando a instalação for concluída.

Quando os drivers são instalados, você pode configurar a fonte de dados usando o Administrador ODBC. Você encontrará o ícone ODBC no painel de controle.

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)<br/>
[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)
