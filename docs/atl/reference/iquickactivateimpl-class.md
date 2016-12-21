---
title: "Classe de IQuickActivateImpl | Microsoft Docs"
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
  - "ATL::IQuickActivateImpl"
  - "ATL::IQuickActivateImpl<T>"
  - "ATL.IQuickActivateImpl"
  - "ATL.IQuickActivateImpl<T>"
  - "IQuickActivateImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ativando controles de ATL"
  - "controles [ATL], ativar"
  - "Implementação de IQuickActivate ATL"
  - "Classe de IQuickActivateImpl"
ms.assetid: aa80c056-1041-494e-b21d-2acca7dc27ea
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IQuickActivateImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe combina a inicialização do controle de recipiente em uma única chamada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template<   
class T   
>  
class ATL_NO_VTABLE IQuickActivateImpl :  
public IQuickActivate  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IQuickActivateImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IQuickActivateImpl::GetContentExtent](../Topic/IQuickActivateImpl::GetContentExtent.md)|Retorna o tamanho atual de exibição para um controle em execução.|  
|[IQuickActivateImpl::QuickActivate](../Topic/IQuickActivateImpl::QuickActivate.md)|Executa a inicialização rápido de controles que estão sendo carregados.|  
|[IQuickActivateImpl::SetContentExtent](../Topic/IQuickActivateImpl::SetContentExtent.md)|Informa o controle da quantidade de espaço de exibição o contêiner atribuído a ele.|  
  
## Comentários  
 Contêiners de ajuda de interface de [IQuickActivate](http://msdn.microsoft.com/library/windows/desktop/ms690146) evitarem atrasos quando controles de carregamento combinando a inicialização em uma única chamada.  O método de `QuickActivate` permite que o recipiente passe um ponteiro a estrutura de [QACONTAINER](http://msdn.microsoft.com/library/windows/desktop/ms688630) que contém ponteiros para todas as interfaces o controle.  O retorno, o controle passar voltam um ponteiro a estrutura de [QACONTROL](http://msdn.microsoft.com/library/windows/desktop/ms693721) que contém ponteiros para suas próprias interfaces, que são usadas pelo recipiente.  A classe `IQuickActivateImpl` fornece uma implementação padrão de **IQuickActivate** e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IQuickActivate`  
  
 `IQuickActivateImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)