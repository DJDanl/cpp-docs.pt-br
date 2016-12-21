---
title: "Classe de IDispEventSimpleImpl | Microsoft Docs"
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
  - "IDispEventSimpleImpl"
  - "ATL::IDispEventSimpleImpl"
  - "ATL.IDispEventSimpleImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IDispEventSimpleImpl"
ms.assetid: 971d82b7-a921-47fa-a4d8-909bed377ab0
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IDispEventSimpleImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece implementações dos métodos de `IDispatch` , sem obter informações sobre o tipo de uma biblioteca de tipo.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template <  
UINT nID,  
class T,  
const IID* pdiid  
>  
class ATL_NO_VTABLE IDispEventSimpleImpl :  
public _IDispEventLocator<nID, pdiid>  
```  
  
#### Parâmetros  
 `nID`  
 Um identificador exclusivo para o objeto de origem.  Quando `IDispEventSimpleImpl` é a classe base para um controle composto, use o recurso de identificação do controle contido desejado para esse parâmetro.  Em outros casos, use um inteiro positivo arbitrário.  
  
 `T`  
 A classe do usuário, que é derivada de `IDispEventSimpleImpl`.  
  
 `pdiid`  
 O ponteiro ao IID de dispinterface de evento implementado por esta classe.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispEventSimpleImpl::Advise](../Topic/IDispEventSimpleImpl::Advise.md)|Estabelece uma conexão com a fonte do evento padrão.|  
|[IDispEventSimpleImpl::DispEventAdvise](../Topic/IDispEventSimpleImpl::DispEventAdvise.md)|Estabelece uma conexão com a fonte do evento.|  
|[IDispEventSimpleImpl::DispEventUnadvise](../Topic/IDispEventSimpleImpl::DispEventUnadvise.md)|Interrompe a conexão com a fonte do evento.|  
|[IDispEventSimpleImpl::GetIDsOfNames](../Topic/IDispEventSimpleImpl::GetIDsOfNames.md)|Retorna **E\_NOTIMPL**.|  
|[IDispEventSimpleImpl::GetTypeInfo](../Topic/IDispEventSimpleImpl::GetTypeInfo.md)|Retorna **E\_NOTIMPL**.|  
|[IDispEventSimpleImpl::GetTypeInfoCount](../Topic/IDispEventSimpleImpl::GetTypeInfoCount.md)|Retorna **E\_NOTIMPL**.|  
|[IDispEventSimpleImpl::Invoke](../Topic/IDispEventSimpleImpl::Invoke.md)|Chame os manipuladores de eventos listado no mapa do coletor de eventos.|  
|[IDispEventSimpleImpl::Unadvise](../Topic/IDispEventSimpleImpl::Unadvise.md)|Interrompe a conexão com a fonte do evento padrão.|  
  
## Comentários  
 `IDispEventSimpleImpl` fornece uma maneira para implementar um dispinterface de evento sem exigir que você fornecer código de implementação para cada método\/evento na interface.  `IDispEventSimpleImpl` fornece implementações dos métodos de `IDispatch` .  Você só precisará fornecer implementações para eventos que você está interessado em tratamento.  
  
 Os trabalhos de`IDispEventSimpleImpl` em conjunto com [mapa o coletor de eventos](../Topic/BEGIN_SINK_MAP.md) em sua classe para rotear eventos para o manipulador adequado funcionam.  Para usar esta classe:  
  
-   Adicione uma macro de [SINK\_ENTRY\_INFORMATION](../Topic/SINK_ENTRY_INFO.md) ao mapa o coletor de eventos para cada evento em cada objeto que você deseja manipular.  
  
-   Informações de tipo de fonte para cada evento passando um ponteiro a estrutura de [\_ATL\_FUNC\_INFORMATION](../../atl/reference/atl-func-info-structure.md) como um parâmetro para cada entrada.  Em a plataforma x, o valor de `_ATL_FUNC_INFO.cc` deve ser CC\_CDECL com o método de chamada de função de retorno de chamada de \_\_stdcall.  
  
-   Chamada [DispEventAdvise](../Topic/IDispEventSimpleImpl::DispEventAdvise.md) para estabelecer a conexão entre o objeto de origem e a classe base.  
  
-   Chamada [DispEventUnadvise](../Topic/IDispEventSimpleImpl::DispEventUnadvise.md) para interromper a conexão.  
  
 Você deve derivar de `IDispEventSimpleImpl` \(usando um valor exclusivo para `nID`\) para cada objeto para o qual você precisar manipular eventos.  Você pode reutilizar a classe base unadvising em um objeto de origem que recomendável então contra um objeto diferente de origem, mas o número máximo de objetos de origem que podem ser tratados por um único objeto ao mesmo tempo é limitado pelo número de classes base de `IDispEventSimpleImpl` .  
  
 **IDispEventSimplImpl** fornece a mesma funcionalidade que [IDispEventImpl](../../atl/reference/idispeventimpl-class.md), a não ser que não seja digite informações sobre a interface de uma biblioteca de tipo.  Os assistentes geram código baseado apenas em `IDispEventImpl`, mas você pode usar `IDispEventSimpleImpl` adicionar código à mão.  Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipo que descreve a interface de evento nem a desejar evitar a sobrecarga associada com o uso de biblioteca de tipo.  
  
> [!NOTE]
>  `IDispEventImpl` e fornecem `IDispEventSimpleImpl` sua própria implementação de **IUnknown::QueryInterface** ativando cada classe base de `IDispEventImpl` ou de `IDispEventSimpleImpl` para atuar como uma identidade separada de COM enquanto ainda permitir acesso direto a membros de classe em seu objeto COM principal.  
  
 A implementação de CE ATL de coletores de eventos ActiveX suporta apenas valores de retorno do tipo ou HRESULT de vácuo dos métodos do manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.  
  
 Para obter mais informações, consulte [Suporte IDispEventImpl](../../atl/supporting-idispeventimpl.md).  
  
## Hierarquia de herança  
 `_IDispEvent`  
  
 `_IDispEventLocator`  
  
 `IDispEventSimpleImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Estrutura de \_ATL\_FUNC\_INFORMATION](../../atl/reference/atl-func-info-structure.md)   
 [Classe de IDispatchImpl](../../atl/reference/idispatchimpl-class.md)   
 [Classe de IDispEventImpl](../../atl/reference/idispeventimpl-class.md)   
 [SINK\_ENTRY\_INFORMATION](../Topic/SINK_ENTRY_INFO.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)