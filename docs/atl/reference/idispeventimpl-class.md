---
title: "Classe de IDispEventImpl | Microsoft Docs"
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
  - "IDispEventImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IDispEventImpl"
ms.assetid: a64b5288-35cb-4638-aad6-2d15b1c7cf7b
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IDispEventImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece implementações dos métodos de `IDispatch` .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template <  
UINT nID,  
class T,  
const IID* pdiid= &IID_NULL,  
const GUID* plibid= &GUID_NULL,  
WORD wMajor= 0,  
WORD wMinor= 0,  
class tihclass= CcomTypeInfoHolder  
>  
class ATL_NO_VTABLE IDispEventImpl :  
public IDispEventSimpleImpl<nID, T, pdiid>  
```  
  
#### Parâmetros  
 `nID`  
 Um identificador exclusivo para o objeto de origem.  Quando `IDispEventImpl` é a classe base para um controle composto, use o recurso de identificação do controle contido desejado para esse parâmetro.  Em outros casos, use um inteiro positivo arbitrário.  
  
 `T`  
 A classe do usuário, que é derivada de `IDispEventImpl`.  
  
 `pdiid`  
 O ponteiro ao IID de dispinterface de evento implementado por esta classe.  Essa interface deve ser definida na biblioteca de tipos denotada por `plibid`, por `wMajor`, e por `wMinor`.  
  
 `plibid`  
 Um ponteiro para biblioteca de tipo que define a interface de distribuição apontado por `pdiid`.  Se **&GUID\_NULL**, a biblioteca de tipos será carregado objeto de fonte de eventos.  
  
 `wMajor`  
 A versão principal de biblioteca de tipo.  o valor padrão é 0.  
  
 `wMinor`  
 A versão secundária de biblioteca de tipo.  o valor padrão é 0.  
  
 `tihclass`  
 A classe usada para gerenciar informações de tipo para `T`.  o valor padrão é uma classe de tipo `CComTypeInfoHolder`; no entanto, você pode substituir esse parâmetro do modelo fornecendo uma classe de um tipo diferente `CComTypeInfoHolder`.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispEventImpl::\_tihclass](../../atl/reference/idispeventimpl-class.md)|A classe usada para gerenciar informações do tipo.  Por padrão, `CComTypeInfoHolder`.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispEventImpl::IDispEventImpl](../Topic/IDispEventImpl::IDispEventImpl.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispEventImpl::GetFuncInfoFromId](../Topic/IDispEventImpl::GetFuncInfoFromId.md)|Fica o índice de função especificado para o identificador de distribuição.|  
|[IDispEventImpl::GetIDsOfNames](../Topic/IDispEventImpl::GetIDsOfNames.md)|Mapeia um único membro e um conjunto opcional de nomes de argumentos correspondente a um conjunto inteiro DISPIDs.|  
|[IDispEventImpl::GetTypeInfo](../Topic/IDispEventImpl::GetTypeInfo.md)|Recupera informações de tipo para um objeto.|  
|[IDispEventImpl::GetTypeInfoCount](../Topic/IDispEventImpl::GetTypeInfoCount.md)|Retorna o número de interfaces de informações de tipo.|  
|[IDispEventImpl::GetUserDefinedType](../Topic/IDispEventImpl::GetUserDefinedType.md)|Recupera o tipo básico de um tipo definido pelo usuário.|  
  
## Comentários  
 `IDispEventImpl` fornece uma maneira para implementar um dispinterface de evento sem exigir que você fornecer código de implementação para cada método\/evento na interface.  `IDispEventImpl` fornece implementações dos métodos de `IDispatch` .  Você só precisará fornecer implementações para eventos que você está interessado em tratamento.  
  
 Os trabalhos de`IDispEventImpl` em conjunto com [mapa o coletor de eventos](../Topic/BEGIN_SINK_MAP.md) em sua classe para rotear eventos para o manipulador adequado funcionam.  Para usar esta classe:  
  
 Adicione uma macro de [SINK\_ENTRY](../Topic/SINK_ENTRY.md) ou de [SINK\_ENTRY\_EX](../Topic/SINK_ENTRY_EX.md) ao mapa o coletor de eventos para cada evento em cada objeto que você deseja manipular.  A o usar `IDispEventImpl` como uma classe base de um controle composto, você pode chamar [AtlAdviseSinkMap](../Topic/AtlAdviseSinkMap.md) para estabelecer a conexão e entrar com fontes de eventos para todas as entradas no mapa do coletor de eventos.  Em outros casos, ou para maior controle, chame [DispEventAdvise](../Topic/IDispEventSimpleImpl::DispEventAdvise.md) para estabelecer a conexão entre o objeto de origem e a classe base.  Chamada [DispEventUnadvise](../Topic/IDispEventSimpleImpl::DispEventUnadvise.md) para interromper a conexão.  
  
 Você deve derivar de `IDispEventImpl` \(usando um valor exclusivo para `nID`\) para cada objeto para o qual você precisar manipular eventos.  Você pode reutilizar a classe base unadvising em um objeto de origem que recomendável então contra um objeto diferente de origem, mas o número máximo de objetos de origem que podem ser tratados por um único objeto ao mesmo tempo é limitado pelo número de classes base de `IDispEventImpl` .  
  
 `IDispEventImpl` fornece a mesma funcionalidade que [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md), a não ser que obtém informações de tipo na interface de uma biblioteca de tipos em vez de ter a fornecido como um ponteiro a estrutura de [\_ATL\_FUNC\_INFORMATION](../../atl/reference/atl-func-info-structure.md) .  Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipo que descreve a interface de evento nem a desejar evitar a sobrecarga associada com o uso de biblioteca de tipo.  
  
> [!NOTE]
>  `IDispEventImpl` e fornecem `IDispEventSimpleImpl` sua própria implementação de **IUnknown::QueryInterface** ativando cada classe base de `IDispEventImpl` e de `IDispEventSimpleImpl` para atuar como uma identidade separada de COM enquanto ainda permitir acesso direto a membros de classe em seu objeto COM principal.  
  
 A implementação de CE ATL de coletores de eventos ActiveX suporta apenas valores de retorno do tipo ou HRESULT de vácuo dos métodos do manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.  
  
 Para obter mais informações, consulte [Suporte IDispEventImpl](../../atl/supporting-idispeventimpl.md).  
  
## Hierarquia de herança  
 `_IDispEvent`  
  
 `_IDispEventLocator`  
  
 [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)  
  
 `IDispEventImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Estrutura de \_ATL\_FUNC\_INFORMATION](../../atl/reference/atl-func-info-structure.md)   
 [Classe de IDispatchImpl](../../atl/reference/idispatchimpl-class.md)   
 [Classe de IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)   
 [SINK\_ENTRY](../Topic/SINK_ENTRY.md)   
 [SINK\_ENTRY\_EX](../Topic/SINK_ENTRY_EX.md)   
 [SINK\_ENTRY\_INFORMATION](../Topic/SINK_ENTRY_INFO.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)