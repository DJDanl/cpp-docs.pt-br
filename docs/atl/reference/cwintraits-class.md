---
title: Classe CWinTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CWinTraits
- ATLWIN/ATL::CWinTraits
- ATLWIN/ATL::CWinTraits::GetWndExStyle
- ATLWIN/ATL::CWinTraits::GetWndStyle
dev_langs:
- C++
helpviewer_keywords:
- CMDIChildWinTraits class
- window styles, default values for ATL
- CWinTraits class
- CFrameWinTraits class
- CControlWinTraits class
ms.assetid: f78f486e-6d9c-42c6-8e86-371e05aa7e59
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea1eafc6376c44a09d13fb513d41f222048708d9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32362502"
---
# <a name="cwintraits-class"></a>Classe CWinTraits
Essa classe fornece um método para padronizar os estilos usados ao criar um objeto de janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <DWORD t_dwStyle = 0, DWORD t_dwExStyle = 0>  class CWinTraits
```  
  
#### <a name="parameters"></a>Parâmetros  
 `t_dwStyle`  
 Estilos de janela padrão do padrão.  
  
 `t_dwExStyle`  
 Estilos de janela estendidos padrão.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinTraits::GetWndExStyle](#getwndexstyle)|(Estático) Recupera os estilos estendidos para o `CWinTraits` objeto.|  
|[CWinTraits::GetWndStyle](#getwndstyle)|(Estático) Recupera os estilos padrão para o `CWinTraits` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Isso [características de janela](../../atl/understanding-window-traits.md) classe fornece um método simples para padronizar os estilos usados para a criação de um objeto de janela ATL. Use uma especialização dessa classe como um parâmetro de modelo para [CWindowImpl](../../atl/reference/cwindowimpl-class.md) ou outro de classes de janela da ATL para especificar os estilos de padrão e estendido do padrão usados para instâncias dessa classe de janela.  
  
 Use este modelo quando desejar fornecer padrão estilos de janela que serão usados somente quando nenhum outro estilo é especificado na chamada para [CWindowImpl::Create](../../atl/reference/cwindowimpl-class.md#create).  
  
 ATL fornece três especializações predefinidas desse modelo para usadas geral combinações de estilos de janela:  
  
 `CControlWinTraits`  
 Projetado para uma janela de controle padrão. Os seguintes estilos padrão são usados: **WS_CHILD**, **WS_VISIBLE**, **WS_CLIPCHILDREN**, e **WS_CLIPSIBLINGS**. Não há nenhum estilo estendido.  
  
 `CFrameWinTraits`  
 Projetado para uma janela do quadro padrão. Os estilos padrão usados incluem: **WS_OVERLAPPEDWINDOW**, **WS_CLIPCHILDREN**, e **WS_CLIPSIBLINGS**. Os estilos estendidos usados incluem: **WS_EX_APPWINDOW** e **WS_EX_WINDOWEDGE**.  
  
 `CMDIChildWinTraits`  
 Projetado para uma janela padrão do filho MDI. Os estilos padrão usados incluem: **WS_OVERLAPPEDWINDOW**, **WS_CHILD**, **WS_VISIBLE**, **WS_CLIPCHILDREN**e **WS_CLIPSIBLINGS**. Os estilos estendidos usados incluem: **WS_EX_MDICHILD**.  
  
 Se você quiser garantir que determinados estilos estejam definidos para todas as instâncias da classe de janela ao permitir que outros estilos a ser definido em uma base por instância, use [CWinTraitsOR](../../atl/reference/cwintraitsor-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="getwndstyle"></a>  CWinTraits::GetWndStyle  
 Chamar essa função para recuperar os estilos padrão do `CWinTraits` objeto.  
  
```
static DWORD GetWndStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Estilos padrão usados para a criação de uma janela. Se `dwStyle` é 0, os valores de estilo do modelo ( `t_dwStyle`) são retornados. Se `dwStyle` é diferente de zero, `dwStyle` será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Os estilos de janela padrão do objeto.  
  
##  <a name="getwndexstyle"></a>  CWinTraits::GetWndExStyle  
 Chamar essa função para recuperar os estilos estendidos do `CWinTraits` objeto.  
  
```
static DWORD GetWndExStyle(DWORD dwExStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Estilos estendidos usados para a criação de uma janela. Se `dwExStyle` é 0, os valores de estilo do modelo ( `t_dwExStyle`) são retornados. Se `dwExStyle` é diferente de zero, `dwExStyle` será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Os estilos de janela estendidos do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Membros de classe](http://msdn.microsoft.com/en-us/dbe6a147-3f01-4aea-a3fb-fe6ebadc31f8)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Noções básicas sobre as características da janela](../../atl/understanding-window-traits.md)
