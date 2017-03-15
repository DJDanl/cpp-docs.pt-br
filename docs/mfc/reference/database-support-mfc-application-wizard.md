---
title: Suporte, o Assistente de aplicativo MFC de banco de dados | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.exe.database
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, database support
ms.assetid: 9ddf4558-fd41-4ac7-8d9b-c93d9c68ab59
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e1db5b12954f72936a14c173716a123bbd3e90a8
ms.lasthandoff: 02/25/2017

---
# <a name="database-support-mfc-application-wizard"></a>Suporte ao banco de dados, Assistente de Aplicativo MFC
Esta página fornece opções que permitem que você especifique o nível de banco de dados de suporte (mais de uma fonte de dados, se necessário) para seu projeto.  
  
 **Suporte de banco de dados**  
 Define o nível de suporte de banco de dados para seu projeto.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Nenhum**|Não fornece suporte de nenhum banco de dados. Esta é a opção padrão.|  
|**Somente os arquivos de cabeçalho**|Fornece o nível básico de suporte de banco de dados para seu aplicativo. Se você selecionar o suporte a ODBC em **tipo de cliente**, o Assistente para aplicativo do MFC inclui em seu projeto, o arquivo de cabeçalho AFXDB. H. Ele adiciona as bibliotecas de vínculo, mas não cria as classes de banco de dados específico. Você pode criar conjuntos de registros posteriormente e usá-los para examinar e atualizar registros. Se você selecionar o suporte de OLE DB em **tipo de cliente**, os arquivos de cabeçalho a seguir estão incluídos: ATLBASE. AFXOLEDB H. ATLPLUS H. H|  
|**Exibição de banco de dados sem suporte de arquivo**|Inclui arquivos de cabeçalho do banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada a [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página.) Essa opção inclui suporte a documentos, mas não há suporte para serialização. Se você optar por incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.|  
|**Exibição de banco de dados com suporte a arquivos**|Inclui arquivos de cabeçalho do banco de dados, bibliotecas de vínculo, uma exibição de registro e um conjunto de registros. (Disponível somente para aplicativos com o **suporte para a arquitetura de documento/exibição** opção selecionada a **tipo de aplicativo** página.) Essa opção oferece suporte à serialização de documento, que você pode usar, por exemplo, para atualizar um arquivo de perfil do usuário. Aplicativos de banco de dados geralmente operam em uma base por registro, em vez de em cada arquivo base e, portanto não é necessário serialização. No entanto, você pode ter um uso especial para serialização. Se você optar por incluir um modo de exibição de banco de dados, você deve especificar a fonte de dados.|  
  
> [!NOTE]
>  Em **suporte de banco de dados**, se você selecionar uma **exibição sem suporte a arquivos de banco de dados** ou **exibição com suporte a arquivos de banco de dados**, a derivação de classe de exibição for diferente, dependendo da sua **tipo de cliente** seleção, da seguinte maneira:  
  
-   Se você selecionar **ODBC** em **tipo de cliente**, em seguida, deriva de classe de exibição do aplicativo [CRecordView](../../mfc/reference/crecordview-class.md). Essa classe é associada com um [CRecordset](../../mfc/reference/crecordset-class.md)-derivado da classe, que o Assistente para aplicativo do MFC também cria para você. Essa opção fornece um aplicativo baseado em formulário em que o modo de exibição de registro é usado para exibir e atualizar registros por meio de seu conjunto de registros.  
  
-   Se você selecionar **OLE DB** em **tipo de cliente**, em seguida, a classe de exibição deriva de [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), e ele está associado um [CTable](../../data/oledb/ctable-class.md) ou [CCommand](../../data/oledb/ccommand-class.md)-classe derivada.  
  
 **Tipo de cliente**  
 Indica se o seu projeto usa classes OLE DB ou ODBC.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**OLE DB**|Quando essa opção é selecionada, clicar no **fonte de dados** botão chama o **propriedades de vínculo de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados OLE DB.|  
|**ODBC**|Quando essa opção é selecionada, clicar no **fonte de dados** botão chama o **Selecionar fonte de dados** Assistente para ajudá-lo a criar uma conexão a uma fonte de dados ODBC.|  
  
 **Fonte de dados**  
 Clique o **fonte de dados** botão para configurar uma fonte de dados usando o driver especificado ou o provedor e o banco de dados. Se você selecionou o OLE DB no **tipo de cliente** este botão de opção, exibe o **propriedades de vínculo de dados** caixa de diálogo. Se você selecionou o ODBC no **tipo de cliente** opção, esse botão fornece o **Selecionar fonte de dados** caixa de diálogo. Essa opção está disponível somente se você optar por incluir um modo de exibição de banco de dados em seu aplicativo.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Propriedades de vínculo de dados** (OLE DB)|Estabelece a fonte de dados especificado usando o provedor OLE DB especificado. Você deve especificar o provedor OLE DB, o local dos dados, a fonte de dados, ID de logon e (opcionalmente) uma senha. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).|  
|**Selecionar fonte de dados** (ODBC)|Estabelece a fonte de dados especificado usando o driver ODBC especificado. Você deve selecionar um nome de fonte de dados para escolher uma tabela da fonte de dados. O assistente vincula todas as colunas da tabela para as variáveis de membro de um `CRecordset`-classe derivada. Para obter detalhes sobre essa caixa de diálogo, consulte **fonte de dados** na [Assistente de consumidor ODBC MFC](../../mfc/reference/mfc-odbc-consumer-wizard.md).|  
  
> [!NOTE]
>  Em versões anteriores, Shift + clique o **fonte de dados** botão Abrir uma caixa de diálogo Abrir arquivo para permitir que você selecione um arquivo de vínculo de dados (. udl). Não há suporte para essa funcionalidade.  
  
 **Gerar a classe de banco de dados atribuído**  
 Disponível para somente cliente OLE DB. Especifica se as classes de banco de dados no projeto gerado usam atributos.  
  
 **Associar todas as colunas**  
 Disponível para somente cliente ODBC. Especifica se todas as colunas na tabela selecionada estão vinculadas. Se você selecionar esta caixa, todas as colunas são vinculadas; Se você não selecionar essa caixa, não há colunas associadas e você deve associá-las manualmente na classe de conjunto de registros.  
  
 **Tipo**  
 Disponível para somente cliente ODBC. Especifica se o conjunto de registros é um dynaset ou um instantâneo, conforme descrito na tabela a seguir.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Dynaset**|Especifica que o conjunto de registros é um dynaset. Dynaset é o resultado de uma consulta que fornece uma exibição indexada em dados do banco de dados consultados. Dynaset armazena em cache apenas um índice integral para os dados originais e, portanto, oferece um desempenho obter um instantâneo. Os pontos de índice diretamente a cada registro encontrado como resultado de uma consulta e indica se um registro for removido. Você também tem acesso a informações atualizadas nos registros consultados.|  
|Instantâneo|Especifica que o conjunto de registros é um instantâneo. Um instantâneo é o resultado de uma consulta e é uma exibição de um banco de dados em um ponto no tempo. Todos os registros em virtude da consulta são armazenados em cache, para que você não veja todas as alterações nos registros originais.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md)

