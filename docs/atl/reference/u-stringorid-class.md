---
title: Classe u_stringorid
ms.date: 11/04/2016
f1_keywords:
- ATL._U_STRINGorID
- ATL::_U_STRINGorID
- _U_STRINGorID
helpviewer_keywords:
- _U_STRINGorID class
- U_STRINGorID class
ms.assetid: 443cdc00-d265-4b27-8ef3-2feb95f3e5e3
ms.openlocfilehash: 4e6c086f9d2ff4061c6404444a3b4c61dd91fe1c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62197107"
---
# <a name="ustringorid-class"></a>Classe u_stringorid

Essa classe de adaptador do argumento permite que os nomes de recursos (LPCTSTRs) ou IDs de recurso (unidades) a serem passados para uma função sem exigir que o chamador converter a ID em uma cadeia de caracteres usando a macro MAKEINTRESOURCE.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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

Essa classe é projetada para a implementação de invólucros para a API de gerenciamento do recurso, no Windows, como o [FindResource](/windows/desktop/api/winbase/nf-winbase-findresourcea), [LoadIcon](/windows/desktop/api/winuser/nf-winuser-loadicona), e [LoadMenu](/windows/desktop/api/winuser/nf-winuser-loadmenua) funções que aceitam um argumento LPCTSTR que pode ser o nome de um recurso ou sua ID.

A classe define duas sobrecargas de construtor: uma aceita um argumento LPCTSTR e o outra aceita um argumento UINT. O argumento UINT é convertido em um tipo de recurso compatível com funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado armazenado no membro de dados único da classe, [m_lpstr](#_u_stringorid__m_lpstr). O argumento para o construtor LPCTSTR é armazenado diretamente, sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="_u_stringorid__m_lpstr"></a>  _U_STRINGorID::m_lpstr

A classe armazena o valor passado para qualquer um dos seus construtores como um membro de dados LPCTSTR público.

```
LPCTSTR m_lpstr;
```

##  <a name="_u_stringorid___u_stringorid"></a>  _U_STRINGorID::_U_STRINGorID

O construtor UINT converte seu argumento em um tipo de recurso compatível com funções de gerenciamento de recursos do Windows usando a macro MAKEINTRESOURCE e o resultado é armazenado no membro de dados único da classe, [m_lpstr](#_u_stringorid__m_lpstr).

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

O argumento para o construtor LPCTSTR é armazenado diretamente, sem conversão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
