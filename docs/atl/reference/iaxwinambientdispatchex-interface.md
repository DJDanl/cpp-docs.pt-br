---
title: Interface IAxWinAmbientDispatchEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAxWinAmbientDispatchEx
- No header/ATL::IAxWinAmbientDispatchEx
- No header/ATL::SetAmbientDispatch
dev_langs:
- C++
helpviewer_keywords:
- IAxWinAmbientDispatchEx interface
ms.assetid: 2c25e079-6128-4278-bc72-b2c6195ba7ef
caps.latest.revision: 25
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 915514a021aa89b751a49a34cb53b693b9fd0c45
ms.lasthandoff: 02/25/2017

---
# <a name="iaxwinambientdispatchex-interface"></a>Interface IAxWinAmbientDispatchEx
Essa interface implementa propriedades complementares para um controle hospedado do ambiente.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
MIDL_INTERFACE("B2D0778B - AC99 - 4c58 - A5C8 - E7724E5316B5") IAxWinAmbientDispatchEx : public IAxWinAmbientDispatch
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[SetAmbientDispatch](#setambientdispatch)|Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.|  
  
## <a name="remarks"></a>Comentários  
 Inclua essa interface em aplicativos de ATL estaticamente vinculadas para ATL e hospedar controles ActiveX, especialmente os controles ActiveX que têm propriedades do ambiente. Não incluir essa interface gerará esta declaração: "Você esqueceu de passar o ID da biblioteca para CComModule"  
  
 Essa interface é exposta pelo controle ActiveX do ATL que objetos de hospedagem. Derivado de [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite complementar a interface de propriedade de ambiente fornecida pelo ATL com sua própria.  
  
 [AXHost](https://msdn.microsoft.com/library/system.windows.forms.axhost.aspx) tentará carregar informações de tipo sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` da biblioteca de tipos que contém o código.  
  
 Se você está vinculando ATL90.dll, **AXHost** carregará o tipo de informação da biblioteca de tipos na DLL.  
  
 Consulte [de hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível em um número de formulários, conforme mostrado na tabela a seguir.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|atliface.idl|  
|Biblioteca de Tipos|ATL.dll|  
|C++|atliface (também incluído no atlbase. H)|  
  
##  <a name="setambientdispatch"></a>IAxWinAmbientDispatchEx::SetAmbientDispatch  
 Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.  
  
```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDispatch*  
 Ponteiro para a nova interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usado para invocar qualquer propriedades ou métodos solicitados pelos controle hospedado, se essas propriedades já não são fornecidas pela [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).  
  
## <a name="see-also"></a>Consulte também  
 [Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)

