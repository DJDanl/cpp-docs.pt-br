---
title: Criando um provedor atualizável | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, updatable
- notifications, support in providers
- OLE DB providers, creating
ms.assetid: bdfd5c9f-1c6f-4098-822c-dd650e70ab82
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e9ee36d2300ed1e86c1f867012ed54c85692f5bd
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39340632"
---
# <a name="creating-an-updatable-provider"></a>Criando um provedor atualizável

Visual C++ oferece suporte a provedores atualizáveis ou os provedores que podem atualizar (gravar) o repositório de dados. Este tópico discute como criar provedores atualizáveis usando modelos OLE DB.  
  
 Este tópico pressupõe que você está começando com um provedor viável. Há duas etapas para criar um provedor atualizável. Primeiro você deve decidir como o provedor será fazer alterações ao repositório de dados; Especificamente, se as alterações devem ser feito imediatamente ou adiada até que um comando update é emitido. A seção "[tornando provedores atualizáveis](#vchowmakingprovidersupdatable)" descreve as alterações e configurações que você precisa fazer no código do provedor.  
  
 Em seguida, você deve verificar se que seu provedor contém toda a funcionalidade para dar suporte a qualquer coisa que o consumidor pode solicitar dele. Se o consumidor deseja atualizar o armazenamento de dados, o provedor deve conter código que persiste os dados para o armazenamento de dados. Por exemplo, você pode usar a biblioteca de tempo de execução do C ou o MFC para realizar operações em sua fonte de dados. A seção "[escrevendo para a fonte de dados](#vchowwritingtothedatasource)" descreve como gravar na fonte de dados, lidar com valores nulos e padrão e definir sinalizadores de coluna.  
  
> [!NOTE]
>  UpdatePV é um exemplo de um provedor atualizável. UpdatePV é o mesmo que MyProv, mas com suporte atualizável.  
  
##  <a name="vchowmakingprovidersupdatable"></a> Tornando provedores atualizáveis  

 A chave para tornar um provedor atualizável é entender as operações que você deseja que o provedor para executar no armazenamento de dados e como você deseja que o provedor para executar essas operações. Especificamente, o grande problema é se as atualizações para o armazenamento de dados devem ser feito imediatamente ou adiada (agrupados) até que um comando update é emitido.  
  
 Primeiro você deve decidir se deseja herdar `IRowsetChangeImpl` ou `IRowsetUpdateImpl` em sua classe de conjunto de linhas. Dependendo de qual deles você optar por implementar, a funcionalidade dos três métodos será afetada: `SetData`, `InsertRows`, e `DeleteRows`.  
  
- Se você herda de [IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md), esses três métodos de chamada imediatamente altera o armazenamento de dados.  
  
- Se você herda de [IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md), os métodos de adiar as alterações ao repositório de dados até que você chame `Update`, `GetOriginalData`, ou `Undo`. Se a atualização envolver várias alterações, elas são executadas no modo de lote (Observe que o envio em lote de alterações pode adicionar sobrecarga considerável de memória).  
  
 Observe que `IRowsetUpdateImpl` deriva `IRowsetChangeImpl`. Portanto, `IRowsetUpdateImpl` dá a você alterar a funcionalidade além da funcionalidade de lote.  
  
#### <a name="to-support-updatability-in-your-provider"></a>Para dar suporte à capacidade de atualização no provedor  
  
1. Em sua classe de conjunto de linhas, herdam `IRowsetChangeImpl` ou `IRowsetUpdateImpl`. Essas classes fornecem interfaces apropriadas para o armazenamento de dados de alteração:  
  
     **Adicionando IRowsetChange**  
  
     Adicionar `IRowsetChangeImpl` para sua cadeia de herança usando este formato:  
  
    ```cpp  
    IRowsetChangeImpl< rowset-name, storage-name >  
    ```  
  
     Também adicione `COM_INTERFACE_ENTRY(IRowsetChange)` para o `BEGIN_COM_MAP` seção em sua classe de conjunto de linhas.  
  
     **Adicionando IRowsetUpdate**  
  
     Adicionar `IRowsetUpdate` para sua cadeia de herança usando este formato:  
  
    ```cpp  
    IRowsetUpdateImpl< rowset-name, storage>  
    ```  
  
    > [!NOTE]
    >  Você deve remover o `IRowsetChangeImpl` linha de sua cadeia de herança. Essa única exceção à diretiva mencionada anteriormente deve incluir o código para `IRowsetChangeImpl`.  
  
2.  Adicione o seguinte ao seu mapa COM (`BEGIN_COM_MAP ... END_COM_MAP`):  
  
    |Se você implementar|Adicionar ao mapa COM|  
    |----------------------|--------------------|  
    |`IRowsetChangeImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)`|  
    |`IRowsetUpdateImpl`|`COM_INTERFACE_ENTRY(IRowsetChange)COM_INTERFACE_ENTRY(IRowsetUpdate)`|  
  
3.  Em seu comando, adicione o seguinte ao seu mapa de conjunto de propriedade (`BEGIN_PROPSET_MAP ... END_PROPSET_MAP`):  
  
    |Se você implementar|Adicionar ao mapa de conjunto de propriedade|  
    |----------------------|-----------------------------|  
    |`IRowsetChangeImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)`|  
    |`IRowsetUpdateImpl`|`PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)`|  
  
4.  Em seu mapa de conjunto de propriedade, você também deve incluir todas as configurações a seguir conforme elas aparecem abaixo:  
  
    ```cpp  
    PROPERTY_INFO_ENTRY_VALUE(UPDATABILITY, DBPROPVAL_UP_CHANGE |   
      DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE)  
    PROPERTY_INFO_ENTRY_VALUE(CHANGEINSERTEDROWS, VARIANT_TRUE)  
    PROPERTY_INFO_ENTRY_VALUE(IMMOBILEROWS, VARIANT_TRUE)  
  
    PROPERTY_INFO_ENTRY_EX(OWNINSERT, VT_BOOL, DBPROPFLAGS_ROWSET |   
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)  
    PROPERTY_INFO_ENTRY_EX(OWNUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET |   
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)  
    PROPERTY_INFO_ENTRY_EX(OTHERINSERT, VT_BOOL, DBPROPFLAGS_ROWSET |   
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)  
    PROPERTY_INFO_ENTRY_EX(OTHERUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET |   
      DBPROPFLAGS_READ, VARIANT_TRUE, 0)  
    PROPERTY_INFO_ENTRY_EX(REMOVEDELETED, VT_BOOL, DBPROPFLAGS_ROWSET |   
      DBPROPFLAGS_READ, VARIANT_FALSE, 0)  
    ```  
  
     Você pode encontrar os valores usados nessas chamadas de macro examinando Atldb.h para as IDs de propriedade e os valores (se Atldb.h difere da documentação online, Atldb.h substitui a documentação).  
  
    > [!NOTE]
    >  Muitas da `VARIANT_FALSE` e `VARIANT_TRUE` configurações são necessários para os modelos OLE DB; a especificação OLE DB diz que eles podem ser de leitura/gravação, mas os modelos OLE DB só podem oferecer suporte a um valor.  
  
     **Se você implementar IRowsetChangeImpl**  
  
     Se você implementar `IRowsetChangeImpl`, você deve definir as propriedades a seguir no seu provedor. Essas propriedades são usadas principalmente para solicitar interfaces por `ICommandProperties::SetProperties`.  
  
    - `DBPROP_IRowsetChange`: Isso automaticamente definindo conjuntos `DBPROP_IRowsetChange`.  
  
    - `DBPROP_UPDATABILITY`: Um bitmask que especifica os métodos com suporte no `IRowsetChange`: `SetData`, `DeleteRows`, ou `InsertRow`.  
  
    - `DBPROP_CHANGEINSERTEDROWS`: O consumidor pode chamar `IRowsetChange::DeleteRows` ou `SetData` para linhas recentemente inseridas.  
  
    - `DBPROP_IMMOBILEROWS`: O conjunto de linhas não reorganizará as linhas inseridas ou atualizadas.  
  
     **Se você implementar IRowsetUpdateImpl**  
  
     Se você implementar `IRowsetUpdateImpl`, você deve definir as propriedades a seguir no seu provedor, além para definir todas as propriedades para `IRowsetChangeImpl` listados anteriormente:  
  
    - `DBPROP_IRowsetUpdate`.  
  
    - `DBPROP_OWNINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    - `DBPROP_OWNUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    - `DBPROP_OTHERINSERT`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    - `DBPROP_OTHERUPDATEDELETE`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    - `DBPROP_REMOVEDELETED`: Deve ser VARIANT_TRUE e de READ_ONLY.  
  
    - `DBPROP_MAXPENDINGROWS`.  
  
        > [!NOTE]
        >  Se você oferecer suporte a notificações, você também pode ter algumas outras propriedades também; Consulte a seção sobre `IRowsetNotifyCP` para esta lista.  
  
##  <a name="vchowwritingtothedatasource"></a> Escrevendo para a fonte de dados  
 Para ler da fonte de dados, chame o `Execute` função. Para gravar a fonte de dados, chame o `FlushData` função. (Em um sentido geral, liberação meios para salvar as modificações feitas a uma tabela ou índice em disco).  

