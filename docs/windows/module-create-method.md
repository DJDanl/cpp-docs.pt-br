---
title: "M&#233;todo Module::Create | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module::Create"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Create"
ms.assetid: bfa97fd7-5226-4604-92a5-3b9697053e64
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::Create
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma instância de um módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW static Module& Create();  
template<  
   typename T  
>  
WRL_NOTHROW static Module& Create(  
   T callback  
);  
template<  
   typename T  
>  
WRL_NOTHROW static Module& Create(  
   _In_ T* object,  
   _In_ void (T::* method)()  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Tipo de módulo.  
  
 `callback`  
 Chamado quando o último objeto de instância do módulo é liberado.  
  
 `object`  
 O `object` e `method` os parâmetros são usados em combinação. Aponta para o último objeto de instância quando o último objeto de instância no módulo é liberado.  
  
 `method`  
 O `object` e `method` os parâmetros são usados em combinação. Aponta para o método do último objeto de instância quando o último objeto de instância no módulo é liberado.  
  
## <a name="return-value"></a>Valor de retorno  
 Referência ao módulo.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
[Classe de módulo](../windows/module-class.md)

 