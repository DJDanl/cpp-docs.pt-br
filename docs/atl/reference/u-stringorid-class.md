---
title: Classe _U_STRINGorID
ms.date: 11/04/2016
f1_keywords:
- ATL._U_STRINGorID
- ATL::_U_STRINGorID
- _U_STRINGorID
helpviewer_keywords:
- _U_STRINGorID class
- U_STRINGorID class
ms.assetid: 443cdc00-d265-4b27-8ef3-2feb95f3e5e3
ms.openlocfilehash: c57d983e9680ce6d2cab375e427b80f4d3b6c2d6
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70739573"
---
# <a name="_u_stringorid-class"></a>Classe _U_STRINGorID

Essa classe de adaptador de argumento permite que nomes de recurso (LPCTSTRs) ou IDs de recurso (UINTs) sejam passados para uma função sem exigir que o chamador converta a ID em uma cadeia de caracteres usando a macro MAKEINTRESOURCE.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

Essa classe é projetada para implementar wrappers na API do gerenciamento de recursos do Windows, como as funções [FindResource](/windows/win32/api/winbase/nf-winbase-findresourcea), [LoadIcon](/windows/win32/api/winuser/nf-winuser-loadiconw)e [LoadMenu](/windows/win32/api/winuser/nf-winuser-loadmenuw) , que aceitam um argumento LPCTSTR que pode ser o nome de um recurso ou sua ID.

A classe define duas sobrecargas de construtor: uma aceita um argumento LPCTSTR e a outra aceita um argumento UINT. O argumento UINT é convertido em um tipo de recurso compatível com funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado armazenado no membro de dados único da classe, [m_lpstr](#_u_stringorid__m_lpstr). O argumento para o Construtor LPCTSTR é armazenado diretamente sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="_u_stringorid__m_lpstr"></a>  _U_STRINGorID::m_lpstr

A classe contém o valor passado para um de seus construtores como um membro de dados LPCTSTR público.

```
LPCTSTR m_lpstr;
```

##  <a name="_u_stringorid___u_stringorid"></a>  _U_STRINGorID::_U_STRINGorID

O Construtor UINT converte seu argumento para um tipo de recurso compatível com as funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado é armazenado no único membro de dados da classe, [m_lpstr](#_u_stringorid__m_lpstr).

```
_U_STRINGorID(UINT nID);
_U_STRINGorID(LPCTSTR lpString);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Uma ID de recurso.

*lpString*<br/>
Um nome de recurso.

### <a name="remarks"></a>Comentários

O argumento para o Construtor LPCTSTR é armazenado diretamente sem conversão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
