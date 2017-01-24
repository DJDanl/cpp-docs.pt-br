---
title: "Classe de IPersistPropertyBagImpl | Microsoft Docs"
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
  - "IPersistPropertyBagImpl"
  - "ATL.IPersistPropertyBagImpl<T>"
  - "ATL::IPersistPropertyBagImpl"
  - "ATL::IPersistPropertyBagImpl<T>"
  - "ATL.IPersistPropertyBagImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IPersistPropertyBagImpl"
ms.assetid: 712af24d-99f8-40f2-9811-53b3ff6e5b19
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPersistPropertyBagImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e permite que um objeto salvar suas propriedades para um saco cliente fornecido da propriedade.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template <   
class T   
>  
class ATL_NO_VTABLE IPersistPropertyBagImpl :  
public IPersistPropertyBag  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPersistPropertyBagImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPersistPropertyBagImpl::GetClassID](../Topic/IPersistPropertyBagImpl::GetClassID.md)|Recupera o CLSID do objeto.|  
|[IPersistPropertyBagImpl::InitNew](../Topic/IPersistPropertyBagImpl::InitNew.md)|Inicializa um objeto criado.  a implementação de ATL retorna `S_OK`.|  
|[IPersistPropertyBagImpl::Load](../Topic/IPersistPropertyBagImpl::Load.md)|Carrega as propriedades do objeto de um saco cliente fornecido da propriedade.|  
|[IPersistPropertyBagImpl::Save](../Topic/IPersistPropertyBagImpl::Save.md)|Salva as propriedades do objeto em um saco cliente fornecido da propriedade.|  
  
## Comentários  
 A interface de [IPersistPropertyBag](https://msdn.microsoft.com/en-us/library/aa768205.aspx) permite que um objeto salvar suas propriedades para um saco cliente fornecido da propriedade.  A classe `IPersistPropertyBagImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 Trabalhos de**IPersistPropertyBag** em conjunto com [IPropertyBag](https://msdn.microsoft.com/en-us/library/aa768196.aspx) e [IErrorLog](https://msdn.microsoft.com/en-us/library/aa768231.aspx).  Essas duas últimas interfaces devem ser implementadas pelo cliente.  Com `IPropertyBag`, o cliente salva e carrega as propriedades individuais do objeto.  Com **IErrorLog**, o objeto e o cliente pode relatar erros encontrados.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPersistPropertyBag`  
  
 `IPersistPropertyBagImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [BEGIN\_PROP\_MAP](../Topic/BEGIN_PROP_MAP.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)