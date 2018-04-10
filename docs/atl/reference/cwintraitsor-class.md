---
title: Classe CWinTraitsOR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR
- ATLWIN/ATL::CWinTraitsOR::GetWndExStyle
- ATLWIN/ATL::CWinTraitsOR::GetWndStyle
dev_langs:
- C++
helpviewer_keywords:
- CWinTraitsOR class
- window styles, default values for ATL
ms.assetid: 1eb7b1e8-a9bd-411b-a30a-35a8a10af989
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ac6cf07fcd6d3703ffb6b483ba19a2d12520cb0a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cwintraitsor-class"></a>Classe CWinTraitsOR
Essa classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <DWORD t_dwStyle = 0,
          DWORD t_dwExStyle = 0, 
          class TWinTraits = CControlWinTraits>
class CWinTraitsOR
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_dwStyle`  
 Estilos de janela padrão.  
  
 `t_dwExStyle`  
 Estilos de janela estendidos padrão.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinTraitsOR::GetWndExStyle](#getwndexstyle)|Recupera os estilos estendidos para o `CWinTraitsOR` objeto.|  
|[CWinTraitsOR::GetWndStyle](#getwndstyle)|Recupera os estilos padrão para o `CWinTraitsOR` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Isso [características de janela](../../atl/understanding-window-traits.md) classe fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Use uma especialização dessa classe como um parâmetro de modelo para [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outro de classes de janela da ATL para especificar o conjunto mínimo de estilos padrão e estendidos a ser usado para instâncias dessa classe de janela.  
  
 Use uma especialização deste modelo, se você deseja garantir que determinados estilos estejam definidos para todas as instâncias da classe de janela ao permitir que outros estilos a ser definido em uma base por instância na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).  
  
 Se você quiser fornecer padrão estilos de janela que serão usados somente quando nenhum outro estilo é especificado na chamada para `CWindowImpl::Create`, use [CWinTraits](../../atl/reference/cwintraits-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="getwndstyle"></a>CWinTraitsOR::GetWndStyle  
 Chamar essa função para recuperar uma combinação (usando o operador lógico OR) dos estilos de padrão de `CWinTraits` objeto e os estilos padrão especificados pelo `t_dwStyle`.  
  
```
static DWORD GetWndStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Estilos usados para a criação de uma janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos que são transmitidos `dwStyle` e o padrão que aqueles especificados por `t_dwStyle`, usando o operador lógico OR.  
  
##  <a name="getwndexstyle"></a>CWinTraitsOR::GetWndExStyle  
 Chamar essa função para recuperar uma combinação (usando o operador lógico OR) dos estilos estendidos do `CWinTraits` objeto e os estilos padrão especificados pelo `t_dwStyle`.  
  
```
static DWORD GetWndExStyle(DWORD dwExStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Estilos estendidos usados para a criação de uma janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos estendidos que são transmitidos `dwExStyle` e o padrão especificado pelo `t_dwExStyle`, usando o operador lógico OR  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Noções básicas sobre as características da janela](../../atl/understanding-window-traits.md)

