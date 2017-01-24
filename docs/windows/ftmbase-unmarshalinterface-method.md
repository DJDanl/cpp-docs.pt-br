---
title: "M&#233;todo FtmBase::UnmarshalInterface | Microsoft Docs"
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
  - "ftm/Microsoft::WRL::FtmBase::UnmarshalInterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método UnmarshalInterface"
ms.assetid: 6850a621-e9a6-4001-bc1e-bd5d1b121adc
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo FtmBase::UnmarshalInterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inicializa um proxy padrão e retorna um ponteiro de interface para esse proxy.  
  
## Sintaxe  
  
```  
STDMETHODIMP UnmarshalInterface(  
   __in IStream *pStm,  
   __in REFIID riid,  
   __deref_out void **ppv  
) override;  
```  
  
#### Parâmetros  
 `pStm`  
 Ponteiro para o fluxo do qual o ponteiro de interface deve ser unmarshaled.  
  
 `riid`  
 Referência ao identificador da interface a ser usada.  
  
 `ppv`  
 Quando esta operação concluída, o endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitada em `riid`.  Se essa operação é bem\-sucedida, \*`ppv` contém o ponteiro solicitando a interface da interface a ser unmarshaled.  
  
## Valor de retorno  
 S\_OK se bem\-sucedido; se não, E\_NOINTERFACE ou E\_FAIL.  
  
## Requisitos  
 **Cabeçalho:** ftm.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe FtmBase](../windows/ftmbase-class.md)