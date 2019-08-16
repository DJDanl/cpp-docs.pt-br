---
title: Classe _U_MENUorID
ms.date: 11/04/2016
f1_keywords:
- ATL._U_MENUorID
- ATL::_U_MENUorID
- _U_MENUorID
helpviewer_keywords:
- U_MENUorID class
- _U_MENUorID class
ms.assetid: cfc8032b-61b4-4a68-ba3a-92b82500ccae
ms.openlocfilehash: 9388ca1751ee27fb25d6751c961d23e5243f2918
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495141"
---
# <a name="_u_menuorid-class"></a>Classe _U_MENUorID

Essa classe fornece wrappers para `CreateWindow` e `CreateWindowEx`.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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

Essa classe de adaptador de argumento permite que IDs (UINTs) ou identificadores de menu (HMENUs) sejam passados para uma função sem a necessidade de uma conversão explícita na parte do chamador.

Essa classe é projetada para implementar wrappers na API do Windows, especialmente as funções [CreateWindow](/windows/win32/api/winuser/nf-winuser-createwindoww) e [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) , ambas aceitam um argumento HMENU que pode ser um UINT (identificador de janela filho) em vez de um identificador de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl:: Create](cwindowimpl-class.md#create).

A classe define duas sobrecargas de construtor: uma aceita um argumento UINT e a outra aceita um argumento HMENU. O argumento UINT é apenas convertido em um HMENU no construtor e o resultado armazenado no único membro de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu). O argumento para o Construtor HMENU é armazenado diretamente sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin. h

##  <a name="_u_menuorid__m_hmenu"></a>  _U_MENUorID::m_hMenu

A classe contém o valor passado para um de seus construtores como um membro de dados HMENU público.

```
HMENU m_hMenu;
```

##  <a name="_u_menuorid___u_menuorid"></a>_U_MENUorID::_U_MENUorID

O argumento UINT é apenas convertido em um HMENU no construtor e o resultado armazenado no único membro de dados da classe, [m_hMenu](#_u_menuorid__m_hmenu).

```
_U_MENUorID(UINT nID);
_U_MENUorID(HMENU hMenu);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Um identificador de janela filho.

*hMenu*<br/>
Um identificador de menu.

### <a name="remarks"></a>Comentários

O argumento para o Construtor HMENU é armazenado diretamente sem conversão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
