---
title: operador Windows::UI::Xaml::Interop::TypeName
ms.date: 12/30/2016
ms.assetid: a65a105e-7e3a-452f-932f-2cdaf00fbba5
ms.openlocfilehash: c77655ed7692c4cdccc311bc27c492126d62e54e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659196"
---
# <a name="operator-windowsuixamlinteroptypename"></a>operador Windows::UI::Xaml::Interop::TypeName

Habilita a conversão de `Platform::Type` para [Windows::UI::Xaml::Interop::TypeName](https://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx).

## <a name="syntax"></a>Sintaxe

```cpp
Operator TypeName(Platform::Type^ type);
```

### <a name="return-value"></a>Valor de retorno

Retorna um [Windows::UI::Xaml::Interop::TypeName](https://msdn.microsoft.com/library/windows/apps/windows.ui.xaml.interop.typename.aspx) quando um `Platform::Type^`é especificado.

### <a name="remarks"></a>Comentários

`TypeName` é a estrutura do Tempo de Execução do Windows com neutralidade de idioma para representar informações de tipo. [Platform::Type](../cppcx/platform-type-class.md) é específico a C++ e não pode ser passado pela ABI (interface de binária de aplicativo). Aqui está um uso de `TypeName`na função [Navigate](https://msdn.microsoft.com/library/windows/apps/hh702394.aspx) :

```
rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
```

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como converter entre `TypeName` e `Type`.

```

// Convert from Type to TypeName
Windows::UI::Xaml::Interop::TypeName tn = TypeName(MainPage::typeid);

// Convert back from TypeName to Type
Type^ tx2 = (Type^)(tn);
```

## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework

O .NET Framework programa o `TypeName` do projeto como [System.Type](assetId:///System.Type?qualifyHint=False&autoUpgrade=True).

### <a name="requirements"></a>Requisitos

## <a name="see-also"></a>Consulte também

[operador Windows::UI::Xaml::Interop::TypeName](../cppcx/operator-windows-ui-xaml-interop-typename.md)<br/>
[Classe Platform::Type](../cppcx/platform-type-class.md)