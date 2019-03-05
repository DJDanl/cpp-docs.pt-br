---
title: Classe u_menuorid
ms.date: 11/04/2016
f1_keywords:
- ATL._U_MENUorID
- ATL::_U_MENUorID
- _U_MENUorID
helpviewer_keywords:
- U_MENUorID class
- _U_MENUorID class
ms.assetid: cfc8032b-61b4-4a68-ba3a-92b82500ccae
ms.openlocfilehash: d02d00e3c56fc253e8f89eec9815e01d60c6e2aa
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57259354"
---
# <a name="umenuorid-class"></a>Classe u_menuorid

Essa classe fornece wrappers `CreateWindow` e `CreateWindowEx`.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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

Essa classe de adaptador do argumento permite IDs (unidades) ou (HMENUs) a serem passados para uma função sem a necessidade de uma conversão explícita de identificadores de menu na parte do chamador.

Essa classe é projetada para a implementação de invólucros para a API do Windows, particularmente o [CreateWindow](/windows/desktop/api/winuser/nf-winuser-createwindowa) e [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) funções, que aceitam um argumento HMENU que pode ser uma janela filho identificador (UINT) em vez de um identificador de menu. Por exemplo, você pode ver essa classe em uso como um parâmetro para [CWindowImpl::Create](cwindowimpl-class.md#create).

A classe define duas sobrecargas de construtor: uma aceita um argumento UINT e o outra aceita um argumento HMENU. O argumento UINT apenas é convertido para um HMENU no construtor e o resultado armazenado no membro de dados único da classe, [m_hMenu](#_u_menuorid__m_hmenu). O argumento para o construtor HMENU é armazenado diretamente, sem conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="_u_menuorid__m_hmenu"></a>  _U_MENUorID::m_hMenu

A classe armazena o valor passado para qualquer um dos seus construtores como um membro de dados público HMENU.

```
HMENU m_hMenu;
```

##  <a name="_u_menuorid___u_menuorid"></a>  _U_MENUorID::_U_MENUorID

O argumento UINT apenas é convertido para um HMENU no construtor e o resultado armazenado no membro de dados único da classe, [m_hMenu](#_u_menuorid__m_hmenu).

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

O argumento para o construtor HMENU é armazenado diretamente, sem conversão.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
