---
title: Macros de troca de dados de registro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- RegistryDataExchange function, macros
ms.assetid: c1bc5e79-2307-43d2-9d10-3a62ffadf473
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: ee3c1d639ee4a6c6bd6cf26a8c59bb1a37a4fa02
ms.lasthandoff: 02/25/2017

---
# <a name="registry-data-exchange-macros"></a>Macros de Exchange de dados de registro
Essas macros realizar operações de troca de dados de registro.  
  
|||  
|-|-|  
|[BEGIN_RDX_MAP](#begin_rdx_map)|Marca o início do mapa de troca de dados de registro.|  
|[END_RDX_MAP](#end_rdx_map)|Marca o fim do mapa de troca de dados de registro.|  
|[RDX_BINARY](#rdx_binary)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo BYTE.|  
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa uma variável de membro especificado do tipo CString a entrada do Registro especificada.|  
|[RDX_DWORD](#rdx_dword)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo DWORD.|  
|[RDX_TEXT](#rdx_text)|Associa uma variável de membro especificado do tipo TCHAR a entrada do Registro especificada.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlplus.h  
   
##  <a name="a-namebeginrdxmapa--beginrdxmap"></a><a name="begin_rdx_map"></a>BEGIN_RDX_MAP  
 Marca o início do mapa de troca de dados de registro.  
  
```
BEGIN_RDX_MAP
```  
  
### <a name="remarks"></a>Comentários  
 As seguintes macros são usadas dentro do mapa de troca de dados de registro para ler e gravar entradas no registro do sistema:  
  
|Macro|Descrição|  
|-----------|-----------------|  
|[RDX_BINARY](#rdx_binary)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo BYTE.|  
|[RDX_DWORD](#rdx_dword)|Associa a entrada do Registro especificada com uma variável de membro especificado do tipo DWORD.|  
|[RDX_CSTRING_TEXT](#rdx_cstring_text)|Associa uma variável de membro especificado do tipo CString a entrada do Registro especificada.|  
|[RDX_TEXT](#rdx_text)|Associa uma variável de membro especificado do tipo TCHAR a entrada do Registro especificada.|  
  
 A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo `BEGIN_RDX_MAP` e `END_RDX_MAP` macros, deve ser usado sempre que seu código precisa para trocar dados entre o registro do sistema e as variáveis especificadas no mapa RDX.  
  
##  <a name="a-nameendrdxmapa--endrdxmap"></a><a name="end_rdx_map"></a>END_RDX_MAP  
 Marca o fim do mapa de troca de dados de registro.  
  
```
END_RDX_MAP
```  
  
##  <a name="a-namerdxbinarya--rdxbinary"></a><a name="rdx_binary"></a>RDX_BINARY  
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
 `rootkey`  
 A raiz de chave do registro.  
  
 `subkey`  
 A subchave do registro.  
  
 `valuename`  
 A chave do registro.  
  
 `member`  
 A variável de membro para associar a entrada do Registro especificada.  
  
 `member_size`  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com o `BEGIN_RDX_MAP` e `END_RDX_MAP` macros para associar uma variável de membro uma entrada de registro específico. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo `BEGIN_RDX_MAP` e `END_RDX_MAP` macros, deve ser usado para realizar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="a-namerdxcstringtexta--rdxcstringtext"></a><a name="rdx_cstring_text"></a>RDX_CSTRING_TEXT  
 Associa uma variável de membro especificado do tipo CString a entrada do Registro especificada.  
  
```
RDX_CSTRING_TEXT(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 `rootkey`  
 A raiz de chave do registro.  
  
 `subkey`  
 A subchave do registro.  
  
 `valuename`  
 A chave do registro.  
  
 `member`  
 A variável de membro para associar a entrada do Registro especificada.  
  
 `member_size`  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com o `BEGIN_RDX_MAP` e `END_RDX_MAP` macros para associar uma variável de membro uma entrada de registro específico. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo `BEGIN_RDX_MAP` e `END_RDX_MAP` macros, deve ser usado para realizar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="a-namerdxdworda--rdxdword"></a><a name="rdx_dword"></a>RDX_DWORD  
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
 `rootkey`  
 A raiz de chave do registro.  
  
 `subkey`  
 A subchave do registro.  
  
 `valuename`  
 A chave do registro.  
  
 `member`  
 A variável de membro para associar a entrada do Registro especificada.  
  
 `member_size`  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com o `BEGIN_RDX_MAP` e `END_RDX_MAP` macros para associar uma variável de membro uma entrada de registro específico. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo `BEGIN_RDX_MAP` e `END_RDX_MAP` macros, deve ser usado para realizar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
##  <a name="a-namerdxtexta--rdxtext"></a><a name="rdx_text"></a>RDX_TEXT  
 Associa uma variável de membro especificado do tipo TCHAR a entrada do Registro especificada.  
  
```
RDX_TEXT(
    rootkey, 
    subkey, 
    valuename, 
    member, 
    member_size )
```  
  
### <a name="parameters"></a>Parâmetros  
 `rootkey`  
 A raiz de chave do registro.  
  
 `subkey`  
 A subchave do registro.  
  
 `valuename`  
 A chave do registro.  
  
 `member`  
 A variável de membro para associar a entrada do Registro especificada.  
  
 `member_size`  
 O tamanho, em bytes, da variável de membro.  
  
### <a name="remarks"></a>Comentários  
 Essa macro é usada em conjunto com o `BEGIN_RDX_MAP` e `END_RDX_MAP` macros para associar uma variável de membro uma entrada de registro específico. A função global [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange), ou a função de membro do mesmo nome criado pelo `BEGIN_RDX_MAP` e `END_RDX_MAP` macros, deve ser usado para realizar a troca de dados entre o registro do sistema e as variáveis de membro no mapa RDX.  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [RegistryDataExchange](../../atl/reference/registry-and-typelib-global-functions.md#registrydataexchange)








