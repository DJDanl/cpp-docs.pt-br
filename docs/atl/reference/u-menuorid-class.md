---
title: Classe _U_MENUorID | Microsoft Docs
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7ddde6ff5d45c90e675bd2e44ac421e840d1357b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="umenuorid-class"></a>Classe _U_MENUorID
Essa classe fornece wrappers para **CreateWindow** e **CreateWindowEx**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class _U_MENUorID
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_MENUorID::_U_MENUorID](#_u_menuorid___u_menuorid)|O construtor.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_MENUorID::m_hMenu](#_u_menuorid__m_hmenu)|Um identificador para um menu.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de adaptador do argumento permite que qualquer IDs ( **UINT**s) ou identificadores de menu ( `HMENU`s) a serem passados para uma função sem a necessidade de uma conversão explícita na parte do chamador.  
  
 Essa classe destina-se para implementar wrappers para a API do Windows, particularmente o [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) e [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) funções, que aceitam um `HMENU` argumento pode ser um filho Identificador de janela ( **UINT**) em vez de um identificador de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl::Create](cwindowimpl-class.md#create).  

  
 A classe define duas sobrecargas de construtor: um aceita um **UINT** argumento e o outro aceita um `HMENU` argumento. O **UINT** argumento apenas é convertido para um `HMENU` no construtor e o resultado armazenado no membro de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu). O argumento para o `HMENU` construtor é armazenado diretamente, sem conversão.  
  
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
