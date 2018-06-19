---
title: Macros e funções globais para modelos de consumidor OLE DB | Microsoft Docs
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
- OLE DB consumer templates, macros
- macros, OLE DB consumer template
ms.assetid: 8765eb7b-32dd-407c-bacf-8890ef959837
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 57f61dd54855a2cf0196c0e269eda92295c818b9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33114309"
---
# <a name="macros-and-global-functions-for-ole-db-consumer-templates"></a>Macros e funções globais para modelos de consumidor de banco de dados OLE
O OLE DB modelos de consumidor incluem as seguintes macros e funções globais:  
  
### <a name="global-functions"></a>Funções globais  
  
|||  
|-|-|  
|[AtlTraceErrorRecords](../../data/oledb/atltraceerrorrecords.md)|OLE DB erro informações de registro para o dispositivo de despejo de despejos de memória se um erro será retornado.|  
  
### <a name="accessor-map-macros"></a>Macros de mapa do acessador  
  
|||  
|-|-|  
|[BEGIN_ACCESSOR](../../data/oledb/begin-accessor.md)|Marca o início de uma entrada de acessador.|  
|[BEGIN_ACCESSOR_MAP](../../data/oledb/begin-accessor-map.md)|Marca o início das entradas do mapa de acessador.|  
|[END_ACCESSOR](../../data/oledb/end-accessor.md)|Marca o final de uma entrada de acessador.|  
|[END_ACCESSOR_MAP](../../data/oledb/end-accessor-map.md)|Marca o fim das entradas de mapa de acessador.|  
  
### <a name="column-map-macros"></a>Macros de mapa de coluna  
  
|||  
|-|-|  
|[BEGIN_COLUMN_MAP](../../data/oledb/begin-column-map.md)|Marca o início das entradas do mapa de coluna na classe de registro de usuário.|  
|[BLOB_ENTRY](../../data/oledb/blob-entry.md)|Usado para associar um objeto binário grande (BLOB).|  
|[BLOB_ENTRY_LENGTH](../../data/oledb/blob-entry-length.md)|Informa o comprimento da coluna de dados BLOB.|  
|[BLOB_ENTRY_LENGTH_STATUS](../../data/oledb/blob-entry-length-status.md)|Informa o comprimento e o status da coluna de dados BLOB.|  
|[BLOB_ENTRY_STATUS](../../data/oledb/blob-entry-status.md)|Relata o status da coluna de dados BLOB.|  
|[BLOB_NAME](../../data/oledb/blob-name.md)|Usado para associar um objeto binário grande pelo nome da coluna.|  
|[BLOB_NAME_LENGTH](../../data/oledb/blob-name-length.md)|Informa o comprimento da coluna de dados BLOB.|  
|[BLOB_NAME_LENGTH_STATUS](../../data/oledb/blob-name-length-status.md)|Informa o comprimento e o status da coluna de dados BLOB.|  
|[BLOB_NAME_STATUS](../../data/oledb/blob-name-status.md)|Relata o status da coluna de dados BLOB.|  
|[BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md)|Representa uma entrada de indicador no conjunto de linhas. Uma entrada de indicador é um tipo especial de entrada da coluna.|  
|[COLUMN_ENTRY](../../data/oledb/column-entry.md)|Representa uma associação a uma coluna específica no banco de dados.|  
|[COLUMN_ENTRY_EX](../../data/oledb/column-entry-ex.md)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a `type`, *comprimento*, *precisão*, `scale`, e *status* parâmetros.|  
|[COLUMN_ENTRY_LENGTH](../../data/oledb/column-entry-length.md)|Representa uma associação para a coluna específica no banco de dados. Oferece suporte a *comprimento* variável.|  
|[COLUMN_ENTRY_LENGTH_STATUS](../../data/oledb/column-entry-length-status.md)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *status* e *comprimento* parâmetros.|  
|[COLUMN_ENTRY_PS](../../data/oledb/column-entry-ps.md)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *precisão* e `scale` parâmetros.|  
|[COLUMN_ENTRY_PS_LENGTH](../../data/oledb/column-entry-ps-length.md)|Representa uma associação para a coluna específica no banco de dados. Oferece suporte a *comprimento* variável, *precisão* e `scale` parâmetros.|  
|[COLUMN_ENTRY_PS_LENGTH_STATUS](../../data/oledb/column-entry-ps-length-status.md)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a *status* e *comprimento* variáveis, *precisão* e `scale` parâmetros.|  
|[COLUMN_ENTRY_PS_STATUS](../../data/oledb/column-entry-ps-status.md)|Representa uma associação para a coluna específica no banco de dados. Oferece suporte a *status* variável, *precisão* e `scale` parâmetros.|  
|[COLUMN_ENTRY_STATUS](../../data/oledb/column-entry-status.md)|Representa uma associação para a coluna específica no banco de dados. Oferece suporte a *status* variável.|  
|[COLUMN_ENTRY_TYPE](../../data/oledb/column-entry-type.md)|Representa uma associação a uma coluna específica no banco de dados. Dá suporte a `type` parâmetro.|  
|[COLUMN_ENTRY_TYPE_SIZE](../../data/oledb/column-entry-type-size.md)|Representa uma associação para a coluna específica no banco de dados. Dá suporte a `type` e `size` parâmetros.|  
|[COLUMN_NAME](../../data/oledb/column-name.md)|Representa uma associação a uma coluna específica no banco de dados por nome.|  
|[COLUMN_NAME_EX](../../data/oledb/column-name-ex.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados, tamanho, precisão, escala, comprimento de coluna e status da coluna.|  
|[COLUMN_NAME_LENGTH](../../data/oledb/column-name-length.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de comprimento da coluna.|  
|[COLUMN_NAME_LENGTH_STATUS](../../data/oledb/column-name-length-status.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de comprimento de coluna e status.|  
|[COLUMN_NAME_PS](../../data/oledb/column-name-ps.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão e escala.|  
|[COLUMN_NAME_PS_LENGTH](../../data/oledb/column-name-ps-length.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de comprimento de precisão, escala e coluna.|  
|[COLUMN_NAME_PS_LENGTH_STATUS](../../data/oledb/column-name-ps-length-status.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão, escala, comprimento de coluna e status da coluna.|  
|[COLUMN_NAME_PS_STATUS](../../data/oledb/column-name-ps-status.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de precisão, escala e coluna status.|  
|[COLUMN_NAME_STATUS](../../data/oledb/column-name-status.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de status da coluna.|  
|[COLUMN_NAME_TYPE](../../data/oledb/column-name-type.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados.|  
|[COLUMN_NAME_TYPE_PS](../../data/oledb/column-name-type-ps.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados, precisão e escala.|  
|[COLUMN_NAME_TYPE_SIZE](../../data/oledb/column-name-type-size.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de tipo de dados e tamanho.|  
|[COLUMN_NAME_TYPE_STATUS](../../data/oledb/column-name-type-status.md)|Representa uma associação a uma coluna específica no banco de dados por nome. Oferece suporte à especificação de status de coluna e de tipo de dados.|  
|[END_COLUMN_MAP](../../data/oledb/end-column-map.md)|Marca o fim das entradas de mapa de coluna.|  
  
### <a name="command-macros"></a>Macros de comando  
  
|||  
|-|-|  
|[DEFINE_COMMAND](../../data/oledb/define-command.md)|Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Aceita somente os tipos de cadeia de caracteres correspondente ao tipo de aplicativo especificado (ANSI ou Unicode). É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`.|  
|[DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md)|Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Oferece suporte a aplicativos ANSI e Unicode.|  
  
### <a name="parameter-map-macros"></a>Macros de mapa de parâmetro  
  
|||  
|-|-|  
|[BEGIN_PARAM_MAP](../../data/oledb/begin-param-map.md)|Marca o início das entradas do mapa de parâmetro na classe de registro de usuário.|  
|[END_PARAM_MAP](../../data/oledb/end-param-map.md)|Marca o fim das entradas de mapa de parâmetro.|  
|[SET_PARAM_TYPE](../../data/oledb/set-param-type.md)|Especifica `COLUMN_ENTRY` macros que seguem o `SET_PARAM_TYPE` macro como entrada, saída ou entrada/saída.|  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)