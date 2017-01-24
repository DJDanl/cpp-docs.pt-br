---
title: "Classe de IPropertyPage2Impl | Microsoft Docs"
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
  - "IPropertyPage2Impl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Implementação de IPropertyPage2 ATL"
  - "Classe de IPropertyPage2Impl"
  - "páginas de propriedades"
ms.assetid: e89fbe90-203a-47f0-a5de-23616697e1ce
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPropertyPage2Impl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IPropertyPage2Impl : public IPropertyPageImpl< T>  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPropertyPage2Impl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPropertyPage2Impl::EditProperty](../Topic/IPropertyPage2Impl::EditProperty.md)|Especifica que o controle da propriedade receberá o foco quando a página de propriedades é ativada.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 a interface de [IPropertyPage2](http://msdn.microsoft.com/library/windows/desktop/ms683996) estende [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) adicionando o método de `EditProperty` .  Esse método permite que um cliente seleciona uma propriedade específica em um objeto da página de propriedades.  
  
 A classe `IPropertyPage2Impl` simplesmente retorna **E\_NOTIMPL** para **IPropertyPage2::EditProperty**.  Em o entanto, ele herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md) e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 Quando você cria uma página de propriedades, a classe é derivada de `IPropertyPageImpl`normalmente.  Para fornecer suporte adicional de **IPropertyPage2**, modifique a definição da classe e substitua o método de `EditProperty` .  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPropertyPage`  
  
 [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)  
  
 `IPropertyPage2Impl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de IPerPropertyBrowsingImpl](../Topic/IPerPropertyBrowsingImpl%20Class.md)   
 [Classe de ISpecifyPropertyPagesImpl](../Topic/ISpecifyPropertyPagesImpl%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)