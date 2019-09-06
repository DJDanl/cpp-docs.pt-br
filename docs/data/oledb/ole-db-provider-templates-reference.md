---
title: Referência dos modelos de provedor de banco de dados OLE
ms.date: 11/04/2016
f1_keywords:
- vc.templates.ole
helpviewer_keywords:
- OLE DB provider templates
ms.assetid: 518358f0-bab1-4de9-bce9-4062cc87c11f
ms.openlocfilehash: 4c89d22cc66937ef9e10636bec79e2cf8b7de43c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311701"
---
# <a name="ole-db-provider-templates-reference"></a>Referência dos modelos de provedor de banco de dados OLE

As classes e interfaces para os modelos de provedor de OLE DB podem ser agrupadas nas categorias a seguir. O material de referência também inclui informações sobre as [macros para modelos de provedor de OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md).

As classes usam a seguinte convenção de nomenclatura: uma classe chamada com o `IWidgetImpl` padrão forneceria uma implementação da interface `IWidget`.

## <a name="session-classes"></a>Classes de sessão

[IDBCreateSessionImpl](../../data/oledb/idbcreatesessionimpl-class.md)<br/>
Cria uma nova sessão do objeto de fonte de dados e retorna a interface solicitada na sessão recém-criada. Interface obrigatória em objetos de fonte de dados.

[ISessionPropertiesImpl](../../data/oledb/isessionpropertiesimpl-class.md)<br/>
Implementa propriedades de sessão chamando uma função estática definida pelo mapa do conjunto de propriedades. O mapa do conjunto de propriedades deve ser especificado na sua classe de sessão. Interface obrigatória em sessões.

## <a name="rowset-classes"></a>Classes de conjunto de linhas

[CRowsetImpl](../../data/oledb/crowsetimpl-class.md)

Fornece uma implementação de conjunto de linhas OLE DB padrão sem exigir várias heranças de muitas interfaces de implementação. O único método para o qual você deve fornecer a `Execute`implementação é.

[CSimpleRow](../../data/oledb/csimplerow-class.md)<br/>
Fornece uma implementação padrão para o identificador de linha, que é usado na `IRowsetImpl` classe. Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl`Cria um novo `CSimpleRow` para cada linha solicitada `IRowsetImpl::GetNextRows`no.

[IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)<br/>
OLE DB requer que os provedores implementem um `HACCESSOR`, que é uma marca para uma matriz de `DBBINDING` estruturas. Fornece `HACCESSOR`s que são endereços `BindType` das estruturas. Obrigatório em conjuntos de linhas e comandos.

[IColumnsInfoImpl](../../data/oledb/icolumnsinfoimpl-class.md)<br/>
Delega a uma função estática definida pelo mapa de coluna do provedor. Interface obrigatória em conjuntos de linhas e comandos.

[IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)<br/>
Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas. Obrigatório em comandos, conjuntos de linhas e conjuntos de linhas de índice. Implementa a `IConvertType` interface delegando para o objeto de conversão fornecido pelo OLE DB.

[IDBSchemaRowsetImpl](../../data/oledb/idbschemarowsetimpl-class.md)<br/>
Implementa a `IDBSchemaRowset` interface e a função `CreateSchemaRowset`de criador modelos.

[IOpenRowsetImpl](../../data/oledb/iopenrowsetimpl-class.md)<br/>
Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. Interface obrigatória para um objeto de sessão.

[IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)<br/>
Implementa a interface OLE DB [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)) , que permite a atualização dos valores das colunas em linhas existentes, a exclusão de linhas e a inserção de novas linhas.

[IRowsetCreatorImpl](../../data/oledb/irowsetcreatorimpl-class.md)<br/>
Essa classe herda de [IObjectWithSite](/windows/win32/api/ocidl/nn-ocidl-iobjectwithsite) e substitui [IObjectWithSite:: SetSite](/windows/win32/api/ocidl/nf-ocidl-iobjectwithsite-setsite). `IRowsetCreatorImpl`executa as mesmas funções que `IObjectWithSite` , mas também habilita as propriedades `DBPROPCANSCROLLBACKWARDS` OLE DB `DBPROPCANFETCHBACKWARDS`e.

[IRowsetIdentityImpl](../../data/oledb/irowsetidentityimpl-class.md)<br/>
Implementa a `IRowsetIdentity` interface, que permite que você compare se duas linhas de dados são idênticas ou não.

[IRowsetImpl](../../data/oledb/irowsetimpl-class.md)<br/>
Fornece uma implementação da `IRowset` interface, que é a interface base do conjunto de linhas.

[IRowsetInfoImpl](../../data/oledb/irowsetinfoimpl-class.md)<br/>
Implementa as propriedades do conjunto de linhas usando o mapa de conjunto de propriedades definido em sua classe de comando. Interface obrigatória em conjuntos de linhas.

[IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)<br/>
Implementa a interface OLE DB [IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85)) , que busca linhas arbitrárias de um conjunto de linhas. Para dar suporte a OLE DB indicadores em um conjunto de linhas, faça com que o conjunto de linhas herde dessa classe.

[IRowsetNotifyCP](../../data/oledb/irowsetnotifycp-class.md)<br/>
Implementa funções de difusão para avisar os ouvintes no ponto `IID_IRowsetNotify` de conexão das alterações para o conteúdo do conjunto de linhas. Os consumidores que manipulam as notificações implementam o [IRowsetNotify](/previous-versions/windows/desktop/ms712959(v=vs.85)) e o registram nesse ponto de conexão.

[IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)<br/>
Implementa a interface OLE DB [IRowsetUpdate](/previous-versions/windows/desktop/ms714401(v=vs.85)) , que permite aos consumidores atrasar a transmissão de alterações feitas com [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)) na fonte de dados e desfazer alterações antes da transmissão.

## <a name="command-classes"></a>Classes de comando

[ICommandImpl](../../data/oledb/icommandimpl-class.md)<br/>
Fornece uma implementação da interface `ICommand`. Essa interface não é visível, mas é manipulada `ICommandTextImpl`pelo. Uma interface obrigatória no objeto Command.

[ICommandPropertiesImpl](../../data/oledb/icommandpropertiesimpl-class.md)<br/>
Essa implementação da `ICommandProperties` interface é fornecida por uma função estática definida `BEGIN_PROPSET_MAP` pela macro. Obrigatórios em comandos.

[ICommandTextImpl](../../data/oledb/icommandtextimpl-class.md)<br/>
Define, armazena e retorna o texto do comando. Obrigatórios em comandos.

[IDBCreateCommandImpl](../../data/oledb/idbcreatecommandimpl-class.md)<br/>
Cria um novo comando a partir do objeto de sessão e retorna a interface solicitada no comando recém-criado. Interface opcional em objetos de sessão.

Outras classes de comando `IColumnsInfoImpl` são `IAccessorImpl`e, descritas na seção classes do conjunto de linhas acima.

## <a name="data-source-classes"></a>Classes de fonte de dados

[IDBInitializeImpl](../../data/oledb/idbinitializeimpl-class.md)<br/>
Cria e exclui a conexão com o consumidor. Interface obrigatória em objetos de fonte de dados e interface opcional em enumeradores.

[IDBPropertiesImpl](../../data/oledb/idbpropertiesimpl-class.md)<br/>
`IDBProperties`é uma interface obrigatória para objetos de fonte de dados e uma interface opcional para enumeradores. No entanto, se um `IDBInitialize`enumerador expõe, `IDBProperties` ele deve expor (Propriedades na fonte de dados).

[IGetDataSourceImpl](../../data/oledb/igetdatasourceimpl-class.md)<br/>
Obtém um ponteiro de interface para o objeto de fonte de dados. Interface obrigatória na sessão.

## <a name="other-classes"></a>Outras classes

[CUtlProps](../../data/oledb/cutlprops-class.md)<br/>
Implementa propriedades para uma variedade de interfaces de propriedade OLE DB (por exemplo `IDBProperties`, `ISessionProperties`, e `IRowsetInfo`).

[IErrorRecordsImpl](../../data/oledb/ierrorrecordsimpl-class.md)

Implementa a interface OLE DB [IErrorRecords](/previous-versions/windows/desktop/ms718112(v=vs.85)) , adicionando registros e recuperando registros de um membro de dados.

## <a name="see-also"></a>Consulte também

[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Modelos do OLE DB](../../data/oledb/ole-db-templates.md)