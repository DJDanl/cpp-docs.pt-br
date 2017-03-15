---
title: "Classe IErrorRecordsImpl | Microsoft Docs"
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
  - "ATL::IErrorRecordsImpl"
  - "ATL.IErrorRecordsImpl"
  - "IErrorRecordsImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IErrorRecordsImpl"
ms.assetid: dea8e938-c5d8-45ab-86de-eb8fbf534ffb
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IErrorRecordsImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a interface OLE DB [IErrorRecords](https://msdn.microsoft.com/en-us/library/ms718112.aspx) , adicionando registros e a recuperação de registros de membro de dados \([m\_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)\) do tipo **CAtlArray\<**`RecordClass`**\>**.  
  
## Sintaxe  
  
```  
template <  
   class T,   
   class RecordClass = ATLERRORINFO  
>  
class IErrorRecordsImpl : public IErrorRecords  
```  
  
#### Parâmetros  
 `T`  
 Uma classe derivada de `IErrorRecordsImpl`.  
  
 `RecordClass`  
 Uma classe que representa um objeto de erro OLE DB.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[GetErrorDescriptionString](../../data/oledb/ierrorrecordsimpl-geterrordescriptionstring.md)|Obtém a cadeia de caracteres de descrição de erro de um registro de erro.|  
|[GetErrorGUID](../../data/oledb/ierrorrecordsimpl-geterrorguid.md)|Obtém o erro GUID de um registro de erro.|  
|[GetErrorHelpContext](../../data/oledb/ierrorrecordsimpl-geterrorhelpcontext.md)|Obtém a ID de contexto da ajuda de um registro de erro.|  
|[GetErrorHelpFile](../../data/oledb/ierrorrecordsimpl-geterrorhelpfile.md)|Obtém o nome de caminho completo do arquivo de ajuda de um registro de erro.|  
|[GetErrorSource](../../data/oledb/ierrorrecordsimpl-geterrorsource.md)|Obtém o código de erro de um registro de erro.|  
  
### Métodos da interface  
  
|||  
|-|-|  
|[AddErrorRecord](../Topic/IErrorRecordsImpl::AddErrorRecord.md)|Adiciona um registro ao objeto de erro OLE DB.|  
|[GetBasicErrorInfo](../../data/oledb/cdberrorinfo-getbasicerrorinfo.md)|Retorna informações básicas sobre o erro, como o código de retorno e o número do erro específico do provedor.|  
|[GetCustomErrorObject](../../data/oledb/cdberrorinfo-getcustomerrorobject.md)|Retorna um ponteiro para uma interface em um objeto de erro personalizada.|  
|[GetErrorInfo](../../data/oledb/cdberrorinfo-geterrorinfo.md)|Retorna um ponteiro de interface de [IErrorInfo](https://msdn.microsoft.com/en-us/library/ms718112.aspx) no registro especificado.|  
|[GetErrorParameters](../../data/oledb/cdberrorinfo-geterrorparameters.md)|Retorna os parâmetros de erro.|  
|[GetRecordCount](../Topic/CDaoRecordset::GetRecordCount.md)|Retorna o número de registros no objeto do registro OLE DB.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_rgErrors](../../data/oledb/ierrorrecordsimpl-m-rgerrors.md)|Uma matriz de registros de erro.|  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)