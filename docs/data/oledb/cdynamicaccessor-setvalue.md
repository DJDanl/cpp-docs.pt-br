---
title: CDynamicAccessor::SetValue | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CDynamicAccessor.SetValue
- ATL::CDynamicAccessor::SetValue
- ATL::CDynamicAccessor::SetValue<ctype>
- CDynamicAccessor.SetValue
- ATL.CDynamicAccessor.SetValue<ctype>
- CDynamicAccessor::SetValue
- CDynamicAccessor::SetValue<ctype>
dev_langs:
- C++
helpviewer_keywords:
- SetValue method
ms.assetid: ecc18850-96e5-4845-abe5-ab34ad467238
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2227564d321ca3c5c590c11fca52b906ebc911ca
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicaccessorsetvalue"></a>CDynamicAccessor::SetValue
Armazena dados para uma coluna especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <class ctype>
bool SetValue(   
   DBORDINAL nColumn,   
   constctype& data) throw( );  

template <class ctype>    
bool SetValue(   
   const CHAR * pColumnName,   
   const ctype& data) throw( );  

template <class ctype>   
bool SetValue(  
   const WCHAR *pColumnName,  
   const ctype& data) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ctype`  
 [in] Um parâmetro de modelo que lida com qualquer tipo de dados exceto tipos de cadeia de caracteres (**CHAR\***, **WCHAR\***), que requerem tratamento especial. `GetValue` usa o tipo de dados apropriado com base no que você especificar aqui.  
  
 `pColumnName`  
 [in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 `data`  
 [in] O ponteiro para a memória que contém os dados.  
  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.  
  
## <a name="return-value"></a>Valor de retorno  
 Se você quiser definir dados de cadeia de caracteres, use as versões nontemplated do `GetValue`. As versões de nontemplated desse método de retorno **void\***, que aponta para a parte do buffer que contém os dados da coluna especificada. Retorna **nulo** se a coluna não for encontrada.  
  
 Para todos os outros tipos de dados, é mais simples de usar as versões de modelo de `GetValue`. As versões de modelo retornam **true** em caso de sucesso ou **false** em caso de falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)