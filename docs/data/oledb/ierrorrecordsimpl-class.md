---
title: Classe IErrorRecordsImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IErrorRecordsImpl
- ATL.IErrorRecordsImpl
- IErrorRecordsImpl
dev_langs:
- C++
helpviewer_keywords:
- IErrorRecordsImpl class
ms.assetid: dea8e938-c5d8-45ab-86de-eb8fbf534ffb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0d0425e7765cf09abb870cb39720cf43c8c74174
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33105459"
---
# <a name="ierrorrecordsimpl-class"></a>Classe IErrorRecordsImpl
Implementa o OLE DB [IErrorRecords](https://msdn.microsoft.com/en-us/library/ms718112.aspx) interface, adicionando registros e recuperar os registros de um membro de dados ([m_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)) do tipo **CAtlArray <** `RecordClass`**>**.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class RecordClass = ATLERRORINFO>  
class IErrorRecordsImpl : public IErrorRecords  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de `IErrorRecordsImpl`.  
  
 `RecordClass`  
 Uma classe que representa um objeto de erro OLE DB.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetErrorDescriptionString](../../data/oledb/ierrorrecordsimpl-geterrordescriptionstring.md)|Obtém a cadeia de caracteres de descrição de erro de um registro de erro.|  
|[GetErrorGUID](../../data/oledb/ierrorrecordsimpl-geterrorguid.md)|Obtém o GUID de erro de um registro de erro.|  
|[GetErrorHelpContext](../../data/oledb/ierrorrecordsimpl-geterrorhelpcontext.md)|Obtém a ID do contexto de ajuda de um registro de erro.|  
|[GetErrorHelpFile](../../data/oledb/ierrorrecordsimpl-geterrorhelpfile.md)|Obtém o nome do caminho completo do arquivo de ajuda de um registro de erro.|  
|[GetErrorSource](../../data/oledb/ierrorrecordsimpl-geterrorsource.md)|Obtém o código de erro de um registro de erro.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[AddErrorRecord](../../data/oledb/ierrorrecordsimpl-adderrorrecord.md)|Adiciona um registro para o objeto de erro OLE DB.|  
|[GetBasicErrorInfo](../../data/oledb/cdberrorinfo-getbasicerrorinfo.md)|Retorna informações básicas sobre o erro, como o código de retorno e o número do erro específico do provedor.|  
|[GetCustomErrorObject](../../data/oledb/cdberrorinfo-getcustomerrorobject.md)|Retorna um ponteiro para uma interface em um objeto de erro personalizada.|  
|[GetErrorInfo](../../data/oledb/cdberrorinfo-geterrorinfo.md)|Retorna um [IErrorInfo](https://msdn.microsoft.com/en-us/library/ms718112.aspx) ponteiro de interface do registro especificado.|  
|[GetErrorParameters](../../data/oledb/cdberrorinfo-geterrorparameters.md)|Retorna os parâmetros de erro.|  
|[GetRecordCount](../../mfc/reference/cdaorecordset-class.md#getrecordcount)|Retorna o número de registros no objeto de registro de OLE DB.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)|Uma matriz de registros de erro.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)