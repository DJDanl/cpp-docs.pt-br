---
title: "Refer&#234;ncia dos modelos de provedor de banco de dados OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.templates.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "modelos de provedor do OLE DB"
ms.assetid: 518358f0-bab1-4de9-bce9-4062cc87c11f
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncia dos modelos de provedor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes e interfaces para os modelos do provedor OLE DB podem ser agrupadas nas categorias a seguir.  Material de referência também inclui informações sobre [macros para modelos do provedor OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md).  
  
 As classes use a seguinte convenção de nomenclatura: uma classe nomeada com o padrão **IWidgetImpl** ofereceria uma implementação da interface **IWidget**.  
  
## Classes de sessão  
 [IDBCreateSessionImpl](../../data/oledb/idbcreatesessionimpl-class.md)  
 Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada na sessão recém\-criada.  Interface obrigatória em objetos de fonte de dados.  
  
 [ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)  
 Propriedades da sessão das ferramentas chamando uma função estática definida pelo conjunto de propriedades.  O mapa do conjunto de propriedades deve ser especificado em sua classe da sessão.  Interface obrigatória em sessões.  
  
## Classes do conjunto de linhas  
 [CRowsetImpl](../../data/oledb/crowsetimpl-class.md)  
  
 Fornece uma implementação padrão de conjunto de linhas OLE DB sem exigir a herança múltipla das interfaces de implementação.  O único método para o qual você deve fornecer uma implementação é **Executar**.  
  
 [CSimpleRow](../Topic/CSimpleRow%20Class.md)  
 Fornece uma implementação padrão para a alça da linha, que é usada na classe de `IRowsetImpl` .  Um identificador de linha é logicamente uma marca exclusivo de uma linha do resultado.  `IRowsetImpl` cria uma nova `CSimpleRow` para cada linha solicitada em `IRowsetImpl::GetNextRows`.  
  
 [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)  
 Provedores OLE DB requer implementar **HACCESSOR**, que é uma marca a uma matriz de estruturas de **DBBINDING** .  Fornece **HACCESSOR**s que é endereços de estruturas de **BindType** .  Obrigatório em conjuntos de linhas e em comandos.  
  
 [IColumnsInfoImpl](../../data/oledb/icolumnsinfoimpl-class.md)  
 Delega a uma função estática definida pelo mapa da coluna do provedor.  Interface obrigatória em conjuntos de linhas e em comandos.  
  
 [IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)  
 Fornece informações sobre a disponibilidade conversões de tipo em um comando ou em um conjunto de linhas.  Obrigatório em comandos, em conjuntos de linhas, e em conjuntos de linhas do índice.  Implementa a interface de **IConvertType** delegando a conversão o objeto fornecido pelo OLE DB.  
  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)  
 Implementa a interface de **IDBSchemaRowset** e a função templatized `CreateSchemaRowset`do designer.  
  
 [IOpenRowsetImpl](../../data/oledb/iopenrowsetimpl-class.md)  
 Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela ou índice base.  Interface obrigatória para um objeto de sessão.  
  
 [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)  
 Implementa a interface OLE DB [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) , o que permite atualizar os valores das colunas nas linhas existentes, excluindo linhas, e ao inserir novas linhas.  
  
 [IRowsetCreatorImpl](../Topic/IRowsetCreatorImpl%20Class.md)  
 Esta classe é herdada de [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) e substitui [IObjectWithSite::SetSite](http://msdn.microsoft.com/library/windows/desktop/ms683869).  `IRowsetCreatorImpl` executa as mesmas funções que `IObjectWithSite` mas também permite que as propriedades **DBPROPCANSCROLLBACKWARDS** e **DBPROPCANFETCHBACKWARDS**OLE DB.  
  
 [IRowsetIdentityImpl](../Topic/IRowsetIdentityImpl%20Class.md)  
 Implementa a interface de **IRowsetIdentity** , o que permite comparar se duas linhas de dados são idênticas ou não.  
  
 [IRowsetImpl](../Topic/IRowsetImpl%20Class.md)  
 Fornece uma implementação da interface de `IRowset` , que é a interface base do conjunto de linhas.  
  
 [IRowsetInfoImpl](../Topic/IRowsetInfoImpl%20Class.md)  
 Implementa as propriedades do conjunto de linhas usando o mapa do conjunto de propriedades definido na sua classe de comando.  Interface obrigatória em conjuntos de linhas.  
  
 [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)  
 Implementa a interface OLE DB [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) , que busca linhas arbitrárias de um conjunto de linhas.  Para oferecer suporte a indicadores do OLE DB em um conjunto de linhas, faça o conjunto de linhas herdar dessa classe.  
  
 [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)  
 O implementa passam funções para recomendar ouvintes no ponto de conexão **IID\_IRowsetNotify** as alterações para o conteúdo do conjunto de linhas.  Os consumidores que manipulam notificações implementam [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx) e registrá\-lo no ponto de conexão.  
  
 [IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md)  
 Implementa a interface OLE DB [IRowsetUpdate](https://msdn.microsoft.com/en-us/library/ms714401.aspx) , que permite que os consumidores para reter a transmissão das alterações feitas com [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) à fonte de dados e para desfazer alterações antes de transmissão.  
  
## Classes de comando  
 [ICommandImpl](../Topic/ICommandImpl%20Class.md)  
 Fornece uma implementação da interface de `ICommand` .  Essa interface não estiver visível, mas é controlada por **ICommandTextImpl**.  Uma interface obrigatória no objeto de comando.  
  
 [ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)  
 Essa implementação da interface de **ICommandProperties** é fornecida por uma função estática definida pela macro de `BEGIN_PROPSET_MAP` .  Obrigatório em comandos.  
  
 [ICommandTextImpl](../../data/oledb/icommandtextimpl-class.md)  
 Conjuntos, o armazena, e retorna o texto do comando.  Obrigatório em comandos.  
  
 [IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)  
 Cria um novo comando de objeto de sessão e retorna a interface solicitada no comando recém\-criado.  Interface opcional em objetos de sessão.  
  
 Outras classes de comando são `IColumnsInfoImpl` e `IAccessorImpl`, descritos na seção de classes do conjunto de linhas precedentes.  
  
## Classes da fonte de dados  
 [IDBInitializeImpl](../Topic/IDBInitializeImpl%20Class.md)  
 Cria e exclui a conexão com o consumidor.  Interface obrigatória em objetos de fonte de dados e interface opcional em enumeradores.  
  
 [IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)  
 `IDBProperties` é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores.  No entanto, se expõe um enumerador **IDBInitialize**, deve expor `IDBProperties` \(propriedades na fonte de dados\).  
  
 [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md)  
 Obtém um ponteiro de interface do objeto de fonte de dados.  Interface obrigatória na sessão.  
  
## Outras classes  
 [CUtlProps](../../data/oledb/cutlprops-class.md)  
 As propriedades das ferramentas para uma variedade de propriedade OLE DB interface \(por exemplo, `IDBProperties`, **ISessionProperties**, e `IRowsetInfo`\).  
  
 [IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)  
  
 Implementa a interface OLE DB [IErrorRecords](https://msdn.microsoft.com/en-us/library/ms718112.aspx) , adicionando registros e a recuperação de registros de membro de dados.  
  
## Consulte também  
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Modelos de banco de dados OLE](../Topic/OLE%20DB%20Templates.md)