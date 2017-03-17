---
title: Classe CWinTraitsOR | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
ms.openlocfilehash: cd077c7f79c3099d0e825a48233e7a8b269c0d04
ms.lasthandoff: 02/25/2017

---
# <a name="cwintraitsor-class"></a>Classe CWinTraitsOR
Essa classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
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
 Isso [características de janela](../../atl/understanding-window-traits.md) classe fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Use uma especialização da classe como um parâmetro de modelo [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outra das classes de janela da ATL para especificar o conjunto mínimo de estilos padrão e estendidos a ser usado para instâncias dessa classe de janela.  
  
 Use uma especialização do modelo se você quiser garantir que determinados estilos estejam definidos para todas as instâncias da classe de janela ao permitir que outros estilos a ser definido em uma base por instância na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).  
  
 Se você quiser fornecer padrão estilos de janela que serão usados somente quando não há outros estilos são especificados na chamada para `CWindowImpl::Create`, use [CWinTraits](../../atl/reference/cwintraits-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="getwndstyle"></a>CWinTraitsOR::GetWndStyle  
 Chame essa função para recuperar uma combinação (usando o operador lógico OR) os estilos padrão da `CWinTraits` objeto e os estilos padrão especificados por `t_dwStyle`.  
  
```
static DWORD GetWndStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Estilos usados para a criação de uma janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos que são passados em `dwStyle` e o padrão que aqueles especificados por `t_dwStyle`, usando o operador OR lógico.  
  
##  <a name="getwndexstyle"></a>CWinTraitsOR::GetWndExStyle  
 Chame essa função para recuperar uma combinação (usando o operador lógico OR) os estilos estendidos do `CWinTraits` objeto e os estilos padrão especificados por `t_dwStyle`.  
  
```
static DWORD GetWndExStyle(DWORD dwExStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Estilos estendidos usados para a criação de uma janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de estilos estendidos que são passados em `dwExStyle` e o padrão especificado por `t_dwExStyle`, usando o operador OR lógico  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Noções básicas sobre as características de janela](../../atl/understanding-window-traits.md)


