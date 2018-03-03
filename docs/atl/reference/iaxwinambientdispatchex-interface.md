---
title: Interface IAxWinAmbientDispatchEx | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAxWinAmbientDispatchEx
- ATLIFACE/ATL::IAxWinAmbientDispatchEx
- ATLIFACE/ATL::SetAmbientDispatch
dev_langs:
- C++
helpviewer_keywords:
- IAxWinAmbientDispatchEx interface
ms.assetid: 2c25e079-6128-4278-bc72-b2c6195ba7ef
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3fd212417a00335bfc02699cf5e38eeacc6451ad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iaxwinambientdispatchex-interface"></a>Interface IAxWinAmbientDispatchEx
Essa interface implementa propriedades de ambiente complementares para um controle hospedado.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
 Inclua essa interface em aplicativos de ATL que estão vinculados estaticamente a ATL e host controles ActiveX, especialmente os controles ActiveX que têm propriedades de ambiente. Não incluir essa interface irá gerar essa asserção: "Você esqueceu de passar a ID da biblioteca para CComModule"  
  
 Essa interface é exposta pelo controle ActiveX do ATL objetos de hospedagem. Derivado [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md), `IAxWinAmbientDispatchEx` adiciona um método que permite complementar a interface de propriedade de ambiente fornecida pelo ATL com uma de sua preferência.  
  
 [AXHost](https://msdn.microsoft.com/library/system.windows.forms.axhost.aspx) tentará carregar as informações de tipo sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` na biblioteca de tipos que contém o código.  
  
 Se você está vinculando ATL90.dll, **AXHost** carregará o tipo de informação da biblioteca de tipo na DLL.  
  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível em um número de formulários, como mostrado na tabela a seguir.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|atliface.idl|  
|Biblioteca de tipos|ATL.dll|  
|C++|atliface (também é incluído no atlbase)|  
  
##  <a name="setambientdispatch"></a>IAxWinAmbientDispatchEx::SetAmbientDispatch  
 Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.  
  
```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDispatch*  
 Ponteiro para a nova interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usado para invocar qualquer propriedades ou métodos solicitados pelo controle hospedado, se essas propriedades já não são fornecidas pela [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).  
  
## <a name="see-also"></a>Consulte também  
 [Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)
