---
title: "Método Ftmbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: ftm/Microsoft::WRL::FtmBase::GetMarshalSizeMax
dev_langs: C++
helpviewer_keywords: GetMarshalSizeMax method
ms.assetid: b416b1bf-c73e-45d5-abb8-04921c1a0c94
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0d68889531c270db190f861eb20a34783b88987f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ftmbasegetmarshalsizemax-method"></a>Método FtmBase::GetMarshalSizeMax
Obter o limite superior no número de bytes necessários para realizar marshaling do ponteiro de interface especificado no objeto especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHODIMP GetMarshalSizeMax(  
   __in REFIID riid,  
   __in_opt void *pv,  
   __in DWORD dwDestContext,  
   __reserved void *pvDestContext,  
   __in DWORD mshlflags,  
   __out DWORD *pSize  
) override;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Referência ao identificador da interface a ser empacotado.  
  
 `pv`  
 Ponteiro de interface para ser empacotado; pode ser NULL.  
  
 `dwDestContext`  
 Contexto de destino onde a interface especificada é para ser desempacotada.  
  
 Especifique um ou mais valores de enumeração MSHCTX.  
  
 Atualmente, o unmarshaling pode ocorrer em outro apartment do processo atual (MSHCTX_INPROC) ou em outro processo no mesmo computador que o processo atual (MSHCTX_LOCAL).  
  
 `pvDestContext`  
 Reservado para uso futuro; deve ser NULL.  
  
 `mshlflags`  
 Sinalizador que indica se os dados a ser empacotado são a serem transmitidos para o processo do cliente — o caso típico — ou gravados em uma tabela global, onde ela pode ser recuperada por vários clientes. Especifique um ou mais valores de enumeração MSHLFLAGS.  
  
 `pSize`  
 Quando essa operação for concluída, ponteiro para o limite superior na quantidade de dados a serem gravados no fluxo de marshaling.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, E_FAIL ou E_NOINTERFACE.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)