---
title: classe _U_STRINGorID
ms.date: 11/04/2016
f1_keywords:
- ATL._U_STRINGorID
- ATL::_U_STRINGorID
- _U_STRINGorID
helpviewer_keywords:
- _U_STRINGorID class
- U_STRINGorID class
ms.assetid: 443cdc00-d265-4b27-8ef3-2feb95f3e5e3
ms.openlocfilehash: 4e46ceec077b8daf8ef2a76110d2fc19dd39ae26
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325819"
---
# <a name="_u_stringorid-class"></a>classe _U_STRINGorID

Essa classe de adaptador de argumento permite que nomes de recursos (LPCTSTRs) ou IDs de recursos (UINTs) sejam passados para uma função sem exigir que o chamador converta o ID em uma string usando a macro MAKEINTRESOURCE.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class _U_STRINGorID
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_STRINGorID:_U_STRINGorID](#_u_stringorid___u_stringorid)|O construtor.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[_U_STRINGorID::m_lpstr](#_u_stringorid__m_lpstr)|O identificador de recursos.|

## <a name="remarks"></a>Comentários

Esta classe foi projetada para implementar invólucros na API de gerenciamento de recursos do Windows, como as funções [FindResource,](/windows/win32/api/winbase/nf-winbase-findresourcea) [LoadIcon](/windows/win32/api/winuser/nf-winuser-loadiconw)e [LoadMenu,](/windows/win32/api/winuser/nf-winuser-loadmenuw) que aceitam um argumento LPCTSTR que pode ser o nome de um recurso ou seu ID.

A classe define duas sobrecargas de construtores: uma aceita um argumento LPCTSTR e a outra aceita um argumento UINT. O argumento UINT é convertido em um tipo de recurso compatível com as funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado armazenado no membro único de dados da classe, [m_lpstr](#_u_stringorid__m_lpstr). O argumento para o construtor LPCTSTR é armazenado diretamente sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="_u_stringoridm_lpstr"></a><a name="_u_stringorid__m_lpstr"></a>_U_STRINGorID::m_lpstr

A classe detém o valor repassado a qualquer um de seus construtores como membro público de dados LPCTSTR.

```
LPCTSTR m_lpstr;
```

## <a name="_u_stringorid_u_stringorid"></a><a name="_u_stringorid___u_stringorid"></a>_U_STRINGorID:_U_STRINGorID

O construtor UINT converte seu argumento em um tipo de recurso compatível com as funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado é armazenado no membro único de dados da classe, [m_lpstr](#_u_stringorid__m_lpstr).

```
_U_STRINGorID(UINT nID);
_U_STRINGorID(LPCTSTR lpString);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Uma id de recurso.

*Lpstring*<br/>
Um nome de recurso.

### <a name="remarks"></a>Comentários

O argumento para o construtor LPCTSTR é armazenado diretamente sem conversão.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
