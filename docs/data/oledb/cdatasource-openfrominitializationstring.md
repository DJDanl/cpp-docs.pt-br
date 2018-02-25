---
title: 'Cdatasource:: Openfrominitializationstring | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDataSource.OpenFromInitializationString
- OpenFromInitializationString
- CDataSource::OpenFromInitializationString
- ATL::CDataSource::OpenFromInitializationString
- ATL.CDataSource.OpenFromInitializationString
dev_langs:
- C++
helpviewer_keywords:
- OpenFromInitializationString method
ms.assetid: 5ef1f1fd-92a9-4e1c-ad80-d3601b094b8c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f05654c9b8647f62d967f97fa4b373471e049cda
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdatasourceopenfrominitializationstring"></a>CDataSource::OpenFromInitializationString
Abre uma fonte de dados especificada pela cadeia de caracteres de inicialização fornecida pelo usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT OpenFromInitializationString(LPCOLESTR szInitializationString,   
   bool fPromptForInfo= false) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *szInitializationString*  
 [in] A cadeia de caracteres de inicialização.  
  
 *fPromptForInfo*  
 [in] Se esse argumento for definido como **true**, em seguida, `OpenFromInitializationString` definirá o **DBPROP_INIT_PROMPT** propriedade para **DBPROMPT_COMPLETEREQUIRED**, que especifica que o usuário seja solicitado somente se forem necessárias mais informações. Isso é útil para situações em que a cadeia de caracteres de inicialização especifica um banco de dados que requer uma senha, mas a cadeia de caracteres não contém a senha. O usuário receberá uma senha (ou qualquer outra informação ausente) ao tentar se conectar ao banco de dados.  
  
 O valor padrão é **false**, que especifica que o usuário nunca solicitado (define **DBPROP_INIT_PROMPT** para **DBPROMPT_NOPROMPT**).  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, inscrição de transação automática e assim por diante.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataSource](../../data/oledb/cdatasource-class.md)