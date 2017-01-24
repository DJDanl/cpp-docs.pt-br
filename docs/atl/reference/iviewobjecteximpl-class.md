---
title: "Classe de IViewObjectExImpl | Microsoft Docs"
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
  - "ATL::IViewObjectExImpl<T>"
  - "ATL.IViewObjectExImpl"
  - "ATL::IViewObjectExImpl"
  - "ATL.IViewObjectExImpl<T>"
  - "IViewObjectExImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], desenhar"
  - "seja recomendável dissipadores"
  - "Implementação de IViewObjectEx ATL"
  - "Classe de IViewObjectExImpl"
ms.assetid: ad6de760-1ee5-4883-b033-ae57beffc369
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IViewObjectExImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e fornece implementações padrão das interfaces de [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), de [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e de [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template<  
class T   
>  
class ATL_NO_VTABLE IViewObjectExImpl :  
public IViewObjectEx  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IViewObjectExImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IViewObjectExImpl::Draw](../Topic/IViewObjectExImpl::Draw.md)|Desenha uma representação do controle em um contexto de dispositivo.|  
|[IViewObjectExImpl::Freeze](../Topic/IViewObjectExImpl::Freeze.md)|Congelasse uma representação desenhada de um controle para não sofrerá alterações até `Unfreeze`.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IViewObjectExImpl::GetAdvise](../Topic/IViewObjectExImpl::GetAdvise.md)|Recupera uma conexão existente consultiva coletora no controle, se houver um.|  
|[IViewObjectExImpl::GetColorSet](../Topic/IViewObjectExImpl::GetColorSet.md)|Retorna a paleta lógica usada pelo controle de desenho.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IViewObjectExImpl::GetExtent](../Topic/IViewObjectExImpl::GetExtent.md)|Retorna o tamanho de exibição de controle em unidades de HIMETRIC mm \(0,01\) por unidade de membro [CComControlBase::m\_sizeExtent](../Topic/CComControlBase::m_sizeExtent.md)de dados da classe do controle.|  
|[IViewObjectExImpl::GetNaturalExtent](../Topic/IViewObjectExImpl::GetNaturalExtent.md)|Fornece dicas de dimensionamento do contêiner para o objeto para usar como o usuário redimensiona.|  
|[IViewObjectExImpl::GetRect](../Topic/IViewObjectExImpl::GetRect.md)|Retorna um retângulo que descreve um aspecto desenhando aplicativo.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IViewObjectExImpl::GetViewStatus](../Topic/IViewObjectExImpl::GetViewStatus.md)|Returns informações sobre a opacidade do objeto e que aspectos de desenho são suportados.|  
|[IViewObjectExImpl::QueryHitPoint](../Topic/IViewObjectExImpl::QueryHitPoint.md)|Verifica se o ponto especificado está no retângulo especificado e retorna um valor de [HITRESULT](http://msdn.microsoft.com/library/windows/desktop/ms682187) em `pHitResult`.|  
|[IViewObjectExImpl::QueryHitRect](../Topic/IViewObjectExImpl::QueryHitRect.md)|Verifica se o retângulo de exibição de controle sobrepostos qualquer ponto no retângulo do local especificado e retorna um valor de **HITRESULT** em `pHitResult`.|  
|[IViewObjectExImpl::SetAdvise](../Topic/IViewObjectExImpl::SetAdvise.md)|Configura de uma conexão entre o controle e o coletor do que o coletor conselhos pode ser notificado sobre alterações no modo do controle.|  
|[IViewObjectExImpl::Unfreeze](../Topic/IViewObjectExImpl::Unfreeze.md)|Descongela a representação desenhada do controle.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 As interfaces de [IViewObject](http://msdn.microsoft.com/library/windows/desktop/ms680763), de [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318), e de [IViewObjectEx](http://msdn.microsoft.com/library/windows/desktop/ms682375) permitem que um controle para exibir\-se diretamente, e para criar e gerenciar um coletor de conselhos o recipiente para notificar as alterações na exibição do controle.  A interface de **IViewObjectEx** fornece suporte para recursos estendidos do controle como o desenho cintilação\- livre, controles não retangulares e transparente, e teste \(por exemplo, como fechar um clique do mouse deve deve ser considerada no controle\).  A classe `IViewObjectExImpl` fornece uma implementação padrão de essas interfaces e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
## Hierarquia de herança  
 `IViewObjectEx`  
  
 `IViewObjectExImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [ActiveX Controls Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Tutorial](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)   
 [Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)