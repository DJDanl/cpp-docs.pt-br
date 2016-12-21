---
title: "M&#233;todo Module::GetActivationFactory | Microsoft Docs"
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
  - "module/Microsoft::WRL::Module::GetActivationFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetActivationFactory"
ms.assetid: 59da8844-072e-414b-b89c-1db1cc4fd81d
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo Module::GetActivationFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Obtém uma alocador de ativação para o módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW HRESULT GetActivationFactory(  
   _In_ HSTRING pActivatibleClassId,  
   _Deref_out_ IActivationFactory **ppIFactory,  
   wchar_t* serverName = nullptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pActivatibleClassId`  
 IID de uma classe de tempo de execução.  
  
 `ppIFactory`  
 O IActivationFactory para a classe de tempo de execução especificado.  
  
 `serverName`  
 O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado no [ActivatableClassWithFactoryEx](../Topic/ActivatableClass%20Macros.md) macro, ou especificar `nullptr` para obter o nome do servidor padrão.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, o HRESULT retornado por GetActivationFactory.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
[Classe de módulo](../windows/module-class.md)
 [ActivatableClass Macros](../Topic/ActivatableClass%20Macros.md)