---
title: 'Método Ftmbase: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::UnmarshalInterface
dev_langs:
- C++
helpviewer_keywords:
- UnmarshalInterface method
ms.assetid: 6850a621-e9a6-4001-bc1e-bd5d1b121adc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 964ce5cc33b51c54446874522317814279cdd960
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877713"
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)