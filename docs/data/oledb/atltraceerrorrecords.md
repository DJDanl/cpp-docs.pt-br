---
title: AtlTraceErrorRecords | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.AtlTraceErrorRecords
- ATL::AtlTraceErrorRecords
- AtlTraceErrorRecords
dev_langs: C++
helpviewer_keywords: AtlTraceErrorRecords function
ms.assetid: b83970b3-dc2a-445c-9142-f52218719905
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4a3f8542f2c897f45916ac62fbac147259b2362d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atltraceerrorrecords"></a>AtlTraceErrorRecords
OLE DB erro informações de registro para o dispositivo de despejo de despejos de memória se um erro será retornado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      inline void AtlTraceErrorRecords(   
   HRESULT hrErr = S_OK    
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hErr`  
 [in] Um `HRESULT` retornado por uma função de membro de OLE DB modelo de consumidor.  
  
## <a name="remarks"></a>Comentários  
 Se `hErr` não é `S_OK`, `AtlTraceErrorRecords` OLE DB erro informações de registro para o dispositivo de despejo de despejos de memória (o **depurar** guia da janela de saída ou um arquivo). As informações de registro de erro, que são obtidas do provedor, incluem o número de linhas, fonte, descrição, arquivo de Ajuda, contexto e GUID para cada entrada de registro de erro. `AtlTraceErrorRecords`Essas informações apenas em compilações de depuração de despejos de memória. Em compilações de versão, é um stub vazio que seja otimizado out.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)   
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)