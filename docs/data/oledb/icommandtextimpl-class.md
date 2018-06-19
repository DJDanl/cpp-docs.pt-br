---
title: Classe ICommandTextImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ICommandText
dev_langs:
- C++
helpviewer_keywords:
- ICommandText class
ms.assetid: 9c2715cc-1e55-4468-8327-85341617ed46
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f49326dba4868ad490dc1a7122eed68271bdfa15
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33100194"
---
# <a name="icommandtextimpl-class"></a>Classe ICommandTextImpl
Fornece uma implementação para o [ICommandText](https://msdn.microsoft.com/en-us/library/ms714914.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T >  
class ATL_NO_VTABLE ICommandTextImpl   
   : public ICommandImpl<T, ICommandText>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O comando de classe derivada de **ICommandTextImpl**.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetCommandText](../../data/oledb/icommandtextimpl-getcommandtext.md)|Retorna o texto de comandos definidos pela última chamada para [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).|  
|[SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md)|Define o texto de comando, substituindo o texto do comando existente.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_strCommandText](../../data/oledb/icommandtextimpl-m-strcommandtext.md)|Armazena o texto do comando.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em comandos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** altdb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)