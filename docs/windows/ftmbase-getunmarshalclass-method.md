---
title: "M&#233;todo FtmBase::GetUnmarshalClass | Microsoft Docs"
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
  - "ftm/Microsoft::WRL::FtmBase::GetUnmarshalClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetUnmarshalClass"
ms.assetid: 535fc539-5b97-4967-b158-f7568f13d341
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo FtmBase::GetUnmarshalClass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém CLSID que a usa para localizar a DLL que contém código para o proxy correspondente.  Carrega COM este DLL para criar uma instância de não inicializada do proxy.  
  
## Sintaxe  
  
```  
STDMETHODIMP GetUnmarshalClass(  
   __in REFIID riid,  
   __in_opt void *pv,  
   __in DWORD dwDestContext,  
   __reserved void *pvDestContext,  
   __in DWORD mshlflags,  
   __out CLSID *pCid  
) override;  
```  
  
#### Parâmetros  
 `riid`  
 Referência ao identificador da interface para realizar marshaling.  
  
 `pv`  
 Ponteiro para a interface a ser usada; poderá ser NULL se o chamador não tem um ponteiro para a interface desejada.  
  
 `dwDestContext`  
 Contexto de destino onde a interface especificada deve ser unmarshaled.  
  
 Especifique um ou mais valores de enumeração de MSHCTX.  
  
 O desempacotamento pode ocorrer em outro STA. do processo atual \(MSHCTX\_INPROC\) ou em outro processo no mesmo computador que o processo atual \(MSHCTX\_LOCAL\).  
  
 `pvDestContext`  
 Reservado para uso futuro; deve ser NULL.  
  
 `mshlflags`  
 Quando esta operação concluir, ponteiro para CLSID a ser usado para criar um proxy no processo do cliente.  
  
 `pCid`  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; se não, S\_FALSE.  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)