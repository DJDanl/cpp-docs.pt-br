---
title: Interface IRegistrar | Microsoft Docs
ms.custom: 
ms.date: 2/1/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IRegistrar
- ATLIFASE/ATL::IRegistrar
- ATLIFASE/ATL::IRegistrar::ResourceRegisterSz
- ATLIFASE/ATL::IRegistrar::ResourceUnregisterSz
- ATLIFASE/ATL::IRegistrar::FileRegister
- ATLIFASE/ATL::IRegistrar::FileUnregister
- ATLIFASE/ATL::IRegistrar::StringRegister
- ATLIFASE/ATL::IRegistrar::StringUnregister
- ATLIFASE/ATL::IRegistrar::ResourceRegister
- ATLIFASE/ATL::IRegistrar::ResourceUnregister
dev_langs: C++
helpviewer_keywords: Iregistrar Interface
ms.assetid: e88c04b7-0c93-4ae8-aeb9-ecd78f87421e
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6c0b304b00b5cc5c613ff7e81818d1c637989e5f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iregistrar-interface"></a>Interface IRegistrar
Essa interface é definido em atliface e é usado internamente por funções de membro CAtlModule como [UpdateRegistryFromResourceD](catlmodule-class.md#updateregistryfromresourced).   
  
## <a name="syntax"></a>Sintaxe  
  
```
typedef interface IRegistrar IRegistrar;
```  
## <a name="remarks"></a>Comentários
Consulte o tópico [usando parâmetros substituíveis (do registrador pré-processador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md) para obter mais detalhes.  

## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IRegistrar::ResourceRegisterSz](#resourceregistersz)|Registra o recurso. |  
|[IRegistrar::ResourceUnregisterSz](#resourceunregistersz)| Cancela o registro do recurso.|  
|[IRegistrar::FileRegister](#fileregister)|Registra o arquivo.|  
|[IRegistrar::FileUnregister](#fileunregister)|Cancela o registro do arquivo.|  
|[IRegistrar::StringRegister](#stringregister)|Registra a cadeia de caracteres.|  
|[IRegistrar::StringUnregister](#stringunregister)|Cancela o registro a cadeia de caracteres|  
|[IRegistrar::ResourceRegister](#resourceregister)|Registra o recurso.|  
|[IRegistrar::ResourceUnregister](#resourceunregister)|Cancela o registro do recurso.| 
  

 
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlifase.h  
  
##  <a name="resourceregistersz"></a>IRegistrar::ResourceRegisterSz 
 Registra o recurso.  
  
```
virtual HRESULT STDMETHODCALLTYPE ResourceRegisterSz( 
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```  
  
 
  
##  <a name="resourceunregistersz"></a>IRegistrar::ResourceUnregisterSz  
 Cancela o registro do recurso.
  
```
virtual HRESULT STDMETHODCALLTYPE ResourceUnregisterSz( 
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_z_ LPCOLESTR szID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```  
  
  
##  <a name="fileregister"></a>IRegistrar::FileRegister  
Registra o arquivo.
  
```
virtual HRESULT STDMETHODCALLTYPE FileRegister( 
    /* [in] */ _In_z_ LPCOLESTR fileName) = 0;
```  
  
  
##  <a name="fileunregister"></a>IRegistrar::FileUnregister  
Cancela o registro do arquivo.

```
virtual HRESULT STDMETHODCALLTYPE FileUnregister( 
    */ _In_z_ LPCOLESTR fileName) = 0;
```  
  
 
##  <a name="stringregister"></a>IRegistrar::StringRegister  
  Registra os dados de cadeia de caracteres especificada.
```
virtual HRESULT STDMETHODCALLTYPE StringRegister( 
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```  
  
##  <a name="stringunregister"></a>IRegistrar::StringUnregister
 Cancela o registro de dados de cadeia de caracteres especificada.  
  
```
virtualHRESULT STDMETHODCALLTYPE StringUnregister( 
    /* [in] */ _In_z_ LPCOLESTR data) = 0;
```  

  
##  <a name="resourceregister"></a>IRegistrar::ResourceRegister  
 Registra o recurso.  
  
```
virtual HRESULT STDMETHODCALLTYPE ResourceRegister( 
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0;
```  
   
  
##  <a name="resourceunregister"></a>IRegistrar::ResourceUnregister  
 Cancela o registro do recurso.  
  
```
virtualHRESULT STDMETHODCALLTYPE ResourceUnregister( 
    /* [in] */ _In_z_ LPCOLESTR resFileName,
    /* [in] */ _In_ UINT nID,
    /* [in] */ _In_z_ LPCOLESTR szType) = 0; 
```  
 
## <a name="see-also"></a>Consulte também  
 [Usando parâmetros substituíveis (pré-processador do Registrador)](../../atl/using-replaceable-parameters-the-registrar-s-preprocessor.md)  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)   
 [Componente de registro (Registrar)](../../atl/atl-registry-component-registrar.md)  
