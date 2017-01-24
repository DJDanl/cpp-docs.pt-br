---
title: "M&#233;todo FtmBase::GetMarshalSizeMax | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ftm/Microsoft::WRL::FtmBase::GetMarshalSizeMax"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetMarshalSizeMax"
ms.assetid: b416b1bf-c73e-45d5-abb8-04921c1a0c94
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo FtmBase::GetMarshalSizeMax
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obter o limite superior no número de bytes necessário para realizar marshaling do ponteiro especificado da interface no objeto especificado.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `riid`  
 Referência ao identificador da interface para realizar marshaling.  
  
 `pv`  
 Ponteiro de interface para realizar marshaling; pode ser NULL.  
  
 `dwDestContext`  
 Contexto de destino onde a interface especificada deve ser unmarshaled.  
  
 Especifique um ou mais valores de enumeração de MSHCTX.  
  
 Atualmente, o desempacotamento pode ocorrer em outro STA. do processo atual \(MSHCTX\_INPROC\) ou em outro processo no mesmo computador que o processo atual \(MSHCTX\_LOCAL\).  
  
 `pvDestContext`  
 Reservado para uso futuro; deve ser NULL.  
  
 `mshlflags`  
 Sinalizador que indica se os dados devem realizar marshaling ser passados de volta ao processo de cliente — os casos característicos — ou ser gravada em uma tabela global, onde podem ser recuperados por vários clientes.  Especifique um ou mais valores de enumeração de MSHLFLAGS.  
  
 `pSize`  
 Quando esta operação concluir, ponteiro para o limite superior na quantidade de dados a serem gravados no fluxo marshaling.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; se não, E\_FAIL ou E\_NOINTERFACE.  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)