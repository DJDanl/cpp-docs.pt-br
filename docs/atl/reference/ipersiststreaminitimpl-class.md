---
title: "Classe de IPersistStreamInitImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL::IPersistStreamInitImpl"
  - "ATL::IPersistStreamInitImpl<T>"
  - "ATL.IPersistStreamInitImpl<T>"
  - "IPersistStreamInitImpl"
  - "ATL.IPersistStreamInitImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Implementação de IPersistStreamInit ATL"
  - "Classe de IPersistStreamInitImpl"
  - "fluxos, ATL"
ms.assetid: ef217c3c-020f-4cf8-871e-ef68e57865b8
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPersistStreamInitImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template<  
class T   
>  
class ATL_NO_VTABLE IPersistStreamInitImpl :  
public IPersistStreamInit  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPersistStreamInitImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPersistStreamInitImpl::GetClassID](../Topic/IPersistStreamInitImpl::GetClassID.md)|Recupera o CLSID do objeto.|  
|[IPersistStreamInitImpl::GetSizeMax](../Topic/IPersistStreamInitImpl::GetSizeMax.md)|Retorna o tamanho de fluxo necessário salvar os dados do objeto.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IPersistStreamInitImpl::InitNew](../Topic/IPersistStreamInitImpl::InitNew.md)|Inicializa um objeto criado.|  
|[IPersistStreamInitImpl::IsDirty](../Topic/IPersistStreamInitImpl::IsDirty.md)|Verifica se os dados do objeto foram alterado desde que os foram salvos o último.|  
|[IPersistStreamInitImpl::Load](../Topic/IPersistStreamInitImpl::Load.md)|Carrega as propriedades do objeto de fluxo especificado.|  
|[IPersistStreamInitImpl::Save](../Topic/IPersistStreamInitImpl::Save.md)|Salva as propriedades do objeto para o fluxo especificado.|  
  
## Comentários  
 A interface de [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) permite que um cliente peça ao objeto carregar e salvar os dados persistentes a um único fluxo.  A classe `IPersistStreamInitImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPersistStreamInit`  
  
 `IPersistStreamInitImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Storages and Streams](http://msdn.microsoft.com/library/windows/desktop/aa380352)   
 [Visão geral de classe](../../atl/atl-class-overview.md)