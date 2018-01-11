---
title: "Método Ftmbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: ftm/Microsoft::WRL::FtmBase::MarshalInterface
dev_langs: C++
helpviewer_keywords: MarshalInterface method
ms.assetid: fc8421b4-06e4-4925-b908-c285fe4790d2
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9df1e5d7559b434c1af0f1feff3b73b8141a8865
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ftmbasemarshalinterface-method"></a>Método FtmBase::MarshalInterface
Grava em um fluxo de dados necessários para inicializar um objeto de proxy em algum processo do cliente.  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `pStm`  
 Ponteiro para o fluxo a ser usado durante o empacotamento.  
  
 `riid`  
 Referência ao identificador da interface a ser empacotado. Esta interface deve ser derivada da interface IUnknown.  
  
 `pv`  
 Ponteiro para o ponteiro de interface para ser empacotado; pode ser NULL se o chamador não tem um ponteiro para a interface desejada.  
  
 `dwDestContext`  
 Contexto de destino onde a interface especificada é para ser desempacotada.  
  
 Especifique um ou mais valores de enumeração MSHCTX.  
  
 Unmarshaling pode ocorrer em outro apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).  
  
 `pvDestContext`  
 Reservado para uso futuro; deve ser zero.  
  
 `mshlflags`  
 Especifica se os dados a ser empacotado deve ser transmitido para o processo do cliente — o caso típico — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes.  
  
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)