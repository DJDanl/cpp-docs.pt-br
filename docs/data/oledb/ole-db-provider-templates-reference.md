---
title: Referência de modelos de provedor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- vc.templates.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates
ms.assetid: 518358f0-bab1-4de9-bce9-4062cc87c11f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 04ee2d36d269d3bc9324b10dffd8840f9f68a8ab
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220881"
---
# <a name="ole-db-provider-templates-reference"></a>Referência dos modelos de provedor de banco de dados OLE
As classes e interfaces para o OLE DB modelos de provedor podem ser agrupados nas categorias a seguir. O material de referência também inclui informações sobre o [macros para modelos OLE DB Provider](../../data/oledb/macros-for-ole-db-provider-templates.md).  
  
 As classes usam a seguinte convenção de nomenclatura: uma classe chamada com o padrão `IWidgetImpl` forneceria uma implementação da interface `IWidget`.  
  
## <a name="session-classes"></a>Classes de sessão  
 [IDBCreateSessionImpl](../../data/oledb/idbcreatesessionimpl-class.md)  
 Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada a sessão recém-criada. Interface obrigatória em objetos de fonte de dados.  
  
 [ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)  
 Implementa propriedades da sessão, chamando uma função estática definida pelo mapa do conjunto de propriedade. O mapa do conjunto de propriedade deve ser especificado em sua classe de sessão. Interface obrigatória em sessões.  
  
## <a name="rowset-classes"></a>Classes de conjunto de linhas  
 [CRowsetImpl](../../data/oledb/crowsetimpl-class.md)  
  
 Fornece uma implementação padrão do conjunto de linhas OLE DB sem a necessidade de várias heranças de várias interfaces de implementação. O único método para o qual você deve fornecer a implementação é `Execute`.  
  
 [CSimpleRow](../../data/oledb/csimplerow-class.md)  
 Fornece uma implementação padrão para o identificador de linha, que é usado no `IRowsetImpl` classe. Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl` cria um novo `CSimpleRow` para cada linha solicitada em `IRowsetImpl::GetNextRows`.  
  
 [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)  
 OLE DB exige que os provedores implementar uma `HACCESSOR`, que é uma marca para uma matriz de `DBBINDING` estruturas. Fornece `HACCESSOR`s que são endereços do `BindType` estruturas. Obrigatório nos conjuntos de linhas e comandos.  
  
 [IColumnsInfoImpl](../../data/oledb/icolumnsinfoimpl-class.md)  
 Delegados para uma função estática definidos pelo mapa de coluna de provedor. Interface obrigatória nos conjuntos de linhas e comandos.  
  
 [IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)  
 Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas. Obrigatório em comandos, conjuntos de linhas e conjuntos de linhas do índice. Implementa o `IConvertType` interface delegando para o objeto de conversão fornecido pelo OLE DB.  
  
 [IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)  
 Implementa o `IDBSchemaRowset` interface e a função de criador de modelos `CreateSchemaRowset`.  
  
 [IOpenRowsetImpl](../../data/oledb/iopenrowsetimpl-class.md)  
 Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. Interface obrigatória para um objeto de sessão.  
  
 [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)  
 Implementa o OLE DB [IRowsetChange](/previous-versions/windows/desktop/ms715790\(v=vs.85\)) interface, que permite atualização dos valores de colunas em linhas existentes, a exclusão de linhas e inserindo novas linhas.  
  
 [IRowsetCreatorImpl](../../data/oledb/irowsetcreatorimpl-class.md)  
 Essa classe herda de [IObjectWithSite](/windows/desktop/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite::SetSite](/windows/desktop/api/ocidl/nf-ocidl-iobjectwithsite-setsite). `IRowsetCreatorImpl` executa as mesmas funções como `IObjectWithSite` , mas também permite que as propriedades de OLE DB `DBPROPCANSCROLLBACKWARDS` e `DBPROPCANFETCHBACKWARDS`.  
  
 [IRowsetIdentityImpl](../../data/oledb/irowsetidentityimpl-class.md)  
 Implementa o `IRowsetIdentity` interface, que permite comparar se duas linhas de dados são idênticas ou não.  
  
 [IRowsetImpl](../../data/oledb/irowsetimpl-class.md)  
 Fornece uma implementação do `IRowset` interface, que é a interface de conjunto de linhas de base.  
  
 [IRowsetInfoImpl](../../data/oledb/irowsetinfoimpl-class.md)  
 Implementa as propriedades do conjunto de linhas usando a propriedade conjunto definido em sua classe de comando de mapa. Interface obrigatória em conjuntos de linhas.  
  
 [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)  
 Implementa o OLE DB [IRowsetLocate](/previous-versions/windows/desktop/ms721190\(v=vs.85\)) interface, que busca linhas arbitrárias em um conjunto de linhas. Para dar suporte a indicadores de OLE DB em um conjunto de linhas, verifique o conjunto de linhas herdam dessa classe.  
  
 [IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)  
 Implementa funções para informar ouvintes no ponto de conexão de difusão `IID_IRowsetNotify` de alterações no conteúdo do conjunto de linhas. Os consumidores que lidar com notificações implementam [IRowsetNotify](/previous-versions/windows/desktop/ms712959\(v=vs.85\)) e registrá-lo no ponto de conexão.  
  
 [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)  
 Implementa o OLE DB [IRowsetUpdate](/previous-versions/windows/desktop/ms714401\(v=vs.85\)) interface, que permite que os consumidores atrasar a transmissão das alterações feitas com [IRowsetChange](/previous-versions/windows/desktop/ms715790\(v=vs.85\)) para os dados de origem e desfazer as alterações antes da transmissão.  
  
## <a name="command-classes"></a>Classes de comando  
 [ICommandImpl](../../data/oledb/icommandimpl-class.md)  
 Fornece uma implementação da interface `ICommand`. Essa interface não estiver visível, mas é tratada pelo `ICommandTextImpl`. Uma interface obrigatória no objeto de comando.  
  
 [ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)  
 Essa implementação do `ICommandProperties` interface é fornecida por uma função estática definida pelo `BEGIN_PROPSET_MAP` macro. Obrigatório em comandos.  
  
 [ICommandTextImpl](../../data/oledb/icommandtextimpl-class.md)  
 Define, armazena e retorna o texto do comando. Obrigatório em comandos.  
  
 [IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)  
 Cria um novo comando do objeto de sessão e retorna a interface solicitada em um comando recém-criado. Interface opcional em objetos de sessão.  
  
 Outras classes de comando são `IColumnsInfoImpl` e `IAccessorImpl`, descrito na seção de Classes de conjunto de linhas acima.  
  
## <a name="data-source-classes"></a>Classes de fonte de dados  
 [IDBInitializeImpl](../../data/oledb/idbinitializeimpl-class.md)  
 Cria e exclui a conexão com o consumidor. Interface obrigatória em objetos de fonte de dados e interface opcional em enumeradores.  
  
 [IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)  
 `IDBProperties` é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores. No entanto, se expõe um enumerador `IDBInitialize`, ele deve expor `IDBProperties` (propriedades na fonte de dados).  
  
 [IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md)  
 Obtém um ponteiro de interface para o objeto de fonte de dados. Interface obrigatória na sessão.  
  
## <a name="other-classes"></a>Outras Classes  
 [CUtlProps](../../data/oledb/cutlprops-class.md)  
 Implementa as propriedades para uma variedade de interfaces de propriedade do OLE DB (por exemplo, `IDBProperties`, `ISessionProperties`, e `IRowsetInfo`).  
  
 [IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)  
  
 Implementa o OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112\(v=vs.85\)) interface, adicionar registros a e recuperar registros de um membro de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Modelos do OLE DB](../../data/oledb/ole-db-templates.md)