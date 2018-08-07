---
title: 'Método ftmbase:: Marshalinterface | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- ftm/Microsoft::WRL::FtmBase::MarshalInterface
dev_langs:
- C++
helpviewer_keywords:
- MarshalInterface method
ms.assetid: fc8421b4-06e4-4925-b908-c285fe4790d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ff0c1a5e41dfe46f2d88aeeb3093dbc9ee4d4005
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570051"
---
# <a name="ftmbasemarshalinterface-method"></a>Método FtmBase::MarshalInterface
Grava os dados necessários para inicializar um objeto de proxy em algum processo do cliente em um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHODIMP MarshalInterface(  
   __in IStream *pStm,  
   __in REFIID riid,  
   __in_opt void *pv,  
   __in DWORD dwDestContext,  
   __reserved void *pvDestContext,  
   __in DWORD mshlflags  
) override;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pStm*  
 Ponteiro para o fluxo a ser usado durante o marshaling.  
  
 *riid*  
 Referência ao identificador da interface a ser empacotado. Essa interface deve ser derivada de `IUnknown` interface.  
  
 *VP*  
 Ponteiro para o ponteiro de interface para ser empacotado; pode ser NULL se o chamador não tem um ponteiro para a interface desejada.  
  
 *dwDestContext*  
 Contexto de destino onde a interface especificada deve ser desempacotada.  
  
 Especifique um ou mais valores de enumeração MSHCTX.  
  
 Unmarshaling pode ocorrer em outra apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).  
  
 *pvDestContext*  
 Reservado para uso futuro; deve ser zero.  
  
 *mshlflags*  
 Especifica se os dados a ser empacotado deve ser transmitido de volta para o processo do cliente — o caso comum — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK  
 O ponteiro de interface foi empacotado com êxito.  
  
 E_NOINTERFACE  
 Não há suporte para a interface especificada.  
  
 STG_E_MEDIUMFULL  
 O fluxo está cheio.  
  
 E_FAIL  
 A operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)