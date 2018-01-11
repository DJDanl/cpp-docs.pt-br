---
title: Assistente de aplicativo MFC, o suporte do banco de dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.mfc.exe.database
dev_langs: C++
helpviewer_keywords: MFC Application Wizard, database support
ms.assetid: 9ddf4558-fd41-4ac7-8d9b-c93d9c68ab59
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7b7c9aaa6389f5e86a51348a8b5423260c4c76e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="database-support-mfc-application-wizard"></a>Suporte ao banco de dados, Assistente de Aplicativo MFC
Esta página fornece opções que permitem que você especifique o nível de banco de dados de suporte (mais de uma fonte de dados, se necessário) para seu projeto.  
  
 **Suporte de banco de dados**  
 Define o nível de suporte de banco de dados para seu projeto.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Não fornece suporte nenhum banco de dados. Esta é a opção padrão.|  
|**Somente os arquivos de cabeçalho**|Fornece o nível básico de suporte de banco de dados para seu aplicativo. Se você selecionar o suporte a ODBC em **tipo de cliente**, o Assistente de aplicativo MFC inclui em seu projeto, o arquivo de cabeçalho AFXDB. H. Ele adiciona bibliotecas de vínculo, mas não cria todas as classes específicas de banco de dados. Você pode criar conjuntos de registros mais tarde e usá-los para examinar e atualizar registros. Se você selecionar o suporte de OLE DB em **tipo de cliente**, os arquivos de cabeçalho a seguir estão incluídos: ATLBASE. AFXOLEDB H. ATLPLUS H. H|  
|**Exibição de banco de dados sem suporte para arquivo**|Inclui os arquivos de cabeçalho de banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada a [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página.) Essa opção inclui o suporte do documento, mas não há suporte de serialização. Se você optar por incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.|  
|**Exibição de banco de dados com suporte para arquivo**|Inclui os arquivos de cabeçalho de banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada a **tipo de aplicativo** página.) Essa opção oferece suporte a serialização de documento, que você pode usar, por exemplo, para atualizar um arquivo de perfil de usuário. Aplicativos de banco de dados geralmente operam em uma base por registro em vez de por arquivo base e, portanto não precisa de serialização. No entanto, você pode ter um uso especial para serialização. Se você optar por incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.|  
  
> [!NOTE]
>  Em **suporte do banco de dados**, se você selecionar uma **exibição sem suporte para arquivo de banco de dados** ou **exibição com suporte a arquivos de banco de dados**, a derivação de classe de exibição for diferente, dependendo da em seu **tipo de cliente** seleção, da seguinte maneira:  
  
-   Se você selecionar **ODBC** em **tipo de cliente**, em seguida, deriva de classe de exibição do aplicativo [CRecordView](../../mfc/reference/crecordview-class.md). Essa classe é associada com um [CRecordset](../../mfc/reference/crecordset-class.md)-derivada da classe que o Assistente de aplicativo MFC também cria para você. Essa opção fornece um aplicativo baseado em formulário no qual a exibição de registro é usada para exibir e atualizar registros por meio de seu conjunto de registros.  
  
-   Se você selecionar **OLE DB** em **tipo de cliente**, em seguida, a exibição de classe derivada de [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), e ele está associado um [CTable](../../data/oledb/ctable-class.md) ou [CCommand](../../data/oledb/ccommand-class.md)-classe derivada.  
  
 **Tipo de cliente**  
 Indica se o seu projeto usa as classes de OLE DB ou ODBC.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**OLE DB**|Quando essa opção é selecionada, clicar no **fonte de dados** botão invoca o **propriedades de vínculo de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados OLE DB.|  
|**ODBC**|Quando essa opção é selecionada, clicar no **fonte de dados** botão invoca o **Selecionar fonte de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados ODBC.|  
  
 **Fonte de dados**  
 Clique o **fonte de dados** botão para configurar uma fonte de dados usando o driver especificado ou o provedor e o banco de dados. Se você selecionou OLE DB no **tipo de cliente** este botão de opção, exibe o **propriedades de vínculo de dados** caixa de diálogo. Se você selecionou o ODBC no **tipo de cliente** opção, esse botão fornece o **Selecionar fonte de dados** caixa de diálogo. Essa opção estará disponível somente se você optar por incluir um modo de exibição de banco de dados em seu aplicativo.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Propriedades de vínculo de dados** (OLE DB)|Estabelece a fonte de dados especificado usando o provedor OLE DB especificado. Você deve especificar o provedor OLE DB, o local dos dados, a fonte de dados, ID de logon e (opcionalmente) uma senha. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).|  
|**Selecione a fonte de dados** (ODBC)|Estabelece a fonte de dados especificado usando o driver ODBC especificado. Você deve selecionar um nome de fonte de dados para escolher uma tabela da fonte de dados. O assistente vincula todas as colunas da tabela para as variáveis de membro de um `CRecordset`-classe derivada. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [Assistente de consumidor ODBC MFC](../../mfc/reference/mfc-odbc-consumer-wizard.md).|  
  
> [!NOTE]
>  Em versões anteriores, Shift + clique o **fonte de dados** botão Abrir uma caixa de diálogo Abrir arquivo para permitir que você selecione um arquivo de vínculo de dados (. udl). Não há suporte para essa funcionalidade.  
  
 **Gerar a classe de banco de dados atribuído**  
 Disponível para somente cliente OLE DB. Especifica se as classes de banco de dados no projeto gerado usam atributos.  
  
 **Associar todas as colunas**  
 Disponível para somente cliente ODBC. Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar essa caixa, todas as colunas são vinculadas; Se você não selecionar essa caixa, não há colunas associadas e você deve associá-las manualmente na classe de conjunto de registros.  
  
 **Tipo**  
 Disponível para somente cliente ODBC. Especifica se o conjunto de registros é um dynaset ou um instantâneo, conforme descrito na tabela a seguir.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Dynaset**|Especifica que o conjunto de registros é dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache somente um índice integral aos dados originais e, portanto, oferece um desempenho obter um instantâneo. Os pontos de índice diretamente a cada registro encontrado como resultado de uma consulta e indica se um registro é removido. Você também tem acesso a informações atualizadas nos registros de consultado.|  
|Instantâneo|Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é um modo de exibição em um banco de dados em um ponto no tempo. Todos os registros em virtude da consulta são armazenados em cache, para que você não veja todas as alterações nos registros originais.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)
