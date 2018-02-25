---
title: CDataSource::OpenFromFileName | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataSource::OpenFromFileName
- ATL::CDataSource::OpenFromFileName
- OpenFromFileName
- CDataSource.OpenFromFileName
- ATL.CDataSource.OpenFromFileName
dev_langs:
- C++
helpviewer_keywords:
- OpenFromFileName method
ms.assetid: c4226de6-59da-4368-9c15-c5afab86f68b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a5ff7df5d0490910a7198fa8a1f2560b98a8570d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdatasourceopenfromfilename"></a>CDataSource::OpenFromFileName
Abre uma fonte de dados de um arquivo especificado pelo nome de arquivo fornecida pelo usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT OpenFromFileName(LPCOLESTR szFileName) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `szFileName`  
 [in] O nome de um arquivo, geralmente uma conexão de fonte de dados (. Arquivo UDL).  
  
 Para obter mais informações sobre arquivos de link de dados (arquivos. udl), consulte [visão geral de API de Link de dados](https://msdn.microsoft.com/en-us/library/ms718102.aspx) no SDK do Windows.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, inscrição de transação automática e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB do programador em [http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true](http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataSource](../../data/oledb/cdatasource-class.md)