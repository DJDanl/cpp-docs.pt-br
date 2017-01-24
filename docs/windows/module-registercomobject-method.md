---
title: "M&#233;todo Module::RegisterCOMObject | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module::RegisterCOMObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método RegisterCOMObject"
ms.assetid: 59f223dc-03c6-429d-95da-b74b3f73b702
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::RegisterCOMObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Registra um ou mais objetos para que outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW virtual HRESULT RegisterCOMObject(  
   const wchar_t* serverName,  
   IID* clsids,  
   IClassFactory** factories,  
   DWORD* cookies,  
   unsigned int count);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `serverName`  
 Nome totalmente qualificado de um servidor.  
  
 `clsids`  
 Uma matriz de CLSIDs para registrar.  
  
 `factories`  
 Uma matriz de interfaces IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.  
  
 `cookies`  
 Quando a operação for concluída, uma matriz de ponteiros para os valores que identificam a classe de objetos que foram registrados. Esses valores são usados mais tarde revogar o registro.  
  
 `count`  
 O número de CLSIDs para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.  
  
## <a name="remarks"></a>Comentários  
 Os objetos COM são registrados com o enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.  
  
 O tipo de conexão para os objetos registrados é especificado por uma combinação do atual `comflag` parâmetro do modelo e o enumerador REGCLS_SUSPENDED da enumeração REGCLS.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe de módulo](../windows/module-class.md)