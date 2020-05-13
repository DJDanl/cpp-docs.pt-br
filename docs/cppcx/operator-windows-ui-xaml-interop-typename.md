---
title: operador Windows::UI::Xaml::Interop::TypeName
ms.date: 12/30/2016
ms.assetid: a65a105e-7e3a-452f-932f-2cdaf00fbba5
ms.openlocfilehash: d35056ca1a4e7f06c9f91fe86998a676a12395f2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337005"
---
# <a name="operator-windowsuixamlinteroptypename"></a>operador Windows::UI::Xaml::Interop::TypeName

Habilita a conversão de `Platform::Type` para [Windows::UI::Xaml::Interop::TypeName](/uwp/api/windows.ui.xaml.interop.typename).

## <a name="syntax"></a>Sintaxe

```cpp
Operator TypeName(Platform::Type^ type);
```

### <a name="return-value"></a>Valor retornado

Retorna um [Windows::UI::Xaml::Interop::TypeName](/uwp/api/windows.ui.xaml.interop.typename) quando um `Platform::Type^`é especificado.

### <a name="remarks"></a>Comentários

`TypeName` é a estrutura do Windows Runtime com neutralidade de idioma para representar informações de tipo. [Platform::Type](../cppcx/platform-type-class.md) é específico a C++ e não pode ser passado pela ABI (interface de binária de aplicativo). Aqui está um uso de `TypeName`na função [Navigate](/uwp/api/windows.ui.xaml.controls.frame.navigate) :

```cpp
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
```

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como converter entre `TypeName` e `Type`.

```cpp
// Convert from Type to TypeName
Windows::UI::Xaml::Interop::TypeName tn = TypeName(MainPage::typeid);

// Convert back from TypeName to Type
Type^ tx2 = (Type^)(tn);
```

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

O .NET Framework programa o `TypeName` do projeto como [System.Type](/dotnet/api/system.type).

### <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Confira também

[operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)<br/>
[Plataforma::Classe de tipo](../cppcx/platform-type-class.md)
