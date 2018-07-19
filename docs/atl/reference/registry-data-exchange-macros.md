---
title: Macros de troca de dados de registro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlplus/ATL::BEGIN_RDX_MAP
- atlplus/ATL::END_RDX_MAP
- atlplus/ATL::RDX_BINARY
- atlplus/ATL::RDX_CSTRING_TEXT
- atlplus/ATL::RDX_DWORD
- atlplus/ATL::RDX_TEXT
dev_langs:
- C++
helpviewer_keywords:
- RegistryDataExchange function, macros
ms.assetid: c1bc5e79-2307-43d2-9d10-3a62ffadf473
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7473bed5e4bf973dcea4d186e9b5b3367fb03ff1
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37880353"
---
# <a name="registry-data-exchange-macros"></a>Macros de troca de dados de registro
Essas macros executam operações de troca de dados de registro.  
  
|||  
|-|-|  
|[BEGIN_RDX_MAP](#begin_rdx_map)|Marca o início do mapa de troca de dados de registro.|  
|[END_RDX_MAP](#end_rdx_map)|Marca o fim do mapa de troca de dados de registro.|  
|[RDX_BINARY](#rdx_binary)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo BYTE.|  
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo CString.|  
|[RDX_DWORD](#rdx_dword)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo DWORD.|  
|[RDX_TEXT](#rdx_text)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo TCHAR.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlplus.h  
   
##  <a name="begin_rdx_map"></a>  BEGIN_RDX_MAP  
 Marca o início do mapa de troca de dados de registro.  
  
```
BEGIN_RDX_MAP
```  
  
### <a name="remarks"></a>Comentários  
 As macros a seguir são usadas dentro do mapa de troca de dados de registro para ler e gravar entradas no registro do sistema:  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[RDX_BINARY](#rdx_binary)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo BYTE.|  
|[RDX_DWORD](#rdx_dword)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo DWORD.|  
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo CString.|  
|[RDX_TEXT](#rdx_text)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo TCHAR.|  
  
 A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo macros BEGIN_RDX_MAP e END_RDX_MAP, deve ser usado sempre que seu código precisa para trocar dados entre o registro do sistema e o variáveis especificadas no mapa RDX.  
  
##  <a name="end_rdx_map"></a>  END_RDX_MAP  
 Marca o fim do mapa de troca de dados de registro.  
  
```
END_RDX_MAP
```  
  
##  <a name="rdx_binary"></a>  RDX_BINARY  
 Associa a entrada do Registro especificada com uma variável de membro especificado do tipo BYTE.  
  
```
RDX_BINARY(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ROOTKEY*  
 A chave raiz do registro.  
  
 *subchave*  
 A subchave do registro.  
  
 *ValueName*  
 A chave do registro.  
  
 *Membro*  
 A variável de membro para associar a entrada do registro especificado.  
  
 *member_size*  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro uma entrada de registro determinado. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo macros BEGIN_RDX_MAP e END_RDX_MAP, devem ser usadas para executar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="rdx_cstring_text"></a>  RDX_CSTRING_TEXT  
 Associa a entrada do Registro especificada com uma variável de membro especificado do tipo CString.  
  
```
RDX_CSTRING_TEXT(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ROOTKEY*  
 A chave raiz do registro.  
  
 *subchave*  
 A subchave do registro.  
  
 *ValueName*  
 A chave do registro.  
  
 *Membro*  
 A variável de membro para associar a entrada do registro especificado.  
  
 *member_size*  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro uma entrada de registro determinado. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo macros BEGIN_RDX_MAP e END_RDX_MAP, devem ser usadas para executar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="rdx_dword"></a>  RDX_DWORD  
 Associa a entrada do Registro especificada com uma variável de membro especificado do tipo DWORD.  
  
```
RDX_DWORD(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ROOTKEY*  
 A chave raiz do registro.  
  
 *subchave*  
 A subchave do registro.  
  
 *ValueName*  
 A chave do registro.  
  
 *Membro*  
 A variável de membro para associar a entrada do registro especificado.  
  
 *member_size*  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro uma entrada de registro determinado. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo macros BEGIN_RDX_MAP e END_RDX_MAP, devem ser usadas para executar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="rdx_text"></a>  RDX_TEXT  
 Associa a entrada do Registro especificada com uma variável de membro especificado do tipo TCHAR.  
  
```
RDX_TEXT(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 *ROOTKEY*  
 A chave raiz do registro.  
  
 *subchave*  
 A subchave do registro.  
  
 *ValueName*  
 A chave do registro.  
  
 *Membro*  
 A variável de membro para associar a entrada do registro especificado.  
  
 *member_size*  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com as macros BEGIN_RDX_MAP e END_RDX_MAP para associar uma variável de membro uma entrada de registro determinado. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo macros BEGIN_RDX_MAP e END_RDX_MAP, devem ser usadas para executar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange)







