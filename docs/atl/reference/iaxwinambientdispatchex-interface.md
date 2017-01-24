---
title: "Interface de IAxWinAmbientDispatchEx | Microsoft Docs"
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
  - "ATL.IAxWinAmbientDispatchEx"
  - "IAxWinAmbientDispatchEx"
  - "ATL::IAxWinAmbientDispatchEx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IAxWinAmbientDispatchEx"
ms.assetid: 2c25e079-6128-4278-bc72-b2c6195ba7ef
caps.latest.revision: 25
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de IAxWinAmbientDispatchEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa interface implementa propriedades de ambiente suplementares para um controle hospedado.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      MIDL_INTERFACE( "B2D0778B - AC99 - 4c58 - A5C8 - E7724E5316B5" )  
IAxWinAmbientDispatchEx : public IAxWinAmbientDispatch  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[SetAmbientDispatch](../Topic/IAxWinAmbientDispatchEx::SetAmbientDispatch.md)|Este método é chamado para complementar a interface de ambiente de propriedade padrão com uma interface definida pelo usuário.|  
  
## Comentários  
 Inclua essa interface em aplicativos que são associados a ATL estaticamente e hospedarem controles ActiveX, especialmente os controles de ATL ActiveX que têm propriedades de ambiente.  Não incluir essa interface gerará essa declaração: “Você tiver esquecido passar o LIBID a CComModule::Init?”  
  
 Essa interface é exposta pelo controle ActiveX de ATL que hospeda objetos.  Derivado de [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite que você suplemente a interface de ambiente de propriedade fornecida por ATL com um de seus próprios.  
  
 [AXHost](https://msdn.microsoft.com/en-us/library/system.windows.forms.axhost.aspx) tentará carregar digite informações sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` da biblioteca de tipos que contém o código.  
  
 Se você estiver vinculando a ATL90.dll, **AXHost** carregará informações de tipo de biblioteca de tipo no DLL.  
  
 Consulte [Hospedando controles ActiveX usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.  
  
## Requisitos  
 A definição de essa interface está disponível em um número de formulários, conforme mostrado na tabela.  
  
|Definição de tipo|File|  
|-----------------------|----------|  
|IDL|atliface.idl|  
|Biblioteca de tipo|ATL.dll|  
|C\+\+|atliface.h \(também incluído em ATLBase.h\)|  
  
## Consulte também  
 [Interface de IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)