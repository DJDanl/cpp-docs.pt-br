---
title: Classe _U_STRINGorID | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL._U_STRINGorID
- ATL::_U_STRINGorID
- _U_STRINGorID
dev_langs:
- C++
helpviewer_keywords:
- _U_STRINGorID class
- U_STRINGorID class
ms.assetid: 443cdc00-d265-4b27-8ef3-2feb95f3e5e3
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: b02d539ae2a067c015988a847407bf631b6e8c1a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="ustringorid-class"></a>Classe _U_STRINGorID
Esta classe de adaptador do argumento permite que qualquer um dos nomes de recursos ( `LPCTSTR`s) ou IDs de recurso ( **UINT**s) a serem passados para uma função sem exigir que o chamador converter a ID em uma cadeia de caracteres usando o **MAKEINTRESOURCE** macro.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class _U_STRINGorID
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_STRINGorID::_U_STRINGorID](#_u_stringorid___u_stringorid)|O construtor.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[_U_STRINGorID::m_lpstr](#_u_stringorid__m_lpstr)|O identificador de recurso.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe destina-se para implementar wrappers para a API do gerenciamento de recursos do Windows, como o [FindResource](http://msdn.microsoft.com/library/windows/desktop/ms648042), [LoadIcon](http://msdn.microsoft.com/library/windows/desktop/ms648072), e [LoadMenu](http://msdn.microsoft.com/library/windows/desktop/ms647990) funções, que aceitam um `LPCTSTR` argumento pode ser o nome de um recurso ou sua ID.  
  
 A classe define duas sobrecargas de construtor: um aceita um `LPCTSTR` argumento e o outro aceita um **UINT** argumento. O **UINT** argumento é convertido em um tipo de recurso compatível com as funções de gerenciamento de recursos do Windows usando o **MAKEINTRESOURCE** macro e o resultado armazenado no membro de dados da classe, [m_lpstr](#_u_stringorid__m_lpstr). O argumento para o `LPCTSTR` construtor é armazenado diretamente, sem conversão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="_u_stringorid__m_lpstr"></a>_U_STRINGorID::m_lpstr  
 A classe contém o valor passado para qualquer um dos seus construtores como pública `LPCTSTR` membro de dados.  
  
```
LPCTSTR m_lpstr;
```  
  
##  <a name="_u_stringorid___u_stringorid"></a>_U_STRINGorID::_U_STRINGorID  
 O **UINT** construtor converte o argumento para um tipo de recurso compatível com as funções de gerenciamento de recursos do Windows usando o **MAKEINTRESOURCE** macro e o resultado é armazenado em único da classe membro de dados, [m_lpstr](#_u_stringorid__m_lpstr).  
  
```
_U_STRINGorID(UINT nID);  
_U_STRINGorID(LPCTSTR lpString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Uma ID de recurso.  
  
 `lpString`  
 Um nome de recurso.  
  
### <a name="remarks"></a>Comentários  
 O argumento para o `LPCTSTR` construtor é armazenado diretamente, sem conversão.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

