---
title: 'Método ftmbase:: Unmarshalinterface | Microsoft Docs'
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
ms.openlocfilehash: a1991454daa76fcf7878a7487080124b5a34dbeb
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644028"
---
# <a name="ftmbaseunmarshalinterface-method"></a>Método FtmBase::UnmarshalInterface
Inicializa um proxy recém-criado e retorna um ponteiro de interface para esse proxy.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHODIMP UnmarshalInterface(  
   __in IStream *pStm,  
   __in REFIID riid,  
   __deref_out void **ppv  
) override;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pStm*  
 Ponteiro para o fluxo do qual o ponteiro de interface deve ser desempacotada.  
  
 *riid*  
 Referência ao identificador da interface a ser desempacotada.  
  
 *ppv*  
 Quando essa operação for concluída, o endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitado no *riid*. Se essa operação for bem-sucedida, **ppv* contém o ponteiro da interface a ser desempacotada de interface solicitada.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_FAIL ou E_NOINTERFACE.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)