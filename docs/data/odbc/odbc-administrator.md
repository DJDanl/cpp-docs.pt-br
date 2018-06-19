---
title: Administrador ODBC | Microsoft Docs
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
ms.openlocfilehash: 55b214ba3513f95533e3892fb93ad9298c44415d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33090189"
---
# <a name="odbc-administrator"></a>Administrador ODBC
Administrador ODBC registra e configura o [fontes de dados](../../data/odbc/data-source-odbc.md) disponíveis localmente ou em uma rede. Os assistentes usam informações fornecidas pelo administrador de ODBC para criar o código em seus aplicativos que se conecta aos usuários a fontes de dados.  
  
 Para configurar uma fonte de dados ODBC para uso com as classes MFC ODBC ou as classes de objeto de acesso a dados MFC (DAO), você deve primeiro registrar e configurar a fonte de dados. Use o administrador ODBC para adicionar e remover fontes de dados. Dependendo do driver ODBC, você também pode criar novas fontes de dados.  
  
 Administrador de ODBC é instalado durante a instalação. Se você escolheu **personalizado** instalação e não tenha selecionado drivers ODBC no **opções de banco de dados** caixa de diálogo, você precisa executar a instalação novamente para instalar os arquivos necessários.  
  
 Durante a instalação, você deve selecionar os drivers ODBC que você deseja instalar. Posteriormente, você pode instalar drivers adicionais que são fornecidos com o Visual C++ usando o programa de instalação do Visual C++.  
  
 Se você deseja instalar os drivers ODBC que não são fornecidos com o Visual C++, você deve executar o programa de instalação que acompanha o driver.  
  
#### <a name="to-install-odbc-drivers-that-ship-with-visual-c"></a>Para instalar drivers ODBC que são fornecidos com o Visual C++  
  
1.  Execute a instalação do CD de distribuição do Visual C++.  
  
     Abrir a caixa de diálogo do programa de instalação será exibida.  
  
2.  Clique em **próximo** em cada caixa de diálogo até que você alcance a **opções de instalação** caixa de diálogo. Selecione **personalizado**e, em seguida, clique em `Next`.  
  
3.  Desmarque todas as caixas de seleção a **instalação do Microsoft Visual C++** caixa de diálogo, exceto o **opções de banco de dados** caixa de seleção e, em seguida, clique em **detalhes** para exibir o **Opções de banco de dados** caixa de diálogo.  
  
4.  Limpar o **objetos de acesso de dados do Microsoft** caixa de seleção, selecione o **Drivers de ODBC do Microsoft** caixa de seleção e, em seguida, clique em **detalhes**.  
  
     O **Drivers de ODBC do Microsoft** caixa de diálogo é exibida.  
  
5.  Selecione os drivers que você deseja instalar e, em seguida, clique em **Okey** duas vezes.  
  
6.  Clique em **próximo** nas caixas de diálogo restantes para iniciar a instalação. Instalação notifica você quando a instalação for concluída.  
  
 Quando os drivers são instalados, você pode configurar a fonte de dados usando o administrador ODBC. Você encontrará o ícone ODBC no painel de controle.  
  
## <a name="see-also"></a>Consulte também  
 [Open Database Connectivity (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)   
 [Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)