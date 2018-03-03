---
title: "Método Ftmbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::UnmarshalInterface
dev_langs:
- C++
helpviewer_keywords:
- UnmarshalInterface method
ms.assetid: 6850a621-e9a6-4001-bc1e-bd5d1b121adc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ce3710e84a9f7680b56f461029f279a659a5c14a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ftmbaseunmarshalinterface-method"></a>Método FtmBase::UnmarshalInterface
Inicializa um proxy criado recentemente e retorna um ponteiro de interface de proxy.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHODIMP UnmarshalInterface(  
   __in IStream *pStm,  
   __in REFIID riid,  
   __deref_out void **ppv  
) override;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pStm`  
 Ponteiro para o fluxo do qual o ponteiro de interface é realizar unmarshaling.  
  
 `riid`  
 Referência ao identificador da interface a ser desempacotada.  
  
 `ppv`  
 Quando essa operação for concluída, o endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitado na `riid`. Se essa operação for bem-sucedida, *`ppv` contém o ponteiro de interface solicitada da interface a ser desempacotada.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_NOINTERFACE ou E_FAIL.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)