---
title: "M&#233;todo WeakRef::AsIID | Microsoft Docs"
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
  - "client/Microsoft::WRL::WeakRef::AsIID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AsIID"
ms.assetid: 94e87309-32da-4dbb-8233-e77313a1f448
caps.latest.revision: 7
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo WeakRef::AsIID
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define o parâmetro de ponteiro ComPtr especificado para representar a ID da interface especificada.  
  
## Sintaxe  
  
```  
HRESULT AsIID(  
   REFIID riid,  
   _Out_ ComPtr<IInspectable>* ptr  
);  
```  
  
#### Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ptr`  
 Quando essa operação for concluída, um objeto que representa o parâmetro `riid`.  
  
## Valor de retorno  
  
-   S\_OK se essa operação for bem\-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e `ptr` é definido como `nullptr`.  
  
-   S\_OK se essa operação for bem\-sucedida, mas o objeto WeakRef atual já foi liberado. Parâmetro `ptr` é definido como `nullptr`.  
  
-   S\_OK se essa operação for bem\-sucedida, mas o objeto WeakRef atual não é derivado do parâmetro `riid`. Parâmetro `ptr` é definido como `nullptr`. \(Para obter mais informações, consulte comentários.\)  
  
## Comentários  
 Um erro será emitido se parâmetro `riid` não é derivado de IInspectable. Esse erro substitui o valor de retorno.  
  
 O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo \(não mostrada aqui mas declarado no arquivo de cabeçalho\) é uma especialização de auxiliar interno, que oferece suporte a recursos da linguagem C\+\+, como o [automático](../cpp/auto-cpp.md) palavra\-chave de dedução de tipo.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar código de verificação de erro que verifica o WeakRef para `nullptr`. Em vez disso, verifique o HRESULT retornado para determinar se o método foi bem\-sucedido, ou marque `ptr` para `nullptr`.  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)