---
title: 'Cdynamicaccessor:: GetValue | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- GetValue
- CDynamicAccessor::GetValue<ctype>
- ATL.CDynamicAccessor.GetValue<ctype>
- CDynamicAccessor.GetValue
- CDynamicAccessor::GetValue
- ATL.CDynamicAccessor.GetValue
- ATL::CDynamicAccessor::GetValue
- ATL::CDynamicAccessor::GetValue<ctype>
dev_langs: C++
helpviewer_keywords: GetValue method
ms.assetid: 553f44af-68bc-4cb6-8774-e0940003fa90
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1599cd82347c4074863f2b649a2c67df894893e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicaccessorgetvalue"></a>CDynamicAccessor::GetValue
Recupera os dados de uma coluna especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void* GetValue(   
   DBORDINAL nColumn    
) const throw( );  
void* GetValue(  
   const CHAR* pColumnName   
) const throw( );  
void* GetValue(  
   const WCHAR* pColumnName   
) const throw( );  
template < class ctype >  
bool GetValue(  
   DBORDINAL nColumn,  
   ctype* pData   
) const throw( );  
template < class ctype >  
bool GetValue(  
   const CHAR* pColumnName,  
   ctype* pData   
) const throw( );  
template < class ctype >  
bool GetValue(  
   const WCHAR* pColumnName,  
   ctype* pData   
) const throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ctype`  
 [in] Um parâmetro de modelo que lida com qualquer tipo de dados exceto tipos de cadeia de caracteres (**CHAR\***, **WCHAR\***), que requerem tratamento especial. `GetValue`usa o tipo de dados apropriado com base no que você especificar aqui.  
  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.  
  
 `pColumnName`  
 [in] O nome da coluna.  
  
 `pData`  
 [out] O ponteiro para o conteúdo da coluna especificada.  
  
## <a name="return-value"></a>Valor de retorno  
 Se você quiser passar dados de cadeia de caracteres, use as versões nontemplated do `GetValue`. As versões de nontemplated desse método de retorno **void\***, que aponta para a parte do buffer que contém os dados da coluna especificada. Retorna **nulo** se a coluna não for encontrada.  
  
 Para todos os outros tipos de dados, é mais simples de usar as versões de modelo de `GetValue`. As versões de modelo retornam **true** em caso de sucesso ou **false** em caso de falha.  
  
## <a name="remarks"></a>Comentários  
 Use as versões nontemplated para retornar as colunas que contêm cadeias de caracteres e as versões de modelo para colunas que contêm outros tipos de dados.  
  
 No modo de depuração, você obterá uma asserção se o tamanho de `pData` é igual ao tamanho da coluna para a qual ele aponta.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)