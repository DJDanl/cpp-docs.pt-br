---
title: "Referência de modelos de provedor do OLE DB | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.templates.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates
ms.assetid: 518358f0-bab1-4de9-bce9-4062cc87c11f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 68c741f09772c881b42dc4e4cd17de31ed107f8c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ole-db-provider-templates-reference"></a>Referência dos modelos de provedor de banco de dados OLE
As classes e interfaces para os modelos do provedor de banco de dados OLE podem ser agrupadas nas categorias a seguir. O material de referência também inclui informações sobre o [macros para modelos OLE DB Provider](../../data/oledb/macros-for-ole-db-provider-templates.md).  
  
 As classes usam a seguinte convenção de nomenclatura: uma classe chamada com o padrão **IWidgetImpl** deve fornecer uma implementação da interface **IWidget**.  
  
## <a name="session-classes"></a>Classes de sessão  
 [IDBCreateSessionImpl](../../data/oledb/idbcreatesessionimpl-class.md)  
 Cria uma nova sessão do objeto de origem de dados e retorna a interface solicitada a sessão recém-criada. Interface obrigatória em objetos de fonte de dados.  
  
 [ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)  
 Implementa as propriedades de sessão chamando uma função estática definida pela propriedade conjunto de mapa. O mapeamento de conjunto de propriedade deve ser especificado em sua classe de sessão. Interface obrigatória em sessões.  
  
## <a name="rowset-classes"></a>Classes de conjunto de linhas  
 [CRowsetImpl](../../data/oledb/crowsetimpl-class.md)  
  
 Fornece uma implementação padrão do conjunto de linhas OLE DB sem a necessidade de várias heranças de várias interfaces de implementação. O único método para o qual você deve fornecer a implementação é **Execute**.  
  
 [CSimpleRow](../../data/oledb/csimplerow-class.md)  
 Fornece uma implementação padrão para o identificador de linha, que é usado no `IRowsetImpl` classe. Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl` cria um novo `CSimpleRow` para cada linha solicitada em `IRowsetImpl::GetNextRows`.  
  
 [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)  
 OLE DB requer provedores implementar um **HACCESSOR**, que é uma marca para uma matriz de **DBBINDING** estruturas. Fornece **HACCESSOR**que são endereços do **BindType** estruturas. Obrigatório nos conjuntos de linhas e comandos.  
  
 [IColumnsInfoImpl](../../data/oledb/icolumnsinfoimpl-class.md)  
 Delegados para uma função estática definido pelo mapa de coluna do provedor. Interface obrigatória em conjuntos de linhas e comandos.  
  
 [IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)  
 Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas. Obrigatório em comandos, conjuntos de linhas e conjuntos de linhas do índice. Implementa o **IConvertType** interface delegando para o objeto de conversão fornecido pelo OLE DB.  
  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)  
 Implementa o **IDBSchemaRowset** interface e a função de modelo criador `CreateSchemaRowset`.  
  
 [IOpenRowsetImpl](../../data/oledb/iopenrowsetimpl-class.md)  
 Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. Interface obrigatória para um objeto de sessão.  
  
 [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)  
 Implementa o OLE DB [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) interface, que permite atualização dos valores de colunas em linhas existentes, excluindo linhas e inserir novas linhas.  
  
 [IRowsetCreatorImpl](../../data/oledb/irowsetcreatorimpl-class.md)  
 Essa classe herda de [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) e substituições [IObjectWithSite::SetSite](http://msdn.microsoft.com/library/windows/desktop/ms683869). `IRowsetCreatorImpl` executa as mesmas funções `IObjectWithSite` , mas também permite que as propriedades de OLE DB **DBPROPCANSCROLLBACKWARDS** e **DBPROPCANFETCHBACKWARDS**.  
  
 [IRowsetIdentityImpl](../../data/oledb/irowsetidentityimpl-class.md)  
 Implementa o **IRowsetIdentity** interface, que permite comparar se duas linhas de dados são idênticas ou não.  
  
 [IRowsetImpl](../../data/oledb/irowsetimpl-class.md)  
 Fornece uma implementação de `IRowset` interface, que é a interface de conjunto de linhas de base.  
  
 [IRowsetInfoImpl](../../data/oledb/irowsetinfoimpl-class.md)  
 Implementa as propriedades do conjunto de linhas usando a propriedade definida mapa definido em sua classe de comando. Interface obrigatória em conjuntos de linhas.  
  
 [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)  
 Implementa o OLE DB [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) interface, que busca linhas arbitrárias de um conjunto de linhas. Para dar suporte a indicadores de OLE DB em um conjunto de linhas, verifique o conjunto de linhas herdar desta classe.  
  
 [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)  
 Implementa funções para informar ouvintes no ponto de conexão de difusão **IID_IRowsetNotify** de alterações no conteúdo do conjunto de linhas. Os consumidores que tratar notificações implementam [IRowsetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx) e registrá-lo no ponto de conexão.  
  
 [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)  
 Implementa o OLE DB [IRowsetUpdate](https://msdn.microsoft.com/en-us/library/ms714401.aspx) interface, que permite que os consumidores atrasar a transmissão das alterações feitas com [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) para os dados de origem e desfazer as alterações antes da transmissão.  
  
## <a name="command-classes"></a>Classes de comando  
 [ICommandImpl](../../data/oledb/icommandimpl-class.md)  
 Fornece uma implementação da interface `ICommand`. Esta interface não estiver visível, mas é tratada pelo **ICommandTextImpl**. Uma interface obrigatória no objeto de comando.  
  
 [ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)  
 Essa implementação do **ICommandProperties** interface é fornecida por uma função estática definida pelo `BEGIN_PROPSET_MAP` macro. Obrigatório em comandos.  
  
 [ICommandTextImpl](../../data/oledb/icommandtextimpl-class.md)  
 Define, armazena e retorna o texto do comando. Obrigatório em comandos.  
  
 [IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)  
 Cria um novo comando do objeto de sessão e retorna a interface solicitada no comando recém-criado. Interface opcional em objetos de sessão.  
  
 Outras classes de comando são `IColumnsInfoImpl` e `IAccessorImpl`, descrita na seção de Classes de conjunto de linhas acima.  
  
## <a name="data-source-classes"></a>Classes de fonte de dados  
 [IDBInitializeImpl](../../data/oledb/idbinitializeimpl-class.md)  
 Cria e exclui a conexão com o consumidor. Interface obrigatória em objetos de fonte de dados e uma interface opcional em enumeradores.  
  
 [IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)  
 `IDBProperties` é uma interface obrigatória para objetos de fonte de dados e uma interface opcional de enumeradores. No entanto, se expõe um enumerador **IDBInitialize**, ele deve expor `IDBProperties` (propriedades na fonte de dados).  
  
 [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md)  
 Obtém um ponteiro de interface para o objeto de fonte de dados. Interface obrigatória na sessão.  
  
## <a name="other-classes"></a>Outras Classes  
 [CUtlProps](../../data/oledb/cutlprops-class.md)  
 Implementa propriedades para uma variedade de interfaces de propriedade do banco de dados OLE (por exemplo, `IDBProperties`, **ISessionProperties**, e `IRowsetInfo`).  
  
 [IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)  
  
 Implementa o OLE DB [IErrorRecords](https://msdn.microsoft.com/en-us/library/ms718112.aspx) interface, adicionando registros e recuperar os registros de um membro de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Modelos do OLE DB](../../data/oledb/ole-db-templates.md)