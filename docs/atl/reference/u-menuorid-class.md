---
title: Classe _U_MENUorID | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL._U_MENUorID
- ATL::_U_MENUorID
- _U_MENUorID
dev_langs:
- C++
helpviewer_keywords:
- U_MENUorID class
- _U_MENUorID class
ms.assetid: cfc8032b-61b4-4a68-ba3a-92b82500ccae
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: f7c0a5c34c4e103f830a029f58cdfa00dcb58a32
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="umenuorid-class"></a>Classe _U_MENUorID
Essa classe fornece wrappers para **CreateWindow** e **CreateWindowEx**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class _U_MENUorID
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_MENUorID::_U_MENUorID](#_u_menuorid___u_menuorid)|O construtor.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_MENUorID::m_hMenu](#_u_menuorid__m_hmenu)|Um identificador para um menu.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de adaptador do argumento permite que qualquer um dos IDs ( **UINT**s) ou identificadores de menu ( `HMENU`s) a serem passados para uma função sem exigir uma conversão explícita na parte do chamador.  
  
 Essa classe foi projetada para a implementação de invólucros para a API do Windows, principalmente o [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) e [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) funções, dos quais aceitam um `HMENU` argumento pode ser um identificador de janela filho ( **UINT**) em vez de um identificador de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl::Create](cwindowimpl-class.md#create).  

  
 A classe define duas sobrecargas de construtor: uma aceita um **UINT** argumento e o outro aceita um `HMENU` argumento. O **UINT** argumento apenas é convertido para um `HMENU` no construtor e o resultado armazenado no membro de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu). O argumento para o `HMENU` construtor é armazenado diretamente, sem conversão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="_u_menuorid__m_hmenu"></a>_U_MENUorID::m_hMenu  
 A classe contém o valor passado para qualquer um dos seus construtores como pública `HMENU` membro de dados.  
  
```
HMENU m_hMenu;
```  
  
##  <a name="_u_menuorid___u_menuorid"></a>_U_MENUorID::_U_MENUorID  
 O **UINT** argumento apenas é convertido para um `HMENU` no construtor e o resultado armazenado no membro de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu).  
  
```
_U_MENUorID(UINT nID);  
_U_MENUorID(HMENU hMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Um identificador de janela filho.  
  
 `hMenu`  
 Um identificador de menu.  
  
### <a name="remarks"></a>Comentários  
 O argumento para o `HMENU` construtor é armazenado diretamente, sem conversão.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

