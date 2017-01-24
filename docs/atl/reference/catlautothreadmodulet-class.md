---
title: "Classe de CAtlAutoThreadModuleT | Microsoft Docs"
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
  - "ATL.CAtlAutoThreadModuleT"
  - "ATL::CAtlAutoThreadModuleT"
  - "CAtlAutoThreadModuleT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlAutoThreadModuleT"
ms.assetid: ae1667c6-3fb8-47bc-b35d-9ea5e9896d7f
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlAutoThreadModuleT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para implementar com agrupados, o servidor de apartamento\- COM o modelo.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T,  
class ThreadAllocator= CComSimpleThreadAllocator,  
DWORD dwWait= INFINITE   
>  
class ATL_NO_VTABLE CAtlAutoThreadModuleT :  
public IAtlAutoThreadModule  
```  
  
#### Parâmetros  
 `T`  
 A classe que implementará o servidor COM.  
  
 `ThreadAllocator`  
 A classe que gerencia a seleção de segmento.  o valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).  
  
 `dwWait`  
 Especifica o intervalo de tempo limite em milissegundos.  O padrão é INFINITA, o que significa que o intervalo de tempo limite de método não decorre.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlAutoThreadModuleT::GetDefaultThreads](../Topic/CAtlAutoThreadModuleT::GetDefaultThreads.md)|Essa função estática dinamicamente calcula e retorna o número máximo de segmentos para o módulo de EXE, com base no número de processadores.|  
  
## Comentários  
 A classe deriva de [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md)`CAtlAutoThreadModuleT` para implementar com agrupados, o servidor de apartamento\- COM o modelo.  Substitui a classe [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md)obsoleta.  
  
> [!NOTE]
>  Esta classe não deve ser usada em uma DLL, porque o valor padrão de `dwWait` de INFINITO causará um deadlock quando o DLL é descarregado.  
  
## Hierarquia de herança  
 `IAtlAutoThreadModule`  
  
 `CAtlAutoThreadModuleT`  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de IAtlAutoThreadModule](../../atl/reference/iatlautothreadmodule-class.md)   
 [Classes de módulo](../Topic/ATL%20Module%20Classes.md)