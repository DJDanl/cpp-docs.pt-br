---
title: "Classe de IPersistStorageImpl | Microsoft Docs"
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
  - "ATL::IPersistStorageImpl"
  - "ATL::IPersistStorageImpl<T>"
  - "ATL.IPersistStorageImpl<T>"
  - "IPersistStorageImpl"
  - "ATL.IPersistStorageImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IPersistStorageImpl"
  - "storage, ATL"
ms.assetid: d652f02c-239c-47c7-9a50-3e9fc3014fff
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPersistStorageImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa a interface de [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template <  
class T  
>  
class ATL_NO_VTABLE IPersistStorageImpl :  
public IPersistStorage  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPersistStorageImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPersistStorageImpl::GetClassID](../Topic/IPersistStorageImpl::GetClassID.md)|Recupera o CLSID do objeto.|  
|[IPersistStorageImpl::HandsOffStorage](../Topic/IPersistStorageImpl::HandsOffStorage.md)|Instrui o objeto para liberar todos os objetos de armazenamento e para ir para o modo de HandsOff.  a implementação de ATL retorna `S_OK`.|  
|[IPersistStorageImpl::InitNew](../Topic/IPersistStorageImpl::InitNew.md)|Inicializa um novo armazenamento.|  
|[IPersistStorageImpl::IsDirty](../Topic/IPersistStorageImpl::IsDirty.md)|Verifica se os dados do objeto foram alterado desde que os foram salvos o último.|  
|[IPersistStorageImpl::Load](../Topic/IPersistStorageImpl::Load.md)|Carrega as propriedades do objeto de armazenamento especificado.|  
|[IPersistStorageImpl::Save](../Topic/IPersistStorageImpl::Save.md)|Salva as propriedades do objeto para o armazenamento especificado.|  
|[IPersistStorageImpl::SaveCompleted](../Topic/IPersistStorageImpl::SaveCompleted.md)|Notifica um objeto que pode retornar ao modo normal para gravar no seu objeto de armazenamento.  a implementação de ATL retorna `S_OK`.|  
  
## Comentários  
 `IPersistStorageImpl` implementa a interface de [IPersistStorage](http://msdn.microsoft.com/library/windows/desktop/ms679731) , que permite que um cliente parte que sua carga do objeto e salvar os dados persistentes usando um armazenamento.  
  
 A implementação da classe requer a classe `T` fazer uma implementação da interface de `IPersistStreamInit` disponível através de `QueryInterface`.  Geralmente isso significa que a classe `T` deve derivar de [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md), fornecer uma entrada para `IPersistStreamInit` em [Mapa COM](../Topic/BEGIN_COM_MAP.md), e usar [mapeamento de propriedade](../Topic/BEGIN_PROP_MAP.md) para descrever dados persistentes da classe.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPersistStorage`  
  
 `IPersistStorageImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Storages and Streams](http://msdn.microsoft.com/library/windows/desktop/aa380352)   
 [Classe de IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)   
 [Classe de IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)