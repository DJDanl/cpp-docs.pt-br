---
title: 'Cdatasource:: Openwithservicecomponents | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDataSource::OpenWithServiceComponents
- OpenWithServiceComponents
- CDataSource.OpenWithServiceComponents
dev_langs: C++
helpviewer_keywords: OpenWithServiceComponents method
ms.assetid: 49c1d037-36ae-4fde-8e54-ced623abe1a9
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ce2f96937bfd037cc949142bf357447ac29c0ace
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cdatasourceopenwithservicecomponents"></a>CDataSource::OpenWithServiceComponents
Abre um objeto de fonte de dados usando os componentes de serviço em Oledb32.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      HRESULT OpenWithServiceComponents (  
   const CLSID clsid,  
   DBPROPSET* pPropset = NULL,  
   ULONG ulPropSets = 1   
);  
HRESULT OpenWithServiceComponents (  
   LPCSTR szProgID,  
   DBPROPSET* pPropset = NULL,  
   ULONG ulPropSets = 1   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clsid`  
 [in] O **CLSID** de um provedor de dados.  
  
 `szProgID`  
 [in] ID do programa de um provedor de dados.  
  
 `pPropset`  
 [in] Um ponteiro para uma matriz de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas contendo propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedade](https://msdn.microsoft.com/en-us/library/ms713696.aspx) no *referência do programador de OLE DB* no SDK do Windows. Se o objeto de fonte de dados for inicializado, as propriedades devem pertencer ao grupo de propriedade de fonte de dados. Se a mesma propriedade está especificada mais de uma vez na `pPropset`, e em seguida, o valor que é usado é específica do provedor. Se `ulPropSets` for zero, este parâmetro é ignorado.  
  
 `ulPropSets`  
 [in] O número de [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estruturas passado a *pPropSet* argumento. Se isso for zero, o provedor ignora `pPropset`.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, inscrição de transação automática e assim por diante. Para obter mais informações, consulte "OLE DB Services" na referência do OLE DB do programador em [http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true](http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataSource](../../data/oledb/cdatasource-class.md)