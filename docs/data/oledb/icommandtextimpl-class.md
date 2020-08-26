---
title: Classe ICommandTextImpl
ms.date: 11/04/2016
f1_keywords:
- ICommandText
- GetCommandText
- ICommandTextImpl.GetCommandText
- ICommandTextImpl::GetCommandText
- ATL::ICommandTextImpl::m_strCommandText
- ICommandTextImpl<T>::m_strCommandText
- m_strCommandText
- ICommandTextImpl.m_strCommandText
- ICommandTextImpl::m_strCommandText
- ATL::ICommandTextImpl<T>::m_strCommandText
- ATL.ICommandTextImpl.m_strCommandText
- ICommandTextImpl.SetCommandText
- ICommandTextImpl::SetCommandText
- SetCommandText
helpviewer_keywords:
- ICommandText class
- GetCommandText method
- m_strCommandText
- SetCommandText method
ms.assetid: 9c2715cc-1e55-4468-8327-85341617ed46
ms.openlocfilehash: 8d435cd8c5c8723d008be98482631f081c967058
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845114"
---
# <a name="icommandtextimpl-class"></a>Classe ICommandTextImpl

Fornece uma implementação para a interface [ICommandText](/previous-versions/windows/desktop/ms714914(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T >
class ATL_NO_VTABLE ICommandTextImpl
   : public ICommandImpl<T, ICommandText>
```

### <a name="parameters"></a>parâmetros

*T*<br/>
A classe de comando derivada de `ICommandTextImpl` .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** altdb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[GetCommandText](#getcommandtext)|Retorna o comando Text definido pela última chamada para [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).|
|[SetCommandText](#setcommandtext)|Define o texto do comando, substituindo o texto do comando existente.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_strCommandText](#strcommandtext)|Armazena o texto do comando.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória em comandos.

## <a name="icommandtextimplgetcommandtext"></a><a name="getcommandtext"></a> ICommandTextImpl:: GetCommandText

Retorna o comando Text definido pela última chamada para [SetCommandText](../../data/oledb/icommandtextimpl-setcommandtext.md).

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetCommandText)(GUID * pguidDialect,
   LPOLESTR * ppwszCommand);
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommandText:: GetCommandText](/previous-versions/windows/desktop/ms709825(v=vs.85)) na *referência do programador de OLE DB*. O parâmetro *pguidDialect* é ignorado por padrão.

## <a name="icommandtextimplsetcommandtext"></a><a name="setcommandtext"></a> ICommandTextImpl:: SetCommandText

Define o texto do comando, substituindo o texto do comando existente.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(SetCommandText)(REFGUID rguidDialect,
   LPCOLESTR pwszCommand);
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommandText:: SetCommandText](/previous-versions/windows/desktop/ms709757(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="icommandtextimplm_strcommandtext"></a><a name="strcommandtext"></a> ICommandTextImpl:: m_strCommandText

Armazena a cadeia de caracteres de texto do comando.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR m_strCommandText;
```

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
